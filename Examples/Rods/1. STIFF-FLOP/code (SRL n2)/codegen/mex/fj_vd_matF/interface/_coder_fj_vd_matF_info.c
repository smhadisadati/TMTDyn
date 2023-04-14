/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_vd_matF_info.c
 *
 * Code generation for function '_coder_fj_vd_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vd_matF.h"
#include "_coder_fj_vd_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_vd_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_vd_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.32947916666));
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
    "789ced5d4b6fdbd81566d26490a0989640dbc91445a7e36911b4c8c09465d9b28b16b09e966ceb65c98f38335528899268f32191942c69532d67318bfe802eb2"
    "9c166d9176d1069841a1eeba2dd0e9a2ab00c5fc84765d4a146df34637624c8a32a97380e0e6e690f7bb3c39fccee5e1e115712b99ba4510c437d43f7ffe2541",
    "7cf21f62246f6b0d418edbdb845150fdad71fb10e9eb7297b86338efd618efd7e37e591414a6a3681d8e1598748b2f3192da11689eb918a622f2ac400b4aa1db"
    "6008899145aecd54469a2acb31059667f6c42b9d04ab76f8f815d54567a81afe3d5267ca67f9164f4875f972badcd50e31b6cf505e60aeff8e49fbec63ec4322",
    "fa27b18fa9bac833549daeb0542ab61d92bb42994a0c7ba196221652856857a0226285b9da0f330a4db557967d5479a8a99e16db95224f2bf165de781d4f31f3"
    "7ccbe475a0ad2ef7897b577a3fdb9a8667d66e773178e458d310cf47de6217de5b48ff124fd354c45689632ef13eb38817c2e219f54f927bc7aa6bb46489e2c4",
    "32cd51a950612f14a6f6fdbe958d12a5882257123b14c37314c79628f5bf9ea34b94d890a99185743770d00ffa9f7eb9feaf90b37ee7b49fcf0faf8319cfacdf"
    "bd83c12311fd51fd9059cfe7f26bfb855ceb38ba7b7228e60f2297f3c84ec199360f02d3776a7cb7debf0dccbcccfadb6da4afcb7de4784d1e6e69ed0717bcde",
    "c78c6fd66e3fc0e093887e18cea465565d244802cd2db372b8c5724a525097098cc496e7c6fb8ead07ccfbcdf0cfa391bda847bac128d460ceaf07fa7ff9efbf"
    "bf843830233ca7e240a6dd8c84aa89f6462117e89663bce08f9f7009efc481e798f3cdda7107333e89e82dc781a52aa7e88b5ec261bfeba7b6ecf2bb07183c12",
    "d123fc2fab26a3a5586d6ebc7f03fd6422efeb869a03dfffe1e12f60ddef76bef7edd756dacacea628d5ea723e4ed7c2f1643b0a7cbf38f73161e07bdcf38659"
    "7bbd8df409e4385dcfca82b650558699bef9e575acfa47128b67d4bfe17aa0ca76984a4354dd8332586a0ef91de2f747df8575bddb797e7bf5ac9b6fd6582e52",
    "889ced37c3b5c2d9410c787e61791e8767d65ef7903e71719ca661e52aab3ed4d4dd9aaf8f62f18c7a2bbcae5948f304e0736fe059e5f3ef60f04844df6e32b1"
    "46bb2c6f1e9faf8a6256ceafac3e3e21bcc3e76ec9bb5ef2f952959564a5ca1aafe329669eb6fadfe0a96df9faf7307824a2578d51548d50ac8a12278a8da2d8",
    "66a42a279e17cbc3f7edd6d7f3a8e0e6a38b8e37b8269e3efec9143c5d7fbdfcded88d5e6339e7d705832fbeba0b799c9b1a0fccaeefe5dd582716edf5b23b1d"
    "7f20e5f74572a1155fcc3bf1e025e67cb376ec63c62711fdeceeeba5d71f50ac335c83919cf5d36ddb9e07ee207de2e2384d335ced0edb39bf5760850ad3490a",
    "cac53c9e599cc7d69479e87a6bcf09cbbc837ef102dee3ba3f1ee4bb0d965f6bee1fadb0a54a207992cba656bc94d77f86397f81ef5b557c9ec9e34f8b27e53a"
    "3d7a330e79fcc9ad2e90f771060ff2f8f68cff12733eacf3275faf393f4ddab6ce9f9687572f9ca73bf38b033734efaffb0fa7fe85d26ce474de7ff0e2c17dc8",
    "f3b89dffa5a6af71caca8110bf9e0d0ad9d2f1eaeea11c06fe07fe378af1bdafb3fccf0ac0ffd3f89f151ce7ffcf81ffddcfff35fa7130b37a946e064b2125b2"
    "4667024c20b7ed1dfe87f7be935b5d0cfef7f2a96dbcfea6f97bab786f5acff3cc22de1616cfa87751be0ff2f433c4833cbd3de3bb90cf7b8c24ca2dde781db8",
    "7cfa4cbec31d7cb4356ab73e768cdfab2d8e1bb650af3969dd2e3768a9da12a8a1959c5eb7f7ff08797bf7f3bcb2eee7f7a347dbf59355b1d756527c3cb5a278"
    "88e79f63ce87ef6aaffadd65fdfd2798f1ccdaebc7183c12d123f52f74a3c175c3ac404bddfc28e2c55b42596145c1aef7c6df9c322f5d5f1de316ebb4505103",
    "815df59b4fa6e0eb7aabeb05ac21c76f761d8c0f7ffa8d04791db7c7875c2ea29c654f7dc1d2497a375d2ad01b99941cf74e7c1860ce87fbda28463f0cda162f"
    "7e88c123113d1a2fda225b094912dd8d73b4a230022bd446c7cdabbedfeaf3e4e1143c5d6fd98f26186ee8420efa4fff7f25880b6e8f0bbd9dc46ae4a071cce7",
    "4a994ae8b89a4875f88c87f6e3b17a3f1730e39388defa738396212a563991568a174f10ce7ee77502fbf258c4f3fe77deb02fcf2cf1605f1e7bc6b7cafb39cc"
    "f824a2b7cefb82a8a4e974464aaab7764d4f1b39bc6fc3916def01a6edb3ccca022d10ee7d0f10c1e219f596ea778636723ecf03ef7b6788e7d4be0dcd502bc3",
    "07bac701dfbee46f455698cd369f26bcc3eb70ff1ac5e86f3fb26d9f06d857198767d4c3beca6f8aa7c9a2e0c1becaf68c0febf9c9ad2eb8f57c1f339e59bb7d"
    "0f834722fa89799ce52a278a9a05dc9acfc960f18c7aab71e09166316a6431350838c8ffbf85fa1ff7f37fa9be9e3d1638a59217f9584b48ac9662e11d0fd5ed",
    "dfc0bceccdabffe9a76dcbdf7f1b8347227a84f71949124dbdb798d5f759376cdd2fabd3632a94c6f663ce47a97f64b339acfbffbafb18f2f86ee7fd8e903bef"
    "a51a7c78bb198dcb1b919d665bf4411effcdef678ffd5e621f339e59bbbd8fc123113dc2ff12a3325e83c9b33ded873165b7d6f1e4a7e0e97aabebfe570ce67c",
    "deff1fbffb0ce280dbe3c0fab68f0b6683b9ec61e2503e3c5aafedee37bd54ff0ff7f3e45617a3ffbd6fdb73c0bb183c12d1237140a0a51a2b94eb676ee57f9b"
    "eb38cd3c075cd8ccd93acefeb77ebaff4fe0ff19e139c5ffddce7972938e576b6bbe722626e64fe3ade0b987f667f6cafd8cf307b3fef735cc75e8dff9be6bf8",
    "d70fb7b4f68371fbd0b13a1f3df30f753e93eb04465ffb8e73fd4371909ffe76f010f2fd6ee7fb8d6630536872d1b5b370bd90dbce2bcd68b4eca1efb9e0fe35"
    "0a6e7ddfc78c07753ee6f0a0ce6756789a2c0a1ed4f9d8333ef0be516655df7953ea7a50319bdf797e4d3c7d7ca8ebb11b4f9345c183ba1e7bc607be370a8eef",
    "7f8519cfac9d7e82c12311fda4fd7c8c1b5524852c479799f1f1fafc1a16e737ef7d7d3e9a82afeb6dd9ff63a2411ddfafb9f4f55378efebf6f820d27ba7259a"
    "de8e5456374ee5633f933a69743df4de7780391fee6ba318fdf043dbf2fcd37f877db877a5ccb835cf9fc0e219f5d6f6f5d4ade4e4fecd5bf77e0efb34b89edf",
    "cf8f92729c3b3b8cfbab529e6b9f6676845e2e02fcbed8fcbeecb93cd075f91ff24093e70f792067f0200f64cff850df39b9d505f73bbc56f7ed5cc2e091881e"
    "cd0bc93223298734c75686a60849b5f1716e7d0f3c837dfe26af235e319ce3799fdb9173782e707b3cf0fbcf7a9bd1783859dbebe44f7a895262735f817acf05",
    "bc9f55e96f41bec7241ee47becc2d36451f020df63cff8c0eb935b5d8cbc1e823acff1bf439de7e45617a8f374060fea3ced197f8039dfac1d8b98f149443f8b"
    "38b0c4ca437d4da23967fd70f0d8b1efb786975825e0fbadd7eff3aada08f669f6149e53fcbed64971f1b376e534b97edcd9a948fe80905f87efb716e0fe1d0a",
    "ecd30ceb7ae3bc615d3f5f3c58d7db33fe0073be6bd6f525b125546487d7f539dbe2c1f7317824a27f251e8cb7ab8e70aa6588f9eddff9dc225e16e913c871ba"
    "de7a3cb86a3047f3fc9fbe731ff2fc6e8f0371612f1b0e1da57b2cdfc99c362a7c4649773d94e71f60ce87386014631c38b02dbf336d1dae1a80a73bf3e379ab",
    "cf87512c9e516fe9f9706423c7eb735e3c007e773dbf4b4d5fe3949503217e3d1b14b2a5e3d5dd43390cfcbed0fc4e1c3acaefac00fc3e8ddf59c1717eff1cf8"
    "ddfdfc5ea31f0733ab47e966b01452226b7426c00472508f7f31de42d5e91009e0759378c0eb76e169b22878c0ebf68c0fbc3eb9d505f77b5a383cc8c76802f9",
    "18bbf03459143cc8c7d833fedf31e79bb5238d199f44f433f87e76a94d4ba3adf28b0d49ac20d7f514336f7b79be6cdbfbd7f7307824a2578d53548d52ac8a12"
    "278a8da2d866a42a279e17cb43abcc6f5fcdc135f1f4f14fa6e0e9fa6bc601cdad5e6339e7eb72065f7c7517e283dbe383bc1bebc4a2bd5e76a7e30fa4fcbe48",
    "2eb4e2f3c0f7b4ff073bb252e9", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58272U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
