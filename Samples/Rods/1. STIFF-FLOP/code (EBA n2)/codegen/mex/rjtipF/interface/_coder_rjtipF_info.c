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
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.7759375));
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
  const char * data[28] = {
    "789ced5dcd6fe3c615e726d9208b222d81b4d9f42bcda6c52245024b9664c95b2080647dd8b2ad6fadecf5269529899268f343222959f2a53ef69043fe801e72"
    "4c8bb6d8f692451314eaadd7024d0f3d2d5004bdf4da9e2b8aa2ede16a22da1cd1a2f41e608ce827ce6ff4f0f89b99376f86d4ad64ea164551df1cfe957e4151",
    "e1d7b42b8a7a95d2851e972f50a898f5b7c6e58ae9da90dbd44bc87db7c678bf1a5f572551657baa7ec173229bee0815561e5e888cc09e575393044e6444b5d8"
    "6fb194cc2a12df656b234d9de3d92227b0bbd2a58b2d6e7821242ea9ce2f3495f639da64abc7858e40c94de5a2b9fce50b6a6c1f4d9e607eff4b16ed93c6d887",
    "36e91fc73ff4342581f534991ae749c537234a5fac7ab6b4ab4847958aa962ac2f7aa2528dbd7cbdc1aa8ca7bbbae2f554358d7ca472adc48a70d1fe1ea67d2f"
    "5b6cff8b98f6df19976f20ff0d84f5d2372efd61a31d87181cab76bc8d69073dd6b4a49391f790c27bd9747d81a76b6a52a7c2b317789fdac48b60f150fde3e4",
    "eefed0553a8aece1a52ac37b5291e26e64c393f77957d72b1e5592f88ad4f3b002efe1b98a4760549ea978a496e2195948738d914cb39355ff309786dca15e19"
    "7f3afbe8cbe03f22cee1e9b22c78b8e7dbaadfbd8ec1a34dfabd66890d167285b57c31d7d98fed1c94a4c2c3e8453bb25370a6b583c25c3b55bf5b9fdf16a65d",
    "56fded05d3b52106bfd3c87fef87f5f2ed735e3fc3d46fd56e3fc2e0d326bdd6bdc92bdc70d0208b0cbfc2291b1d8e5793e270d8c0ca5cf5c678ffa94dbc3c16"
    "0fd55fc16fb4bf7747f6f2bc6b18cc633698e1480ef6039ffdf79f5f423f30233ca7fa814cb71d8dd4b7baebc55ca05f8d0ba22f71c06f2d4e3f6077bcbf8da9",
    "9f36e96df703f7eabc6a0c7a2987fdee2c1526e577773178b4496fe27f656832468e376e8cf7e7d04f26f2be61a81be0fbdfdfff398cfbddcef7de7c63b5ab6e"
    "3f90e44653292498c64622d98d01df2fcf734c217c8f9b6f58b5d7aba66bcaf43d43cf29a23e5055b5c8dfcdc575ecfa47128b87eaaf381ea8733db6d69286ee",
    "e1412c7503f11dea777bdf8571bddb797ed37fdc2fb41b1c1f2d468ff3ed8d46f1f8611c787e69791e8767d55eaf98aea9f3efe91a4ea973c3494dd3adf1fa18"
    "160fd5dbe175dd42ba27009f2f069e5d3eff0e068f36e9bb6d36deea569507fb277e49ca2a8555ffa3036a71f8dc2d71d70b3ebf57e76445ad73e8ef38c4b493",
    "a8ff0d0e89c5ebdfc4e0d126fdd018e5a111ca7549e625a95596baac5ce7a59372555b7fb73f9e370bae3d861878836be219f51f4cc133f4d78bef8ddde86b2c"
    "e7fcb860f0c557b7218e33affd81d5f1bdb213efc563a7a7d9ed9e2f90f279a3b9c8aa37be38fdc133ccfd56ed7886a99f36e967f75cdffbfa2f949b2cdf6265",
    "67fd7493d87ce025d33575fe3d5da38d76b5f286d71538b1c6f692a27ade8e4f6cb6233ca51d86dede3c614570d02f9ec23aaefbfb8342bfc5096bedfcde2a57"
    "a9059207b96c6a7591e2fa9f60ee5fe2e77628de8589e34feb4faa4d66b4320e71fcc9a52110f771060fe2f864ea7f86b91fc6f9937faf353f4d121be74f8bc3",
    "0f7fb8c0f46eae1f98d3b8bfe13ffcf08347b791d371ffc1d3bb7720cee376fe97dbded611a7042242301b12b3957dff4e49d900fe07fe47055df77596ff3911"
    "f87f1aff73a2e3fcff39f0bffbf9bfc13c0a65fc7be976a81251a36b4c26c006729b8bc3ffb0ee3bb93404f1bf6787c478fdaaf17bbb7857cde7f9c4265e188b",
    "87ea5d14ef8338fd0cf1204e4fa67e17f2f9292b4b4a47407f072e9e3e937db8830fc2a332fca163fc5eeff0bc5642bee6a471bbd262e47a47f46856727adc7e"
    "f60788dbbb9fe7d5a04fc8c7f6369b077ee9b4aba684446a555d209e7f82b91ff6d55ef6bb8bfcfb5f62eab36aaf773078b4496fca7f615a2dbebfc1898cdc2f",
    "8c7abc4447acaa9c24925a37fed6947619fafa18b7dc64c4dab0232095bff9780abea1b73b5ec01a72bcb2eb60fff0c75fcb10d7717bff90cb45d5e3ec913754"
    "3948efa42b45663d9352128bd33f0c30f7c3738d0aea872162fdc58f3178b4496fee2fba12578bc832d34ff08caab222273646dfbba9fc7ebbf3c9d2143c436f",
    "db8f2618eef2b97d87987612f49fb3ff55a05f707bbf70babde58f3e6ced0bb94aa616d9af6fa57a426681cee3b1fb3c1731f5d326bdfd79831e212ad7798951"
    "cbe7330867f7791dc0b93c36f1167f9f379ccb334b3c3897874cfd76793f87a99f36e9edf3be28a969269d9193c347bb61848d1c3eb7618fd83ac0b473963945",
    "6444cabdeb00512c1eaab795bfa3d9c8f9380facf7ce10cfa9731bda914e4608f4f703debceceb4457d9075d214d2d0eafc3f38b0aea6f3f21764e039cab8cc3"
    "43f570aef255f17459163c3857994cfd309e9f5c1a821bcf9f61eab36ab7ef63f068937e621c67a5ce4b926e01b7c67332583c546fb71f7857b7986764b16127",
    "e020ffff06f27fdccfff956630bb2ff26aad2009f18eb8e5afc437b617286f7f0ee3b2f397ff73962616bfff36068f36e94dbccfcab26469dd6256fbb3e66cdc"
    "af0c9bc7d63c3adb8f39df4cfd239bddc0b8ffcf3b8f208eef76deef89b993d3544bd8d86cc712ca7a74bbdd95bc0b14c7b7cbfb694cfdb4493fabf7271e62da",
    "47d6ef828ee5f12b6d79f4d24db7c6ef37b078a8febaf13f2d8b5fb391f37c1efecbc3fb308e773b9f0736e3f5a637983ccac4fd49359b13c56e34b640711c78"
    "7e5141fded3eb1b8cd0f3078b449ff5cfc3e26090c27c6cde3f896cdf6d8cddb774b1c0731a0b3719c3ffd07f2315dcfff7c4aa809c7329b6a45f7d475a953ab",
    "3fea700b74fe0e3cc793db3fabf1fcf4f7a8687b4f15d6ade3f92d2c1eaab7b72fd7b09293e72f845f791ff22c5dcfe7277b4925c11f9712beba5ce0bb47996d"
    "f13417053e5f2e3e7f1ff6598d05f659a1edb6e03fb0cf6a8678b0cf8a4cfd10d74105f5b777605dd6261eaccbce0a4f9765c183755932f503dfa382fadb0ab1",
    "38fef73078b4493f39ffd258adbdb971beddf9a1e5f57b42f99786cf38e72f83cffef56f58b79d57beb7baef6abdb35bf096fc99889cf4c7c5fded7c50cc0729"
    "e0fb65e3fb8f31f559b5d34f3178b4493fe9dc35f440a1a498e5992a3bfefebcace30e6ce27f3005dfd01339a769a2411d3f57bff28d23980fcc6bff60753e20",
    "31bb471586d98cd6fceb47cabe8f4d1db4fa0b341f1860ee87e71a15d40fdf83755e8b78b0ce4b0a4f9765c183755e32f50f30f703bfa3b2e871a0ebf23fc481"
    "26b71fe240cee0411c884cfd8e3dc7aede8f1522c6fb6f61f06893dec4fb32ab3499165be04ed9a8f65648c5ad793e85297886de2eef3f6730e7cf5ffbdb6f3f",
    "8579c0bcf2bfd5794070d3cb87b2a15cb6b455524a7bc1c64ebebd48ef6181e779726908ea7f6f11cbfb790383479bf4a67e4064e40627569bc76ee57fc2799e"
    "56f27ece6de6ecb8e1ecb59fe5ff0efc3f233ca7f8bfdf3b493e6012f5c69ab79a894b85a34427741207fe9fb7e719e70f56fdef45ccef30deb7f806f2dff7c2",
    "7af9f6b8bcd8e77b88c12175deb271029b5be3feb33eaf75f4d6c5f1996b9a38c84f705ec30cf19ce2fbf57628536cf3b1b5e38d6631b75950dbb1587581deab"
    "05cf2f2ab8f1fd19a63e386fd91a1e9cb73c2b3c5d96050fce5b26533ff03e2ab33a677f5ece57368bd5f8ce936be219f5c3f9caa4f17459163c385f994cfdc0",
    "f7a8e0f8fe634c7d90dfafcbc026fef2e589417eff2cf120bf9f4cfd03ccfdf05ca332abfccf7999275c373e04f384c9ed8779823378304f20533fe4ff4c2e0d"
    "41fdcf7bceff76cf7dbb87c1a34d7af3bc415158592d313c57d34c11911be3efb9759da088c543f5b6c711cf19cef179c10bd1139817b8bd3ff0f98e4f1fc412",
    "1bc9c66eaf7070ba55d97a9057211f68099fe7a19c8561bfaf453cd8ef4b0a4f9765c183fdbe64ea075e9f5c1a82f27a04f280c6ff873ca0c9a5219007e40c1e"
    "e40191a97f80b9dfaa1dcb98fa69937e16fdc03d4ed1f40d99e19df5c3c123c7f2fbb59f58a720bf1f973730fce019d9c8f9fdbc4f81dfddcfef6bbd149f38ee",
    "d68e92c1fdde764df605c44210f2fb97e0f9d5845c9e278ceb7178a81ec6f557c5d36559f0605c4fa6fe01e67ed78ceb2b5247ac290e8feb73c4fa831f62f068"
    "93feb9fe20a9cd685839ca0f2d43911bf75ff57d2e4f6ce2654dd794e97b86de7e7f70d9608ec6f93f7afd0ec4f9ddde0f24c4ddec46642f7dca09bdcc51ab26",
    "64d4747f81e2fc03ccfdd00fa082f6030f89c577a68dc387061098decdf1bcddf9610c8b87ea6dcd0f4736723c3fe7e95de077d7f3bbdcf6b68e3825101182d9"
    "9098adecfb774aca02bd6f7d80b91ff81d15d40f4b8ef23b2702bf4fe3774e749cdf3f077e773fbf379847a18c7f2fdd0e55226a748dc904d8400ef2f1cfeb5b",
    "aa3c1d6a0b78dd221ef03a293c5d96050f789d4cfdc0eb934b43d0fccb34c4632ce2413c86149e2ecb8207f11832f5ff1573bf553b3298fa69937e06fb67ef75"
    "1979749472b9254b35d3ef3ac4b49b2ccf5789adbfbe89c1a34dfaa171ca43a394eb92cc4b52ab2c7559b9ce4b27e5aa66959b3b776d704d3ca3fe83297886fe",
    "9afd80ee565f6339e7f372065f7c751bfa07b7f70fca4ebc178f9d9e66b77bbe40cae78de622abde05d84ffb7f588b09f3",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
