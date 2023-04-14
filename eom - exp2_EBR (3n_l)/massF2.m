function [out1,out2,out3,out4] = massF2(in1,in2,s,ds,t_sym)
%MASSF2
%    [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    14-Jun-2021 23:13:51

g_x_ = in1(:,13);
g_y_ = in1(:,14);
g_z_ = in1(:,15);
gamma_ = in1(:,21);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
q4 = in2(4,:);
q5 = in2(5,:);
q6 = in2(6,:);
q7 = in2(7,:);
q8 = in2(8,:);
q9 = in2(9,:);
q10 = in2(10,:);
q11 = in2(11,:);
q12 = in2(12,:);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
sigma_s_ = in1(:,1);
u4 = in2(22,:);
u5 = in2(23,:);
u6 = in2(24,:);
u7 = in2(25,:);
u8 = in2(26,:);
u9 = in2(27,:);
u10 = in2(28,:);
u11 = in2(29,:);
u12 = in2(30,:);
t2 = cos(gamma_);
t3 = sin(gamma_);
t4 = l_s_.^2;
t5 = lambda_.^2;
t6 = q4.^2;
t7 = q5.^2;
t8 = q6.^2;
t9 = q10.^2;
t10 = q11.^2;
t11 = q12.^2;
t12 = r_p1_.^2;
t13 = r_s1_.^2;
t14 = r_s2_.^2;
t16 = 1.0./lambda_;
t21 = l_s_./3.0;
t22 = l_s_./4.0;
t23 = l_s_./6.0;
t24 = q4./2.0;
t25 = q5./2.0;
t26 = q6./2.0;
t27 = q7./2.0;
t28 = q8./2.0;
t29 = q9./2.0;
t30 = q10./2.0;
t31 = q11./2.0;
t32 = q12./2.0;
t47 = (q4.*q10)./4.0;
t51 = (q4.*q11)./4.0;
t52 = (q5.*q10)./4.0;
t55 = (q4.*q12)./4.0;
t56 = (q5.*q11)./4.0;
t57 = (q6.*q10)./4.0;
t59 = (q5.*q12)./4.0;
t60 = (q6.*q11)./4.0;
t61 = (q6.*q12)./4.0;
t62 = (q10.*q11)./4.0;
t63 = (q10.*q12)./4.0;
t64 = (q11.*q12)./4.0;
t83 = l_s_./1.2e+1;
t98 = (l_s_.*q4)./2.4e+1;
t99 = (l_s_.*q5)./2.4e+1;
t100 = (l_s_.*q6)./2.4e+1;
t101 = (l_s_.*q10)./2.4e+1;
t102 = (l_s_.*q11)./2.4e+1;
t103 = (l_s_.*q12)./2.4e+1;
t104 = q5.*q10.*(-1.0./2.0);
t106 = q4.*q12.*(-1.0./2.0);
t109 = q6.*q11.*(-1.0./2.0);
t119 = q4.*u4.*(-1.0./2.0);
t120 = q5.*u5.*(-1.0./2.0);
t121 = q6.*u6.*(-1.0./2.0);
t133 = l_s_.*q10.*(-1.0./1.2e+1);
t145 = (l_s_.*q4.*q10)./4.8e+1;
t146 = (l_s_.*q4.*q11)./4.8e+1;
t147 = (l_s_.*q5.*q10)./4.8e+1;
t148 = (l_s_.*q4.*q12)./4.8e+1;
t149 = (l_s_.*q5.*q11)./4.8e+1;
t150 = (l_s_.*q6.*q10)./4.8e+1;
t151 = (l_s_.*q5.*q12)./4.8e+1;
t152 = (l_s_.*q6.*q11)./4.8e+1;
t153 = (l_s_.*q6.*q12)./4.8e+1;
t162 = l_s_.*q4.*q5.*(-1.0./2.4e+1);
t163 = l_s_.*q4.*q6.*(-1.0./2.4e+1);
t164 = l_s_.*q5.*q6.*(-1.0./2.4e+1);
t15 = t2.^2;
t17 = t12.*6.0;
t18 = t13.*3.0;
t19 = t14.*3.0;
t20 = 1.0./t3.^2;
t33 = -t13;
t34 = -t14;
t35 = q5.*t24;
t36 = q6.*t24;
t37 = q7.*t24;
t38 = q6.*t25;
t39 = q8.*t24;
t40 = q7.*t25;
t41 = q8.*t25;
t42 = q7.*t26;
t43 = q10.*t24;
t44 = q8.*t26;
t45 = q11.*t24;
t46 = q10.*t25;
t48 = q12.*t24;
t49 = q11.*t25;
t50 = q10.*t26;
t53 = q12.*t25;
t54 = q11.*t26;
t58 = q12.*t26;
t65 = t24.*u4;
t66 = t24.*u5;
t67 = t25.*u4;
t68 = t24.*u6;
t69 = t25.*u5;
t70 = t26.*u4;
t71 = t24.*u7;
t72 = t25.*u6;
t73 = t26.*u5;
t74 = t24.*u8;
t75 = t25.*u7;
t76 = t26.*u6;
t77 = t24.*u9;
t78 = t25.*u8;
t79 = t26.*u7;
t80 = t25.*u9;
t81 = t26.*u8;
t82 = t26.*u9;
t84 = -t24;
t85 = -t25;
t86 = -t26;
t87 = -t30;
t88 = -t31;
t89 = -t32;
t90 = t6./4.0;
t91 = t7./4.0;
t92 = t8./4.0;
t93 = q4.*t83;
t94 = q5.*t83;
t95 = q6.*t83;
t96 = q10.*t83;
t97 = q11.*t83;
t105 = -t47;
t107 = -t51;
t108 = -t52;
t110 = -t55;
t111 = -t56;
t112 = -t57;
t113 = -t59;
t114 = -t60;
t115 = -t61;
t116 = -t62;
t117 = -t63;
t118 = -t64;
t122 = q9+t21;
t123 = -t83;
t127 = t6./8.0;
t128 = t7./8.0;
t129 = t8./8.0;
t130 = t9./8.0;
t131 = t10./8.0;
t132 = t11./8.0;
t134 = -t98;
t135 = -t99;
t136 = -t100;
t137 = -t101;
t138 = -t102;
t140 = q5.*t98;
t141 = q6.*t98;
t142 = q6.*t99;
t143 = q12.*t101;
t144 = q12.*t102;
t156 = (l_s_.*t6)./4.8e+1;
t157 = (l_s_.*t7)./4.8e+1;
t158 = (l_s_.*t8)./4.8e+1;
t159 = (l_s_.*t9)./4.8e+1;
t160 = (l_s_.*t10)./4.8e+1;
t161 = (l_s_.*t11)./4.8e+1;
t165 = -t145;
t166 = -t146;
t167 = -t147;
t168 = -t148;
t169 = -t149;
t170 = -t150;
t171 = -t152;
t179 = t23+t29;
t183 = t30+t64;
t184 = t31+t63;
t185 = t32+t62;
t186 = (t4.*t5)./1.08e+2;
t191 = t47+t56-1.0;
t192 = t47+t61-1.0;
t193 = t56+t61-1.0;
t203 = t24+t30+t59;
t204 = t25+t31+t57;
t205 = t26+t32+t51;
t124 = -t90;
t125 = -t91;
t126 = -t92;
t139 = t5.*t15;
t154 = -t131;
t155 = -t132;
t172 = -t156;
t173 = -t157;
t174 = -t158;
t175 = -t159;
t176 = -t160;
t178 = t18+t19;
t180 = (q4.*t122)./4.0;
t181 = (q5.*t122)./4.0;
t182 = (q6.*t122)./4.0;
t187 = t30+t118;
t188 = t31+t117;
t189 = t32+t116;
t190 = t13+t17+t34;
t194 = t93+t142;
t195 = t94+t141;
t196 = t95+t140;
t197 = q4+q10+t53+t109;
t198 = q5+q11+t50+t106;
t199 = q6+q12+t45+t104;
t200 = t24.*t179;
t201 = t25.*t179;
t202 = t26.*t179;
t206 = t93+t164;
t207 = t94+t163;
t208 = t95+t162;
t209 = t191.*u6;
t210 = t192.*u5;
t211 = t193.*u4;
t212 = t24+t30+t114;
t213 = t25+t31+t110;
t214 = t26+t32+t108;
t215 = t204.*u4;
t216 = t203.*u6;
t217 = t205.*u5;
t218 = t32+t51+t108;
t219 = t31+t57+t110;
t220 = t30+t59+t114;
t225 = t27+t97+t143;
t227 = t43+t49+t58-2.0;
t228 = t61+t191;
t250 = t28+t133+t144;
t259 = t114+t203;
t260 = t110+t204;
t261 = t108+t205;
t280 = t127+t128+t129+1.0./2.0;
t177 = t139-1.0;
t221 = t212.*u5;
t222 = t214.*u4;
t223 = t213.*u6;
t224 = (t16.*t178)./1.2e+1;
t229 = t220.*u4;
t230 = t219.*u5;
t231 = t218.*u6;
t232 = (q4.*t197)./4.0;
t233 = (q4.*t198)./4.0;
t234 = (q4.*t199)./4.0;
t235 = (q5.*t197)./4.0;
t236 = (q5.*t198)./4.0;
t237 = (q5.*t199)./4.0;
t238 = (q6.*t197)./4.0;
t239 = (q6.*t198)./4.0;
t240 = (q6.*t199)./4.0;
t241 = (q10.*t197)./4.0;
t242 = (q10.*t198)./4.0;
t243 = (q10.*t199)./4.0;
t244 = (q11.*t197)./4.0;
t245 = (q11.*t198)./4.0;
t246 = (q11.*t199)./4.0;
t247 = (q12.*t197)./4.0;
t248 = (q12.*t198)./4.0;
t249 = (q12.*t199)./4.0;
t251 = sigma_s_.*t21.*t190.*pi;
t255 = l_s_.*sigma_s_.*t190.*pi.*(-1.0./3.0);
t256 = t225.*u4;
t257 = t225.*u5;
t258 = t225.*u6;
t262 = t250.*u4;
t263 = t250.*u5;
t264 = t250.*u6;
t265 = t23.*t228;
t266 = (q4.*t227)./4.0;
t267 = (q5.*t227)./4.0;
t268 = (q6.*t227)./4.0;
t269 = (q10.*t227)./4.0;
t270 = (q11.*t227)./4.0;
t271 = (q12.*t227)./4.0;
t272 = l_s_.*t228.*(-1.0./6.0);
t273 = t83.*t228;
t274 = t93.*t228;
t275 = t94.*t228;
t276 = t95.*t228;
t277 = t96.*t228;
t278 = t97.*t228;
t281 = t23.*t259;
t282 = t23.*t260;
t283 = t23.*t261;
t284 = l_s_.*q6.*t228.*(-1.0./1.2e+1);
t285 = l_s_.*t259.*(-1.0./6.0);
t286 = l_s_.*t260.*(-1.0./6.0);
t287 = t83.*t259;
t288 = t83.*t260;
t289 = t83.*t261;
t290 = t280.*u10;
t291 = t280.*u11;
t292 = t280.*u12;
t293 = t130+t154+t155+1.0./2.0;
t294 = t130+t132+t154-1.0./2.0;
t295 = t130+t131+t155-1.0./2.0;
t297 = t93.*t259;
t298 = t93.*t260;
t299 = t93.*t261;
t300 = t94.*t259;
t301 = t94.*t260;
t302 = t94.*t261;
t303 = t95.*t259;
t304 = t95.*t260;
t305 = t95.*t261;
t306 = t96.*t259;
t307 = t96.*t260;
t308 = t96.*t261;
t309 = t97.*t259;
t310 = t97.*t260;
t311 = t97.*t261;
t315 = l_s_.*q5.*t259.*(-1.0./1.2e+1);
t316 = l_s_.*q5.*t260.*(-1.0./1.2e+1);
t317 = l_s_.*q6.*t260.*(-1.0./1.2e+1);
t318 = t133.*t260;
t320 = t83+t158+t172+t173;
t321 = t83+t157+t172+t174;
t322 = t83+t156+t173+t174;
t323 = t22+t29+t161+t175+t176;
t226 = t17.*t20.*t177;
t252 = -t241;
t253 = -t245;
t254 = -t249;
t279 = q12.*t273;
t312 = q12.*t287;
t313 = q12.*t288;
t314 = q12.*t289;
t319 = t186+t224;
t324 = t323.*u4;
t325 = t323.*u5;
t326 = t323.*u6;
t327 = t83+t145+t149+t153+t273;
t328 = t123+t149+t153+t165+t273;
t329 = t123+t145+t153+t169+t273;
t331 = t98+t101+t151+t152+t287;
t332 = t100+t103+t146+t147+t289;
t337 = t101+t134+t151+t171+t287;
t338 = t98+t137+t151+t171+t287;
t339 = t102+t135+t150+t168+t288;
t340 = t99+t138+t150+t168+t288;
t341 = t99+t102+t168+t170+t288;
t342 = t103+t136+t146+t167+t289;
t343 = t100+t103+t166+t167+t289;
t344 = t229+t230+t231;
t354 = t105+t111+t115+t232+t236+t240+1.0;
t296 = t14+t33+t226;
t330 = t327.*u12;
t333 = t329.*u10;
t334 = t328.*u11;
t335 = t331.*u10;
t336 = t332.*u11;
t345 = t340.*u10;
t346 = t343.*u10;
t347 = t338.*u11;
t348 = t341.*u11;
t349 = t337.*u12;
t350 = t339.*u12;
t351 = t342.*u12;
t355 = t37+t41+t182+t202+t279+t283+t309+t318;
t352 = -t345;
t353 = sigma_s_.*t21.*t296.*t319.*pi;
out1 = reshape([t255,0.0,0.0,0.0,0.0,0.0,0.0,t255,0.0,0.0,0.0,0.0,0.0,0.0,t255,0.0,0.0,0.0,0.0,0.0,0.0,t353,0.0,0.0,0.0,0.0,0.0,0.0,t353,0.0,0.0,0.0,0.0,0.0,0.0,sigma_s_.*t16.*t21.*t296.*pi.*(t13./2.0+t14./2.0)],[6,6]);
if nargout > 1
    out2 = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,t355,t40-t122+t265+t306+t310-(q4.*q8)./2.0-(l_s_.*q12.*t261)./1.2e+1,q8+t42-t180+t277+t285+t311+t313-(q4.*t179)./2.0,t105+t111+t115+t241+t253+t254+1.0,t52+t86+t89+t107+t242+t244+t271,t243+t247+t260-t270,t39+t122+t272+t314-(q5.*q7)./2.0+t133.*t259-(l_s_.*q11.*t260)./1.2e+1,t355,-q7+t44-t181+t278+t286-(q5.*t179)./2.0+t133.*t261-(l_s_.*q12.*t259)./1.2e+1,t242+t244+t261-t271,t105+t111+t115+t245+t252+t254+1.0,t60+t84+t87+t113+t246+t248+t269,-q8+t180+t200+t281-(q6.*q7)./2.0+t133.*t228-(l_s_.*q11.*t261)./1.2e+1-(l_s_.*q12.*t260)./1.2e+1,q7+t181+t201+t282+t308+t312-(q6.*q8)./2.0-(l_s_.*q11.*t228)./1.2e+1,t355,t55+t85+t88+t112+t243+t247+t270,t246+t248+t259-t269,t105+t111+t115+t249+t252+t253+1.0,t90+t125+t126+1.0,q6+t35,-q5+t36,0.0,0.0,0.0,-q6+t35,t91+t124+t126+1.0,q4+t38,0.0,0.0,0.0,q5+t36,-q4+t38,t92+t124+t125+1.0,0.0,0.0,0.0,t283+t284+t315-(l_s_.*q4.*t260)./1.2e+1,t265+t297+t305+t316,t274+t285+t317-(l_s_.*q5.*t261)./1.2e+1,t354,t52+t86+t89+t107+t233-t235-t268,t234-t238+t260+t267,t272+t297+t316-(l_s_.*q6.*t261)./1.2e+1,t283+t284+t298+t300,t275+t286+t299+t303,-t233+t235+t261+t268,t354,t60+t84+t87+t113+t237-t239-t266,t274+t281+t302+t317,t275+t282+t303-(l_s_.*q4.*t261)./1.2e+1,t276+t283+t298+t315,t55+t85+t88+t112-t234+t238-t267,-t237+t239+t259+t266,t354,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,18]);
