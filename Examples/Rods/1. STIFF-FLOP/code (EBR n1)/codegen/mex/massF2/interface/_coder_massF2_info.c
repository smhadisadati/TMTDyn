/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF2_info.c
 *
 * Code generation for function '_coder_massF2_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF2.h"
#include "_coder_massF2_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"));
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
    "789ced5dcd6fdbc81567d26491a0d89640dbcd1645b7eb6d11b4c8c29265d9b25b14d0b725dbfab2e48f38bb9529899268f343222959d2a53af6b087fe013de4"
    "b82dda22eda10db08b857aebb540b7879e0214fb27b4e752a2689b134d449b146552ef01c178f2c8f90d1f86bf37f3e67144dc49a6ee1004f10de5df5f7e4910",
    "cfff438ce46db520c8717997d00baabf332e1f23754dee13f774f7dd19e3fd665c2f0bbc4c7764b5c2323c9d6e71255a542a3cc5d117cd54048ee1295e2e741b"
    "3421d292c0b6e9ca48536558bac070f4ae70a59260940a17bfa2baa80c55c3bf2375ba7c966f718458972ebbcb5ead1063fb0ce505e6f9ef19b44f1a631f12d1",
    "3f8b7deca90b1ceda95315c6938a6d85a42e5ff62486b5504b160aa942b4cb7b224285be5a0fd332e569af2c7b3de5a186a32429ee5be62efbdfc0f4ef2d83fd"
    "bf8bd43579885cafca5a502dfd410dff04d3be51fbddc7e093634d43381f8d1aabf0de42ea9778aaa622b44a2c7d89f7a949bc10164faf7f96dc3d5286484b12",
    "3dac50a6584f2a54d80d853d7b3eefca46c9230b025b123a1e9a633d2c53520682cc52258fd0903c230b0d87c448a6d9c9e8b8404b4d1e120fc67ff53ff972fd"
    "5f21fbf0545914bc0ea63da3e3ee1d0c1e89e80feb07f47a3e975fdb2be45a47d19de30321bf1fb9ec47760aceb47e1098ba5ded3bf5fdb597d71f07d5f2830b",
    "5eef63da376ab71f60f049443f746be232a34c16449e62971929dc625839c92bd3055a64ca73e3fd9726f1f6b0787afd35c6cdf0df9391bd3c4f348379508369"
    "03c9463ff0d7fffefb4bf00333c2b3cb0f64dacd48a89a686f1472fe6e39c6f1bef8319b708f1f303bcfdfc6b44f227ad37e60a9cacadaa497b079dcf55341ab",
    "c6dd230c1e89e811fe9714935162ac3637debf85e36422ef6b869a03dffff1f12f60deef74bef7eed556daf2f6a620d6ea523e4ed5c2f1643b0a7cbf38ef31a1"
    "e37bdc7ac3a8bdde46ea04729da667245e9da8cac388dffce23a66c747128ba7d75f733e50653a74a52128c3c3a3b3d41ce23bc41f0ebf0bf37aa7f3fcd6ea59",
    "37dfac316ca41039db6b866b85b3fd18f0fcc2f23c0ecfa8bd1e2075e2e23a55c348554659d4d49d1aaf8f62f1f47a33bcae5a481d09c0e7eec033cbe7dfc1e0"
    "9188bedda4638d7659da3c3a5f1584ac945f597d7a4cb887cf9d1277bde4f3a52a234a7295d13fc709a69f968ebfc18965f1faf7307824a2578c51548c50ac0a",
    "222b088da2d0a6c52a2b9c17cbc37d77f3f3795470fdd144c31bdc104f6bff780a9ea6bf597c6f3c8cde6039fbe70583cfbfba0f719cdbea0f8cceefa59d5827"
    "16edf5b2db1d9f3fe5f34672a1156fcc3dfee015e67ea376ec63da2711fdecdeeba5375f50acd36c8316ed1da75b96ad07ee2175e2e23a55339ced0ecb39ef2b",
    "307c85ee2479f9a21fcf4df62338a51f9adedc3a6199b3715cbc847d5ce7fb837cb7c1706bcdbdc315a654f1278f73d9d48a9be2facf31f72ff07bab88d73571"
    "fc69fea45ca7463be310c79f5c6a02711f7bf0208e6f4dfbaf30f7c33c7ff2f31a1ba749cbe6f9d3e2f0ca837354677e7ee096c6fdb5f1c32a7f78541bd91df7",
    "1fbc7cf410e23c4ee77fb1e96d9c32923fc4ad67037cb674b4ba73208581ff81fff5a2dff7b597ff191ef87f1aff33bcedfcff19f0bff3f9bf463d0d64560fd3"
    "cd40292447d6a88c9ff6e7b6dcc3ffb0ef3bb9d44437fe5e9d58c6ebd78ddf9bc5bb6e3ecf739378412c9e5eefa0781fc4e9678807717a6bda77209ff7685190",
    "5a9cfe3970f1f4997c873bf828382a831fdbc6efd516cb0e4bc8d79c346f971a94586df19ea195ec9eb7f7ff04717be7f3bcbceee3f6a2875bf5e355a1d79653"
    "5c3cb522bb88e75f60ee87ef6aaf8ebbcbfcfb5f61da336aaf1f63f048448fe4bf508d06db0d333c2576f3238f176ff165991178abf68dbf39a55f9abe3ac62d",
    "d629bea23802abf2379f4dc1d7f466e70b58438e77766df40f7ffead08711da7fb875c2e229f654fbd81d2717a275d2a501b999414778f7f1860ee87f75a2ffa"
    "7118b0cc5ffc108347227ad45fb405a6121245aa1b672959a67986af8dae9b577ebfd9f5e4c1143c4d6f7a1c4d30dcd5f3fa4e30fdb470fcf4ff5702bfe074bf",
    "d0db4eac46f61b475cae94a9848eaa895487cbb8e83c1eb3ef7301d33e89e8cdaf1bd40851b1ca0a945cbc5841d8fb9dd7319ccb6312cffddf79c3b93cb3c483"
    "7379ac69df2cefe730ed9388de3ceff3829ca6d21931a9bcda352d6c64f3b90d8796ed034c3b679991788a279cbb0f10c1e2e9f5a6f2778636b23fce03fbbd33",
    "c4b3ebdc8666a895e1fcdd23bf774ff4b5222bf4669b4b13eee175787ff5a21f6f3fb2ec9c0638571987a7d7c3b9cad7c5536551f0e05c656bda87f9fce45213"
    "dc7cbe8f69cfa8ddbe87c12311fdc438ce72951504d5024e8de764b0787abd593ff044b598676431c509d8c8ffbf83fc1fe7f37fa9be9e3de259b99217b8588b",
    "4fac9662e16d17e5eddfc2b8ecedcbffe9a72d8bdf7f1b8347227a84f76951140ced5bcceafbac5b36ef9794eed1158fcaf663ce47a97f64b339ccfbbfd8790a"
    "717ca7f37e87cf9df7520d2ebcd58cc6a58dc876b32d785d14c737cbfb694cfb24a29fd5ef26e2c681d171f7354cffb5bcfe7775fffbb3a05ac6d4b21fb26c1d",
    "f03ea61f24a247fc81482b0cd8a0f34c4ffdc14cc9a9793df929789adeec3ae03583d9bf0ff08fdf7f0a7ec1e97e617dcbcb06b2815cf62071201d1caed776f6"
    "9a6efa1e00dee7c9a526faf1f7be65eb8277913a815ca7e9113fc053628de1cbf533a7f2bfc5799d46d6051736b337afb3ffad9feefd13f87f467876f17fb773",
    "9edca4e2d5da9ab79c8909f9d3782b70eea2f39addf23edbbb3ef830a8961f8ccbc7b6e5fd683b0190f733396f60f4f5ef38f63f141bf9e96ffb8f21feef74be"
    "df68063285261b5d3b0bd70bb9adbcdc8c46cb2efabe0bde5fbde0e6f77d4c7b90f7630c0ff27e6685a7caa2e041de8f35ed03efeb6556f99eb725cf0715a3f1",
    "9d1737c4d3da873c1fabf15459143cc8f3b1a67de07bbde0f8fed798f68cdae927183c12d14f3adf477f704592cfb254991e5faff5af61b27ff33ee7e7a329f8"
    "9ade92f340261ad4f6f39b4b5f3f857d5fa7fb0781da3d2d51d456a4b2ba712a1df9e8d471a3eba27ddf01e67e78aff5a21f871f5a16e79ffebbecc3b32c25da",
    "a971fe04164faf3777cea766253bcf730e3ef8399cdbe0787e3f3f4c4a71f6ec20eeab8a79b67d9ad9e67bb908f0fb62f3fbb2ebe24037e57f88034dee3fc481"
    "ecc183389035ed437ee7e45213dceff29a3dc773098347227a342e2449b4281f502c53199a2224d6c6d739751f7806e7fe4d9e47bc6638dbe33e7723e7b02e70",
    "ba3ff0f9ce7a9bd1783859dbede48f7b895262734f867ccf057c9f15e90721de63100fe23d56e1a9b2287810efb1a67de0f5c9a5267a5eb7ee7b5ec8f3c4e1e9"
    "f590e7795d3c5516050ff23cad697f80b9dfa81d8b98f649443f0b3fb0c448437d4da4587bc7e1e0a96ddf6f0d1fb14ac0f75b6f3ef755b1119cdbec2a3cbbf8",
    "7dad9362e367edca6972fda8b35d117d7e3ebf0edf6f2dc0fb3b1438b719e6f5fa7ec3bc7ebe7830afb7a6fd01e67ec7cceb4b428baf4836cfeb7396f983ef63"
    "f04844ff9a3f181f5f1d6115cb10f33bcff38549bc2c522790eb34bd797f70d560b6c6f93f79e721c4f99dee07e2fc6e361c3a4cf718ae93396d54b88c9ceeba",
    "28ce3fc0dc0f7e402f7a3fb06f597c67da3c5c31004775e6c7f366d787512c9e5e6f6a7d38b291edf9392f1f01bf3b9edfc5a6b771ca48fe10b79e0df0d9d2d1"
    "eace8114067e5f687e270e6ce57786077e9fc6ef0c6f3bbf7f06fcee7c7eaf514f0399d5c37433500ac991352ae3a7fd39c8c7bf686fa1f2748804f0ba413ce0",
    "75abf05459143ce0756bda075e9f5c6a82fb7d2d1c1ec4635481788c5578aa2c0a1ec463ac69ffef98fb8dda91c2b44f22fa197c3fbbd4a6c4d151f9c5862854"
    "90e73ac1f4db5a9e2f5bb6fffa1e068f44f48a718a8a518a55416405a15114dab4586585f362796895f99dab39b8219ed6fef1143c4d7f433fa00eab3758cefe",
    "bc9cc1e75fdd07ffe074ff20edc43ab168af97ddeef8fc299f37920bad785df03dedff019f5d518e",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58296U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
