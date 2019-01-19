/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_vdF_info.c
 *
 * Code generation for function '_coder_fj_vdF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vdF.h"
#include "_coder_fj_vdF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_vdF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_vdF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.32935185183));
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
  const char * data[18] = {
    "789ced5dcf6fdb541cf7c6366d87810fc03421011b68429a54276ddaae8843933449d32ebfd31feb18991ddb8957db2fb19d34e9851c3970e1c289c38e80041a"
    "1c601208e59f1807b84c48dcb8c219278ed3fac96f4967c7a9d3f795aad7b7affd3ecfdf7ddfe77dfd7dcfafc4b964ea1c4110afea3f3f7d4a10e497445fae1a",
    "05410ecaf3845560fdb941791daa9b7291b860b9efdc00efab41bd0c648d6b69464514642edd90184ed12b322d71c366582009322d6bc5768d23144e05629363"
    "fb1a5e10b9a2207177c1b1cabaa057a4f831d5b0d253f57e8f56b9f27ea121114a553deaae78bc420cecd3932788e7bf30a67dd208fb9090fe7eec0155051247",
    "556956a052b144586dcb656abd570b3734504c15d7da3215052c77bc1ee1349a6a06e70254b9a7e11f959a6c7c4e3aeaff4344ff2e8dd97fb834e50a71f958ed"
    "a3d55178e3daeb15041e39d0d08cf11fe516de25a87e84676858d06044ee08ef6b877861249e557f3f797757778986aa502228d322950a17ef8623547e3e10bc",
    "c3501a0022035a14278994283094446b22cd509cc837644ab751cf05fae29d1f74bb5bb79e85bdf53baffd7c7a782d447be3fadd9b083c12d2d71986e5433526"
    "53cc16941c082612e2dd50e4a81fd91138a3fa4120ea5eb58fc7af55acfef6ee90c73b88f6c6b5d33b083c12d2f7a62d654ed0830145a6c539418d3404514bca",
    "7a38c02942796a3cffd4215e1e8967d59fc04f7a3fb7fbf6a26e9b06a36083998ee39ddf747efef70fccfb7ee7fd4cb31e0df3ebcd3bc55ca85d8e49f27c7c4f"
    "5cc7bc7f36783fe01aefa3de0749480ff1beaa9b8a56e6cce8de797c0f0baa3fa6b8f5be971a8167ea9df2fe6dc362439ff130ceffe2cf0f31dffb9def1f2d26",
    "721536b79d5c89a7832bdb4c6eb1c267a398efcf1adf7f86686f5c3bdd44e091901ee27bba5613db853e85c51b725913806c5c67f6abe6b05faf8de897a9e707"
    "e8a52a2db3fa0b805bf1ffd6087c53ef741eb031a4d7f3c15fff30bfe3f96042785ecd079bdbc17d103ae469f6e060273f1f4aadc4b7eec566673ec0e3d9be34",
    "c5ea7f8baecd0fef21f048480fcf0f4d20b06145a1db7191d6344e16e44affba69bd1738f59fed1178a6deb1ffd818cee3f5a0ce7f783ef0fd7c70b8b1be10dd"
    "aaed4a3926c38677f9f5544bcacc503e08cf07f6a52956ff5b9fb9fcd0cbae0be0fc907dff717ec81b3c9c1f72a77da7e318efeb31645c7b5d44e091034d0d1c",
    "f4777fe17d3d76f9425053a9be85a6902fec7cfe6c09c7f37ee7f39dea36b754c81516f3c55c63776d736f1b14b66688cffd3a7e5179ee71fded3c5437e50a74"
    "bd21b7568df226dee733f877bccfc7be3405eff3f1060feff371a77da771fd06a27d12d23b9e076ef0a26606bd84c77ed749adbae577d7107824a4b7cde7c42a",
    "becde34cc04f6c79df34d414f8fefb5b9fe0b8dfef7c1fc857824d6d63052895aa5a88d395483cd95cc37c7f76c63161e17bd4fbc6b8f6ba0ad509e83a532fa8"
    "b211a86abd2ff7fc9baf4f22f1acfa13c603bcd0e2d81ad0dd83b2586a1afbc1bedbb98ee37abff37c6261bf5da85704315a8ceee7eb914a717f2b8679feccf2",
    "3c0a6f5c7b5d86eac4f03a4323a8bca0bfd454fd9aaf5f43e259f54e78ddb090e10998cf6703cf299fbf81c023217db3cec56acdb2bab27bb00040562d0417ee"
    "ed11b3c3e77ec9bb1ef1f90d5e50548d17accff110d14f57fdaffbd0b57cfddb083c12d2ebc628e94628f1401101a89540935378111c94cabdf333a6b70fb3fb",
    "927866fb7b23f04cfd4b7ed761b8d10b2ce77d5cd0fdf5ef8b388f735ae78371e37b7533d68aad1d1e66375af3a1d47c209a0b070333b43fff39e2fe71edd841"
    "b44f42fac98deb1b2fbea054e5c41aa778eba709d7de072e407562789da1e945bbbd72caeb0a82cc72ada4ac0dfbf1d8613f5647f4c3d43b7b4f98933cf48ba7",
    "781dd7fff341a15d13a4c57a7e2728306c28b997cba682b394d77f8cb8ff0c8f5be2f877bb7ecfe38f9a4fca55babf328ef3f8f6a52938efe30d1ecee3bbd3fe"
    "73c4fd38ceb77fdef1fc34e95a9c3f2a0faf3fb844b7a6370f9cd2bcfff05c0ffd17cab091d779ffeed36b57709ec7effcafd403b547821a0a4b4bd96539cbec",
    "2e6c6eab3374fee673c4fd98ffed9f772c3fed78cbff828cf97f14ff0bb2e7fcff0be67ffff37f85beb79c59d849d79799b0165da433212e944bcc0effe3755f"
    "fbd2148bff3d7fe81aaf9f347fef14efa4fb791e3bc45b45e259f53ecaf7e13cfd04f1709ede9df67dc8e7879c02d486647d0e543e7d22dfe1763f5eed97ab0f",
    "3ce377be218abd12efd7b48bdbd51aadf44e64ed59c9ebb8bdf303cedbfb9fe7b5a57929bfb693a8ee2d80c3a69692e2a9a036433cff04713ffeaef6b8df1ded"
    "bf777a6ee607083c12d2db9dab1c11645a810e8d736bddd8e9b9ca5d87f8f747e09b7a57ceddb333e46065d7c3f9e1c76f149cd7f1fbfc90cb45b5fdeca3c032",
    "b397de4c3345fa4e26a5c667677ee822eec7e3da2a563f5c766dbec0e72c1b82cf599e185e5fce0a1e3e67d99df69d8ee722a27d12d23b7f6f303244255e04b4"
    "561abe4178fb9dd71e3e97c721deec7fe78dcfe599241e3e97c79df69df27e0ed13e09e99df3be0cb4349dce28497d6857ccb491c7e736ecb8b60e30ea9c6541",
    "956999f0ef3a40148967d53bdabfd3b391f7791ebcde3b413cafce6da8871b1929d4de0d05f2ca7c231ae4569a529a981d5ec7e3d72a567f7bdfb5731af0b9ca"
    "283cab1e9fab7c523c43ce0a1e3e57d99df6713c6f5f9a828ae73b88f6c6b5db5b083c12d2dbffbd2c5e04c0b0805ff33919249e55efd6dfcbea5b4c9f043ce4",
    "ff6ff1fe1ffff33f535dcaeecaa2c61680146bc8eb0b4c2cb23143fbf64f615ef6f4edffe9a45dcbdfbf8ec023213dc4fb9ca280b1d62d26f57dd6298bfb55bd"
    "7b1c4b196c3fe07c98fafb369b42dcffdbe63d9cc7f73befb7e4dcc161aa264512f5b5b87a27ba516f82c00ce4f1ff076d75c558",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 38440U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vdF_info.c) */
