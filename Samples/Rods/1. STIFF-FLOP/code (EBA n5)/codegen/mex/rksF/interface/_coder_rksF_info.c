/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rksF_info.c
 *
 * Code generation for function '_coder_rksF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rksF.h"
#include "_coder_rksF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rksF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rksF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.8314583333));
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
  const char * data[17] = {
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4d3fd22121359f4dbaa6499a2ced3a20736c2771e28fc476d2a42ff411211ef80378d8e38440"
    "da1b93e021bcf18a043cf0b417fe04deb1e3dc34becb5dbcda7571738f54ddde1efbfcae4fcffddde3eb1387984ba5e708827853ff297e49106b5f1303b96a36",
    "04396c2f105681f573c3f63ad4077289b868396f6e88f7ddb0cfc892c67535b323f012b7dd16cb9ca277245ae446665859e4255ad20abd2647289c2a0b1d8e1d"
    "682abcc0157891db92c73a495eef888931d5a863a88cdfa3358e69e4db22a1d4d4e3e10ae31d62e81f439e22aeffa24dff6c21fc4342fa87f1cfa99a2c72548d",
    "66792a1ddf08ab3d89a192462fdcd6e442ba10eb49545466b9f17e84d368aab3b810a01843a334d4c482383efe4788f1bd6e73fc700be40a7179ac175a077847"
    "087b76fd75138147427ae37295055e0f2245a285053d346a7493cbf387e63f589d76fdd3c6030b6a3c4000deb313e201fbf9297840ff30b5b5a7874c5b552841",
    "6668814a870b5be108b5130c2cae95294d9685b2dca5385118fcdc1ef88bba0d1c46bde030336c3c8c9ba3df7f78f257d8db38f57a5e9c1d5e1761cf6e1c5e43"
    "e091907e75232084b2a15cb6982caac5ddd5eabd9d96163b1e47760aceb4711088be57f6f17c9edc02b1c6dfcd75b7e2ef06028f84f4d03a20d14a9597985ac3",
    "affc5f9c8207f436e3450f0a856329335a86310387cec86746c878c8ff6f7fb2f307e6ff53c2f38aff7bdd83d45d3a51a9ae04984c5cced713edd0411cf3ffff"
    "6d3ea3e2c16efcbd86b88e2bc3f686e5af77d6cdf6c3617b6bdd291f03dc4b887190434d459065e32ed22dbcd7a1fe319ea961e57659e08ef19e38c48b22f1ac",
    "fa57c81704be4c89b426d0658a132a6d891af8c8fbfce0d7fbb7fec47c7f4a785ef1fd5a2b9429b484d84a23522be436f25a2b166312e787eff1fcb50a2abf3f"
    "42d8b3eba70f107824a487f27b5e8db479414b49db6d915378e6cc78de695eb083c4b3ea9dde17c20e1b868d9779fe4ffffe8d79dfefbc9fe9b4a2e14ab2b356",
    "c82df798b8280513fb4212f3fe6cf0fe47aef1febb083c12d243bcafeaaea2950590dd3bcfef61b1bbbff3f48478c07e660a1ed03be5fddba6c74631e321df7f"
    "bffb0ee67bbff37db9b69add93048dcdcb62bc2d2597caf1c8e606e6fb59e3fb6f11f6ecfae963041e09e921bea79b4da1971f5058a22d311a2f4b29292bd00c",
    "280d00e36b3a1cdf5b53c607f495e1284a355a62f51b0180df7788ffd9147ca077ba1ea01dea75bd40bffc461d3ff7f5fbfa20d35bf5324d6f44d9a5b5baba17"
    "e4d2fbcdde397aeedb479c8fe7b555ac7178c7b57dfecb509f181d676a78556dd28acaf9759f3f89c4b3ea4f963f18be313208e0a505d1bb3858bffce91798df",
    "fdceef07bb293521348a896045c90b9d7a66533acc4531bfcf36bf2f9cbb7da093f23fde079a3c7ebc0fe40d1ede0772c73eaeef9cdc02b1c65f60c4ff5f21ec"
    "d9f5db3c028f84f4f0be90aa728a56a4059e355c1156aac3e3fcfa1cb880c4b3ea1de7112f38cef37d9f0bd1037c5fe0f7f520186c1cde8d2522a9ea5637bf7f",
    "982c27efee68b8de7306e7b32e47eb78bfc7261edeef710bcf9459c1c3fb3deed8c7bc3eb90562e5f530aef31cfe1dd7794e6e81e03a4f6ff0709da73bf6fb88"
    "f3edfab184b04f42fad35807e679d5d057155af0360efb0f3cfbfc96718915027f7e0b5517a6ff420d7ce4fdfb1a9e617ef73fbfaf74d342a2d161eba9d5bdee",
    "26ab0497a5fc2afefcd60ccc5f43dcabe3c7793d0acfaac779fdabe299322b7838af77c77e1f71be6ff2fab2dc9658d5e3bc3ee7da7af01e028f84f42fac0729"
    "e38e8653a282ee19c2bdbcff22d43f1e8fa9616af4a080c8ad7a9e2cd427a0e380def97a30ee304ff7f9bfb97605eff3fb7d1d48485bd9487877fb9017bb997a",
    "931533da76ef1cedf3f711e7e375c02ad675e0be6bfb3bd3f270dd0122dd3d3b9e777a7f1843e259f58eee0f073ef2bc3ee7d975ccefbee777a51568d6797539"
    "2cae664352b6bcb774afa84630bfcf34bf13454ff99d9730bf4fe3775ef29cdf7fc6fcee7f7eafd20f4299a5dded56a81cd6a22b7466995bcee17afc91bd99aa",
    "d3219298d76de2615e770bcf9459c1c3bcee8e7dcceb935b20d6facb6dbc1f63130fefc7b88567caace0e1fd1877ecff8638dfae1f69847d12d29fc2e767e73b"
    "b43278557ea9a9c82c745d8f10e37697e719d79ebfbe8fc02321bdee9c92ee9452455604596e96e40ea75404f9a0c4185e39bbf76af64f8807ecef4fc103fa13",
    "ae036658bdc473ded7e5f47ff9e7125e1ffcbe3ea8f7e2dd78ecf030bbd90d2ea78381682ebc1838479fa77d8e38dfae1f8f10f649487f7af37afee507946a9c"
    "d0e4146fe374c3b5fb8369f93aaf568cefd4746d5ea0be2f9484f4709d90c472dd94a48dc6f1d8e138d6a78c03e85f31ae2a7c97639bb23e6ecaf09c97f53904",
    "aecf3f453cafd6837cafc98b2bad9ddd45becc2ea7f673d9f462e71cbd57f331e2fc199eb7c4f87b759a087b76fd7315ea13d07140cfab925950ae19dfacecdf"
    "bacb1412cfaa77120f639e0269be973cf4237e8f9aff797d63a9d1cbb7aabc102d441b3bad48b5d0b81f3f47bcfe1c713ecef3275fafbd384de1e70036f1f073",
    "00b7f04c99153cfc1cc01dfbcf11e763fe9f7cbdf69e0f78cbffb8be07d7f70099153c5cdfe3ccfe7ff5b53934",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35408U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
