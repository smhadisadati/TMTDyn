/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_inF_info.c
 *
 * Code generation for function '_coder_fj_inF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_inF.h"
#include "_coder_fj_inF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_inF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_inF.m"));
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
  const char * data[24] = {
    "789ced5dcd6fdbc8156776934582c5767968bbd8b6689b7661ec2285294bb2ecb408a06f4bb6f565c996ac646b93122951268712497df9521d7be821a79e7ac8"
    "b15ba0c5b6970dba45a1bdf51fd816d8538045d14bafedb9a228da26ab896493a24c6a1e104c264f9cdfe8e5f1376fde7c08bb934cddc130ec1ba33feffe02c3",
    "fef60f6c2cefa805864fca3730bd18f57726e50786ba26f7b0bbbae7ee4cf07e33a9570420d33d59ad702ca0d36d9ea2c55105903c7dd14c55e0594002b9d06f"
    "d298484b02d7a1ab630dc3727481e5e97de14a25c18e2a7cfc8aeaa2a2a894bf47ea74e52cdfe631b12e5d7697bb5ac126f651e453c8f7bf3ba77dd210fbe006",
    "fdd3d8c7445de069a24e56592215db09497d5021124a2dd4968542aa10ed03222254e9abf5302d93446763dd4354140dd33861417c9dbfecff29a47f6fcdd97f"
    "63a9c903ecfe959a37380b6f5e7bbd09c1c3279a8aa0fe475985f796a17e89a76aaa429be2e84bbcdf9ac40b41f1f4faa7c9fdd2c825da9248704285e48854a8",
    "b01f0a13075ecfc63645c882c051428fa0798ee0588ae04999232982e6983618b982a4b8c0586cf4832f0ed7be0cd9eb7776fbf9f2f07a90f6e6f5bb6f43f070"
    "83be59e835b6327236b095210bf94641dce95740f8b21fd91938b3fa8141ea76b58fde5fbde8fded830b1e1f40da9bd74eef43f070835e19b6c47576140c8880",
    "e4d6a591a948715d6379f33c6f14587f34b16adc4fcdc0d3f4d7f013e5cfa3b1bd88479ac18847aac52e7cc63e7f09067efd09e27ba7f3fdb6b82f91b94aeab8"
    "481d97a87038e0676a34e2fb95e3fbe790f6e6b5d347103cdca037f03dd96c72fdfc98c2e26d50915901244196232bda1450eb5fd364ffde9dd13f4dcf4c7a71",
    "5227417514f86bf84393f8cf66e06b7ab3e301dca0aa8bd9e75f43eaedc6dfd1f8b0203cbbc60781dc6f5024b913a9fab61b52c94ba7cacd7ed43de3c310f23c"
    "7aaff5a2f7c39f5896efb96fa863179f5335ac24354951a29d9aef4940f1f4fa9bc50f8a6d940842b3d23a6f63fc7fffc9cf11bf3b9ddfbbc5a414e7ce8ee25e",
    "46cc739d4666179ce72288df579bdfd75d9707ba29ffa33cd0f4fea33c903d78280f644dfb66dfe365afe30e20fd9bd7efee1aea9a3c98943fd4fdeb56502d03"
    "93d23729372d8bfbef41fa834f344da13bde0de0d4b87fb17943a12911630b2d216f38f8d5970114f73b9def8bf5233a90cfe5370f0ab97629ba573e12f2872e",
    "8afb9dfafec2f2dcf3fadb1b86ba261acfe3ba7f5d0baae58f2c8bf77f00c1c70d7a43bccf4ae136cbc949906ef3b4c85696c6fb2f4de21d40f1f47ab3f1bed1"
    "609a23d9380e7cf69faf50dceff47120d36945424ca2b35dc8f9fb95180fbcf1329770cf386036eedf85b48f1bf4a6c781870c276b412f66b3df0d5241abfcee",
    "3d081e6ed04fcdf7c46a8ecdf32cc04fa6f2be66a825f0fd1fd650bedff17cef39a86d74e4ddc78258ab4bf938590bc7931d17ade7a2f7787aff617c0f9b6fcc"
    "6baf770c75ccf0394dcf4a400d5465e5248773f3f949289e5e7fcd7880617b74b5298cdc83d0596a19fbc27e5f7c1fc5f54ee7f91ddf593fdfaab15ca410393b",
    "68856b85b3c318e2f995e579189e75fb74187634a9a93b355f1f85e2e9f566785db590edebf988cf17886796cfbf05c1c30dfa4e8b8e353b15e971a9eb1384ac"
    "94dff01d9731f7f0b953f2ae977cfe906145496658fdf73885f4d352ff1b9e5a96afff3e040f37e847c6381919e18411444e109a27428716194ee89e5494f3d4",
    "cb3ba735bc219ed67e79069ea6bfe1f90ed58d5e6339fbe382e15ffe790fe5716eeb78306f7c2fedc57ab1e8f97976b7e7f5a7bc9e482eb4e189b9673c780579"
    "7e5e3b0e20ede306fde2deeb87afffc0499de69ab468af9fee58361f80ed27c2271a25da55ca25af2bb0a04af79240bee8c70b93fd08cee887a637374fb0731f",
    "3ff612ade33a7f3cc8f79b2cbfd93a286eb054d59f2ce7b2a90d37e5f55f409e5fe1f776241ed7e4f1678d27953a395e194779fce9a52628ef630f1ecae35bd3"
    "fe2bc8f328ce9ffe7de7f3d3a46571feac3cfce88bf3646f79e3c02dcdfb5fdcef31fa0ba1dac8f6fb175ebef700e5799cceff62cbd36cb0923fc407b25b204b",
    "957c7b47928bce65bd823c8ff87ffaf79dcb4f07f6f23f0b10ffcfe27f16d8ceff9f23fe773effd7c8e3ad8caf986e6d512139b24966fcb43fb7e31efe47ebbe"
    "d34b4d74fef7ead4325ebf6efede2cde75f7f3bc30891784e2e9f50ecaf7a13cfd02f1509ede9af61dc8e7e7b428486d5eff3d60f9f4859cc31d3e0b8ecbe0c7",
    "b6f13bd3e638a544fb355f77af9a6225bbe3f6c11f51dedef93c2f07bcfc41b4b8532ffb84f38e9ce2e3a90dd9453cff29e47974aef6aadf5deebfff25a4bd79"
    "edf521040f37e8a7ddaf1c6601291a2e97b36add78d9f72a3f9d81afe92db99f6f9a21272bbb368e0f7ffa4444791da78f0fb95c443ecb363c5b5439bd97a60a",
    "e4762625c5dd333e0c21cfa3f75a2f7a3fdcb26cbcf831040f37e88de3454760ab215124fb718e94651ab0a036fedcb2f6f79b9d4f1ecdc0d3f4a6fd688ae16c"
    "fe1db6c17f29342e387d5c38df4df82287cd129fa332d5508949a47a7cc645f7f1987d9f0b90f67183defcbc41cd109d309c40ca271733087bcf7995d1bd3c26",
    "f1dc7fce1bddcbb3483c742f8f35ed9be5fd1ca47ddca037cffb4090d3643a232647af764d4b1bd97c6f43d1b2758059f72cb3122001e6dc758008144faf37b5"
    "7f47b191fd791eb4debb403cbbee6d6885da19dedf2ff93d07a2b71dd9a01f77f834e61e5e47efaf5e16f57bbae85e65189e5e8fee55be2e9e2aab8287ee55b6",
    "a67d14cf4f2f3581c5f303487bf3daedbb103cdca09ffe7b5a0c2708aa059c9acfc940f1f47aab7e4f6b6cb1d1206023ffff0eedff713eff53f540b60438b99a"
    "17f8581b247c542cbceba27dfbb7302f7bfbf6ff0cd296e5efbf09c1c30d7a03efd3a228ccb56eb1a8f359b72cee9746dda3ab84caf613ce3752ffd8664b88fb",
    "ffba778cf2f84ee7fd1ec875cf534d3ebcd38ac6a5edc86eab23785c94c737cbfb6948fbb841bfa8df513c85f4cf5abff35b96bf7f1382874f349272f816736e"
    "fe3e04c5d3eb6f9aff5376f14bdae15bcc4e3f087e71b886e278a7f3394926c2e5ee59823d4a45da5c380ca25bd9b48bf81cbdbf7a5954fededcefa06b2cbfbc",
    "7d9866c7fdd40c3c4d6f55de46f319fbfc651844bf83ee7cbef76c2602db916ed1eb0977bb9ca7c9f9a3b57317ddb783f85e2f30be7f0e696f5e3b7d04c1c30d"
    "fa69e7b5f407119220cb91157af279b79cdb7a36035fd35b72be63aa416dbf8f877abb81f23b4e1f1f0472bf4191e44ea4eadb6e48252f9d2a37fb2e9a0f0c21",
    "cfa3f75a2f7a3f5c77dd3ce1a6f920344f98de7f344fb0070fcd13ac69dfe9797e587cbc90fb7bb09f05d5f2a796e5fd67adb34a2d51564aa7e6fdc3503cbdde"
    "d43c726423fbd77151de7f917876f1bb7f27c6d43d81642313f325e56c0e804e24eaa2fd9be8fdd58bdedfd62c8be7bf07c1c30dfaffdbb71f1578920531e3fe",
    "9d65e77dccc60576eddfd419d0defd9b7ffe37ba87c1f1fccfa5f82a7f26d2a966a4286f0bed2a73dc66517cbf42efb12201cbe2f9d9bf9faedc3929d14e8de7"
    "13503cbddedc7d9c9a95ecbc773978ff09ba5fc1f17cde2d26a538777614f732629eeb3432bbe03c17417cbe5a7cfee482cfd1fd6aaaa0fbd5a6979aa0fbd5ec",
    "c143f7ab59d33ecaebe845ef6f1fa2f35826f1d079ac45e1a9b22a78e83c9635ed23bed7cba2f6e57c0782871bf4907d3993d55ae7eedf9f7b3ddfaa7d39139f"
    "b1715fce675fff0baddbde56be9ff7beb5edf67ede73e4cb84c4a42f064abb07017010c010dfaf1adf3f87b487f6efab323489bf7afb7cd1fefd45e2a1fdfbd6",
    "b43f843c8fde6bbdb87d9ea0e1dbbd7f1fcd13acc6536555f0d03cc15cfbff03ebcc7ea7",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 55264U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_inF_info.c) */
