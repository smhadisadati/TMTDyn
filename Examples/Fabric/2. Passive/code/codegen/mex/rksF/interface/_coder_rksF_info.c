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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/rksF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737434.15019675926));
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
  const char * data[20] = {
    "789ced5d4b6f1bd7151ea77660a3484ba0401e289ada4511a070a0a1288a940b04e05ba42d8aa44853b2d2569917c921e741ce0c5fda54cb2ebac8aaab2eb24c"
    "8b1628baa9d176c1eeba2dd064d19537fd09d987c3e1a534635e732c0eaf3ce4398070757538e7bb737cee775f87d7d4ad5cfe164551df1bfffcf5d71475ffef",
    "d444deb10a2a302ddfa2ece2d4df9a963f76d491dca16edb9ebb35c5fbfdb4cea98a210c0cab22898a70d89559411b5714461666667855161546312ac3b64069"
    "82ae4a3d819f686aa2245444593850af54b2e2b82267aea866155365fe9e6c085cabdc9529ada15f3657ba5aa1a6fe31e539e6fd6fbbf44f19e39f8043ff69fa",
    "9774439505bac1f0229d4fefc7f5a1c2d159b316ef1a6a255f490d153aa9f2c2d57a423018bab7bd15a4330cab891ccd991fd05a7a664bb6bdc7679876beedf2"
    "3d9c25927bd4ddcbcac593d8223cb77efb0e062f30d570aaf50fe615dedb8efa259ea5e1d52e2b0997785f2e8917c7e2d9f59fe60e4ec6a1d1d5355a523946a2",
    "f3f1ca413c411f8582db7b2c6da8aac4aa035a90255a12595a660c89616941aa7595712ce8d328201a07ff7afad15771a27147118ef31bc41b60ecb98dbb7731"
    "780187be5d1934a305a3188916984ab959d1f6879c92b86c477101cea27650983a29fbd07fed628fb79fce78fc0263cfad9f3ec0e0051c7a73dcd2b6c4f1a440",
    "5318694b1fbb8ad1b610cb2fcff34ec1b50709c2fbcb35f190fdfc023ca47f8d38317f1e4efc453f440ea31f5a1e9bc50cb97889457ef707e07bbff3fd9e76a0"
    "33252effec987d76c226129170ad2e00df6f1cdf7f8eb1e7d64f3fc3e0051c7a07df33edb6342c4f282cd355384354959c5294180e2d0551fbda4bb6effb0bda",
    "87f4b5692bce1a8cc28f27fe087fb424fe2f16e023fdb2e301dea15688918baf11fbdde6d7303eac088fd4f8a032074d9661f693fcce5e533f0909f9d3f630b5"
    "3ee3c308f33cf46bbbd8e3f063cff67bee3aead4ec739646d4f536a3e9825ff77bb2583cbbfe7af307d337e60c0279694b2638ffbffbc9af80dffdceeffde39c",
    "9e915ad54ca8a695a55eb3f058392f2581df379bdfb7d66e1fe8bafc0ffb40f3db0ffb4064f0601fc81bfb709e3bbf44628fbf0362e7b9baa84c4abfceef49ec"
    "0f8e7d7403fb833138cf5d211e295e67986ce2b4dfca8ad57cb22b25124a2a5a3c5ca3fd1be8bf767933cf7311cbc379aedb793c8a1982fbf53198c7fb9fef83",
    "bbd9c85eb27f1c0a26fa7d29d896c2a9faf91acde381efed02e7b9f3db07e7b996c079ae3ff0e03cd71bfb23ccf3d0afedf266eef77bb74eb8ee7e10ac13e6b7"
    "1fd60964f0609de08d7dd8ef9f5f22b1c55face819ffdfc7e0051c7a07ff6b82de60da42593cb7bea8a7dfd43e11b1b85992ff5f7218f1b8b9f8cf9fbe84f580",
    "dfc781c87e508a16a3a562355bd5abc791fa93a38eb146eb01e8cff34b24f6f8bb1ff32afedec7e0051c7ac738a0305a5d54b846cbaffc5f5d8087f42ee3651c"
    "149ac0d356b44c63c6193a339f99214390ff7ff0f3a3ff02ffaf088f14ff0f07fddc232653abef06b9425a2d3733dd683f0dfcffa6f5675c3cb88d3f5c1ecebd",
    "69f9beedaf1fc7acf227d3f223cff281ee60da11986a6a92aa9ab781f8351f2889c5b3eb97395f9af888fcfc00f2815688472ccfb3132d543a526ab79568544a"
    "fb65a3934a7199f5e17be8bf76c1cdef2f30f6dcfa0977ff53c0a177ccef453dd1152523a71c76654113b91be3f965e70547583cbb7ed975a1d36128b180e03c",
    "ff6fdffc0f78dfefbc5fe87592f15ab6b7572985875c5a56429953290bbcbf19bcef5d1ee80f317801877efef92e9addfb370fb4b0000fe9bd3adf45314390ef"
    "ff78fc01f0bddff99e6d448a278a64f065554e7795ec0e9b4e3cde07bedf34beff1c630ff2402d192d89bf79f9629007ba4a3cc803f5c6fe08f33cf46bbbac2a",
    "0ff44d59275c777f08d609f3db0feb043278b04ef0c63ee4ffcc2f91d8e32f38e3ffdf60ecb9f5db030c5ec0a177ae1b745dd08c2a2389bce98ab8569f7eceaf"
    "e704152c9e5dbff43ce225c7115f17bc95ecc3bac0efe34128d43a7f94ca2472f58341f9f43ccb661f1d19900fb481fd792c1731cff27ee09e4f4be09ecf4578",
    "966c0a1edcf3e98d7de0f5f925123bafc7210f68fa77c8039a5f22813c2032789007e48dfd11e679b77e3cc3d80f38f4ab18071e88baa9af6b8c44360e47cf88"
    "e5f79baf58a320bf1f973730fe859ef888fcf7799f03bffb9fdf77077929d3eaf1cd5ce464f098d74261a51c81fcfe0de8bfa67897e709f37a1c9e5d0ff3fad7",
    "c5b36453f0605eef8dfd11e679dfcceb59b5abf03ae1797dc9b3f1e04718bc8043ffd27890335734829694c69ea1bc9bf7df76d42fdb6369b806334920f22a9f"
    "a7e8a8538ecf21fdf2e3c1558711dde7ffedbbf7609fdfefe34046392826e2c787e7a23c2834dbbc5c300e876bb4cf3fc23c0fe3805dece3c053cff67716cdc3",
    "c70e9099c1cdf1fcb2ebc31416cfae5f6a7d38f111f1fc9ce7ef01bffb9edfb54eb0dd14f5705c8e14a34a913dd97952d5d7e8dece11e679e077bbd8e3b04a94"
    "dfcd4b9a81df5fcdefe8bf8020c8efff007ef73fbfd79967d1c2cef16127cac68de42e53080be112e4e3cfec6d549e0e95055e778907bcee159e259b8207bcee",
    "8d7de0f5f925127bfee521ecc7b8c483fd18aff02cd9143cd88ff1c6febf31cfbbf52383b11f70e857f0fdd9073d469b5ca57cd6d654def15e9f61daed2dcf73"
    "9e9dbf7e88c10b38f463e79c8d9d725653354955db676a4fd06a92da3fe34cafdcdcbd6ba36be221fba70bf090fe9ae3801556aff01cf9bc9cd13fff7f07c607",
    "bf8f0ffa93f4209d3a3f2f3e1e84c2f95030598a6f07d7e8fbb42f30cfbbf5e305c67ec0a15f5dbf7ef0ea0f9c3504a92d6864e374dfb3f5c1a2f9baa8d744b3"
    "f4aa5fbc87c5b3eb9d79420a2f0c728a316bc7174bb623b6a01d48ff9a7155130702df56c7eda64dcf91cccfa1203f7f8578a4c683f2b02dcabb9da3e36d91e5",
    "c3b9d35231bfdd5ba37bd7bec03cbfc1fd96ba7aaf4e1b63cfad7fde71d429c7e7905ed4152ba1dc18b6cd3b37fd9a7799c3e2d9f5cbc4c3154fa1693e491efa"
    "33dca3e67f5edfdf690dcb9dba28252bc9d6512751afb49ea6d788d75f609e8779fefcf77517a7393807708907e7005ee159b22978700ee08dfd1798e781ffe7",
    "bfafbbf301b2fc0ff93d90df836453f020bf6739fbdf0274aff4e2", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 47672U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
