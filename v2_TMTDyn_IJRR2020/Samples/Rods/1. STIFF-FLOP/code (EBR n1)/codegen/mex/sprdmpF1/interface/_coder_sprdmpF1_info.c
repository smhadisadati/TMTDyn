/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF1_info.c
 *
 * Code generation for function '_coder_sprdmpF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF1.h"
#include "_coder_sprdmpF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94940972223));
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
  const char * data[21] = {
    "789ced5dcb6fe3c619e726bbc12e82b43cb44d83162db62d160db630f5b2ec459b56ef876dbd2cd996b59bdaa4444994490e45522f5faa630f3de4d4530f7b4c"
    "0ab4487b68174851287f447ae8692ff913d2734549b4cd8166259b1465d23380311e7fe4fc869fbff97d33df7086c4bd74e61e4110df1afffce37704f1fd4f89",
    "497a6f9a11e42c7f8b3026587e6f96ff102aebe90171df70dfbd19de9f66e52a1055b6af4e0b3c27b2d98ec0b0f2b820d2027b514d0d089c488b6a6920b184cc"
    "2a80efb2b589a4cef16c8913d83d70a590e2c6052171457451d044daefd1265b3d2b7604426e2a97cde5af1688997eb4f439e2f9ef2fa99f3c423f24247f1eff",
    "986a0281a59a748da332f164581988552aa595c21d159432a5d840a4a2a0c65e2d475895a6bade0d0f55d5248a24d70429e1dd10f4f69f22daf7ce92ed87733d"
    "3d221e5e296d8616e12dabafb71178e44c5205d37f945578ef40e54bbca9a4063a0ccf5ee27d6a122f8cc433ca9fa7f7ca6393e82832c5832acd539970692f1c",
    "a1f67d1eef3643a900f00ce853acc0533cc75002adf23443b17cbd238e4d41d91066f5d868075f1e3cf92a6cafddd9fa7c6bc5eb23ea5bd6eebe87c02321b954"
    "eab7b6726a3eb895a34bc556494e0eaa62e4b21d3a5fa17016b5834094edaa1ff75f6332dadbcf2e787c88a86f593d7d80c02321b9e6b6e40d6e3c1890459adf",
    "50c6aaa2e50d9de5cdf33c9c50edd193557e3fb3004f975fc34eb49fa7137d514f7585514fa71abbb019fbec2514fce36798ef9dcef7dbf29e4217aa99e323e6"
    "b8cc4422c140bdc162bebf737cff09a2be65f5f421028f84e410dfd392c40f8a130a4b74c4aaca01312de679baaa4f01f5f64926dbf7ed05edd3e5f5592b4e9a",
    "b4581b0ffc75fc9149fc170bf075b9597f8056e8d4c4ecb3af11f36eeb3fd83fac08cf2eff00e8bd1643d3c968cdbfdd52ca3e3653910631f7f88711e27edcaf"
    "8dc96887bfb02cdef3102a1317d74d259ca248b4acb04e8df7a4907846f9cdc60f9a6eb41184ae253be37ea1871ffd16f3bbd3f9bd77945612fcd961c257978b",
    "7cb795db11cf0b51ccef779bdf375c1707ba29ffe338d0fcf6e338903d78380e644dfd66fb711e2a13d075ba7c55ebb8a8f8ccb27687e2bd47b3dc63f8eb47a1"
    "69fecb59feeb59be35cb7f33cbb72d9b073c40b48f9c4924d09bbc1de0d479c06ae3884052a88986d610471cfee1ab209e07389dff8f9a876cb058286eee970a",
    "9d726cb772088a072e9a0738b5ffa2e2decbdadb5b50594f3aef9386bf3e094df39f5836feff31029f84e4d0f89f53221d8e57d362b623b032575d1befbf3289"
    "b78fc433cacd8eff6185e98664a31ff8e737ffc5f300a7fb815cb71d0dd753dded522130a8c605d197a8f029f7f801b3f3801d44fd242437ed071ed779551ff4",
    "1236dbdd3013b2caeede47e091907c6efc27de706cdc6705763297f77545ad81effffa04c7ff1dcff79efd86b7abee3c0372a3a9141374239248775db4be8bfb"
    "f1fcf6a3f81e35df58565fef416502ba4e97738a381da8aadace0ee7c6f7d3483ca3fc9ae3813ad7676b12189b0765d0d43ade13fbcbd107785cef749e4ffacf",
    "06c57683e3a3a5e8d97e3bd2289d1dc431cfdf599e47e159f7de4e9d1b4f6a9a4e8dd7c7907846b9195e9f6ac8f6f57dcce72bc433cbe7df45e09190bcdb66e3"
    "52b7aa3c2bf7fc00e495a2d77f5c21dcc3e74e89bb5ef2f9e33a272b6a9d333ec729a29d96dadfe8d4b278fd8f107824241f2be364ac84933a907900a413d065",
    "e53a0f7a27556d7ff5faf66d8d6e88a7d75f5980a7cb6fb8df636a466fd09cfde382d1bfbe7e80e338b7d51f2c3bbe5776e3fd78ecfc3cbfd3f705323e4fb410"
    "f67ae2eef107af11f72fabc721a27e1292afae5f3f7ef305274d969758d95e3b4d5a361fb80f95898beba6126db4abe56b5e57e0c41adb4f8bea453b5e9a6c47",
    "68413b74b9b97982ade779bcc2ebb8cef707c581c4099bedfd232fc7d402e94a219ff1ba29aeff1271ff1deeb7e3e4714d1c7f913fa936e9c9ca388ee3cfcff5"
    "84e33ef6e0e138be35f5bf46dc8fc7f9f39f77393b4d5b36ce5f14871f3fb840f7d7e7076e69dcffe2bc8ff12fd45447b69fc7f0eafd4738cee374fe97db1ea9",
    "c52981b010cc6f8979a6ecdf3d545cb44feb35e27eccfff39f77293b1ddacbff9c88f97f11ff73a2edfcff05e67fe7f37f833edecaf98fb2ed2d26ac4637e95c"
    "800d1492eee17fbcee3b3fd793c1fe5e9f5ac6ebd78ddf9bc5bbeefb3c2f4de285907846b983e27d384ebf423c1ca7b7a67e07f2f9392b03a523189f03154f5f",
    "c93edcd18bd0240f7d6c1bbfd73b3cafe5f87dcd379db3a669c9ee71fbf06f386eef7c9e57833e613f76946c56fce0bcab668444c6abba88e73f47dc8ff7d55e"
    "b5bbcbf7ef7f8fa86f597dfd1c814742f279e72d47389196a1c3e6ac5a375ef739cbcf17e0eb724bceeb9ba7c8d9caae8dfee1ef9fc938aee374ff502844d5b3",
    "7ccbb3c554b2bb59a6446fe7324ac23dfe6184b81ff76b6332dae19665fee2a7083c1292c3fea20bb85a5896e94182a755951539b131b96e5deff79b9d4f1e2e"
    "c0d3e5a6ed688ee23413b2d17e86ff63b05f70ba5f38df49f9a30752592830b95ab85c4f65fa42ce45e7f198edcf2544fd2424373f6f9846884eea3ca0d5938b",
    "1984bdfbbc2af85c1e9378eedfe78dcfe559251e3e97c79afacdf27e01513f09c9cdf3be08d42c9dcdc9e971d76ee861239bcf6d38b26c1d60d139cb9c22d222"
    "e1dc75802812cf2837f5fe8ea623fbe33c78bd778578769ddbd00e77724260500e78f6655f27ea659f75852ce11e5ec7fdd79856f57d5d7cae320acf28c7e72a",
    "5f176f9aee0a1e3e57d99afaf1787e7eae27d4787e88a86f59bdfd00814742f2f9dfd7aaf3004c35e0d4784e0e8967945bf57dad89c6c64ec046feff337effc7"
    "f9fccf3483f9b2c8abb52210e21d31e567e2911d17bdb77f0be3b2b7effd9f61d6b2f8fd771078242487789f9565b0d4bac5aaf667ddb271bf326e1e5ba3a66c",
    "3fe37c98fa273a5bc3b8ffdfbbc7388eef74deef8b85de79461222c9762ca16c4777da5de071511cdf2cefe7a132015da7cb57f55dc55344fbacb5bb5f5916bf"
    "7f1b8147ce248ab6f996706efc3e8cc433ca6f1affd3dee257f4cdb7849dfc13faf2e0091ec73b9dcf693a15a9f4ce52dc6126dae1231131b695cfba88cf71ff",
    "35a655c5efcd7d175d67f9f5bd8769d6ef6716e0e972abe236bacdd8672fa310fe2ebaf3f9deb3990a6e477b473e4fa4d7e33d121f8835ce5d74de0ee67b6342"
    "f1fd2788fa96d5d387083c1292cfdbaf65dc889016f33c5d6567d7bb65dfd68b05f8badc92fd1d73156afb793cccbb2d1cdf71ba7f00f45e8ba1e964b4e6df6e",
    "29651f9ba9480317cd074688fb71bf3626a31d6eb86e9e70d378109e27cc6f3f9e27d88387e709e6eaff3f34bec72b",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF1_info.c) */
