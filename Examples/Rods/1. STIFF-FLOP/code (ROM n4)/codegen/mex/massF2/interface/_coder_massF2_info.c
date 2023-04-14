/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF2_info.c
 *
 * Code generation for function '_coder_massF2_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF2.h"
#include "_coder_massF2_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.06178240746));
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
    "789ced5d4d6ce3c615e66eb3c12e8ab404f2dbbf349b148b14092c5992656f8100fab7645bff5e5b7692ca944449b4f92391942c0905aa630f39e4d8430f39a6"
    "455b6c73c9a20902f5d66b81a6879e0214412f456fcdb994287acd59cd8abba428937a0f588c474f9c6ff476f8bd9937c347e25a2a7d8d2088ef28fffefb4b82",
    "f8f5f3e31a413c47a8424ecbeb845e50fdb569b986d435b9413ca3bbeeda14ef37d37a55e065ba27ab1596e1e94c87abd0a252e1298ebe68a626700c4ff1f27e"
    "bf4513222d096c97ae4d347586a5f7198ede132e55928c52e11297541795b16afc77b44957cf8a1d8e109bd2c3eeb2972bc4d43e63b98ff9fdcf18b44f06631f",
    "12d1bf1b7fdfd31438dad3a46a8c271ddf0e4b7dbeea498e6be18e2ceca7f7637dde13156af4e57a8496294f777dcdeba98e351c254909df1af7b0ff1f63faf7"
    "acc1fedfc2f45ffb3c79f9c35025342987c76a39caa925119b7e1e9dd6936a199aea87d3fa3017d2fa7d82e99751bbdfc0f49b9c6a5ac2f964b45985f72c527f",
    "88a76a6a42a7c2d2f3ff5f8ce285b1787afdbba9bd9232b43a92e861852ac57ad2e1fdbd70c453f079d7b72a1e5910d88ad0f3d01ceb61998a32806496aa7884"
    "96e49958683c942632cf4e46c7135a6a728bb839fd6bf8c197c17f84edc3536555f07a98f68c8ebb97307824a23f6c1ed0c162beb851d8cf774ab1dde303a178",
    "2ffab01fb93938f3fa4160ea76b5efd4fbb785e997d1f1761da96ba2f90352f7e99d905abe7ec1eb434cfb46edf6630c3e89e8c7ee505c63944986c853ec1a23"
    "453a0c2ba778659a418b4c7569bcffc0245e018ba7d73fc1b819ff7b6b622fcf5b9ac13ca8c1b48164a31ff8f47ffffc12fcc082f0ecf203d96e3b1aae27bb5b",
    "fbf940bf1ae7785fe2984dbac70f985d1fec60da2711bd693f70bbcecadaa497b079dc0dd321abc6ddcb183c12d123fc2f2926a3c4786369bc7f05c7c94cded7"
    "0cb504beffe39d9fc3bcdfe97cef2d34d6bbf2ce5d416c34a562826a4412a96e0cf87e75ee6342c7f7b8f586517b3d87d409e47b9a9e917875a22a8f2385cb8b",
    "eb981d1f292c9e5eff84f3813ad3a36b2d41191e1e9da59610df21fe70f83d98d73b9de7b7fd67fd62bbc1b0d1fde859a11d69ec9fdd8b03cfaf2ccfe3f08cda"
    "eb2652272ebea76a18a9ce288b9aa653e3f5312c9e5e6f86d7550ba92301f8dc1d7866f9fc450c1e89e8bb6d3adeea56a5bba573bf20e4a4e2baffe898700f9f",
    "3b25eefa90cf6fd7195192eb8cfe779c60fa69e9f81b9d5816af7f158347227ac51865c508e5ba20b282d02a0b5d5aacb3c279b93adeaf373f9f4705d71f4d34"
    "bcd153e269ed1fcfc1d3f44f17df9b0ea3c758cefe79c1e8f3af6f401ce7aafa03a3f37b6937de8bc70683dc4ecf1748fbbcd17c78dd1b778f3ff80a73bd513b",
    "0e31ed93887e71f7f5edc77fa1dca4d9162dda3b4eb72d5b0f3c83d4898befa99af16c775c2e795f81e16b742fc5cb17fdf8c8643f4273faa1e9cdad13d6381b"
    "c7c503d8c775be3f28f65b0cb7d12e1cae33955a20759ccfa5d7dd14d7ff0873fd0adfb78a785d13c79fe74faa4d6ab2330e71fcd9a52610f7b1070fe2f8d6b4",
    "ff15e67a98e7cffebdc6c669cab279febc38bcf2c339aab73c3f7045e3fedaf861953f3caa8dec8efb8f1ebc7c0be23c4ee77fb1ed6d9d325220cc05739b7cae"
    "52f2ef1e4811e07fe07fbde8f77dede57f8607fe9fc7ff0c6f3bff7f06fcef7cfe6f50479b59ff61a6bd5909cbd10d2a1ba003f96df7f03fecfbce2e35d18dbf",
    "af4e2ce3f5278ddf9bc57bd2f33c1f99c40b61f1f47a07c5fb204ebf403c88d35bd3be03f97c408b82d4e1f4bf03174f5fc873b8a3f7429332f4be6dfc5eefb0"
    "ecb884f39ab3e6ed528b12eb1dde33b692ddf3f6e19f206eef7c9e97833eae103bdc6e1efb8541574e7389f4baec229ebf8fb91e9eabbd3cee1e9ebfff15a63d",
    "a3f67a138347227ae4fc0bd56ab1fd08c35362bf38f178890e5f951981b76adff8bb73faa5e9eb53dc7293e26b8a23b0eafce6bb73f035bdd9f902d690d39d5d"
    "1bfdc327bf1521aee374ff90cf47e5b3dca977b3729cd9cd54f6a9ad6c5a4ab8c73f8c30d7c37dad17fd38dcb4cc5fbc81c123113dea2fba02530b8b22d54fb0",
    "942cd33cc33726df5bd6f97eb3ebc98339789adef4389a61b8cb79fe4e30fdb470fc0cbfa9805f70ba5f18ec24fdd17bad1297af646be1523d99ee715917e5e3"
    "317b3fef63da2711bdf975831a212ad7598192cb172b087b9ff33a86bc3c26f1dcff9c37e4e559241ee4e5b1a67db3bc9fc7b44f227af3bccf0b7286ca64c594",
    "726b37b4b091cd791b0e2ddb079897679991788a279cbb0f10c5e2e9f5a6ceef8c6d647f9c07f67b17886757de8676b893e502fd52c05b107d9de83a7db7cb65"
    "08f7f03adcbf7ad18fb79f5896a701f22ae3f0f47ac8abfca478aaac0a1ee455b6a67d98cfcf2e35c1cde78798f68cdaed07183c12d1cf8ce3acd55941502de0",
    "d4784e168ba7d79bf5036fa916f34c2ca638011bf9ff7770fec7f9fc5f690673259e956b45818b77f8a4bf128fecb8e8dcfe158ccb5ebdf33fc38c65f1fb1730"
    "7824a247789f1645c1d0bec5a29ecfba62f37e49e91e5df3a86c3fe57c94fa27365bc2bcff8bdd2388e33b9df77b7cfe7c906e7191ed762c216d4577da5dc1eb",
    "a238be59decf60da2711fda2deb7881b0746c7ddb730fdd7cef5bf72f9c3e12f42ea1fdb6a393ab26c1df01aa61f24a247fc81482b0cd8a28bcc407dd1a6e4d4"
    "733dc539789adeec3ae01183d9bf0ff0b7df7f0c7ec1e97e21b8ed6537739bf9dc41f2403a380c36760b6d373d0f00f7f3ec5213fdf87bcdb275c12b489d40be",
    "a7e9113fc0536283e1abcd33a7f2bfc5e73a8dac0b2e6c66efb9cee1f33f2bfc1df87f417876f17fbf779eba4b25ea8d0d6f351b178aa789cee6b98bf235bbe5"
    "7eb6757d40bc1d52cbd7a7e51ddbcefd683b0170ee67f6b981c9d3bfd3d8ff586ce4a7bfdcbb03f17fa7f3fd567b33bbdf66631b6791e67e7ebb28b763b1aa8b",
    "9eef82fb572fb8f9fd10d31e9cfb318607e77e1685a7caaae0c1b91f6bda07ded7cba2ce7b5e95733ea8188defdc7f4a3cad7d38e763359e2aab8207e77cac69"
    "1ff85e2f38beff10d39e513bfd14834722fa59f97df4892b527c8ea5aaf4f4fb5aff5a26fbb7ec3c3fefcdc1d7f496e403996950dbf33757be7d0afbbe4ef70f",
    "02b5775aa1a8ed68cdbf752a957c74fab8d577d1beef08733ddcd77ad18fc3b72d8bf3cf7f2ffb3897a5443b35ce9fc4e2e9f5e6f27c6a56b2339f73e8e63b90"
    "b7c1f1fc7e7e989212ecd941c257178b6cf734bbc30ff251e0f7d5e6f735d7c5819e96ff210e34bbff1007b2070fe240d6b40fe73b67979ae0decb6b368fe76d",
    "0c1e89e8d1b89024d1a27c40b14c6d6c8ab0d8987ecfa9fbc00bc8fb377b1ef188e16c8ffb5c8f9ec3bac0e9fec0e73b1bdc8d2522a9c65eaf783c485692770b"
    "329cf75cc1fb59916108e23d06f120de63159e2aab8207f11e6bda075e9f5d6aa2e7f5309cf39c7e0ee73c67979ac0394f7bf0e09ca735ed8f30d71bb56319d3",
    "3e89e817e1076e33d258df1029d6de717829bf030ecfbabccd0c5f27e0f9adc7e77d556c04799b5d856717bf6ff4d26ce2ac5b3b4d054bbd9d9ae80bf0c5203c"
    "bfb502f7ef58206f33ccebf5fd8679fd72f1605e6f4dfb23ccf58e99d757840e5f936c9ed7e72df3073fc2e09188fe117f304d5f1d6515cb10cbcbe779df245e",
    "0ea913c8f734bd797f70d960b6c6f93f78e916c4f99dee0712fc5e2e123ecc0c18ae973d6dd5b8ac9ce9bb28ce3fc25c0f7e402f7a3f70cfb2f8cebc79b86200"
    "8eea2d8fe7cdae0f63583cbdded4fa706223dbcfe73c7819f8ddf1fc2eb6bdad53460a84b9606e93cf554afedd032902fcbed2fc4e1cd8caef0c0ffc3e8fdf19",
    "de767eff0cf8ddf9fcdea08e36b3fec34c7bb31296a31b54364007f2701effa2bd953aa7432481d70de201af5b85a7caaae001af5bd33ef0faec5213dcfbb570"
    "78108f5105e23156e1a9b22a78108fb1a6fdbf62ae376a470ad33e89e817f0fceced2e254e52e5975ba250437ed709a6dfd6f27cd5b2fdd757317824a2578c53",
    "568c52ae0b222b08adb2d0a5c53a2b9c97ab63ab2c2fafe6e829f1b4f68fe7e069faa7f403eab07a8ce5ec3f9733fafceb1be01f9cee1fa4dd782f1e1b0c723b"
    "3d5f20edf346f3e175af8b9ea7bd8fb9de29ef556c61fa6774dc5dc7f45f7b6f8a8e0f87f9d0a40ce52d9bffcf9b8f4b6d511e974e3d6f1fc1e2e9f566f2b08e",
    "6d643fbf87e07d290bc4b38bdf03dbf17ad31b4c9d66e3fe949ccbf37c371a73d1b94bb87ff5a21f6f772c9bdfff10834722fa47ce57c6048e62f838fabe749c"
    "5fb32b6fb2d979815df9d37406b4377fda9fff5381f9bdd3f99f4d7335ee4ca4d3ade8a1bc25746af5a30ee3a2f80fdcc7b3fbaf1f7741cbe6f390274715c893",
    "330f4f9555c1833c39d6b40f7c3ebbfffa71f7ce059f9bcd83f906068f44f4681eccaec0d4c2a248f5132c25cb34cff06a26cc65c5efafd87b92f1fbfb330c67"
    "ef7bcf89e13730af77bc1f18ec24fdd17bad1297af646be1523d99ee715988ebac485ce7cd9055e3ed050c1e89e811fea7d178ce89c97e3ce9b99d2b963f4152",
    "ba47d73c2adb4f391fa57e7a3a55202eff8e134c3f2d8ce37cb17b047cef74beeff1f9f341bac545b6dbb184b415dd697705af8bde77057caf9745bdf7e4fb18"
    "3c12d1cf7eef89b65bbbbc79bed9f5a1e1fd7c8bde7ba28d191bcfe57cfaaf7fc3beed55e5fb17317824a2dfeaec15bd07fe6c584cf9e37c69a710e40b4102f8",
    "7ed5f8fe434c7b46ed04efbf7d3cfeeabd470dde7fbb483c78ffad35ed8f30d7c37dad17b7af13347cbbdf8f08eb04abf15459153c5827986bffff47821656",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70576U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
