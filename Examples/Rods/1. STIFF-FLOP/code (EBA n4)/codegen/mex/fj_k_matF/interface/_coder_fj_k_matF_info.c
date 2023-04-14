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
    "789ced5ddd6fdb541477c7366d42034b48db1002568426a14d759a7e0e09a9f96cd2354dd26469d701991d3b89936b3bb19d34e90b7d448807fe001ef6382190"
    "7863123c84375e9180079ef6c29fc03b761ca7f15deee2d58e8b9b7ba4eaf6f6d8e7777d7aeeef5e1f9f38c45c32354710c41bda4fe10b82d8f88ae8cb35a321",
    "c8417b81b00aac9f1bb437a0be2997888b96f3e60678df0efa254954b98e6a74002f723b2d81e164ad23d2023734c34a022fd2a29aef363842e61409b439b6af"
    "29f380cbf302b72d8d7412bcd611e223aa614757e9bf47aa5ca99e6b09845c554e860b463bc4c03fba3c435cff459bfec922fc4342fa47b1cfa8aa2470549566",
    "792a15db0c295db14425f45ea8a54af9543eda15a988c472a3fd30a7d2547b71214095744db956ac17055a8d2f08d0753c468cf3b2cdeb805b53ae1257467ab7"
    "364cbc63843dbb7ebb85c02321bd7ed9f202af05932cd260410b912adde072fc91f18f56265dffa4f1c0821a8f296ec54d6e029ea97f94dcded742a7a5c81490",
    "4a34a052a1fc76284ced06038beb0ca54a1260a40ec509a0ff73a7ef2fea8ee930ea05870d22c7bbb839fefdfba77f85bc8d53afe7c5d9e17510f6ecc6e17504"
    "1e09e9573703602db396cd141205a5b0b75ab9bfdb54a327e3c84cc099340e02d1f7ca3e9ecfe35b5350eb80d3f8bb89c023213db40e88b45ce1c552b5ee57fe",
    "2f4cc033f536e3450b0a996329235a06310387ced0677ac878c8ff6f7dbcfb07e6ff29e179c5ffddce61f21e1d2f575602a5744ccad5e2adb5c318e6ffffdb7c"
    "46c583ddf87b0d711d5707ed4dcb5fef6e18ed0783f6f686533e36712f21c6410e34652049fadda45b7897a1fe099ea161a51603b813bca70ef122483cabfe15",
    "f60b806728edde10d00cc581724ba4fa3ef27e7ff0eb83db7f62be9f129e577cbfde5c4be79b20ba520f57f3d9cd9cda8c464bf1f3c3f778fe5a655a799ef711"
    "7824a487f6f7bc126ef1404d8a3b2d8193f9d299f1bcd37dc12e12cfaa777a5f083bcc4c107ab8cfffe9dfbf31effb9df7d3ed6624544eb4d7f3d9e56e292688",
    "c1f8014860de9f0ddeffd035de7f078147427a88f715cd55b4bc60eeee9defef61b19bdff9f19478a6fdf4043c53ef94f7ef181e1bc68c877cffdddedb98effd"
    "cef74c7535b32f0295cd4942ac2526969858786b13f3fdacf1fd37087b76fdf411028f84f410dfd38d06e8e6fa14166f89259597c4a4980174c92c1130c7d770",
    "38be37278ccfd49707a328566991d56e044cfc9e43fc4f27e09b7aa7eb01daa1468079175f3de6f51a7eeeebf7f541a2b76b0c4d6f46d8a5f59ab21fe452078d"
    "ee397aeedb439c8fe7b555ac7178d7b53cff15a84f0c8f3334bca2346859e1fc9ae74f20f1acfad3ed1f74dfe83b08d34b0b827771b071e593cf31bffb9ddf0f",
    "f7924a1cd40bf16059ce81762dbd251e652398df679bdf17ce5d1ee8b4fc8ff340e3c78ff340dee0e13c903bf6717de7f8d6146bfc0586fcff25c29e5dbfcd23"
    "f048480fe785148593d5020d7856774548ae0c8ef3eb73e03c12cfaa77bc8f78c1719ee77d2e440ef17d81dfd78360b07e742f1a0f272bdb9ddcc1518249dcdb",
    "5571bde70cce674d8e3770bec7261ecef7b88567c8ace0e17c8f3bf631af8f6f4db1f27a08d7790efe8eeb3cc7b7a6e03a4f6ff0709da73bf67b88f3edfab188"
    "b04f42fa69ac03f3bca2eb2b320dbc8dc3de43cf3ebfa55f6299c09fdf42d58569bf507d1f79ffbe866798dffdcfef2b9d1488d7db6c2db9badfd962e5e0b298",
    "5bc59fdf9a81f9ab8b7b75fc785f8fc2b3eaf1befe55f10c99153cbcaf77c77e0f71be6ff6f58cd41259c5e37d7dd6b5f5e05d041e09e95f580f92fa1d0d2747"
    "80e619c2bd7dff45a87f321e4353aad2fd0222b7ea7932509f808e33f5ced7835187799ae7fffafa559ce7f7fb3a1017b733e1d0dece112f74d2b5062ba4d59d",
    "ee39caf3f710e7e375c02ad675e0816bf99d49fb70cd0102dd393b9e777a7f1845e259f58eee0ffb3ef2bc3ee7d90dccefbee777b91968d478653924ac66d6c4"
    "0cb3bf74bfa08431bfcf34bf13054ff99d1731bf4fe2775ef49cdf7fc6fcee7f7eafd00fd7d24b7b3bcd3526a44656e8f432b79cc5f5f8437b3355a7432430af",
    "dbc4c3bcee169e21b3828779dd1dfb98d7c7b7a658eb2f77703ec6261ecec7b88567c8ace0e17c8c3bf67f439c6fd78f34c23e09e9a7f0f9d9f9362df75f955f"
    "6cc8120b5dd763c4b8dde5f9926bcf5fdf43e091905e734e51734ab12cc940921a45a9cdc965201d164bba57ceeebd9abd53e299f60f26e099fa53ae034658bd",
    "c473ded7e5f47ef9e7125e1ffcbe3e28f7639d58f4e828b3d5092ea782814836b41838479fa77d8e38dfae1f8f11f649483fbd793dfff2038a550e3438d9db38"
    "dd74edfe60d27e9d57cafa776bba362f50df1b4a427ab84e4864b94e525487e378e2701c1b13c661ea5f31aeca7c87631b92366e4af79c97f53904aecf9f229e",
    "57eb41aedbe08595e6eede22cfb0cbc9836c26b5d83e47efd57c82387f86e72d31fa5e9d06c29e5dff5c83fa04749ca9e715d1282857f56f58f66fdd65128967"
    "d53b8987114f9dc5f72bff80dfa3e67f5edf5caa7773cd0a0f22f9487db719aee4eb0f62e788d79f23cec7fbfcf1d76b2f4e93f839804d3cfc1cc02d3c436605",
    "0f3f0770c7fe73c4f998ffc75fafbde703def23faeefc1f53da6cc0a1eaeef7166ff3fb4df3b22",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
