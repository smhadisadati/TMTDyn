/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rjtipF_info.c
 *
 * Code generation for function '_coder_rjtipF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rjtipF.h"
#include "_coder_rjtipF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
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
  const char * data[30] = {
    "789ced5d4d6ce3d611e626bb49b6405aa269932cdaa6bb69b06d9ac4fab565e764fddab2254bb2e41f292d648aa224dafc33a93ffb64a045d1430f39f6d0534f"
    "2d904390538f027a29726e9aa228d01c7a087aea31871e2a89a46dbee8adb8ab27caa4e701c63335e4fb8683e1cc7b338f43ea4e3a7b87a2a86f527afbefe33b",
    "e3fe65e39836fae7286b43e9778c3e801c9bed1e75d7729d49ff9dd1b3b2d4e6fa6dfd40e0256ea723d638757820312277394c5d16798991daa53385a3544e93"
    "852e571f531abcc0957891cbc8d70e36f9e18198ba46ba3c189146ffc75b1c7b52ec8894dad2aed815ae1f50d7e4f35bccfddfb5299f08463e3442ff20f9f3f8",
    "fbbe3d8d53359fa60522c1d5a02fc169276d59f105961e164be954eabd542697f7b1729df3a9c76d5e492d89977cf6317cbc6093cfe7317cde37fad72dbffad7"
    "f53e60f4c175938f230c8e5d79bd88e18336286a9deff2758e2285f702727c85a753ea72a7267057faf0f18c78692c9e95fe413a73385689bc2a3755467c38d2",
    "5dcd978d9632d1986f37e80f446abeb62c0b35b9efe344c127f0359fc8b405a6e69315cd67c869a8217a9b262fbb7a82f666bb4fbd64fc77f1da370a9f459dc3"
    "d3db6dc1c33de776f5efbb183c1aa1aff60a8dbdc3f04a64b32becae25565733f21e7b8d8ffc149c697c509863a7c677fb73ac60f8b3ab77cf21c76633ed3d6d",
    "f9f5cd75bd7f7c69e72f30e3db95df0f31f834421f793b75891f4e1654891196782dd6e185765a1a4e1738956717e607fe3423de2116cf4a7f6afd19fdbd3396"
    "9aef1d536c3e546c4ba283fee047fffe07f8839bea0f5ec5e0d1083dd73d8d471b9bddd552217cc626452998aa089be00f6e8a3f38c2f04756ef7e4accfe3fc4",
    "e0d1081db1ff1acb085c5f89cba2c2b4f9a1455e94fd1fcc8857c6e259e964ecffd7c4b608fdf9f49357fe067e604e784ef981565d512b87e749b61949642267"
    "a10e132dacc6c00fdc2e3ff0fe3a29bdfb36068f46e8881f18debdfebb5be340db583c2b9d8cfd1f8acbd014b0f7dec073cade3763b1b37a24944c56fac1eee6",
    "76894f94d55d0fcdfb21beaf376b7c3fb4aef761a35f2616dfc7f1411b148d97c6fda2ecfa1f66c4dbc0e259e9b3f87f4e687424df5052d7f4e308c31741fbf3"
    "5ee231c471dc6ecf19663356e99d6cf2fbd9784788c5a44424bf93f08e3d87e7d7daacfaf616b1f8cd030c1e8dd027c46f1875c9b4f2b3db79b4e1f8311ba9f8",
    "7d710a9e4927337f7f47979ba133d7efe308c327c1f8fd47bffc23d87db7db7dfff2e6ca6abc7710f4c77a3dc1af08e144f3dc43711bb0fbd686b3fb1f62c6b3"
    "2ba7b73178344247ec3ea328c259716cc4521d896df3b29496f202c39a5bbda6e5b5edf2f7ad29fc99f486c145b5c54875e16a3fd15f66c4af4dc137e964fc02",
    "5eac6660d0413d0bf59621dee3763f91d9da66cba7f9b568391b56b5a0c207bb912d0fad0fe0f99e7c5ff6f471c973eb87678d13c1fa61726f36583f388307eb"
    "0732e3431e406fd63cc0cabac1bdd1af3a96076065fd850cc8034c5b4f0e25057900cfe03965cf9552ff38926be7572239a6543c2ea91b67ace4217b0ecfafb5",
    "ddcc3c8069e5210ff074f3785d67aedfc711864f827af37b98c7bbdfeeafaa198d29b0d9f241ad7c588bc556c28d260776ffd6d97dc803e80df2007a833c803b"
    "f0200f40667c78be27df97bbf200e4d60fb72b0f00eb07afe1c1fa81ccf86ec9035c60f8b0ab5f779163b399798087d77fbc88afebff248c3ea9f7174962f980",
    "7b187e6883a2c8bd717528c8073cf9bdc0b19c1c5d575e7cf5e71598efbbddae1fb4f6b99562a1b8bc5b2a740e13db957db9b817f78e5d77ebf38b8b83409d9f"
    "67e307eafc58f1a1ce8f3bf0a0ce0f99f13fc65c6f578e79e49842ce33e984fcc0a386d01effeba8de5d6489d577780d834723f489f19d64d3b5f51de6a627d8",
    "fa3e2371396aefefffe69f60efdd6eeffd3bbd8858e2c5ca36bf5b4f6e27d862a371e6a1780e3cc793f9c7d97bdc7ac3aebc5e468e29e43c93ce6b923e456d8f"
    "2a7bbbb78e4f0e8b67a53fd37ca0c1f7b9ba220fd5c3679197b3fb061ea41e809d77bb9ddf089d9c154f9bbc102fc54f764f63cdd2c95ed243f95cb0f393f9c7",
    "d9791c9e5d79bd841c5397e7e9145e6bf0c3e54ccbad767d0b8b67a5cf6ed775392d208f0f767d8e784ed5e9ef9e7249a5cb6a6b87bd902ce7b5622054ae50de"
    "b1ebee8abf5ed9f5470d5ed5da0dde51fd1b1c118bdbbf81c1a311fa500cd5e1ed571bb22ac8b25295bb9cda10e45e951d7d676771fbfa07cf88678e7f3405cf",
    "a4cfb40f5857a327c8cfd178ce479fdf833cee4df50776e7f9da76b29f4c9c9fe7b7fac17036e88f17a2017fd23bfee04bccf576e5f82bccf834429ff773fde8"
    "c927545b9ca08c36bc38abaf1bc4d607b8fd45b44119cd7b47fd82f30cbc54e7fa69a94d6c9f406a0a1f269dc4ba61b46670503fde82fcaefbfd43f14ce1c5e5",
    "d3dd83005fab87d395423e1be87a280e04cfafb559f5cdef9938ff34ffc2b698d1765188f3637ab3413cc8193c88f393191fe6ff567ec9ea6b9ad8fc7f5abc7e"
    "78eb22d377af3f986b7ee0f23df1e13f3e5d52cee7072ede7ae13ec483dcee0fd453bf72cc6be1a8b8928f48f9da61687b5ff3d0fe1ef007567ec9e68b9df507",
    "a3a29ee00fecf883cb329e4efa831f833f70bf3f6832e5482e74b0731aa945dbf1652617e6c2850deff803c8174feecd66d1bf2f8e88d9f7a78df7cf8ae7f4fb"
    "bb1e8e0b425c7f8e7810d72733feacf3b33c724c21e7997457bfb7455dedeffc35663cbbf2fa09068f46e893eabbc5788951917245a4f20e8baeebc64cc137e9",
    "04eb3e4d12e702befb7cf1d9ffa0ce83ebfdc439c7c85169275469379bc10d7f3657df3b0878c84f0c30d7db956305333e8dd049f9097d05506d0832d3ae9a45"
    "6e2887f5705081f77d67c49bdbfce2c6bc3f02effbce130fdef72533feacf19f03ccf834422765ff25b9bdc3ece4d4f4f0d16e0e8dbfb3f1fd0362f19f69f5db",
    "784d6224cabdeff9a6b178563a81f8fe48528b98df431c688e784ebd0f761aede4c4f0d961d8bfab063bf100b7d6157728efd877788e27f33fafefbb40fd361c"
    "9e950ef5db9e164f6fb7050feab791191fe6f7937bb3e1e6f71798f1eccaed7b183c1aa14faed3df1064590f6cb9d50fec61f1ac74b275fac7721bcf211cf403",
    "afc27b00eef703b5d64afe5012daf5a22c263bd266a8968c6d79689fcf8d8dd7dea47cf0c50eb1b8fe773078344247ec3fa7aab2659fe5d18c7c3cedbece1b39"
    "ffd7864c72759f6ef50ddb8fba80b1e41c9dffcb83c790df75bbdd974ae502132c6f5642dd6e2779d80d84c42dde4375fcddf27d96230c1f64ed3bb9efafbc88",
    "c1a30d8aca0d8d96c22d6cfe3eabbfdfc6e259e9b3c7fd0c4939fe7dad8bff2cfd0be6ed6eb7df69fff15ae72c1a92fc21ff4eaf1d48b25c5ff050fd1e788e27"
    "f36fd5bb7789cddb5fc7e0d1081d99b74b8cdae425b67532abbd471b8e0fb391dac7f5b32978269df8bcfd5272bae23868ff9f7f77f7af60ffe784e794fd3feb",
    "f7d26b4caad15cf6b3b9a45c3c4e75223d0fd9ff01e67ab73ed738bdb0ab87cf63eec7fc3ed7eb965fdf5cd7fbc746ff2eb1f9ffb4fd3b6604dfadf37f67f2fe"
    "8d8e742d663f6a0edaabf7128f61feef76fbbf7a1ac9954e85c4f249ac552a6c14dba789049bf28efd87e77832ff56bd7b08fb778cdf6f64fc1ef6ef5cb6db82",
    "07fb77c88c0ff67f32fff3dabf7953f6eda0cd6e1c08f6ed4ceecd06fb769cc1837d3b64c607fb3f997f9cfdff10339e5d79bd8dc1a311faa43a0ed692036929"
    "2f302c679c6ff2a7ccc8dfa2eb39d4a6e09b7482f51c268a7501dfff0af59661bf8fdbfd45666b9b2d9fe6d7a2e56c58d5820a1fec46b63c54cf019eefc9f765",
    "4f1f973cb78e58541c09d611f3c2d3db6dc183750499f1675d47dc8e7d442b97f67fd67a708f3078344247d7119ac6a9ed7d46e0eb45fe9c8baa4de3bc45f981"
    "c18c7873ab0f35793ef135f12d601ef1e927afc03ac1edfe20cbd7d2c5ad6445d91437926b6bb142b777bee6a1f7020698ebe1b9b636ebfb03eb9067367e873c",
    "f3e4de6c906776060ff2cc64c69f356ec421c714729e499f9f3f78c46b23fa70508172581fd7cb8eed2b1ddd6483827da576ea490d250575e13c86e794bd5fee"
    "6785d449b77e9c5e39ec6fd5d560582aaec0bed25bf41c8f1ad48583f9be956f98ef2f160fe6fb64c6f7c87cbf2677a4ba46393ddf2f10f30b3fc0e0d108fd6b",
    "7ec12890171786b2a1dc5b2f681f8b67a593f20bd7c5e6f077c3beba0bdf8374bd5f4849997c2c7ab073ce8bfddcb1521773ed9d330fe505c02f4cbe2f7b7e61"
    "8f581c68dafc1cbe070fdf83b7e2e9edb6e0c1f7e0c98c0ff67ef27dd9d2c70b67ed3d7cef1dbef77e53ecafd378f0bd7732e383bd9f7c5ff6e6f7fbc4e23edf",
    "c7e0d1081d8dfb4875ae9f96dabb9c202b23faa2de331e3c239e39fed1143c934ebc2e9545828ee605f6c212e405dcee1f3299543c12cdaa5b8d8ca889f9562b"
    "7a1838f7d07ae04bccf576e5f80bccf834429ff773fd48ff42303b8af35659596a33bca455cd93cca8b9c3fafa0547cc7f3cc0e0d1081df11f63a96487bf0906",
    "ddad79835d2c9e954e661e7225b605ac2be0fdb239e239e537baaba17084dbdace35126bed4a84d9cdc479d143f9e4bf63aeb72bc73e724c21e799f4b9fb0d5e"
    "ab6a7c53e2ea5667e1a87e0e58882bd9c483b812693cbddd163c882b91197f80b91ede27b336ab1e6e809db78907769e349ede6e0b1ed87932e30f30d7839db7",
    "366b9e380bfb826ce2c1be20d2787abb2d78b02f88ccf803ccf576e558c68c4f237482f5821e751975fcd199aaa2ca75e47e8e30fc92d5c3abb8cd05663cbbf2"
    "7b03834723f4a148aa434b566dc8aa20cb4a55ee726a43907b55b6c5b127901f7ea2fee8d38627c8cfd1fcf0479fdf03bfe076bfa06d27fbc9c4f9797eab1f0c",
    "6783fe78211af07be07b64ff07f0866bcb", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 75528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
