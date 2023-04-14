/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_loadsF1_info.c
 *
 * Code generation for function '_coder_loadsF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "loadsF1.h"
#include "_coder_loadsF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("loadsF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.63709490746));
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
    "789ced5dcd6fe3c615e7a6d9208b222d81b4d9f42bcda6c52245024b9664d95b2080be6dd9d6b7d6d67a93ca944449b4f92191942cfb521f7bc8217f400f39a6"
    "455b6c8b02593441a1de7a2dd0f4d0d30245d04bafedb9a228da1eae26a2cd11254aef018b11fdc4f98dde3efe66e6cd9b21752b99ba4551d43706fffef8738a",
    "2abdaa5d51d42b942ef4a87c8142c5acbf352a574cd786dca65e44eebb35c2fbe5e8ba2a892adb53f50b9e13d97447a8b0f2e0426404f6a29a9a24702223aac5"
    "d3164bc9ac22f15db636d4d4399e2d7202bb2b5db9d8e2061742e28aeae24253699fa34db67a5ce80894dc542e9bcb5fbda046f6d1e409e6f7bf68d13e198c7d",
    "6893fe71fc034f5312584f93a9719e547c33ac9c8a55cf967615eea85231558c9d8a9ea85463af5e475895f1745757bc9eaaa6e125a6a6245657848bf69f63da"
    "f792c5f6bf68ba36e4cea87c13f96b38a48386f4920a8eca50c868cf2106cfaa3d6f63da438f342de964e845a4f05e325d5fe2e99a9ad4a9f0ec25de2736f1c2",
    "583c54ff38b95b1ab84c479107ffe95586f7a4c2c5dd70c493f77957372a1e5592f88ad4f3b002efe1b98a4760549ea978a496e2195a68e021ba4cb293553f31"
    "9786dca15e1e7d3afff08be03fc2cee1e9b22c783d4c7d56fdee350c1e6dd2ef37f7d860215758cb17739d526ce7604f2a3c8c5eb6233b0167523b28ccb553f5",
    "bbf5f96d61da65d5df5e305d1b62f03c8dfcf57e482fdf0a4dea67acdaed87187cdaa4d7ba3979851b0c1e6491e1573825d2e17835290e860faccc5567c6fb4f"
    "6de2e5b178a8fe1a7ea3fd7b67682fcf3b86c13c6683198ee4603ff0e97ffff905f40353c273aa1fc874dbd1707dabbb51cc054eab7141f4250ef8adc5e907ec",
    "8efbb731f5d326bded7ee05e9d578d412fe5b0df9da742a4fcee2e068f36e94dfcaf0c4cc6c8f1c6cc787f0efd642cef1b869a01dfffeefecf60dcef76bef7e6"
    "1bab5d75fb8124379a4a21c13422896437067cbf3ccf3185f03d6ebe61d55eaf98ae29d3f70c3da788fa4055d52280b38bebd8f58f24160fd55f733c50e77a6c",
    "ad250ddcc383586a06f11deab7fbdf8171bddb797ed37f7c5a6837383e5a8c1ee7db9146f1f8611c787e69791e8767d55e2f9baea98befe91a4ea97383494dd3"
    "adf1fa18160fd5dbe175dd42ba27009f2f069e5d3eff36068f36e9bb6d36deea569507a513bf246595c2aaffd101b5387cee96b8eb259fdfab73b2a2d639f477",
    "1c62da49d4fffa87c4e2f56f60f068937e608cf2c008e5ba24f392d42a4b5d56aef3d249b9aaadc3db1fcf9b05d71e430cbcfe0df18cfa0f26e019fa9bc5f746"
    "6ef41596737e5cd0fffccbdb10c799d7fec0eaf85ed989f7e2b1b3b3ec76cf1748f9bcd15c78d51b5f9cfee019e67eab763cc7d44f9bf4d37baeef7df517ca4d",
    "966fb1b2b37eba496c3e80cb27a2471a6db4ab95335e57e0c41adb4b8aea453b3eb6d98ed08476187a7bf38415c141bf780aebb8eeef0f0aa72d4e586be7f757"
    "b94a2d903cc86553ab8b14d7ff1873ff123fb703f12e4c1c7f527f526d32c3957188e38f2f0d81b88f337810c72753ff33ccfd30ce1fff7badf96992d8387f52",
    "1c7ef0c305a637bb7e604ee3fe86fff0830f1edd464ec7fdfb4fefde81388fdbf95f6e7b5b479c12080bc1ecba98ad94fc3b7b4a04f81ff81f1574ddd759fee7"
    "44e0ff49fccf898ef3ff67c0ffeee7ff06f3683de3df4fb7d72b6135bac664026c20b7b938fc0febbee34b4310ff7b76488cd7af1bbfb78b77dd7c9e8f6de285",
    "b078a8de45f13e88d34f110fe2f464ea77219f9fb1b2a47404f477e0e2e953d987db7f3f342c431f38c6eff50ecf6b25e46b8e1bb72b2d46ae77448f6625a7c7"
    "ede7bf87b8bdfb795e0dfa847c6c7fb379e097ceba6a4a48a456d505e2f92798fb615fed55bfbbccbfff05a63eabf67a1b83479bf4a6fc17a6d5e24f239cc8c8",
    "a785618f97e8885595934452ebc6df9cd02e435f1fe1969b8c581b7404a4f2371f4fc037f476c70b58438e56761dec1ffef02b19e23a6eef1f72b9a87a9c3df2"
    "ae570ed23be94a91d9c8a494c4e2f40f7dccfdf05ca382fae13ab1fee247183cdaa437f7175d89ab856599394df08caab222273686df9b557ebfddf9e4de043c",
    "436fdb8fc6184e732107fde7fc7f15e817dcde2f9c6d6ff9a30f5b252157c9d4c2a5fa56aa276416e83c1ebbcf7311533f6dd2db9f37e811a2729d9718b57c31"
    "8370769fd7019ccb63136ff1f779c3b93cd3c4837379c8d46f97f77398fa6993de3eef8b929a66d219393978b41b46d8c8e1731bf689ad034c3a6799534446a4",
    "dcbb0e10c5e2a17a5bf93b9a8d9c8ff3c07aef14f19c3ab7a11dee6484c06929e0cdcbbe4e74957dd015d2d4e2f03a3cbfa8a0fef66362e734c0b9ca383c540f"
    "e72a5f174f9765c1837395c9d40fe3f9f1a521b8f1fc39a63eab76fb1e068f36e9c7c67156eabc24e916706b3cc7f27b786cf603efe816f30c2d76e53d3c8798",
    "f611e4ff5f43fe8ffbf9bfd20c664b22afd60a9210ef885bfe4a3cb2bd4079fb7318979dbffc9ff334b1f8fdb73078b4496fe27d5696254beb16d3da9f3567e3"
    "7e65d03cb6e6d1d97ec4f966ea1fda6c06e3fe3fef3c8238bedb79bf27e64ece522d21b2d98e25948de876bb2b7917288eefd8f86d4aef516c61da3795bcfef3",
    "4848ff10712caf5f69cbc39771ba359e1fc1e2a1fa9bc603b5ac7ecd46cef37be82f0fefc3b8deedfc1ed88cd79bde60f22813f727d56c4e14bbd1d802c575e0"
    "f94505f5b7fbc4e238dfc7e0d126fd73f1fc9824309c18378feb71fd9a5379fc6e89eb20067436aef3a7ff407ea6ebf99f4f0935e1586653ade8beba21756af5",
    "471d6e81cee381e7787cfb51bf0b121bcf4f7eaf8ab6175561dd3a9edfc2e2a17a7bfb740d2b39791e43e8e5f720efd2f57c7eb29f5412fcf15ec257970b7cf7"
    "28b32d9ee5a2c0e7cbc5e7efc1beab91c0be2bb4dd16fc07f65d4d110ff65d91a91fe23aa8a0fef636acd3dac48375da69e1e9b22c78b04e4ba67ee07b54507f",
    "5b2116c7ff2e068f36e9c7e7631aabb5b31be7db9d1fa627e0197a52f99886cf38e72ffd4ffff56f58b79d57beb7ba0f6ba3b35bf0eef9336139e98f8ba5ed7c"
    "50cc0729e0fb65e3fb8f30f559b5d34f3078b4493fee1c36f480a1a498e5992a3bfafebcace3f66de2bf3f01dfd01339b769ac411d3f67bff2f523980fcc6bff",
    "60753e2031bb471586d98cd6fc1b474ac9c7a60e5aa70b341fe863ee87e71a15d40fdf85755e8b78b0ce4b0a4f9765c183755e32f5f731f703bfa3b2e871a09b"
    "f23fc481c6b71fe240cee0411c884cfd769fe359efcf3ac4b48facdf2589f1fe9b183cdaa437f1becc2a4da6c516b83336aabd2552716b9e4f61029ea1b7cbfb",
    "cf19ccf9f3d8fef69b4f601e30affc6f751e10dcf4f2ebd9f55c766f6b4fd9db0f3676f2ed457a2f0b3ccfe34b4350ff7b9358decfeb183cdaa437f503222337"
    "38b1da3c762bff13cef3b492f773613367c7ffe7affe34ff77e0ff29e139c5ffa7bd93e40326516fac79ab99b854384a74d64fe2c0fff3f63ce3fcc1aaff7d0d",
    "f33b8c731a5e47fefa6e482fdf1a9597fb7c0f3138a4ce5f364e64736bdc7fdae7b70edfc2383a834d1307f909ce6b98229e537cbfd15ecf14db7c6ced38d22c"
    "e6360b6a3b16ab2ed07bb6e0f9450537be3fc7d407e72f5bc383f397a785a7cbb2e0c1f9cb64ea07de47655ae7eecfcb79cb66b11adf7972433ca37e386f9934",
    "9e2ecb8207e72d93a91ff81e151cdf7f84a90ff2fb75e9dbc45fbe3c31c8ef9f261ee4f793a9bf8fb91f9e6b54a695ff392ff3849bc687609e30befd304f7006"
    "0fe60964ea87fc9ff1a521a8ff792ff8dfeeb96ff73078b4496f9e37280a2bab7b0ccfd5345384e5c6e87b6e5d272862f150bded71c47386737c5ef042f404e6",
    "056eef0f7cbee3b307b14424d9d8ed150eceb62a5b0ff22ae4032de1f33c90f310ecf7b58807fb7d49e1e9b22c78b0df974cfdc0ebe34b43505e0f431ed0e8ef"
    "900734be3404f2809cc1833c2032f5f731f75bb56319533f6dd24fa31fb8c7299abe2133bcb37ed87fe4587ebff613eb14e4f7e3f206061f3c431b39bf9ff729",
    "f0bbfbf97dad97e213c7ddda513258ea6dd7645f402c0421bf7f099e5f4dc8e579c2b81e8787ea615c7f5d3c5d96050fc6f564eaef63ee77cdb8be2275c49ae2"
    "f0b83e47ac3ff801068f36e99feb0f92da8c8695a3fcc03214b971ff75dfe7f2c4265ed6744d99be67e8edf707570de6689cffc3d7ee409cdfedfd4042dccd46",
    "c2fbe9334ee8658e5a3521a3a64f1728cedfc7dc0ffd002a683ff090587c67d2387c600081e9cd8ee7edce0f63583c546f6b7e38b491e3f9394fef02bfbb9edf"
    "e5b6b775c42981b010ccae8bd94ac9bfb3a72cd0fbd6fb98fb81df5141fd70cf517ee744e0f749fcce898ef3fb67c0efeee7f706f3683de3df4fb7d72b6135ba",
    "c664026c2007f9f817f52d559e0eb505bc6e110f789d149e2ecb8207bc4ea67ee0f5f1a52168fe651ae23116f1201e430a4f9765c183780c99faff8ab9dfaa1d"
    "194cfdb4493f85fdb3f7ba8c3c3c4ab9dc92a59ae9771d62da4d96e7abc4d65fdfc0e0d126fdc038e58151ca7549e625a95596baac5ce7a5937255b3caecce5d",
    "ebdf10cfa8ff60029ea1bf613fa0bbd55758cef9bc9cfee75fde86fec1edfd83b213efc5636767d9ed9e2f90f279a3b9f0aa7701f6d3fe1f2a360d86",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70512U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
