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
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737560.594363426));
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
    "789ced5dcd6fe3c615e7a649b041904640da246dfab19b068b049b98fab0656f8114faa425af657daeadf526b129919228f343222959f2a53ee69043fe801ef6"
    "98066d91e692455b14caadd7024d0f3d2d5014bdf4da9e2b8aa22dce6a22ae49d1a6f41e608ca927ce6ff4f0f89b99376f86c4b574e61a4110df1dfe7df24b82",
    "78f88a7645102f11baf8c6e533845950fdb571b9825c1bf21cf1ace9be6b63bc5f8dafab92a8b23d55bfe03991dde90815561e5e88b4c09e55c3480227d2a25a"
    "eab75842661589efb2cc4853e378b6c409ecb6347191e286170235a13abbd054dafff1065b3d2a7604426e28e7cde5272f88b17d3419607effb316edf311c63e",
    "3e44ff20f921d99004966cd00c4716e91a4b66929b51a52f56c994f65129534af445322e31acf17f8c5569b21b58f193058951c8c0ca8d62294d51ef51dbd91c"
    "59d5be28d08a42055784f3dfd3c3b4f7798bbfe73b98dff3c2b87c7df2c3d35c44ffe7dd71f98b88d18e530c8e55bbdec0b4c387e83533c82bdcd0d96491e657",
    "862ed4a05b6c913bd11d4131da7378c1f6a0826b8f2106dea30be219f51767e019fa07e9edf2d0b53a8a4cf25295e6c94cb4b41d8d9185a03fb051215549e22b"
    "528f64057ef4777b642ff2b66130f2098369ce34f13b0e31edb4ea4f6869c80bc4f5f17fa77ffdcd677f8fba87a7cbb2e0e1f8c0aa1fbe8ac1f321faf0a69f5f",
    "cfade773bba95d65772f5cbf5b68ab89f376e466e0cc6a0781b976ab7e789ea7978698fdef46c429ff7b1db92690ef197aa41f1069b9ce89d5c69157f97f7706"
    "9ea1b7e82f43a7905986d4bd65ec33a8eb9cd96c723c718869a783fcffcacf0b7f03fe9f139e5bfcdfef1da7efd054adbee6af669352b14975d68f93c0ff57ed",
    "7976757e70362f78735cde8ad8e56303f7394c3b7c634d8d97246db6e914def3c8f5399eae61a44e8567cff13eb38917c7e299f54f315ee0b9ca70c2a8f27485"
    "64f95a47244736727f7cf0f5bd5bdf00dfcf09cf2dbedf68af674b6d3eb176146b94f29b45b59d4854a9c5e17b787ecd821bdf9f62eab36aa79f62f07c881e19",
    "df734aacc3f16a5adce908accc552f8de7ed8e0b0a583cb3deeebc1035d8d86ddc1ce77ff5df7f00ef7b9df7b3dd763c5a4b75374af9d57e352988416a9f4f01"
    "ef2f07efbfe518efbf81c1f3217a84f795a1a96879c518dddb1fdfa36235bef3c505f18cfab333f00cbd5ddebfad5beccc675ce4fbcff77e007cef75beaf34c2",
    "b9b2c8ab4c5112921d3115aa24635b9bc0f7cbc6f79f62eab36aa77730783e448ff03ddd6af1fde288c2a88e585539494c8b399eae1a290446fb5a36dbf7f28c"
    "f619fadab815070d5a64861301a7f2083e98816fe8edf6077883ea0ee69e7f0d2a2f3661ddd7ebfd83446f372b34bd1967421b4da51c6433fbadfe02adfb0e30",
    "f7c3736d16b31fbeeb589cff3a724d9c7d4fd7708ad2a26585f56a9c3f85c533eb2f367ed06ca38d200c2bad08eef941e4fafb1f01bf7b9ddf8ff7d20ac51fed"
    "52c19a5ce4bbcdec9678928f03bf2f37bfaf2c5c1ce8a2fc0f71a0e9ed8738903b78100772a67ec8ef9c5e1a62f63fff19ff7f8ca9cfaadd6e62f07c881e8d0b",
    "290a2babbb34cf319a29a2727dfc3dafae0397b07866bded71c41386733deef34cfc18e6055eef0f82c1a3933b092a96ae6ff78afb27a94aea4e41857ccf257c"
    "9e87721a81788f453c88f73885a7cbb2e041bcc799fa81d7a7978698793d0a799ee3cf21cf737a6908e479ba8307799eced43fc0dc6fd58e0798fa7d887e1efd",
    "c04d4ed1f47599e6ddf5c3c17dd7f66f693fb146c0fe2d5c5ed8f01f726423f7cf6b7804fcee7d7e5feb6578eaa8cb34d3e1726f8b9183ab62310cfbb796e0f9"
    "d5c4b93c7e18d7e3f0cc7a18d73f2d9e2ecb8207e37a67ea1f60eef7ccb8be2275444671795c9f77ac3ff83106cf87e89fe80fd2da8c8695e3fcd0328473e3fe",
    "6791ebf3f6e89a6a831e25103995cf9343ae09e47b86de7e7f30693057e3fc9fbcfa02c4f9bdde0f50e2762e16dddb39e1845eb6d96284acbad35fa038ff0073"
    "3ff4036631f703f71c8befcc1a870f0d20d0bdcbe379bbf3c30416cfacb7353f1cd9c8f5fc9c47af01bf7b9edfe5b6bfd5e494d5a810cead8bb94a3974775789",
    "01bf2f35bf13bbaef23b2702bfcfe2774e749ddfff08fcee7d7eafd3f7d7b3a1bd9df67a25aac6d7e8ec2abb9a877cfcb3fa962a4f874801af5bc4035e770a4f"
    "9765c1035e77a67ee0f5e9a521e6fccb1d88c758c483788c5378ba2c0b1ec4639ca9ff2f98fbadda91c6d4ef43f473d83f7bb34bcba3a3f20f5ab2c420bfeb10",
    "d36e6779beead8faeb4f30783e443f34cec1d028073549e625a975207559b9c64bc70755cd2a9777aee6e0827846fdfb33f00cfd05fb01ddadbec572eee7e50c"
    "fef4afe7a07ff07affa0dc4df692899393dc562fb89a09fae3f968c0bf40fb691f63eeb76ac7534cfd3e443fbfe7fae6b77fe1a0c1f22d5676d74f371d9b1fcc",
    "1aaf734a4d7bf7a663cfc56b583cb31ecd131219b69716d5b3763cb4d98ec88c7618faa7f4ab1ad7639996346c37a959cecdfc1c02f2f3e788e7567f50ecb738"
    "61ad5dd80b70156635bd9fcf6502dd053a57f321e6fe257e6e89c973755a98faacdae725e49a40be67e83945d413ca55ed0dccdecdbb4c63f1cc7a3bfe306129",
    "6398ef260ffd16ce51f33eaf6f868efac5769de3e3a5f851a11dab978eee251788d71f63ee8771fef4df6bcd4fd3b00e60110fd6019cc2d36559f0601dc099fa"
    "1f63ee07fe9ffe7badad0fb8cbff90df03f93d862c0b1ee4f73853ff0073bf553b7e84a9df87e81f0c1fde8624b064836638b248d7583293dc8c2a7db14aa6b4",
    "8f4a9952a22f927189618dff63ac4a93ddc08a9f2c488c4206566e144b698a7a8fdacee6462f511f3ee68a420527df977e8a69af553fc4f19ff1bef41b931f9e"
    "4622fa3fc171e91f9701d7cedd6949c7ac97df9b1ec5e299f517e37fa9a590230b5d42fce7f4936fc2c0ff5ee7ffbdc62e1b2ee68b6b8552be534edcdddf958a",
    "f71668dfad579f5f5cbcddaabf3d8369b7c1f33ed3a7b7227af9269cc333fe1ccee1995e1a02e7f0b88307e7f03853ff1798fbadda710b53bf0fd1dbee076ed6"
    "78d518f4122efbdd6926e294df5d309f467f2b54b27e69bc7f05fd642aef1b86ba04beffdd2d3857dff37cef2fd4035d75eb8e24d71b4a91a2eb312abd48f93c",
    "f01c4f6f3f8eef71f30dafe4f7b8cdf390dfe338de4896050ff27b9ca91f787e7afb713c8fc3b36aafd9efc3aa71c3494dc3abf1fa39add72279bc9a855cdfbf"
    "0d7c3e473cbb7cfe7d0c9e0fd177db6cb2d5ad2a77cac72149ca29c540e8fe3eb1387cee95b8eb399fdfac71b2a2eabb915cf6bfc121ecd31d97830be219f5c3",
    "3edd79e3e9b22c78b04fd799faa13f985e1a62f2bfc7878e8df39f76ffad5dbca71de73fb48917c1e299f51edaaf07fb6ce78807fb6c9da9df837c7ec2ca92d2"
    "41c667b878f95cf273061f444665e443d7f8bdd6e179ad8438ceb7bdd75cb392db719cd3df431cc7fb3caf86834221b1b7d9d80f49275d3523509980ba403c7f",
    "05e3f2572fdf86388fcb7f8ca9cfaabddec6e0f9103d926f43b75a7c3fc689b4dc2f8e7a3caa2356554e129d5a177e7946bb0c7d6d8c7bd0a04566d8113815d7"
    "793003dfd0db3e9f156748f7df87fbe5af6588eb78bd7fc8e7e3ea51aee95fafecefdcdda994e88d6c46a116a77f1860ee87e7da2c663f5c77acbff81906cf87",
    "e8d1fea22b714c5496e93ec5d3aaca8a9c581f7defb2e2fe76e793bb33f00cbd6d3f9a62b8c97d7d8798763ae83fa7ffab40bfe0f57ee1642b158adf6b95857c"
    "25cb44cbb554a6276417284fff0a9ec78f9937e811a2831a2fd1eac1d90cc2ddf5df7dc8d7b789b7f8f95f90af3f4f3cc8d777a67ebbbc9fc7d4ef43f4f6795f",
    "94d41d7a272b8fdf778dfc8e434c3b9dcde7dc73edfc054e116991f0ee3a401c8b67d6db3a7f47b391fb711e58ef9d239e5bf99ced68272bacf6cbabfe821cec"
    "c403ec9daeb0432c0eafc3f36b16b3bfbd05e72d8c3ff74a5e009cb7b0d87870de8233f5c3787e7a69086e3c7f8aa9cfaadddec0e0f910fdd438ce4a8d9724dd",
    "025e8de764b17866bddd7ee0b66e317264b16127e022ff7f0ef93fdee7ff4a239c2b8bbcca142521d91153a14a32b6b540e76e5ec1b8ecd5cbff99789fae5dbf"
    "fb1e06cf87e811de676559b2b46e31aff395afd8b85f19368f65489dedc79c8f52ffc8669730eefff3ddfb10c7f73aeff7c4fcf149a625c436db094ad9886fb5",
    "bb927f81e2f803ccfd5e3d6fb98569ef7ccee15c8be8e5aa6b79fe4a5b56b5d2abf1fd1816cfacbf687c50cbf2d76ce43edf47bebe770bc6f95ee7fbd5cd64ad"
    "e10fa79bd96428ade6f2a2d88d271628ce03cfaf59ccfe76cbb1b8ce8f30783e44ff447c3f2109342726d1713eae5f732bafdf2b711e9301dd8df3fce13f90af",
    "e979fee73302231cc96ca615df5337a40e53bbdfe116e8fd5af01c4f6fbfd9efc28e8de7679fbfa6ed4d5558af8ee753583cb3dedebe5dc34a6e9ecf10b9fe3e"
    "e4617a9ecf8ff7d20ac51fed52c19a5ce4bbcdec9678925fa0f7a5009f4f6fbfd9efde877d5863817d58e6765bf01fd88735473cd887e54cfd10d7318bd9dfde",
    "86755b9b78b06e3b2f3c5d96050fd66d9da91ff8de2c667f5b712c8eff430c9e0fd14fcfcf34566b2f6f9c6f777eb83303cfd03b959f69f88c7bfe32f8ea9fff"
    "8675dbabcaf756f7656d74b68bfedd50362aa74349b1bc55088b8530017cbf6c7cff29a63eab767a0783e743f4d3ce65331f389416733c5d65c7dfbf2aebb803",
    "9bf81fccc037f48e9ce334d5a06e9fdf39a8bcd884f9c055ed1facce07247abb59a1e9cd3813da682ae5209bd96ff517683e30c0dc0fcfb559167d9e60e0bbbd"
    "8f0be6094ee3e9b22c78304fb057ffff01018a192b", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70584U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
