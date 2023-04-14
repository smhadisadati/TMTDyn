/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF2_info.c
 *
 * Code generation for function '_coder_massF2_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF2.h"
#include "_coder_massF2_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.88285879628));
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
  const char * data[28] = {
    "789ced5dcd6fe3c615e7a6bbc12e8a3404d26613144d77d3629162034b9665c9dba280be2dd9d697a5f5d7269529899268f34322a9cf4b7dec21879c7aea618f"
    "49d116db5eba408242bdf55aa0e9a1a7bde44f68cfa5448d6d72352bae495126f51e608cc68f9cdfe861f89b99378f4fc48d54fa064110df53fedefe35413c7f",
    "67542388b70855c849f906a115bdfec6a45cd1d591dc226e6aeebb31c1fbdda45e117899eec96a8565783ad3e6cab4a854788aa3cf9ba90a1cc353bc5cec3769"
    "42a42581edd0d5b1a6c6b07491e1e81de15225c928152e7149755e19a9469fa30dba725a687384d8902ebacb5eae1013fb8ce419e6fbdf34689f0cc63ea44eff",
    "24fea9a72170b4a74155194f3abe1996fa7cc5931cd5c26d5928a68bb13eef890a55fa723d42cb94a7b3bae2f554461a8e92a4846f85bbe8ff6f30fd7bd360ff"
    "6f61fa7f67527e74f99ff798d0b83c3e564b0295fe49b91e42fd3ac6e01ab52bae5fe444d314bae3d16415de9bbafa059eaaa90aed324b5fe07d61122f8cc5d3",
    "ea9fa4760e94a1d396440f2b5428d6930e1777c211cfaecfbbba51f6c882c096859e87e6580fcb94950122b354d9233425cfd842a3a132965976323a5ef42592"
    "3bc4edc9a7b3cfbe09fc3b6c1f9e2acb82d7c3b46774dcbd8bc12375fafdc61e1d28e40bebbbc57cfb20b67db427141e472ffa919b8133ab1f04a66e57fb4e7d",
    "7e9b987e191d6f6fe8ea4810df939aff3e08a9e587e7bc7e8669dfa8dd7e8cc12775fad17427ae30ca2242e429768591226d869553bcb28ca045a6b230de7f6e"
    "126f178ba7d5bfc6b819fd3d1cdbcbf31019cca337181a4836ce037ffdef7fbe8179604e7876cd03d94e2b1aae253b1bc5bcbf5f8973bc2f71c426dd330f985d",
    "ff6f61da27757ad3f3c0fd1a2ba3452f61f3b83b4b87ac1a77773178a44eafe37f49311925c6eb0be3fd6b384ea6f23e32d402f8fe4f0f7e05eb7ea7f3bd77b7"
    "beda91b71e0962bd211512543d92487562c0f7cbf31c131abec7ed378cdaeb2d5d9dd05d87f48cc4ab0b5579e4095c9c5fc7ecf84861f1b4fad75c0fd4981e5d",
    "6d0acaf0f0682cb500ff0ef1c7fdf7615def749edf5c3bed175a75868d16a3a7bbad48bd78fa380e3cbfb43c8fc3336aafdbba3a717e9daa61a41aa36c6a1a4e"
    "f5d7c7b0785abd195e572da48e04e07377e099e5f31f60f0489dbed3a2e3cd4e457a74d05d13849c54585d3b3c22dcc3e74ef1bb5ef0f9fd1a234a728dd17e8f",
    "634c3f2d1d7fc363cbfcf51f60f0489d5e3146493142a92688ac20344b4287166bacd02d5546e7f1e6d7f37ac1f50709c21b5e110fb57f34030fe9afe6df9b0c"
    "a35758cefe75c1f0eb6f6f811fe7bace0746d7f7d276bc178f0d06b9ad9ecf9ff679a3f9f0aa37ee9ef9e005e67ea3763cc3b44feaf4f37baeefbffa82528366",
    "9bb468ef38ddb46c3f70535727ceaf5335a3d5eea85cf0b902c357e95e8a97cffbf1d4643f4233fa81f4e6f6092b9c8de3e2399ce33a7f3e28f49b0cb7dedadd"
    "5f65ca557fea289f4bafbac9afff1473ff123fb78a785de3c79f359f541ad4f8641cfcf8d34b24e0f7b1070ffcf8d6b4ff02733facf3a77f5f63e33465d93a7f",
    "961f5ef9e21cd55bdc3c704dfdfe68fcb0ca078f6a23bbfdfec3e777ef809fc7e9fc2fb6bccd1346f287b9402ec8e7ca076bdb7b5204f81ff85f2bda735f7bf9"
    "9fe181ff67f13fc3dbceff5f01ff3b9fffebd46130bbb69f6905cb6139ba4e65fdb43fbfe91efe8773dfe92512cdf87b716c19afbfaeffde2cdeebc6f33c3589",
    "17c2e269f50ef2f7819f7e8e78e0a7b7a67d07f2f9801605a9cd69bf07ce9f3e97f770879f84c665e853dbf8bdd666d95109f19ad3d6ed5293126b6dde33b292"
    "ddebf6b33f83dfdef93c2f077cdc6e6c7fb371b4260c3a729a4ba4576517f1fc33ccfdf05eede57177117f8fcbe363d45e1fe9ea84ee3aa4d7c5bf50cd26db8f",
    "303c25f60be3192fd1e62b3223f0569d1bbf3da35f485f9be0961a145f552602abe2379fccc0477ab3eb05ac212727bb36ce0f7ff95204bf8ed3e7877c3e2a9f"
    "e64ebcc1f251663b532e521bd9b49470cffc30c4dc0fcfb556b4e33068d97cf1130c1ea9d3ebe78b8ec054c3a248f5132c25cb34cff0f5f1758b8aef37bb9fdc",
    "9b8187f4a6c7d114c35dcee3778ce9a785e3e7ec7f6598179c3e2f0cb6926bd1c7cd032e5fce56c307b564bac7655d948fc7ecf35cc4b44feaf4e6f70daa87a8"
    "5463054a2e9def20ec7dcfeb08f2f298c473ff7bde9097679e789097c79af6cdf27e1ed33ea9d39be77d5e903354262ba69447bb8edc4636e76dd8b7ec1c6056",
    "9e6546e2299e70ee3940148ba7d59b8adf19d9c87e3f0f9cf7ce11cfaebc0dad703bcbf9fb077eefaee86b4757e9471d2e43b887d7e1f9d58a76bcfdd4b23c0d"
    "90571987a7d5435ee5d7c5536559f020afb235edc37a7e7a8904b79e3fc3b467d46e3fc4e0913afd543fce4a8d1504d5024ef5e764b1785abdd979e0a16a31cf",
    "d862ca246023ffff1ee27f9ccfffe5462077c0b372b52070f1369f5c2bc7235b2e8adbbf867ed9eb17ff7396b1cc7fff7d0c1ea9d3eb789f1645c1d0b9c5bcde"
    "cfba66eb7e49e91e5df5a86c3fe17c3df58f6db68075ffdfb60fc18fef74deeff1f9ee20dde4229bad5842da886eb53a82d7457e7cb3bc9fc1b44feaf4f3fa3d",
    "45dc38303aeebe83e93f8aeb7feff23fd1ef2912bf50cbd0ae65fb807b987e903abd6e3e106985019b748119a83fa4293935aea730030fe9cdee035e3298fde7"
    "00fffcc317302f387d5e086c7ad9602e98cfed25f7a4bdfd407d7bb7e5a6f701e0799e5e22d18ebf7b96ed0bded3d509dd7548af9b07784aac337ca571ea54fe",
    "b738aed3c8bee0dc66f6c6759ebdf3f3dd7f01ffcf09cf2efeeff7baa94754a2565ff756b271a170926807bb2ecad7ec96e7d9d6fd01f171482d3f9c940f6c8b"
    "fb41270110f7333d6e60fcf6efc4f73f121bf9e9ef8f1f80ffdfe97cbfd10a668b2d36b67e1a6914f39b05b9158b555cf47e173cbf5ac1adefcf30ed41dc8f31",
    "3c88fb99179e2acb8207713fd6b40fbcaf9579c57b5e97381fbd18f5ef3cbb221e6a1fe27cacc6536559f020cec79af681efb582e3fbcf31ed19b5d3cf3078a4"
    "4e3f2dbf8f3671458acfb154859e5c8ffad734d9bf45e7f9f964063ed25b920f64aa416dcfdf5cfeee099cfb3a7d7e10a89d9332456d46ab6b1b27d2818f4e1f",
    "35fb2e3af71d62ee87e75a2bda71f8b1657efed9bfcb3eca6529d14ef5f327b1785abdb93c9fc84a76e6730eddfe25e46d703cbf77f75352823ddd4bf86a6281"
    "ed9c64b7f8413e0afcbedcfcbee23a3fd055f91ffc40d3fb0f7e207bf0c00f644dfb10df39bd4482fb5d5eb3793cef63f0489d5eef1792245a94f72896a98e4c",
    "1116eb93eb9c7a0e3c87bc7fd3d7112f19ce76bfcf1bd12eec0b9c3e1ff87ca78347b1442455dfe9158e06c972f2d1ae0cf19e4bf83c2b7216027f8f413cf0f7"
    "5885a7cab2e081bfc79af681d7a79748b4bc1e8638cfc9ff21ce737a8904e23cedc183384f6bda1f62ee376ac712a67d52a79fc73c709f9146faba48b1f68ec3",
    "e1a16def6f8dbe628d80f7b75e9df755b111e46d76159e5dfcbede4bb389d34ef5241538e86d55459f9f2f04e0fdad25787e4702799b615dafed37aceb178b07"
    "eb7a6bda1f62ee77ccbabe2cb4f9aa64f3ba3e6fd97cf0230c1ea9d3bf341f4cd2574759c532c4e2f2793e338997d3d509dd75486f7e3eb86c305bfdfc9fbd7b",
    "07fcfc4e9f0712fc4e2e12decf0c18ae973d6956b9ac9ce9bbc8cf3fc4dc0ff38056b4f3c063cbfc3bb3d6e18a0138aab7389e37bb3f8c61f1b47a53fbc3b18d"
    "6c8fcf797e17f8ddf1fc2eb6bccd1346f287b9402ec8e7ca076bdb7b5204f87da9f99dd8b395df191ef87d16bf33bcedfcfe15f0bbf3f9bd4e1d06b36bfb9956",
    "b01c96a3eb54d64ffbf3108f7fdede52c5e91049e0758378c0eb56e1a9b22c78c0ebd6b40fbc3ebd4482fb7d2d1c1ef86354017f8c5578aa2c0b1ef863ac69ff"
    "1f98fb8dda91c2b44feaf473787ff67e8712c7a9f24b4d51a8eabed731a6dfd6f27cc5b2f3d70f3078a44eaf18a7a418a554134456109a25a1438b3556e8962a",
    "23ab2c2eafe6f08a78a8fda31978487fc579401d56afb09cfd7139c3afbfbd05f383d3e707693bde8bc70683dc56cfe74ffbbcd17c78d5eba2f7699f61ee87df"
    "555445f3bb2967e190fa21a49616be5f8beb0739d15404695c3a35ee3e8cc5d3eacde463556c8468de4e5e82df4d99239e5d3cdf2cf64e825939170866a962e1",
    "a4286ef62bbc8bf601f0fc6a655e71f7ef63f0489d7e7ade34c4f28b5be79b5d0fa467e021bd5579d3d098b131ce32f0db2f81ef9dcef71be28e44e52be9c3fd"
    "f2e141391209f86b751af87ee9f8fe734c7b903f5f95a149fce5cbc30af9f3e78907f9f3ad697f88b91f9e6badcc2bbff275d9275cd51f04fb84e9fd877d823d",
    "78b04fb0a67df0ff4fefff74ff7f24a47e40e70011dbfcffd228b89300ffffabf693120aee246ce579f0ffcf11cf2e9ea7a864e4a87b9a64f6d2d1361b89f0b1"
    "602ee3a2f53e3cbf5ab99efe7fc4f2e0ff37baae4763c646ff4e08d6f5cee77bef7a32b011edeefbbc916e97f536597fac3e70d1ba1ef85e2be0ff9fde3ff0ff",
    "ab02fe7f67e081ffdf9af68798fbe1b9d6caf5f4ff5bb74f5816ff3fec13dc8507fb0473edff1f0f2309a1",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70608U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
