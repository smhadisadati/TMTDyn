/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF4_info.c
 *
 * Code generation for function '_coder_massF4_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF4.h"
#include "_coder_massF4_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF4"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/massF4.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.22800925921));
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
  const char * data[29] = {
    "789ced5d4d6ce3c615e6a649b141904640da246dfab39b068b041b98b224cb768100fab7e4b5ac5fcb5a6f529b122989327f249292255fea630e39e4d8430f39"
    "a64153a4bd24688b42b9f55aa0e9a1a7058aa2975edb734591b4cd594dc43529da94de038c31f5c4f9460f8fdfccbc7933246e65b2b70882f8cef8efb35f10c4",
    "2f5f56af08e24542139f5e3e439805d5dfd2cb15e4da90e788674df7ddd2f17ea55fd7454161068a76c1b102b3dbe36b8c34be10289e39af86167956a004a53c"
    "ec3084c4c822d767e889a6c1724c99e5991df1d2459a1d5ff0a94baaf30b55a5fe1f6f31f5e3528f27a4967cd15ceef205a1db47952f31bfff598bf6d9c3d8c7",
    "87e81f25df275b22cf902d8a66c912d560c86c722b2a0f853a99563f2a67cb89a140c6459a31fe8f310a45f6032bfe3be99d1d3245d524b64e32224ff2942ca7"
    "422bfca5df31c0b4f3db167fc7b730bfe379bd7cedf287914711ed1fbf5e4623463bce303856ed7907d30e1fa2af8fed24adb0632793048a5b19bb4e8bea3025",
    "f6547300d968cfd115db830aae3d8638e54fa5197886fe5166a73a76a99e2c919c58a738321b2def44636431e05fdda8918a2872357140323c37f9bb3fb11779"
    "df3018f984c126de74f13b8e30edb4ea4f6869c8f3c46dfdbfb3bffee693bf47ddc3d36459f0707c60d50f5fc1e0f9107d78cbcfade7d70bf94aba2257f6c3cd",
    "07c5ae92b868477e06ceac7610986bb7ea87e7797a6988d9ffee449cf2bfd7906b02f99ea147fa0181929aac506f1d7b95ff2b33f00cbd457f193b85c4d0a4e6"
    "2dbacfa0ae736e33d5655ce4ff977f56fc1bf0ff9cf0dce2ffe1e024b349a51acd357f3d97144bed546ffd2409fc7fd39e6757e707c43b11ad7c432fef45ecf2",
    "b181fb1ca61d3e5dd3e044519d653a85f76de4fa024fd3d062afc63117789fd8c48b63f1ccfaa7182f706c6d3c635438aa46325ca32790131bb93f3ef86aefde"
    "d7c0f773c2738bef37baebb972974bac1dc75ae5c25649e92612f5d4e2f03d3cbf66c18defcf30f559b5d34f30783e448f8cef5939d663392523ecf6784662eb",
    "d7c6f376c705452c9e596f775e881a4c771b37c7f95ffcf71fc0fb5ee7fd5cbf1b8f36d2fd8d722134ac277921903ae0d2c0fbcbc1fb6f3ac6fbaf63f07c881e"
    "e17d796c2a4a5a3146f7f6c7f7a8588def7c7e453ca3fedc0c3c436f97f7ef6b163bf71917f9fed3fdef03df7b9def6bad70be2a700a5d12f9644f48076bc9d8",
    "f616f0fdb2f1fd4798faacdae96d0c9e0fd1237c4f753adcb034a1b0544fa82bac2864843c47d58dd401a37d1d9bed7b6946fb0c7d436fc5618b12e8f144c0c0"
    "1fd9c47f6f06bea1b7db1fe00daa39987bfe35aabdd086755faff70f22b5d3ae51d4569c0e6eb4e56a80c91e74860bb4ee3bc2dc0fcfb559cc7ef88e6371fedb",
    "c83571fe3d4dc3ca72879264c6ab71fe3416cfacbfdaf841b58d3a8230acb4c2bbe70791dbeffe1cf8ddebfc7eb29f9153dc712515684825aedfce6d0ba78538"
    "f0fb72f3fbcac2c581aecaff10079ade7e8803b98307712067ea87fccee9a52166fff39ff3ff0798faacdaed2e06cf87e8d1b8902c339252a13896564d11959a",
    "faf7bcba0e5cc6e299f5b6c7114f18cef5b8cf33f113981778bd3f08048e4f3713a958a6b933281d9ca66be9cda202f99e4bf83c8fe52c02f11e8b7810ef710a"
    "4f9365c183788f33f503af4f2f0d31f3ba73fb7921cf138767d6439ee7d3e269b22c7890e7e94cfd23ccfd56ed7888a9df87e8e7d10fdc656555df9428ce5d3f",
    "1c3d746dff96fa131b04ecdfc2e5858dff21273672ffbc862f81dfbdcfef6b832c973aeed3ed4cb83ad8a6a54048288561ffd6123cbfaa3897c70fe37a1c9e59"
    "0fe3faa7c5d36459f0605cef4cfd23ccfd9e19d7d7c49e40cb2e8feb0b8ef5073fc2e0f910fd13fd41469dd130529c1b5b86706edcff2c727dd11e4d536f5193",
    "0422a7f279f2c835817ccfd0dbef0f2e1bccd538ff87af3c0f717eaff7032961271f8beeef9eb2fc20d7eed07c4ed91d2e509c7f84b91ffa01b398fb813dc7e2"
    "3bb3c6e16303f0d4e0fa78deeefc3081c533eb6dcd0f2736723d3fe7cb5781df3dcfef52d7df69b37228ca87f3eb42be560d3ea8c831e0f7a5e677a2e22abfb3",
    "02f0fb2c7e6705d7f9fd8fc0efdee7f726f5703d17dcdfedaed7a24a7c8dca85985001f2f1cfeb5baa3c1d220dbc6e110f78dd293c4d96050f78dd99fa81d7a7"
    "978698f32f77211e63110fe2314ee169b22c78108f71a6febf60eeb76a470a53bf0fd1cf61ffecdd3e254d8eca3fec48228dfcae234cbb9de5f9ba63ebaf3fc6",
    "e0f910fdd8388763a31c36448913c5cea1d867a406279e1cd655ab5cdfb99aa32be219f51fccc033f457ec0734b7fa06cbb99f9733fad3bf9e83fec1ebfd83fc"
    "203948264e4ff3db8340281bf0c70bd155ff02eda77d8cb9dfaa1dcf30f5fb10fdfc9eebbbdffc85c316c37518c95d3fdd726c7e306bbcceca0df59d9b8e3d17",
    "af62f1cc7a344f48a099414650cedbf1b1cd764466b4c3d03fa55f35d8014377c471bb49d5726ee6e710909f3f473cb7fa83d2b0c3f26bdde2fe2a5ba3439983"
    "423ebbda5fa073353fc6dcbfc4cf2d71f95c9d0ea63eabf67911b92690ef197a5616b48472457df3b277f32e33583cb3de8e3f5cb29431cc7793873e8373d4bc",
    "cfeb5bc1e361a9db64b978397e5cecc69ae5e3bde402f1fa63ccfd30ce9ffe7badf96906d6012ce2c13a8053789a2c0b1eac033853ff63ccfdc0ffd37fafb5f5"
    "0177f91ff27b20bfc79065c183fc1e67eab79bdfb387a9df87e81f8d1fde96c833648ba259b2443518329bdc8aca43a14ea6d58fcad9726228907191668cff63",
    "8c4291fdc08aff4e7a67874c51b5f1649e64447efc74cb722a3479a067c5a7acfa1fee1c4be33de911d3a741fd32a0979b5a7916d3af437a19d7cb35bddc70ed"
    "3c9e8e78c278f97dea512c9e597fb57e41ecc8e4c442d710173afbf0eb30f40b5eef17f65b15265c2a94d68ae542af9a787050114b7b0bb41fd7abcf2f2e0e6f",
    "d5df9ec1b4dbe8077ca64fef45b4f20d389f47ff1ccee7995e1a02e7f3b88307e7f33853ffe798fbadda711b53bf0fd1dbee07ee3638c518f4122efbdd5936e2"
    "94df5d31cf467b5b54b2796dbc7f03fd642aef1b86ba06beffed3d386fdff37cef2f3657fbcaf6a628355b7229453563a9cc22e5f9c0733cbdfd38bec7cd37bc",
    "92f7e336cf43de8fe3781359163cc8fb71a67ee0f9e9edc7f13c0ecfaabd66bf27abc18e27352dafc6ebe7b48e8be4f7aa16727d5f37f0f91cf1ecf2f9f73078"
    "3e44dfef32c94ebf2e6f564f82a298974babc18707c4e2f0b957e2ae177c7eb7c14ab2a2ed5272d9ff4647b07f572f4757c433ea87fdbbf3c6d36459f060ffae",
    "33f5437f30bd34c4e47f8f8f1c1be73fedbe5cbb784f3bceffd8265e048b67d67b681f1fecbf9d231eecbf75a67e0ff2f9292389720f199fe1e2e573c9cf19bd"
    "17999491f75de3f7468fe3d412e238dff4be73d54a6ec771ce7e07711ceff3bc120ef0c5c4fe56eb20289ef6952c9fcaae2a0bc4f337302e7ff3f26d888bb8fc",
    "0798faacdaeb2d0c9e0fd123f93654a7c30d63ac4049c3d2a4c74bf584bac28a8253ebc22fcd6897a16fe8b8872d4aa0c71d8153719d4733f00dbded735b7186"
    "74ff3db9bfffb504711daff70f85425c39ceb7fdebb583dd07bbb532b591cbcaa9c5e91f4698fbe1b9368bd90fd71deb2f7e8ac1f3217ab4bfe88b2c1d95246a",
    "98e22845610456684ebe775d717fbbf3c9ca0c3c436fdb8fa6184e752117fde7ec7f35e817bcde2f9c6ea783f1bd4e952fd47274b4da4867077c6e81f2f46fe0"
    "39fd98798316213a6c7022a51c9ecf20dc5dff3d807c7d9b788b9fff05f9faf3c4837c7d67eab7cbfb054cfd3e446f9ff70551d9a5767392fe1e6ce4771c61da",
    "e96c3ee7be6be72fb0b240098477d701e2583cb3ded6b93caa8ddc8ff3c07aef1cf1dccae7ec467b393e34ac86fc4529d08baf329b7d7e97581c5e87e7d72c66"
    "7f7b13ce5bd03ff74a5e009cb7b0d87870de8233f5c3787e7a69086e3c7f86a9cfaadd5ec7e0f910fdd438ce4a831345cd025e8de7e4b07866bddd7ee0be6631",
    "7262b17127e022ff7f0af93fdee7ff5a2b9caf0a9c4297443ed913d2c15a32b6bd40e771dec0b8eccdcbffb9f49e5dbb7ef75d0c9e0fd123bccf48926869dd62"
    "5ee72edfb071bf3c6e1e43931adbeb9c8f52ffc466d730eefff3838710c7f73aef0f84c2c969b6c3c7b6ba8994bc11dfeef6453fc4f1cfebbb29e7301f61da39",
    "af7c1e1c9e53bc2b7725452dbd1ac78f61f1ccfaabc601d56c7ed546eef37ae4abbd7b309ef73aaf87b6928d963f9c69e792c18c922f08423f9e58a0780e3cbf"
    "6631fbdb3dc7e2373fc4e0f910fd1371fc84c853ac9044c7f31d9bedb19bbfef95788ec980eec673fef01fc8cbf43cff73599ee68f2526db89ef2b1b628f6e3c",
    "ecb10bf47e2d788ea7b7dfec7761c7c6f3b3cf5953f7a0ca8c57c7f3692c9e596f6f7fae612537cf6188dc7e17f22d3dcfe727fb1939c51d5752818654e2faed"
    "dcb6705a58a0f7a2009f4f6fbfd9efde85fd56bac07e2b73bb2df80fecb79a231eecb772a67e88eb98c5ec6f6fc1faac4d3c589f9d179e26cb8207ebb3ced40f",
    "7c6f16b3bfad3816c7ff0106cf87e8a7e7611aabb5d737ceb73b3fdc9d8167e89dcac3347cc63d7f197df1cf7fc3baed4de57babfbaf367a3b257f25988b4a99"
    "6052a86e17c342314c00df2f1bdf7f84a9cfaa9ddec6e0f910fdb4f3d7cc070b65843c47d519fdfb37651d776413ffbd19f886de91f39aa61ad4ed733a47b517",
    "da301fb8a9fd83d5f98048edb46b14b515a7831b6db91a60b2079de102cd074698fbe1b936cba2cf130c7cb7f76bc13cc1693c4d96050fe609f6eaff3fbc5b14"
    "03", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70576U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF4_info.c) */
