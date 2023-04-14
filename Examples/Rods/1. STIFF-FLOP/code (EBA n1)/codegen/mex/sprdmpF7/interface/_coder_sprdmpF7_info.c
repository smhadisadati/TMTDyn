/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF7_info.c
 *
 * Code generation for function '_coder_sprdmpF7_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF7.h"
#include "_coder_sprdmpF7_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF7"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/sprdmpF7.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737560.59438657411));
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
  const char * data[32] = {
    "789ced5d4b6ce3c619e6e6516c10a411d0368fa68fdd345824d8c4946cf91534801ed6cb6b594fcb5e6f529b122989325f222959f2a53ae690437aef21c73468"
    "8bb4972cdaa2506ebd16687a682f8b16452fbdb6e78aa2c636b99a886b52b428fd3f608ca95f9c6ff4e3e73733fffc33246ea4d2370882f8e6e0efa39f12c4c3",
    "75ed8a205e2074f18dcaa708a398f5374665d0748de459e219c37d3746783f1f5d574441653aaa7ec1b102b3dbe2cb8c3cb810289e39af86167956a004b5d895"
    "18426614916b33f450536539a6c8f2cc8e78e922c90e2ef8f825d5f985a6d2fe8fd699ca49a1c513725db9682e77f98218d947933ee6f73f63d13ec718fbf84c",
    "fa07b10fc8bac833649da259b2405519321d4b8495ae502193da47c57471ab2b90519166d0ff1146a5c87660c94fe6455a21034bb70ac5543cfe4e7c2793252b"
    "da171549a67929bebec4a3dfd3c1b4f71b167fcfd398dff3dca87ce5f287bd6c48ff67432f7b99106a470f8363d5aeb730edf099f49a19e42576e06cb240714b",
    "0317aa53125360cf744750507b8eafd81eb3e0da8304e13dbc221eaabf30010fe91fa4760e06aed5526492132b1447a6c3c59d7084cc2ffb031b65521545ae2c"
    "764886e7867f7787f622ef2283918f196c8937fc8e634c3badfa93b944f21c7173f45fefcfbffcf4af61f7f07459143c1c1f58f5c39730783e937e2de1e7d6b3",
    "ebb96c2959524afb6bb57bf9a6ba75d18eec049c49ed2030d76ed50fcff3f81289d1ff6e859cf2bf574cd784e97b486fea07044aaeb142a57ee255fe2f4dc043"
    "7a8bfe32700a99a149dd5b463e63769d739b692ee322ff7febddfc5f80ffa784e716ff773ba7a94d2a5eadadfa2b99985868c45beba731e0ff597b9e5d9d1f10",
    "6f87f4f2f551792764978f11eeb39876f8469a2a278ada6cd329bc6f98ae2ff0740d2db6ca1c7381f7a94dbc2816cfa87f82f102c796499e5239aa4c325cb525"
    "90431bb93f3ef872efce57c0f753c2738bef379aeb996293db5a3d89d48bb944416d6e6d55e2f3c3f7f0fc1a0537beef61eab36aa71f62f07c26bd697ccf2a91",
    "16cba92961b7c533325bb9369eb73b2ec863f18c7abbf342b3c1466ee3e638ff8bfffe0d78dfebbc9f6937a3e16ab2bd51cc05bb95182f2cc70fb924f0fe62f0"
    "fe1b8ef1fe6b183c9f496fe27d65602a4a5e42a37bfbe37bb3588def7c7e453c547f66021ed2dbe5fdbbbac5ce7dc645beff6cff55e07baff37db9be963d1038",
    "952e887cac252457cab1c87602f87ed1f8fe634c7d56edf41606cf67d29bf89e9224ae5b185258bc2554545614524296a32a288500b54fb2d9be1727b40fe9ab"
    "a3561cd529811e4c049cca23787f023ed2dbed0ff006d51dcc3dffea979f6fc0baafd7fb0791da6994292a11a557361acac132933e94ba73b4eedbc7dc0fcfb5",
    "518c7ef8b66371fe9ba66be2fc7bba865514899215c6ab71fe2416cfa8bfdaf841b38d36824056bac8133bc6b4cb393f08dd7cef27c0ef5ee7f7d3fd9412e74e"
    "4af1e5aa5ce0da8dccb670968b02bf2f36bf2fcd5d1ce8aafc0f71a0f1ed8738903b78100772a67ec8ef1c5f2231fa9fff9cff3fc4d467d56eb731783e93de1c",
    "17521446564b14c7d29a29c2726df43dafae0317b17846bded71c46386733deef354f414e6055eef0f96974fce36b7e291546da753383c4b96939b7915f23d17"
    "f0791e482f04f11e8b7810ef710a4f9745c183788f33f503af8f2f9118793d0c799ea3cf21cf737c8904f23cddc1833c4f67eaef63eeb76ac7234cfd3e937e1a",
    "fdc06d56d1f43599e2dcf5c3fe7dd7f66f693fb14ac0fe2d5c5ed8e01f726823f7cf6b7808fcee7d7e5feda4b9f8499b6ea4d60e3adbb4bc1c140a6bb07f6b01"
    "9e5f4d9ccbe387713d0ecfa88771fd93e2e9b2287830ae77a6fe3ee67ecf8cebcb624ba01597c7f539c7fa83ef63f07c26fd63fd414a9bd13072941b5886706e",
    "dcff8ce9faa23dbaa652a78609444ee5f3644dd784e97b486fbf3fb86c3057e3fc1fbdf41cc4f9bdde0fc4859d6c24bcbf7bc6f29d4c43a2f98cbadb9da3387f"
    "1f733ff4034631f6037b8ec577268dc30706e0a9cef5f1bcddf9e11616cfa8b7353f1cdac8f5fc9c872f03bf7b9edfe5a65f6ab04a30ccaf65d7856cf960e55e",
    "498900bf2f34bf132557f99d1580df27f13b2bb8ceefbf077ef73ebfd7a8fbeb9995fddde67a39ac4657a94c9009e6201fffbcbe85cad32192c0eb16f180d79d"
    "c2d36551f080d79da91f787d7c89c4987fb90bf1188b78108f710a4f9745c183788c33f5ff0973bf553b5298fa7d26fd14f6cfde6e53f2f0a8fc23491669d3ef",
    "3ac6b4db599eaf38b6fefa030c9ecfa41f18e7686094a3aa2873a2281d896d46ae72e2e95145b3caf59dabd9bf221eaaff70021ed25fb11fd0ddea6b2ce77e5e"
    "4eff0fff7a16fa07aff70fcabd5827b6757696ddee2c07d3cbfe682e1cf0cfd17eda4798fbaddab187a9df67d24fefb9befdf55f38aa339cc4c8eefa69c2b1f9",
    "c1a4f13aab54b5776f3af65cbc8cc533eacd794202cd7452827ade8e4f6cb62334a11d48ff847e55653b0c2d898376939ae5dccccf21203f7f8a786ef50785ae"
    "c4f2abcdfc7e802dd3c1d4612e9b0eb4e7e85ccd4f30f72ff0734b5c3e5747c2d467d53e2f98ae09d3f7909e55043da15cd5dec0ecddbccb1416cfa8b7e30f97",
    "2c8586f96ef2d0afe01c35eff37a62e5a45b68d6582e5a8c9ee49b915af1642f3647bcfe08733f8cf3c7ff5e6b7e9a8275008b78b00ee0149e2e8b8207eb00ce"
    "d4ff08733ff0fff8df6b6d7dc05dfe87fc1ec8ef41b2287890dfe34cfd7dccfd56ed788ca9df67d23f183cbc759167c83a45b36481aa32643a96082b5da14226",
    "b58f8ae9e2565720a322cda0ff238c4a91edc0929fcc8bb44206966e158aa978fc9df84e263b7c893aa94832cd4bf1f58bb84f0fd35eab7e88e33ff4bef45b86"
    "4f77433a68582f891f8fae9d3b5f73d2b93b9278ca78f9bde9612c9e517f35fe1725851c5ae81ae23fbd8fbe5a03fef73affefd74bcc5a215758cd1773ad83ad",
    "7b8725b1b03747fb6ebdfafce2e2ed56fded294cbb11cffb0c9fde09e9e5eb700ecfe8733887677c8904cee171070fcee171a6fecf31f75bb5e336a67e9f496f"
    "bb1fb85de55434e8255cf6bb5e3ae494df5d319f467f2b54ac766dbc3f837e3296f791a1ae81ef7f7d07ced5f73cdffbf3b5405bddde14e55a5d29c4a95a249e",
    "9aa77c1e788ec7b71fc7f7b8f98657f27bdce679c8ef711c6f288b8207f93dced40f3c3fbefd389ec7e159b5d7e4f76155d9c1a4a6eed578fd94d66b4d79bc9a"
    "855cdfbf0d7c3e453cbb7cfe1d0c9ecfa46f379998d4ae289b07a72ba298550a8195fb87c4fcf0b957e2ae177c7ebbcaca8aaaef4672d9fffac7b04f7754f6af",
    "8887ea877dbad3c6d36551f0609fae33f5437f30be4462f0bf47c78e8df39f74ffad5dbc271de77f62132f84c533ea3db45f0ff6d94e110ff6d93a53bf07f9fc"
    "8c9145a5651a9fe1e2e553c9cfe9bf1f1a96a10f5ce3f76a8be3b412e2385ff75e73cd4a6ec7717abf81388ef7795e5d5be6f35bfb89fae18a78d656d37c3c1d",
    "50e788e767302e3f7bf936c4455cfe434c7d56edf52606cf67d29bf26d2849e2ba1156a0e46e61d8e3c55b42456545c1a975e11727b40be9ab23dca33a25d083"
    "8ec0a9b8ce8309f8486ffb7c569c21dd7f1fee6f7f21435cc7ebfd432e17554fb20dff7af970f7de6eb9486d64d24a7c7efa873ee67e78ae8d62f4c375c7fa8b",
    "1f61f07c26bdb9bf688b2c1d9665aa1be72855650456a80dbf775d717fbbf3c9d2043ca4b7ed47630ca7b9908bfed3fb5f19fa05aff70b67dbc995e89e74c0e7"
    "ca193a7c504da63b7c668ef2f467f03c7eccbc418f101d553991528fce6710eeaeff1e42bebe4dbcf9cfff827cfd69e241bebe33f5dbe5fd1ca67e9f496f9ff7",
    "0551dda57633f2e87dd7a6df718c69a7b3f99cfbae9dbfc02a022510de5d078862f18c7a5be7ef6836723fce03ebbd53c4732b9fb3196e65f860f720e8cfcbcb"
    "ad6880d96cf3bbc4fcf03a3cbf4631fadb1b70dec2e873afe405c0790bf38d07e72d38533f8ce7c7974870e3f91ea63eab767b0d83e733e9c7c67196aa9c28ea",
    "16f06a3c2783c533eaedf60377758b91438b0d3a0117f9ff33c8fff13eff97eb6bd9038153e982c8c75a4272a51c8b6ccfd1b99b3318979dbdfc9f4befd3b5eb"
    "77dfc6e0f94c7a13ef33b22c5a5ab798d6f9ca3336ee5706cd63685267fb11e79ba97f68b36b18f7fff1de7d88e37b9df73b42eef42c2df19144732bae6c44b7",
    "9b6dd13f4771fc3ee67eaf9eb72c61da3b9d7338d179cb5baee5f92b4d59d54aafc6f723583ca3feaaf1412dcb5fb391fb7c1ffa72ef0e8cf3bdcef7c144ac5a"
    "f7afa51a99d84a4acde604a11ddd9aa3380f3cbf4631fadb1dc7e23adfc3e0f94cfac7e2fb5b224fb142cc3ccec7f56b6ee5f57b25ce6330a0bb719edffd07f2",
    "353dcfff5c9aa7f91399494bd17d75436cd1d5fb2d768edeaf05cff1f8f61bfd6ecdb1f1fce4f3d7b4bda90ae3d5f17c128b67d4dbdbb78bace4e6f90ca19bef"
    "411ea6e7f9fc743fa5c4b993527cb92a17b87623b32d9ce5e6e87d29c0e7e3db6ff4bbf7601fd648601f96b1dd16fc07f6614d110ff66139533fc4758c62f4b7",
    "3761ddd6261eacdb4e0b4f9745c183755b67ea07be378ad1df961c8be37f1783e733e9c7e767a2d5daeb1be7db9d1fee4ec0437aa7f23391cfb8e72ffd2ffef9"
    "6f58b79d55beb7ba2f6ba3b553f09756326139b512130eb6f36b427e8d00be5f34beff18539f553bbd85c1f399f4e3ce65331e389412b21c556146df9f9575dc",
    "be4dfcf727e023bd23e7388d35a8dbe777f6cbcf37603e30abfd83d5f98048ed34ca149588d22b1b0de56099491f4add399a0ff431f7c3736d94799f27207cb7"
    "f771c13cc1693c5d16050fe609ced4dfc7dcefd57c7edc78deaa1fe27810e5f3fb2f7fd8db0ee9ff8cca5e6a748dcae4e8f3a463f9414f63dae71b69a8b2322c",
    "bd9a1f14c6e219f576e69d031b5dc3fb76fb7dc8f79fddfec0eabca0592ed3d5a054ce14b30539270612096e273847f99ef0fc1ac5e86fb7e03c9fd1e733b63e"
    "0ce7f9cc080fbb8d07e7f938533ff0be518cfee6778cf75fc5e0f94cfaf1711f34baf7eefa707a021ed23b15f7413ee3e238ff677f7f17f8deeb7cdf584de46a",
    "74ae94da8cef06364be5dc6aad9a9da37d00c0f746c1f1bdddfcffd731783e937ef2fab0febd595917b63bfedf9b808ff453583f72bb3ff807ecf3f57e7f70af"
    "1438118367558a3e3dddcf2f07d39bf1bdfbf01ef6057c9e355985fd612381fd61c6765bf01fd81f36453cd81fe64cfdd01f8c2f9118fdef627db787a9cf6bf1",
    "a1abae0b407c687cfb213ee40e1ec487ecd5ff7f36fc33c0", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 79824U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF7_info.c) */
