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
    "789ced5dcd6feb5815f7bc2f5e85802701c30c1fc374787a33e8bd693edbb423909ae6a34dda7ca79f034a9dc449dcfa23b19d34edaa121262c162962cf80358"
    "cc62c48a652436880d126218849098051223fe00340b1638716e1bfbe5be789e6f9cd83957aadcdb639fdff5e9b9e79c7bee87a95712a957288afaaafa7347fd",
    "e93decd728ea2b94561e0daf77287d31d25f195e9f19eaa8dca7eee99e43f45f0faf15515098aea255385660d26dbecc486a45a079e6864d55e459811694e265"
    "93a1244616b90e531d506a2cc714599ed913472a3bac5ae1e323a49b4a9fd4ff3dd2602ae785364f490df9b6b9dc68851a91cfaf30ef7fcfa47c4218f93c1af2",
    "47f4f7633f8dbce7d9971949f6c8b22fe45ff77ba28c7cae884d8f6fe5cd4231118fbf1bdfcb643d15b1ca78a433856dc657f89b767631ed7860b29d7731ed5c"
    "1a5e5fd3fd757d53bb6e0cafef6da2769c6270cccaeb3ea61d8f544a9f7f53bc18680929bc0786fa2dde8301ffaad82e73cc2dde6f2ce26d63f134fe88fe7e62",
    "ef68a0125949ac4b34ff665f77654f2a5cdc0b6f79f27eaf2f54f628a2c895c5ae87e1390fc7963d3cad7074d9233665cf404e23fa718a699759fd305e5159a2"
    "1e0e7fbbfefcf76b7f0ddb87a79545c1c3f56fb37af72a060fe91da21f360e98b542aeb09a2fe6da47d1dd9303b1b01fb96d477602cea4765098ba5dfc9dda7f",
    "9b987699d5b73b863a2ac8be3fd2fdf5ad4dedfae4c6ae5f63f89b95dbf731f8486e88def76ed20aab06079240732bacbcd566392521a8e10123b19599d9fddf"
    "59c43bc2e269fc11fd0beb4dffe7e9406a9ea7486c1ea3d856781bfdc00ffef5f78fc10f4c09cf2e3f90e9b422e1da4e67bd980b5e5662bce08f9f703beef103",
    "1f619e372bc7aca14e8ddc37da7e427e60b9c629835f6dd5bbebd42629bdfb16060fc90bd10df65faed01c2dc5ea33b3fb73ab2763ed3e1297adf67ee997ff00"
    "7bef747bef4d5f84f822cb9fecb2f96a6c375a29d46a975b60ef17a71f533a7b8f1b6f98959731ef478ddc776784ceca8216a22afd0cdfecf23a56f52383c5d3",
    "f823fa4bc50335b6cb549ba2aa1e1e9dbc6ccdef50afc75f073bef743bbf1d38bf2cb4ea2c172946cef3adad7af17c3f16053bbfa8761e8767565e0f0d75eae6"
    "be8703feac5c63d5e14cc3a9763d89c5d3f823ba75bbaec94935e9830276dd1d7856edfa37317848ff10bdd36262cd4e45de38ba088862562ef802c727947bec",
    "bab3f2afb7767db9c64ab252636dd5bfde29b1bcfd1b183c24374457c550525fbf5413254e149b25b1c348354ebc2855faf3edd6e37a63c1b507959bf50d2f89"
    "87f89f1aea463c44b792e71baad10be4676b3ee7c34feec33ceebcfa03b371bebc1bebc6a25757d964d71f4cf9bd915cd8e78db9c71f7c8679deac1c7f8ee18f",
    "e488e8d3eed7cb2fbea1d460b8667fc18bbdfaba4d6c7c70cf50a76eeebb77333ee8d7673ccfc00a55a69b101462eb04e213da81e824c60dfd31838dfaf118e6"
    "779def1f0a974d965f6de50f7d6cb91a4c9ce4b2295fc7457920e8bffaa2d737af6bf2fc93fc4ba541f7978b429e1f734505f241f6e0419e9f0c7f88fff5ef45",
    "565f13c4e2ff49f97af5d579baeb5c7f30d5f901a4479cfa8b479394fdf303d78f1f2c413ec8e9fe406a799b67ac1c0cf36bd990902d1f05760f6417adef017f"
    "a07f2fb2f3c5f6fa0356007f60ce1fb0c20cfcc1dbe00f9cef0feaf4712813384cb742e5b01259a533412698db768f3f80f9e2f1575474faf7e92931fbfe45f3",
    "fd56f1ecdebfebe2bc20e4f5a78807797d32fcadc66759439d1ab9cfd2face79dab745ddaeeffc05869f5979bd83c143f24274c37c2add6c72975bac404b9785"
    "816f8bb7858ac28a02a97987af4d6817a2d786b8a5062d54554780f0ff60119f9e808fe864e203ac3851f86f67fcfff1ffe09c07c7fb892b8616c3423a70a2d4",
    "ebfe6d6f2a53dd3ff4b9c84ff430cf9b95e309863f9223a293f213da08a054e3445a29a1436e289bf5b07702fb7d2de24d2dbe989bfd23b0df779a78b0df970c"
    "7fabf99f430c7f2447442765ff055149d3e98c9450bb765d35fef6e6f70f89e57f269ddfc6ca022d50cedde79bc0e269fc119d407ebf2fa959c4f790079a229e",
    "5dfbc15ae176860f5e1e05bd79c9df8ef8988d0e9fa6dc63dfa11f8f6fbf5eef1e13db0706e7b7e1f0a6311f04e7b7b9150fce6f23c31fe2fbf1575470f1fd35"
    "869f59b97d078387e486e863f33a2b354e14b5c49653fdc03e164fe38fe864fcc0534d6e9e81dc0631848d7ee055d807e07c3f506eac658f044ea916443ed616",
    "7602e5d856d245eb7ce6365f3b4ff3c1d7696279fd6f60f090bc10dd60ff19491275eb2c4f2db6e38baeeb9ccbf85f561bc9543d9ad51fda7ea30b1848ced6f8"
    "5fec3d81f95da7db7da1789ca3fdc73b27814ea71d3beaf8027c9275d139fe4ef92ecb29a61d64f5eb47b6addf945bd2e0a33d4e5dbfb983c5d3f823bab5bc5f",
    "ad2d78fa92b2f55cbf77a34f205e77badd0e6ec76a0def5ae22c130b24946c4e103a91a88bf236d07ff545af6fe4beb7f25d0c1e9213a23f97af8f8a3ccd0a31"
    "63bcdeb4d81eabeb359d95b7d189d1e6bc0db5f4a72d88dfe7d50f989dbfe552a972cc1788ac5eb0954a4c6e761ac7f55dca3d7e00faf3f82b2a7afd5b2316df",
    "4f3eaf596ed292cc38757d4e1a8ba7f147742bf1415f42fd0801c9cade7d5ad75fceff17e2fc79b5ef66e3fc552ebf7321a6d6b703fb3bf550257295cc270a2e"
    "5a7f0971bebee8f5ed1dc8c75bc4837cfcb4f0b4b22878908f27c31fecbdbee8f56d85585ee7db183c2427441fbffe0665efaddb7d63c1b507155276bf38010f",
    "d1c9aebfd17466f43d4e31ed24b90ef3cfff86387f5eedbed93cce7a7bafe03d0864c2522210138e92f93521bf4681dd5f34bbff01869f5939fd108387e484e8"
    "e3ce61d01f199010b21c5d6186f7cf4b7edfea790ce509f8884ef03c86b1629dc1f7bb0217ab303e98573f61767cb097dcad1cb7b21be1e3545092fd4dd6df09",
    "255d741e03f4eff1efb5a8e387979d1f80f1c3f82b2a307eb0070fc60f64f8c33ace51fdfa31b179de2f61f01ea9943e7f89911b749399991dffc822de2e164f"
    "e38fe8d6f76f0f253574fc36daefffacfc13ecf7bcda6fb3717dc27bb6d1be0c07046fc09bbe507cb10ad3e55cf41d46e8c7e3dbafd7bb67c4e67b5fc3e02179",
    "21ba217e1768a9ce0a95c6f9acf2febd97c443fc7f32010fd189cff7de48cef6f8fdeeb3fc5fc0fe4f09cf2efb7fd9bd486cd0f15a7dd55bc9c4c4c259bc1dba"
    "7091fdef619e776abfc6e985593dbc8b799fa5e1f535dd5fdfdad4ae4f86d767c4e2ff49e7b0a193189c1affdb737e537fdee8f6ec857e81fd5ceec0b3cbfeaf",
    "b74299628b8bae9e6f358ab9ed82d28a462b71f7d87fe8c7e3dbafd7bb3789e5efe11c361c9e85759f700edb4d59143c38878d0c7fb0ffe3db3fad7338e7e5fc"
    "3563319b0772d6be3f387fcdad7870fe1a19fe60ffc7b71f67ff3fc0f08375a0b04eec45ef6542cf601de814f1601d2819fed0bfc7bf97397d24b70e745ec611",
    "b3ca23c138625a785a59143c184790e16f751cb118eb886ecf01b2fa5ddf650c1e9217a21bc711b2cc48ca01cdb1d5027bc584a5faf0be59f9819e45bca97de7"
    "737c3cf19cf8661047fcf1b75f877182d3fd418a2d270ac9d8497387df8e6d6c6ce53a17571b2e3a4fa287791efab5bee8cff9df8479660ae69947db6d627c00",
    "f3cc53c483796632fcade68d18439d1ab9efce087d7afe609995fb74952947d9ac8f9bc7b6ad2bedbf648d8275a566be0baa4a0abeefeb323cdbce0feda6b8f8"
    "79a77a96583bea26ab923f2814d6605de902f5e37e81effb42bcaf6f37c4fbb3c583789f0c7f97c4fb65b12d5465caee783f47cc2f7c0f8387e488e8cff985e1",
    "878e239c2a1b8adc78c0ee73a60fb0781a7f4427e51746c566ef7705a8cfef2dc1bc80d3fd425cd8cb6e850fd3572cdfcd9c35ab7c46495fba685e00fcc2f8f7"
    "32e717f689e58126c5e7aa0878ba3b3bbb6f75fc98c4e269fc119dc0f8712029fbe78bae1f3f007bef787b2fb5bccd33560e86f9b56c48c8968f02bb07f216d8",
    "7bb0f76ab9b6d7deb302d87b73f69e156660efdf067bef7c7b5fa78f4399c061ba152a8795c82a9d0932c19c8bd68182bd1fff5ee6e2fb0362799f97fd7eb050"
    "65ba0941c9339cd8ecd367b5cfb8f7927888ffa9a16ec44374e2e752e92468ebbcc07e50807901a7fb87bdbd7824144e49c9da1e2ff3d946237ce4bb72d178e0",
    "33ccf366e5f8330c7f2447449f76bf5eae7122ad942afd3c6fa9220a0acd0a7209dd84b2e636ebeba70c31fff13a060fc919d10dfe63209594fa376e4877eabc"
    "411e8ba7f147743271c8add86630ae80fd6553c4b3cb6f74d603c11093dccdd4a21bca4988ceef4558de45f3c97fc33c6f568e5d439d1ab96ff4ff3475bfc1ca",
    "2599ad0b4c55ef2c6cd5cf5e05f24a26f120af441a4f2b8b8207792532fc7b98e7613f99bee8f5701becbc493cb0f3a4f1b4b2287860e7c9f0ef619e073baf2f"
    "fa79e214ac0b328907eb8248e3696551f0605d1019fe3dccf366e5788ce18fe488e804cf0b5aeed0d2e0a333a5a624560def738a692f593dbccddb5c63f89995",
    "df1b183c243f44574552522d59a9264a9c28364b6287916a9c7851aa3498ca39cc0fbf507fb4b0e105f2b3757ef8c34fee835f70ba5f907763dd58f4ea2a9bec"
    "fa8329bf37920bfbbc2ef81ed9ff01976eca9e", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 67800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
