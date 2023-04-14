/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_kF_info.c
 *
 * Code generation for function '_coder_fj_kF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_kF.h"
#include "_coder_fj_kF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_kF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"));
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
  const char * data[21] = {
    "789ced5dcd6fe3c615e726bbc12e82343cb40d82160d362d160db630f5b5b6b740127d5bb2ad2f4bb664eda63629511265924391942cf9521d7be821a79e7ad8"
    "6352a045da4b17685128b7fe03e9a1a7bdf44f68cf1545523609cd8a6b529449cf00c678fcc4f98d9edffcdecc9b0f6277b2b93b18867d6ffaf3feaf31acf815",
    "364befa919866bf95b983199e577b4fcc7a6b29eee61770dcfddd1f07eaf951b8097e9a1ac165886a7f37d8ea2c5698127397a5e4d13700c4ff2726524d09848"
    "4b801dd0cd99a4c5b07485e1e87d70a59061a6052e7d45342f2822e5f744876e9c95fb1c2676a4cbe6b2570b98a61f257d03f9fe772dea2707d10f6e923f4b7d",
    "41740047131db2c910b9d44e4c1af10d22a394627d19547295e4882712a0495f2dc769992406c18d00d15024adeec9597a83bbd2fe5348fbdeb1d87e73aea707"
    "d8fd2ba5ade8323cabfa7a1b82876b920650ff514ee1bd632a5fe2a99226e8532c7d89f7954dbc1814cf287f96ddaf4d4da22f89040b1a244be46295fd589c38",
    "080582db142103c0526048d01c4bb00c4570a4cc921441b3ad3e3f35056966034a72d10ebe3d7cf45dcc5dbb73dbced7873784d467d5ee7e08c1c34d72a132ec"
    "6e15e4e2e65681ac94bb157167d4e0e397ed282ec159d60e0c5276ab7ed47f8dc9686f3f9bf3f818529f553d7d08c1c34d72c56d891bcc743020f224bb214d55",
    "458a1b3acbdbe7797382b5474faefb7deb76a2fc3c9ee98b78ac2b8c78ac6a6c6e33eed94b74f3775f23bef73adf6f8bfb12596ae48eabd4718d8ac73723ad36"
    "8df8fed6f1fd9790faaceae913081e6e929bf89e140476549e5158bacf376406f059bec8920d7d0aa8b74fb0d9bef797b44f97b7b4569c7448be391df8ebf813",
    "9bf8cf97e0eb72bbfe00ae50d5c4dcb3af09f56ef75fc83fac08cf2dff00c8fd2e45923b896678bb2bd54274ae2e8c92fef10f13c8f3a85f1b93d10e7fe158bc"
    "e7bea98ccd3fa74a1849124851a2bd1aefc940f18cf2eb8d1f14dd2823085d4b1b9c8be3fffb9ffe0af1bbd7f9fdbc9a95d2ecd9513ad412cbeca05bd8e52f4a",
    "09c4efb79bdf377c1707ba2effa338d0e2f6a338903b78280ee44cfdaef5e315ade3fe13d23eab76f79ea9aca7075adeb9fac7713aaafea2e749351f27b4b296"
    "8f535af9975a39aa959f6ae58c56d6fffea9967feed8fce19ea98ccd3fa74a04703edb55e0d5f9c36ae38f4090889986d6107f1cfff6bb4d347ff0badfa8768e",
    "e8cd72a9fce4a052ead7927bf523503ef4d1fcc1abfd17162fb76a6f6f99ca7ad2fd056ef8eba3a89a7fecd8bce123083e6e929be60d8c14ef33ac9ce5f37d8e"
    "1699c6da78ffa54dbc03289e516e77de6056986e482efa81bffef7df68fee0753f5018f412b15666b05d2945468d14c787d27536e31f3f6077feb00ba91f37c9",
    "6dfb81872d56d607bd98cb7637ce459db2bb0f2078b849be306e946a7b365eb4023b59c8fbbaa2d6c0f77f7a84d60d3ccff78183767020ef3e0562bb2395d364"
    "3b9ece0e7cb42e8cfaf1e2f6c3f81e36dfb0aa2f587c0a37c919895707aab27222c4bbeb0259289e51fe86e3811633a49b02989a0761d0d43af697fdb1fa211a",
    "d77b9de777c267a372afcdb0894ae2eca0176f57ce0e5388e76f2dcfc3f09cdbefd362a6939a8e57e3f549289e516e87d7550db9be2f00f1f90af1ecf2f90f20"
    "78b8493ee8d12961d0909ed6cec30014a572307c5cc7fcc3e75e89bb5ef2f9c316234a728b317e8f53483b1db5bfc9a963f1fa9f40f070937caa8c93a9124e5a",
    "406401104ec080165b2c383f6928e7b2d777de6b724d3cbdfefa123c5d7ecd7322aa19bd4673ee8f0b267fffcf3d14c7b9a9fec0eaf85eda4b0d53c98b8be2ee"
    "3014c9850289522c1848f9c71fbc823c6f558f6348fdb849beba7efdf0f51f38e9d0ac408beedae98e63f381bba63236ff9c2a5146bb4abee67505866fd2c32c",
    "2fcfdbf1c2663ba24bdaa1cbedcd13dc3c0f80bd44ebb8def707e591c0704f7a07d520433523d97aa9980bfa29aeff02f2fc2deeb7d314f04d1c7f993f6974c8"
    "d9ca388ae32fcef584e23eeee0a138be33f5bf823c8fc6f98bbfaf353bcd3a36ce5f16879f7e718e1caecf0fdcd0b8fffc9e90e92f84aa23d7ef7178f9c10314",
    "e7f13aff8bbd80d065a4488cdb2c6ef145aa16de3b927c74beeb15e479c4ff8bbfaf253b1dbbcbff0c8ff87f19ff33bcebfcff37c4ffdee7ff3679bc550857f3"
    "bd2d2a26279e9085081d29edf887ffd1baefe25c4f06fb7b75ea18afbf69fcde2ede9beee77961132f0ac533ca3d14ef4371fa15e2a138bd33f57b90cf2f6811",
    "487dcef83d60f1f4959cc39d3c8fcef2e817aef17babcfb24a8ef66bbeee7e36454b6e8fdbc77f46717beff3bcbc19e20e92d59d4e3d0c2e06728e4be782b28f"
    "78fe1bc8f3e85ced55bbbbdc7fff1b487d56f5f573081e6e922fbaa739cef0a468baa4cea975e375dfcffc6c09be2e77e49ebf458ad456765df40f7ff95a4471",
    "1daffb875229219f15bb812daa9edfcb531572bb9093d2fef10f13c8f3a85f1b13ec7d5c76fdc54f2178b8496ef61703c03463a2488ed22c29cb34cff0edd9e7"
    "d6b5bfdfee7cf268099e2eb76d470b14a798908bf633fe1f85fc82d7fdc2c56e269c38146a5c892a3463b5562637e40a3eba8fc76e7fae40eac74d72fbf30635",
    "4274d26201299fcc6710ee9ef3aaa37b796ce2f9ff9c37ba97679578e85e1e67eab7cbfb2548fdb8496e9ff77920e7c97c41cc4ebb765b0f1bb97c6f43d5b175"
    "8065f72c33124ff29877d70112503ca3dcd6fe1d4547eec779d07aef0af1dcbab7a117eb17b8c8a816091c88a17e22483f1d7079cc3fbc8efaaf31adeabdbce8",
    "5e65189e518eee557e533c35dd163c74afb233f5a3f1fce25c4fb0f1fc18529f55bdfd0882879be48bdfcbd562015035e0d5784e018a67943bf55eae99c6a64e"
    "c045feff03daffe37dfea73a9bc51acfcacd32e0527d3e13a652f15d1feddbbf8171d99bb7ff679c772c7eff7d081e6e929b789f16456069dd6255e7b36ed8b8",
    "5f9a368f6e122adb6b9c6fa6fe99ced630eeffc7de318ae37b9df7877ce9fc222770f19d5e322d6d27767b0310f0511cdf2eefe720f5e326f9aadec7780a699f"
    "b376f79963f1fbb72178b8269194c3b79877e3f731289e517eddf89fb28b5fd20fdf626eda41f4dbc347681cef753e27c94cbc7e7e96618e72893e1b8ff3c9ad",
    "62de477c8efaaf31ad2a7e6fef7dea3acbaf6f1fa66b7edfa1b88d6e33eed9cb248adea7ee7dbe0f3cc96c6e27ceaba140fcfc9c0d086c24d9bef0d17d3b88ef"
    "8d09c6f75f42eab3aaa74f2078b849bee8bc96f12042962fb26483d63eef97735bcf97e0eb7247ce772c54a8ebf7f150ef76517cc7ebfe0190fb5d8a247712cd",
    "f07657aa85e85c5d18f9683e30813c8ffab53119ed70c377f384ebc683d03c6171fbd13cc11d3c344fb057ffff016a3ec925",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43112U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_kF_info.c) */
