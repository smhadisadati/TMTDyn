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
    "789ced5dcd73da4614571cc76d0e693dd39934997ec56d269d4e120b3036764fc67cd86030d860c776da21421246465f4802834fcc74a6d3637beba17f400f3d"
    "747aea9163a7e77e4d2feda1874eff821e2b21d620c51b9468110576676c79fda4f75b3d9e7eefedbe05882b89f41582205ed17f66f49fd61744a7dd300fc47c",
    "f73843589b5d7ea57bbc65eb83768d98b55c07e45f758fb4246a6c43333b3c27b23b35a1c82a7a47a404f6420d23099c48895abe29b384c2aa125f67998ea4c4"
    "f16c9e13d894d4d7d9e2f48e10ef135d740c91f177a4ccd2955c4d2094b2da1b2edfdf21faecf325e4fe671dda6719629ff9ae7e207f1cfb38f221b9afb28a4a",
    "aaaa3f14580d905156ad68924cfa17efe4f28978fc613c95c992b4c4b0a45251e38b42df389f40c631e7709cf62368d78997fb7aa1f541784eedf212046f5e97"
    "18faf5d7ba4ce9af392abc395bbf8737d7d1cf48b522cff6ecf9ad4bbc6d289ea91fc81f2752879d973eab48270a25dc317c5425d3e17c2abc41ee057cfe5091",
    "d424892f4a0d92157892e78aa440693c5524595eff83ec5aaae30d5efa43eb9fc53f7e0e7beb7f5efbfbe8f01a107d4efdef26040ff81f90277ca76bb5667849"
    "f42df976ce347f8c661b7cac378eec009c41e320207daff4e3e7f8f2f15bfdeec13a2abf83e503c05e406e44316591d3930045a4f84591524e38912e57dcf2bd",
    "bdc1c6011ac06bbf201ed0ffd1003c207f2e3fd11d4261994ec457babfef770fc072e485e54cc7f190ffaf3ed8fb09f3ff90f0bce2ff66e32cb146c54b27cb3e"
    "3a139372a7f15ae86c82f8bf0db97e5c9f6b985f38f5c3ab90fbb9de3ddeb2fcf7dd75f378af7b7c802cffbf0619c7bc2e31f4977849326683e39aff27a078a6",
    "7e20779737946a22d9b154376bf094af1e46efe1fc7fdcf97fb51acae4ab7c74b9b251ceef6ee6b46a344ac72787fff1737cf9f8ad7e77e782d75b107d4eedf5"
    "0e040fd80bc86df93fa76ed4385e4b883b358155387a64bcffbd4bbc43289ea91fc89fdb5f8c9fa79204bbd916050ff3fff7fefa1df3ffb8f37fa65e8d844b5b",
    "f5d5fc6eb049c70431103fe6b730ff4f17ffdf45c6ff6f40f080bd80dcc6ff2a4df194b208b27ef779bfbd395d0772cbfffb03f0801c0dffdf37edd6e73b1ef2"
    "ffcdf86dccffe3ceffc5f24af650e435262709b19ab8b5548c6d243731ff4f2bff7f0ed1e7d45e1f40f080bd80dcc6ff942cf3cd5c87cce23591d638494c8859",
    "9ea2c15600303ed9e5f85e1d303e202f754751285322c3f7ead03fb8c42f0ec0077234f1016e56e0681efad9d2d9f22f385e0c09cfab78914a6ed347d5ec5af8"
    "281d54d480cc05eaa1647472e2057ebe2fbf2f67feb83871f38851ad23e179c4b0f0cc362d78781e8146bfdb79c474ec235ab9e0ffcf20fa9cda6b018207ec05",
    "e4f67984aab28a7640f11c93e3ced9b072d23d6f5471a0ed12ef188a67ea077244f9c453e61b411ef1e377afe179c2b8c78334574ce492b163794bd88cadad6d"
    "ecd6cfced72293130fda90ebf1736d6d163f6cade33a3381ebccfde376303fc075e621e2e13a331afd6ed78d585b9fe83b6fa64f3ebc78b0c0a9865c57ca131e",
    "fbe3fa9167fb4a8d9b2c11785fe9e07964c75223a847b5ee62be1f7fbe5f6ea4f978a5ce9c26560e1b49460904c5dc0ade573a45cfb1d1d0ed2bc2f93e0c0fe7"
    "fbeef0cc362d7838df47a37f42f2fda254131995f03adfdf451617de82e0013b02f953712161cc755825c2ebb621d0cd07666dfdde78663bfae932d5294ca38a",
    "0b07503c533f90a38a0bfd6633920a0ffde6dfd9ebb82e30ee71212ea6b21be1473be79cd0c89cca8c90d1769a135417c071e1f2fb721617f691ad030dcacf75"
    "1308546374bcef76fe9884e299fa811cc1fcb16329efeb45adbb7398efc79eef95aa4f3ee5d4605858c986c46cf17069fb40ddc07c8ff95e6f2d6ff99e1331df",
    "3be37b4e1c01dfbf8ff97efcf9fe843a0a65961eed5443c5b01659a6324136b83b41fb4031df5f7e5fcef2fb0364eb3e6f42f0801d81dcbeee23326c23216a7b"
    "2c2fc9867c54ef336ebf201ed0ffc4d6b7e30139f2cfa5b258d0d3bac07e50c47581718f0fa9543c120aa795642925a842b65c0e1ffacf27683ef037e47aa776",
    "fc04a21fd811c887fd5c2f947889d20ab4b1ce5b303eac9be244b5004e02abe61efbeb9f2cb2f8711b8207ec0ce4b6f8d1b14a5aff1fdf958f6bdd600f8a67ea"
    "0772347948cf6c239857e0f7970d11cfabb8515f5d0a86d8e476a6145dd38e43d45e2ac20913544ffe0d72bd533b366c7da2efbcfed769e87183530b2a7722b2",
    "8c355878ea9f6d1aaf2b39c4c3eb4aa8f1cc362d78785d098dfe36e47afc7e326bb3fae126e679877898e751e3996d5af030cfa3d1df865c8f79dedaac75e234"
    "de17e4100fef0b428d67b669c1c3fb82d0e86f43ae776ac723887e60472047f879410b754ae97ce94c415624c6763f4f20e345eb87bd759b16449f53fbbd0dc1",
    "03f60372dd24059dc90a2549e125492e48755629f1d2598136be2714d7879fe93f66daf00cfb795a1ffee6d76b382e8c7b5c50b7638d58f4fc3c9b6c0482e980"
    "2fb21bf6fb26e8fbc8dcd6873f85e8077604f2613fd70bcf3ea1506679d9f83ae7715d0f1a94b7736ac9f8ae6964cfc7eb503c533f9043f6335d8ce36b97e388",
    "0f180790bf907f95b806cbc8923e7ad2b09fc7ef1fc39f2b31443cafe243ae2973c27275ef919f2b32c1c4f16e36edaf4fd0e74fe3e7d7daacfee6bbe07719a2"
    "cfa99d6ed8fa44df79337d724e15cd8f40d09ab2b137775cd78532503c533f90bbf78b3e7be90ee2a17fdcc6fb7cc69fdf37972acd5cf584e323f94865afba71",
    "92afecc72688df71fe6fbd2fb4fe9ac075028778b84e801acf6cd38287eb0468f4e37860bd2fb475636fe301de1f84f707fd5ff8d96b3cbc3fc89dfeff00a30b"
    "de5d", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 37272U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
