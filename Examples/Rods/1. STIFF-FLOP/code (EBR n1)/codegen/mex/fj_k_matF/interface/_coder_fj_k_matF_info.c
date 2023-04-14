/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_k_matF_info.c
 *
 * Code generation for function '_coder_fj_k_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_k_matF.h"
#include "_coder_fj_k_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_k_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_k_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.950625));
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
    "789ced5dcd6fe3c615e726d96017415a026df381a269362d160d1258b2244b768a00fab6645b5f9656b695a45a4aa2244afc9048eaf3521d7bc821a79e7ac831"
    "29da62db43bb408242b9e5d8024d0f3ded257f427bae288a5a93d1ac6493a24cea3dc0188f9f38bfd1f3e36f661edf0cb15bf1c42d0cc3be37f9f9ebaf31ec1f",
    "3f906a18f632260b3e2b9fc3d4a2d5df9a953b9aba22b7b11754d7dd9ae1fd6e562f73ac48f645b942532c99ec3025929f54588221e7cd543886620956cc0d5a"
    "24c693024777c9ca5453a568324731e40977a912a32615267a4935af482ae9f7509d2c37b31d06e3ebc2d3eed2972bd8cc3e923c467cff1756b44f06611f5ca3",
    "ff20f291a3ce31a4a34e54284722721810066cd911936a818ec8e512b9f0807584b80a79b91e2445c2d1dddd713aca92a6da28368b0c21467718cdf77888e8e7"
    "8b2b7e0f6da9c85deccea5daae7f19deaa767b1e8187cf34654efe871985f7a2a6fe144fd654b84e89269fe27da6132f80c453eb3f889f9c4f5ca323f00e9a2b",
    "13b42311c89d04828e53977377bfe410398e2e717d07c9d00e9a2a3926ff7b9a283948bada61272e216cc20fbe7a70ff9b80b97e67b69f6f0eaf8f686f55bf7b"
    "0581876bf4ad5cbfe14b8969af2f45e4b28d1c7f3828b3c1a7fd482fc159d60f0c5137ab7db87fd5a2f6b79fcf797c84686f553bbd8ec0c3357a69f8e277a8c9",
    "a48067097a4798988ae0771496d7cff35a41f5471105efd135f194f6134bf014fd15fc44fa79676a2fc73b8ac11cefc8169bfb8c79fee2f7fef673e07babf3fd"
    "3e7f22109972e2e2ac74715e0a06bd9e6a8d04bedf3abeff04d1deaa767a1b81876bf41abe275a2d7a909d5258b4c396458a63e36c9a26caca5250e95f4b67ff",
    "bebfa47f8abe3aeb45b14eb095c9c45fc11febc4ff7009bea2d73b1ea00d2abb9879fe352ebdd4f8378c0f6bc2336b7ce088934689200e4315f77e4338779189"
    "426b10b6cff830465c0ff7b55ad47ef8ae61f19e3b9a3a36ff9caca104a145f00269d5784f0c89a7d65f6ffe20d9469a412856da614c9cffdf79ff57c0ef56e7",
    "f7de595c88d2cd7cd455e5b374b7913a62879910f0fb76f3fb8eede240d7e57f88032dee3fc481ccc183389031eddbe579eed7887eaeea7f2f6bea8adc9d95f5"
    "cb7f1c85fcf22f4a1990cb917f569f95a3e0acee9995bf9c95ee993e32abbf372b7db3f2c0b075c46d4d1d9b7f4ed6b4b8de34cbc0aaeb88f5c621b996e0985a",
    "680371c8d1c7df78611d61f5f1e3ac9e27bdd94c76ef3497e99c878f0b792efbc046eb08abdebfa8b8f9aafef69ca6ae88325ee0aabfdef7cbe55b86ad1f7e8a"
    "c0c7357acdfa8112821d8a16e36cb2c3903c55de18efeb9d779c22f1d47abdeb07adc1144732711cf8db7fff03eb08ab8f03a96e3b14a8c6bafbb98c67508e30",
    "ac2b5aa063f61907f4c6038e10ede31abdee71e05e951695492f66b2df8d127ea3fcee55041eaed12f8c1f456a968d1badc14f16f2be62a80df0fd9feec3f303"
    "cbf3bdf3b4b6db158f0e38be5617b251a2168cc6bb367a3e0cf7f1e2fea3f81eb5de58d55ea8f814aed153022b4f5445698788759f0fc491786afd15e70355aa",
    "4f565adcc43d1c2a4b6d22cfec8f67afc3bcdeea3c7fe86e0eb2ed1a458772a1e6693b58cb351f4480e7b796e75178c6e5fd54a9c9a2a66ed5787d1889a7d6eb"
    "e175d942a6e707009faf114f2f9fff0881876bf4dd36196975cbc2c179cfcd716921bbebbe2860f6e173abc45d9ff2f9bd2ac50b6295527f8f87887e1aea7fe3",
    "8786c5ebdf40e0e11afdc418c589118a558ea739ae55e4ba245fa5b95eb12cedd3dedcbeaff135f194f60b4bf014fd35f78bc86ef40ccb993f2f187ff9ed6d88"
    "e3dcd4f160d5f9bd701ce947c2c361faa8eff2245cce5026b0eb8cd8673c7882b87e553b8e10ede31afdfaeeeb7bcffe40b14ed22d9237d74f0f0d5b0fbca0a9",
    "63f3cfc91a69b62b951b7eae40b115b21f67c5793f3ed5d90fff927e287a7deb0433f705608fe139aef5c783eca045317bedd3b35daa54f1c40b997462d74e71"
    "fd4f11d76ff17d3b11a76de2f8cbc693729d983e198738fee2521188fb988307717c63da7f82b81ee6f98bbfef6a7e1a376c9ebf2c0e3ff9e20cd1dfdc387043",
    "e3fef3f34226bf38641b997e9ec3e357ef429cc7eafccfb79dad062578028c37ed63d3a573f7715eb0d13eaf2788eb81ff177fdf95fc74642eff532cf0ff32fe"
    "a758d3f9ff0be07febf37f8db8f0a5dc67c9b6af1410437b44ca437a3287f6e17f78eebbb85444e57f4f1e1ac6eb578ddfebc5bb6a3ecfa73af1fc483cb5de42",
    "f13e88d3af110fe2f4c6b46f413e1f923c277418f5f740c5d3d7b20f77fca17f5afa3f328ddfab1d9a964ac8d77cd6396d9295cc9eb78ffe0c717bebf3bce875"
    "31a7e1b3c37ac1cd0dbb6282892676451bf1fc23c4f5b0aff6b2df3dcdbfff0da2bd55edf50b041eaed12f3aaf3948b104af39accea8e7c69b3ea7f98325f88a",
    "de90f3fe161972f664d7c4f1e12f9ff310d7b1faf890c984c466bae1f4950ac9e3642947eca71242d43ee3c318713ddcd76a51fba1cfb0f1e267083c5ca3d78e"
    "175d8eaa04789e18446942144996626bd3cf6d2abf5fef7a32bf044fd1ebf6a30586935cc844ff19fdaf04e382d5c785e151cc1d7ad03a6732a55425705e8d25",
    "fa4cca46e7f1e8bd9f7388f6718d5effba418e1015ab344788c5f90ac2dc7d5e05389747279efdf779c3b93cebc48373798c69dfb4f39c75f33ecb89492299e2"
    "e3935bbba6848d4c3eb7e1ccb0e700cbce59a604966031eb3e070821f1d47a5df93b928dcc8ff3c0f3de35e299756e433bd049319ec1b9c779cabb3aa15df2a0",
    "cb2431fbf03adcbf6a59d7fb79e15c65149e5a0fe72a5f154f966dc18373958d691fe6f38b4b4550f3f911a2bd55edf663041eaed12f7e3f5795e638d902568d"
    "e7a490786abd51efe79a5a6c320898c8ffbf87fc1febf37fa9ee4d9fb3b458c9724ca4c3c6dca548f0c84679fb37302e7bf3f27f4649c3e2f73f44e0e11abd86",
    "f7499ee7567a6eb1aefd59376cde2f4cba47561c32dbcf385f4bfd539b6d60defff7e30b88e35b9df7fb6ca6374cb498e0613b1c15f64347ed2ee78438fed5e7"
    "fd6b7e2fe343443f8df5bf7dc3e2f8cf23f0f099469036e162d68de30790786afd75e3805236bfa06cc2c5ccf403ff570feec37cdeeabc4e10b160a1d78c51f9",
    "44a84307836cd8974eda88d7e1fe55cbbae2f8fadeafaeb0fce6f231f5aefb124bf014bd51f11bc567ccf397b11fdeaf6e7dbe77eec5bcfba1de99cb19ecf568"
    "678bf6846b431b9dbb037caf1614df7f82686f553bbd8dc0c335fa45fbb6d41b12e26c9a26cae4ecf376d9bff5e1127c456fc83e8f850635fd5c9ed24b0d88f3",
    "587d7ce088934689200e4315f77e4338779189426b60a3f5c018713ddcd76a51fbe18eedd609d78d07c13a6171ff619d600e1eac138c691fe2fd8b4b45d4fe17"
    "358cffdf44e0e11abd86ff7952a8132d324b0dc99074faa860d57dbbd925788a5e2fff7fc760e6e7f9fff30f9fc17ac0eae380f7d049fbd2be4c3a1fcb0bf933",
    "6fedf8b46da7f37ee07e5e5c2aa2f6bf370dcbfb790d81876bf49a718025f81ac596eb4dabf2bfc1e736ac92f733b799b9e7368c7ef0dee9bf80ffd7846716ff"
    "0ffabdf80111add6f69ce55484cb36a21d5fcf46ef63b4cbfd8cf28755fd0f9587a39cebf99aeaafeffae5f2ad5979dfb47dbd4aa6bf55f381d6bd2f707abae7",
    "2cb75f1213f909f281d6886716dfefb77da95c9b0eef3583f55ce6302bb6c3e1b28dce6f83fb572da8f9fd08d11eeceb5d0d0ff6f5ae0b4f966dc1837dbdc6b4"
    "0fbcaf9675e581de947dbc5a5935bef3e89a784afbb08fd7683c59b6050ff6f11ad33ef0bd5a200f7471ff200f5416c803b5061ee4811ad3fe18713ddcd76a59",
    "571ee84d59275c373e04eb84c5fd8775823978b04e30a67dc8ff595c2aa2f63fe79cfff5bec7e51e020fd7e8b5eb06412079314fd05445324580afcd3e67d5e7"
    "046b78efc3e279c4770c67fabae0b9500fd605561f0f5caee6f0201c0dc66b27fd6c61182bc50e4e45c807dac2fb792223bf61793f7734756cfe39594309d2bb",
    "6b05d2aa793f31249e5aafefbdbe8a95cc7c7fbbffcefbf09e16cbf37aef2c2e44e9663eeaaaf259badb481db1c34c08787d3b793d007940b3bf431ed0e25211"
    "c80332070ff2808c697f8cb87e553b1611ede31afd3ac6817b9420e96b3c419beb87e30bd3f2fba5af58c520bfffd9effd99d808dedb652b3cb3f87daf9fa0a3",
    "cd6ea511f79ef78f2abccbc366bd90dfbf05f7af24f0de2e98d7abfb0df3facde2c1bcde98f6c788eb2d33af2f711db622983cafcf18361efc0481876bf4df19"
    "0f66af2f0bd113cb60c6cdfbaffa3e97473af1d29a3aa6f99ca2d73f1e5c3698a971fe8f5fb90b717eab8f0351f6241d0c9c258714d34f355a1526252607368a",
    "f38f11d7c338a016f538f0c0b0f8ceb279f8c4000cd1df1ccfeb5d1f8691786abdaef5e1d446a6e7e73c7e15f8ddf2fcceb79dad062578028c37ed63d3a573f7"
    "715eb0d1b99d63c4f5c0ef6a51fb61de547e970e69067e7f36bf2baf803091dfbf007eb73ebfd7880b5fca7d966cfb4a0131b447a43ca42703f9f8f3f6b62a4f",
    "078b01afaf8807bc6e149e2cdb8207bc6e4cfbc0eb8b4b4550ef5747e1413c461688c7188527cbb6e0413cc698f6bf465cbfaa1d0944fbb846bf86fdb3f7ba04"
    "3f3d4ab9d8e2b98ae67b3d44f4db589e2f1bf6fcf50d041eaed14f8c539c18a558e5789ae35a45ae4bf2559aeb15cb92553677eedaf89a784afb8525788afe9a",
    "e380ec56cfb09cf97939e32fbfbd0de383d5c707e138d28f8487c3f451dfe549b89ca14c60d76983fdb4ff07ebca1078",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70632U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
