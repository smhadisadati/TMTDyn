/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF5_info.c
 *
 * Code generation for function '_coder_sprdmpF5_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF5.h"
#include "_coder_sprdmpF5_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF5"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF5.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94942129625));
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
  const char * data[23] = {
    "789ced5dcf6fe3581df72c33ab19a1051f58560b0834b01a2d9a559d3669da110c247192266dd3244da6493bbbb44ee2246efd2bb69326bd9023070e7be2c461"
    "8e2c1268e1c08e00a172e31f5884388d841017ae702689edb6cfe44dd2da716ae7fb95aa97375ffb7d9ebff37d9ff7def73d3f1377d2993b04417c69f0f7bb1f",
    "1304f93762246fe909411ae91b042a56fd1d237dcf9237e51e7117b9ef8e81f773235f95448ded6a7a86e74476a72d54586590111981bd28a626099cc8885ab1"
    "27b384c2aa12df616b234d9de3d92227b0dbd2954c8a1b6484e415d54566a81afea69b6cf5a4d01608a5a95e5697bf9a210cfb0ce553ccf3df9dd23e398c7d48",
    "8bfe79e223aa29092cd5646a1c95496c44d59e58a552c35cb4ad49c54c31de13295aaab157f3315663a8cef25280aa0e35aaacd40439b9ba2498f5ff0ba67e6f"
    "4e59ffb72c79531e186913f9d7cdc828e96f1869424f0923edc78dfcf78df47b466a5c4f3c35d29491fed04823c6fdb188f95c47987a4ffbff72cf92272eaed3",
    "35b2743af246a7f0deb4e42ff1744d4d6a5778f612ef1736f1a2583c54ff3cbd5d1eb85e5b55285eaa323c958916b7a3316a7725b0bc5ea13449e22b52976205"
    "9ee2b90a25301acf54284956a991859604a39c49769ad6dfaca9290f88fbc6affe4f3f0fff35ea1e9e2e8b82d7c59437addf7d1583475af4a5e61e1b2ee40bab",
    "bbc57cbb1cdf3ad8930acfe8cb7a98bc88c399540f029377ab7cafb65f1953af69fded0d4bde14b3bf20917f7d14d1d36f5ff07a1f53feb476fb16069fb4e887"
    "dda5b2c40d06218ac8f04b9c1a6b73bc961607c31056e1aa73e3fd9736f176b178a8fe1a7e33fc7b3cb217f5d83418653598e9482ef6039ffde7ef9f433f3023",
    "3cb7fa816ca74547eba9ce7a311fea551382b8923ce053fee907ecce1f3631e59316bded7ee0619dd7cc412fe1b2dff53311a7fcee1d0c1e69d15bf85f1d988c"
    "51128db9f1fe2df493b1bc6f1a6a0e7cffeb473f8271bfd7f93eb0db58ee689b4f24a5d1540b49a6114ba63b71e0fbc569c704c2f7b8f9c6b4f6c2c5a7488b9e",
    "53457da0aa0d2389f38bebd8f58f34160fd55f733c50e7ba6c4d9606ee4121969a437c87f855e95d18d77b9de7378227bd42abc1f174913ed96dc51ac5936709"
    "e0f985e5791cdeb4f6ba6fc91317d7e91a4ead7383494dd3abf1fa38160fd5dbe175dd42ba27009ffb03cf2e9fbf8dc1232dfa4e8b4dc89daafaa47c1a94a49c",
    "5a580eee1f10fee173afc45d2ff9fc619d5354adcea1cf7184a9a7a3fe777ee458bcfe9b183cd2a21f18e3706084c3baa4f092241f4a1d56a9f3d2e96175b89e"
    "6f7f3c6f155c7d4c31f1ce6f8867967f3001cfd4df2cbe67b8d16b2ce7feb8e0fc8fffbc07719cdbda1f4c3bbe57b712dd44fcec2cb7d95d09655602743eba1c",
    "48f8a73f7885b97f5a3bf631e59316fdecdaf5c3d75f70d864799955dcf5d30dc7e603772d79e2e23a5d331ced0ed339af2b70628deda645eda21e2f6cd62332"
    "a11ea6dede3ce172ffd811a63e0efac54b58c7f57e7f50e8c99cb0dada2d2d73955a287d90cf6596fd14d77f81b97f81dbed4002be89e34fea4faa4d66b4320e",
    "71fcf1a92910f771070fe2f8ce94ff0a733f8cf3c73fef747e9a766c9c3f290e3f787081e9ceaf1fb8a5717fd37ff8c10f4ab791db71fff397ef3c80388fd7f9"
    "5f6905e4634e0d4585706e4dcc55cac1ad3d3506fc0ffc8f0abaeeeb2eff7322f0ff24fee744d7f9ff0fc0ffdee7ff06b3bf960d96765a6b95a846af32d9101b",
    "ca6ff887ff61dd777c6a0ae27faf8e1ce3f5ebc6efede25d773fcf0b9b78112c1eaaf750bc0fe2f433c48338bd33e57b90cfcf584552db02fa1cb878fa4cdec3"
    "3dff30324a231fb9c6eff536cf0f53d8af396edcaeca8c526f8bd4d04a6e8fdbfbbf81b8bdf7795e0baf08bbf1d246f320289d75b48c90cc2c6b3ee2f94f31f7",
    "c37bb557fdee72fffd4f30e54d6baff73178a4456fd9ffc2c832df8b7122a3f40aa31e2fd916ab1a27894ead1b7f7942bd4c7dddc03d6c32626dd01138b57ff3"
    "f9047c536f77bc8035a4b1b2eb62fff0db4f1488eb78bd7fc8e769ed24771c58ab1cec6ced548acc7a36a326fdd33f9c63ee87768d0aea876b8ef517dfc1e091",
    "16bdb5bfe8485c2daa284c2fc9339ac68a9cd8185d37affdfd76e7937b13f04cbd6d3f1a63b8a10bb9e83ffdff56a05ff07abf70b6990ad2cfe4b290af646bd1"
    "723d95e90a591f9dc763b73d1731e59316bdfd79831e213aacf312a31d5ecc20dc7dcfeb00cee5b189e7fff7bce15c9e59e2c1b93cce946f97f7f398f2498bde",
    "3eef8b92b6c3ec6495f4a06937ccb091cbe736941c5b079874ce32a78a8c4878771d80c6e2a17a5bfb778636723fce03ebbd33c473ebdc8656b49d1542bd7228"
    "b0abacb4e965f64947d821fcc3ebd07e5141fded3dc7ce698073957178a81ece55be2e9e2e8b8207e72a3b533e8ce7c7a7a6e0c6f37d4c79d3daedeb183cd2a2",
    "1f1bc759aaf392a45bc0abf19c2c160fd5dbed071eeb16a346161b74022ef2ff2f61ff8ff7f9bfd20ce7ca22afd50a9290688ba9602511dbf4d1befd5b1897bd"
    "7dfb7ffa3b8ec5efbf82c1232d7a0befb38a224db56e31abf7b36ed9b85f1d548fad513adb1b9c6fa5fe91cde630eeffd3d63ec4f1bdcefb5d317f7a969185d8",
    "462b9e54d7e9cd56470af8288e6f97f773963c61b9ced4cfea7b8c4798fa39eb773f702c7eff050c1e6968aa92fee14cafc6efa3583c547fd3f8df7017ffc046"
    "f3387fe7cfcf1ec138deeb7c2e17bbc76b592d175ecb32c5c27151d9e855451f9dbf00ed179559c5efdfc5e09116fdf8b88dc9f2f3db8769b7dfcf4cc033f54e",
    "c56d4c9f71cf5f22e19f7d027cef75be5f57b655265fcdec972afbe54a2c160ed51b2cf0fdc2f1fdc798f2a6b5d3773178a4453fee7d2df44584b498e3992a6b"
    "5cef97f7b63e9c806fea1d79bf63ac415d3f8fa7f2c56388ef78bd7f9098ede30ac36cd0b5e0fab15a5e61330772cf47f19d73ccfdd0ae5141fdf003c7e23d93",
    "bfb3353c9b4065bd1aef4961f150bdbd731b4c2bb919f78bdc7f0afbf03dcfefa7a5b49ae44ff6922b75a5c0778eb39be2599e067e5f6c7e5ff25d1ce8a6fc0f"
    "71a0f1f58738903b78100772a67cbbed3867c91396eb4cbdb7d77163aeade3aac343940958c77d5d5c50350f51265ce57358c79d219e5b7cce30a9d8c1e9498a",
    "dbcbd06d3e1613e36bb91d1fc56da0fda2723bd7714d968775dc69c7efa6cfb818a78fc0f8ddfb7c1f584d85d7e9d3d24a20767aca07643e146f9cf968fc0e7c"
    "8f0aace38eaf1face3ea02ebb8dec083755c67ca3fc7dc0fed1a95db19e7776e9e70d37810cc13c6d71fe609eee0c13cc199f2bd1ee7c78d8f67f21d963e1dd1",
    "7fd08ec5fd27bd2fabb6146d987a35ee1fc3e2a17a5bf3c8818ddc7f1f17e2feb3c4738bdf431b897a33104e1f6713c1b496cb8b62878efbe81c1e68bfa8a0fe"
    "f6c8b1f1fc373078a445ff7fe7afc52581e1c484f51c8679c77dec8e0bdc3a870731a0bbe7f0fcfedf709ebee7f99fcf0835e1446133325dd2d6a576adbedfe6",
    "607cbf40ed782861d89f3f251eeccf770a4f9745c183fdf9ce940f7c3ebefea8df3dbde073f84e962ef09dacf1a929f09d2c77f0e03b59ce940f711d54507f7b"
    "3fe294bfc1b99a563c540fe76a5e174f9745c18373359d291ff81e9559edcbf91a068fb4e831fb728cd55aefeedfdf998067ea1ddb9763f88c8bfb723efbc7bf",
    "60ddf6b6f2fdb4dfcd5a6f6f17027bc16c54490713627973372cee8609e0fb45e3fb8f31e5c1fe7d5dce6de22fde3e5fd8bf3f4b3cd8bfef4cf9e798fba15da3"
    "e2f7798289eff6fe7d9827388da7cba2e0c13cc15ef9ff03e6418a74", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 55336U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF5_info.c) */
