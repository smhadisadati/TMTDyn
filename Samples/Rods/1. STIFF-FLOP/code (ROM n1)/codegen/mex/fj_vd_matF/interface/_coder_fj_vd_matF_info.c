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
                (737429.55663194449));
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
  const char * data[17] = {
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4d3f8784d47c36e99a2669b2b4eb80ccb19dc4c9b59dd84e9af4853e22c4037f000f7b9c1048"
    "bc2026c14378e3150978e0692ffc09bc63c7711adfe52e5eedba38b947aa6e6f8f7d7ed7a7e7feeef5f18943cc2553730441bcaefdfcf839416c7c49f4e5aad1",
    "10e4a0bd405805d6cf0ddaeb50df944bc445cb797303bc6f067d461255aea31a1dc08bdc4e4b2871b2d61169811b9a612581176951cd771b1c21738a04da1cdb"
    "d79479c0e57981db96463a095eeb08f111d5b0a3abf4df23558ea9e75a0221579593e182d10e31f08f2e4f11d77fd1a67f7611fe2121fdc3d8a754551238aa4a",
    "b33c958a6d8694aec85009bd176aa9523e958f76452a22b1dc683fcca934d55e5c08508cae29d78a6db628d06a7c41b05ec723c4385fb5791d706bca15e2f248"
    "efe68689778cb067d76f37117824a4d72f5b5ee0b56092451a2c682152a51b5c8e3f32fed1caa4eb9f341e5850e331c5adb8c94dc033f50f93dbfb5ae8b41499",
    "021243032a15ca6f87c2d46e30b0b85ea254490225a9437102e8ffdceefb8bba6d3a8c7ace6183c0f12e6e8e7fffeec95f216fe3d4eb79717e781d843dbb7178"
    "0d814742fad5cd0058cbac653385444129ecad56eeed36d5e8c938321370268d8340f4bdb28fe7f3f8d614d43ae034fe6e20f048480fad03222d577891a9d6fd",
    "caff850978a6de66bc684121732c6544cb2066e0d019fa4c0f190ff9ffcd8f76ffc0fc7f46785ef17fb77398bc4bc7cb959500938e49b95abcb57618c3fcff7f"
    "9bcfa878b01b7faf20aee3caa0bd61f9eb9d0da37d7fd0deda70cac726ee25c438c881a60c2449bf9b740bef55a87f82676858a95502dc09de13877811249e55",
    "ff12fb05c09728edd610d0258a03e59648f57de4fdfee0d7fbb7fec47c7f46785ef1fd7a732d9d6f82e84a3d5ccd6737736a331a65e2d3c3f778fe5ae5acf23c"
    "ef21f048480fedef7925dce2819a14775a0227f3ccb9f1bc67f94187f785b0c3bccf0f1efff4efdf98f7fdcefbe97633122a27daebf9ec7297890962307e0012",
    "98f76783f73f708df7df46e091901ee27d4573152d2f98bb7be7fb7b58ece6777e38259e693f3d01cfd43be5fddb86c78631e321df7fbbf716e67bbff37da9ba"
    "9ad91781cae62421d612134ba558786b13f3fdacf1fdd7087b76fdf421028f84f410dfd38d06e8e6fa14166f898cca4b6252cc009a314b04ccf1351c8eef8d09",
    "e333f5e5c1288a555a64b51b0113bfe710ff9309f8a6dee97a8076a81160dec557aff45a0d3ff7f5fbfa20d1dbb5124d6f46d8a5f59ab21fe452078dee143df7"
    "ed21cec7f3da2ad638bce35a9eff32d42786c7191a5e511ab4ac707ecdf327907856fde9f60fba6ff41d84e9a505c1bb38d8b8fcf16798dffdceef877b49250e",
    "ea8578b02ce740bb96de128fb211ccefb3cdef0b5397073a2dffe33cd0f8f1e33c903778380fe48e7d5cdf39be35c51a7f8121ff7f81b067d76ff3083c12d2c3"
    "792145e164b540039ed55d11922b83e3fcfa1c388fc4b3ea1def239e739ce7799f0b91437c5fe0f7f52018ac1fdd8dc6c3c9ca76277770942825eeeeaab8de73",
    "06e7b326c71b38df63130fe77bdcc2336456f070bec71dfb98d7c7b7a658793d84eb3c077fc7759ee35b53709da73778b8ced31dfb3dc4f976fd5844d82721fd"
    "59ac03f3bca2eb2b320dbc8dc3de03cf3ebfa55f6299c09fdf42d58569bf507d1f79ffbe86a798dffdcfef2b9d1488d7db6c2db9badfd962e5e0b2985bc59fdf",
    "9a81f9ab8b7b75fc785f8fc2b3eaf1befe65f10c99153cbcaf77c77e0f71be6ff6f525a925b28ac7fbfaac6bebc13b083c12d23fb71e24f53b1a4e8e00cd3384"
    "7bfbfe8b50ff643c8686a9d2fd0222b7ea7932509f808e33f5ced7835187799ae7ffeada159ce7f7fb3a1017b733e1d0dece112f74d2b5062ba4d59dee14e5f9",
    "7b88f3f13a6015eb3a70dfb5fccea47db8e60081ee9c1fcf3bbd3f8c22f1ac7a47f7877d1f795e9ff3f43ae677dff3bbdc0c346abcb21c1256336b62a6b4bf74"
    "afa08431bfcf34bf13054ff99d1731bf4fe2775ef49cdf7fc6fcee7f7eafd00fd6d24b7b3bcdb552488dacd0e9656e398bebf187f666aa4e8748605eb7898779",
    "dd2d3c4366050ff3ba3bf631af8f6f4db1d65feee07c8c4d3c9c8f710bcf9059c1c3f91877ecff8638dfae1f69847d12d29fc1e767e7dbb4dc7f557eb1214b2c"
    "745d8f10e37697e719d79ebfbe8bc02321bde69ca2e6946259928124358a529b93cb403a2c32ba57ceefbd9abd53e299f60f26e099fa53ae034658bdc073ded7",
    "e5f47ef9e7125e1ffcbe3e28f7629d58f4e828b3d5092ea782814836b41898a2cfd33e439c6fd78fc708fb24a43fbb793dffe2038a550e3438d9db38dd74edfe"
    "60d27e9d57cafa776bba362f50df1b4a427ab84e4864b94e525487e378ec701c1b13c661ea5f32aeca7c87631b92366e4af79c97f53904aecf3f433cafd6835c",
    "b7c10b2bcdddbd45bec42e270fb299d4627b8adeabf91871fe0ccf5b62f4bd3a0d843dbbfeb90af509e83853cf2ba25150aeeadfb0ecdfbacb2412cfaa77120f"
    "239e32b7f95ef2d0f7f83d6afee7f5cda57a37d7acf020928fd4779be14abe7e3f3645bcfe0c713edee78fbf5e7b719ac4cf016ce2e1e7006ee119322b78f839",
    "803bf69f21cec7fc3ffe7aed3d1ff096ff717d0faeef316556f0707d8f33fbff0173a73c51",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