end
if nargout > 2
    t356 = t71+t78+t82+t256+t263+t326+t330+t347+t352;
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t356,t75+t257-t262+t335+t348-t351-u9-(q4.*u8)./2.0,t79+t258-t324+t333+t336+t350+u8-(q4.*u9)./2.0,t24.*u10+t55.*u11+t185.*u6+t188.*u5-(q4.*q11.*u12)./4.0,t24.*u11+t47.*u12-t183.*u5-t294.*u6-(q4.*q12.*u10)./4.0,t24.*u12+t51.*u10-t187.*u6+t295.*u5-(q4.*q10.*u11)./4.0,t74-t257+t262-t335-t348+t351+u9-(q5.*u7)./2.0,t356,t81+t264-t325+t334-t346-t349-u7-(q5.*u9)./2.0,t25.*u10+t59.*u11-t188.*u4-t293.*u6-(q5.*q11.*u12)./4.0,t25.*u11+t52.*u12+t183.*u4+t189.*u6-(q5.*q12.*u10)./4.0,t25.*u12+t56.*u10-t184.*u6-t295.*u4-(q5.*q10.*u11)./4.0,t77-t258+t324-t333-t336-t350-u8-(q6.*u7)./2.0,t80-t264+t325-t334+t346+t349+u7-(q6.*u8)./2.0,t356,t26.*u10+t61.*u11-t185.*u4+t293.*u5-(q6.*q11.*u12)./4.0,t26.*u11+t57.*u12-t189.*u5+t294.*u4-(q6.*q12.*u10)./4.0,t26.*u12+t60.*u10+t184.*u5+t187.*u4-(q6.*q10.*u11)./4.0,t65+t120+t121,t66+t67+u6,t68+t70-u5,0.0,0.0,0.0,t66+t67-u6,t69+t119+t121,t72+t73+u4,0.0,0.0,0.0,t68+t70+u5,t72+t73-u4,t76+t119+t120,0.0,0.0,0.0,-t195.*u10+t322.*u12-t329.*u6-t331.*u5-t340.*u4,t196.*u12+t206.*u10+t331.*u4-t340.*u5+t343.*u6,-t207.*u12-t320.*u10+t329.*u4-t340.*u6-t343.*u5,t344,-t209+t215-t221+t292,t210-t216+t222-t291,-t195.*u11-t208.*u12-t332.*u6+t338.*u4-t341.*u5,t206.*u11+t321.*u12-t328.*u6+t338.*u5+t341.*u4,t194.*u12-t320.*u11+t328.*u5+t332.*u4+t338.*u6,t209-t215+t221-t292,t344,-t211+t217-t223+t290,t195.*u12-t208.*u11+t327.*u4+t322.*u10-t339.*u6+t342.*u5,t196.*u10-t206.*u12+t321.*u11+t327.*u5+t337.*u6-t342.*u4,t194.*u11-t207.*u10+t320.*u12+t327.*u6-t337.*u5+t339.*u4,-t210+t216-t222+t291,t211-t217+t223-t290,t344,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,18]);
end
if nargout > 3
    out4 = [g_x_;g_y_;g_z_;0.0;0.0;0.0];
end
