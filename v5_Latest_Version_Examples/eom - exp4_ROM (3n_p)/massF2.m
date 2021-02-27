function [out1,out2,out3,out4] = massF2(in1,in2,s,ds,t_sym)
%MASSF2
%    [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 15:53:29

g_x_ = in1(:,13);
g_y_ = in1(:,14);
g_z_ = in1(:,15);
l_f_ = in1(:,17);
l_s_ = in1(:,5);
m_f_ = in1(:,16);
q7 = in2(7,:);
q8 = in2(8,:);
q9 = in2(9,:);
q10 = in2(10,:);
q11 = in2(11,:);
q12 = in2(12,:);
q13 = in2(13,:);
q14 = in2(14,:);
q15 = in2(15,:);
r_f_ = in1(:,18);
u7 = in2(22,:);
u8 = in2(23,:);
u9 = in2(24,:);
u10 = in2(25,:);
u11 = in2(26,:);
u12 = in2(27,:);
u13 = in2(28,:);
u14 = in2(29,:);
u15 = in2(30,:);
t2 = l_s_.*q7;
t3 = l_s_.*q10;
t4 = l_s_.*q13;
t5 = l_f_.^2;
t6 = l_s_.^2;
t7 = l_s_.^3;
t9 = l_s_.^5;
t11 = r_f_.^2;
t8 = t6.^2;
t10 = t6.^3;
t12 = t2.*2.0;
t13 = t3.*2.0;
t14 = t4.*2.0;
t15 = t6.*2.0;
t16 = t7.*2.0;
t18 = t9.*2.0;
t20 = t11.*3.0;
t21 = l_f_.*t6;
t22 = l_f_.*t7;
t24 = l_f_.*t9;
t26 = q8.*t6;
t27 = q9.*t7;
t28 = q11.*t6;
t29 = q12.*t7;
t30 = q14.*t6;
t31 = q15.*t7;
t38 = (m_f_.*t5)./4.0;
t17 = t8.*2.0;
t19 = t10.*2.0;
t23 = l_f_.*t8;
t25 = l_f_.*t10;
t32 = q8.*t15;
t33 = q9.*t16;
t34 = q11.*t15;
t35 = q12.*t16;
t36 = q14.*t15;
t37 = q15.*t16;
t39 = t5+t20;
t40 = t2+t26+t27;
t41 = t3+t28+t29;
t42 = t4+t30+t31;
t43 = (m_f_.*t39)./1.2e+1;
t44 = t40.^2;
t45 = t40.^3;
t46 = t41.^2;
t47 = t41.^3;
t48 = t42.^2;
t49 = l_f_.*l_s_.*t42;
t50 = t12+t32+t33;
t51 = t13+t34+t35;
t52 = t14+t36+t37;
t53 = t21.*t42;
t54 = t22.*t42;
t55 = -t44;
t56 = -t46;
t57 = -t48;
t58 = l_s_.*t50;
t59 = l_s_.*t51;
t60 = l_s_.*t52;
t61 = t6.*t50;
t62 = t7.*t50;
t63 = t6.*t51;
t64 = t7.*t51;
t65 = t6.*t52;
t66 = t7.*t52;
t67 = t38+t43;
out1 = reshape([m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,t67,0.0,0.0,0.0,0.0,0.0,0.0,t67,0.0,0.0,0.0,0.0,0.0,0.0,(m_f_.*t11)./2.0],[6,6]);
if nargout > 1
    t68 = t55+t56+t57+1.0;
    t69 = sqrt(t68);
    t70 = 1.0./t69;
    t72 = l_s_.*t69.*2.0;
    t73 = l_f_.*l_s_.*t69;
    t74 = t21.*t69;
    t75 = t22.*t69;
    t76 = t15.*t69;
    t77 = t16.*t69;
    t71 = t70.^3;
    t78 = t15.*t40.*t70;
    t79 = t16.*t40.*t70;
    t80 = t17.*t40.*t70;
    t81 = t18.*t40.*t70;
    t82 = t19.*t40.*t70;
    t83 = t15.*t41.*t70;
    t84 = t16.*t41.*t70;
    t85 = t17.*t41.*t70;
    t86 = t18.*t41.*t70;
    t87 = t19.*t41.*t70;
    t88 = t15.*t42.*t70;
    t89 = t16.*t42.*t70;
    t90 = t17.*t42.*t70;
    t91 = t18.*t42.*t70;
    t92 = t19.*t42.*t70;
    t93 = t21.*t40.*t70;
    t94 = t22.*t40.*t70;
    t95 = t23.*t40.*t70;
    t96 = t24.*t40.*t70;
    t97 = t25.*t40.*t70;
    t98 = t21.*t41.*t70;
    t99 = t22.*t41.*t70;
    t100 = t23.*t41.*t70;
    t101 = t24.*t41.*t70;
    t102 = t25.*t41.*t70;
    t103 = t53.*t70;
    t104 = t54.*t70;
    t105 = t23.*t42.*t70;
    t106 = t24.*t42.*t70;
    t107 = t25.*t42.*t70;
    t120 = t61.*t70;
    t121 = t62.*t70;
    t122 = t8.*t50.*t70;
    t123 = t9.*t50.*t70;
    t124 = t10.*t50.*t70;
    t125 = t63.*t70;
    t126 = t64.*t70;
    t127 = t8.*t51.*t70;
    t128 = t9.*t51.*t70;
    t129 = t10.*t51.*t70;
    t130 = t65.*t70;
    t131 = t66.*t70;
    t132 = t8.*t52.*t70;
    t133 = t9.*t52.*t70;
    t134 = t10.*t52.*t70;
    t135 = l_f_.*l_s_.*t40.*t41.*t70;
    t108 = t94.*3.0;
    t109 = t95.*3.0;
    t110 = t96.*3.0;
    t111 = t99.*3.0;
    t112 = t100.*3.0;
    t113 = t101.*3.0;
    t114 = t22.*t45.*t71;
    t115 = t23.*t45.*t71;
    t116 = t24.*t45.*t71;
    t117 = t22.*t47.*t71;
    t118 = t23.*t47.*t71;
    t119 = t24.*t47.*t71;
    t136 = t41.*t93;
    t137 = t41.*t94;
    out2 = reshape([t6,0.0,0.0,0.0,0.0,0.0,t7,0.0,0.0,0.0,0.0,0.0,0.0,t6,0.0,0.0,0.0,0.0,0.0,t7,0.0,0.0,0.0,0.0,0.0,0.0,t6,0.0,0.0,0.0,0.0,0.0,t7,0.0,0.0,0.0,t49-t135,-t73+l_f_.*l_s_.*t44.*t70,l_f_.*l_s_.*t40.*-2.0,t72+t40.*t58.*t70,-t60+t40.*t59.*t70,t59+t40.*t60.*t70,t53-t136,-t74+t21.*t44.*t70,t21.*t40.*-2.0,t76+t40.*t120,-t65+t40.*t125,t63+t40.*t130,t54-t137,-t75+t22.*t44.*t70,t22.*t40.*-2.0,t77+t40.*t121,-t66+t40.*t126,t64+t40.*t131,t73+l_f_.*l_s_.*t56.*t70,t49+t135,l_f_.*l_s_.*t41.*-2.0,t60+t41.*t58.*t70,t72+t41.*t59.*t70,-t58+t41.*t60.*t70,t74+t21.*t56.*t70,t53+t136,t21.*t41.*-2.0,t65+t41.*t120,t76+t41.*t125,-t61+t41.*t130,t75+t22.*t56.*t70,t54+t137,t22.*t41.*-2.0,t66+t41.*t121,t77+t41.*t126,-t62+t41.*t131,l_f_.*l_s_.*t40-t41.*t49.*t70,l_f_.*l_s_.*t41+t40.*t49.*t70,0.0,-t59+t42.*t58.*t70,t58+t42.*t59.*t70,t72+t42.*t60.*t70,t21.*t40-t41.*t103,t21.*t41+t40.*t103,0.0,-t63+t42.*t120,t61+t42.*t125,t76+t42.*t130,t22.*t40-t41.*t104,t22.*t41+t40.*t104,0.0,-t64+t42.*t121,t62+t42.*t126,t77+t42.*t131],[6,15]);
end
if nargout > 2
    t138 = t21.*t41.*t44.*t71;
    t139 = t21.*t40.*t46.*t71;
    t140 = t22.*t41.*t44.*t71;
    t141 = t22.*t40.*t46.*t71;
    t142 = t23.*t41.*t44.*t71;
    t143 = t23.*t40.*t46.*t71;
    t144 = t24.*t41.*t44.*t71;
    t145 = t24.*t40.*t46.*t71;
    t146 = t25.*t41.*t44.*t71;
    t147 = t25.*t40.*t46.*t71;
    t148 = t44.*t53.*t71;
    t149 = t44.*t54.*t71;
    t150 = t22.*t40.*t48.*t71;
    t151 = t23.*t42.*t44.*t71;
    t152 = t23.*t40.*t48.*t71;
    t153 = t24.*t42.*t44.*t71;
    t154 = t24.*t40.*t48.*t71;
    t155 = t25.*t42.*t44.*t71;
    t156 = t46.*t53.*t71;
    t157 = t46.*t54.*t71;
    t158 = t22.*t41.*t48.*t71;
    t159 = t23.*t42.*t46.*t71;
    t160 = t23.*t41.*t48.*t71;
    t161 = t24.*t42.*t46.*t71;
    t162 = t24.*t41.*t48.*t71;
    t163 = t25.*t42.*t46.*t71;
    t164 = t44.*t62.*t71;
    t165 = t8.*t44.*t50.*t71;
    t166 = t9.*t44.*t50.*t71;
    t167 = t44.*t64.*t71;
    t168 = t46.*t62.*t71;
    t169 = t8.*t44.*t51.*t71;
    t170 = t8.*t46.*t50.*t71;
    t171 = t9.*t44.*t51.*t71;
    t172 = t9.*t46.*t50.*t71;
    t173 = t44.*t66.*t71;
    t174 = t46.*t64.*t71;
    t175 = t48.*t62.*t71;
    t176 = t8.*t44.*t52.*t71;
    t177 = t8.*t46.*t51.*t71;
    t178 = t8.*t48.*t50.*t71;
    t179 = t9.*t44.*t52.*t71;
    t180 = t9.*t46.*t51.*t71;
    t181 = t9.*t48.*t50.*t71;
    t182 = t46.*t66.*t71;
    t183 = t48.*t64.*t71;
    t184 = t8.*t46.*t52.*t71;
    t185 = t8.*t48.*t51.*t71;
    t186 = t9.*t46.*t52.*t71;
    t187 = t9.*t48.*t51.*t71;
    t188 = t48.*t66.*t71;
    t189 = t8.*t48.*t52.*t71;
    t190 = t9.*t48.*t52.*t71;
    t191 = t40.*t41.*t53.*t71;
    t192 = t40.*t41.*t54.*t71;
    t193 = t23.*t40.*t41.*t42.*t71;
    t194 = t24.*t40.*t41.*t42.*t71;
    t195 = t25.*t40.*t41.*t42.*t71;
    t196 = t40.*t41.*t61.*t71;
    t197 = t40.*t41.*t62.*t71;
    t198 = t8.*t40.*t41.*t50.*t71;
    t199 = t9.*t40.*t41.*t50.*t71;
    t200 = t10.*t40.*t41.*t50.*t71;
    t201 = t40.*t42.*t61.*t71;
    t202 = t40.*t41.*t63.*t71;
    t203 = t40.*t42.*t62.*t71;
    t204 = t40.*t41.*t64.*t71;
    t205 = t8.*t40.*t42.*t50.*t71;
    t206 = t8.*t40.*t41.*t51.*t71;
    t207 = t9.*t40.*t42.*t50.*t71;
    t208 = t9.*t40.*t41.*t51.*t71;
    t209 = t10.*t40.*t42.*t50.*t71;
    t210 = t10.*t40.*t41.*t51.*t71;
    t211 = t40.*t41.*t65.*t71;
    t212 = t40.*t42.*t63.*t71;
    t213 = t41.*t42.*t61.*t71;
    t214 = t40.*t41.*t66.*t71;
    t215 = t40.*t42.*t64.*t71;
    t216 = t41.*t42.*t62.*t71;
    t217 = t8.*t40.*t41.*t52.*t71;
    t218 = t8.*t40.*t42.*t51.*t71;
    t219 = t8.*t41.*t42.*t50.*t71;
    t220 = t9.*t40.*t41.*t52.*t71;
    t221 = t9.*t40.*t42.*t51.*t71;
    t222 = t9.*t41.*t42.*t50.*t71;
    t223 = t10.*t40.*t41.*t52.*t71;
    t224 = t10.*t40.*t42.*t51.*t71;
    t225 = t10.*t41.*t42.*t50.*t71;
    t226 = t40.*t42.*t65.*t71;
    t227 = t41.*t42.*t63.*t71;
    t228 = t40.*t42.*t66.*t71;
    t229 = t41.*t42.*t64.*t71;
    t230 = t8.*t40.*t42.*t52.*t71;
    t231 = t8.*t41.*t42.*t51.*t71;
    t232 = t9.*t40.*t42.*t52.*t71;
    t233 = t9.*t41.*t42.*t51.*t71;
    t234 = t10.*t40.*t42.*t52.*t71;
    t235 = t10.*t41.*t42.*t51.*t71;
    t236 = t41.*t42.*t65.*t71;
    t237 = t41.*t42.*t66.*t71;
    t238 = t8.*t41.*t42.*t52.*t71;
    t239 = t9.*t41.*t42.*t52.*t71;
    t240 = t10.*t41.*t42.*t52.*t71;
    t241 = -t191;
    t242 = -t192;
    t243 = -t193;
    t244 = -t194;
    t245 = -t195;
    t246 = -t197;
    t247 = -t198;
    t248 = -t199;
    t249 = -t203;
    t250 = -t204;
    t251 = -t205;
    t252 = -t206;
    t253 = -t207;
    t254 = -t208;
    t255 = -t214;
    t256 = -t215;
    t257 = -t216;
    t258 = -t217;
    t259 = -t218;
    t260 = -t219;
    t261 = -t220;
    t262 = -t221;
    t263 = -t222;
    t264 = -t228;
    t265 = -t229;
    t266 = -t230;
    t267 = -t231;
    t268 = -t232;
    t269 = -t233;
    t270 = -t237;
    t271 = -t238;
    t272 = -t239;
    t273 = t21+t191;
    t274 = t22+t192;
    t275 = t23+t193;
    t276 = t24+t194;
    t277 = t25+t195;
    t283 = t16+t214;
    t284 = t16+t215;
    t285 = t16+t216;
    t286 = t17+t217;
    t287 = t17+t218;
    t288 = t17+t219;
    t289 = t18+t220;
    t290 = t18+t221;
    t291 = t18+t222;
    t301 = t108+t114;
    t302 = t109+t115;
    t303 = t110+t116;
    t304 = t111+t117;
    t305 = t112+t118;
    t306 = t113+t119;
    t307 = t93+t139;
    t308 = t94+t141;
    t309 = t95+t143;
    t310 = t96+t145;
    t311 = t97+t147;
    t312 = t98+t138;
    t313 = t94+t150;
    t314 = t99+t140;
    t315 = t95+t152;
    t316 = t100+t142;
    t317 = t96+t154;
    t318 = t101+t144;
    t319 = t102+t146;
    t320 = t103+t148;
    t321 = t99+t158;
    t322 = t104+t149;
    t323 = t100+t160;
    t324 = t105+t151;
    t325 = t101+t162;
    t326 = t106+t153;
    t327 = t107+t155;
    t328 = t103+t156;
    t329 = t104+t157;
    t330 = t105+t159;
    t331 = t106+t161;
    t332 = t107+t163;
    t351 = t121+t164;
    t352 = t122+t165;
    t353 = t123+t166;
    t354 = t121+t168;
    t355 = t122+t170;
    t356 = t123+t172;
    t357 = t121+t175;
    t358 = t126+t167;
    t359 = t122+t178;
    t360 = t127+t169;
    t361 = t123+t181;
    t362 = t128+t171;
    t363 = t126+t174;
    t364 = t127+t177;
    t365 = t128+t180;
    t366 = t126+t183;
    t367 = t131+t173;
    t368 = t127+t185;
    t369 = t132+t176;
    t370 = t128+t187;
    t371 = t133+t179;
    t372 = t131+t182;
    t373 = t132+t184;
    t374 = t133+t186;
    t375 = t131+t188;
    t376 = t132+t189;
    t377 = t133+t190;
    t378 = t79+t204;
    t379 = t84+t197;
    t380 = t80+t206;
    t381 = t85+t198;
    t382 = t81+t208;
    t383 = t86+t199;
    t384 = t79+t228;
    t385 = t89+t203;
    t386 = t80+t230;
    t387 = t90+t205;
    t388 = t81+t232;
    t389 = t91+t207;
    t390 = t84+t237;
    t391 = t89+t229;
    t392 = t85+t238;
    t393 = t90+t231;
    t394 = t86+t239;
    t395 = t91+t233;
    t278 = t21+t241;
    t279 = t22+t242;
    t280 = t23+t243;
    t281 = t24+t244;
    t282 = t25+t245;
    t292 = t16+t255;
    t293 = t16+t256;
    t294 = t16+t257;
    t295 = t17+t258;
    t296 = t17+t259;
    t297 = t17+t260;
    t298 = t18+t261;
    t299 = t18+t262;
    t300 = t18+t263;
    t333 = t307.*u10;
    t334 = t308.*u10;
    t335 = t308.*u11;
    t336 = t309.*u10;
    t337 = t309.*u11;
    t338 = t312.*u7;
    t339 = t309.*u12;
    t340 = t310.*u11;
    t341 = t314.*u7;
    t342 = t310.*u12;
    t343 = t314.*u8;
    t344 = t316.*u7;
    t345 = t311.*u12;
    t346 = t316.*u8;
    t347 = t316.*u9;
    t348 = t318.*u8;
    t349 = t318.*u9;
    t350 = t319.*u9;
    t396 = t79+t250;
    t397 = t84+t246;
    t398 = t80+t252;
    t399 = t85+t247;
    t400 = t81+t254;
    t401 = t86+t248;
    t402 = t79+t264;
    t403 = t89+t249;
    t404 = t80+t266;
    t405 = t90+t251;
    t406 = t81+t268;
    t407 = t91+t253;
    t408 = t84+t270;
    t409 = t89+t265;
    t410 = t85+t271;
    t411 = t90+t267;
    t412 = t86+t272;
    t413 = t91+t269;
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-t333-t335-t338-t339-t343-t347+t278.*u13+t279.*u14+t280.*u15,t301.*u8+t302.*u9+t312.*u10+t314.*u11+t316.*u12+t320.*u13+t322.*u14+t324.*u15+u7.*(t93.*3.0+t21.*t45.*t71),t21.*u7.*-2.0-t22.*u8.*2.0-t23.*u9.*2.0,u10.*(t83+t196)+u13.*(t88+t201)+t351.*u8+t352.*u9+t379.*u11+t381.*u12+t385.*u14+t387.*u15+u7.*(t120+t44.*t61.*t71),u13.*(t15+t212)+t284.*u14+t287.*u15+t358.*u8+t360.*u9-t396.*u11-t398.*u12+u7.*(t125+t44.*t63.*t71)-u10.*(t78-t202),-t292.*u11-t295.*u12+t367.*u8+t369.*u9-t402.*u14-t404.*u15+u7.*(t130+t44.*t65.*t71)-u10.*(t15-t211)-u13.*(t78-t226),-t334-t337-t341-t342-t346-t349+t279.*u13+t280.*u14+t281.*u15,t301.*u7+t302.*u8+t303.*u9+t314.*u10+t316.*u11+t318.*u12+t322.*u13+t324.*u14+t326.*u15,t22.*u7.*-2.0-t23.*u8.*2.0-t24.*u9.*2.0,t351.*u7+t352.*u8+t353.*u9+t379.*u10+t381.*u11+t383.*u12+t385.*u13+t387.*u14+t389.*u15,t284.*u13+t287.*u14+t290.*u15+t358.*u7+t360.*u8+t362.*u9-t396.*u10-t398.*u11-t400.*u12,-t292.*u10-t295.*u11-t298.*u12+t367.*u7+t369.*u8+t371.*u9-t402.*u13-t404.*u14-t406.*u15,-t336-t340-t344-t345-t348-t350+t280.*u13+t281.*u14+t282.*u15,t302.*u7+t303.*u8+t316.*u10+t318.*u11+t319.*u12+t324.*u13+t326.*u14+t327.*u15+u9.*(t97.*3.0+t25.*t45.*t71),t23.*u7.*-2.0-t24.*u8.*2.0-t25.*u9.*2.0,u12.*(t87+t200)+u15.*(t92+t209)+t352.*u7+t353.*u8+t381.*u10+t383.*u11+t387.*u13+t389.*u14+u9.*(t124+t10.*t44.*t50.*t71),u15.*(t19+t224)+t287.*u13+t290.*u14+t360.*u7+t362.*u8-t398.*u10-t400.*u11-u12.*(t82-t210)+u9.*(t129+t10.*t44.*t51.*t71),-t295.*u10-t298.*u11+t369.*u7+t371.*u8-t404.*u13-t406.*u14-u12.*(t19-t223)-u15.*(t82-t234)+u9.*(t134+t10.*t44.*t52.*t71),-t307.*u7-t304.*u11-t308.*u8-t305.*u12-t309.*u9-t328.*u13-t329.*u14-t330.*u15-u10.*(t98.*3.0+t21.*t47.*t71),t333+t335+t338+t339+t343+t347+t273.*u13+t274.*u14+t275.*u15,t21.*u10.*-2.0-t22.*u11.*2.0-t23.*u12.*2.0,-t294.*u14-t297.*u15+t354.*u11+t355.*u12-t397.*u8-t399.*u9+u10.*(t120+t46.*t61.*t71)-u13.*(t15-t213)-u7.*(t83-t196),u7.*(t78+t202)+u13.*(t88+t227)+t363.*u11+t364.*u12+t378.*u8+t380.*u9+t391.*u14+t393.*u15+u10.*(t125+t46.*t63.*t71),u7.*(t15+t211)+t283.*u8+t286.*u9+t372.*u11+t373.*u12-t408.*u14-t410.*u15+u10.*(t130+t46.*t65.*t71)-u13.*(t83-t236),-t304.*u10-t308.*u7-t305.*u11-t309.*u8-t306.*u12-t310.*u9-t329.*u13-t330.*u14-t331.*u15,t334+t337+t341+t342+t346+t349+t274.*u13+t275.*u14+t276.*u15,t22.*u10.*-2.0-t23.*u11.*2.0-t24.*u12.*2.0,-t294.*u13-t297.*u14-t300.*u15+t354.*u10+t355.*u11+t356.*u12-t397.*u7-t399.*u8-t401.*u9,t363.*u10+t364.*u11+t365.*u12+t378.*u7+t380.*u8+t382.*u9+t391.*u13+t393.*u14+t395.*u15,t283.*u7+t286.*u8+t289.*u9+t372.*u10+t373.*u11+t374.*u12-t408.*u13-t410.*u14-t412.*u15,-t305.*u10-t309.*u7-t306.*u11-t310.*u8-t311.*u9-t330.*u13-t331.*u14-t332.*u15-u12.*(t102.*3.0+t25.*t47.*t71),t336+t340+t344+t345+t348+t350+t275.*u13+t276.*u14+t277.*u15,t23.*u10.*-2.0-t24.*u11.*2.0-t25.*u12.*2.0,-t297.*u13-t300.*u14+t355.*u10+t356.*u11-t399.*u7-t401.*u8-u15.*(t19-t225)-u9.*(t87-t200)+u12.*(t124+t10.*t46.*t50.*t71),u9.*(t82+t210)+u15.*(t92+t235)+t364.*u10+t365.*u11+t380.*u7+t382.*u8+t393.*u13+t395.*u14+u12.*(t129+t10.*t46.*t51.*t71),u9.*(t19+t223)+t286.*u7+t289.*u8+t373.*u10+t374.*u11-t410.*u13-t412.*u14-u15.*(t87-t240)+u12.*(t134+t10.*t46.*t52.*t71),t278.*u7+t279.*u8+t280.*u9-t321.*u14-t323.*u15-t328.*u10-t329.*u11-t330.*u12-u13.*(t98+t21.*t41.*t48.*t71),t273.*u10+t274.*u11+t275.*u12+t313.*u14+t320.*u7+t315.*u15+t322.*u8+t324.*u9+u13.*(t93+t21.*t40.*t48.*t71),0.0,u10.*(t15+t213)+t285.*u11+t288.*u12+t357.*u14+t359.*u15-t403.*u8-t405.*u9+u13.*(t120+t48.*t61.*t71)-u7.*(t88-t201),-t293.*u8-t296.*u9+t366.*u14+t368.*u15-t409.*u11-t411.*u12+u13.*(t125+t48.*t63.*t71)-u7.*(t15-t212)-u10.*(t88-t227),u7.*(t78+t226)+u10.*(t83+t236)+t375.*u14+t376.*u15+t384.*u8+t386.*u9+t390.*u11+t392.*u12+u13.*(t130+t48.*t65.*t71),t279.*u7+t280.*u8+t281.*u9-t321.*u13-t323.*u14-t329.*u10-t325.*u15-t330.*u11-t331.*u12,t274.*u10+t275.*u11+t276.*u12+t313.*u13+t315.*u14+t322.*u7+t317.*u15+t324.*u8+t326.*u9,0.0,t285.*u10+t288.*u11+t291.*u12+t357.*u13+t359.*u14+t361.*u15-t403.*u7-t405.*u8-t407.*u9,-t293.*u7-t296.*u8-t299.*u9+t366.*u13+t368.*u14+t370.*u15-t409.*u10-t411.*u11-t413.*u12,t375.*u13+t376.*u14+t384.*u7+t377.*u15+t386.*u8+t388.*u9+t390.*u10+t392.*u11+t394.*u12,t280.*u7+t281.*u8+t282.*u9-t323.*u13-t325.*u14-t330.*u10-t331.*u11-t332.*u12-u15.*(t102+t25.*t41.*t48.*t71),t275.*u10+t276.*u11+t277.*u12+t315.*u13+t317.*u14+t324.*u7+t326.*u8+t327.*u9+u15.*(t97+t25.*t40.*t48.*t71),0.0,u12.*(t19+t225)+t288.*u10+t291.*u11+t359.*u13+t361.*u14-t405.*u7-t407.*u8-u9.*(t92-t209)+u15.*(t124+t10.*t48.*t50.*t71),-t296.*u7-t299.*u8+t368.*u13+t370.*u14-t411.*u10-t413.*u11-u9.*(t19-t224)-u12.*(t92-t235)+u15.*(t129+t10.*t48.*t51.*t71),u9.*(t82+t234)+u12.*(t87+t240)+t376.*u13+t377.*u14+t386.*u7+t388.*u8+t392.*u10+t394.*u11+u15.*(t134+t10.*t48.*t52.*t71)],[6,15]);
end
if nargout > 3
    out4 = [g_x_;g_y_;g_z_;0.0;0.0;0.0];
end
