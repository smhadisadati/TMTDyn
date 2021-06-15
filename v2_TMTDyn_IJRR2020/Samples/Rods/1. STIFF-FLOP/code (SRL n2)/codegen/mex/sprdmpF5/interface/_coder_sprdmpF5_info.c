/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF5_info.c
 *
 * Code generation for function '_coder_sprdmpF5_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF5.h"
#include "_coder_sprdmpF5_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF5"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF5.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.88288194442));
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
    "789ced5dcd6f234915ef5966563342cbf601582d206016345a1814dbb1e3641003fefe48e2d88e9dcfd925e9b6db7627fd6177b79d381772e4c061b970e23047"
    "1609b470d9112064fe8845082e2310820357b870c14e7725a9c63576d2edb6bbfd9e34aa945fbb7ee537af7e55f5eaa3a93bd9dc1d8aa23ed3fff7e60f28ea9f",
    "ffa52ee40d3da168237d8dc2c5acbf63a4df34e591dca3ee62dfbb63e0fdd4c8576449e34e353d23f012b7d116594ee9672446e42e8ba9ca222f319256ee3639"
    "4ae15459e870d50b4d8d17b8322f72ebf2b54c86ef67c4d435d56566a01afc1d6f7095e3525ba494867a555de17a8632ec33908f08bfffee98f62910ec439bf4",
    "cf92effb1ab2c8f91a4c95f7e592e9a8da952abecc20176d6b7239574e74255f5cae72d7f3314e637c9dc082df571968d4a652159ba9a50511d5ff4f84fabd3e"
    "66fddf24d4ff81919e5efff0bc18d1ff5835d28c9e9e278d3c4a73c6e709239f36d2a746fa1d438f3effae91468ccf8d948a47d0ef3c24fc8e71ff9fee99f2d4",
    "e573baa6299f5c78a75d78af9bf25778baa62ab75981bbc2fb9945bc28110fd73fcbaeeff65db1ad2a3e41ae30822f172daf4763becd457f6085f569b22cb0f2"
    "a98f13059fc0b33e91d10486f5c94dd57761a105d12867949dc6f53f738ae40175dff8ebfc479f84ff18750e4f9779c143edfbb67ef779021e6dd2ef34b6b970",
    "a9585ada2c17dbbb89b5fd6db9b415bfaa07e24912cea87a5084bc53e5bbb5fd3609f51ad7df5e33e591a0fe83c63e7d14d1d3772e79fd9c50feb876fb0a019f"
    "36e907dda7b2c0f707258ac4080bbc1a6bf3829695fac3124ee12b53e3fd1716f1368978b8fe067e33f8f7f8c25ebec7c8603eb3c1902339d80f7cfcef3f7f02",
    "fdc084f09cea07f29d563c5acb7456cac550b79214a5c5d4be90f14e3f60753eb14a289f36e92df7030f6b828606bd94c37e779e8bd8e5776f11f06893dec4ff"
    "6adf648c92ac4f8df767d04f86f23e32d414f8fe978fbe0fe37eb7f3bd7fb31ee868ab4f64a5de504b29a61e4b653b09e0fbf969c714c6f7a4f9c6b8f67ac394",
    "a74ccf213daf4afa40551b4416a717d7b1ea1f59221eaebfe178a0c69f72d5a6dc770f1f66a929c477a85fecbc0de37ab7f37c3a78dc2db5eabc102fc78f375b"
    "b17af9782b093c3fb73c4fc21bd75ef74d79eaf2395dc3ab35be3fa969b8355e9f20e2e17a2bbcae5b48f704e0736fe059e5f3cf11f06893bed3e292cd4e457d",
    "b27b1294e5825a0a04f7f629eff0b95be2ae577cfeb0c62baa56e3f1df7148a8a7adfed73bb42d5eff65021e6dd2f78d71d037c2414d5604596e1ec81d4ea909"
    "f2c94165b0be6f7d3c6f16527d9020bcde2df150f9fb23f090fe76f13dc38d5e6139e7c705bddffdfd1ec47166b53f18777cafae254f9389b3b3c2eae96228b7",
    "e88f17a3017fd23bfdc14bc2f7c7b5e339a17cdaa49f5cbb7ef8ea070e1a9cd0e41467fd346ddb7ce0ae294f5d3ea76b06a3dd413ae575055eaa72a75949bbac"
    "c7738bf5888ca807d25b9b275ced273b24d4c746bf7801ebb8eeef0f4add262f2eb53677023c5b0d65f78b855cc04b71fde784efcf71bbed8bdf3371fc51fd49",
    "a5c15cac8c431c7f788a04e23ecee0411cdf9ef25f12be0fe3fce1bf773c3fcdda36ce1f1587efff7091399d5e3f30a3717fe43f42ff0f9f6e23a7e3febd176f"
    "3d80388fdbf95f69f99b47bc1a8a8ae1c2b2546077836bdb6a0cf81ff81f177cddd759fee725e0ff51fccf4b8ef3ff6f81ffddcfff75666f391fdcd9682db351",
    "2dbec4e4435ca898f60effc3baeff01409e67f2f0f6de3f59bc6efade2dd743fcf738b7811221eae7751bc0fe2f413c48338bd3de5bb90cfcf384556db22fe3b"
    "48f1f4899cc3edbd17b94823ef3bc6efb5b6200c52d8af396cdcae3619a5d6967c032b393d6e3fff15c4edddcff35a7851dc4ceca41bfb41f9aca3e5c4542ea0",
    "7988e73f227c1fced55ef7bbabfdf73f249437aebdde25e0d126bd69ff0bd36c0add182f314ab774d1e3a5da5245e365c9ae7563d27d45b4495f33700f1a8c54"
    "ed770476eddf7c36021fe9ad8e1788863456761dec1f7efda102711db7f70fc5625c3b2e1cf997d9fd8db50db6ccace4736aca3bfd438ff07d68d7b8e07eb86c",
    "5b7ff135021e6dd29bfb8b8ecc57a38ac2745302a3699cc44bf58be7a6b5bfdfea7c727b041ed25bf6a321861bb89083fe73fe1f16fa05b7f70b67ab99607cab"
    "b92b16d97c35ba5bcbe44ec5bc87eee3b1da9ecb84f26993defabc418f101dd40499d10e2e6710ce9ef3da877b792ce279ff9c37dccb33493cb897c79ef2adf2",
    "7e91503e6dd25be77d49d636988dbc92ed37ed3a0a1b397c6fc38e6deb00a3ee59e655899128f7ae03c48978b8ded2fe9d818d9c8ff3c07aef04f19cbab7a115"
    "6de7c5507737e4df5416dbf100f7a4236e50dee17568bfb8e0fef675dbee69807b954978b81eee55be299e2ef38207f72adb533e8ce787a74848e3f9734279e3",
    "daed8b043cdaa41f1ac759a809b2ac5bc0adf19c3c110fd75bed071eeb16f35d58acdf0938c8ff3f87fd3feee77fb6112eec4a82562dc962b22d65826c32b6ea"
    "a17dfb3318979dbdfd3fe71bb6c5ef3f4bc0a34d7a13ef738a228fb56e31a9f3593336ee57fbd5e3aa3e9ded0dce3753ff85cda630eefffdda1ec4f1ddcefba7",
    "52f1e42cd71463e95622a5aec4575b1dd9efa138be55de2f98f294e939a49fd4fb190f09f5b3d7efbe675bfcfe53043cdad05464fd459a6e8ddf478978b8feb6"
    "f1bfc12efebe8da671ffce1fb61ec138deed7cde2c9f1e2de7b5427839cf944b476525ddad481eba7f01da2f2e938adfbf4dc0a34dfae1711bc4f2d3db8769b5",
    "dfcf8dc0437abbe236c8679cf39748f8271f02dfbb9def579475952956727b3becde2e1b8b8543b53a077c3f777cff01a1bc71edf40d021e6dd20f3baf851f44"
    "c84a0581a970c6f35e39b7f5de087ca4b7e57cc750833a7e1f0ffbe92388efb8bd7f9099f5239661d2f16a70e548dd5de472fbcdae87e23b3dc2f7a15de382fb",
    "e1b76c8bf78c7ecfd6e06e0295736bbc2743c4c3f5d6ee6d40567232ee17b9ff14f6e1bb9edf4f76b26a4a38de4e2dd69492d039caaf4a67c538f0fb7cf3fb82"
    "e7e240b7e57f88030daf3fc4819cc18338903de55b6dc705539e323d87f4ae5ec73d8f39b68eab0e2e51a6601df7557141155da24c39cae7b08e3b413ca7f89c",
    "6132b1fd93e30cbf9d8bb785584c4a2c17363c14b781f68bcb6caee322968775dc71c7efc8671c8cd34760fcee7ebef72f65c22bf1939d457fece444f0378550"
    "a27ee6a1f13bf03d2eb08e3bbc7eb08eab0bace3ba030fd671ed29bf47f83eb46b5c6633ce6fdf3ce1b6f12098270caf3fcc139cc18379823de5439c7f78fdf1",
    "387fdcb638ffa8f3b16a4bd106a95be3fc31221eaeb7346fecdbc8f9f3b710e79f249e537c1e4a276b0d7f387b944f06b35aa128499d78c243f7ee40fbc505f7"
    "b747b68ddfbf44c0a34dfaffbb6f2d218b0c2f25cdf72e4c3bce63751ce0d4bd3b98019dbd77e737ff82fbf35dcfff424eac8ac70a976bc677b415b95dadedb5",
    "7918cfcf513b1e4818f6e38f8907fbf1edc2d3655ef0603fbe3de5039f0faf3fee774f2ff91cde8ba50bbc176b788a04de8be50c1ebc17cb9ef221ae830bee6f"
    "ef46ecf237b847d38c87ebe11ecd9be2e9322f78708fa63de503dfe332a97d385f20e0d1263d611f8eb15aebdefdfa1b23f090deb67d3886cf38b80fe7e3bffd",
    "03d66d6795efc77d4fd64a7bbde4df0ee6a34a369894765737c3d2669802be9f37beff80501eecd7d7a567117ffef6f5c27efd49e2c17e7d7bcaef11be0fed1a"
    "17afcf1310bed3fbf5619e60379e2ef38207f3047bcab7da8e0ba63c657a0ee95dbd5f9fca39762f0fc3c2fb5546cd1bfb369ac239ef5e0ff6ebcf2e9f8f3bae",
    "6fb16cb5166ab2f972a1a414e5403a2dac873cb45f13da2f2eb8bf7dd5b6f13bbc1f9d8487ebe1fde837c5d3655ef0e0fde8f6940fbc8f0bee6ffe19b967018d"
    "eeddbbbe9b1b8187f476c56d90cf3838cefff15fbe0d7cef76be3f5a4a17ebd5e276f6496a23f0649b2d2ed56b050fede307bec785c4f756f7efbf43c0a34dfa",
    "d1ebbbfa73b3b2ae6b75fcbf35021fe927b0fee3747ff05738a7ebfefe606d3b702c87ce6a4cf5e464677331947b92dada4b7aa73f80f63c3c4582fbdf129cef"
    "3204ce77e1f51ec37fe07cd704f1e07c973de5437f303c4582fb5fc673f1a1dbae0b407c6878fd213ee40c1ec487ac95ff3fe3a598e2",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 64512U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF5_info.c) */
