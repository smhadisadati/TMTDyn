/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF6_info.c
 *
 * Code generation for function '_coder_sprdmpF6_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF6.h"
#include "_coder_sprdmpF6_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF6"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF6.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94942129625));
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
  const char * data[20] = {
    "789ced5d4d73e34819d62c335b33b5b5a003b0b5050535404d410d15f92b4ee600f82376ec248eedd8133b9e5d12c9966d25925a96e4af5cf09103074e9c38cc"
    "71972aa885034c15d456f811cb81d35cf8097046b6a424ea728f95489623a5bb2ad5eebc523fed376f3fdd7abad5211ee40b0f0882f8baf6f3d75f1144e23362",
    "963ed4338234f2f7086b82ed0f8cfcbb50d94c8f888796fb1e1878bf37ca4d20aaec48d50b3c27b2fb7d816165ad20d2027b594d0b089c488b6a752cb184cc2a"
    "801fb0ad99a5cdf16c9513d83d70ad90e3b48290bd66ba2c4c4dd3cfe92edb3cabf40542ee2a57cde5af1708c33fd3f405e2fb3fb4e99f12c23f24647f95f994",
    "ea0281a5ba748ba30a99eda432169b546e5a4af655502d54b7c62295062df67a39c5aa343508af85a8e6d4a248724b90b2f135c16cff1b44fbdeb7d9fe0f10ed"
    "7f62e4f5ebbf9c2413fa878491ffc2c8d346beaee79394518e1979dcc8378dfc8591ff3c617e8f13443bedfe1d1e4165e2f23add2281e12cfadcc27b1f2a5fe1",
    "e99616e8333c7b85f79943bc2412cf6a7f95dfab6ba1d657648a074d9aa70ac9ea5e32451d4442e14d865201e01930a25881a7788ea1045ae56986029242cd3c"
    "b42618f52cf293ddf88273333d211e1b9f26bff92afeafa477787aba2f7823447d76e3eedb083c12b2d7ba876cbc52aeac1f54cbfdfad66ee310545ea6afda61",
    "f2200a67513b0844d9abfafdda7f2544bbecc6db7b50d94ce6f8405a7efb2ca1e73fb8e4f509a27ebb7efb3e029f84ecd3e1515ee3b449872cd2fc1aa7a4fa1c"
    "afe6456ddac1ca5c7365bc8f1a9fede21d20f1acf61bc4cdf4e7f9cc5fd473d36114ec3033903c1c07fef6df7f7f85c78125e179350e1407bd74b29d1b6c56cb",
    "b171332388916c83cf05671c70fabcb083a89f84ec8ec781a76d5e3527bd84c771372924dc8abb8f1078246487f85fd15c46cb99ceca78ff0ec6c95cde371db5"
    "02beffd3b35fe279bfdff93e74d0090fd49d1740ee74954a96eea4b2f9c116e6fbfbd38f090bdfa39e37ecfaeb43a84c40d799764e11f589aa3a550e57a7eb38",
    "8d8f3c12cf6abfe17ca0cd8dd89604b4f0a02c9e5a81be43fcb1f6319ed7fb9de7b7a367e34aafc3f1e96afaeca097ea54cf5e6630cfdf5b9e47e1d9f5d763a8"
    "4c5c5ea75b38a5cd690f355dbfeaf55b483cabdd09afeb1ed22301f37930f09cf2f9b7107824641ff4d88c34682a2feac3280025a5128e1e3588e0f0b95f74d7",
    "2b3e7fdae664456d73d6ef718268a7abf17771e29a5eff3d041e09d935671c6b4e386e039907403a0603566ef36078dc9caedf3b9fcfc309d51e33997817b7c4"
    "33eb6f2cc033edb7d3f78c307a87e7bc9f175cfce33f8fb08e7357c703bbf37b653733ca6c9d9f977646915821124a9793e1502638e3c15bc4fd76fd3841d44f",
    "42f6e5f5eba7efbee0b8cbf2122b7b1ba7dbae3d0f3c84cac4e575ba653adb9de62b5e57e0c4163bca8bea653b5e3b6c4762413b4cbbb3e784abfd622788f6b8"
    "18176ff03aaeffc783ca58e284f5de412dcc31ad58be512e15c241d2f55f23eebfc7fd564ba1c0e8f88bc69366979ead8c631d7f7e6e26acfb788387757c77ea",
    "7f8bb81fcff3e77f5f7b719a776d9ebf4887d7beb8408f56370edc51dddf8c1f5efb40e93ef25af7bf78f3d113acf3f89dffe55e483ae5945852889736c41253"
    "8fee1e2a29ccff98ffadc9baeeeb2dff7322e6ff45fccf899ef3ffdf31fffb9fff3bf4d146315adbef6d304935bd4e17636cacbc1d1cfec7ebbef3733359e2ef",
    "ed896bbc7e53fdde29de4df7f3bc76889740e259ed3ed2fbb04ebf443cacd3bb53bf0ff9fc9c9581d217acdf03a5a72fe53ddc8b4f12b33cf1a967fcdeeef3fc"
    "34c7fb35e7cddb158996db7d919a7ac9eb79fbe4cf58b7f73fcfabf18870b055dbee36a2e07ca016846c21ac0688e7bf40dc8fdfabbd1e7757fbef7f8da8cfae",
    "bf7e8cc023213bb4ff8596247e9ce2445a1e5766235eb62f36550e886ead1b7f6341bb4c7bdbc03deed2624b1b08dcdabff96a01be69773a5f403ad258d9f570"
    "7cf8cbe732d675fc3e3e94cb69f5ac741ada601afbbbfb4c95de2c16946c70c6870bc4fdb85f5b93350e375c1b2f7e88c023213b3c5e0c00d74aca323dcef2b4",
    "aab222277666d7ad6a7fbfd3e7c9c30578a6dd711ccd71dc34843c8c9fc9ff183c2ef87d5c38dfc945d32fa5ba50668aad64bd9d2b8c846280cee371da9fab88"
    "fa49c8eefcb94157888edb3ca0d5e3cb27086fdff36ae073791ce205ff3d6f7c2ecf32f1f0b93ceed4ef94f7cb88fa49c8ee9cf745a0eed3fb4539af75ed8e29",
    "1b797c6e43cdb5758045e72c738a488b847fd701d2483cabddd1fe9da98fbcd779f07aef12f1bc3ab7a197ec1785d8b81e0b1dc8917e3accbe1808fb4470781d"
    "f75f6bb2c6db8f5c3ba7019fab8cc2b3daf1b9ca37c5d3d37dc1c3e72abb533f9ecfcfcfcd849acf4f10f5d9f5db77107824649fabe3acb57900740ff855cf29",
    "22f1ac76a7e3c073dd63d4cc63da20e021ffff01effff13fff33dd78a92ef26aab02844c5fcc45994c6a2740fbf6efa02e7bf7f6ff4cf65dd3efbf89c023213b"
    "c4fbac2c035beb16cb7a3feb8ecdfb15ad796c8bd2d9dee07c98fa673e5bc1bcffcbdd23ace3fb9df7476279785e9084d4766f2bab6ca6777a03100a908eef94",
    "f74b509980ae33edcbfaff8b2788f62d6b1f0f0acfaebfbe86c0230d4b13e8ff28d3affa7d128967b5df56ff9beee2d77cb48af377fef9f2199ec7fb9dcfa5ea"
    "e874a3a896e21b45ba5a39adcadbe3a618a0f31770ffb5a665e9f71f23f048c83e5fb731597e75fb309d8efb850578a6dd2dddc68c19efe22511ffdde798effd",
    "cef79bf29e42979b85a31a73546752a978acdd6131dfdf3bbeff2da23ebb7efa09028f84ecf3ded7b2be8890174b3cdd648deb83f2ded6270bf04dbb2bef77cc"
    "75a8e7e7f1301f9c627dc7efe303a0f74e199ade4eb7a29ba74a3dc2161ad23840face05e27edcafadc91a873f754def59fc7fb6a6671328ac5ff59e1c12cf6a",
    "77766e83e9252f75bfc4e39fe17df8bee7f7612daf64f9b3c36ca42d57f8c16971473c2fa731bfdf6f7e5f0b9c0e745bfec73ad0fcf6631dc81b3cac03b953bf"
    "d37e5c82ca04749d69f7f73a6ecab3755c657a883281d771dfa50b2ae621ca84a77c8ed7719788e7159fd3742ed5189ee5b8c342bacfa752e2d646693f40ba0d",
    "eebfd67437d7714d96c7ebb876e7ef66cc78a8d327f0fcddff7c1f5acfc537d3c35a24941a0ef990c4c7b63ae7019abf63beb726bc8e3bbf7d781d574f781dd7"
    "1f78781dd79dfa2f10f7e37e6d4d7753e777ef39e1b67a107e4e98df7efc9ce00d1e7e4e7056ffff01c4fbcb2e",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43096U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF6_info.c) */
