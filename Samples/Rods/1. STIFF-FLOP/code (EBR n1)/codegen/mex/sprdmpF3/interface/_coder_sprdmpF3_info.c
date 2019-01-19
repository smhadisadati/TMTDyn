/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF3_info.c
 *
 * Code generation for function '_coder_sprdmpF3_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF3.h"
#include "_coder_sprdmpF3_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF3"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF3.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94940972223));
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
    "789ced5dcd6fe3c615e726bbc12e82b43cb44d83162db62d160db63065496b7bd1a6d587254b5eebcb926d59bba94d4a944499e45024254bbe54c71e7ac8a9a7"
    "1ef698146891f6d02e90a250fe88f4d0d35ef227a4e78aa2c636079a956c529449cf00c678fcc8f90d9fdffcdecc1bce90ba93cedca128ea5ba39f7ffc8ea2be",
    "ff29354eef9919454ff2b7286b42e57726f90f91324cf7a8bb96fbee4cf0fe34295781acf33ddd2c8882cc673b12c7aba382cc4afc7935352009322beba5bec2"
    "532aaf01b1cbd7c692ba20f22541e277c0a5424a1815a4e425d179c11019bfc79b7cf5a4d89128b5a95d3457bc5ca026fa31d2e798e7bf3ba77ef218fdd088fc",
    "79e263a609249e69b23581c924b6a25a5fae3229a314ede8a094296df665260e6afce5728cd759a6bbba1260aa864453d49aa424432b126cff31a67defccd97e"
    "3487e90175ff52e997915978f3eaeb6d0c1e3d915481f98f720aef1da47c81674a6aa0c389fc05dea736f1a2583cabfc797aa73c32898ea63222a8b222938996",
    "76a23166371858dde0181d0091033d86974446143846627591e5185eac77e49129682bd2a41e17ede0cbbd475f45ddb53b579f6fa9783d4c7df3daddf7307834"
    "22574abdd67a4ecfafade7d852b15552b7fa553976d10ec857389c59eda03065b7ea27fdd79aacf6f6b3731e1f60ea9b574f1f60f068446eb82d7545180d0654",
    "991557b491aa587505b2bc7d9e4713ae3d3039e5f73333f0a0fc0a7662fc3c1eeb8b790c15c63c3635766e33eed94b64ed8f9f11bef73adf6fa83b1a5ba8660e"
    "0fb8c332178bad85eb0d9ef0fdade3fb4f30f5cdaba70f3178342247f89e5514b15f1c5358b223577501c869392fb255380584ed536cb6efdb33da07e5f5492b",
    "8e9aac5c1b0dfc21fed026fe8b19f8506ed71fe0156a9a987bf635e4de6dfd87f88705e1b9e51f00bbd3e258762b5e0b6db4b47290cf5494fea67ffcc310733f"
    "e9d7d664b5c35f3816efb98f94a9f3eb4c89a0690aab6abc57e33d292c9e557ebdf183a11b630401b5e466dc2f72ffa3df127ef73abf9f1ea4b5a478b29f0cd6",
    "d5a2d86de5b6e5b3429cf0fbede6f715dfc581aecbff240e34bdfd240ee40e1e89033953bfdd7e9c47ca14721d942f6a1d17179f99d7ee70bcf76092072c7f8d"
    "45cc3c32c97f33c97f65e60328ffb563f3807b98f6d11389024ec76f0778751eb0d83822503466aca125c411077ff86a8dcc03bcceff07cd7d7ead58283ed92d",
    "153ae5cd67957d50dcf3d13cc0abfd1717f79ed7dede42ca3041dea72d7f7d1431f39f3836feff31069f46e4c8f85fd0621d41d4d372b623f1aa505d1aefbfb2"
    "89b78bc5b3caed8eff5185414372d10ffcf39bff927980d7fd40aedb8e47eba9ee46a910ee5713921c4c56c4947ffc80dd79c036a67e1a91dbf6030feba20e07",
    "bd94cb7637c8449cb2bbf7317834229f1aff49343c1bf759809d4ce57da8a825f0fd5f1f91f8bfe7f93eb0db58edeadb4f81da686ac524db8825d35d1fadef92"
    "7e3cbdfd38bec7cd37e6d5d77b489942ae83724193cd81aa6eececf06e7c3f8dc5b3caaf381ea80b3dbea680917930164d2de33db1bf1c7c40c6f55ee7f9add0",
    "49bfd86e0862bc143fd96dc71aa593bd04e1f95bcbf3383ce7dedba90ba3494dd3abf1fa4d2c9e556e87d74d0db9bebe4ff87c817876f9fcbb183c1a9177db7c"
    "42e956b5a7e5d3100079adb81a3aac50fee173afc45d2ff8fc615d5035bd2e589fe318d34e47ed6f78ec58bcfe47183c1a918f94713452c2511da82200ca11e8",
    "f26a5d04a74755637ff5f2f66d0daf8907ebafccc083f26beef730cde80d9a737f5c30fcd7d7f7481ce7a6fa8379c7f7dab3442fb1797696dfee05c39960205e"
    "88ae0612fef107af31f7cfabc701a67e1a912fae5f3f7cf305474d5e5478d55d3bdd726c3e70172953e7d7991263b46be44b5e5710e41adf4bcbfa793b5eda6c",
    "4764463ba0dcde3cc1d5f33c5e91755ceffb83625f11a427eddd835581ab85d395423eb3eaa7b8fe4bccfdb7b8df8e52c03771fc59fea4da64c72be3248e3f3d"
    "8789c47ddcc123717c67ea7f8db99f8cf3a73fef7c769a766c9c3f2b0e3f7a7089ed2dcf0fdcd0b8fff9791fa35f185347ae9fc7f0eafd0724cee375fe57db01",
    "a52568e1a8b4965f97f35c39f46c5ff3d13eadd798fb09ff4f7fdeb9ec74e02eff0b32e1ff59fc2fc8aef3ff1784ffbdcfff0df6703d173ac8b6d7b9a81e7fc2"
    "e6c27cb8b0e51ffe27ebbed373982cf6f7fad8315ebf6afcde2ede55dfe77969132f82c5b3ca3d14ef2371fa05e29138bd33f57b90cfcf7815681dc9fa1cb878",
    "fa42f6e10e5f44c679e463d7f8bdde11452327ef6bbee99c35434b6e8fdb077f23717beff3bcbe169476370fb69a951038ebea19299959d57dc4f39f63ee27fb"
    "6a2fdbddc5fbf7bfc7d437afbe7e8ec1a311f9b4f3966382ccaac861734ead1b2ffb9ce5e733f0a1dc91f3faa62972b2b2eba27ff8fb672a89eb78dd3f140a71",
    "fd24df0aac7395ecb32c57623772192de91fff30c4dc4ffab53559ed70dd317ff1530c1e8dc8517fd105422daaaa6c3f29b2bacecb82dc185fb7acf7fbedce27"
    "f767e041b96d3b9aa238c3845cb49fc1ff38e217bcee17ceb653a1f89e52960a5cae162dd753999e94f3d1793c76fb7309533f8dc8edcf1bcc08d1515d04ac7e",
    "743e8370779f57859ccb6313cffffbbcc9b93c8bc423e7f23853bf5dde2f60eaa711b97dde97819e65b339353deada0d183672f9dc8603c7d601669db32c6832"
    "2b53de5d078863f1ac725befef183a723fce43d67b1788e7d6b90ded68272785fbe57060570d76e2abfcd3ae94a5fcc3eba4ff5ad3a2beaf4bce55c6e159e5e4",
    "5ce5abe299e9b6e09173959da99f8ce7a7e730e1c6f3034c7df3eaed07183c1a914fffbe565d04c0d48057e339392c9e55eed4f7b5c61a1b390117f9ffcfe4fd"
    "1feff33fd75ccb976551af158194e8c8a91097886dfbe8bdfd1b1897bd79efff0cb28ec5efbf83c1a31139c2fbbcaa82b9d62d16b53feb868dfbb551f3f81a63",
    "b2fd84f351ea1feb6c09e3fe7f3f3b24717caff37e4f2e9c9e651429b6d5de4c6a1bf1ed7617047c14c7b7cbfb79a44c21d741f9a2beab788c699fb376f79163"
    "f1fbb73178f444a2199b6f29efc6efa3583cabfcbaf13fe32d7e0d6ebea5dce49fc8977b8fc838deeb7cceb2a958e5f42425ec67e21d31169337d7f3591ff139",
    "e9bfd6b4a8f8bdbdefa243965fde7b9876fd7e66061e943b15b78136e39ebd0c23e4bbe8dee7fbc093d4da46fcf42018889d9e8a01450c6f36ce7c74de0ee17b"
    "6bc2f1fd2798fae6d5d387183c1a914fdbaf65dd889096f3225be527d7fb65dfd68b19f850eec8fe8ea90a75fd3c1eeedd1689ef78dd3f0076a7c5b1ec56bc16",
    "da6869e5209fa9287d1fcd078698fb49bfb626ab1daef86e9e70dd781099274c6f3f9927b88347e609f6eaff3ffc19c7d1",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF3_info.c) */
