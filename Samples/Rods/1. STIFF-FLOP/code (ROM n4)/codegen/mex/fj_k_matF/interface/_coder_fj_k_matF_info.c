/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_k_matF_info.c
 *
 * Code generation for function '_coder_fj_k_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_k_matF.h"
#include "_coder_fj_k_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_k_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_k_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.19488425925));
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
    "789ced5dcf6fdb541c77c78636a18125a46d08012b4293d0a63a4d7f0e09a9f9d9a46b9aa4c9d2ae0332c7761227cf76623b69d20b3d22c4813f80c38e130289"
    "1b93e0106e5c918003a75db872e38e1dc769fc96b778b5ebe2e47da5eaf5f56b7f3fcfdf7edfe73d7ffd8d43cc2553730441bcaefdfcf339416c7c49f4e5aad1",
    "10e4a0bd405805d6cf0ddaeb50df944bc445cb797303bc6f067d461255aea31a1dc08bdc4e4b2871b2d61169811b9a612581176951cd771b1c21738a04da1cdb"
    "d79479c0e57981db96463a095eeb08f111d5b0a3abf4df23558ea9e75a0221579593e182d10e31f08f2e4f11d77fd1a67fb208ff9090fe61ec53aa2a091c55a5",
    "599e4ac536434a5764a884de0bb554299fca47bb221591586eb41fe6549a6a2f2e042846d7946bc57a51a0d5f882005dc723c4385fb5791d706bca15e2f248ef"
    "e68689778cb067d76f37117824a4d72f5b5ee0b56092451a2c682152a51b5c8e3f32fed1caa4eb9f341e5850e331c5adb8c94dc033f50f93dbfb5ae8b4149902",
    "1243032a15ca6f87c2d46e30b0b85ea254490225a9437102e8ffdceefb8bba6d3a8c7ace6183c8f12e6e8e7ffbeec99f216fe3d4eb79717e781d843dbb71780d"
    "814742fad5cd0058cbac653385444129ecad56eeed36d5e8c938321370268d8340f4bdb28fe7f3f8d614d43ae034fe6e20f048480fad03222d577891a9d6fdca",
    "ff850978a6de66bc684121732c6544cb2066e0d019fa4c0f190ff9ffcd8f767fc7fc7f46785ef17fb77398bc4bc7cb959500938e49b95abcb57618c3fcff7f9b"
    "cfa878b01b7faf20aee3caa0bd61f9eb9d0da37d7fd0deda70cac726ee25c438c881a60c2449bf9b740bef55a87f82676858a95502dc09de13877811249e55ff",
    "12fb05c09728edde10d0258a03e59648f57de4fdfee097fbb7fec07c7f46785ef1fd7a732d9d6f82e84a3d5ccd6737736a331a65e2d3c3f778fe5ae5acf23cef"
    "21f048480fedef7925dce2819a14775a0227f3ccb9f1bcd37dc12e12cfaa777a5f083bcc4c107ab8cffff1dfbf30effb9df7d3ed6624544eb4d7f3d9e52e1313",
    "c460fc002430efcf06ef7fe01aefbf8dc023213dc4fb8ae62a5a5e3077f7cef7f7b0d8cdeffc704a3cd37e7a029ea977cafbb70d8f0d63c643beff76ef2dccf7"
    "7ee7fb527535b32f0295cd4942ac2526964ab1f0d626e6fb59e3fbaf11f6ecfae943041e09e921bea71b0dd0cdf5292cde12199597c4a498013463960898e36b",
    "381cdf1b13c667eacb835114abb4c86a3702267ecf21fe2713f04dbdd3f500ed5023c0bc8baf5ee9b51a7eeeebf7f541a2b76b259ade8cb04beb35653fc8a50e"
    "1add297aeedb439c8fe7b555ac7178c7b53cff65a84f0c8f3334bca2346859e1fc9ae74f20f1acfad3ed1f74dfe83b08d34b0b827771b071f9e3cf30bffb9ddf",
    "0ff7924a1cd40bf16059ce81762dbd251e652398df679bdf17a62e0f745afec779a0f1e3c779206ff0701ec81dfbb8be737c6b8a35fe0243feff0261cfaedfe6"
    "117824a487f3428ac2c96a81063cabbb22245706c7f9f539701e8967d53bde473ce738cff33e172287f8bec0efeb4130583fba1b8d879395ed4eeee028514adc",
    "dd5571bde70cce674d8e3770bec7261ecef7b88567c8ace0e17c8f3bf631af8f6f4db1f27a08d7790efe8eeb3cc7b7a6e03a4f6ff0709da73bf67b88f3edfab1"
    "88b04f42fab35807e67945d757641a781b87bd079e7d7e4bbfc432813fbf85aa0bd37ea1fa3ef2fe7d0d4f31bffb9fdf573a2910afb7d95a7275bfb3c5cac165",
    "31b78a3fbf3503f35717f7eaf8f1be1e8567d5e37dfdcbe219322b78785fef8efd1ee27cdfeceb4b524b64158ff7f559d7d68377107824a47f6e3d48ea77349c"
    "1c019a6708f7f6fd17a1fec9780c0d53a5fb05446ed5f364a03e011d67ea9daf07a30ef334cfffd5b52b38cfeff775202e6e67c2a1bd9d235ee8a46b0d5648ab",
    "3bdd29caf3f710e7e375c02ad675e0be6bf99d49fb70cd0102dd393f9e777a7f1845e259f58eee0ffb3ef2bc3ee7e975ccefbee777b91968d478653924ac66d6"
    "c44c697fe95e4109637e9f697e270a9ef23b2f627e9fc4efbce839bfff84f9ddfffc5ea11faca597f6769a6ba5901a59a1d3cbdc7216d7e30fedcd549d0e91c0",
    "bc6e130ff3ba5b7886cc0a1ee67577ec635e1fdf9a62adbfdcc1f9189b78381fe3169e21b38287f331eed8ff1571be5d3fd208fb24a43f83cfcfceb769b9ffaa"
    "fc62439658e8ba1e21c6ed2ecf33ae3d7f7d178147427acd3945cd29c5b22403496a14a53627978174586474af9cdf7b357ba7c433ed1f4cc033f5a75c078cb0",
    "7a81e7bcafcbe9fdfcf725bc3ef87d7d50eec53ab1e8d15166ab135c4e0503916c683130459fa77d8638dfae1f8f11f649487f76f37afec50714ab1c6870b2b7"
    "71bae9dafdc1a4fd3aaf94f5efd6746d5ea0be379484f4709d90c8729da4a80ec7f1d8e13836268cc3d4bf645c95f90ec736246ddc94ee392feb73085c9f7f86",
    "785ead07b96e8317569abb7b8b7c895d4e1e6433a9c5f614bd57f331e2fc199eb7c4e87b751a087b76fd7315ea13d071a69e5744a3a05cd5bf61d9bf75974924"
    "9e55ef241e463c751edfaffc3d7e8f9aff797d73a9decd352b3c88e423f5dd66b892afdf8f4d11af3f439c8ff7f9e3afd75e9c26f173009b78f839805b7886cc",
    "0a1e7e0ee08efd6788f331ff8fbf5e7bcf07bce57f5cdf83eb7b4c99153c5cdfe3ccfe7fb63b3c52",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
