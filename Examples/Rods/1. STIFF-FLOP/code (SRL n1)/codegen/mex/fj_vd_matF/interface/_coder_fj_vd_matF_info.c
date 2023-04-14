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
                (737430.88297453709));
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
    "789ced5d4b6fdbd81566d26490a0980e81b693298a4ec7d32268918129cbb2651728603d2dd996f58c5f99a9424994449b0f89a464499b6a398b59f4077491e5"
    "b4688bb49b0698c140dd755ba0d34557018af909edba9428dae68d6ec498146552e700c1cdcd21ef777972f89dcbc3c32be25632758b2088efa87fdef935417c",
    "fa1f62246f6b0d418edbdb845150fdad71fb10e9eb7297b86338efd618efb7e37e591414a6a3681d8e1598fd165f6224b523d03c73314c45e45981169442b7c1"
    "1012238b5c9ba98c345596630a2ccfec89573a0956edf0f12baa8bce5035fc7ba4ce94cff22d9e90eaf2e574b9ab1d626c9fa1bcc05cff1d93f6c961ec4322fa",
    "27b14fa8bac833549daeb0542ab61d92bb42994a0c7ba196221652856857a0226285b9da0f330a4db557967d5479a8a99e16db95224f2bf165de781d4f31f37c"
    "cbe475a0ad2ef7897b577aeb5bd3f0ccdaed2e068f1c6b1ae2f9c85becc27b0be95fe2699a8ad82a71cc25dee716f142583ca3fe4972ef48758d962c519c58a6",
    "392a152aec85c254ceef5bd928518a287225b143313c47716c8952ffeb39ba44890d991a5948770307fda0ffd9d7ebff0a39eb774efbf9fcf03a98f1ccfaddbb"
    "183c12d11fd60f98f57c36bf962b645b47d1dd930331ff3872398fcc149c69f320307da7c677ebfddbc0cccbacbfdd46fabadc478ed7e4e196d67e78c1eb7dcc",
    "f866edf6630c3e89e887e14c5a66d5458224d0dc322b875b2ca724057599c0486c796ebcefd87ac0bcdf0cff3c1ad98b7aa41b8c420de6fc7aa0ffd7fffefb6b"
    "880333c2732a0ea4dbcd48a89a686f14b2816e39c60bfef80997f04e1c788e39dfac1d7730e39388de721c58aa728abee8251cf6bb7e6acb2ebf7b80c123113d",
    "c2ffb26a325a8ad5e6c6fb37d04f26f2be6ea839f0fd9f1efe0ad6fd6ee77b5faeb6d256763645a95697f371ba168e27db51e0fbc5b98f0903dfe39e37ccdaeb"
    "6da44f20c7e97a5616b485aa32ccf4cd2faf63d53f92583ca3fe0dd70355b6c3541aa2ea1e94c15273c8ef107f3cfc01acebddcef3dbab67dd7cb3c6729142e4",
    "2cd70cd70a678f63c0f30bcbf3383cb3f6ba87f4898be3340d2b5759f5a1a6eed67c7d148b67d45be175cd429a27009f7b03cf2a9f7f1f834722fa76938935da"
    "6579f3e87c551433727e65f5f884f00e9fbb25ef7ac9e74b555692952a6bbc8ea79879daea7f83a7b6e5ebdfc7e091885e3546513542b12a4a9c28368a629b91",
    "aa9c785e2c0fdfb75b5fcfa3829b8f2e3adee09a78faf82753f074fdf5f27b63377a8de59c5f170cbefce62ee4716e6a3c30bbbe9777639d58b4d7cbec74fc81"
    "94df17c986567c31efc4839798f3cddab18f199f44f4b3bbaf975e7f40b1ce700d4672d64fb76d7b1eb883f4898be334cd70b53b6ce7fc5e81152a4c27292817",
    "f37866711e5b53e6a1ebad3d272cf30efac50b788febfe7890ef36587ead993b5c614b9540f2249b49ad7829afff0c73fe02dfb7aaf83c93c79f164fca757af4"
    "661cf2f8935b5d20efe30c1ee4f1ed19ff25e67c58e74fbe5e737e9ab46d9d3f2d0faf5e384f77e617076e68de5ff71f4efd0ba5d9c8e9bcffe0c583fb90e771",
    "3bff4b4d5fe3949503217e3d131432a5a3d5dd03390cfc0ffc6f14e37b5f67f99f1580ffa7f13f2b38ceff5f00ffbb9fff6bf47130bd7ab8df0c96424a648d4e"
    "07984076db3bfc0fef7d27b7ba18fcefe553db78fd4df3f756f1deb49ee79945bc2d2c9e51efa27c1fe4e9678807797a7bc677219ff71849945bbcf13a70f9f4",
    "997c873bf8786bd46e7de218bf575b1c376ca15e73d2ba5d6ed052b52550432b39bd6eefff19f2f6eee77965ddcfe7a287dbf59355b1d756527c3cb5a27888e7"
    "9f63ce87ef6aaffadd65fdfda798f1ccdaeb67183c12d123f52f74a3c175c3ac404bddfc28e2c55b42596145c1aef7c6ef4c9997aeaf8e718b755aa8a881c0ae",
    "facd2753f075bdd5f502d690e337bb0ec687bffc4e82bc8edbe343361b51ce32a7be60e9647f77bf54a037d22939ee9df830c09c0ff7b5518c7e18b42d5efc04"
    "8347227a345eb445b6129224ba1be76845610456a88d8e9b577dbfd5e7c9832978badeb21f4d30dcd0851cf49ffeff4a1017dc1e177a3b89d5c8e3c6119f2da5",
    "2ba1a36a22d5e1d31eda8fc7eafd5cc08c4f227aebcf0d5a86a858e5445a295e3c4138fb9dd709eccb6311cffbdf79c3be3cb3c4837d79ec19df2aef6731e393"
    "88de3aef0ba2b24fefa7a5a47a6bd7f4b491c3fb361cdaf61e60da3ecbac2cd002e1def700112c9e516fa97e676823e7f33cf0be7786784eeddbd00cb5d27ca0",
    "7b14f0e5247f2bb2c26cb6f97dc23bbc0ef7af518cfef653dbf669807d957178463decabfca6789a2c0a1eecab6ccff8b09e9fdcea825bcff731e399b5db0f31"
    "7824a29f98c759ae72a2a859c0adf99c3416cfa8b71a071e6916a3461653838083fcff7ba8ff713fff97eaeb992381532a79918fb584c46a2916def150ddfe0d",
    "cccbdebcfa9ffebe6df9fbef61f048448ff03e2349a2a9f716b3fa3eeb86adfb65757a4c85d2d87eccf928f58f6c368775ff57bbc790c7773bef7784ec792fd5"
    "e0c3dbcd685cde88ec34dba20ff2f86f7e3f7becf712fb98f1ccdaed030c1e89e811fe971895f11a4c9eed693f8c29bbb58e273f054fd75b5df7bf6230e7f3fe",
    "fff8c3e71007dc1e07d6b77d5c3013cc660e1207f2c1e17a6d37d7f452fd3fdccf935b5d8cfef7816dcf01ef61f048448fc40181966aac50ae9fb995ff6daee3"
    "34f31c70613367eb38fbdffd45ee9fc0ff33c2738affbb9df3e4261dafd6d67ce5744ccc9fc65bc1730fedcfec95fb19e70f66fdef5b98ebd0bff37dcff0af1f",
    "6d69ed87e3f6a163753e7ae61fea7c26d7098cbef61de7fa87e2203ffdedf143c8f7bb9def379ac174a1c945d7cec2f542763baf34a3d1b287bee782fbd728b8"
    "f57d1f331ed4f998c3833a9f59e169b2287850e763cff8c0fb4699557de74da9eb41c56c7ee7f935f1f4f1a1aec76e3c4d16050fea7aec191ff8de2838beff0d",
    "663cb376fa39068f44f493f6f3316e549114321c5d66c6c7ebf36b589cdfbcf7f5f9780abeaeb765ff8f8906757cbfe6d2b74fe1bdafdbe38348ef9d96687a3b"
    "5259dd38958ffc4ceaa4d1f5d07bdf01e67cb8af8d62f4c38f6ccbf34fff1df6e1de9532e3d63c7f028b67d45bdbd753b79293fb376fddfb25ecd3e07a7e3f3f",
    "4cca71eeec20eeaf4a79ae7d9ade117ad908f0fb62f3fbb2e7f240d7e57fc8034d9e3fe4819cc1833c903de3437de7e45617dceff05addb773098347227a342f"
    "24cb8ca41cd01c5b199a2224d5c6c7b9f53df00cf6f99bbc8e78c5708ee77d6e47cee1b9c0edf1c0ef3feb6d46e3e1646daf933fe9254a89cd9c02f59e0b783f",
    "abd2df827c8f493cc8f7d885a7c9a2e041bec79ef181d727b7ba18793d04759ee37f873acfc9ad2e50e7e90c1ed479da33fe0073be593b1631e393887e167160"
    "899587fa9a4473cefae1e0d8b1efb786975825e0fbadd7eff3aada08f669f6149e53fcbed64971f1b376e534b97ed4d9a948fe80905f87efb716e0fe1d0aecd3",
    "0ceb7ae3bc615d3f5f3c58d7db33fe0073be6bd6f525b125546487d7f559dbe2c18f307824a27f251e8cb7ab8e70aa6588f9eddff9dc225e06e913c871bade7a"
    "3cb86a3047f3fc9fbd7b1ff2fc6e8f0371612f130e1deef758be933e6d54f8b4b2dff5509e7f80391fe280518c71e0b16df99d69eb70d5003cdd991fcf5b7d3e",
    "8c62f18c7a4bcf87231b395e9ff3e201f0bbebf95d6afa1aa7ac1c08f1eb99a090291dadee1ec861e0f785e677e2c0517e6705e0f769fcce0a8ef3fb17c0efee"
    "e7f71a7d1c4caf1eee3783a5901259a3d3012690857afc8bf116aa4e874800af9bc4035eb70b4f9345c1035eb7677ce0f5c9ad2eb8dfd3c2e1413e4613c8c7d8",
    "85a7c9a2e0413ec69ef1ff8e39dfac1d69ccf824a29fc1f7b34b6d5a1a6d955f6c486205b9aea79879dbcbf365dbdebfbe8fc12311bd6a9ca26a946255943851"
    "6c14c536235539f1bc581e5a657efb6a0eae89a78f7f32054fd75f330e686ef51acb395f9733f8f29bbb101fdc1e1fe4dd582716edf5323b1d7f20e5f745b2a1",
    "159f07bea7fd3f9fd3518f", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58272U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
