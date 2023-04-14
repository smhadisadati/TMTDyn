/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF1_info.c
 *
 * Code generation for function '_coder_massF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF1.h"
#include "_coder_massF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.9493865741));
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
  const char * data[25] = {
    "789ced5dcd6fdbc81567d26491a0d89640dbcd1645b7eb6d116c918525cbb2652f5040df966ceb5bb11d67b7322551126d7e4824254bba54c71ef6d03fa0871c"
    "b7455ba43db4017651a8b75e0b747be82940b17f427b2e258ab639d1448c495126f51e608c478f9cdfe861f87b336f1e47c4ad64ea164110df52fefefc0b8278",
    "f11f622c6fab05414ecadb845e50fdad49f910a96b7297b8a3bbefd604efd7937a45e065ba2bab1596e1e9749b2bd3a252e1298ebe68a62a700c4ff172b1d7a4"
    "09919604b64357c79a1ac3d24586a3f7852b9504a354b8f815d54565a41afd1f69d095b3429b23c48674d95df66a8598d86724cf31dfff8e41fba431f62111fd",
    "d3d8a79e86c0d19e0655653ca9d84e48eaf1154f62540bb565a1982a467bbc272254e9abf5302d539ecedaaad7531969384a92e26babdc65ff7f89e9df5b06fb"
    "7f17d3fffb93f243dda7a1e0b81804d592f878520626e57650ebd70906d7a85d71fd22279aa6703e1e4d56e1bd85d42ff1544d55689759fa12ef739378212c9e",
    "5eff34b97fa40c9db6247a58a142b19e54a8b81f0a7bf23eefda56d9230b025b16ba1e9a633d2c53560688cc52658fd0943c630b8d86ca5866d9c9e878414b4d"
    "ee13f726ff0d3efb6af35f21fbf0545916bc2ea63da3e3ee1d0c1e89e80f1b07f4662157d8c81773eda3e8def18150781cb9ec477606ceac7e1098ba5ded3bf5",
    "f96d62fa6574bcdd46ea9a687c4fea3e7d1854cb0f2e787d8069dfa8dd7e84c12711fdc8dd89ab8c328910798a5d65a4709b61e524af4c236891a92c8cf75f98"
    "c4cb63f1f4fa371837a3bf47637b791e6906f3a006d306928d7ee02ffffdf757e007e68467971fc8745a91502dd1d92ae6fcbd4a8ce37df16336e11e3f6076fe",
    "bf8b699f44f4a6fdc04a8d95b5492f61f3b81ba482568dbb07183c12d123fc2f2926a3c4587d61bc7f03c7c954ded70cb500beffc3c39fc3bcdfe97cefcdd7d7"
    "3af2eeb620d61b52214ed5c3f164270a7cbf3ccf31a1e37bdc7ac3a8bdde46ea04729da667245e9da8caa348e0e2e23a66c747128ba7d7bfe17ca0c674e96a53",
    "5086874767a905c47788df1f7e1fe6f54ee7f99df5b35ea15567d8483172966f85ebc5b3c731e0f9a5e5791c9e517bdd43eac4c575aa86916a8cb2a86938355e"
    "1fc5e2e9f566785db5903a1280cfdd816796cfbf87c123117da745c79a9d8ab47d74be2e0859a9b0b6fee498700f9f3b25ee7ac9e72b354694e41aa3ff1e2798",
    "7e5a3afe862796c5ebdfc3e091885e3146493142a92688ac20344b4287166bac705eaa8cf6e3cdcfe751c1f547130d6f784d3cadfde319789afe7af1bdc9307a"
    "8de5ec9f170cbffcfa2ec4716eaa3f303abf97f662dd58b4dfcfee767dfe94cf1bc985d6bc31f7f8839798fb8dda7180699f44f4f37bae575e7f41a941b34d5a",
    "b4779cee58b61eb883d4898beb54cd68b63b2a17bcafc0f055ba9be4e58b7e3c33d98fe08c7e687a73eb8455cec671f102f6719def0f0abd26c36db4f2876b4c"
    "b9ea4f1ee7b2a93537c5f59f61ee5fe2e75611af6be2f8b3fc49a5418d77c6218e3fbdd404e23ef6e0411cdf9af65f62ee8779fef4ef6b6c9c262d9be7cf8ac3",
    "2b5f9ca3ba8bf3033734eeaf8d1f56f9c7a3dac8eeb8fff0c583fb10e7713aff8b2d6ff39491fc216e331be0b3e5a3f5bd03290cfc0ffcaf17fdbeafbdfccff0"
    "c0ffb3f89fe16de7ff2f80ff9dcfff75ea4920b37e986e05ca2139b24165fcb43fb7e31efe877ddfe9a526baf1f7f2c4325e7fd3f8bd59bc37cde77966122f88",
    "c5d3eb1d14ef8338fd1cf1204e6f4dfb0ee4f33e2d0a529bd37f0f5c3c7d2eefe10e3f098ecbe0a7b6f17badcdb2a312f235a7cddba52625d6dabc676425bbe7"
    "ed833f42dcdef93c2f6ffab87cf470a771bc2ef43b728a8ba7d66417f1fc73ccfdf05eedd57177997f8f3bc7c7a8bd3e44ea04729da647f25fa86693ed85199e",
    "127b85b1c78bb7f98acc08bc55fbc6df9ed12f4d5f9be0961a145f551c8155f99b4f67e06b7ab3f305ac21273bbb36fa873ffd4684b88ed3fd432e1791cfb2a7"
    "de40f938bd972e17a9ad4c4a8abbc73f0c31f7c373ad17fd380c58e62f7e8cc123113dea2f3a02530d8922d58bb3942cd33cc3d7c7d72d2abfdfec7af260069e",
    "a6373d8ea618eeea397e27987e5a387e06ff2b835f70ba5fe8ef26d6238f9b475cae9ca9868e6a895497cbb8e83c1eb3cf7311d33e89e8cdaf1bd40851a9c60a"
    "945cba5841d8fb9ed7319ccb6312cffdef79c3b93cf3c4837379ac69df2cefe730ed9388de3ceff3829ca6d21931a93cda752d6c64f3b90d8796ed03cc3a6799",
    "91788a279cbb0f10c1e2e9f5a6f2774636b23fce03fbbd73c4b3ebdc8656a89de1fcbd23bf372ffada91357abbc3a509f7f03a3cbf7ad18fb79f58764e039cab"
    "8cc3d3ebe15ce537c5536559f0e05c656bda87f9fcf45213dc7c7e8069cfa8dd7e80c12311fdd438ce6a8d1504d5024e8de764b0787abd593ff048b598676c31",
    "c509d8c8ffbf85fc1fe7f37fb9b1993de259b95a10b8589b4fac9763e15d17e5eddfc0b8eccdcbff19a42d8bdf7f178347227a84f76951140ced5bccebfdac1b"
    "36ef9794eed1558fcaf613ce47a97f6cb305ccfbffbaf704e2f84ee7fd2e9f3befa79a5c78a7158d4b5b91dd5647f0ba288e6f96f7d398f649443fafdf53c48d",
    "03a3e3ee1b98fe6b79fdefea3edd09aa656452c62c5b07bc8fe90789e8117f20d20a0336e902d3577f4853726a5e4f61069ea637bb0e78c560f6ef03fce3779f"
    "835f70ba5fd8dcf1b2816c20973d481c4807879bf5bd7ccb4def03c0f33cbdd4443ffedeb76c5df02e522790eb343de207784aac337ca571e654feb738afd3c8",
    "bae0c266f6e6750ebef371fe9fc0ff73c2b38bff7bddf3e43615afd537bc954c4c289cc6db8173179dd7ec96e7d9def5c14741b5fc60523eb42def47db0980bc"
    "9fe97903e3b77f27b1ff91d8c84f7f7bfc10e2ff4ee7fbad5620536cb1d18db370a398db29c8ad68b4e2a2f7bbe0f9d50b6e7e3fc0b407793fc6f020ef675e78",
    "aa2c0b1ee4fd58d33ef0be5ee695ef7953f27c50311adf797e4d3cad7dc8f3b11a4f9565c1833c1f6bda07bed70b8eef7f8569cfa89d7e8ac12311fdb4f37df4"
    "075724f92c4b55e8c9f55aff9a26fbb7e8737e3e9981afe92d390f64aa416d3fbfb9fccd53d8f775ba7f10a8fdd33245ed44aaeb5ba7d2918f4e1d377b2edaf7",
    "1d62ee87e75a2ffa71f8916571fed9bfcb3e3acb52a29d1ae74f60f1f47a73e77c6a56b2f33ce7e0bd9fc1b90d8ee7f7f3c3a41467cf0ee2be9a58603ba7995d"
    "be9f8b00bf2f37bfafba2e0e745dfe8738d0f4fe431cc81e3c880359d33ee4774e2f35c1fd2eafd9733c57307824a247e34292448bf201c532d5912942627d72",
    "9d53f781e770eedff479c42b86b33dee733b720eeb02a7fb039fefacbf1d8d8793f5fd6ee1b89f2827b6f332e47b2ee1f3acc82008f11e837810efb10a4f9565"
    "c183788f35ed03af4f2f35d1f37a08f23c279f439ee7f45213c8f3b4070ff23cad697f88b9dfa81d4b98f649443f0f3fb0c248237d5da4587bc7e1f0896def6f",
    "8dbe628d80f7b75e7feeab622338b7d9557876f1fb4637c5c6cf3ad5d3e4e65177b72afafc7c6113dedf5a82e77724706e33ccebf5fd8679fd62f1605e6f4dfb"
    "43ccfd8e99d79785365f956c9ed7e72cf3073fc4e09188fe157f3039be3ac22a962116779ee773937859a44e20d7697af3fee0aac16c8df37ff6ce7d88f33bdd",
    "0fc4f9fd6c387498ee335c3773daac721939dd73519c7f88b91ffc805ef47ee0b165f19d59f370c5001cd55d1ccf9b5d1f46b1787abda9f5e1d846b6e7e7bc78"
    "00fcee787e175bdee62923f943dc6636c067cb47eb7b075218f87da9f99d38b095df191ef87d16bf33bcedfcfe05f0bbf3f9bd4e3d0964d60fd3ad4039244736",
    "a88c9ff6e7201fffa2bda5cad32112c0eb06f180d7adc2536559f080d7ad691f787d7aa909eef7b57078108f5105e23156e1a9b22c78108fb1a6fdbf63ee376a"
    "470ad33e89e8e7f0feec4a8712c747e5979aa25045bed709a6dfd6f27cc5b2fdd7f7307824a2578c53528c52aa09222b08cd92d0a1c51a2b9c972a23ab2cee5c",
    "cde135f1b4f68f67e069fa6bfa017558bdc672f6e7e50cbffcfa2ef807a7fb07692fd68d45fbfdec6ed7e74ff9bc915c68cdeb82f769ff0f6e585367",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58320U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF1_info.c) */
