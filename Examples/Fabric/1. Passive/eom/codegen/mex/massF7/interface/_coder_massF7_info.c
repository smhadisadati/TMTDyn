/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF7_info.c
 *
 * Code generation for function '_coder_massF7_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF7.h"
#include "_coder_massF7_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF7"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/massF7.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.22763888887));
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
    "789ced5d4d6ce3c615e6a649b141908640da246dfab39b068b041b98b264cb768100fab7e4b52cc99265ad37a94d899444993f1249c9922ff531871c72eca187"
    "1cd3a029d25e12b445a1dc7a2dd0f4d0d30245d14bafedb9a248dae6ac26e29a146d4aef01c6987ae27ca387c76f66debc1912b732d95b04417c67f4f7d92f08",
    "e2972f6b5704f122a10b6994cf105641f5b78c7209b936e539e259cb7db70cbc5f19d7354954d9beaa5ff09cc8ee74852a2b8f2e445a60cfab6124811369512d"
    "0dda2c21b38ac4f75866aca9733c5be204765bba7491e6461742ea92eafc425369ffc79b6cedb8d81508b9a95c3497bf7c4118f6d1e44bccef7fd6a67df630f6",
    "2111fda3e4fb54531258aa49331c55a4eb2c954d6e46958158a3d2da47a56c293110a9b8c4b0e6ff3156a5a95e70297027bdbd4da5e8aaccd528561228815694"
    "d4da9270e977f431edfcb6cddff12dccef78de285fbbfc61e45144ff276094d188d98e330c8e5d7bdec1b48344f4b5919de4256ee464b248f34b23d769d26db6",
    "c89dea0ea098ed39ba627b50c1b5c714b7fca93805cfd43fca6c57462ed555648a976a344f65a3a5ed688cda0d0696d7ab942a497c55ea53acc08fffee8fed45"
    "dd370d463d61b0b1375dfc8e234c3bedfa135a9af23c71dbf8efecafbff9e4ef51eff07459143c1c1fd8f5c357307824a20f6f06f8b5fc5a215f4e9795f27eb8",
    "f160b7a3262eda919f8233ad1d04e6daabfae1799e5c9a62f5bf3b11b7fcef35e49a40be67ea917e40a4e50627d69ac77ee5fff2143c536fd35f464e21b30ca5"
    "7b8be133a8eb9cdb4c73190ff9ffe59fedfe0df87f46785ef1ffa07f92d9a053f5c66aa0964b4ac556aabb769204febf69cfb3a7f303e29d885ebe6194f7224e",
    "f9d8c47d0ed30ed2d0d47949d266996ee17d1bb9bec0d3358cd4adf2ec05de270ef1e2583cabfe29c60b3c571dcd18559eae522c5fef8ad4d846de8f0fbedabb"
    "f735f0fd8cf0bce2fbf5ce5aaed4e113abc7b166a9b059543b89442d353f7c0fcfaf5570e3fb334c7d76edf4130c1e89e891f13da7c4ba1caf66c49daec0ca5c",
    "edda78dee9b860178b67d53b9d17a20633dcc6cb71fe17fffd07f0bedf793fd7ebc4a3f5746fbd545819d49282184c1df069e0fdc5e0fd375de3fdd7317824a2"
    "47785f19998a9697ccd1bdf3f13d2a76e33b9f5f11cfac3f3705cfd43be5fdfbbac5ce7dc643beff74fffbc0f77ee7fb6a339caf88bcca142521d915d3a16a32",
    "b6b5097cbf687cff11a63ebb767a1b8347227a84efe9769b1f14c71496ea8a359593c48c98e7e99a993a60b6afedb07d2f4d699fa9af1bad386cd222339a0898"
    "f84387f8ef4dc137f54efb03bc417507f3cebf86d5175ab0eeebf7fe41a2b75b559ade8c33a1f5965209b2d983f6608ed67d8798fbe1b9b68ad50fdf712dce7f",
    "1bb926cebfa76b384569d3b2c2fa35ce9fc6e259f5571b3f68b6d14610a6959604effc2072fbdd9f03bffb9ddf4ff6334a8a3f2ea78275b9c8f75ab92df1b410"
    "077e5f6c7e5f9abb38d055f91fe24093db0f71206ff0200ee44efd90df39b934c5ea7f8173feff00539f5dbbddc5e091881e8d0b290a2bab659ae718cd1451b9",
    "617ccfafebc0252c9e55ef781cf184e13c8ffb3c133f817981dffb8360f0f87423918a651adbfde2c169ba9aded85521df73019fe7919c4520de63130fe23d6e"
    "e1e9b2287810ef71a77ee0f5c9a529565e776f3f2fe479e2f0ac7ac8f37c5a3c5d16050ff23cdda97f88b9dfae1d0f31f593887e16fdc05d4ed1f40d99e6bdf5",
    "c3e143cff66f693fb14ec0fe2d5c5ed8e81f6a6c23efcf6bf812f8ddfffcbedacff2a9e31ed3ca842bfd2d460eae88c530ecdf5a80e75713f7f2f8615c8fc3b3"
    "ea615cffb478ba2c0a1e8cebdda97f88b9df37e3faaad41519c5e3717dc1b5fee047183c12d13fd11f64b4190d2bc7f9916508f7c6fdcf22d717edd135b5263d",
    "4e20722b9f278f5c13c8f74cbdf3fee0b2c13c8df37ff8caf310e7f77b3f9012b7f3b1e8fece2927f473ad3623e4d49dc11cc5f98798fba11fb08ab51fd8732d"
    "be336d1c3e328040f7af8fe79dce0f13583cabded1fc706c23cff373be7c15f8ddf7fc2e7702ed16a7ac4485707e4dcc572ba107652506fcbed0fc4e943de577",
    "4e047e9fc6ef9ce839bfff11f8ddfffcdea01faee542fb3b9db56a548dafd2b91576a500f9f8e7f52d549e0e91065eb78907bcee169e2e8b8207bcee4efdc0eb"
    "934b53acf9973b108fb18907f118b7f07459143c88c7b853ff5f30f7dbb5238da99f44f433d83f7bb747cbe3a3f20fdbb2c420bfeb08d36e7779bee6dafaeb8f",
    "317824a21f19e7706494c3ba24f392d43e947aac5ce7a593c39a6695eb3b577378453cb3fe832978a6fe8afd80ee56df6039eff372867ffad773d03ff8bd7f50"
    "1e24fbc9c4e9697eab1f5cc90603f14274393047fb691f63eeb76bc7334cfd24a29fdd737df79bbf70d864f9362b7beba79baecd0fa68dd739a5aebd73d3b5e7",
    "e2552c9e558fe609890cdbcf88ea793b3e76d88ec8947698faa7f4ab3ad76799b6346a37a559cecbfc1c02f2f36788e7557f501cb43961b5b3bbbfcc559995cc"
    "41219f5deecdd1b99a1f63ee5fe0e796b87cae4e1b539f5dfbbc885c13c8f74c3da7887a42b9aabd79d9bf7997192c9e55efc41f2e59ca1ce67bc9439fc1396a",
    "fee7f5cdd0f1a0d869707cbc143fdeedc41aa5e3bde41cf1fa63ccfd30ce9ffc7bedf96906d6016ce2c13a805b78ba2c0a1eac03b853ff63ccfdc0ff937fafbd"
    "f5016ff91ff27b20bfc79445c183fc1e77ea779adfb387a99f44f48f460f6f531258aa49331c55a4eb2c954d6e46958158a3d2da47a56c293110a9b8c4b0e6ff",
    "3156a5a95e70297027bdbd4da5e8ea68324fb192307aba1525b5367ea0a7c5a7ecfa1fee1c4bf33de911cba721e33268941b7a791633ae578c326e94ab46b9ee"
    "d9793c6de984f5f3fbd4a3583cabfe6afd82d456a8b185ae212e74f6e1d761e817fcde2fec37cb6cb85828aeee960add4ae2c141592aeecdd17e5cbf3ebfb838",
    "bc5d7f7b06d36eb31f202d9fde8be8e51b703e8ff1399ccf33b93405cee7f1060fcee771a7fecf31f7dbb5e316a67e12d13bee07eed679d51cf4121efbdd5936"
    "e296df5d31cf467f5b54b2716dbc7f03fd6422ef9b86ba06beffed3d386fdff77c1fd86d2cf7d4ad0d496e3495628a6ec4529979caf381e77872fb717c8f9b6f",
    "f825efc76b9e87bc1fd7f1c6b2287890f7e34efdc0f393db8fe3791c9e5d7b4d7f4f569d1b4d6a9a7e8dd7cf681d17c9efd52ce4f9be6ee0f319e239e5f3ef61"
    "f04844dfebb0c976afa66c544e429294578acba18707c4fcf0b95fe2ae177c7eb7cec98aaaef52f2d8ff8647b07fd7288757c433eb87fdbbb3c6d36551f060ff",
    "ae3bf5437f30b934c5e27f8f8f5c1be73fedbe5ca7784f3bceffd8215e048b67d5fb681f1fecbf9d211eecbf75a77e1ff2f9292b4b4a17199fe1e2e533c9cf19"
    "be17199791f73de3f77a97e7b512e238dff4be73cd4a5ec771ce7e07711cfff3bc1a0e0abb89fdcde641483aeda95921955d56e788e76f605cfee6e5db101771",
    "f90f30f5d9b5d75b183c12d123f93674bbcd0f629c48cb83e2b8c74b75c59aca49a25bebc22f4d6997a9af1bb8874d5a64461d815b719d4753f04dbde3735b71"
    "86f4fe3db9bfffb50c711dbff70f85425c3dceb7026bd5839d073bd512bd9ecb2aa9f9e91f8698fbe1b9b68ad50fd75ceb2f7e8ac123113dda5ff4248e89ca32",
    "3d48f1b4aab2222736c6dfbbaeb8bfd3f964790a9ea977ec47130ca7b99087fe73f6bf2af40b7eef174eb7d2a1f85ebb2214aa39265aa9a7b37d21374779fa37"
    "f09c7eccbc418f101dd67989560fcf6710deaeff1e40bebe43bcf9cfff827cfd59e241bebe3bf53be5fd02a67e12d13be77d515277e89d9c6cbc071bf91d4798",
    "76ba9bcfb9efd9f90b9c22d222e1df75803816cfaa77742e8f6623efe33cb0de3b433caff2393bd16e4e5819545602bb72b01b5f66377ac20e313fbc0ecfaf55"
    "acfef6269cb7607cee97bc00386f61bef1e0bc0577ea87f1fce4d214dc78fe0c539f5dbbbd8ec12311fdc438ce529d9724dd027e8de7e4b07856bdd37ee0be6e",
    "316a6cb15127e021ff7f0af93ffee7ff6a339caf88bcca142521d915d3a16a32b63547e771dec0b8eccdcbffb9f49e5da77ef75d0c1e89e811de676559b2b56e"
    "31ab73976fd8b85f19358f65289ded0dce47a97f6cb36b18f7fff9c14388e3fb9df7fb62e1e434db16629b9d444a598f6f757a5200e2f8e7f5dd9473988f30ed",
    "9c553e0f0ecf2dde553ab2aa957e8de3c7b07856fd55e3805a36bf6623ef793df2d5de3d18cffb9dd7573693f566209c69e592a18c9a2f88622f9e98a3780e3c"
    "bf56b1fadb3dd7e2373fc4e09188fe89387e4212684e4ca2e3f9b6c3f638cddff74b3cc762406fe3397ff80fe465fa9efff9acc008c7329b6dc7f7d575a9cbd4",
    "1f76b9397abf163cc793db6ff5bbb06be3f9e9e7ac697b5015d6afe3f93416cfaa77b63fd7b49297e730446ebf0bf996bee7f393fd8c92e28fcba9605d2ef2bd"
    "566e4b3c2dccd17b5180cf27b7dfea77efc27e2b4360bf95b5dd36fc07f65bcd100ff65bb9533fc475ac62f5b7b7607dd6211eaccfce0a4f9745c183f55977ea",
    "07beb78ad5df965c8be3ff00834722fac97998e66aedf58df39dce0f77a6e0997ab7f2304d9ff1ce5f865ffcf3dfb06e7b53f9deeefeabf5ee7631500ee5a272"
    "2694142b5bbb6171374c00df2f1adf7f84a9cfae9ddec6e091887ed2f96bd6838532629ea76bacf1fd9bb28e3b7488ffde147c53efca794d130deaf5399dc3ea",
    "0b2d980fdcd4fec1ee7c40a2b75b559ade8c33a1f5965209b2d983f6608ee60343ccfdf05c5b65dee70926bed7fbb5609ee0369e2e8b8207f30467f5ff1f1863"
    "140c", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70576U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF7_info.c) */
