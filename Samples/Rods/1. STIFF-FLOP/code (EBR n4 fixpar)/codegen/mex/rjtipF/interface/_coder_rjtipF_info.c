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
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[28] = {
    "789ced5d4d6ce3c615e6667f922d9076d1b449166dd3751a6c9b6663fddab273b2ac1f5bb665fdfa3749254aa224dafc914949967d2250a0e8a1871e7be8618f"
    "39e450e4d4a3805e8a9c9ba6280ad4871e829e7a4c811e2a896f6c91ab5933ab1165523380f1f4e60de71b3e0fdf1bbe19ce30b712c95b0cc37cbbf7d7a7fff9",
    "2f3348afea847900f425c698ccf25b40df35f128dd65ee18ae43f2df032dcb5293eb347546e0256ebb259638a5c748acc85d565391455e62a566feacc1310aa7"
    "ca429bab0c24555ee0f2bcc86dc943cc3adf63c4f890e892e98bfabf2375ae7c9c6b898c5257af9a2b0c33cc907e7e87b9ff3b16f513c2e8e701e421f987b18f",
    "231f7876544e513daaea0bf997fc9e28a71e37e586c737ff28974fc4e3efc7b752694f59ae701ee5a8c937e2f3e2653b3fb93dba1df72cb693c7b4f33ed0f5db"
    "c3b92b2b03a2458102cf848107caac020f9489000f9489018d035d033950e623a0eb3a5d015e035e43f204d08f816e4079e035e03524df041ee8ca2f80df020a",
    "3c93041e285300ba0dd701af01af21790a78a04c11681aae035e03be0b5443e532500ea80694c9423e500d6817e5e7201f68172893877ca05da0cc0e5c07b40b"
    "94d9857ca01a5006f4f208daf9146817b59b0539d015a01ad0a740bb402f90bca4d322073cd0a7402f803255a81f6811a806f429d00ba04c0dca032d02d5803e",
    "057a0194a94379a045a01ad0a7402f80323c9407ba02943982eb8132c7500e68bab1829edba25ee085edcbcb269eb92cf7f2204fa9f06dbec231a4f0ee99f82b"
    "bc7b83bc8adc2a09dc95fdfcc39878092c9e9e87e41f26b6f6072634adc83585151ff56dbdea4986f35be1554fd6eff5854a9ea62c0b25b9e3e144c123f0258f",
    "c83605b6e4911baa07f4d4b3a87aba4e5f56edaa99a2749f79057e696f7c2bf345d83e3c3dcd0a5e07539fd5fef77d0c1eea7f48be749aa9eeec071743eb6d21"
    "bb1c5d5ada9277ca43ed485f83735d3b180c6f57fd4e7f8e1b98f659ed772f997894d0f8e88121f7ed159d3ebeb4f31aa67eabfafb31061fe90fc9fba343659e",
    "ef0dae158915e67975b5c50bcd84d41b5e730a5f9e9a1ff8e39878fb583c3d0fc9bf71ffe9ffbd37d09ae73da4368f596df3a28dfee027fffa3bf50737d51fbc"
    "8ec143fd10c953ed9348b8bade5eca678267e59828f9e387c23af50737c51f1431ed23dbef7e4eccfe3fc2e0217d21b9c9feab6556e03a8d882c36d826dfb3c8",
    "d3b2ffdd31f10eb0787a1e9293b1ffcfa86d1afde7f3cf5efb2bf50313c2b3cb0fd42b0de570ff3c56ae85a25ba1b3408b0d679656a91f982d3ff0c10aa97ef7"
    "5d0c1ed217929bfc40efeef57ca7c68136b1787a1e9293b1ff3d75414fa1f6de1d7876d9fbdaeaea59251488c50e3bfef6fa669e8f1e2859178dfb9d321f56c4",
    "b48368ff2218c7bf8bc17bd093f4f31af2e96076745af6fb9331f1d6b0787a1e928febe7077ab2b51f685fff6991da6da7dbedbdfa2eb798cbe416b2f94c6b3f"
    "ba79b82be77622eeb1db4e7d7e69dc9ec6ed69dc7e149e9e66058fc6edc9d43fee7b78dac43343e586db4fc80fcc5585e6e0a7adfd4e4b128bd7bc81c143fa42",
    "f211717b5689d51c1baf99583fc1c6ebfbeab2d5dedfffcd3fa8bd77babdf76e9f86c43c2f1e6ef2d94a6c335ace55ab67343e3f43cf3163b0f7b8f70dabfa7a"
    "d5c43343e56e0dc97955d287a8cdfeca76e7c6e553583c3d0fc95f683c50e53b5ca521f7ba87c7a02f7be37c0fe30fa99d77ba9d5f0b1c9fe54e6abc10c9478e",
    "b327abb5fcf14e2c4aedfcacda791c9e557dbd62e299cb72af0cf278b5caf75e67ea4eb5eb1b583c3d0fc9c7b7ebba9ed0c43cb5ebeec0b36bdd7dfb848b35da"
    "657579ff3420cb6935e70b1c1c32eeb1ebce8abf5ed9f5b92aafa8cd2a6f6bffeb1689c5eddfc2e021bd21794f0d85deed17aab222c872a320b739a52ac8a785",
    "72ff3bd3f1c7f5e6846b0f4aa4d65b164dbc190fc9c789f341377a8efe6c8de77cfae55d3a8f7b53fd81d571beba19ebc4a2e7e7e98d8e3f98f47b2399b0cf1b"
    "738f3ff80a73bd553dfe0a533fd223924ffab99e7b7e81429d131afd052ff6f6d73562ef07774c3c7359eecee5fb419f9ff23c032f55b84e426a125b2710bfa6",
    "1d484ee2bda1ffce6063ff7887ceef3adf3fe4ce1abcb87092ddf3f1a54a30719849277d6d17c581e8f36b4cc6fee6754d9cff3aff52aeb3fde5a234ce8fa128"
    "d178903d7834ce4fa67e3afe37de17d9fe9a2036febf2e5edfbb7591ed38d71f4c747e00f523a1f7c3a36bcafef901ed9d7bf7693cc8e9fe4039f1368e783518",
    "1617d321295dda0f6ceeaa2e5adf43fd81f1bec8ce17dbeb0f7889fa036bfe8097a6e00f7e4afd81f3fd418d3d08a5027bdb27a152b819596053412e9859738f"
    "3fa0f3c5a3294a86fe77512466dfbf69bc7f5c3cbbbfdf75715c90c6f5278847e3fa64ea1f777c9636f1cc50b9e1f63bfabb2de66a7de7af31f559d5d7cf3078",
    "485f486e9a4f651b0de16c959758e52c37f06df196546ef2b2446adee13bd7b40bc9ab805ba8b35245b8dafff9cf63e2b3d7e0233999f101569dd3d8a7f98bff"
    "d17d1e1cef27ce39560e4bdb81c366ade65ff32653959d3d9f8bfc441773bd553d1e62ea477a4472527e427f03285405996d16d026378ccdfdb07b48bff71d13",
    "6f62e38b1bf3fd08fdde779278f47b5f32f58f1bffd9c3d48ff488e4a4ecbf2437b7d9ed9492e83ddab59ef1b737bebf472cfe73ddfe6dbc2ab112e3dcef7ced"
    "d8a715e2fb7d4d4d637c4fe34013c4b3eb7bb093702b2506cff683deace26f457cdc725bdc66dc63dfe9733cbafdc67ef70eb1efc0e8fe6d383c3d8feedff6a2",
    "787a9a153cba7f1b99fae9f87e34450937bed730f559d5db0f3078486f483e32ae335f1564590f6c39d50fec60f1f43c2427e307ded3f5e619e86d3086b0d10f"
    "bc4ebf0370be1f28d517d3fb92d0ace46431d692d603a5d8ea868bd6f9dcd878ed4d9a0fd6b689c5f5bf87c143fa427293fde7144536acb32c8ed98e6fbaaef3",
    "468effd55e23b98a47b7fa60fbcd2e60a0395bc7ff72f7319ddf75badd97f20719d67fb07e1868b75bb1fdb62f206ef02edac79f9ebf3299f357ae3d479deb19"
    "ad8673cf519fd8f959cfc4fd4053b69f9fa5fd7bfe9f74dcee74fb9df01e2db7cec201c91bf06e9f367db132d7115cb47f0f7d8e47b7dfd8ef9e101bb7bf89c1",
    "43fa4272d3b85d62951a2f95ebc7e3da7b73c2b5032552ebb83eba060fc9898fdb2f35a7771c1bedffed27d9bf50fb3f213cbbecff59e734b1ccc6abb5056f39"
    "15937347f156e8d445f6bf8bb9dea9cf35ae5f58ed87b731f783cee77ad390fbf68a4e1f037d426cfc7fddfa1d14c177eaf8df9e79ff6a4b1a8ad9f7938df6ea",
    "fde8633afe77bafd5f3a09a5f2274274e178b59ecface59a27d16839ee1efb4f9fe3d1ed37f6bb4774fd0e94b991f17bba7ee732cd0a1e5dbf43a67e6aff47b7"
    "7f52eb376fcaba1d73c2b50725ba6ec7d86e0bf69faedb99201e5db743a67e6aff47b71f67ff7f8ba9cfaabedec5e0217d21f9a87d1c8c5b0e24a4b4c0963928",
    "8fdad718b37dd3decfa1740d3e9213dccf61a45aa770fe57e07481aef771babfd8dad82c1f9ca497c307c9a0a2fa1bbcbf1dda70d17e0ef4f91e7d5fd6fae3bc"
    "ebde23103e5dff6f6c277d8f70061e7d8f2053ffb8ef11b3b18e68f1d2fe8fbb1fdc1c060fe90bc9cdef11aaca29cd5d56e02b39fe9c0b2b3528372d3fd01d13",
    "6f62fb438d1e4f3ca3be298c233effec35fa9ee0747f90e44b89dc46ecb0b12eaec596975733edd3f365177d17d0c55c4f9f6b63327e1fb642e7991932ef0774"
    "9e7952787a9a153c3acf4ca6fe71e3469c896786cadd1a924fce1fccf16a5fdeab54606cee8f2b07b6ad2beddf6495a1eb4aadec27d5d314dd17ce657876d9fb",
    "854e52881fb72b4789c5fdce4645f107a5dc225d573a43cf713fd17de1e878dfd86e3ade9f2e1e1def93a9df25e3fd92dc922a2a63f7783f43cc2ffc088387f4"
    "88e4cff805d8202f22f474c33877bfa05d2c9e9e87e4a4fcc2b0da6c3e37eceb3bf43c48c7fb85b8b4955e0def6d9ff3622775d4a888a9e6f6998be605a85f18",
    "7d5fd6fcc20eb1389095f37fe979f0f43cf89b627fedc6a3e7c193a99fdafbd1f765a93f6af6da7b7ade3b3deffda6d85fbbf1e879ef64eaa7f67ef47d591bdf"
    "ef128bfbfc108387f488e4e6b88f54e13a09a999e504b9d1974feb3be3ee0be2a1ba8a26de8c87e4c4f7a53268d0d679819da044e7059cee1fb6b6e2915038a9",
    "6c54b744554cd7ebe17ddfb98bde07bec25c6f558fbfc4d48ff488e4937eaee7f41382cbfd386fa12c4b4d9697d4022a84a2e636f7d70b8e98ff7888c1437a46"
    "7293ff186825d9cb1340eed479832c164fcf437232e3902bb54de1bd827e5f36413cbbfc467b29100c711b9ba96a74b9791862b35b115e74d17cf2df30d75bd5",
    "63c7c43343e586ff4f13f71bbc5a50f99ac4558ccec2d6fed92dd3b892453c1a57228da7a759c1a3712532f57731d7d3efc98cc9d80fd7a89db78847ed3c693c"
    "3dcd0a1eb5f364eaef62aea776de988cf3c449ba2ec8221e5d17441a4f4fb38247d70591a9bf8bb9deaa1e0f30f5233d2239c1fd82e6daac323874a6d050e48a",
    "e97e8a98f692ed8757711b0d539f55fdbd85c143fa43f29e4a0a3d4b56a8ca8a20cb8d82dce694aa209f16ca75ae7c4ce7879fdb7ff461c373f467ebfcf0a75f"
    "dea57ec1e97e41dd8c7562d1f3f3f446c71f4cfabd914cd8e775c17964ff07e59313db", ""
  };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 64008U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
