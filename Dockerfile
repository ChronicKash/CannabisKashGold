# daemon runs in the background
# run something like tail /var/log/CannabisKashd/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/CannabisKashd:/var/lib/CannabisKashd -v $(pwd)/wallet:/home/turtlecoin --rm -ti CannabisKashGold:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG CANNABISKASHGOLD_BRANCH=master
ENV CANNABISKASHGOLD_BRANCH=${CANNABISKASHGOLD_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/ChronicKash/CannabisKashGold.git /src/CannabisKashGold && \
    cd /src/CannabisKashGold && \
    git checkout $CANNABISKASHGOLD_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/CannabisKashd /usr/local/bin/CannabisKashd && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/Cannabiskashd && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/CannabisKashGold && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the CannabisKashd service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/Cannabiskashd Cannabiskashd && \
    useradd -s /bin/bash -m -d /home/CannabisKashGold CannabisKashGold && \
    mkdir -p /etc/services.d/Cannabiskashd/log && \
    mkdir -p /var/log/Cannabiskashd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Cannabiskashd/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/Cannabiskashd/run && \
    echo "cd /var/lib/Cannabiskashd" >> /etc/services.d/Cannabiskashd/run && \
    echo "export HOME /var/lib/Cannabiskashd" >> /etc/services.d/Cannabiskashd/run && \
    echo "s6-setuidgid Cannabiskashd /usr/local/bin/Cannabiskashd" >> /etc/services.d/Cannabiskashd/run && \
    chmod +x /etc/services.d/Cannabiskashd/run && \
    chown nobody:nogroup /var/log/Cannabiskashd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/Cannabiskashd/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/Cannabiskashd/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/Cannabiskashd" >> /etc/services.d/Cannabiskashd/log/run && \
    chmod +x /etc/services.d/Cannabiskashd/log/run && \
    echo "/var/lib/Cannabiskashd true Cannabiskashd 0644 0755" > /etc/fix-attrs.d/Cannabiskashd-home && \
    echo "/home/CannabisKashGold true CannabisKashGold 0644 0755" > /etc/fix-attrs.d/CannabisKashGold-home && \
    echo "/var/log/Cannabiskashd true nobody 0644 0755" > /etc/fix-attrs.d/Cannabiskashd-logs

VOLUME ["/var/lib/Cannabiskashd", "/home/CannabisKashGold","/var/log/Cannabiskashd"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/CannabisKashGold export HOME /home/CannabisKashGold s6-setuidgid CannabisKashGold /bin/bash"]
