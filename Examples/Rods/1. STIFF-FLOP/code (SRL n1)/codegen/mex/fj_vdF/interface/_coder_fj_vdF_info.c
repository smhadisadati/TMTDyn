/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_vdF_info.c
 *
 * Code generation for function '_coder_fj_vdF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vdF.h"
#include "_coder_fj_vdF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_vdF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_vdF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.882962963));
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
  const char * data[18] = {
    "789ced5dcf6fdb541cf7c686b6c3980fc03421011b68429a54276ddaae9c9aa4499a76f99dfe58c7c8ecd84ebcda7e89eda4492fe4c8810b174e1c760424d0e0"
    "c22410ca3f310e70a990b87185334e1ca7f593df92ce8e53a7ef2b55af6f5ffb7d9ebffbbecffbfafb9e5f890bc9d4058220ded07fae7f4610e457445fae1905",
    "410eca8b845560fd85417913aa9b7299b864b9efc200efeb41bd0c648d6b69464514642edd90184ed12b322d71c366582009322d6bc5768d23144e05629363fb"
    "1a5e10b9a22071f7c189cabaa057a4f809d5b0d253f57e8f56b9f27ea121114a553deeae78b2420cecd3936788e7bf34a67dd208fb9090fe61ec115505124755",
    "6956a052b144586dcb656abd570b3734504c15d7da3215052c77b21ee1349a6a06e70254b9a7e19f949a6c7c4e3aeeff6344ff5e1fb3ff7069ca55e2ca89dad2"
    "ea28bc71edf51a028f1c6868c6f88f720bef75a87e8c676858d06044ee18ef1b877861249e55ff30797f57778986aa502228d322950a17ef8723547e3e10bcc7",
    "501a0022035a14278994283094446b22cd509cc837644ab751cf05fae29d1f74bb5b775e84bdf53baffd7c7a782d447be3fadddb083c12d2d71986e543352653"
    "cc16941c082612e2fd50e4b81fd91138a3fa4120ea5eb58fc7af55acfef6fe90c73b88f6c6b5d37b083c12d2f7a62d654ed0830145a6c539418d3404514bca7a",
    "38c02942796a3cffdc215e1e8967d59fc24f7a3f77fbf6a2ee9a06a36083998ee39ddf747efef70fccfb7ee7fd4cb31e0df3ebcd7bc55ca85d8e49f27c7c4f5c"
    "c7bc7f3e783fe01aefa3de0749480ff1beaa9b8a56e6cce8de797c0f0baa3fa6b8f5be971a8167ea9df2fe5dc362439ff130cefff2cf8f31dffb9def9f2c2672",
    "1536b79d5c89a7832bdb4c6eb1c267a398efcf1bdf7f8e686f5c3bdd46e091901ee27bba5613db853e85c51b725913806c5c67f6abe6b05fd747f4cbd4f303f4"
    "52959659fd05c0adf87f6b04bea9773a0fd818d2ebf9e0af7f98dff17c30213cafe683cdede03e081df2347b70b0939f0fa556e25b0f62b3331fe0f16c5f9a62",
    "f5bf45d7e6870f107824a487e7872610d8b0a2d0edb8486b1a270b72a57fddb4de0b9cfacff6083c53efd87f6c0ce7f17a50e73f3c1ff87e3e38dc585f886ed5"
    "76a51c9361c3bbfc7aaa256566281f84e703fbd214abffadcf5c7ee855d705707ec8beff383fe40d1ece0fb9d3bed3718cf7f51832aebd2e23f0c881a6060efa",
    "bbbff0be1ebb7c21a8a954df4253c81776be78b184e379bff3f94e759b5b2ae40a8bf962aeb1bbb6b9b70d0a5b33c4e77e1dbfa83cf7b8fe7611aa9b7215bade"
    "903bab46791beff319fc3bdee7635f9a82f7f9788387f7f9b8d3bed3b87e03d13e09e91dcf03b7785133835ec263bfeba456ddf2bb1b083c12d2dbe6736215df",
    "e67126e027b6bc6f1a6a0a7cffc39d4f71dcef77be0fe42bc1a6b6b102944a552dc4e94a249e6cae61be3f3fe398b0f03dea7d635c7b5d83ea04749da91754d9"
    "0854b5de977bfecdd727917856fd29e3015e68716c0de8ee41592c358dfd60dfefdcc471bddf793eb1b0df2ed42b82182d46f7f3f548a5b8bf15c33c7f6e791e",
    "8537aebdae407562789da111545ed05f6aaa7ecdd7af21f1ac7a27bc6e58c8f004cce7b381e794cfdf42e09190be59e762b566595dd93d580020ab16820b0ff6"
    "88d9e173bfe45d8ff9fc162f28aac60bd6e7788ce8a7abfed77dec5abefe5d041e09e975639474239478a08800d44aa0c929bc080e4ae5def919d3db87d97d45",
    "3cb3fdbd1178a6fe15bfeb30dce82596f33e2ee8fefaf7659cc739abf3c1b8f1bdba196bc5d60e0fb31badf9506a3e10cd85838119da9f7f84b87f5c3b7610ed"
    "93907e72e3fad6cb2f285539b1c629defa69c2b5f7814b509d185e67687ad16eaf9cf2ba8220b35c2b296bc37e3c75d88fd511fd30f5cede13e6240ffde2395e",
    "c7f5ff7c5068d70469b19edf090a0c1b4aeee5b2a9e02ce5f59f22ee3fc7e39638f9ddaedff3f8a3e6937295eeaf8ce33cbe7d690acefb788387f3f8eeb47f84"
    "b81fc7f9f6cf3b9e9f265d8bf347e5e1f50797e8d6f4e681339af71f9eeba1ff421936f23aefdf7d7ee32acef3f89dff957aa0f6445043616929bb2c6799dd85",
    "cd6d7586cedf3c42dc8ff9dffe79c7f2d38eb7fc2fc898ff47f1bf207bceffbf60fef73fff57e807cb99859d747d99096bd1453a13e242b9c4ecf03f5ef7b52f"
    "4db1f8dfd163d778fdb4f97ba778a7ddcff3d421de2a12cfaaf751be0fe7e9278887f3f4eeb4ef433e3fe414a03624eb73a0f2e913f90eb7fbc96abf5c7de419",
    "bff30d51ec9578bfa65ddcaed668a577226bcf4a5ec7ed9d1f71dedeff3caf2dcd4bf9b59d44756f011c36b594144f05b519e2f96788fbf177b527fdee78ffbd"
    "d373333f42e09190deee5ce58820d30a74689c5bebc64ecf55ee3ac47f3802dfd4bb72ee9e9d21072bbb1ece0f3f7dabe0bc8edfe7875c2eaaed679f049699bd",
    "f4669a29d2f73229353e3bf34317713f1ed756b1fae1b26bf3053e67d9107ccef2c4f0fa725ef0f039cbeeb4ef743c1711ed9390def97b8391212af122a0b5d2"
    "f00dc2dbefbcf6f0b93c0ef166ff3b6f7c2ecf24f1f0b93ceeb4ef94f77388f64948ef9cf765a0a5e9744649ea43bb62a68d3c3eb761c7b5758051e72c0baa4c",
    "cb847fd701a2483cabded1fe9d9e8dbccff3e0f5de09e279756e433ddcc848a1f66e289057e61bd120b7d294d2c4ecf03a1ebf56b1fadb87ae9dd380cf5546e1"
    "59f5f85ce5d3e219725ef0f0b9caeeb48fe379fbd214543cdf41b437aeddde41e09190defeef65f122008605fc9acfc920f1ac7ab7fe5e56df62fa24e021ff7f",
    "87f7fff89fff99ea5276571635b600a458435e5f6062918d19dab77f06f3b2676fff4f27ed5afefe4d041e09e921dee714058cb56e31a9efb3ce58dcafeadde3"
    "58ca60fb01e7c3d4dfb7d914e2fedf361fe03cbedf79bf25e70e0e53352992a8afc5d57bd18d7a130466208fff3fbb5fc3fe",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 38440U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vdF_info.c) */
