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
    "789ced5dcd6f234915ef5966563342cbf601582d206016345a1894b663c7c92006fcfd91c4b11d3b7192d925e9b6db7627fd6177b79d381772e4c061b970e230"
    "471609b470d9112064fe8845082e2310e2c21584c405dbdd9da41ad7d849b7dbeef67bd2a8527eedfa95dfbcfa55d5ab8f26ee64b2770882f84cffdf9b3f2088",
    "fffc9718ca1b5a42907afa1a818a597f474fbf69ca1b728fb88b7cef8e8ef7533d5f9144953d53b50ccf89ec565b6058b99f116981bd2ca62a099c488b6aa9db"
    "6409995524bec356879a1ac7b3254e6037a56b9934d7cf08c96baacbcc4035f83bd6602b27c5b640c80de5aabafcf50ca1db67201f617effdd09ed93c7d88734",
    "e99f25dea71a92c0520dbaca51d9442aa274c50a951ee4226d552a654bf1ae48c5a42a7b3d1f65559aeaf8977c5465a0519a72556826434b8251ff3f61eaf7fa"
    "84f57f1353ff077a7a76fdc35e213c4c2fd6b59448eb6952ff3ca1a759fd733d4f3cd5d3efe8fa949effae9e37ca09eb793d256261e3771e617ec7a4ff4ff74c",
    "79e2f2394dd3944e87de6917deeba6fc159ea6a94a6d8667aff07e66112f82c543f5cf329b7b7d576c2b32c54b159aa7b291d266244a6d2ffbfc6b0ca54a12cf"
    "4867142bf014cf319440ab3ccd505253a186165a12f472c6d96952ff33a7863c20eeeb7f5dfce893d01f23cee169b2287846fbbeaddf7d1e83479af4e5c62e1b",
    "2a168a2bdba5427b2fbe71b02b15776257f53078128733ae1e0426ef54f96e6dbf4d4cbd26f5b7d74c79438cfe83443e7d14d6d2772e79fd0253fea476fb0a06"
    "9f34e907dda7bcc4f50725b248f34b9c126d73bc9a11fbc31256e62a33e3fd1716f1b6b178a8fe067e33f8f778682feab16130ca6c30c3911cec073efed79f3f",
    "817e604a784ef503b94e2b16a9a53b6ba542b05b4908e272f2804f7ba71fb03a9f58c7944f9af496fb8187355e3506bd84c37ed79f1fd8e5776f61f04893dec4"
    "ff4adf64b49ca8cf8cf7e7d04f46f2be61a819f0fd2f1f7d1fc6fd6ee77bdf76dddf51d79f4872bda11493743d9acc74e2c0f78bd38e0984ef71f38d49edf586",
    "294f989e33f49c226a03557510599c5d5cc7aa7f64b078a8fe86e3811a77c6569b52df3d28c4523388ef10bf28bf0de37ab7f37c2a70d22db6ea1c1f2bc54eb6"
    "5bd17ae96427013cbfb03c8fc39bd45ef74d79e2f2394dc32935ae3fa969b8355e1fc7e2a17a2bbcae5948f304e0736fe059e5f3cf61f04893bed36213cd4e45",
    "79b2771a90a4bc52f407f60f08eff0b95be2ae577cfeb0c6c98a5ae3d0df7184a9a7adfed73bb22d5eff650c1e69d2f78d71d837c2614d9279496a1e4a1d56ae"
    "f1d2e96165b0be6f7d3c6f165c7d0c31f07ab7c433ca3f188367e86f17dfd3dde81596737e5cd0fbdddfef411c675efb8349c7f7ca46e22c113f3fcfaf9f2d07",
    "b3cbbe5821e2f725bcd31fbcc47c7f523b5e60ca274dfae9b5eb87af7ee0b0c1f24d5676d64f53b6cd07ee9af2c4e5739a6630da1da4335e57e0c42a7b9611d5"
    "cb7a3cb7588ff0987a187a6bf384abfd644798fad8e8172f601dd7fdfd41b1dbe48495d676d9cf31d560e6a090cffabd14d77f8ef9fe02b7dbbef83c13c71fd7",
    "9f541af470651ce2f8a3534320eee30c1ec4f1ed29ff25e6fb30ce1ffd7b27f3d38c6de3fc7171f8fe0f17e8b3d9f503731af737fc87efff416936723aeedf7b"
    "f1d60388f3b89dffe596af79cc29c18810caaf8a79662fb0b1ab4481ff81ff5141d77d9de57f4e04fe1fc7ff9ce838ffff16f8dffdfc5fa7f7577381f2566b95",
    "89a8b1153a176483859477f81fd67d47a78620fef7f2c8365ebf69fcde2ade4df7f33cb78817c6e2a17a17c5fb204e3f453c88d3db53be0bf9fc9c9525a52da0"
    "bf03174f9fca39dcde7be1611a7edf317eafb5797e90c27ecd51e376a549cbb5b6480dace4f4b8fde25710b7773fcfaba165613b5e4e350e02d27947cd0ac9ac",
    "5ff510cf7f84f93e9cabbdee7757fbef7f88296f527bbd8bc1234d7ad3fe17bad9e4bb514ea4e56e71d8e325db6245e524d1ae7563dc7d45a4495fd3710f1bb4"
    "58ed770476eddf7c3606dfd05b1d2f600da9afec3ad83ffcfa4319e23a6eef1f0a85987a923ff6ad32075b1b5b4c895ecb6595a477fa871ee6fbd0ae5141fd70",
    "d5b6fee26b183cd2a437f7171d89ab466499ee26795a55599113ebc3e766b5bfdfea7c72770c9ea1b7ec47230c37702107fde7e2df0cf40b6eef17ced7d381d8"
    "4e734f2830b96a64af96ce9e09390fddc763b53d9730e59326bdf5798316213aacf112ad1e5ece209c3de77500f7f258c4f3fe396fb897679a78702f8f3de55b",
    "e5fd02a67cd2a4b7cefba2a46ed15b3939d36fda75236ce4f0bd0d65dbd601c6ddb3cc29222d12ee5d078861f150bda5fd3b031b391fe781f5de29e239756f43"
    "2bd2ce09c1ee5ed0b72d2fb7637ef64947d822bcc3ebd07e5141fdedebb6ddd300f72ae3f0503ddcab7c533c4d16050fee55b6a77c18cf8f4e0dc18de72f30e5",
    "4d6ab72f62f048937e641c67a9c64b926601b7c67372583c546fb51f78ac598c1a5aacdf0938c8ff3f87fd3feee77fa611caef89bc5a2d4a42a22da6034c22ba"
    "eea17dfb7318979dbffd3f175bb6c5ef3f8bc1234d7a13efb3b22c4db46e31adf3597336ee57fad563ab94c6f63ae79ba97f68b3198cfb7fbfb10f717cb7f3fe",
    "9958383dcf368568aa154f2a6bb1f55647f279288e6f95f7f3a63c617aced04febfd8c4798fad9eb77dfb32d7eff290c1ea96b2a92f6224db7c6ef23583c547f"
    "dbf8df60177fdf46b3b87fe70f3b8f601cef763e6f96ce8e57736a3eb49aa34bc5e3929cea56440fddbf00ed179569c5efdfc6e09126fde8b88dc1f2b3db8769",
    "b5dfcf8ec133f476c56d0c9f71ce5fc2a19f7c087cef76be5f933715ba50c9ee9799fd3d261a0d056b7516f87ee1f8fe034c7993dae91b183cd2a41f755e0b3d"
    "889011f33c5d61f5e7bd726eebbd31f886de96f31d230deaf87d3ccca78f21bee3f6fe41a2378f199a4ec5aa81b563656f99cd1e34bb1e8aeff430df87768d0a",
    "ea87dfb22dde33fe3d5b83bb0914d6adf19e34160fd55bbbb7c1b0929371bff0fda7b00fdff5fc7e5ace2849fe6437b95c938b7ce738b72e9e1762c0ef8bcdef"
    "4b9e8b03dd96ff210e34bafe100772060fe240f6946fb51de74d79c2f49ca177f53aee45d4b1755c6570893201ebb8af8a0b2ac625ca84a37c0eebb853c4738a",
    "cf693a1d3d383d4973bbd9589b8f46c5f86a7ecb43711b68bfa8cce73aaec1f2b08e3be9f8ddf01907e3f46118bfbb9fef7d2be9d05aecb4bcec8b9e9ef2be26"
    "1f8cd7cf3d347e07be4705d67147d70fd6713581755c77e0c13aae3de5f730df87768dca7cc6f9ed9b27dc361e04f384d1f58779823378304fb0a77cb7c7f971",
    "e3e3a9bc8785888787c945ccb6b8ffb8f3b24a4b5607a95be3fe512c1eaab7348fecdbc8f9f3b810f79f269e53fc1e4c256a0d5f28739c4b04326abe208a9d58"
    "dc43f7f040fb4505f5b747b68de7bf84c1234dfaffbb7f2d2e09342726ccf730cc3aee63755ce0d43d3c88019dbd87e737ff84fbf45dcfff7c56a80a27329b6d",
    "c6caea9ad4aed6f6db1c8cef17a81d0f2404fbf327c483fdf976e169b22878b03fdf9ef281cf47d71ff5bba7977c0eefc9d204de93353a3504de93e50c1ebc27"
    "cb9ef221ae830aea6fef86edf237b857d38c87eae15ecd9be269b2287870afa63de503dfa332ad7d395fc0e091263d665f8ebe5aebdefdfb5b63f00cbd6dfb72",
    "749f71705fcec77ffb07acdbce2bdf4ffadeacb5f666d1b71bc845e44c2021eead6f87c4ed10017cbf687cff01a63cd8bfaf49cf22fee2edf385fdfbd3c483fd"
    "fbf694dfc37c1fda352a5e9f2718f84eefdf877982dd789a2c0a1ecc13ec29df6a3bce9bf284e93943efee7b7ab28eddd34333f0be9571f3c6be8d6670eebbd7",
    "83fdfaf3cbe7938eeb5b0c53ad059b4cae942fca05c99f4af19b410fedd784f68b0aea6f5fb56dfc0eef4bc7e1a17a785ffa4df13459143c785fba3de503efa3"
    "82fa9b6f4eee5d3046f7ee5ddfcd8ec133f476c56d0c9f71709cffe3bf7c1bf8deed7c7fbc922ad4ab85ddcc93e496ffc92e5358a9d7f21edac70f7c8f0a8eef",
    "adeedf7f0783479af4e3d777b5e7e6655dd7eaf87f670cbea19fc2fa8fd3fdc15fe19caefbfb838d5dff89143cafd1d5d3d3f2f67230fb24b9b39ff04e7f00ed"
    "79746a08ea7f2b70be4b1738df85d67b02ff81f35d53c483f35df6940ffdc1e8d410d4ffd29e8b0fdd765d00e243a3eb0ff12167f0203e64adfcff01b6e29b57",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 64528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF6_info.c) */
