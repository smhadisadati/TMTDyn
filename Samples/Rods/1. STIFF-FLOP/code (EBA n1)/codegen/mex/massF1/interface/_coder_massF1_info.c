/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF1_info.c
 *
 * Code generation for function '_coder_massF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF1.h"
#include "_coder_massF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/massF1.m"));
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
    "789ced5dcd6fe3c615e76eb34116455a02f9ec579a4d8ac516492dc992656f8000fab6645bd6e7dab2f321531225d1e6874452b2a44b7dec2187fc013de49816"
    "6db1ed258b2408d45baf059a1e7a0a5004bdf4da9c4b89a26dce6a56f492a24cea3dc018d18f9cdff061f87b336f868fc48d54fa0641103f50fe3efa35417cfa",
    "c2e888209e27542127e54d422fa8fec6a45c418e35b9453ca3bbeec604efb793e3aac0cb744f560f5886a7773b5c851695039ee2e8f36a6a02c7f0142f17fb2d"
    "9a10694960bb746daca9332c5d64387a47b874906494032e7149757e30528d7e479b74f5a4d0e108b1295d3497bd7c404cec339221e6fe9f31689f0f31f62111",
    "fd7bf10f3c4d81a33d4daac6780a549df6a4e39b61a9cf573dc9d1bf8ae962accf7ba2428dd67e476899f2747d2b5e4f5ea8491edfcaeb85622a91f855622793"
    "f5544727729424257c2bdcc5fdfc06d3de670ddecf2dccfddc9e94f72efff32c12527fac4fca8d49e99b94c190d6ae230cae513be3da454e342de174dcbbacc2",
    "7b1639bec0533535a15361e90bbc4f4de285b1787afd7ba99d92d2953a92e861852ac57ad2e1e24e38e2c9af7a7d1b158f2c086c45e879688ef5b04c45e92032"
    "4b553c424bf28c2d34ea2a63996527a3fd052d35b94d3c37f975f6d1d7c17f86edc3536559f07a98fa8cf6bb97317824a2df6feed1c142aeb0962fe63aa5d8f6",
    "e19e507810bd68477606ceac76109863bbea77eaf3dbc2b4cb687fbb891c6ba2f13da9fbefdd905abe71ceeb6798fa8ddaede7187c12d18fdc9db8c228830a91"
    "a7d815468a7418564ef1cab0821699eac278ff9149bc3c164fafbf42bf19fdbd35b697e72dcd601ed4605a47b2d10f7cf6bf7f7d0d7e604e7876f9814cb71d0d",
    "d793dd8d622ed0afc6397e3571c826dde3071e62ae376ac72d4cfd24a237ed07eed459591bf41236f7bbb374c8aa7ef70a068f44f408ff4b8ac92831de5818ef"
    "5fc37e3295f735432d80efff74f74318f73b9defbdf986af2b6fdd17c446532a24a8462491eac680ef97e73926747c8f9b6f18b5d7f3c831819ca7e919895707",
    "aaf22832b8b8b88ed9fe91c2e2e9f5571c0fd4991e5d6b094af7f0e82cb580f80ef1c7fd1fc1b8dee93cbfe93fe917da0d868d16a327f976a4513c7910079e5f"
    "5a9ec7e119b5d773c831717e9eaa61a43aa34c6a9a4e8dd7c7b0787abd195e572da4f604e07377e099e5f397307824a2efb6e978ab5b95ee974efd8290950a3e",
    "ffc121e11e3e774adcf582cfefd4195192eb8cfe3e8e30edb4b4ff0d8f2c8bd7bf86c12311bd628cb26284725d1059416895852e2dd659e1b45c1dadcf9b1fcf"
    "a3826b8f2656adf71fcec0d3f44f17df9b74a32758cefe71c1f0cb6f6f411ce7bafa03a3e37b693bde8bc70683ec566f35905ef54673619f37ee1e7ff00de67a",
    "a3763cc3d44f22faf93dd7779e7c42b949b32d5ab4b79f6e5a361f78063926cecf5335a3d1eea85cf0ba02c3d7e85e8a97cfdbf189c9768466b443d39b9b27ac"
    "7036f68b47b08eeb7c7f50e8b7186ead9ddff731955a207598cba67d6e8aeb7f82b97e899f5b45bcae89e3cff227d526355e198738fef4521388fbd88307717c",
    "6beaff06733d8cf3a7dfafb17e9ab26c9c3f2b0eafdc3847f516e707ae69dc5feb3facf2c3a3dac8eeb8fff0d12bb721cee374fe17dbded6312305c25c30bbce"
    "672b25fff69e1401fe07fed78b7eddd75efe6778e0ff59fccff0b6f3ff17c0ffcee7ff0675b09ef1efefb6d72b6139ba4665027420b7e91efe8775dfe9a526ba",
    "fef7cd9165bc7ed5f8bd59bcabeee7f9c4245e088ba7d73b28de0771fa39e2419cde9afa1dc8e7035a14a40ea7bf0f5c3c7d2eefe10edf0f8dcbd007b6f17bbd"
    "c3b2a312f66b4e1bb74b2d4aac7778cfc84a768fdbcffe0c717be7f3bc1c5ce5f2b1fdcde6a15f1874e5349748fb6417f1fc43ccf5f05eede57e77b1ff1e97c7",
    "c7a8bdee21c704729ea647f6bf50ad16db8f303c25f60b638f97e8f055991178abd68d7f38a35d9abe3ec12d3729bea63802abf66fbe37035fd39b1d2f600d39"
    "59d9b5d13ffce57722c4759cee1f72b9a87c923df6ae570e77b7772b456a23939612eef10f43ccf5f05ceb45df0fd72df3176f62f048448ffa8baec0d4c2a248",
    "f5132c25cb34cff08df1798bdadf6f763eb937034fd39bee47530c77398fdf11a69d16f69fb3ef2ae0179cee17065b497ff441abc4e52a995ab8544fa67b5cc6"
    "45f978cc3ecf454cfd24a2373f6f502344e53a2b5072f97c0661ef7b5e879097c7249efbdff386bc3cf3c483bc3cd6d46f96f77398fa49446f9ef77941dea576",
    "33624a79b41b5ad8c8e6bc0dfb96ad03cccab3cc483cc513ce5d078862f1f47a53fb774636b23fce03ebbd73c4b32b6f433bdcc970817e29e0cd8bab9da88fbe"
    "dfe57609f7f03a3cbf7ad1f7b75f5896a701f22ae3f0f47ac8ab7c553c5596050ff22a5b533f8ce7a7979ae0c6f36798fa8cdaed27183c12d14f8de3acd45941",
    "502de0d4784e068ba7d79bf5036fa916f38c2da638011bf9fff7b0ffc7f9fc5f6906b3259e956b05818b77f8a4bf128f6cb968dffe358ccb5ebffd3f67bb96c5"
    "ef5fc4e091881ee17d5a140543eb16f37a3feb9a8dfb25a57974cda3b2fd84f351ea1fdb6c01e3feafb60f208eef74deeff1b9d341bac54536dbb184b411dd6a",
    "7705af8be2f843ccf546ed78ddbeaf88eb1746fbe1f730f7a3edf37f55f7df9d905a062665d8b279c1eb987690881ef10f22ad30628b2e3003f5439b9253f7f9"
    "1466e0697ab3f382c70c66ffbac0dffff029f809a7fb89e0a6975dcfaee7b27bc93d696f3fd8d8ceb7ddf47e003ccfd34b4df4fdef75cbe609af22c704729ea6",
    "47fc004f890d86af364f9ccaff16eff334324f38b799bdfb3ccf5e7827ff0fe0ff39e1d9c5fffdde69ea3e95a837d6bcd54c5c281c273aeba72ecadfec96e7d9"
    "def9c1db21b57c6352deb56d1f90b63200fb80a6ef2318bf0d3c590b18898dfcf4d70777613dc0e97cbfd15ecf14db6c6ced24d22ce6360b723b16abbae87d2f",
    "787ef5821bdf9f61ea837d40c6f0601fd0bcf05459163cd807644dfdc0fb7a99d7fecfebb2ef0715a3f19d874f89a7d50ffb7eacc6536559f060df8f35f503df"
    "eb05c7f71f63ea336aa75f62f048443f2ddf8f3e91458acfb254959e9cafb5af65b27d8bcefbf3fe0c7c4d6f497e90a906b53d9f73e5fbc7b0eeeb74ff20503b",
    "c7158ada8cd6fc1bc75269954e1fb6fa2e5af71d62ae87e75a2ffa7ef8b66571fed9df691fe5b69468a7c6f993583cbdde5cde4fcd4a76e6770e3df72ee47170"
    "3cbf9feea7a4047bb29758ad8b05b67b9cd9e207b928f0fb72f3fb8aebe2404fcbff10079ade7e8803d9830771206bea87fd9dd34b4d70dfe9359bd7f30e068f",
    "44f4685c48926851dea358a6363245586c4cce73ea3af01cf2004e1f473c6638dbe33e37a3a7302f70ba3f585d3d19dc8f2522a9c64eaf7038485692f7f332ec"
    "f75cc2e75991b310c47b0ce241bcc72a3c5596050fe23dd6d40fbc3ebdd444cfebd6bdcf0bfb3c71787a3decf3bc2a9e2acb8207fb3cada97f88b9dea81dcb98",
    "fa49443f0f3f70879146fa8648b1f6f6c3e1816def6f8d6eb14ec0fb5b4fce03abd808f238bb0acf2e7e5feba5d9c449b7769c0a967a5b357135c01782f0fed6"
    "123cbf23813cce30aed7b71bc6f58bc58371bd35f50f31d73b665c5f113a7c4db2795c9fb3cc1ffc0c834722fac7fcc1249d7594552c432c2ebfe743937859e4",
    "9840ced3f4e6fdc16583d91ae7ffe8e5db10e777ba1f48f03bd948787f77c070bdcc71abc665e4ddbe8be2fc43ccf5e007f4a2f7030f2c8befcc1a872b06e0a8"
    "dee278deecfc3086c5d3eb4dcd0fc736b27d7fcea35780df1dcfef62dbdb3a66a440980b66d7f96ca5e4dfde9322c0ef4bcdefc49eadfccef0c0efb3f89de16d",
    "e7f72f80df9dcfef0dea603de3dfdf6daf57c272748dca04e8400ef6e39fd7b754fb748824f0ba413ce075abf05459163ce0756bea075e9f5e6a82fbde160e0f"
    "e231aa403cc62a3c5596050fe231d6d4ff37ccf546ed4861ea2711fd1cde9fbdd3a5c471aafc724b146ac87d1d61da6d2dcf572d5b7f7d0d8347227ac53865c5",
    "28e5ba20b282d02a0b5d5aacb3c269b93ab2cae2f26a0e9f124fabff70069ea67f4a3fa076ab2758cefe7d39c32fbfbd05fec1e9fe41da8ef7e2b1c120bbd55b"
    "0da457bdd15cd8e775d1fbb443ccf54efdce620bd35ea3fdf026e67eb4efa8e8f9f1dd905abe63d97c60d6f85c6a8bf2a874eafefb08164faf379397756423fb",
    "f93e04df4f99239e5d7c1fd88cd79bde60ea3813f7a7e46c8ee7bbd1988bf661c2f3ab177d7fbb6bd978ffa7183c12d13fb6df32267014c3c7d1efa9e3fc9a5d"
    "79941f9ac4b72b9f9ace80f6e653fbfcbf1518ef3b9dffd93457e34e443add8aeecb1b42a7563fe8302e8a07c1733cbdfdfa7e17b46c3c0f79735481bc39b3f0",
    "5459163cc89b634dfdc0e7d3dbafef77ef9ef3b9d9bc986f62f048448fe6c5ec0a4c2d2c8a543fc152b24cf30caf66c65c543cff9a7d3719bfde3fc570f67e07"
    "9d38fb0ec6f58ef70383ada43ffaa055e272954c2d5caa27d33d2e03719d2589ebdc0b59d5df5ec4e091881ee17f1a8de71c996cc755f7f15cb37c0a92d23cba",
    "e651d97ec2f928f5d393a10271f93e8e30edb4308ef3d5f601f0bdd3f9bec7e74e07e91617d96cc712d24674abdd15bc2efafe15f0bd5ee6f51d941f63f04844"
    "3ffd3b28da6aede2c6f966e787bb33f034bd55df41d1fa8c8dfb743efbf77f60ddf6baf2fd4b183c12d16f74760ade3d7f262ca6fc71beb4950ff2f920017cbf",
    "6c7cff31a63ea37682efe13e197ff9beab06dfc39d271e7c0fd79afa8798ebe1b9d68bdbe7091afe55d781619e30bdfd304fb0070fe609e6eaff3fb42a195b",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70592U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF1_info.c) */
