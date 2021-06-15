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
                (737429.55663194449));
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
    "789ced5dcd6fe3c615e7a6d96017455a026993f42bcda6c5628b04962cc9b2b7c502d6a72ddbfad6da5e6f5299922889363f249292255dea630f39e40fe8618f"
    "69d116db2240164d50a8b75e0b343df4b44011f4d26b7bae288ab687ab896873448bd27b8031a29f38bfd1c3e36f66debc19523712c91b14457d63f0f7c92f28",
    "2af39a764551af52bad0a3f2250a15b3fec6a85c325d1b72937a19b9efc608ef57a3ebb224aa6c47d52f784e64532da1c4ca830b9111d8b36a2a92c0898ca816"
    "ba0d96925945e2db6c65a8a9723c5be0047647ba70b1c90d2e84f805d5d985a6d23e47ea6cf938df1228b9ae9c3797bf78418deca3c953ccef7fd9a27d5218fb",
    "d026fde3d8079eba24b09e3a53e13cc9d84648e98a65cfa676156aa95221598876454f44aab017afc3acca78dacb4b5e4f59d3c8472ad7882f09e7edff25a67d"
    "af586cff4d4cfb6f8fca7bc87f83eb7ab9322a03a3d23b2a97d78d761d6270adda15d72e7aa4694827436f2285f78ae9fa1c4fd754a4568967cff13eb68917c2",
    "e2a1fac7899dfd81ebb414d9c34b6586f72443859d50d893f37997d74a1e5592f892d4f1b002efe1b9924760549e2979a486e2195a487395a14cb293557f3197"
    "86dca66e8d3e9d7ef845f01f21e7f0745914bc0ea63eab7ef73a068f36e9f7eabb6c309fcdafe40ad9d67e74fb6057ca3f8c9cb723330167523b28ccb553f5bb",
    "f5f96d60da65d5df5e325d1b62f03d8dfcf7eeba5ebe73c6eba798faaddaed87187cdaa4d7ba3b79891b0c226491e1973825dce27835210e8611accc95af8df7"
    "9fd9c4cb61f150fd25fc46fb7b77682fcfbb86c13c6683198ee4603ff0e97ffff905f40353c273aa1f48b79b915075b3bd56c806bae59820fae207fce6fcf403",
    "76c7ff5b98fa6993de763f70a7caabc6a09772d8ef4e93eba4fcee0d0c1e6dd29bf85f19988c9163b56be3fd19f493b1bc6f18ea1af8fef7777f0ee37eb7f3bd"
    "37575b6eab5bf725b95657f271a6168e27da51e0fbc5798e2984ef71f30dabf67ad5744d99be67e83945d407aaaa1609bcbeb88e5dff4860f150fd25c70355ae",
    "c3561ad2c03d3c88a5ae21be43fd6eef3b30ae773bcf6ff88fbbf9668de32385c871ae19ae158e1fc680e71796e7717856ed75cb744d9d7d4fd7704a951b4c6a"
    "ea6e8dd747b178a8de0eafeb16d23d01f87c3ef0ecf2f9b73178b449df6eb2b146bbacdcdf3ff14b5246c92ffb1f1d50f3c3e76e89bb9ef3f99d2a272b6a9543",
    "7fc721a69d44fdaf7f482c5eff16068f36e907c6280e8c50ac4a322f498da2d466e52a2f9d14cbda7abcfdf1bc5970ed31c4c0eb5f11cfa8ff60029ea1bf5a7c"
    "6fe4465f6139e7c705fdcfbfbc09719c59ed0fac8eef95ed582716edf5325b1d5f20e9f346b2a1656f6c7efa83e798fbaddaf114533f6dd24fefb9bef3d55f28",
    "d659bec1cacefae906b1f9c0cba66beaec7bba461bed6ae535af2b706285ed2444f5ac1d4f6cb6637d423b0cbdbd79c292e0a05f3c83755cf7f707f96e831356"
    "9ab9bd65ae5409240eb299e4f23cc5f59f60ee5fe0e796d2f232e7258e3fa93f29d799e1ca38c4f1c7978640dcc7193c88e393a9ff39e67e18e78fffbdd6fc34",
    "416c9c3f290e3ff8e102d3b9be7e6046e3fe86fff0830f1edd464ec7fdfbcfdeb80d711eb7f3bfdcf4368e382510128299553153daf76fef2a61e07fe07f54d0"
    "755f67f99f1381ff27f13f273aceff9f01ffbb9fff6bcca3d5b47f2fd55c2d85d4c80a930eb081ecc6fcf03facfb8e2f0d41fceff921315ebf6cfcde2ede65f3",
    "799ed8c45bc7e2a17a17c5fb204e3f453c88d393a9df857cde6365496909e8efc0c5d3a7b20fb7fffefab05cffc0317eafb6785e2b215f73dcb85d693072b525"
    "7a342b393d6e3ffd03c4edddcff36ad027e4a27b1bf503bfd46bab49219e5c56e788e79f62ee877db517fdee3cff1e778e8f557bdd335d53a6ef197a53fe0bd3",
    "68f0dd30273272373fecf1e22db1ac7292486addf89b13da65e8ab23dc629d112b838e8054fee6e309f886deee78016bc8d1caae83fdc31f7f2d435cc7edfd43"
    "361b518f3347ded5d2416a3b552a306be9a4129f9ffea18fb91f9e6b54503f5c25d65ffc0883479bf4e6fea22d7195902c33dd38cfa82a2b72626df8bdebcaef",
    "b73b9fdc9d8067e86dfbd118c35d3cc7ef10d34e82fe73fabf12f40b6eef177a5b9bfec8c3c6be902da52ba1fdea66b223a4e7e83c1ebbcf7301533f6dd2db9f"
    "37e811a262959718b578368370769fd7019ccb63136ffef779c3b93cd3c4837379c8d46f97f7b398fa6993de3eef8b929a625269393178b46b46d8c8e1731bf6",
    "88ad034c3a6799534446a4dcbb0e10c1e2a17a5bf93b9a8d9c8ff3c07aef14f19c3ab7a1196aa58540773fe0cdc9be566499bddf1652d4fcf03a3cbfa8a0fef6"
    "6362e734c0b9ca383c540fe72a5f164f9745c1837395c9d40fe3f9f1a521b8f1fc29a63eab76fb1e068f36e9c7c67196aabc24e916706b3c278dc543f576fb81",
    "77758b7986161b74020ef2ff6f20ffc7fdfc5faa0733fb22af56f292106b899bfe522cbc354779fb3318979dbdfc9fd314b1f8fdb73078b4496fe27d5696254b"
    "eb16d3da9f3563e37e65d03cb6e2d1d97ec4f966ea1fdaec1ac6fd7fde7e04717cb7f37e47cc9ef4920d21bcd18cc695b5c856b32d79e7288e6f97f75398fa69",
    "937e5aef533cc4b48facdffdccb13c7ea5290f5fc2e9d6f87d188b87eaaf1affd3b2f8351b39cfe7eb7f797817c6f16ee7f3c046ac5af7061347e9983fa166b2"
    "a2d88e44e7288e03cf2f2aa8bfdd2516b7f93e068f36e95f88df472581e1c498791cdfb0d91ebb79fb6e89e3200674368ef3a7ff403ea6ebf99f4f0a15e15866",
    "938dc89eba26b52ad5472d6e8ecedf81e7787cfb51bf0b121bcf4f7e8f8ab6f75461dd3a9edfc4e2a17a7bfb720d2b3979fec2faad079067e97a3e3fd94b2871"
    "fe7837eeabca79be7d94de127bd908f0f962f1f903d8673512d86785b6db82ffc03eab29e2c13e2b32f5435c0715d4dfeec1baac4d3c58979d169e2e8b8207eb",
    "b264ea07be4705f5b7256271fcef62f068937e7cfea5b15a7b7de37cbbf343cbebf784f22f0d9f71ce5ffa9ffeebdfb06e3bab7c6f75dfd55a6b27efddf5a743"
    "72c21f13f7b772413117a480ef178def3fc2d467d54e3fc1e0d126fdb873d7d0038512628667caece8fbb3b28edbb789fffe047c434fe49ca6b10675fc5cfdd2",
    "d78f603e30abfd83d5f980c4ec1c9518662352f1af1d29fb3e3679d0e8ced17ca08fb91f9e6b54503f7c0fd6792de2c13a2f293c5d16050fd679c9d4dfc7dc0f"
    "fc8ecabcc781aecaff10071adf7e8803398307712032f53bf61cbb7a3fd60362bcff36068f36e94dbc2fb34a9d69b079aec746b4b7422a6ecdf3c94fc033f476",
    "79ff0583397ffedadf7efb31cc036695ffadce03821b5e7e35b39acdec6eee2abb7bc1da76ae394fef6181e7797c6908ea7f6f13cbfb791383479bf4a67e4064"
    "e41a2796ebc76ee57fc2799e56f27ece6ce6ecb8e1f4b59fe6fe0efc3f253ca7f8bfdb3949dc67e2d5da8ab79c8e49f9a3786bf52406fc3f6bcf33ce1facfadf",
    "d730bfc378dfe29bc87fdf5bd7cb7746e5f93edf430c0ea9f3968d13d8dc1af79ff679adc3b72e8ece5cd3c4417e82f31aa688e714dfaf3557d385261f5d390e"
    "d70bd98dbcda8c46cb73f45e2d787e51c18def4f31f5c179cbd6f0e0bce569e1e9b2287870de3299fa81f75199d639fbb372beb259acc6779e5e11cfa81fce57",
    "268da7cba2e0c1f9ca64ea07be4705c7f71f61ea83fc7e5dfa36f1172f4f0cf2fba78907f9fd64eaef63ee87e71a9569e57fceca3ce1aaf12198278c6f3fcc13"
    "9cc183790299fa21ff677c6908ea7fde33feb77beedb1d0c1e6dd29be70d8ac2caea2ec37315cd1421b936fa9e5bd7090a583c546f7b1cf182e11c9f17bc1439",
    "817981dbfb039fefb8773f1a0f276a3b9dfc416fb3b4793fa7423ed0023ecf03395d87fdbe16f160bf2f293c5d16050ff6fb92a91f787d7c6908caeb21c8031a"
    "fd1ff280c69786401e903378900744a6fe3ee67eab762c62eaa74dfa69f403773845d3d7648677d60ffb8f1ccbefd77e629582fc7e5cdec0e083676823e7f7f3",
    "3e037e773fbfaf74927cfcb85d394a04f73b5b15d91710f341c8ef5f80e7571372799e30aec7e1a17a18d75f164f9745c183713d99fafb98fb5d33ae2f492db1"
    "a2383caecf12eb0f7e80c1a34dfa17fa838436a361e5083fb00c456edc7fd9f7b93cb58997315d53a6ef197afbfdc14583391ae7fff0f5db10e7777b3f101777",
    "32e1d05eaac7099df451a322a4d554778ee2fc7dccfdd00fa082f6030f89c577268dc307061098cef5f1bcddf961148b87ea6dcd0f8736723c3fe7d91bc0efae"
    "e777b9e96d1c714a20240433ab62a6b4efdfde55e6e87deb7dccfdc0efa8a07eb8eb28bf7322f0fb247ee744c7f9fd33e077f7f37b8d79b49af6efa59aaba590",
    "1a5961d2013690857cfcb3fa162a4f87da045eb78807bc4e0a4f9745c1035e27533ff0faf8d21034ff3205f1188b78108f2185a7cba2e0413c864cfd7fc5dc6f"
    "d58e0ca67edaa49fc2fed93b6d461e1ea55c6cc852c5f4bb0e31ed26cbf36562ebaf6f61f068937e609ce2c028c5aa24f392d4284a6d56aef2d249b1ac59e5fa",
    "ce5deb5f11cfa8ff60029ea1bf623fa0bbd55758cef9bc9cfee75fde84fec1edfd83b21debc4a2bd5e66abe30b247dde4836b4ec9d83fdb4ff07949f0bd3",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70504U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
