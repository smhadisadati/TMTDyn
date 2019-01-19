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
                (737430.96239583334));
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
    "789ced5ddd6fe35815f72c33ab19a1054bc0ce22c4b25dd00834ab3a4dd3a645426a3e9bb4cd77a6ed7476c9388993b8f547623b699217f2c8c33ef007f0308f"
    "0b0234f00023ed0a85375e91581e781a09ed9f00cf3871dcd67772279eda716ae71c69747be7d8f7777d74fd3bc7c7c737c4ad64ea164110df50fffdf91704d1",
    "fd0f319677b4862027ed5b845150fdad49fb00e9eb7287b86d38efd604efd7937e451414a6ab681d8e1598749b2f3392da11689eb918a62af2ac400b4ab1d764"
    "08899145aec354c79a1acb314596670ec42b9d04ab76f8f815d54567a41afd1d693095b3429b27a4867c395dee6a8798d86724cf31d77fdba47dd218fb9088fe",
    "49ec13aa21f20cd5a0ab2c958aed86e49e50a112a35ea8ad88c55431da13a8885865aef6c38c42539db5551f551969a453856dc657f9cbf93fc5ccef6d93f347"
    "5b5dee11772f3b3bb99d597866ed750783474e344df17cbc4aecc27b1be95fe2699aaad82e73cc25de6716f142583ca3fe49f2e0585d126d59a238b14273542a",
    "543c0885a9bcdfb7b655a61451e4ca629762788ee2d832c5d30a479729b12953630b8d96c0589c5b07834fbfdcfc57c8d1754738bcce1788d7c58c6776ddbd8b"
    "c12311fd51e390d92ce40a1bf962ae7d1cdd3f39140b8f2297f3c8cec099350f02d3776a7cb7debf4dccbcccaeb7b790be2ef790e33579b0a3b51f5ef0fa0033",
    "be59bbfd00834f22fa911b935659353890049a5b65e5709be594a4a086078cc45616c6fb2f2ce2e5b17846fd1bac9bd1bf87637b510f758351a8c1f485e4a01f"
    "f8cb7ffffd25f88139e139e507329d5624544b74b68ab940af12e3057ffc844b78c70f588debf730e39388deb21f58a9718a1ef4120eafbb416ac7ae75771f83",
    "47227a84ff65d564b414ab2f8cf76fe03a99cafbbaa116c0f77f78f07388fbddcef7be7c7dada3ec6d8b52bd2117e2743d1c4f76a2c0f7cb731f1306bec73d6f"
    "98b5d73b489f408ed3f5ac2c6881aa32caf02d2eaf63757d24b17846fd1bc60335b6cb549ba2ba3c2883a51690df217e7ff45d88ebddcef3bbeb67bd42abce72",
    "9162e42cdf0ad78b678f62c0f34bcbf3383cb3f6ba8bf4898be3340d2bd758f5a1a6e1d67c7d148b67d45be175cd42da4a003ef7069e553eff0e068f44f49d16"
    "136b762af2f6f1f9ba2866e5c2dafae313c23b7cee96bceb259fafd45849566aacf13a9e62e669ebfa1b3eb52d5fff3e068f44f4aa314aaa114a3551e244b159",
    "123b8c54e3c4f35265f49edd7a3c8f0a6e3ebae878c36be2e9e39fccc0d3f5d7cbef4d96d16b2ce77c5c30fce2ab3b90c7b9a9fec06c7c2fefc7bab168bf9fdd"
    "ebfa0329bf2f920badf962def1072f31e79bb5e300333e89e8e7775fafbcfe805283e19a8ce4ec3addb5ed79e036d2272e8ed334a36877d42ef8bd022b54996e",
    "52502ee6f1cce23c7666cc43d75b7b4e58e51d5c172fe03daefbfd41a1d764f98d56fe688d2d5703c9935c36b5e6a5bcfe33ccf94b7cdfaae2f34c1e7f963fa9"
    "34e8f19b71c8e34f6f7581bc8f337890c7b767fc9798f321ce9f7ebde6d669d2b6387f561e5ebd709eee2ece0fdcd0bcbfbe7e38f50f4ab391d379ffe18bfbf7",
    "20cfe376fe975abee6292b0742fc66362864cbc7ebfb877218f81ff8df28c6f7becef23f2b00ffcfe27f56709cff3f07fe773fffd7e9c7c1ccfa51ba152c8794"
    "c8069d093081dcae77f81fdefb4e6f7531acbf974f6de3f537cddf5bc57bd37a9e6716f176b07846bd8bf27d90a79f231ee4e9ed19df857cde6724516ef3c6eb",
    "c0e5d3e7f21deef0e39d71bbf38963fc5e6b73dca8857acd6971bbdca4a55a5ba04656723a6e1ffc11f2f6eee77965d3cfe7a347bb8d9375b1df51527c3cb5a6"
    "7888e79f63ce87ef6aafaebbcbfafb5f62c6336baf1f63f048448fd4bfd0cd26d70bb3022df50a638f176f0b15851505bbde1b7f73c6bc747d6d825b6ad04255",
    "750476d56f3e9981afebadc60b58434edeec3ae81ffef41b09f23a6ef70fb95c4439cb9efa82e593f47eba5ca4b7322939ee1dff30c49c0ff7b5518ceb30689b"
    "bff821068f44f4a8bfe8886c352449742fced18ac208ac501f1fb7a8fa7eabcf938733f074bde57534c5700eefcf37f85f19fc82dbfd427f2fb11e79d43ce673",
    "e54c35745c4ba4ba7cc643fbf158bd9f8b98f149446ffdb941cb10956a9c482ba58b270867bff33a817d792ce279ff3b6fd897679e78b02f8f3de35be5fd1c66"
    "7c12d15be77d4154d2743a2325d55bbbaea78d1cdeb7e1c8b6f700b3f6596665811608f7be078860f18c7a4bf53b231b399fe781f7bd73c4736adf8656a89de1",
    "03bde3802f2ff9db913566bbc3a709eff03adcbf4631aeb71fd9b64f03ecab8cc333ea615fe537c5d36459f0605f657bc687787e7aab0b2e9e1f60c6336bb7ef"
    "61f048443f358fb35ae34451b3805bf339192c9e516fd50f3cd42c468d2da63a0107f9ffb750ffe37efe2f3736b3c702a7540b221f6b0b89f5722cbce7a1bafd",
    "1b9897bd79f53f83b46df9fb6f63f048448ff03e2349a2a9f716f3fa3eeb86c5fdb23a3da64a696c3fe17c94fac7365b40dcffd7fdc790c7773bef7785dc793f"
    "d5e4c3bbad685cde8aecb53aa2cf43797cabbc9fc68c4f227aaffc4ee200339e597b7d80c123113dc2fb12a3325d9329b07ded873065b7d6ef1466e0e97aabf1",
    "fe2b06733edfff8fdf7d06fcef76fedfdcf571c16c30973d4c1cca87479bf5fd7ccb4b75ff703f4f6f7531aebf0f6c8bffdfc3e091881ef103022dd559a1d238"
    "732bffdb5cbf6926febfb099b371c3e05b3fcdff13f87f4e784ef17faf7b9edca6e3b5fa86af92898985d3783b78eea17d99bd723fe3d683d9f5f735cc75e8df",
    "f7be67f8df8f76b4f6c349fbc0b1fa1e3de30ff53dd3eb03c65ff94e72fc2371909ffef6e801e4f9ddcef75bad60a6d8e2a21b67e14631b75b505ad168c543df"
    "71c1fd6b145c7c3fc08c07f53de6f0a0be675e789a2c0b1ed4f7d8333ef0be51e655d77953ea7950319bdf797e4d3c7d7ca8e7b11b4f9365c1837a1e7bc607be",
    "370a8eef7f8519cfac9d7e82c12311fdb47d7c8c1b5424852c475798c9f1fafc9a16e7b7e8fd7c3e9e81afeb6dd9f763aa411ddfa7b9fcf55378efeb76ff20d2"
    "07a7659ade8d54d7b74ee5633f933a69f63cf4de7788391fee6ba318d7e147b6e5f967fffefa68cf4a99716b9e3f81c533eaadede7a95bc9c97d9b77eefe0cf6",
    "67703dbf9f1f25e538777618f7d7a402d739cdec09fd5c04f87db9f97dd57379a0ebf23fe481a6cf1ff240cee0411ec89ef1a1be737aab0beef777adeed7b982"
    "c123113d9a17926546520e698ead8e4c1192ea93e3dcfa1e780efbfb4d8f235e319ce3799fb722e7f05ce0767fe0f79ff5b7a3f170b27ed02d9cf413e5c4765e",
    "817acf25bc9f5519ec40bec7241ee47becc2d36459f020df63cff8c0ebd35b5d8cbc1e823acfc9ff439de7f45617a8f374060fea3ced197f8839dfac1d4b98f1"
    "49443f0f3fb0c2ca237d5da23967d7e1f0b163df6f8d2eb146c0f75bafdfdf55b511eccfec293ca7f87da39be2e2679dea6972f3b8bb5795fc01a1b009df6f2d",
    "c1fd3b12d89f19e27ae3bc21ae5f2c1ec4f5f68c3fc49cef9ab8be2cb685aaec705c6fdfbe6ddfc7e09188fe157f30d9a63ac2a9962116b76fe7738b7859a44f"
    "20c7e97aebfee0aac11ccdf37ffaee3dc8f3bbdd0fc485836c387494eeb37c3773daacf21925ddf3509e7f88391ffc80518c7ee0916df99d5971b86a009eee2e",
    "8ee7ad3e1f46b17846bda5e7c3b18d1cafcf79711ff8ddf5fc2eb57ccd53560e84f8cd6c50c8968fd7f70fe530f0fb52f33b71e828bfb302f0fb2c7e6705c7f9"
    "fd73e077f7f37b9d7e1cccac1fa55bc17248896cd0990013c8413dfec5784b55a7432480d74de201afdb85a7c9b2e001afdb333ef0faf45617dcef68e1f0201f",
    "a309e463ecc2d36459f0201f63cff87fc79c6fd68e34667c12d1cfe1fbd9950e2d8db7ca2f3525b18a5cd753ccbcede5f98a6def5fdfc7e091885e354e49354a"
    "a9264a9c28364b6287916a9c785eaa8cacb2b87d3587d7c4d3c73f9981a7ebafe907b465f51acb395f9733fce2ab3be01fdcee1fe4fd583716edf7b37b5d7f20",
    "e5f74572a1359f07bea7fd3ff90e5061", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58256U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
