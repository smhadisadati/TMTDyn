/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rksF_info.c
 *
 * Code generation for function '_coder_rksF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rksF.h"
#include "_coder_rksF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rksF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rksF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.7759375));
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
  const char * data[17] = {
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4d3f8784d47c36e99a266db2b4eb80cc899dc4c9b59dd84e9af4853e22c4037f000f7b9c1048"
    "7b63123c84375e9180079ef6c29fc03b769c9bc677b98b57bb2e6eee91aadbdb639fdff5e9b9bf7b7c7de25033c9d40c45516fea3ff92f296af56baa2f57cd86",
    "a207ed05ca2aa87e66d05e47fa502e51172de7cd0cf0be1bf44bb2a4f11dcdec0041e2b75a629157f48ec48afcd00c278b82c44a5aaedbe029855765d0e6b9be"
    "a62c003e2788fca63cd249087a478c8fa8861d4365fc1ea9f2a57ab625524a553d1e2e18ed5003ff18f21473fd176dfa6713e31f1ad13f8c7dce54659167aa2c",
    "2730a9d87a48ed4a252661f4422d4dcea572d1aec444648e1fed87798d65daf37301a6646894ba1a9f1347c7ff0833bed76d8e1f6da15ca12e8ff4eeac41bc23"
    "8c3dbbfeba89c1a311bd71b9ca9ca0079122b1604e0f8d2adbe0b3c2a1f90f56275dffa4f1a0821b0f1488f7ec8478d07e76021ed43f4c6eeee921d3521506c8",
    "251630a9506e331466768281f9d522a3c93228ca1d861741ffe776df5fcc6de830e605879961e361dc1cfdfec393bf42dec6a9d7f3e2ecf03a187b76e3f01a06"
    "8f46f4cbeb01b09259d9cee4137935bfbb5cb9b7d3d4a2c7e3c84cc099340e0ad3f7ca3e99cfe35b28d6f8bbb9e656fcddc0e0d1881e59072456a90852a95af7",
    "2bffe727e041bdcd78d18342e139c68c9641cca0a133f49911321ef2ffdb9fecfc41f8ff94f0bce2ff6ee72079978d972b4b81523a26676bf1d6ca418cf0ffff"
    "6d3ee3e2c16efcbd86b98e2b83f686e5af77d6ccf6c3417b6bcd291f43dc4b9871d0034d19c8b27117e916deeb48ff18cfd47072ab08f863bc270ef122583cab",
    "fe15f20520141991d5005b6478506e494cdf47dee707bfdebff527e1fb53c2f38aef579b2be95c134497eae16a6e7b3dab35a3d152fcfcf03d99bf56c1e5f747"
    "187b76fdf401068f46f4487e2fa8e19600b4a4b4d5127945289d19cf3bcd0b76b07856bdd3fb42d46183b0f132cfffe9dfbf09effb9df7d3ed6624544eb45773",
    "db8bdd524c9482f17d9020bc3f1dbcff916bbcff2e068f46f408efabbaab58650e66f7cef37b54eceeef3c3d211eb49f9e8007f54e79ffb6e9b161cc78c8f7df"
    "efbe43f8deef7c5fac2e67f624a07159598cb5a4c4423116de58277c3f6d7cff2dc69e5d3f7d8cc1a3113dc2f76ca301bad93e85c55b52491364292965005b82",
    "a501707c0d87e37b6bc2f8a0be3c1845a1ca4a9c7e2300f17b0ef13f9b800ff54ed703bc43bdae17e815dfa891e7be7e5f1f6476b35664d9f508b7b05a53f782"
    "7c6abfd13d47cf7d7b98f3c9bcb60aae0e088767d77f97913e353cced408aada601595f7eb3e7f028b67d59f2c7f307c636410d04b73a27771b076f9d32f08bf",
    "fb9ddf0f76936a1cd4f3f16059c982762dbd211d6e4708bf4f37bfcf9dbb7da093f23fd9071a3f7eb20fe40d1ed90772c73ea9ef1cdf42b1c65f60c8ff5f61ec"
    "d9f5db2c068f46f4e8be90aaf28a966781c019ae082995c1717e7d0e9cc3e259f58ef388171ce7f9becf85c801b92ff0fb7a100cd60fef46e3e16465b393dd3f",
    "4c141377773452ef3985f35997a335b2df63138fecf7b88567cab4e091fd1e77ec135e1fdf42b1f27a88d4790efe4eea3cc7b750489da73778a4ced31dfb3dcc"
    "f976fd58c0d8a711fd69ac03b3826ae82b0a0bbc8dc3de03cf3ebf655c6299229fdfc2d585e9bf307d1f79ffbe866784dffdcfef4b9d1488d7db5c2db9bcd7d9",
    "e094e0a2945d269fdf9a82f96b887b75fc24afc7e159f524af7f553c53a6058fe4f5eed8ef61cef74d5e5f945b12a77a9cd76fbbb61ebc87c1a311fd0beb41d2"
    "b8a3e19508d03d43b997f75f44fac7e33135a52adb2f2072ab9e2783f429e438a877be1e8c3accd37dfe6fae5d21fbfc7e5f07e2d266261cdadd3a14c44ebad6",
    "e0c4b4b6d53d47fbfc3dccf9641db08a751db8efdafecea43c5c7780c876ce8ee79dde1f46b17856bda3fbc3be8f3cafcf79769df0bbeff95d69061a35415d0c"
    "89cb99152953dc5bb89757c384dfa79adfa9bca7fc2e4884df27f1bb2079ceef3f137ef73fbf57d8072be985ddade64a31a44596d8f422bfb84deaf187f6a6aa",
    "4e874a105eb7894778dd2d3c53a6058ff0ba3bf609af8f6fa158eb2fb7c87e8c4d3cb21fe3169e29d38247f663dcb1ff1be67cbb7e6431f669447f0a9f9f9d6d"
    "b34aff55f985862273c8753dc28cdb5d9e2fb9f6fcf57d0c1e8de875e71474a714cab20264b95190dbbc5206f241a16478e5ecdeabd93b211eb4bf3f010fea4f",
    "b80e9861f512cf795f97d3fbe59f4b647df0fbfaa0de8b7562d1c3c3cc4627b8980a0622dba1f9c039fa3ced73ccf976fd7884b14f23fad39bd7b32f3fa050e5"
    "418357bc8dd375d7ee0f26e5eb825a36be53d3b57981fbbe501ad1a3754212c7779292361cc76387e3589b300ea87fc5b82a0b1d9e6bc8fab819c3735ed6e750",
    "a43eff14f1bc5a0fb2dd86202e357776e78522b798dcdfcea4e6dbe7e8bd9a8f31e74ff1bca546dfabd3c0d8b3eb9fab489f428e837a4195cc8272cdf86665ff"
    "d65d26b17856bd937818f1144cf3bde4a11fc97bd4fccfebeb0bf56eb65911402417a9ef34c3955cfd7eec1cf1fa73ccf924cf1f7fbdf6e234499e03d8c423cf",
    "01dcc233655af0c8730077ec3fc79c4ff87ffcf5da7b3ee02dff93fa1e52df03655af0487d8f33fbff011dac3929",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35408U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
