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
                (737431.80047453707));
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
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4dd38f2121359f4dbaa6499a2ced3a20736c2771e28fc476d2a42ff411211ef80378d8e38440"
    "da1b93e021bcf18a043cf0b417fe04deb1e3dc34becb5dbcda7571738f54ddde1efbfcae4fcffddde3eb1387984ba5e708827853ff297e49106b5f1303b96a36",
    "04396c2f105681f573c3f63ad4077289b868396f6e88f7ddb0cfc892c67535b323f012b7dd16cb9ca277245ae446665859e4255ad20abd2647289c2a0b1d8e1d"
    "682abcc0157891db92c73a495eef888931d5a863a88cdfa3358e69e4db22a1d4d4e3e10ae31d62e81f439e22aeffa24dff6c21fc4342fa87f1cfa99a2c72548d",
    "66792a1ddf08ab3d89a192462fdcd6e442ba10eb49545466b9f17e84d368aab3b810a01843a334d4c482383efe4788f1bd6e73fc700be40a7179ac175a077847"
    "087b76fd75138147427ae37295055e0f2245a285053d346a7493cbf387e63f589d76fdd3c6030b6a3c4000deb313e201fbf9297840ff30b5b5a7874c5b552841",
    "6668814a870b5be108b5130c2cae95294d9685b2dca5385118fcdc1ef88bba0d1c46bde030336c3c8c9ba3df7f78f257d8db38f57a5e9c1d5e1761cf6e1c5e43"
    "e091907e652320ac665773d962b2a8167757aaf7765a5aec781cd92938d3c64120fa5ed9c7f379720bc41a7f37d7dd8abf1b083c12d243eb80442b555e626a0d",
    "bff27f710a1ed0db8c173d28148ea5cc6819c60c1c3a239f1921e321ffbffdc9ce1f98ff4f09cf2bfeef750f5277e944a5ba1c603271395f4fb4570fe298ffff"
    "6ff319150f76e3ef35c4755c19b6372c7fbdb36eb61f0edb5beb4ef918e05e428c831c6a2a822c1b77916ee1bd0ef58ff14c0d2bb7cb02778cf7c4215e148967",
    "d5bf42be20f0654aa435812e539c50694bd4c047dee707bfdebff527e6fb53c2f38aefd75aab99424b882d3722b5426e23afb5623126717ef81ecf5faba0f2fb"
    "23843dbb7efa008147427a28bfe7d5489b17b494b4dd16398567ce8ce79de6053b483cabdee97d21ecb061d87899e7fff4efdf98f7fdcefb994e2b1aae243b6b",
    "855ca8c7c4452998d8179298f76783f73f728df7df45e091901ee27d557715ad2c80ecde797e0f8bddfd9da727c403f63353f080de29efdf363d368a190ff9fe"
    "fbdd7730dffb9defcbb595ec9e24686c5e16e36d29b9548e47363730dfcf1adf7f8bb067d74f1f23f048480ff13ddd6c0abdfc80c2126d89d178594a49598166",
    "406900185fd3e1f8de9a323ea0af0c4751aad112abdf0800fcbe43fccfa6e003bdd3f500ed50afeb05fae537eaf8b9afdfd70799deaa97697a23ca2eadd5d5bd"
    "2097de6ff6ced173df3ee27c3cafad628dc33baeedf35f86fac4e83853c3ab6a935654ceaffbfc49249e557fb2fcc1f08d9141002f2d88dec5c1fae54fbfc0fc",
    "ee777e3fd84da909a1514c042b4a5ee8d4339bd2612e8af97db6f97de1dced039d94fff13ed0e4f1e37d206ff0f03e903bf6717de7e4168835fe0223feff0a61"
    "cfaedfe6117824a487f785549553b4222df0ace18ab0521d1ee7d7e7c005249e55ef388f78c1719eeffb5c881ee0fb02bfaf07c160e3f06e2c114955b7baf9fd",
    "c36439797747c3f59e33389f75395ac7fb3d36f1f07e8f5b78a6cc0a1edeef71c73ee6f5c92d102baf87719de7f0efb8ce73720b04d7797a8387eb3cddb1df47"
    "9c6fd78f25847d12d29fc63a30cfab86beaad082b771d87fe0d9e7b78c4bac10f8f35ba8ba30fd176ae023efdfd7f00cf3bbfff97db99b16128d0e5b4fadec75",
    "3759251892f22bf8f35b33307f0d71af8e1fe7f5283cab1ee7f5af8a67caace0e1bcde1dfb7dc4f9bec9ebcb725b62558ff3fa9c6bebc17b083c12d2bfb01ea4"
    "8c3b1a4e890aba6708f7f2fe8b50ff783ca686a9d1830222b7ea79b2509f808e037ae7ebc1b8c33cdde7ffe6da15bccfeff77520216d6523e1dded435eec66ea",
    "4d56cc68dbbd73b4cfdf479c8fd701ab58d781fbaeedef4ccbc375078874f7ec78dee9fd610c8967d53bba3f1cf8c8f3fa9c67d731bffb9edf9556a059e7d550"
    "585cc9ae4ad9f2ded2bda21ac1fc3ed3fc4e143de5775ec2fc3e8ddf79c9737eff19f3bbfff9bd4a3f58cd2ced6eb756cb612dba4c67425c2887ebf147f666aa",
    "4e8748625eb7898779dd2d3c5366050ff3ba3bf631af4f6e8158eb2fb7f17e8c4d3cbc1fe3169e29b38287f763dcb1ff1be27cbb7ea411f649487f0a9f9f9def"
    "d0cae055f9a5a622b3d0753d428cdb5d9e675c7bfefa3e028f84f4ba734aba534a15591164b959923b9c5211e483126378e5ecdeabd93f211eb0bf3f050fe84f",
    "b80e9861f512cf795f97d3ffe59f4b787df0fbfaa0de8b77e3b1c3c3ec6637184a0703d15c7831708e3e4ffb1c71be5d3f1e21ec9390fef4e6f5fccb0f28d538"
    "a1c929dec6e9866bf707d3f2755ead18dfa9e9dabc407d5f2809e9e13a2189e5ba29491b8de3b1c371ac4f1907d0bf625c55f82ec736657ddc94e1392feb7308",
    "5c9f7f8a785ead07f95e9317975b3bbb8b7c990da5f673d9f462e71cbd57f331e2fc199eb7c4f87b759a087b76fd7315ea13d07140cfab925950ae19dfacecdf"
    "bacb1412cfaa77120f639e0269be973cf4237e8f9aff797d63a9d1cbb7aabc102d441b3bad48b5d0b81f3f47bcfe1c713ecef3275fafbd384de1e70036f1f073",
    "00b7f04c99153cfc1cc01dfbcf11e763fe9f7cbdf69e0f78cbffb8be07d7f70099153c5cdfe3ccfe7f5db83931",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35408U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
