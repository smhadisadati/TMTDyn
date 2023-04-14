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
                (737431.00444444444));
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
    "789ced5dcd6fe3c615e726d96017415a026df381a269362d160d1258b2244b768a00fab6645b5f96569295a45a4aa224cafc9048eaf3521d7bc821a79e7ac831"
    "29da62db43bb408242b9e5d8024d0f3ded257f427bae688a5a93d1ac6493a24cea3dc0188f9f38bfd1f3e36f661edf0cb15bf1c42d0cc3be37fdf9ebaf31ec1f",
    "3f906a18f632260b3e2b9fc3d4a2d5df9a953b9aba22b7b11754d7dd9ae1fd6e56af72ac480e44b942532c99ec3215929f56588221e7cdd43886620956cc0ddb"
    "24c6930247f7c8da85a64ed1648e62c813ee5225464d2b4cf4926a5e9154d2efa126593dcf76198c6f0a4fbb4b5fae6033fb48f218f1fd5f58d13e19847d708d",
    "fe83c8478e26c7908e2651a31c89c8614018b255474caa05ba22974be4c243d611e26ae4e57a901409476f77c7e9a84a9a7aab7c5e660831bac368bec743443f"
    "5f5cf17b684b45ee62772ed576fdcbf056b5dbf3083c7ca6a972f23fcc28bc1735f5a778b2a6c6752b34f914ef339d7801249e5aff41fca438758daec03b68ae",
    "4ad08e44207712083a4e5dceddfd8a43e438bac20d1c24433b68aae298feef69a2e220e97a979dba84b0093ff8eac1fd6f02e6fa9dd97ebe39bc01a2bd55fdee"
    "15041eaed1b77383962f25a6bdbe1491cbb672fce1b0ca069ff623bd0467593f3044ddacf6e1fe558bdadf7e3ee7f131a2bd55edf43a020fd7e8a5e18bdfa1a6",
    "93029e25e81d616a2a82df51585e3fcf6b05d51f4514bc47d7c453da4f2cc153f457f013e9e79d0b7b39de510ce67847b6d8dc67ccf317bff7b79f03df5b9def"
    "f7f91381c854136785ca59b1120c7a3df506097cbf757cff09a2bd55edf436020fd7e8357c4fb4dbf4307b4161d12e5b15298e8db3699aa82a4b41a57f6d9dfd",
    "fbfe92fe29fafaac17e526c1d6a6137f057fa213ffc325f88a5eef788036a8ec62e6f9d7a4f252ebdf303eac09cfacf181234e5a1582380cd5dcfb2da1e82213"
    "a5f6306c9ff16182b81eee6bb5a8fdf05dc3e23d7734756cfe39594309429be005d2aaf19e18124fadbfdefc41b28d348350acb4c39838ffbff3feaf80dfadce",
    "effd425c88d2e7f9a8abce67e95e2b75c48e3221e0f7ede6f71ddbc581aecbff10075adc7f8803998307712063dab7cbf3dcaf11fd5cd5ff5ed6d415b93b2b9b"
    "97ff380ef9e55f9432209763ffac3e2bc7c159dd332b7f392bdd337d64567f6f56fa66e58161eb88db9a3a36ff9cac6973fd8b2c03abae23d61b87e4da82e3c2",
    "421b88438e3ffec60beb08ab8f1f85669ef46633d9bdd35ca65b0c1f97f25cf6818dd61156bd7f5171f355fded394d5d1165bcc0557fbdef97cbb70c5b3ffc14"
    "818f6bf49af5032504bb142dc6d964972179aaba31ded73bef3845e2a9f57ad70f5a83298e64e238f0b7fffe07d611561f0752bd4e28508ff5f67319cfb01a61",
    "5857b444c7ec330ee88d071c21dac7357adde3c0bd3a2d2a935ecc64bf1b27fc46f9ddab083c5ca35f183f8a342c1b375a839f2ce47dc5501be0fb3fdd87e707"
    "96e77be76963b7271e1d707ca32964a34423188df76cf47c18eee3c5fd47f13d6abdb1aabd50f1295ca3a704569ea88ad20e11eb3e1f8823f1d4fa2bce07ead4",
    "80acb5b9a97b385496da449ed91f0bafc3bcdeea3c7fe83e1f663b0d8a0ee542e7a79d602377fe20023cbfb53c8fc2332eefa74e4d17354dabc6ebc3483cb55e"
    "0fafcb16323d3f00f87c8d787af9fc47083c5ca3ef75c848bb57150e8a7d37c7a585ecaefbac84d987cfad12777dcae7f7ea142f88754afd3d1e22fa69a8ff4d",
    "1e1a16af7f0381876bf4536394a74628d7399ee6b87699eb917c9de6fae5aab44f7b73fbbe26d7c453da2f2dc153f4d7dc2f22bbd1332c67febc60f2e5b7b721"
    "8e7353c78355e7f7c2716410098f46e9a381cb9370394399c0ae33629ff1e009e2fa55ed3846b48f6bf4ebbbafef3dfb03e52649b749de5c3f3d346c3df082a6",
    "8ecd3f276ba4d9ae546ef8b902c5d6c8419c15e7fdf854673ffc4bfaa1e8f5ad13ccdc17803d86e7b8d61f0fb2c336c5ec754e0bbb54a5e6899732e9c4ae9de2"
    "fa9f22aedfe2fb762a4edbc4f1978d27d52671f1641ce2f88b4b4520ee630e1ec4f18d69ff09e27a98e72ffebeabf969dcb079feb238fcf48b33c46073e3c00d",
    "8dfbcfcf0b99fee2906d64fa790e8f5fbd0b711eabf33fdf71b65b94e00930deb48f4d578aeee3bc60a37d5e4f10d703ff2ffebe2bf9e9d85cfea758e0ff65fc"
    "4fb1a6f3ff17c0ffd6e7ff0671e64bb90bc98eaf1210437b44ca437a3287f6e17f78eebbb85444e57f4f1e1ac6eb578ddfebc5bb6a3ecfa73af1fc483cb5de42",
    "f13e88d3af110fe2f4c6b46f413e1f913c277419f5f740c5d3d7b20f77f2a1ffa2f47f641abfd7bb342d9590aff9ac73da242b993d6f1fff19e2f6d6e779d1eb"
    "624ec385c366c9cd8d7a6282892676451bf1fc23c4f5b0aff6b2df3dcdbfff0da2bd55edf50b041eaed12f3aaf3948b104af39accea8e7c69b3ea7f98325f88a",
    "de90f3fe161972f664d7c4f1e12f9ff310d7b1faf890c984c4f374cbe9ab9492c7c94a8ed84f2584a87dc68709e27ab8afd5a2f6439f61e3c5cf1078b846af1d"
    "2f7a1c550bf03c318cd28428922cc5362e3eb7a9fc7ebdebc9fc123c45afdb8f16184e722113fd67fcbf0a8c0b561f1746473177e841bbc8642aa95aa0588f25",
    "064cca46e7f1e8bd9f7388f6718d5effba418e1095eb344788e5f90ac2dc7d5e25389747279efdf779c3b93cebc48373798c69dfb4f39c75f33ecb89492299e2"
    "e3d35bbba1848d4c3eb7a160d8738065e72c53024bb098759f038490786abdaefc1dc946e6c779e079ef1af1cc3ab7a113e8a618cfb0e8719ef2ae6e68973ce8",
    "3149cc3ebc0ef7af5ad6f57e5e38571985a7d6c3b9ca57c593655bf0e05c6563da87f9fce25211d47c7e8c686f55bbfd1881876bf48bdfcf55a7394eb68055e3"
    "3929249e5a6fd4fbb92e2c361d044ce4ffdf43fe8ff5f9bfd2f4a68b2c2dd6b21c13e9b2317725123cb251defe0d8ccbdebcfc9f71d2b0f8fd0f1178b846afe1",
    "7d92e7b9959e5bac6b7fd60d9bf70bd3ee913587ccf633ced752ff85cd3630effffbf119c4f1adcefb0336d31f25da4cf0b0138e0afba1a34e8f73421cffeaf3"
    "fe35bf97f121a29fc6fadfbe6171fce71178f84c23489b7031ebc6f103483cb5feba7140299b5f5036e16266fa81ffab07f7613e6f755e278858b0d43f8f51f9",
    "44a84b07836cd8974eda88d7e1fe55cbbae2f8fadeafaeb0fce6f231f5aefb124bf014bd51f11bc567ccf397891fdeaf6e7dbe77eec5bcfba17ec1e50cf6fbb4"
    "b34d7bc28d918dcedd01be570b8aef3f41b4b7aa9dde46e0e11afda27d5bea0d0971364d135572f679bbecdffa7009bea237649fc742839a7e2e4fe5a516c479",
    "ac3e3e70c449ab421087a19a7bbf25145d64a2d41eda683d30415c0ff7b55ad47eb863bb75c275e341b04e58dc7f5827988307eb0463da8778ffe25211b5ffc5"
    "0ce3ff371178b846afe17f9e149a449bcc522332249d3e2a5875df6e76099ea2d7cbffdf3198f979fefffcc367b01eb0fa38e03d74d2beb42f93cec7f242bee0",
    "6d1c9f76ec74de0fdccf8b4b45d4fef7a661793faf21f0708d5e330eb004dfa0d86af3dcaafc6ff0b90dabe4fdcc6d66eeb90de31fbc77fa2fe0ff35e199c5ff"
    "c3413f7e4044eb8d3d673515e1b2ad68d7d7b7d1fb18ed723fa3fc6155ff43e5e128e77abea6faebbb7eb97c6b56de376d5faf92e96fd57ca075ef0bbc38dd73",
    "96db2f8989fc04f9406bc4338beff73bbe54ae4387f7ce83cd5ce6302b76c2e1aa8dce6f83fb572da8f9fd18d11eeceb5d0d0ff6f5ae0b4f966dc1837dbdc6b4"
    "0fbcaf9675e581de947dbc5a5935bef3e89a784afbb08fd7683c59b6050ff6f11ad33ef0bd5a200f7471ff200f5416c803b5061ee4811ad3fe04713ddcd76a59",
    "571ee84d59275c373e04eb84c5fd8775823978b04e30a67dc8ff595c2aa2f63fe79cfff5bec7e51e020fd7e8b5eb06412079314fd0544d3245806fcc3e67d5e7"
    "046b78efc3e279c4770c67fabae0b9501fd605561f0f5caef3d141381a8c374e06d9d22856891d9c8a900fb485f7f354c67ec3f27eee68ead8fc73b28612a477",
    "d70aa455f37e62483cb55edf7b7d152b99f9fe76ff9df7e13d2d96e7f57e212e44e9f37cd455e7b374af953a62479910f0fa76f27a00f280667f873ca0c5a522"
    "9007640e1ee40119d3fe0471fdaa762c23dac735fa758c03f72841d237788236d70f2767a6e5f74b5fb18e417effb3dffb33b511bcb7cb567866f1fbde204147",
    "cf7bb556dc5b1c1cd5789787cd7a21bf7f0bee5f49e0bd5d30af57f71be6f59bc58379bd31ed4f10d75b665e5fe1ba6c4d30795e9f316c3cf809020fd7e8bf33"
    "1ecc5e5f16a2a796c18c9bf75ff57d2e8f74e2a535754cf33945af7f3cb86c3053e3fc1fbf7217e2fc561f07a2ec493a18282447143348b5da3526252687368a",
    "f34f10d7c338a016f538f0c0b0f8ceb279f8d4000c31d81ccfeb5d1f8691786abdaef5e1858d4ccfcf79fc2af0bbe5f99def38db2d4af004186fdac7a62b45f7"
    "715eb0d1b99d13c4f5c0ef6a51fb61de547e970e69067e7f36bf2baf803091dfbf007eb73ebf3788335fca5d48767c958018da23521ed293817cfc797b5b95a7",
    "73e95c66141ef0ba2cc0eb46e1c9b22d78c0ebc6b40fbcbeb85404f57e75141ec4636481788c5178b26c0b1ec4638c69ff6bc4f5abda9140b48f6bf46bd83f7b"
    "af47f017472997db3c57d37caf87887e1bcbf355c39ebfbe81c0c335faa971ca53a394eb1c4f735cbbccf548be4e73fd7255b2cae6ce5d9b5c134f69bfb4044f",
    "d15f731c90ddea1996333f2f67f2e5b7b7617cb0faf8201c470691f068943e1ab83c0997339409ec3a6db09ff6ffc03d107a",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70632U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
