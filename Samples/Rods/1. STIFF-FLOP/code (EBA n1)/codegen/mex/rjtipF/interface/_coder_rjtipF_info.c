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
                (737431.75717592589));
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
    "789ced5dcd6fe3c615e726d9208b222d81b4d9f42bcda6c52245024b9664d95b2080be6dd9d6b756f67a93ca944449b4f92191942cf9521f7bc8217f400f39a6"
    "455b6c7bc9a2090af5d66b81a6879e1628825e7a6dcf1545d1f67035116d8e68517a0f3046f413e7377a78fccdcc9b3743ea5632758ba2a86f0eff4abfa0a8d0",
    "6bda1545bd4ae9428fcb172854ccfa5be372c5746dc86dea25e4be5b63bc5f8dafab92a8b23d55bfe039914d77840a2b0f2f444660cfaba949022732a25aecb7"
    "584a661589efb2b591a6cef16c9113d85de9d2c51637bc10129754e7179a4afb1c6db2d5e34247a0e4a672d15cfef20535b68f264f30bfff258bf64963ec439b",
    "f48fe31f7a9a92c07a9a4c8df3a4e29b61a52f563d5bda55b8a34ac55431d6173d51a9c65ebe8eb02ae3e9aeae783d554d231fa95c2bb1225cb4bf8769dfcb16"
    "dbff22a6fd77c6e51bc87f57437ab9322ebd21a31d87181cab76bc8d69073dd6b4a49391f790c27bd9747d81a76b6a52a7c2b317789fdac40b63f150fde3e4ee",
    "fed0553a8aece1a52ac37b52e1e26e38e2c9fbbcab1b158f2a497c45ea795881f7f05cc523302acf543c524bf18c2ca4b9c648a6d9c9aa7f984b43ee50af8c3f"
    "9d7df465f01f61e7f07459163cdcf36dd5ef5ec7e0d126fd5eb3c4060bb9c25abe98ebecc7760e4a52e161f4a21dd92938d3da4161ae9daadfadcf6f0bd32eab",
    "fef682e9da1083df69e4bff7437af9f639af9f61eab76ab71f61f069935eebdee4156e38689045865fe1944887e3d5a4381c36b03257bd31de7f6a132f8fc543"
    "f557f01bedefdd91bd3cef1a06f3980d66389283fdc067fffde797d00fcc08cfa97e20d36d47c3f5adee463117e857e382e84b1cf05b8bd30fd81def6f63eaa7",
    "4d7adbfdc0bd3aaf1a835eca61bf3b4b8548f9dd5d0c1e6dd29bf85f199a8c91e38d1be3fd39f49389bc6f18ea06f8fef7f77f0ee37eb7f3bd37df58edaadb0f"
    "24b9d1540a09a6114924bb31e0fbe5798e2984ef71f30dabf67ad5744d99be67e83945d407aaaa16f9bbb9b88e5dff4862f150fd15c70375aec7d65ad2d03d3c",
    "88a56e20be43fd6eefbb30ae773bcf6ffa8ffb857683e3a3c5e871be1d69148f1fc681e79796e7717856edf58ae99a3aff9eaee1943a379cd434dd1aaf8f61f1"
    "50bd1d5ed72da47b02f0f962e0d9e5f3ef60f06893bedb66e3ad6e5579b07fe297a4ac5258f53f3aa01687cfdd1277bde0f37b754e56d43a87fe8e434c3b89fa",
    "dfe09058bcfe4d0c1e6dd20f8d511e1aa15c97645e925a65a9cbca755e3a2957b5f577fbe379b3e0da63888137b8269e51ffc1143c437fbdf8ded88dbec672ce"
    "8f0b065f7c751be238f3da1f581ddf2b3bf15e3c767a9addeef902299f379a0baf7ae38bd31f3cc3dc6fd58e6798fa69937e76cff5bdafff42b9c9f22d5676d6",
    "4f3789cd075e325d53e7dfd335da68572b6f785d81136b6c2f29aae7edf8c4663b4253da61e8edcd13560407fde229ace3babf3f28f45b9cb0d6ceefad72955a"
    "207990cba6561729aeff09e6fe257e6ea9cbf9986e8fe34feb4faa4d66b4320e71fcc9a52110f771060fe2f864ea7f86b91fc6f9937faf353f4d121be74f8bc3",
    "0f7fb8c0f46eae1f98d3b8bfe13ffcf08347b791d371ffc1d3bb7720cee376fe97dbded611a704c24230bb2e662bfbfe9d921201fe07fe47055df77596ff3911"
    "f87f1aff73a2e3fcff39f0bffbf9bfc13c5acff8f7d2edf54a588dae3199001bc86d2e0effc3baefe4d210c4ff9e1d12e3f5abc6efede25d359fe7139b78212c",
    "1eaa7751bc0fe2f433c483383d99fa5dc8e7a7ac2c291d01fd1db878fa4cf6e10e3e088dcad0878ef17bbdc3f35a09f99a93c6ed4a8b91eb1dd1a359c9e971fb"
    "d91f206eef7e9e57833e211fdbdb6c1ef8a5d3ae9a1212a955758178fe09e67ed8577bd9ef2ef2ef7f89a9cfaabddec1e0d126bd29ff8569b5f87e841319b95f",
    "18f578898e5855394924b56efcad29ed32f4f5316eb9c988b56147402a7ff3f1147c436f77bc8035e47865d7c1fee18fbf9621aee3f6fe21978baac7d923ef7a"
    "e520bd93ae14998d4c4a492c4eff30c0dc0fcf352aa81fae13eb2f7e8cc1a34d7a737fd195b85a5896997e826754951539b131fade4de5f7db9d4f96a6e0197a",
    "db7e34c17097cfed3bc4b493a0ff9cfdaf02fd82dbfb85d3ed2d7ff4616b5fc85532b5f07e7d2bd513320b741e8fdde7b988a99f36e9edcf1bf40851b9ce4b8c"
    "5a3e9f4138bbcfeb00cee5b189b7f8fbbce15c9e59e2c1b93c64eab7cbfb394cfdb4496f9ff745494d33e98c9c1c3eda0d236ce4f0b90d7bc4d601a69db3cc29",
    "222352ee5d078862f150bdadfc1dcd46cec77960bd7786784e9ddbd00e773242a0bf1ff0e6655f27baca3ee80a696a71781d9e5f54507ffb09b1731ae05c651c"
    "1eaa877395af8aa7cbb2e0c1b9ca64ea87f1fce4d210dc78fe0c539f55bb7d1f83479bf413e3382b755e92740bb8359e93c1e2a17abbfdc0bbbac53c238b0d3b",
    "0107f9ff3790ffe37efeaf3483d97d91576b05498877c42d7f251ed95ea0bcfd398ccbce5ffecf599a58fcfedb183cdaa437f13e2bcb92a5758b59edcf9ab371"
    "bf326c1e5bf3e86c3fe67c33f58f6c7603e3fe3fef3c8238bedb79bf27e64e4e532d21b2d98e25948de876bb2b7917288e6f97f7d398fa69937e56ef4f3cc4b4",
    "8facdff91dcbe357daf2e8a59b6e8ddf47b078a8febaf13f2d8b5fb391f37c1efacbc3fb308e773b9f0736e3f5a637983ccac4fd49359b13c56e34b640711c78"
    "7e5141fded3eb1b8cd0f3078b449ff5cfc3e26090c27c6cde3f896cdf6d8cddb774b1c0731a0b3719c3ffd07f2315dcfff7c4aa809c7329b6a45f7d40da953ab",
    "3fea700b74fe0e3cc793db8ffa5d90d8787efa7b54b4bda70aebd6f1fc16160fd5dbdb976b58c9c9f31742afbc0f7996aee7f393bda492e08f4b095f5d2ef0dd"
    "a3ccb6789a8b029f2f179fbf0ffbacc602fbacd0765bf01fd86735433cd86745a67e88eba082fadb3bb02e6b130fd6656785a7cbb2e0c1ba2c99fa81ef5141fd",
    "6d85581cff7b183cdaa49f9c7f69acd6dedc38dfeefcd0f2fa3da1fc4bc3679cf397c167fffa37acdbce2bdf5bdd77b5d1d92d784bfe4c584efae3e2fe763e28"
    "e68314f0fdb2f1fdc798faacdae9a7183cdaa49f74ee1a7aa05052ccf24c951d7f7f5ed6710736f13f98826fe8899cd334d1a08e9fab5ff9c611cc07e6b57fb0",
    "3a1f9098dda30ac36c466bfe8d2365dfc7a60e5afd059a0f0c30f7c3738d0aea87efc13aaf453c58e72585a7cbb2e0c13a2f99fa0798fb81df5159f438d075f9"
    "1fe24093db0f712067f0200e44a67ec79e6357efc70a10e3fdb73078b4496fe27d99559a4c8b2d70a76c547b2ba4e2d63c9fc2143c436f97f79f3398f3e7affd",
    "edb79fc23c605ef9dfea3c20b8e9e5d7b3ebb96c69aba494f6828d9d7c7b91dec302cff3e4d210d4ffde2296f7f306068f36e94dfd80c8c80d4eac368fddcaff"
    "84f33cade4fd9cdbccd971c3d96b3fcbff1df87f46784ef17fbf77927cc024ea8d356f3513970a4789cefa491cf87fde9e679c3f58f5bf1731bfc378dfe21bc8",
    "7fdf0be9e5dbe3f2629fef210687d479cbc6096c6e8dfbcffabcd6d15b17c767ae69e2203fc1790d33c4738aef37daeb99629b8fad1d479ac5dc66416dc762d5"
    "057aaf163cbfa8e0c6f76798fae0bc656b7870def2acf07459163c386f994cfdc0fba8ccea9cfd79395fd92c56e33b4fae8967d40fe72b93c6d36559f0e07c65",
    "32f503dfa382e3fb8f31f5417ebf2e039bf8cb972706f9fdb3c483fc7e32f50f30f7c3738dcaacf23fe7659e70ddf810cc1326b71fe609cee0c13c814cfd90ff"
    "33b93404f53fef39ffdb3df7ed1e068f36e9cdf306456165b5c4f05c4d3345586e8cbfe7d6758222160fd5db1e473c6738c7e7052f444f605ee0f6fec0e73b3e",
    "7d104b44928ddd5ee1e074abb2f520af423ed0123ecf43390bc17e5f8b78b0df97149e2ecb8207fb7dc9d40fbc3eb93404e5f530e4018dff0f7940934b43200f"
    "c8193cc8032253ff0073bf553b9631f5d326fd2cfa817b9ca2e91b32c33beb8783478ee5f76b3fb14e417e3f2e6f60f8c133b291f3fb799f02bfbb9fdfd77a29",
    "3e71dcad1d2583fbbded9aec0b888520e4f72fc1f3ab09b93c4f18d7e3f0503d8cebaf8aa7cbb2e0c1b89e4cfd03ccfdae19d757a48e58531c1ed7e788f5073f"
    "c4e0d126fd73fd41529bd1b072941f5a862237eebfeafb5c9ed8c4cb9aae29d3f70cbdfdfee0b2c11c8df37ff4fa1d88f3bbbd1f4888bbd948782f7dca09bdcc",
    "51ab2664d4747f81e2fc03ccfdd00fa082f6030f89c577a68dc387061098decdf1bcddf9610c8b87ea6dcd0f4736723c3fe7e95de077d7f3bbdcf6b68e382510"
    "1682d975315bd9f7ef9494057adffa00733ff03b2aa81f961ce5774e047e9fc6ef9ce838bf7f0efcee7e7e6f308fd633febd747bbd1256a36b4c26c00672908f",
    "7f5edf52e5e9505bc0eb16f180d749e1e9b22c78c0eb64ea075e9f5c1a82e65fa6211e63110fe231a4f07459163c88c790a9ffaf98fbadda91c1d44f9bf433d8"
    "3f7bafcbc8a3a394cb2d59aa997ed721a6dd6479be4a6cfdf54d0c1e6dd20f8d531e1aa55c97645e925a65a9cbca755e3a295735abdcdcb96b836be219f51f4c",
    "c133f4d7ec0774b7fa1acb399f9733f8e2abdbd03fb8bd7f5076e2bd78ecf434bbddf305523e6f34175ef52ec07edaff03906909e3",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
