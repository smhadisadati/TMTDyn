/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rjtipF_info.c
 *
 * Code generation for function '_coder_rjtipF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rjtipF.h"
#include "_coder_rjtipF_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.63710648147));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.5.0.944444 (R2018b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[28] = {
    "789ced5dcd6fe3c615e7a6d9208b222d81b449fa9566d362b1c506962cc992b74000ebd3966d7d6b6daf37a94c4994449b1f1249c9922ef5b1871cf207f49063"
    "5ab4c5b62890451314eaadd7024d0f3d0528825e7a6dcf1545d1f67035116d8e68517a0f30a8f113e7377a78fccdcc9b3743ea5632758ba2a86f0cfffef8738a",
    "cabeaa9528ea154a177a7c7d8142c5acbf35beae98ca86dca65e44eebb35c6fbe5b85c914495edaa7a81e74436dd16caac3c2c888cc09e575395044e6444b5d8"
    "6bb294cc2a12df61ab234d8de3d92227b0bbd2a5c216372c08894baaf382a6d23e471b6ce5a4d01628b9a15c3497bf5ca0c6f6d1e429e6f7bf68d13e698c7d68",
    "93fe49fc7d4f4312584f83a9729e547c33acf4c48a674b2b85dbaa544c15633dd11395aaece5728455194f6775c5eba9681af958e59a8915e1a2fdbfc0b4ef25"
    "8bedbf8d69ff9df1f5fee57f9e4537f40fc635a85fcf22e37268c368d71106d7aa5d71eda2c79aa6743af22652782f99ca1778baa62ab5cb3c7b81f7b14dbc30",
    "160fd53f49ee1e0c5da7adc81e5eaa30bc27152eee86239ebccfbbba5ef6a892c497a5ae8715780fcf953d02a3f24cd9233515cfc8429aab8c649a9dacfa8bf9"
    "6ac81deae5f1a7b30f3e0ffe23ec1c9e2ecb82d7c5d467d5ef5ec3e0d126fd7e638f0d167285b57c31d73e88ed1cee498547d18b7664a7e04c6b0785293b55bf",
    "5b9fdf26a65d56fded0553d91083ef69e4bff736f4ebdbe7bc7e86a9dfaadd7e88c1a74d7aadbb9357b8e1204216197e8553226d8e5793e27018c1ca5ce5c678"
    "ff994dbc3c160fd55fc16fb4bf07237b791e1806f3980d66389283fdc027fffde7e7d00fcc08cfa97e20d36945c3b5adce7a3117e855e282e84b1cf25b8bd30f",
    "d81dff6f63eaa74d7adbfdc0dd1aaf1a835eca61bf3b4b6d90f2bbd73178b4496fe27f656832468ed76f8cf7e7d04f26f2be61a81be0fbdfddfb198cfbddcef7"
    "de7c7db5a36e3f94e47a432924987a2491ecc480ef97e739a610bec7cd37acdaeb155399327dcfd0738aa80f54552d127873711dbbfe91c4e2a1fa2b8e076a5c",
    "97ad36a5a17b78104bdd407c87faedfe77605cef769edff49ff40aad3ac7478bd1937c2b522f9e3c8a03cf2f2dcfe3f0acdaeb6553993aff9eaee1941a379cd4"
    "34dc1aaf8f61f150bd1d5ed72da47b02f0f962e0d9e5f36f63f06893bed362e3cd4e45797870ea97a4ac5258f53f3ea41687cfdd1277bde0f3bb354e56d41a87",
    "fe8e234c3b89fadfe08858bcfe4d0c1e6dd20f8d511a1aa15493645e929a25a9c3ca355e3a2d55b4f578fbe379b3e0da63888137b8269e51ffe1143c437fbdf8"
    "ded88dbec272ce8f0b069f7d791be238f3da1f581ddf2b3bf16e3cd6ef67b7bbbe40cae78de6c2abdef8e2f4075f60eeb76ac7334cfdb4493fbbe7faee577fa1",
    "d460f9262b3beba79bc4e6032f9acad4f9f7748d36dad5ae37bcaec08955b69b14d5f3767c64b31d1b53da61e8edcd13560407fde219ace3babf3f28f49a9cb0"
    "d6caefaf72e56a207998cba6561729aeff11e6fe257e6e87e25d9838feb4fea4d260462be310c79f7c3504e23ecee0411c9f4cfd5f60ee8771fee4df6bcd4f93",
    "c4c6f9d3e2f0c31f2e30dd9beb07e634ee6ff80f3ffce0d16de474dc7ff0ecf53b10e7713bffcb2d6ff39853026121980d89d9f2817f674f8900ff03ffa382ae"
    "fb3acbff9c08fc3f8dff39d171feff14f8dffdfc5f671e8732fefd742b540eabd13526136003b9cdc5e17f58f79d7c3504f1bf2f8e88f1fa55e3f776f1ae9acf",
    "f3914dbc0d2c1eaa7751bc0fe2f433c483383d99fa5dc8e77d569694b680fe0e5c3c7d26fb7007ef6d8cae1bef3bc6efb536cf6b57c8d79c346e579a8c5c6b8b"
    "1ecd4a4e8fdbcf7e0f717bf7f3bc1af409f9d8fe66e3d02ff53b6a4a48a456d505e2f9a798fb615fed65bfbbc8bfc79de363d55ef74d65caf43d436fca7f619a",
    "4dbe17e14446ee15463d5ea22d56544e1249ad1b7f734abb0c7d6d8c5b6a306275d81190cadf7c3205dfd0db1d2f600d395ed975b07ff8c3af6488ebb8bd7fc8"
    "e5a2ea49f6d81b2a1fa677d2e522b39e492989c5e91f0698fbe1b94605f5c310b1fee247183cdaa437f7171d89ab866599e925784655599113eba3efdd547ebf",
    "ddf9e4de143c436fdb8f2618eef2397e47987612f49fb3ff95a15f707bbfd0dfdef2471f350f845c39530d1fd4b6525d21b340e7f1d87d9e8b98fa6993defebc"
    "418f10956abcc4a8a5f31984b3fbbc0ee15c1e9b788bbfcf1bcee599251e9ccb43a67ebbbc9fc3d44f9bf4f6795f94d43493cec8c9e1a35d37c2460e9fdbb04f",
    "6c1d60da39cb9c223222e5de758028160fd5dbcadfd16ce47c9c07d67b6788e7d4b90dad703b23047a07016f5ef6b5a3abecc38e90a61687d7e1f94505f5b71f"
    "133ba701ce55c6e1a17a3857f9aa78ba2c0b1e9cab4ca67e18cf4fbe1a821bcf9f61eab36ab7ef61f068937e621c67a5c64b926e01b7c67332583c546fb71f78",
    "a05bcc33b2d8b0137090ff7f0df93feee7ff7223983d1079b55a9084785bdcf297e391ed05cadb9fc3b8ecfce5ff9ca589c5efbf85c1a34d7a13efb3b22c595a"
    "b798d5feac391bf72bc3e6b1558fcef663ce3753ffc8663730eefff3ce6388e3bb9df7bb62eeb49f6a0a91cd562ca1ac47b75b1dc9bb40717cbbbc9fc6d44f9b",
    "f4b37a9fe211a67d64793fe6581ebfd292472fe1746bfc3e82c543f5d78dff6959fc9a8d9ce7f38dbf3cba07e378b7f37960335e6b7883c9e34cdc9f54b33951"
    "ec44630b14c781e71715d4dfee118bdb7c1f83479bf4cfc5ef6392c07062dc3c8e6fda6c8fddbc7db7c47110033a1bc7f9d37f201fd3f5fccfa784aa7022b3a9",
    "66745f5d97dad5dae336b740e7efc0733cb9fda8df05898de7a7bf4745db7baab06e1dcf6f61f150bdbd7db986959c3c7f61e3e57721cfd2f57c7eba9f5412fc"
    "c95ec257930b7ce738b32df67351e0f3e5e2f377619fd558609f15da6e0bfe03fbac668807fbacc8d40f711d54507fbb0febb236f1605d765678ba2c0b1eaccb",
    "92a91ff81e15d4df5688c5f1bf8bc1a34dfac9f997c66aedcd8df3edce0f2dafdf13cabf347cc6397f197cf2af7fc3baedbcf2bdd57d57ebeddd8277cf9f09cb"
    "497f5c3cd8ce07c57c9002be5f36beff10539f553bfd0483479bf493ce5d430f144a8a599ea9b0e3efcfcb3aeec026fe7b53f00d3d91739a261ad4f173f5cb5f",
    "3f86f9c0bcf60f56e70312b37b5c6698cd68d5bf7eac1cf8d8d461b3b740f38101e67e78ae5141fdf01d58e7b58807ebbca4f07459163c58e72553ff00733ff0"
    "3b2a8b1e07ba2eff431c6872fb210ee40c1ec481c8d4efd873ece6fd58548218efbf85c1a34d7a13efcbacd2609a6c81ebb351edad908a5bf37c0a53f00cbd5d",
    "de7fce60ce9fbff6b7df7c0cf38079e57fabf380e0a6970f6543b9ecded69eb2b71facefe45b8bf41e16789e275f0d41fdef2d62793f6f60f06893ded40f888c"
    "5ce7c44ae3c4adfc4f38cfd34adecfb9cd9c1d379cbdfad3fcdf81ff6784e714fff7baa7c9874ca2565ff3563271a9709c68874ee3c0fff3f63ce3fcc1aaff7d",
    "0df33b8cf72dbe81fcf79d0dfdfaf6f87ab1cff7088343eabc65e30436b7c6fd677d5eebe8ad8be333d73471909fe0bc8619e239c5f7ebad50a6d8e2636b2791"
    "4631b759505bb1586581deab05cf2f2ab8f1fd19a63e386fd91a1e9cb73c2b3c5d96050fce5b26533ff03e2ab33a677f5ece57368bd5f8ced36be219f5c3f9ca",
    "a4f17459163c385f994cfdc0f7a8e0f8fe434c7d90dfafcbc026fef2e589417eff2cf120bf9f4cfd03ccfdf05ca332abfccf7999275c373e04f384c9ed877982"
    "3378304f20533fe4ff4cbe1a82fa9ff79cffed9efb761783479bf4e67983a2b0b2bac7f05c55334558ae8fbfe7d6758222160fd5db1e473c6738c7e7052f444f",
    "615ee0f6fec0e73be93f8c2522c9fa6eb770d8df2a6f3dccab900fb484cff350ce3660bfaf453cd8ef4b0a4f9765c183fdbe64ea075e9f7c3504e5f530e4018d"
    "ff0f794093af86401e903378900744a6fe01e67eab762c61eaa74dfa59f403773945d3d7658677d60f078f1dcbefd77e628d82fc7e5cdec0f083676423e7f7f3",
    "3e037e773fbfaf75537ce2a4533d4e060fbadb55d917100b41c8ef5f82e7571372799e30aec7e1a17a18d75f154f9765c183713d99fa0798fb5d33ae2f4b6db1"
    "aa383caecf11eb0f7e80c1a34dfae7fa83a436a361e5283fb40c456edc7fd5f7b93cb58997359529d3f70cbdfdfee0b2c11c8df37ff0da1d88f3bbbd1f4888bb",
    "d948783fdde7846ee6b85915326abab74071fe01e67ee8075041fb8147c4e23bd3c6e14303084cf7e678deeefc3086c543f5b6e687231b399e9ff3ec75e077d7"
    "f3bbdcf2368f3925101682d990982d1ff877f694057adffa00733ff03b2aa81fee39caef9c08fc3e8ddf39d1717eff14f8ddfdfc5e671e8732fefd742b540eab",
    "d1352613600339c8c73faf6fa9f274a82de0758b78c0eba4f07459163ce07532f503af4fbe1a82e65fa6211e63110fe231a4f07459163c88c790a9ffaf98fbad"
    "da91c1d44f9bf433d83f7bb7c3c8a3a3944b4d59aa9a7ed711a6dd6479be426cfdf54d0c1e6dd20f8d531a1aa55493645e929a25a9c3ca355e3a2d5534abdcdc",
    "b96b836be219f51f4ec133f4d7ec0774b7fa0acb399f9733f8eccbdbd03fb8bd7f5076e2dd78acdfcf6e777d8194cf1bcd8557bd0bb09ff6ff6b520d9a",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70504U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
