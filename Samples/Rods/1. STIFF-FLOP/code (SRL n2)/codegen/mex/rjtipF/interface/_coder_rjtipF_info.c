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
                (737431.32945601852));
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
  const char * data[29] = {
    "789ced5dcd8fdbc615a7133bb011a42590361f289ac669613448b0d26ab5d2ba6d507dafb4bbfa5a69a55dc5a94c4994442dbf44529f97ead8430e39f5d4438e"
    "49d1166e0fad81048572ebb540d3434fbee44f68cf152572bd643496bca4a825f51e608cc74f9cdfe879e6376fde3c8eb01b89e40d0cc3be33f9f3d75f63d867",
    "afca350c7b059b09ae942f605ad1eb6f28e596aeaeca2deca6e6b91b0adeef947a956325b22fcd2a34c592a90e53218549852518f2a2991ac7502cc14af9014f"
    "620229727497ac4d35758a26f314431e71972a716a526162975417155925ff3ddc24abe7b90e83094df16977e9cb154cb18f2c8f10dfffe692f64921ec83ebf4",
    "1f463f723539867435891ae54a46f783e280adbae2722dd891b87c321f19b0ae3057232fd743a444b8badb5b6e5755d6082d89e2635bccd3fe7f82e8df4b4bf6"
    "ff255d5d953b4ae9befc8fa37c605a069412fba552fe5c294f94f21701b57f0f11f8cbdaf74544ff704553e566ffb166e1a1ec812b9a1ad7a9d0e453bccf0ce2",
    "0591785afd8789a3d3c910ea88828be6aa04ed4a06f347c190ebd8e3dedeabb8248ea32b5cdf4532b48ba62a2e869068a2e222e97a879d0c1d511e32535964a7"
    "65c78dbe54e50e765bfdeb5727f7be0e5a8837954dc1eb23da5b76dcbd86c0c3757a3edf6ff9d352c6e74f13f95c2b2fec0faa6ce8693f320b7016f50343d4ad",
    "6a1fe6af56b4e3ed27173c3e42b4b7ac9dde44e0e13abdbccc095bd4c479105882de1227a622842d95e58df3bc5e50fd51c52c3f21b9004fd53fc73891ffbc37"
    "b597eb3dd560aef76616bb1833d68d9780efb79f03dfdb9deff7842391c8569367c5cad9692514f279eb0d12f87ee3f81eb5af58d64eef22f0709d5ec7f704cf",
    "d383dc94c2621db62a511c9b6033345155b78c6aff7883fdfbee82fea9fabad28b7293606b13c75fc51f1bc47fb0005fd51b5d0fd0069d0d31ebc6d7b8f272eb"
    "dfb03eac08cfaaf581238e5a1582d80fd776f65ae2a9874c96f841c439ebc318f13ccc6bad68c7e1fba6c57b6eebead8c5e7661a4a1479421049bbc67be2483c",
    "adfe6afe836c1bd98350adb4c558e8ffdffee057c0ef76e7f75e3121c6e8f342cc53177274b7953e6087d930f0fb66f3fb96e3e24057e57f8803cdef3fc481ac"
    "c183389039ed1b9dc79b75eeab9ceb8e9573df51605606d4f3de0f943260d9b9af48b1d3d2aefb002be288131bad218e188073df15e259c5ff04110f957ae771",
    "aa900c77e850888df8332907c57960fe6ae57a9efbaa2c0fe7becbfafbea98b130ae1f007fdffe7cefde8dfbf6c2bda2c71deaf568374f7b238da183fc7de07b"
    "adc0b9effcfec1b9ef4ce0dcd71e7870ee6b4efb63c4f330afb5723dcf05ccdb276ccab900ec139c8507fb0473dab7fbb9c04344ff4c1d77e38f4c8bf3df42e0",
    "e18a86e77ad3b70621ce3f6fdfc8f1a26b6aa135ec1b471f7fed03bfdeee7c5e6c16485f2e9bdb3dce673ba791c35281cb9d3828dfc7aef31715e75876bcbda0"
    "ababa29eef6ae3ddf702b3f21dd3fcf91f21f0719d5ee7cf5362a843d152824d751852a0aa6be3fdc706f18e91785abd517f5e6f30752059b80efcedbfff01bf",
    "deeeeb40badb0e07ebf1ee5e3eeb1d54a30ceb8995e8b873d601a37efd01a27d5ca737bc0edcadd392eaf462168fbb513260d6b87b1d8187ebf473e339d1866d"
    "e3382b182773795f35d41af8fe4ff720cfdff67cef3e6e6c77a583fb9cd0688ab918d108c5125d07c5f3611ecfef3f8aef51fb8d65edf58aae8ee93ea7ea2991",
    "9d39aa927ce3937de3f509249e56ff9cfe409dea93359e9b0c0f97c652ebc80bf863f14df0ebedcef3fb3be7835cbb41d1e17cf8fcb81d6ae4cf4fa2c0f31bcb"
    "f3283cf3decfad53934d4dd3aef1fa08124fab37c2eb330b597e5e0f7cbe423ca37cfe7d041eaed377db6494ef56c5fba7bd1d8ecb88b9ed9db312e61c3eb74b",
    "dcf5299fdfad538228d529edf77888e8a7b9e7b00f4d8bd7bf85c0c375fa8931ca132394eb9c40731c5fe6baa450a7b95eb92adfbbbabe3cfdf115f1d4f64b0b"
    "f054fd15f37b67c3e81996b3de2f187ff9cd2d88e35cd7f56059ff5e3c8cf6a391e13073d0f778931e77381bdc76479db31e3c413cbfac1d4788f6719d7e75f3",
    "faeeb33f506e92344f0ad68ed37dd3f603377575ece273338decedcae59acf1528b646f613ac74d18f4f0df623b0a01faaded83ec1cafb7bb0c7708e6bfff520"
    "37e02966b77d5cdca62a356fa294cd24b79d14d7ff14f1fc06cfdb89b81d13c75fb49e549bc4f4641ce2f8f34b5520ee630d1ec4f1cd69ff09e279f0f3e77fdf",
    "e5c669c2343f7f511c7ef2c519a2bfbe75e09ac6fd2fdeef9efcc535b391e5efdf3e7efd0ec479ecceff42dbcdb728d11b647c193f9ba99cee1c164407bd77f5"
    "04f13cf0fffcefbbd4381d59cbfff24bb8c0ffcfe67ff58a0f0bf9ff0be07ffbf37f8338f3a7778aa9b6bf1294c2bb44da4b7ab3fbcee17f38f79d5faaa2197f",
    "4f1e9ac6ebcf1bbf378af7bcf93c9f1ac40b20f1b47a1bc5fb204ebf423c88d39bd3be0df97c480a9cd861b4df03154f5fc97bb8e30781691930ef7e8545fc5e"
    "efd0b45c42bee6b37e4f45b692d57efbe8cf10b7b73fcf4b3e0f731c29ee374b3bdcb02b259958725b7210cf3f423c0fefd55e1e774ff3ef7f83686f597bfd14",
    "8187ebf4f3eed70c512c21e82e8f33ebdc78ddf76a7eb8005fd59b72ffde3c432a27bb16ae0f7ff95c80b88eddd7876c362c9d675a6e7fa5943a4c55f2c45e3a"
    "29c69cb33e8c11cfc3bcd68a761cfa4d5b2f7e8cc0c3757afd7ad1e5a85a501088418c2624896429b631fddcbaf2fb8dee270b0bf054bde17134c77016dfcf37",
    "fa5f05d605bbaf0bc383f84ef8843f65b295742d785a8f27fb4cda41f7f1189dcf7944fbb84e6f7cdf308b1095eb344748e58b1d84b5ef7995e05e1e8378ce7f"
    "cf1beee559251edccb634efb46793f8b681fd7e98df33ecb49292295161293a9dd50c34616dfdb5034ed1c60d13dcb94c8122c66df738030124fab3794bf23db",
    "c8fa380f9cf7ae10cfaa7b1bdac14e9af10e4ebdee63c1d3096f93f7bb4c0a730eafc3fcd5caaa7e4f11ee5546e169f570aff2f3e2cd6453f0e05e6573da077f"
    "7e7ea90aca9f1f21da5bd66e3f40e0e13afdfcdfcbaad31c37b3805de33969249e566fd6ef654d2d3659042ce4ffdf43fe8ffdf9bfd2f4654e595aaae53826da",
    "61e33b9568e8c04179fbd7302e7bfdf27f4629d3e2f7df43e0e13abd8ef74941e0963ab758d5fb59d7ccef1727dd236bae19db2b9cafa7fea9cdd6e0f7fffdf0"
    "0ce2f876e7fd3e9bed0d933c13da6f4762e25ef8a0dde5dc0e8ae31be5fd14a27d5ca777caef248e10ed2d6bafb71178b84eafe37d819c301d4fe6a8211996df",
    "4216ed9abf935b80a7ea8dfafbdf3298f5f1fe7ffee133e07fbbf3bf6fdf4dfb33fe6ca6102f8885a2af7178dc7652de3fcce7f9a52adaf1f7b669feff1b083c"
    "5ca7d7ad032c213428b6da3cb72bff9b9cbfb98cff7f61336bfd86d1ab3f3bfe17f0ff8af0ace2ff41bf97b84fc4ea8d5d77351de572ad58c7df73d0bdcc4e99",
    "cfa8f1b0ecf87b11f13dd4f77bdfd0fcebfb8159f98e52deb32cbf478df8437ecffcfc80e95bbe4a8c5f160bf9e9ab937b10e7b73bdfefb5fde97c9b8eec9e87"
    "9af9ec7e4e6a47225507bdc705f3572b28ff7e84680ff27b96c383fc9e55e1cd6453f020bfc79cf681f7b5b2aabcceeb92cfa39765e33b8fae88a7b60ff93c66",
    "e3cd6453f0209fc79cf681efb582e2fb4f10ed2d6ba7771178b84e3fef1e1fed0515093643135552f9bcda3fde60ffd67d9fcf8305f8aade947b3fe61ad4f27b"
    "9a2b2fb7e0dcd7eeeb03471cb52a04b11faeedecb5c4530f992cf103079dfb8e11cfc3bcd68a761c6e396e9f70d5f810ec13e6f71ff609d6e0c13ec19cf621ff",
    "677ea90aeaf7198ddee776178187ebf4fa7d83289282542068aa269b22283494cfd9f59c6005f73fcdf723be6538cbf7052f847bb02fb0fb7ae0f19c0fef4762"
    "a144e3a89f2b0de395f8fd6309f28136703e4f6414302defe7b6ae8e5d7c6ea6a144f90e7b91b46bde4f1c89a7d51bbbdf5fb59295bfe312b8fd01dcd7667b5e",
    "ef1513628c3e2fc43c752147775be90376980d03af6f26af07210f48f977c8039a5faa027940d6e0411e9039ed8f11cf2f6bc732a27d5ca75fc53a709712657d"
    "4320688bdfff3db32cbf5ffe8a750cf2fb9f7dffdfc446707fa7a3f0ace2f7dd7e928e9d776bad84efb47f50133c5e36e783fcfe0d98bfb2c0fd9de0d76bfb0d",
    "7efd7af1c0af37a7fd31e279dbf8f515aec3d6448bfdfaac69ebc10f1178b84effadf540b9c6344c4f2c83adef5eb74706f132ba3aa6fb9caa37be1e5c3698a5"
    "71fe8f5fbb03717ebbaf0331f628130a1653438ae9a75b7c8d494ba98183e2fc63c4f3b00e6845bb0e9c9816df59e4874f0cc010fdf5f1fcf5fe9d76657f38b5",
    "91e5f9398f5f077eb73dbf0b6d37dfa2446f90f165fc6ca672ba73581043c0ef1bcdef58c1527ea758e0f745fc4eb196f3fb17c0eff6e7f70671e64fef14536d"
    "7f2528857789b497f466211fffa2bd8dcad3c1e2c0eb4be201af9b8537934dc1035e37a77de0f5f9a52aa8df5941e1413c6626108f310b6f269b8207f11873da",
    "ff07e2f965ed4820dac775fa15bc3f7bb74b08d3ab94cbbcc0d574dfeb21a2dfe6f27cd5b4f3d7b71078b84e3f314e796294729d13688ee3cb5c9714ea34d72b"
    "5765abacefdeb5f115f1d4f64b0bf054fd15d781d9b07a86e5accfcb197ff9cd2d581fecbe3e8887d17e34321c660efa1e6fd2e30e6783db6e07bc4ffb7f3140",
    "0dd5", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70592U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
