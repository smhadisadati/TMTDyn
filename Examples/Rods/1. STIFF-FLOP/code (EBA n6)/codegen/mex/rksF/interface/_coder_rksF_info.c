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
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rksF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[18] = {
    "789ced5dcd73da4614571cc76d0e693dd39934997ec56da69d4e1204181b3b27630c36180c36d8b19d7688908491d11792c0e013339de9f4d8de7ae81fd0430f"
    "9d9e7ae4d8e9b95fd34b7be8a1d3bfa0c74a883548f106255a4481dd195b5e3fe9fd568fa7df7bbb6f01e24a227d85208857f49f19fda7f505d16937cc0331df",
    "3dce10d666975fe91e6fd9faa05d23662dd701f957dd232d891adbd0cc0ecf89ec4e4d28b28ade112981bd50c348022752a2966fca2ca1b0aac4d759a6232971"
    "3c9be7043625f575b638bd23c4fb44171d4364fc1d2db37425571308a5acf686cbf777883efb7c09b9ff5987f65982d867beab1fc81fc73e8e3e24f755565149",
    "550d84832b417283552b9a249301df9d5c3e118f3f88a7325992961896542a6adc27f48df309641c730ec7693f82769d78b9aff7706d109e53bbbc04c19bd725"
    "867efdb52e53fa6b8e0a6fced6efe1cd75f43352adc8b33d7b7eeb126f1b8a67ea07f2c789d461e7a5cf2ad2894209770c1f55c974249f8aac937b417f205c24",
    "3549e28b528364059ee4b92229501a4f154996d7ff20bb96ea788397fed0fac7f7c7cf116ffdcf6b7f1f1d5e03a2cfa9ffdd84e001ff03f284ff74b5d68c2c8a"
    "fe45ffce991688d16c838ff5c6911d8033681c04a4ef957efc1c5f3e7eabdfdd5f43e577b07c00d80bc88d28a6f8383d0950448af7899472c28974b9e296efed",
    "0d360ed0005efb05f180fe8f06e001f973f989ee100acb7422bed2fd7daf7b0096232f2c673a8e87fc7ff5fede4f98ff8784e715ff371b6789552a5e3a59f2d3"
    "9998943b8dd7c26713c4ff6dc8f5e3fa5cc3fcc2a91f5e85dccff5eef196e5bfefae99c7f7bbc7fbc8f2ff6b9071cceb12437f899724633638aef97f028a67ea",
    "0772777943a926921d4b75b3064ff9eac1c6fb38ff1f77fe5fa98633f92abfb154592fe77737735a7563838e4f0effe3e7f8f2f15bfdeece05afb720fa9cdaeb"
    "1d081eb01790dbf27f4e5daf71bc9610776a02ab70f4c878ff7b977887503c533f903fb7bf183f4f250976b3f9040ff3fff7fefa1df3ffb8f37fa65e8d464a5b",
    "f595fc6ea849c70431183fe6b730ff4f17ffdf45c6ff6f40f080bd80dcc6ff2a4df194e20359bffbbcdfde9cae03b9e5fffd0178408e86ffef9976ebf31d0ff9"
    "ff66fc36e6ff71e7ff6279397b28f21a939384584ddc5a2cc6d6939b98ffa795ff3f87e8736aaf0f2178c05e406ee37f4a96f966ae4366f19a486b9c2426c42c",
    "4fd1602b00189fec727caf0e181f9097baa328942991e17b75e81f5ce21707e003399af800372b70340ffd6cf16ce9171c2f8684e755bc4825b7e9a36a763572"
    "940e296a50e682f570726372e2057ebe2fbf2f67fee89bb879c4a8d691f03c625878669b163c3c8f40a3dfed3c623af6112d5ff0ff67107d4eedb500c103f602",
    "72fb3c425559453ba0788ec971e76c4439e99e37aa38d07689770cc533f50339a27ce229f38d208ff8f1bbd7f03c61dce3419a2b2672c9d8b1bc256cc65657d7"
    "77eb67e7abd1c989076dc8f5f8b9b6368b1fb6d6709d99c075e6fe713b981fe03af310f1709d198d7eb7eb46acad4ff49d37d3271f5e3c58e05443ae2be5098f",
    "fd71edc8b37da5c64d9608bcaf74f03cb263a911d4a35a7731df8f3fdf2f35d27cbc52674e13cb878d24a30443626e19ef2b9da2e7d868e8f615e17c1f8687f3"
    "7d7778669b163c9cefa3d13f21f97e51aa898c4a789defef228b0b6f41f0801d81fca9b89030e63aac12e575db10e8e603b3b67e6f3cb31dfd7499ea14a651c5",
    "8503289ea91fc851c5857eb3194985877ef3efec755c1718f7b8101753d9f5c8a39d734e68644e6546c8683bcd09aa0be0b870f97d398b0bfbc8d68106e5e7ba"
    "0904aa313ade773b7f4c42f14cfd408e60fed8b194f7f5a2d6dd39ccf763cff74ad52f9f726a28222c67c362b678b8b87da0ae63bec77cafb796b77ccf8998ef",
    "9df13d278e80ef3fc07c3ffe7c7f421d85338b8f76aae162448b2e5199101bda9da07da098ef2fbf2f67f9fd01b2759f372178c08e406e5ff71119b69110b53d"
    "969764433eaaf719b75f100fe87f62ebdbf1801cf9e752592ce8695d603f24e2bac0b8c787542a1e0d47d24ab2941254215b2e470e03e713341ff81b72bd533b",
    "7e02d10fec08e4c37eae174abc446905da58e72d181fd64d71a25a00278155738ffdf54f1659fcb80dc1037606725bfce85825adff8fefcac7b56eb007c533f5"
    "03399a3ca467b611cc2bf0fbcb8688e755dca8af2c86c26c723b53da58d58ec3d45e2aca0913544ffe0d72bd533b366c7da2efbcfed769e87183530b2a7722b2",
    "8c355878ea9f6d1aaf2b39c4c3eb4aa8f1cc362d78785d098dfe36e47afc7e326bb3fae126e679877898e751e3996d5af030cfa3d1df865c8f79dedaac75e234"
    "de17e4100fef0b428d67b669c1c3fb82d0e86f43ae776ac723887e60472047f879410b754ae97ce94c415624c6763f4f20e345eb87bd759b16449f53fbbd0dc1",
    "03f60372dd24059dc90a2549e125492e48755629f1d2598136be2714d7879fe93f66daf00cfb795a1ffee6d76b382e8c7b5c50b7638dd8c6f97936d90886d241"
    "7f743712f04fd0f791b9ad0f7f0ad10fec08e4c37eae179e7d42a1ccf2b2f175cee3ba1e34286fe7d492f15dd3c89e8fd7a178a67e2087ec67ba18c7d72ec711",
    "1f300e207f21ff2a710d9691257df4a4613f8fdf3f863f576288785ec5875c53e684a5eadea30057644289e3dd6c3a509fa0cf9fc6cfafb559fdcd7fc1ef3244"
    "9f533bddb0f589bef366fae49c2a9a1f81a03565636feeb8ae0b65a078a67e2077ef177df6d21dc443ffb88df7f98c3fbf6f2e569ab9ea09c747f3d1ca5e75fd",
    "245fd98f4d10bfe3fcdf7a5f68fd3581eb040ef1709d00359ed9a6050fd709d0e8c7f1c07a5f68ebc6dec603bc3f08ef0ffabff0b3d778787f903bfdff015137"
    "de60", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 37272U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
