/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_kF_info.c
 *
 * Code generation for function '_coder_fj_kF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_kF.h"
#include "_coder_fj_kF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_kF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.32934027782));
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
  const char * data[21] = {
    "789ced5dcb6fe3c619e726bbc12e82b43c340d82160db62d160db63065492b7b0f41f47ed8d6cb926d59bba94c4a944499e45024f5f2a53af6d0434e3df5b0c7"
    "a4408bb4877681168572eb3f901c72da4bfe84f65c51246593d0acb4264599f40c608c469f38bfd1e76f7edfcc370f617732d93b1886fd60faf7f7df6258e10b",
    "6c96de53330cd7f2b7306332cbef68f94f4d653dddc3ee1a9ebba3e1fd512bd7012fd343592db00c4fe77a1c458bd3024f72f4bc9a06e0189ee4e5f248a03191"
    "9600dba71b33499361e932c3d107e04a21cd4c0b5cf28a685e5044caeb589bae9f977a1c26b6a5cbe6b2570b98a61f257d05f9fe7757d44f16a21fdc247f96f8",
    "8c68038e26da648321b28954441af17522ad94223d1994b3e5f8882762a0415f2d47699924fadb5b3ea2ae489a9dda79728bbbd2fe3348fbde59b1fde65c4f0f"
    "b0fb574a9f8497e1adaaafb72178b826a903f51f6517de3ba6f2259e2a69801ec5d297785f58c48b40f18cf2679983cad4247a9248b0a04eb24436523e884489",
    "43bf6f7b97226400580a0c099a630996a1088e9459922268b6d9e3a7a620cd6c40490edac1d7478fbe89386b774edbf9e6f08690fa56b5bb1f43f070935c280f"
    "3b3b79b910dac993e552a72ca646753e7ad98ec2129c65edc02065a7ea47fdd7988cf6f6cb398f8f21f5adaaa70f2178b849aeb82d718b990e06449e64b7a4a9",
    "aa48714b6779eb3c6f4eb0f6e8c971bfbfba9d287f8f67fa221eeb0a231eab1a9bdb8c73f6120efde14bc4f76ee7fb5df140228bf5ece909755aa1a2d150b0d9"
    "a211dfdf3abeff1c52dfaa7afa1882879be426be2705811d95661496ecf17599017c862fb0645d9f02eaed132cb6ef874bdaa7cb9b5a2b6a6d926f4c07fe3afe",
    "c422fef325f8badcaa3f802b543531e7ec6b42bddbf916f98735e139e51f0079d0a14832156b04763b52c54f67abc228ee1dff30813c8ffab53119edf0d7b6c5"
    "7bee9bcad8fc73aa849124811425daadf19e3414cf28bfdef841d18d3282d0b5b4c53938febfffc96f10bfbb9ddf07271929c99e1f27fd4db1c4f63bf93dfea2",
    "1843fc7ebbf97dcb7371a0ebf23f8a032d6e3f8a03398387e240f6d4ef583f5ed33aee7f20ed5bd5eede3395f5f440cbdb57df1c67c2ea0b3d4fa9f938a995b5"
    "7c9cd6ca61ad1cd3ca9f6ae57dadacbd3f8e6879d4b6f9c33d53199b7f4e95086030db55e0d6f9c37ae38f409088998636107f1cfffe9b109a3fb8dd6f9cb48f",
    "e950a9587a72582ef62af1fdea31281d7968fee0d6fe0b8b97af6a6f6f99ca7ad2fd056e78f75158cd7f6edbbce123083e6e929be60d8c14ed31ac9ce1733d8e"
    "1699fac678ffa545bc43289e516e75de6056986e480efa817ffcf73b347f70bb1fc8f7bbb14833dddf2d1783a37a82e3fdc92a9bf68e1fb03a7fd883d48f9be4",
    "96fdc0c3262beb835ecc61bb1b67c376d9dd07103cdc245f18374ab45c1b2f5a839d2ce47d5d511be0fbbf3c42eb06aee77bdf616bbb2fef3d0562ab2d959264"
    "2b9accf43db42e8cfaf1e2f6c3f81e36df58555fb0f8146e923312af0e5465e544887bd70532503ca3fc0dc7034d6648370430350fc2a0a94dec2ffbf3c98768",
    "5cef769e4f05ce47a56e8b6163e5d8f96137da2a9f1f2510cfdf5a9e87e1d9b7dfa7c94c27356db7c6ebe3503ca3dc0aafab1a727c5f00e2f335e259e5f3f721"
    "78b849deefd209a15f979e560601000a52693b705ac5bcc3e76e89bb5ef2f9c326234a7293317e8f33483b6db5bfc9996df1fa9f41f070937caa8cda5409b526",
    "105900841ae8d3629305835a5d3997bdb9f35e936be2e9f55797e0e9f26b9e1351cde8359a737e5c30f9d7f7f7501ce7a6fa8355c7f7d27e6298885f5c14f686"
    "fe60d6ef8b1523dbbe8477fcc12bc8f3abea710ca91f37c9d7d7af1fbefe03b536cd0ab4e8ac9da66c9b0fdc3595b1f9e7548932da55f20daf2b307c831e6678",
    "79de8e1716db115ed20e5d6e6d9ee0e47900ec255ac775bf3f288d04867bd23d3cd966a84630532d16b2db5e8aebbf803c7f8bfbed34f93c13c75fe64fea6d72"
    "b6328ee2f88b733da1b88f3378288e6f4ffdaf20cfa371fee2efbb9a9d666c1be72f8bc34fbf38470e37e7076e68dc7f7e4fc8f405a1eac8f17b1c5e7ef000c5",
    "79dcceff62d72774182918e142851dbe405502fbc79287ce77bd823c8ff87ff1f75dc94ec7cef23fc323fe5fc6ff0cef38ffff13f1bffbf9bf459eeee40327b9"
    "ee0e1591634fc87c900e1653dee17fb4eebb38d793c1fe5e9dd9c6eb6f1abfb78af7a6fb795e58c40b43f18c7217c5fb509c7e8d78284e6f4ffd2ee4f30b5a04",
    "528f337e0f583c7d2de77027cfc3b33cfc9963fcdeecb1ac92a3fd9aafbb9f4dd192d3e3f6f15f51dcdefd3c2f87fcdc61fc24d5ae06c0455fce72c9ecb6ec21"
    "9eff0af23c3a577bd5ee2ef7dfff0e52dfaafafa15040f37c917ddd31c657852345d5267d7baf1a6ef677eb6045f97db72cfdf22456a2bbb0efa87bf7d29a2b8",
    "8edbfd43b11893cf0b1ddf0e55cdede7a832b99bcf4a49eff88709e479d4af8dc968873bb6f98b5f40f07093dcec2ffa80694444911c25595296699ee15bb3cf"
    "6d6a7fbfd5f9e4f1123c5d6ed98e16284e312107ed67fc3f0af905b7fb858bbd7420762454b822956f442acd7476c8e53d741f8fd5fe5c86d48f9be4d6e70d6a",
    "84a8d6640129d7e6330867cf7955d1bd3c16f1bc7fce1bddcbb34e3c742f8f3df55be5fd22a47edc24b7cefb3c9073642e2f66a65dbba5878d1cbeb7e1c4b675"
    "8065f72c33124ff2987bd70162503ca3dcd2fe1d4547cec779d07aef1af19cbab7a11be9e5b9e0a812f41d8afe5e6c9b7edae7729877781df55f635ad7eff2a2",
    "7b9561784639ba57f94df1d4745bf0d0bdcaf6d48fc6f38b733dc1c6f363487dabeaed27103cdc245ffcbb5c4d160055036e8de7e4a17846b95dbfcb35d3d8d4"
    "0938c8ff7f42fb7fdccfff543b54a8f0acdc28012ed1e3d3012a11ddf3d0befd1b1897bd79fb7fc639dbe2f73f82e0e126b989f76951042bad5baceb7cd60d1b",
    "f74bd3e6d10d42657b8df3cdd43fd3d906c6fdffde3f45717cb7f3fe902f0e2eb202174d75e3496937b6d7ed039f87e2f856793f0ba91f37c9d7f57b8c6790f6"
    "d96b7751dbe2f76f43f0704d2229876f31f7c6ef23503ca3fcbaf13f6517bfa41fbec59cb483f0d7478fd038deed7c4e92e96875709e668eb3b11e1b8df2f19d",
    "42ce437c8efaaf31ad2b7e6fedf7d47596dfdc3e4cc7fcbe4d711bdd669cb3974918fd9ebafbf9def7241dda8d0d4efcbee860c0fa0436186f5d78e8be1dc4f7"
    "c604e3fbcf21f5adaaa78f2178b849bee8bc96f12042862fb0649dd63eef95735bcf97e0eb725bce772c54a8e3f7f150ef76507cc7edfe0190071d8a2453b146",
    "60b72355fc74b62a8c3c341f98409e47fdda988c76b8e5b979c275e341689eb0b8fd689ee00c1e9a2758abffff78eecbab",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43112U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_kF_info.c) */
