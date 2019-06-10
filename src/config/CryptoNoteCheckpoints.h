// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
{     100, "69b1bb40b26cbe7eb4bfabc63b4c86cb00312d793d2f46b631ec5a5f7ef97bc6"},
{     200, "2c8e92512d2566f1352c346f969517170d79f4911a6b980b407f23657826d1ea"},
{     300, "56022360222ceea5bcb731275df2da66ffa17b73457eaae9412f54f6ba78f1fc"},
{     400, "e488d58e38f1dce2d7e485d604c720d083c56889d7dedc4183ea9b2c7811af04"},
{     500, "95451cd10fa9633b3ea6b204adbda56afc741cff68a52ecdc985f29c3eab2f85"},
{     600, "e2980b7ef76b2028076b35ff3fb0c2fbf0dac0c506e825dec2bcf97988fd1f9a"},
{     700, "a00057a04aae4e0b60343d167e55f039cd4c2acb453d2314606e9fe179320a6d"},
{     800, "f855a21c4d0eed1c9a0099df6d1fdf51b10165358c4270e6aadabb3cd48cfa4b"},
{     900, "0d1940aeed73e65198313af08a568d53f9c54b1e5a3f77dd9d712d88ce12b9a5"},
{    1000, "8bb797ce6ff574c1d23cfef762d18b643ae4add982258159c03b216ffd2d662f"},
{    1100, "0f616b55258601bfabd37e0e25d97b962102e1d97dc6f690847977fe5d7cc726"},
{    1200, "6393377ee6dcc94652201f7c5e182022d0b600fe2074b3cb8d1bb1994ce8bf1f"},
{    1300, "3d548d9350fbd29d23066b50d7581d9cc5461e03509ecb18e8a44a697fa861fc"},
{    1400, "63d9888872b988ace0ba11961a8cd99e00feccfc1c9dc54104980fb81797ebf5"},
{    1500, "03b83e7cc996ed8a0dcee580d786eb82cb0f32fe486c479bc7e650e9380cd70b"},
{    1600, "149f3adf434f800d3b7da32509a91b8a6824e063a97be182c9a18223ca1be403"},
{    1700, "87847b7448ca99cc03dd84912e989a99055e1a39c406fe9661583ec5b2b374b9"},
{    1800, "bcb4e9327e8a57a732b172e6be9bf43ef1a9b6129f19f230f412f50a36ee7457"},
{    1900, "e9a37e36526f9cbf916f3e623dd4b84b70f4d127f6e0d064965e2937f5b6a952"},
{    2000, "308042a7d4c7ddb893e88b0a30dfc044a4bc2a7653a3e7808eaa1839408f77d6"},
{    2100, "b3a749a061f24c88ed23e8a484ed08d8d0b55a45c00479d49e13eab1b9cae04d"},
{    2200, "ee5675d261c9c649c9dbaa7b43d26f9e5825dc42430aa26bdd40b494e4fc2a3d"},
{    2300, "402a162b0a5a11207bac7d3440e57e0de81da99a34a995a21f093b16008e74db"},
{    2400, "c3a5192dcb43e881162742785eb926b59ecb42731cb4b6373ea358e6d04cb39f"},
{    2500, "9470b071d31016de8b9367fe474d9e2c67b8c0f82cb0e48de25ca52c1855f8e8"},
{    2600, "bb6f70d64ab6ca4b1910dbae658ad212deed0330f8bcf486c3e6c66667c50f38"},
{    2700, "fd9ef5ff92d68fd6231b0c434eeb738f4af72934140ce3fdb505d288f0e7c1d9"},
{    2800, "9d76f4db76dee98f39be7b202452e929c1d586e1ee47ca92463fbb74261605f2"},
{    2900, "6bc0b9ea230e0cdbc8cebb3d72763c4f2ec7611810e0ab820d4eefcb113b915a"},
{    3000, "67d244b1e2956ec1e5adf538c76c40739e71b28e95a5618c675323b9546574d5"},
{    3100, "89b515ae0513bd2c2728f7615d91148adcf3fb4228afccdc68d8e15263c30a55"},
{    3200, "6ccc65a38bc07b33b775d214f9beadf26968b5f2499c660ac69cae541db292e3"},
{    3300, "a89bd65797acf8d1901cdeef04ab5119ed86d8965ac3a938692074c37ace6867"},
{    3400, "5c27b187951856c3129522a243f87f3585b55ad32d0389f77a638a35ca185ed1"},
{    3500, "e2e023418588630cd4defdda0ff325b38dba4967f477077c0727b8f09a674d9b"},
{    3600, "a2492742a3f78a9fe5d37ac61469503e84485379edd11bdc2e11ac74405de2cc"},
{    3700, "b2067a8ba1b27b41abd5006044ecd2b4351566cc8c5e996c968069ff46d52c34"},
{    3800, "1ef06a8e6bc2ed80cd01b2f58922fc121a29390920c0c2966e30d4d8d4536312"},
{    3900, "e43ba0d1f55fedd354961aa634a02c55bf130283e6845d5d417472264a9860ff"},
{    4000, "7c4a5f384eb60e7a789844c451c9ec8e06c70cfc4d9fe91ae76887ba8af7477b"},
};
}
