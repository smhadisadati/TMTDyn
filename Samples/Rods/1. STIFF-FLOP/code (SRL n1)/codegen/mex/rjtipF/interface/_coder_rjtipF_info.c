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
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.882962963));
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
    "789ced5dcd6fe3c615e726d96217411a0269f381a269362d160d1258b22c4b768100fab6645b5f96569295a45a4aa224cafc12497d5eaa630f39e4d4530f3926"
    "455b6c7be902090ae5d66b81a6879ef6923fa13d5714457bc968565a93a24cea3d6031e63e727ea38799dfbc79f338c46e2592b7300cfbe1f4dfabbfc1b0c16b",
    "f21586bd822982cfcb1730ade8f5b7e6e58eee5a95dbd84b9ae76ecdf17e3fbfae71ac440e24e582a65832d565aaa430bd600986bcaca6ce31144bb0527ec893"
    "98408a1cdd23eb334d83a2c93cc590a7dc5317716a7ac1c49e525d5ec82af9ef708bac5de4ba0c26b4c4abe6d24f5f6073fbc8f208f1fb5f5ad13e29847d709d",
    "fea3e827ae16c790ae1651a75cc9e851501cb235575cbe0a76252e9fcc4786ac2bccd5c9a7af43a444b87abb3b6e574dd6086d89e2633bcc55fb0788f6fd60c5"
    "f6bf8868ffdd79f9a6e67f7d01a5f4cecbfd80da8e87089c55ed886a073ed788143b2bcdc2fb81eefa0a4fd1d4b96e9526aff0be30881744e269f51f254e4bd3",
    "aed2150517cdd508da950ce64f8321d799c7bd7b5075491c4757b9818b6468174d555d0c21d144d545d28d2eeb9ada48ee1a335966a755fb87be54e52e7667fe"
    "57e09b07f7bf0d5a87a7c8b6e0a1c6f7aafdee75041eaed313443c54ee5fc4a94232dca5432136e2cfa42257edc82cc159d60e0c716d55fd307eb5a2ed6fbfb8",
    "e4f131a2be55edf416020fd7e9e5e94cd8a1a64e82c012f48e38351521eca82c6f9ce7f5826a8f2a66f903c92578aafe39fa89fceffd99bd5cefab0673bdaf58"
    "ecb2cf58d75f2681df7d097c6f77be77efc77d07e17ed1e30ef5fbb49ba7bd91e628047cbf6d7cff19a2be55edf41e020fd7e9757c4ff03c3dcccd282cd6656b",
    "12c5b109364313357569a8b68f37d8be5797b44fd537e6ada8b408b63e75fc55fc8941fc8f97e0ab7aa3f301daa04a17b3707ea8bedcfe37cc0f6bc2b36a7ee0"
    "88d37695208ec2f5bd83b658f290c9323f74d07a6082781ec6b556b4fdf003d3e23d7774d7d8e57d8a8612459e1044d2aef19e38124fabbf9eff20db46f62054",
    "2bed3016c67bee7cf86be077bbf37bbf981063f44521e6690839bad74e1fb3a36c18f87dbbf97dc77171a0ebf23fc48116b71fe240d6e0411cc89cfa8d8ee3ed"
    "dadf3d0c28a57f5e1e58b6bf5be3940d7abbfafb56c40ba736da44bc10f677d7886715cff3f941db9f96323e7f9ac8e7da79e16858631dc4f3307eb57233f777",
    "559687fddd55fd7ab5cf5818dff1815f6f7fbe3f104e45225b4b9e17abe7a56a28e4f3369a24f0fdd6f1fd6788fa607f57918941fced8b13c2feee3af1607fd7"
    "9cfa2788e7615c6be566c6ffcd5b276c4bfc1fd609cec283758239f5db3dfeff10d13e53fbdd386c5a9cff36020f9f6b78ae3f7b0b10e2fc8bd68d1c2fba6616",
    "dac0ba71fce9b73ef0ebedcee7c55681f4e5b2b9fdb37cb65b8a9c940b5cee8183f27aec3a7e51718e55fbdb0bba6b55d47d5c6dbcfb7e4029df35cd9fff1902"
    "1fd7e975fe3c2586ba142d25d854972105aab631de7f6c10ef0c89a7d51bf5e7f506533b9285f3c0dffefb1ff0ebed3e0fa47b9d70b011ef1de4b3de612dcab0",
    "9e58998e3b671e30ead71f23eac7757ac3f3c0bd062da94e2f66b55f9f0c98d5efde40e0e13afdc2784eb469db38ce1afac942de570db501befff37dc8e7b73d"
    "dfbbcf9abb3de9f890139a2d3117239aa158a2e7a0783e8ce3c5ed47f13d6abdb1aabd5ed15d63bafb543d25b28aa32ac92738d9375e9f40e269f5cfe90f34a8",
    "0159e7b969f770692cb589bc803f15df02bfdeee3c7fb47731cc759a141dce872fce3aa166fee24114787e6b791e8567de7bb80d6abaa869d9355e1f41e269f5"
    "46785db190e5fbf5c0e76bc433cae73f46e0e13a7daf4346f95e4d3c2cf5f7382e23e676f7cecb9873f8dc2e71d72b3ebfd7a004516a50dadff110d14e53fbdf",
    "e4a169f1fab71178b84e3f3546656a844a8313688ee32b5c8f141a34d7afd4e473543797a73fb9269e5a7f79099eaabf667eafd28d9e6139ebfd82c9d7dfdd86"
    "38ce4d9d0f56f5efc593e8201a198d32c7038f37e97187b3c15d77d439f3c113c4f3abda718ca81fd7e9d737aeef3dfb864a8ba47952b0b69f1e99b61e784977",
    "8d5ddea768646f572e37bcaf40b175729060a5cb767c6eb01d8125ed50f5c6d609569ed3833d867d5cfbcf07b9214f31fb9db3e22e55ad7b13e56c26b9eba4b8"
    "fee788e7b778dc4ec5ed9838feb2f9a4d622663be310c75f5caa02711f6bf0208e6f4efd4f10cf839fbff8f7aed64f13a6f9f9cbe2f0d31fce1083cdcd033734",
    "ee7ff97ef7f40f976223cbdfbf7dfcc65d88f3d89dff858e9b6f53a237c8f8327e36532ded9d144407bd77f504f13cf0ffe2dfbb523f1d5bcbfff2219cc0ffcf"
    "e67ff5130e16f2ff57c0fff6e7ff2671ee4fef15531d7f352885f789b497f4668f9cc3ffb0efbbb85445d3ff9e3c348dd79f377e6f14ef79f3793e37881740e2",
    "69f5368af7419c7e8d7810a737a77e1bf2f9881438b1cb687f072a9ebe96f770271f076665e013cbf8bdd1a569b9847ccd677d3745b692d57efbf82f10b7b73f"
    "cf4b3e0f7316291eb5ca7bdca82725995872577210cf3f423c0fefd53eddefaef2ef7f8ba86f557bfd128187ebf48bced70c512c21e80e8f336bdf78d3e76a7e",
    "b4045fd59b72fede2243ce77762d9c1ffefaa500711dbbcf0fd96c58bac8b4ddfe6a397592aae6898374528c39677e98209e8771ad156d3ff49b365ffc1c8187"
    "ebf4faf9a2c751f5a02010c3184d4812c9526c7376dfa6f2fb8dae270b4bf054bde17eb4c070169fcf37fe5f15e605bbcf0ba3e3f85ef8015f62b2d5743d586a",
    "c4930326eda0f3788c8ee73ca27e5ca737be6e5022449506cd1152e5720561ed7b5e653897c7209ef3dff3867379d68907e7f29853bf51decf22eac7757ae3bc"
    "cf72528a48a585c4746837d5b091c5e736144ddb075876ce3225b2048bd9771f208cc4d3ea0de5efc836b23ece03fbbd6bc4b3eadc864eb09b66bcc392d77d26",
    "78bae15df2b0c7a430e7f03a8c5fadaceb7b8a70ae320a4fab8773959f174f916dc1837395cda91ffcf9c5a52a287f7e8ca86f55bbfd048187ebf48bbf97d5a0"
    "394eb1805de33969249e566fd6f7b266169b4e0216f2ff1f20ffc7fefc5f6df932259696ea398e8976d9f85e351a3a7650defe0d8ccbdebcfc9f71cab4f8fd8f",
    "1078b84eafe37d5210b895f62dd6f57ed60df3fbc569f3c8ba4b61fb39e7eba97f66b30df8fd7f3f398738bedd797fc066fba324cf848e3a919878103eeef438"
    "b783e2f846793f85a81fd7e99df29dc431a2be55edf50e020fd7e975bc2f9053a6e3c91c3522c3f25bc8a25df377724bf054bd517fff7b06b33edeffcf3f7e01",
    "fc6f77fef71db9697fc69fcd14e205b150f4354fce3a4ecafb87f1bcb85445dbffde31cdff7f138187ebf4ba7980258426c5d65a1776e57f93f33757f1ff2f6d"
    "66addf307eed5767ff02fe5f139e55fc3f1cf4138744acd1dc77d7d2512ed78e75fd7d079dcbec94f18cea0fabf6bf1711bf437dbff74dcdff7e1050ca77e7e5",
    "7dcbf27bd4883fe4f72cce0f98bde53b8ff1cb62213f7df3e03ec4f9edcef7071d7f3adfa123fb17a1563e7b94933a9148cd41ef71c1f8d50acabf1f23ea83fc"
    "9ed5f020bf675d788a6c0b1ee4f798533ff0be56d695d77953f279f4b26a7ce7d135f1d4fa219fc76c3c45b6050ff279cca91ff85e2b28beff0c51dfaa767a0f",
    "8187ebf48bcef1d11e50916033345123e7f7abede30db66fd3e7f97cbc045fd59b72eec742835a7e4e73f5e536ecfbda7d7ee088d37695208ec2f5bd83b658f2"
    "90c9323f74d0beef04f13c8c6bad68fbe18ee3d609d78d0fc13a6171fb619d600d1eac13cca91ff27f1697aaa0becf68f43cb77b083c5ca7d7af1b449114a402",
    "415375d91441a139bfcfaefb046b38ff69b11ff13dc359be2e7821dc877581dde7038fe7627418898512cdd341ae3c8a57e3876712e4036de1789eca38605ade"
    "cf1ddd3576799fa2a144f90c7b91b46bde4f1c89a7d51b3bdf5fb59295df7109dcf910ce6bb33daff78b0931465f14629e8690a37bedf4313bca8681d7b793d7",
    "83900734ff7fc8035a5caa027940d6e0411e9039f54f10cfaf6ac70aa27e5ca75fc73c708f12657d5320686bfbe1e4dcb2fc7ef9273630c8ef7ff6f97f531bc1"
    "f99d8ec2b38adff707493a76d1abb713bed2e0b82e78bc6cce07f9fd5b307e6581f33bc1afd7b61bfcfacde2815f6f4efd13c4f3b6f1ebab5c97ad8b16fbf559",
    "d3e6839f22f0709dfe7bf3c1fc18d3303db50cb6b973dd1e19c4cbe8ae31dd7daadef87cf0b4c12c8df37ffafa5d88f3db7d1e88b1a79950b0981a51cc20dde6"
    "eb4c5a4a0d1d14e79f209e8779402bda79e08169f19d657ef8d4000c31d81ccfdfecefb4cfd787331b599e9ff3f80de077dbf3bbd071f36d4af406195fc6cf66",
    "aaa5bd938218027edf6a7ec70a96f23bc502bf2fe3778ab59cdfbf027eb73fbf3789737f7aaf98eaf8ab4129bc4fa4bda4370bf9f897f56d559e0e16075e5f11"
    "0f78dd2c3c45b6050f78dd9cfa81d71797aaa0beb382c283788c22108f310b4f916dc183788c39f5ff03f1fcaa762410f5e33afd1ade9fbdd72384d951ca155e",
    "e0eabadff510d16e7379be66dafeebdb083c5ca79f1aa732354aa5c10934c7f115ae470a0d9aeb576ab2553677eedae49a786afde52578aafe9af380d2ad9e61"
    "39ebf372265f7f771be607bbcf0fe24974108d8c4699e381c79bf4b8c3d9e0aedb01efd3fe1f09ef04d6",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70544U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
