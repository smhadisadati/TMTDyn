/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF4_info.c
 *
 * Code generation for function '_coder_sprdmpF4_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF4.h"
#include "_coder_sprdmpF4_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF4"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF4.m"));
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
  const char * data[23] = {
    "789ced5d3b6ce3c819e65e760fbb082ec72297c3214092dd0b16176c604ab2fc3a20881ed6cbb62cc9925fdabbd8a44449b4f91249bddc44658a1449932ac596"
    "b900092e69b2408283d3a5487b2972cd2240bab4491d49e4d84b42b3924d8a12e9ff078cf1f827e71bfdfef9cdf01b7244dccb64ef1104f18dc1cfbb3f25888f",
    "fe4e8cec1dbd2048a37c8b309bd57fcf289f58eac81e10f74de7dd33f07e6dd42b92a8b15d4daff09cc8eeb604865506159116d8ab66aa92c089b4a8957a324b"
    "28ac2af16db63af2d4389e2d7102bb23bd564973838a907ccd755519ba86bfc71b6ce5bcd81208a5a15e77977fbd4218f119dae798cf7f7fcaf8e431f1212dfe",
    "e7894fa98624b05483ae725436918aaa3db142a587b5684b934ad9d2664fa4e252957dbd1e63359a6a0797025465e85165a52ac8c9f09280faff374cffde9eb2"
    "ffef58eac81e1965c3f4d76c442f534619d3cb7ec4a81b653f6ed4578d12d5578c72cd28378cf263a3fc71047dae534cbfa7fdbf3cb0d489abe3748f2c7546d9",
    "e814dedb96fa359eeea94a2d8667aff17e63132f8ac533fb9f67768e06a9d752158a972a344f65a3a59d688cda0b0582eb0ca54912cf485d8a15788ae7184aa0"
    "359e66284956a951849604a39d49719a36dfac25b247c443e3b7fecfbf5cfd47d43d3cddee0a5e17d3deb479f72d0c1e69f11f360ed8d562a1b8b2572ab48e36",
    "b7cb0752713f7edd0fc48b389c49fd203075b7daf7eaf52b63fa356dbebd65a92343e30569faebd3885e3eb9e2f53ea6fd69e3f65d0c3e69f10f874b65891b4c"
    "421491e6973835d6e2782d230ea621acc255e6c6fb2f6de2ed61f1ccfe1be4cdf0e7d9285ed4331430ca1a3094482e8e037ffaef3fbf84716046786e8d03b976",
    "331eada5dbeba542b8574908622859e6d3fe1907ecde3f6c61da272d7edbe3c0e31aafa1492fe172def5b311a7f2ee7d0c1e69f15bf85f1d848c5612f5b9f1fe"
    "02e6c958de47819a03dffffee94f60deef75be0fecd5836d6d6b4352ea0db598a4ebb164a6bd097c7f77ae63c2c4f7b8fb8d69e385d3a7488b9f53457da2aa0d",
    "95c4f9e93a76f32383c533fb6f381fa8715db62a4b83f4a04c919a83be43fceef00398d77b9de753cbe7bd62b3cef1f152fc7caf19ab97cef713c0f37796e771"
    "78d3c6eba1a54e5c1da77b38b5c60d6e6a1a5ed5eb37b17866bf1d5ed723a46702f0b93ff0ecf2f97b183cd2e26f37d984dcaea81b479d6549caabc5e0f27199",
    "f00f9f7b4577bde6f3c7354e51b51a67fe1ca7987e3a9a7f97a78ee9f5dfc1e09116ff20182783209cd424859724f9446ab34a8d973a2795e17abefdf9bcd570"
    "fd4186f02e6f8987da2f4fc043fedbe97b461abd2172eecf0b2efff2ef07a0e32cea7830edfc5edd4e74139b1717f9ad6e289c0d05e285683090f0cf78f00a73",
    "feb471ec63da272dfed95dd78fdf7cc04983e5655671374f538edd0fdcb7d489abe374cf70b63b2ce7bcaec08955b69b11b5ab7ebcb0d98fc8847e20bfbdfb84"
    "ebe7c74e31fd71302f5ec23aaef7c783624fe68495e6de619063aae14cb990cf06fda4ebbfc09c7f87afdb81057ca3e34f1a4f2a0d7ab4320e3afef81219e83e",
    "eee0818eef4cfbaf30e7c33c7ffce79d2e4f338ecdf327e9f0830f2ed0ddf98d030baafba3fce107bf507a8cdcd6fd2f5fbeff08741eaff3bfd20cc8679c1a8e"
    "0aabf93531cf1c2d6f1fa831e07fe07fb399d77ddde57f4e04fe9fc4ff9ce83affff19f8dffbfc5fa78fd772cb87bbcd3526aac557e85c980d1752fee17f58f7",
    "1d5f2233e5dfab53c778fda6fabd5dbc9b3ecff3c2265e048b67f67b48ef039d7e8678a0d33bd3be07f9fc825524b525983f074e4f9fc97bb8979f444665e453"
    "d7f8bdd6e2f96109cf6b8e9bb7ab32add45a22358c92dbf3f6fe1f40b7f73ecf6bab21616ff330d5282f4b176d2d2b24b341cd473cff39e67c78aff6f5bcbb7e",
    "fefe6798f6a68dd747183cd2e2b73cff42cb32df8b7122adf48aa3112fd9122b1a27894ead1bbf3ba15fc85f33704f1ab4581d0c044e3dbff97c023ef2db9d2f"
    "600369acecba383efcf13305741daf8f0f85425c3bcf9f05d698f2eef62e53a2d7735935e99ff1e112733e5cd76633e7e19a63e3c587183cd2e2b78e176d89ab",
    "461585ee25795ad3589113eba3e3e6f57cbfddfbc9830978c86f3b8fc6046e98422ee64fff7f0c8c0b5e1f172eb6d2cbf17df9482830b96af4a896ce76859c8f"
    "f6e3b17b3d9730ed9316bffdfb065d213aa9f112ad9d5cdd41b8fb9e5719f6e5b189e7fff7bc615f9e59e2c1be3cceb46f97f70b98f6498bdf3eef8b92b64bef",
    "e694cce0d2ae23d9c8e57d1b0e1d5b0798b4cf32a78ab44878771d208ec533fb6d3dbf338c91fb3a0facf7ce10cfad7d1b9ad1564e08f78ec2813d25d48a07d9"
    "8db6b04bf887d7e1fa359b39dfbeefd83e0db0af320ecfec877d956f8aa7db5dc1837d959d691fe6f3e34b64b8f97c1fd3deb471fb36068fb4f8c7ea384b355e",
    "92f4087855cfc961f1cc7ebbe3c0333d62d428628341c045feff2d3cffe37dfe671aabf92391d7aa454948b4c4f43293886df9e8b9fd05d46517eff99ffeae63"
    "fafd373178a4c56fe17d5651a4a9d62d66f57ed682cdfbd541f7d82aa5b3bdc1f956ea1fc56c0ef3fe2fb68f41c7f73aef77c542e7222b0bb1547333a9aec7b7",
    "9a6d29e0231ddf2eefe72d75c2721cf2cfeafb184f31fd7336efd61dd3efbf86c1230d4f45d2bf38d3abfa7d148b67f6df56ff1b3ec53f88d13cf6dff9ebfe53"
    "98c77b9dcfe552f76c2da7e557d77274a978565252bd8ae8a3fd17e0fa35dbacf4fb0f3078a4c53f5eb7412c3fbfe730ed8efbd90978c8ef946e8372c6bd7c89",
    "acfeea33e07baff3fdbab2a3d2854af6f890393e6262b1d570adce02dfdf39beff05a6bd69e3f4030c1e69f18f7b5fcbfc224246ccf37485358ef7cb7b5b9f4c"
    "c0477e47deef181b50d7f7e361be7e06fa8ed7c70789de3963683a15af2eaf9fa94721365b967b3ed2772e31e7c3756d36731efed031bd67f2f76c0df7265059",
    "afea3d692c9ed96f6fdf0614253775bfc8c31fc173f89ee7f7ce61464df2e707c9504d29f2edb3dc9678518803bfdf6d7e5ff29d0e745bfe071d687cff410772"
    "070f742067dab77b1de72d75c2721cf27b7a1db71f736d1d571d6ea24cc03aee9b7441156da24cb8cae7b08e3b433cb7f89ca6d3b172e73ccd1d64e32d3e1613",
    "37d7f2bb3ed26de0fa35db62aee322968775dc69e7ef28675cd4e923307ff73edf0756d2abebf1ce612810eb74f880cc8737eb173e9abf03df9b0dd671c7f70f"
    "d6717583755c6fe0c13aae33ed5f62ce87ebda6c8ba9f33b779f705b3d08ee13c6f71fee13dcc183fb0467da079d7f7cffcd7997724de7a719785f6bd27de320",
    "4673b86fbcbc049ddffb7cde64986a2d2c33b952bea814a4602ac5ef847dc4e770fd9acd9c6fdf736cfe0efbade1f0cc7ed86feda678badd153cd86fcd99f681"
    "f7cd66ceb7c082e83668760febbbd3ea3628675c9ce7fff2ab8f81efbdcef7672ba942bd5a38c86c2477831b074c61a55ecbfbe8397de07bb3e1f8deeef7643d",
    "c1e09116ffe4f55dfdb84559d7b53bffdf9f808ffc3358ff717b3cf8d77fe07bb33c3f1e6c1f04cfa5f0458dae763a877ba1707623b97f9cf0cf7800d7f3f812"
    "9939ff561c1b1f3ec4e091163f7c8fa26ef03d8a37c61bd95dc183ef5174a67d180fc697c8ccf997f69d3e74db7501d087c6f71ff42177f0401fb2d7feff0124",
    "a7d8b6", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 52288U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF4_info.c) */
