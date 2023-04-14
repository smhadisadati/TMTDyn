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
                (737430.88297453709));
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
    "789ced5dcd6fe3c615e726d96017411a026df381a269362d160d1258b2244b768a00fab6645b96646925db49aaa5244aa2cc0f89a43e2fd5b1871c72eaa9871c"
    "93a22db6bd7481048572cbb1059a1e7ada4bfe84f65c5124b526a359c9264599d47b80311e3f717ea3e7c7dfcc3cbe1962b792a95b1886fd60f2f3ca6f30ec1f",
    "3f946a18f632260bae94cf615ad1eb6f29e596aeaeca6dec05cd75b714bcdf2bf50ac78a645f942b34c592c71da64cf2930a4b30e4ac992ac7502cc18af9418b"
    "c47852e0e82e599d6a6a144de629863ce22e5512d4a4c2c42fa966154925fd1e6990958b5c87c1f886f0b4bbf4e50aa6d84792c788efffc292f6c922ec83ebf4",
    "1fc63e763538867435882ae54ac5f643c280adb812522dd411b97c2a1f1db0ae0857252fd7c3a448b8badb5b6e5745d2d49aa58b124388f12d46f73d1e22faf9"
    "e292df435faa7217bb73a9b61d5c84b7acdd9e47e0e18aa6c2c9ff30b3f05ed4d59fe2c99a2ad729d3e453bccf0de28590785afd87c9a3d3896b7404de457315",
    "8276a542f9a350d875e2716fef965d22c7d165aeef2219da455365d7e47f4f13651749d73aecc4258475f8c1d70fee7f1bb2d6efacf6f3f5e1f511ed2deb77af"
    "22f0709dbe95ef37036931e30fa4897cae99e7f7071536fcb41f9905388bfa8121ea56b50ff7af56b4fef68b198f8f10ed2d6ba7371078b84e2f0d5ffc163599",
    "14f02c416f09135311fc96caf2c6795e2fa8fea8a2e23dba269eda7e6a019eaabf829f483fef4eede57a573598eb5dd962339fb1ce5f82fedf7d017c6f77bedf"
    "e58f04225b499d15cb67a7e570d8efabd549e0fb8de3fb4f11ed2d6ba7771078b84eafe37ba2d5a207b92985c53b6c45a43836c96668a2a22e05d5feb50cf6ef",
    "9505fd53f535a517a506c15627137f157f6c10ffa305f8aadee8788036a8ec62d6f9d7b8fc52f3df303eac08cfaaf181238e9a6582d88f54bdbb4de1d443a6ce"
    "5b83a873c68731e27ab8afb5a2f5c3f74c8bf7dcd1d5b1d9e7640d25082d821748bbc67b12483cadfe7af307c936d20c42b5d21663e1fcffce07bf067eb73bbf",
    "f78a49214e5f14e29e1a9fa3bbcdf4013bcc4680df379bdfb71c1707ba2eff431c687eff210e640d1ec481cc69df29cf73bf41f47359ff7b595757e5ae52362e"
    "ff711409cabfa865482e4741a5ae94a3b052f729e5af94d2abe8634afd7da50c28e59e69eb88dbba3a36fb9cac6971bd6996815dd711ab8d43722dc135b5d01a",
    "e290a34fbef5c33ac2eee347b15120fdb96c6ee7249fed9c460fcf0b5cee8183d61176bd7f5171f365fded395d5d1575bcc0357fbd1f94cbb74d5b3ffc0c818f"
    "ebf4baf50325843b142d26d9e30e43f254656dbc6f74de7182c4d3ea8dae1ff406531dc9c271e06ffffd0fac23ec3e0ea4bbed48a896e8eee6b3be4125c6b09e",
    "f8399d70ce3860341e7080681fd7e90d8f03f76ab4a84e7a318bfd6e940a9ae577af21f0709d7e6efc2856b76ddc68057e3297f75543ad81efff7c1f9e1fd89e"
    "efdd27f5edae78b0c7f1f586908b13f5703cd975d0f361b88fe7f71fc5f7a8f5c6b2f642c5a7709d9e125879a22a4a3b44ecfb7c2089c4d3eaaf381fa8517db2",
    "dae226eee1d2586a1d79667f2abe01f37abbf3fcbef762906bd7293a928f5c9cb4c3f5fcc58318f0fcc6f23c0acfbcbc9f1a3559d434ec1aaf8f22f1b47a23bc"
    "2e5bc8f2fc00e0f315e219e5f31f23f0709dbedb2663ad6e45d83bed79392e23e4b6bd67e79873f8dc2e71d7a77c7eaf46f18258a3b4dfe321a29fa6fadff8a1",
    "69f1fa371178b84e3f3146696284528de3698e6b95b82ec9d768ae57aa48fbb4d7b7ef6b7c4d3cb5fdf30578aafe9afb4564377a86e5ac9f178cbffaee36c471"
    "6eea78b0ecfc5e388cf563d1e13073d0f7f8521e77241bda76c79c331e3c415cbfac1d4788f6719d7e75f7f5bd677fa0d420e916c95beba7fba6ad075ed0d5b1",
    "d9e7648d34db95ca353f57a0d82ad94fb2e2ac1f9f19ec4770413f54bdb1758295fb02b0c7f01cd7fee3416ed0a2989df649719b2a577dc9f36c26b5eda4b8fe"
    "6788eb37f8be9d88db3171fc45e349a5414c9f8c431c7f7ea90ac47dacc18338be39ed3f415c0ff3fcf9df77393f4d9a36cf5f14879f7c7186e8af6f1cb8a171",
    "ffd97921935f5cb28d2c3fcfe1f16b7721ce6377fee7dbee5693127c21c69f09b099f2a9f7b02038689fd713c4f5c0fff3bfef527e3ab296ff2916f87f11ff53"
    "ace5fcff25f0bffdf9bf4e9c05d2dee2713b500e89911d22ed237dd97de7f03f3cf79d5faaa2f1bf270f4de3f5abc6ef8de25d359fe733837841249e566fa378",
    "1fc4e9578807717a73dab7219f0f499e133a8cf67ba0e2e92bd9873bfe28382d831f5bc6efb50e4d4b25e46b3eeb9c36c94a56cfdb477f81b8bdfd795ef47b98"
    "936871bf71eee5865d31c5c453dba28378fe11e27ad8577bd9ef9ee6dfff16d1deb2f6fa25020fd7e9e79dd71ca65882d71d5667d673e3759fd3fce1027c556f",
    "ca797ff30ca93cd9b5707cf8eb173cc475ec3e3e64b311f122d37407cae7c787c7e53cb19b4e0971e78c0f63c4f5705f6b45eb8701d3c68b9f23f0709d5e3f5e"
    "7439aa1ae2796210a7095124598aad4f3fb7aefc7ea3ebc9c2023c556fd88fe6184e72210bfd67f4bf328c0b761f178607096fe441eb94c996d3d5d0692d91ea",
    "3369079dc763f47ece23dac7757ae3eb06394254aad11c2196662b086bf7799dc3b93c06f19cbfcf1bcee559251e9ccb634efb969de76c98f7594e3c268ed37c"
    "72726bd7d5b091c5e736144d7b0eb0e89c654a600916b3ef738008124fab3794bf23d9c8fa380f3cef5d219e55e736b4439d34e31b9cfadc27bca713d926f7ba",
    "cc31e61c5e87fb572bab7a3f2f9cab8cc2d3eae15ce5abe2c9b2297870aeb239edc37c7e7ea90a6a3e3f42b4b7acdd7e82c0c375faf9efe7aad11c275bc0aef1"
    "9c34124fab37ebfd5c538b4d06010bf9ff0f90ff637ffe2f37fc99539616ab398e8975d884b71c0b1f38286fff06c6656f5efecfe8d8b4f8fd8f1078b84eafe3",
    "7d92e7b9a59e5bac6a7fd60d9bf70b93ee915597ccf60ae7eba97f6ab335ccfbff7e7806717cbbf37e9fcdf686a91613de6f47e3c26ee4a0dde5dc10c7bffabc"
    "7fc5ef657c88e8a7b9feb76b5a1cff79041eae680469132e66df387e0889a7d55f370e2865f30bea265ccc4a3f087efde03ecce7edceeb0491089ff72e125421",
    "15e9d0e1301b0d648e1dc4eb70ff6a6555717c63ef5757597e7df99846d77da90578aadeacf88dea33d6f9cb3808ef57b73fdfbb7712fedd48afe871877b3dda"
    "dda27dd1fad041e7ee00df6b05c5f79f22da5bd64eef20f0709d7edebe2ded8684249ba1890aa97cde29fbb73e5a80afea4dd9e731d7a0969fcb537ea909711e",
    "bb8f0f1c71d42c13c47ea4eadd6d0aa71e3275de1a38683d30465c0ff7b556b47eb8e5b875c275e341b04e98df7f5827588307eb0473da8778fffc5215adffc5"
    "4de3ffb71078b84eafe37f9e141a448bcc514332229d3e2ad875df6e6e019eaa37caffdf3398f579fefffce3e7b01eb0fb38e0df77d3814c209b29240a42a1e8",
    "af1f9eb49d74de0fdccff34b55b4fef79669793faf23f0709d5e370eb0045fa7d84ae3c2aefc6ff2b90dcbe4fdcc6c66edb90da31fbe7ff22fe0ff15e159c5ff"
    "837e2fb947c46bf51d77251de372cd7827d073d0fb189d723fa3fc6159ff43e5e1a8e77abeaef9eb7b41b97c5b29ef5bb6af57cdf4b76b3ed0aaf7054e4ff754",
    "72fb25b1909f201f68857856f1fd6e3b90ceb7e9e8ce45b891cfeee7c476345a71d0f96d70ff6a0535bf1f21da837dbdcbe1c1bede55e1c9b22978b0afd79cf6"
    "81f7b5b2aa3cd09bb28f572fcbc6771e5d134f6d1ff6f19a8d27cba6e0c13e5e73da07bed70ae481ceef1fe481ca0279a0f6c0833c5073da1f23ae87fb5a2bab",
    "ca03bd29eb84ebc687609d30bfffb04eb0060fd609e6b40ff93ff34b55b4fee79ef1bfd1f7b8dc43e0e13abd7edd2008242f16089aaa4aa608f175e573767d4e"
    "b082f73ecc9f477ccf7096af0b9e8bf4605d60f7f1c0e3b918ee45e3e164fda89f3b1f26ca89bd1311f28136f07e9ec828685adecf1d5d1d9b7d4ed65082f4ee",
    "5a81b46bde4f0289a7d51b7bafaf6a252bdfdf1ebcf301bca7c5f6bcde2b2685387d51887b6a7c8eee36d307ec301b015edf4c5e0f411e90f277c8039a5faa02"
    "7940d6e0411e9039ed8f11d72f6bc712a27d5ca75fc538708f12247d9d27686bfd707c66597ebff4156b18e4f73ffbbd3f131bc17bbb1c856715bfeff45374fc",
    "a25b6d26fda7fd832aeff1b1393fe4f76fc0fd2b09bcb70be6f5da7ec3bc7ebd7830af37a7fd31e27adbccebcb5c87ad0a16cfebb3a68d073f45e0e13afdf7c6"
    "03e5f565117a6219ccbc79ff55dfe7f2c8205e4657c7749f53f5c6c783cb06b334ceffc9ab7721ce6ff77120ce1e65c2a1e2f19062fae966abcaa4c5e38183e2",
    "fc63c4f5300e68453b0e3c302dbeb3681e3e310043f4d7c7f346d78751249e566f687d38b591e5f9398f5f037eb73dbff36d77ab4909be10e3cf04d84cf9d47b"
    "58101c746ee718713df0bb56b47e58b094dfa5439a81df9fcdefea2b202ce4f72f81dfedcfef75e22c90f6168fdb8172488cec10691fe9cb423efeacbd8dcad3",
    "c112c0eb4be201af9b8527cba6e001af9bd33ef0fafc5215d4fbd55178108f9105e23166e1c9b22978108f31a7fd6f10d72f6b4702d13eaed3af60ffecbd2ec1"
    "4f8f522eb578aeaafb5e0f11fd3697e72ba63d7f7d138187ebf413e394264629d5389ee6b85689eb927c8de67aa58a6495f59dbb36be269edafef9023c557fcd",
    "714076ab6758cefabc9cf157dfdd86f1c1eee3837018ebc7a2c361e6a0eff1a53cee4836b4ed76c07edaff0336c90f2a",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70632U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
