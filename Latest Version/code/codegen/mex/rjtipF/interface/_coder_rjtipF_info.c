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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/2. Passive/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737443.03384259262));
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
    "789ced5dcd6fe3c615e726d9601741520269f381a269362d160d1258b22c4bde0201f46dc9b62cc9d2dab292544b499444991f12497d5eea630e39e454f4d043"
    "8e49d116db5eba408240b9f55aa0e9a1a7bde44f68cf2545d16b4e342bad495126f51eb0e0ce3e727ec3b7c3df9b79f36644dc48a56f1004f18af2e7f7bf2588",
    "4f5e554b04f132a10939bd3e471805d5df985e3790b22e3789170ccfdd98e2fd615aae0abc4c0f64adc0323c7dd8e52ab4a814788aa32faaa9091cc353bc5c18"
    "b66942a42581edd1b589a6ceb07481e1e803e15221c928052e714975515055eadfa34dba7a96ef7284d8949e3497bd5c20a6f651658c79ff1716b4cf038c7d48",
    "44ff61fc634f53e0684f93aa319e747c372c0df9aa27a996c25d5928a40bb121ef890a35fa723942cb94a7b7b9e1f524a88ac8543dbe8db7b39424313dda5355"
    "ef155b32d34e6c70af2078687b5f5cf07dd0ab2eb7895b974afba179788bdaef790c1e39d55405ed3fce2abc1791f2133c4d5313ba15967e82f78549bc3016cf",
    "a8ff30755054ba4857123dac50a5584f3a5c3808473c473eefe64ec5230b025b11061e9a633d2c53f17094cc52150fcdd6bbbcd211a40d6e5a8f8dfde0dbfb77"
    "bf0bdbdbef6c7dbf95e20d30f52ddaef5ec3e09188be5d18b48219391b0866a842be55107787553ef2a41dd93938f3da4160ca76d50fdfaf518cfded97173c7e",
    "8ea96f513bbd89c12311bdeab4c40d46191c883cc56e488aa92871436779f33c8f0aae3dbae8780faf88a7d79f9e83a7eb9fa19fa87fde9bd8cbf39e6e30cf7b"
    "9ac52efa8c7dfd2514f8dd97c0f74ee7fb1df140a272d5f4e949e5b458894402fe7a8306be5f3bbeff0c53dfa2767a178347227a84efa9769b1de6271496e8f2",
    "559911f8149f65a9aa3e25d4dbd736d9be1fcd699faeaf4f5b516e527c4d19f85b352ffc680ebeae37eb0ff006d5ba987dfd6b5c79a9f56ff00f4bc2b3cb3f08"
    "d441ab4251bbd1dad64e4b2afae874a93d8cb9c73f8c31cfc3776d14633f7cdfb278cf2da44c5cdca76918496a53a2443b35de93c4e219f5571b3fa8b6514710",
    "ba95ec8cfb856e7df01be077a7f37bff242525d8b3e384af2ee6d95e2bb3c78f7251e0f7f5e6f70dd7c581aecaff10079add7e8803d9830771206bea1f639e87"
    "755da3ac6a5d5762f8c9d5a9e37c3be2848a8d5610270cc1baee12f1ece2778a4a464afdb324739c8e76d948848f05b3872e8ae3c0f76b94ebb9aeabb33caceb",
    "2e3a9ed7fb8c8d71fb108ce79dcff7deed646027da3ff17923fd3eeb6db3fe5863e4a2f13cf0bd51605d7776fb605d571358d775061eaceb5a53ff18f33c7cd7"
    "46b99e717febe609578d07c13c6176fb619e600f1ecc13aca97f8c791ee2fe465956dcff26068f9c6ada427fb20b10e2feb3e691425bf24c2cb48279e4f9a7df",
    "05609cef747e3f691ed3817c2ebf7d54c8758bb1fdd2b190bfefa2fc1ea77ebfb8b8c7a2fded39a4accb6de47e4dee86b4eb3b968def7f8ec127113d32be67a4"
    "489761e5147fd8e568c5dfad8cf71f99c43bc2e219f566c7f7a8c1f48e64a31ff8fb7fff03e37ca7fb814caf130dd793bd9d42ce3facc639de9728b149f7f801",
    "b3f3f53d4cfd24a237ed07eed459591ff41236f7bbf374c8aa7ef73a068f44f433e33bf18663e33a4be82733795f37d40af8fe2f7721afdff17cef3d6a6cf6e4"
    "bd7b82d8684af904d58824523d17c5f7e13b9edd7e1cdfe3e61b8bdaeb65a44c20f7e97a46e2b581aaac9ee0e4dcf87d0a8b67d43fe378a0ce0ce85a5b50ba87",
    "c760a955e409fcf9e44d18d73b9de777b7ce86f94e8361a385e8d95127d2289cdd8f03cfaf2dcfe3f0acdb8f5b6794494dd3a9f1fa1816cfa837c3eb9a856c5f"
    "bf073e5f229e593eff09068f44f4bd0e1d6ff7aad2bd627f4b10b2527e73ebb444b887cf9d12777dc2e777ea8c28c975c6f81e0f30edb4b4ff8d1f5816af7f0b",
    "8347227ac51865c508e5ba20b282d02e0b3d5aacb342bf5c55cf515d5ddefef88a787afda53978bafe8af9be5a377a8ae5ec1f178cbffefe26c471aeab3f5874"
    "7c2fedc707f1d86894dd1bf8fc699f379a0b6f7ae3eef1078f31cf2f6ac7734cfd24a25fde777de7e937949b34dba6457bfbe9ae65f38117903271719fa65147",
    "bbea75c5eb0a0c5fa307295ebe68c7e726db119ad30e5d6f6e9e606b5ed72358c775be3fc80fdb0cb7dd393ad9642a357faa94cba637dd14d7ff1cf3fc1a7fb7"
    "8a785d13c79fe74faa4d6ab2320e71fcd9575d20ee630f1ec4f1ada9ff31e67918e7cf7edfc5fa69cab271febc38bcf2e21c35589d1fb8a671ff8bfddeca5f3c",
    "9a8d6cdf8ffbe8f5db10e7713aff8b1d6fbbc548fe3017c806f96ca5b8b57f2cb9681fd663ccf3c0ffb3df77a17e7a6e2fffab9b7281ff9fcefffa911f36f2ff"
    "57c0ffcee7ff06751acc6c9d1c768295b01cdda6327eda9fdb750fffc3baefecab2e86fef7f88165bcfeacf17bb378cf9acff3b949bc1016cfa87750bc0fe2f4",
    "4bc48338bd35f53b90cf47b428485dcef81eb878fa52f6e18e3f0a4daea18f6de3f77a9765d52be46b3eedf753542bd93d6e3fff2bc4ed9dcff372c0c71dc54e"
    "769ba52d61d493d35c22bd29bb88e71f629e877db597fbdd93fcfb4f30f52d6aaf5f61f048443febbccd08c3532272989c55ebc6ab3e67f3c339f8bade92f3f8",
    "661972bab26ba37ff8db9722c4759cee1f72b9a87c966d798395d2e1fe61a540ed64d252c23dfe618c791ebe6ba318fb61d0327ff10b0c1e89e8517fd113985a"
    "5814a96182a56499e619be31b96f55f9fd66e793c773f074bde97e34c3706a17b2b1ff9cffaf027ec1e97e61b497dc8ade6f17b95c25530b17ebc9f480cbb8e8",
    "3c1eb3df7301533f89e8cdcf1bb40851b9ce0a945cbe9841d8bbcfab04e7f298c473ff3e6f3897679978702e8f35f59be5fd1ca67e12d19be77d5e900fa9c38c"
    "98523eed861e36b2f9dc8613cbd601e69db3cc483cc513ce5d078862f18c7a53f93baa8dec8ff3c07aef12f1ec3ab7a113ee6638ffb0e8f71e89be6e7493bed7",
    "e30e09f7f03a7cbf4659d6ef2bc2b9ca383ca31ece557e563c4dd6050fce55b6a67e18cfcfbeea821bcf9f63ea5bd46e3fc5e091887ef6ef67d55941d02ce0d4"
    "784e068b67d45bf5fb59138b294ec046feff23e4ff389fff2bcd40b6c8b3722d2f70f12e9fdcaac4237b2ecadbbf8671d9eb97ff737e6859fcfec7183c12d123",
    "bc4f8ba2b0d0bac5b2f6675db371bfa4348fae7934b69f723e4afd139bad60dcffcdfe29c4f19dcefb033ed71fa5db5c64b7134b483bd1bd4e4ff0ba288e3fc6"
    "3cbfa81d1f60ea2711bd5b7f37f11c53dfa2f67b1b8347227ac40f88b4c27c6d3acf8ce8a8ba2b59726a3e4f7e0e9eae373bfeff81c1ec8ffffff34f5f803f70",
    "ba3f08ec7ad9603698cb1e278fa5e3934063ffa8e3a67d00f03dcfbeea62ec7f6f5b361f78038347227ac40ff094d860f86af3cca9fc6f713ee722f3810b9bd9"
    "9bcf79feeaaf8ffe05fcbf243cbbf87f38e8a7ee51897a63db5bcdc4857c2bd10df65d744eb35bbe675c7f58b4ff3d8f790f7dbfef1b867f7d3fa45ddf995eef",
    "da96efa3af0040becfec7c81c9aedf69cc5f151bf9e9dbfb7721eeef74bedfe90433850e1bdb3e8b340bb9ddbcdc89c5aa2edad705dfaf5170e3fb734c7d90ef"
    "b3181ee4fb2c0b4f9375c1837c1f6bea07de37cab2f23caf4b7e0f2a8bc6771e5e114faf1ff27bacc6d3645df020bfc79afa81ef8d82e3fbcf30f52d6aa77731",
    "7824a29f75ae8ff1c08a149f65a92a3dbd5f6f5fdb64fb567dbecf4773f075bd25e780cc34a8ede736575e6ac1baafd3fd83401db42a14b51bad6dedb4a4a28f"
    "4e97da4317adfb8e31cfc3776d14633fdc70dd3ce1aaf1219827cc6e3fcc13ecc183798235f543fecfecab2eb8df6b347bbedb1d0c1e89e8d1798324d1a27c4c",
    "b14c4d3545586c4cef73ea3ac112ce839a3d8ef881e16c9f173c17edc3bcc0e9fec0e73b1bdd8b2522a9c6c1205f1a252bc97b4732e403ade1f7acc879c8b2bc"
    "9f5b4899b8b84fd330927aa6bd443b35ef2789c533eacd9df7af5bc9cefd21a15b1fc0f96d8ee7f5fe494a4ab067c7095f5dccb3bd56668f1fe5a2c0ebebc9eb",
    "61c8039afe3be401cdbeea027940f6e0411e9035f58f31cf2f6ac732a67e12d12fc30fdc612455df1029d6de7e383eb52dbf5f7dc53a01f9fd4f3f0f50b1119c"
    "e7e92a3cbbf87d7b90661367bd5a2b15280ef66aa2cfcfe70390dfbf06dfaf2a709e278ceb8ded8671fd6af1605c6f4dfd63ccf38e19d757842e5f936c1ed7e7",
    "2cf3073fc3e09188fe07fe607aac6994552c43acee9cb78726f1b2489940eed3f5e6fdc16583d91ae7fff4b5db10e777ba1f48f007d948f8e470c470834cab5d"
    "e332f2e1d04571fe31e679f0034631fa81fb96c577e68dc3150370d460753c7fbd7fb77d3a3f9cd8c8f6fc9c47af03bf3b9edfc58eb7dd62247f980b64837cb6",
    "52dcda3f9622c0ef6bcdefc4b1adfccef0c0eff3f89de16de7f7af80df9dcfef0dea3498d93a39ec042b6139ba4d65fcb43f07f9f817f5ad559e0e91045e5f10"
    "0f78dd2a3c4dd6050f78dd9afa81d7675f75c1fdee0a0e0fe2319a403cc62a3c4dd6050fe231d6d4ff0fccf38bda91c2d44f22fa25ec9fbdd3a3c4c951cae5b6",
    "28d490f77a8069b7b53c5fb56cfdf52d0c1e89e815e39415a394eb82c80a42bb2cf468b1ce0afd7255b5caeace5d1b5f114fafbf34074fd75fd10f68ddea2996"
    "b33f2f67fcf5f737c13f38dd3f48fbf1413c361a65f7063e7fdae78de6c29b5e17eca7fd3fcaa71bd3",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70560U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
