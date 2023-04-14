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
                (737431.00431712961));
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
    "789ced5dcb6fdbc8196776934582c5b63cb45d2c5ab4485b045da430f58aec1c0ae86dc9b65e966cc94ab63229511265924391d4cb97ead8430f7beaa9871c77"
    "0bb4d8f6d0066851686ffd07b6879e72e99fd09e2b8aa46c129a483129caa46700633cfec4f98d3e7ff3fb66be7910bb97c9dec330ec5bb39fbffc0ac30a5f60",
    "f3f4919a61b896bf871993597e4fcb7f602aebe90176dff0dc3d0def775ab90178991ec96a8165783ad7e7285a9c157892a317d53401c7f0242f97c7028d89b4"
    "04d801dd9c4b5a0c4b97198e3e02d70a696656e052d7448b8222527e8f77e8c645a9cf616247ba6a2e7bbd8069fa51d25790ef7f7f4dfd6421fac14df217c9cf",
    "880ee068a2433619229bdc8f4a63be41a49552b42f8372b69c18f3441c34e9ebe5182d93c4c0bfe3231a8aa4d5ad5fa476b86bed3f87b4ef8335db6fcef5f408"
    "7b7855984423abf0d6d5d7fb103c5c933480fa8fb20bef0353f90a4f9534419f62e92bbc2f2ce245a17846f98bcc517566127d492458d02059221b2d1f4563c4",
    "71c0e7dfa308190096022382e65882652882236596a4089a6df5f9992948731b50928376f0f5c9936fa28eda1de6b09d6f116f04a96f5dbbfb1e040f37c985f2"
    "a8bb9b970be1dd3c592e75cbe2feb8c1c7aeda515881b3aa1d18a4ec54fda8ff1a93d1de7ebae0f109a4be75f5f409040f37c915b725ee30b3c180c893ec8e34",
    "531529eee82c6f9de7cd09d61e3d39eef7d7b713e5e7e95c5fc4535d61c45355630b9b71ce5e22e1df7e89f8deed7cbf271e4964b1913dab5067552a160b875a"
    "6d1af1fd9de3fbcf21f5adaba74f2178b8496ee27b5210d871694e61a93edf9019c067f8024b36f429a0de3ec162fbbebda27dbabca5b5a2de21f9e66ce0afe3",
    "4f2de2bf5c81afcbadfa03b842551373cebea6d487dd7f21ffb0213ca7fc03208fba1449eec79bc1bdae540dd0d99a304e78c73f4c21cfa37e6d4c463bfcb96d"
    "f19e87a632b6f89c2a612449204589766bbc270dc533ca6f367e5074a38c20742ded700e8eff1ffee29788dfddceefc34a464ab117a7a9404b2cb1836efe80bf",
    "2cc611bfdf6d7edff15c1ce8a6fc8fe240cbdb8fe240cee0a138903df53bd68f37b48efb4f48fbd6b5bb8f4c653d3dd2f2cef53f4e8e22ea2f7a7ea0e6938c56"
    "d6f2c9a1568e6be59496c7b43ca7c9f5bf27b43c69dbfce181a98c2d3ea74a04309cef2a70ebfc61b3f1472048c45c435b883f4e7ef34d18cd1fdcee372a9d53",
    "3a5c2a969e1d978bfd6ae2b0760a4a271e9a3fb8b5ffc2e2e5ebdadb7ba6b29e747f811bfefa24a2e63fb66ddef023083e6e929be60d8c14eb33ac9ce1737d8e"
    "1699c6d678ffb545bc63289e516e75de6056986e480efa81bffef7df68fee0763f901ff4e2d1567ab0572e86c68d24c707523536ed1d3f6075fe7000a91f37c9",
    "2dfb81c72d56d607bd98c37637c946ecb2bb8f2178b849be346e946cbb365eb4013b59cafbbaa2b6c0f77f7c82d60d5ccff7bee3b67f201f3c0762bb23955264"
    "3b96ca0c3cb42e8cfaf1f2f6c3f81e36df58575fb0f8146e923312af0e5465e544887bd70532503ca3fc1dc7032d6644370530330fc2a0a96dec2ffb43e51334",
    "ae773bcfef072fc6a55e9b61e3e5f8c5712fd62e5f9c2411cfdf599e87e1d9b7dfa7c5cc26351db7c6eb13503ca3dc0aafab1a727c5f00e2f30de259e5f3ef42"
    "f070937cd0a393c2a0213daf0e830014a4923f7856c3bcc3e76e89bb5ef1f9e316234a728b317e8f73483b6db5bfe9b96df1fa1f42f070937ca68cfa4c09f516",
    "105900843a18d0628b05c37a433997bdbdf35ed31be2e9f5d756e0e9f21b9e1351cde82d9a737e5c30fdfb7f1ea038ce6df507eb8eefa5c3e42899b8bc2c1c8c"
    "02a16cc0172f46fdbea477fcc11bc8f3ebea7102a91f37c937d7af1fbffd03f50ecd0ab4e8ac9deedb361fb86f2a638bcfa91265b4abe45b5e5760f8263dcaf0",
    "f2a21daf2cb623b2a21dbadcda3cc1c9f300d86bb48eeb7e7f501a0b0cf7ac775cf133543394a9150b59bf97e2faaf20cfdfe17e3b4b3ecfc4f157f99346879c"
    "af8ca338fef25c4f28eee30c1e8ae3db53ff1bc8f3689cbffcfbae67a719dbc6f9abe2f0b32fce91a3edf9815b1af75fdc1332fb855075e4f83d0eaf3f7e84e2",
    "3c6ee77fb1e713ba8c148a72e1c22e5fa0aac1c353c943e7bbde409e47fcbffcfbae65a71367f99fe111ffafe27f86779cffff86f8dffdfcdf26cf76f3c14aae"
    "b74b45e5f833321fa243c57deff03f5af75d9eebc9607f6fce6de3f5778ddf5bc57bd7fd3caf2ce245a07846b98be27d284ebf413c14a7b7a77e17f2f9252d02",
    "a9cf19bf072c9ebe9173b8d39791791ef9cc317e6ff55956c9d17ecdb7ddcfa668c9e971fbe44f286eef7e9e97c301ee3851d9efd482e0722067b954d62f7b88"
    "e7bf823c8fced55eb7bbabfdf7bf86d4b7aebe7e06c1c34df265f734c7189e144d97d4d9b56ebcedfb995facc0d7e5b6dcf3b74c91dacaae83fee1cf5f8a28ae",
    "e376ff502cc6e58b42d7b74bd5728739aa4ceee5b352ca3bfe610a791ef56b6332dae1ae6dfee227103cdc2437fb8b01609a515124c7299694659a67f8f6fc73"
    "dbdadf6f753e79ba024f975bb6a3258a534cc841fb99fc8f427ec1ed7ee1f2201d8c9f0855ae48e59bd16a2b9d1d71790fddc763b53f9721f5e326b9f579831a",
    "21aab75840caf5c50cc2d9735e35742f8f453cef9ff346f7f26c120fddcb634ffd5679bf08a91f37c9adf33e0fe41c99cb8b9959d76eeb612387ef6da8d8b60e"
    "b0ea9e6546e2491e73ef3a401c8a67945bdabfa3e8c8f9380f5aefdd209e53f736f4a2fd3c171a5743be6331d08ffbe9e7032e877987d751ff35a64dbd9717dd",
    "ab0cc333cad1bdcaef8aa7a6bb8287ee55b6a77e349e5f9eeb09369e9f40ea5b576fdf87e0e126f9f2f772b55800540db8359e9387e219e576bd976baeb19913"
    "7090ff7f8ff6ffb89fffa94eb850e559b959025cb2cfa783543276e0a17dfbb7302e7bfbf6ff4c72b6c5efbf03c1c34d7213efd3a208d65ab7d8d4f9ac5b36ee",
    "9766cda39b84caf61ae79ba97faeb32d8cfbff717886e2f86ee7fd115f1c5e66052eb6df4ba4a4bdf8416f007c1e8ae35be5fd2ca47edc24dfd4fb18cf21edb3"
    "d7eeec7b4fe2fb103c5c9348cae15bccbdf1fb2814cf28bf69fc4fd9c52fe9876f3127ed20f2f5c913348e773b9f93643a561b5ea499d36cbccfc6627c62b790",
    "f3109fa3fe6b4c9b8adf5b7b9fbacef2dbdb87e998dfb7296ea3db8c73f6328da0f7a9bb9fef7dcfd2e1bdf8b012f0c58643d627b0a144fbd243f7ed20be3726"
    "18df7f0ea96f5d3d7d0ac1c34df265e7b58c0711327c81251bb4f679af9cdb7ab9025f97db72be63a9421dbf8f87fab08be23b6ef70f803cea5224b91f6f06f7",
    "ba523540676bc2d843f38129e479d4af8dc968873b9e9b27dc341e84e609cbdb8fe609cee0a17982b5faff0f2563ccd9",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43112U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_kF_info.c) */
