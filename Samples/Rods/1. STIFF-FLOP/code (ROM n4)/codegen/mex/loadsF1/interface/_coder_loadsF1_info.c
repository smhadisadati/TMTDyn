/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_loadsF1_info.c
 *
 * Code generation for function '_coder_loadsF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "loadsF1.h"
#include "_coder_loadsF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("loadsF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.19486111111));
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
    "789ced5dcd6fe3c615e7a6d9208b22ad80b4d9f42bcda6c52245024b9664d95b3480be6dd9d6b7d6f67a93ca944449b4f92191942ce9521d7bc8217f400f39a6"
    "455b6c7bc922090af5d66b81a6879e0214412f456fedb9a228da1eae26a2cd11254aef018b11fdc4f98dde3efe66e6cd9b21752b91bc4551d43786fffef30b8a",
    "3a7959bda2a897284d5ce3f2390a15a3fed6b85c335ceb729b7a1eb9efd618ef57e3ebb228284c47d12e385660522dbec448c30b81e6998b6a2a22cf0ab4a014"
    "ba0d86921859e4da4c65a4a9b21c536079665fbc72b1c30e2ff8f815d5c585aa523f47ea4cf92cdfe229a92e5f3697bb7a418deda3ca13ccef7fdea47dd218fb",
    "b80cfac7b1f7dc759167dc75bac2ba93b1ed90dc15caee1df52ad452c442b210ed0aee885861ae5e87198576b7d7d73ceeb2aae144ba22c7d7d7f88bf6ff12d3"
    "be174cb6ff36a6fd77c6e59b57ffd8df0e6a1fc6653f3ebefed9b87c27a8b7eb04836bd6aeb876b9c69a86783ef22652782f18ae2ff1344d456c9538e612ef23",
    "8b78212c1eaa7f9cd83f1aba4e4b9686fff9659a73274385fd50d89df37ad6b74a6e4514b992d871333ce7e6d8929ba7158e2eb9c586ec1e5968e8299a4cb393"
    "597f3196badca15e1c7feabfff79e0ef21fbf0345915bc0ea63eb37ef70a06cf65d01fd60f98403e9bdfc815b2ada3e8def181987f18b96c47660aceb4765098",
    "6bbbea77eaf3dbc0b4cbacbf3d67b8d645e77b17f2d7fb41ad7ce382d7fb98facddaed87187c9741af7677d21a3b1c444802cdadb172b8c5724a42180e231889"
    "2dcf8df79f5ac4cb61f150fd35fc46fdf7d6c85eeeb77483b98d06d31dc9c67ee0e3fffee373e807668467573f906e3723a1ea4e7bab90f577cb315ef0c68fb9",
    "9de5e907ac8eff7731f5bb0c7acbfdc0bd2aa7e8835eca66bfeb2783a4fcee2e06cf65d01bf85f1e9a8c9662b5b9f1fe02fac944ded70d3507befffdfd9fc3b8"
    "dfe97cefc9d5d6dbcaee0351aad5e57c9cae85e3897614f87e759e630ae17bdc7cc3acbd5e325c5386efe97a5616b481aaa24602e717d7b1ea1f092c1eaabfe6",
    "78a0ca76984a431cba871bb1d41ce23bd4ef0ebf03e37aa7f3fcb6efac9b6fd6582e52889ce59ae15ae1ec610c787e65791e8767d65e2f1aaea98bef691a56ae"
    "b2c3494ddda9f1fa28160fd55be175cd429a27009f2f079e553eff3606cf65d0b79b4cacd12ecb0f8ece7da29891f3ebbe47c7d4f2f0b953e2ae977c7eafca4a",
    "b25265d1df7182692751ff1b9c108bd7bf86c17319f443631487462856458913c546516c33529513cf8b65753ddefa78de28b8f6e8a2e30d6e88a7d77f3c054f"
    "d7df2cbe3776a3afb09cfde382c1675fde8638cea2f60766c7f7f25eac138bf67a99dd8ed79ff47a22d9d0ba27b63cfdc11798fbcddab18fa9df65d0cfeeb9be",
    "f7d55f28d619aec148f6fae936b1f9c0f3866beae27b9a461dedaae59cd71558a1c274128272d18e0f2db62338a51dbadeda3c618db7d12f9ec23aaef3fb837c"
    "b7c1f21bcddce13a5baaf813c7d94c727d99e2fa1f62ee5fe1e776289ea589e34feb4fca757ab4320e71fcc9a52e10f7b1070fe2f864eaff02733f8cf327ff5e",
    "737e9a2036ce9f16871ffe709eeeccaf1f58d0b8bfee3fdcf0835bb391dd71ffc1d3bb7720cee374fe979a9ec6292bfb437c20b329644a47bebd03390cfc0ffc"
    "8f0abaee6b2fffb302f0ff34fe6705dbf9ff53e07fe7f37f8d7eb499f61da69a9ba59012d9a0d37ec69fdd5e1efe8775dfc9a52e88ff7d71428cd7af1bbfb78a",
    "77dd7c9e0f2de205b178a8de41f13e88d3cf100fe2f464ea77209ff71849945b3cfa3b70f1f499ecc31dbc1b1c95c1f76ce3f76a8be3d412f235278ddbe5062d"
    "555b825bb592dde3f6fe1f206eef7c9e57025e3e173ddcae1ffbc45e5b49f2f1e4bab2443cff04733fecabbdea7797f9f7b8737cccdaeb4dc33565f89eae37e4",
    "bfd08d06d70db3022d75f3a31e2fde12ca0a2b0aa4d68dbf39a55dbabe3ac62dd669a132ec0848e56f3e9e82afebad8e17b0861cafecdad83ffcf1d712c4759c"
    "de3f64b311e52c73ead92c1da7f652a502bd954ecaf1e5e91f0698fbe1b94605f5c34d62fdc58f30782e83ded85fb445b6129224ba1be76845610456a88dbe37",
    "affc7eabf3c9832978badeb21f4d309cea4236fa4fff7f25e8179cde2ff476777c91878d233e5b4a574247d59d64874f2fd1793c569fe702a67e97416f7ddea0"
    "45888a554ea495e2c50cc2de7d5ec7702e8f45bce5dfe70de7f2cc120fcee52153bf55decf62ea7719f4d6795f1095149d4a4b89e1a35dd3c346369fdb70486c",
    "1d60da39cbac2cd002e5dc758008160fd55bcadf516d647f9c07d67b678867d7b90dcd502bcdfbbb477e4f4ef2b622ebcc83369fa29687d7e1f94505f5b71f13"
    "3ba701ce55c6e1a17a3857f9ba789aac0a1e9cab4ca67e18cf4f2e75c18de7fb98faccdaed7b183c97413f318eb356e54451b38053e339a6dfc763b11f784bb3",
    "987b64b12befe339c1b48f20ffff06f27f9ccfffa57a207324704a252ff2b196b0e32bc5c2bb4b94b7bf8071d9c5cbffe9a788c5efbf85c17319f406de672449"
    "34b56e31abfd590b36ee9787cd632a6e8dedc79c6fa4fe91cde630eeffd3de2388e33b9df73b42f6bc976cf0e1ed66342e6f45769b6dd1b344717cdbc66f337a",
    "9f6203d3bed9bc5f2b111c15fd1ddbf2fae5a6347a29a753e3f9612c1eaabf693c50cdea576d643fbf07fffcf03e8ceb9dceeffeed58b5ee09244ed3315f42c9"
    "6405a11d892e515c079e5f54507fbb4f2c8ef37d0c9ecba07f269e1f15799a1562c6713dae5fb32b8fdf29711dc480f6c6753ef937e4673a9effb9245fe1cf24",
    "26d9881c2a5b62ab527dd46297e83c1e788e27b71ff5bb00b1f1fcf4f7aaa87b5165c6a9e3f91d2c1eaab7b64f57b7929de731045f7c07f22e1dcfe7e7870939"
    "ce9d1dc4bd5529cfb54fd3bb422f1b013e5f2d3e7f07f65d8d05f65da1ed36e13fb0ef6a8678b0ef8a4cfd10d74105f5b737619dd6221eacd3ce0a4f9355c183",
    "755a32f503dfa382fadb1ab138fe7731782e837e723ea6be5a3bbf71bed5f9616a0a9eae27958fa9fb8c7dfe32f8f89fff8275db45e57bb3fbb0b65afb79cf81"
    "2f1d9212be9870b49b0b08b900057cbf6a7cff01a63eb376fa0906cf65d04f3a870d3d6028216438bacc8cbfbf28ebb8038bf8ef4ec1d7f544ce6d9a6850dbcf",
    "d92f7dfd14e6038bda3f989d0f88f4fe6989a6b72315dfd6a97ce46592c78dee12cd070698fbe1b94605f5c3b7619dd7241eacf392c2d36455f0609d974cfd03"
    "ccfdc0efa82c7b1ce8a6fc0f71a0c9ed8738903d7810072253bfd5e778defbb34e30ed237bae668e18efbf8ec17319f406de9718b94e37983cdb6322ea5b2265",
    "a7e6f9e4a7e0e97aabbcff8cc1ec3f8fedafbffd08e6018bcaff66e701816d0fb799d9cc660e760ee483c3406d2fd75ca6f7b2c0f33cb9d405f5bfd789e5fdbc"
    "8ac17319f4867e40a0a51a2b94eb674ee57fc2799e66f27e2e6c66eff8bffff24f737f03fe9f119e5dfcdfed9c271ed0f16a6dc3534ec7c4fc69bcb5791e03fe",
    "5fb4e719e70f66fdef6b98dfa19fd3f02af2d7b7835af9c6b8bcdce77b82c12175feb27e229b53e3feb33ebf75f416c6f1196caad8c84f705ec30cf1ece2fbad"
    "e666bad0e4a21b67e17a21bb9d579ad1687989deb305cf2f2ab8f17d1f531f9cbf6c0e0fce5f9e159e26ab8207e72f93a91f781f95599dbbbf28e72d1bc56c7c",
    "e7c90df1f4fae1bc65d2789aac0a1e9cb74ca67ee07b54707cff01a63ec8efd76460117ff5f2c420bf7f967890df4fa6fe01e67e78ae519955fee7a2cc136e1a"
    "1f8279c2e4f6c33cc11e3c982790a91ff27f2697baa0fee7b9e07fabe7beddc3e0b90c7ae3bc4196194939a039b6a29a2224d5c6df73ea3a41018b87ea2d8f23",
    "9e319cedf382e722e7302f707a7fe0f59ef51e44e3e1446dbf933feeed94761ee414c8075ac1e77928fd20ecf7358907fb7d49e169b22a78b0df974cfdc0eb93"
    "4b5d505e0f411ed0f8ef900734b9d405f280ecc1833c2032f50f30f79bb5631153bfcba09f453f708f95557d4da2399bf7ff3eb22dbf5ffd89550af2fb717903",
    "c30fee918decdfcffb14f8ddf9fcbed14972f1b376e5341138eaec5624af5fc80720bf7f059e5f55c8e579c2b81e8787ea615c7f5d3c4d56050fc6f564ea1f60"
    "ee77ccb8be24b6848a6cf3b83e4bac3ff80106cf65d03fd31f24d4190d2345b8a1652872e3feebbecfe58945bc8ce19a327c4fd75bef0fae1accd638fffbafdc",
    "8138bfd3fb81b8b09f09870e533d96efa44f1b153eada4ba4b14e71f60ee877e0015b41f78482cbe336d1c3e34004f77e6c7f356e787512c1eaab7343f1cd9c8"
    "f6fc9ca77781df1dcfef52d3d33865657f880f6436854ce9c8b777202fd1fbd60798fb81df5141fdf0c0567e6705e0f769fcce0ab6f3fba7c0efcee7f71afd68",
    "33ed3b4c35374b2125b241a7fd8c3f0bf9f817f5ad549e0eb503bc6e120f789d149e26ab8207bc4ea67ee0f5c9a52e68fe650ae23126f1201e430a4f9355c183"
    "780c99faff82b9dfac1d694cfd2e837e06fb67efb56969749472b1218915c3ef3ac1b49b2ccf9789adbfbe86c17319f443e31487462956458913c546516c3352",
    "9513cf8b65d52af33b776d70433cbdfee32978bafe86fd80e6565f6139fbf372069f7d791bfa07a7f70ff25eac138bf67a99dd8ed79ff47a22d9d0ba6709f6d3"
    "fe1f1fa80fff", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70520U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
