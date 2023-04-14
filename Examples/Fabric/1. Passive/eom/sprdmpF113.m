function [out1,out2,out3,out4,out5,out6,out7,out8] = sprdmpF113(in1,in2,s)
%SPRDMPF113
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF113(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    06-Jul-2019 06:28:45

E_sym = in1(:,1);
mu_u_sym = in1(:,4);
mu_v_sym = in1(:,3);
mu_pow_sym = in1(:,2);
phi_sym = in1(:,5);
q15 = in2(:,15);
q16 = in2(:,16);
q17 = in2(:,17);
q18 = in2(:,18);
q19 = in2(:,19);
q20 = in2(:,20);
q21 = in2(:,21);
q22 = in2(:,22);
q23 = in2(:,23);
q24 = in2(:,24);
q25 = in2(:,25);
q26 = in2(:,26);
q27 = in2(:,27);
q28 = in2(:,28);
u15 = in2(:,127);
u16 = in2(:,128);
u17 = in2(:,129);
u18 = in2(:,130);
u19 = in2(:,131);
u20 = in2(:,132);
u21 = in2(:,133);
u22 = in2(:,134);
u23 = in2(:,135);
u24 = in2(:,136);
u25 = in2(:,137);
u26 = in2(:,138);
u27 = in2(:,139);
u28 = in2(:,140);
t2 = q18.^2;
t3 = q19.^2;
t4 = q20.^2;
t5 = q21.^2;
t6 = t2+t3+t4+t5;
t7 = 1.0./t6;
t8 = q18.*q21.*t7.*2.0;
t9 = t4.*t7;
t10 = t5.*t7;
t11 = q18.*q19.*t7.*2.0;
t12 = t3.*t7;
t13 = 1.0./sqrt(t6);
t14 = q15-q22;
t15 = q16-q23;
t16 = 1.0./t6.^(3.0./2.0);
t17 = q17-q24;
t18 = q18.*t13.*t14;
t19 = q21.*t13.*t15;
t45 = q20.*t13.*t17;
t20 = t18+t19-t45;
t21 = q18.*t13.*t15;
t22 = q19.*t13.*t17;
t37 = q21.*t13.*t14;
t23 = t21+t22-t37;
t24 = t13.*t15;
t25 = q18.*q21.*t14.*t16;
t49 = t2.*t15.*t16;
t50 = q18.*q19.*t16.*t17;
t26 = t24+t25-t49-t50;
t27 = t13.*t17;
t28 = q18.*q19.*t15.*t16;
t47 = t2.*t16.*t17;
t48 = q18.*q20.*t14.*t16;
t29 = t27+t28-t47-t48;
t30 = t13.*t14;
t31 = q18.*q20.*t16.*t17;
t51 = t2.*t14.*t16;
t52 = q18.*q21.*t15.*t16;
t32 = t30+t31-t51-t52;
t33 = q18.*q19.*t14.*t16;
t34 = q18.*q20.*t15.*t16;
t35 = q18.*q21.*t16.*t17;
t36 = t33+t34+t35;
t38 = q20.*t13.*t14;
t39 = q18.*t13.*t17;
t46 = q19.*t13.*t15;
t40 = t38+t39-t46;
t41 = q19.*t13.*t14;
t42 = q20.*t13.*t15;
t43 = q21.*t13.*t17;
t44 = t41+t42+t43;
t53 = q19.*t13;
t54 = q25.^2;
t55 = q26.^2;
t56 = q27.^2;
t57 = q28.^2;
t58 = t54+t55+t56+t57;
t59 = 1.0./sqrt(t58);
t68 = q26.*t59;
t60 = t53-t68;
t61 = q20.*t13;
t63 = q27.*t59;
t62 = t61-t63;
t72 = t2.*t16;
t64 = t13-t72;
t65 = 1.0./t6.^2;
t66 = q18.*t13;
t73 = q25.*t59;
t67 = t66-t73;
t69 = q21.*t13;
t71 = q28.*t59;
t70 = t69-t71;
t74 = q19.*q20.*t14.*t16;
t84 = t3.*t15.*t16;
t75 = t24+t50+t74-t84;
t76 = t3.*t14.*t16;
t77 = q19.*q20.*t15.*t16;
t78 = q19.*q21.*t16.*t17;
t79 = -t30+t76+t77+t78;
t80 = q19.*q21.*t14.*t16;
t85 = t3.*t16.*t17;
t81 = t27-t28+t80-t85;
t82 = q19.*q21.*t15.*t16;
t86 = q19.*q20.*t16.*t17;
t83 = t33+t82-t86;
t87 = q18.*q19.*t16.*t40;
t89 = t3.*t16;
t88 = t13-t89;
t90 = q18.*q19.*t16.*t70.*2.0;
t91 = q18.*q20.*t16.*t20;
t92 = q19.*q20.*t16.*t44;
t100 = t4.*t14.*t16;
t93 = t30-t31+t77-t100;
t94 = t4.*t15.*t16;
t95 = q20.*q21.*t16.*t17;
t96 = -t24+t74+t94+t95;
t97 = q20.*q21.*t15.*t16;
t101 = t4.*t16.*t17;
t98 = t27+t48+t97-t101;
t102 = q20.*q21.*t14.*t16;
t99 = t34+t86-t102;
t103 = q18.*q20.*t16.*t60.*2.0;
t104 = t13.*t67.*2.0;
t106 = t4.*t16;
t105 = t13-t106;
t107 = t13.*t23;
t108 = q19.*q21.*t16.*t44;
t116 = t5.*t14.*t16;
t109 = t30+t52+t78-t116;
t117 = t5.*t15.*t16;
t110 = t24-t25+t95-t117;
t111 = t5.*t16.*t17;
t112 = -t27+t80+t97+t111;
t113 = t35-t82+t102;
t114 = q18.*q21.*t16.*t23;
t115 = q20.*q21.*t16.*t44;
t118 = q19.*q21.*t16.*t23;
t119 = t13.*t62.*2.0;
t122 = t5.*t16;
t120 = t13-t122;
t121 = q18.*q21.*t16.*t62.*2.0;
t123 = q19.*q21.*t16.*t62.*2.0;
t124 = q18.*q20.*t7.*2.0;
t125 = q19.*q20.*t7.*2.0;
t126 = t2.*t7;
t127 = q19.*q21.*t7.*2.0;
t128 = q20.*q21.*t7.*2.0;
t129 = 1.0./t58.^(3.0./2.0);
t131 = t54.*t129;
t130 = t59-t131;
t133 = t55.*t129;
t132 = t59-t133;
t134 = q21.*q25.*q26.*t13.*t129.*2.0;
t135 = q19.*q25.*q27.*t13.*t129.*2.0;
t137 = t56.*t129;
t136 = t59-t137;
t140 = t57.*t129;
t138 = t59-t140;
t139 = q20.*q25.*q28.*t13.*t129.*2.0;
t141 = q20.*q26.*q28.*t13.*t129.*2.0;
t142 = phi_sym./2.0;
t143 = cos(t142);
t144 = t143.*(9.0./2.5e2);
t145 = sin(t142);
t146 = t145.*(9.0./2.5e2);
t147 = t143./4.0;
t148 = t146+t147;
t149 = t143.*(3.33e2./1.0e3);
t150 = t146+t149;
t442 = t145./4.0;
t151 = t144-t442;
t444 = t145.*(3.33e2./1.0e3);
t152 = t144-t444;
t153 = t13.*t20;
t154 = q20.*t13.*t29;
t155 = q19.*t13.*t36;
t156 = t2.*t16.*t20;
t157 = q18.*q20.*t16.*t40;
t158 = q18.*q19.*t16.*t44;
t159 = q19.*t13.*t79;
t160 = q18.*t13.*t83;
t161 = t3.*t16.*t44;
t162 = q18.*q19.*t16.*t20;
t163 = q19.*q20.*t16.*t40;
t164 = t13.*t40;
t165 = q20.*t13.*t93;
t166 = q18.*t13.*t98;
t167 = q19.*t13.*t96;
t168 = q21.*t13.*t99;
t169 = q20.*q21.*t16.*t23;
t183 = t4.*t16.*t40;
t170 = t91+t92+t164+t165+t166+t167+t168+t169-t183;
t171 = q21.*t13.*t109;
t172 = q19.*t13.*t112;
t173 = t5.*t16.*t23;
t174 = q18.*q21.*t16.*t20;
t185 = q18.*t13.*t110;
t186 = q20.*t13.*t113;
t187 = q20.*q21.*t16.*t40;
t175 = -t107+t108+t171+t172+t173+t174-t185-t186-t187;
t176 = t8+t125;
t177 = t124-t127;
t178 = -t9-t10+t12+t126;
t196 = q18.*t13.*t32;
t197 = q21.*t13.*t26;
t179 = t114-t153+t154+t155+t156-t157+t158-t196-t197;
t180 = t179.*u18;
t198 = t13.*t44;
t199 = q20.*t13.*t75;
t200 = q21.*t13.*t81;
t181 = t118+t159+t160+t161+t162-t163-t198-t199-t200;
t182 = t181.*u19;
t184 = t170.*u20;
t188 = t175.*u21;
t189 = t177.*u17;
t190 = t176.*u23;
t191 = t178.*u22;
t201 = t176.*u16;
t202 = t177.*u24;
t203 = t178.*u15;
t192 = t180+t182+t184+t188+t189+t190+t191-t201-t202-t203;
t193 = abs(t192);
t194 = mu_pow_sym-1.0;
t195 = t193.^t194;
t204 = q21.*t13.*t32;
t205 = q20.*t13.*t36;
t206 = t2.*t16.*t23;
t207 = q18.*q20.*t16.*t44;
t208 = q19.*t13.*t75;
t209 = q20.*t13.*t79;
t210 = t3.*t16.*t40;
t211 = q18.*q19.*t16.*t23;
t212 = q20.*t13.*t96;
t213 = q18.*t13.*t99;
t214 = t4.*t16.*t44;
t215 = q18.*q20.*t16.*t23;
t216 = q20.*q21.*t16.*t20;
t217 = q18.*t13.*t109;
t218 = q21.*t13.*t110;
t219 = q20.*t13.*t112;
t220 = q19.*t13.*t113;
t221 = q19.*q21.*t16.*t40;
t232 = t5.*t16.*t20;
t222 = t114+t115+t153+t217+t218+t219+t220+t221-t232;
t223 = t11+t128;
t224 = t8-t125;
t225 = t9-t10-t12+t126;
t240 = q18.*t13.*t26;
t241 = q19.*t13.*t29;
t226 = t87-t107-t174+t204+t205+t206+t207-t240-t241;
t227 = t226.*u18;
t242 = q18.*t13.*t81;
t243 = q21.*t13.*t83;
t244 = q19.*q21.*t16.*t20;
t228 = t92-t164+t208+t209+t210+t211-t242-t243-t244;
t229 = t228.*u19;
t245 = q19.*t13.*t93;
t246 = q21.*t13.*t98;
t230 = t163-t198+t212+t213+t214+t215-t216-t245-t246;
t231 = t230.*u20;
t233 = t222.*u21;
t234 = t224.*u15;
t235 = t223.*u24;
t236 = t225.*u23;
t247 = t223.*u17;
t248 = t224.*u22;
t249 = t225.*u16;
t237 = t227+t229+t231+t233+t234+t235+t236-t247-t248-t249;
t238 = abs(t237);
t239 = t238.^t194;
t250 = q19.*t13.*t26;
t251 = q21.*t13.*t36;
t252 = t2.*t16.*t40;
t253 = q18.*q21.*t16.*t44;
t254 = q18.*t13.*t75;
t255 = q21.*t13.*t79;
t256 = q19.*t13.*t81;
t257 = q20.*t13.*t83;
t258 = q19.*q20.*t16.*t20;
t272 = t3.*t16.*t23;
t259 = t87+t107+t108+t254+t255+t256+t257+t258-t272;
t260 = q20.*t13.*t98;
t261 = q21.*t13.*t96;
t262 = t4.*t16.*t20;
t263 = q21.*t13.*t112;
t264 = q18.*t13.*t113;
t265 = t5.*t16.*t44;
t266 = q18.*q21.*t16.*t40;
t267 = t124+t127;
t268 = t11-t128;
t269 = -t9+t10-t12+t126;
t284 = q18.*t13.*t29;
t285 = q20.*t13.*t32;
t270 = t91-t164-t211+t250+t251+t252+t253-t284-t285;
t271 = t270.*u18;
t273 = t259.*u19;
t286 = q18.*t13.*t93;
t287 = q19.*t13.*t99;
t288 = q19.*q20.*t16.*t23;
t274 = t115-t153+t157+t260+t261+t262-t286-t287-t288;
t275 = t274.*u20;
t289 = q19.*t13.*t109;
t290 = q20.*t13.*t110;
t276 = -t118-t198+t216+t263+t264+t265+t266-t289-t290;
t277 = t276.*u21;
t278 = t268.*u16;
t279 = t267.*u22;
t280 = t269.*u24;
t291 = t267.*u15;
t292 = t268.*u23;
t293 = t269.*u17;
t281 = t271+t273+t275+t277+t278+t279+t280-t291-t292-t293;
t282 = abs(t281);
t283 = t282.^t194;
t294 = t13.*t60.*2.0;
t295 = t2.*t16.*t60.*2.0;
t296 = q19.*t13.*t64.*2.0;
t297 = q19.*t2.*t65.*2.0;
t298 = q18.*q20.*t16.*t70.*2.0;
t299 = q18.*q19.*t16.*t60.*2.0;
t300 = q19.*q20.*t16.*t70.*2.0;
t301 = t13.*t70.*2.0;
t302 = q20.*q21.*t16.*t62.*2.0;
t303 = t5.*t16.*t62.*2.0;
t304 = q20.*t13.*t120.*2.0;
t305 = q20.*t5.*t65.*2.0;
t306 = q18.*q21.*t16.*t60.*2.0;
t328 = q19.*q21.*t16.*t67.*2.0;
t329 = q20.*q21.*t16.*t70.*2.0;
t307 = -t119+t303+t304+t305+t306-t328-t329;
t308 = q21.*q25.*q27.*t13.*t129.*2.0;
t309 = q18.*t13.*t132.*2.0;
t310 = q19.*q25.*q26.*t13.*t129.*2.0;
t311 = q21.*q26.*q27.*t13.*t129.*2.0;
t312 = q21.*t13.*t136.*2.0;
t313 = q20.*q27.*q28.*t13.*t129.*2.0;
t336 = q18.*q26.*q27.*t13.*t129.*2.0;
t314 = t135+t312+t313-t336;
t315 = q19.*q25.*q28.*t13.*t129.*2.0;
t317 = q18.*q19.*t16.*t67.*2.0;
t316 = t121-t294+t295+t296+t297-t298-t317;
t318 = t316.*u18;
t319 = t3.*t16.*t67.*2.0;
t320 = q18.*t13.*t88.*2.0;
t321 = q18.*t3.*t65.*2.0;
t322 = -t104-t123-t299+t300+t319+t320+t321;
t323 = t4.*t16.*t70.*2.0;
t324 = q21.*t13.*t105.*2.0;
t325 = q21.*t4.*t65.*2.0;
t326 = q19.*q20.*t16.*t67.*2.0;
t327 = -t103-t301-t302+t323+t324+t325+t326;
t330 = t307.*u21;
t331 = q19.*t13.*t130.*2.0;
t332 = q18.*q25.*q26.*t13.*t129.*2.0;
t333 = -t139+t308+t331+t332;
t334 = t141+t309+t310-t311;
t335 = t334.*u26;
t337 = t314.*u27;
t338 = q20.*t13.*t138.*2.0;
t339 = q18.*q26.*q28.*t13.*t129.*2.0;
t340 = q21.*q27.*q28.*t13.*t129.*2.0;
t341 = -t315+t338+t339+t340;
t345 = t322.*u19;
t346 = t327.*u20;
t347 = t333.*u25;
t348 = t341.*u28;
t342 = t318+t330+t335+t337-t345-t346-t347-t348;
t343 = abs(t342);
t344 = t343.^t194;
t349 = t2.*t16.*t62.*2.0;
t350 = q20.*t13.*t64.*2.0;
t351 = q20.*t2.*t65.*2.0;
t352 = q18.*q20.*t16.*t62.*2.0;
t353 = q20.*q21.*t16.*t60.*2.0;
t354 = t3.*t16.*t70.*2.0;
t355 = q21.*t13.*t88.*2.0;
t356 = q21.*t3.*t65.*2.0;
t357 = q18.*q19.*t16.*t62.*2.0;
t358 = q19.*q21.*t16.*t70.*2.0;
t359 = q20.*q25.*q26.*t13.*t129.*2.0;
t360 = q18.*t13.*t136.*2.0;
t361 = q20.*q25.*q27.*t13.*t129.*2.0;
t362 = q19.*q27.*q28.*t13.*t129.*2.0;
t363 = q19.*t13.*t138.*2.0;
t364 = q21.*q26.*q28.*t13.*t129.*2.0;
t388 = q18.*q27.*q28.*t13.*t129.*2.0;
t365 = t139+t363+t364-t388;
t367 = q18.*q20.*t16.*t67.*2.0;
t366 = t90-t119-t306+t349+t350+t351-t367;
t368 = t366.*u18;
t369 = t4.*t16.*t67.*2.0;
t370 = q18.*t13.*t105.*2.0;
t371 = q18.*t4.*t65.*2.0;
t372 = -t104-t300-t352+t353+t369+t370+t371;
t394 = q19.*q21.*t16.*t60.*2.0;
t373 = -t301-t326+t354+t355+t356+t357-t394;
t374 = t373.*u19;
t375 = t5.*t16.*t60.*2.0;
t376 = q19.*t13.*t120.*2.0;
t377 = q19.*t5.*t65.*2.0;
t378 = q20.*q21.*t16.*t67.*2.0;
t379 = -t121-t294-t358+t375+t376+t377+t378;
t380 = q20.*t13.*t130.*2.0;
t381 = q18.*q25.*q27.*t13.*t129.*2.0;
t382 = -t134+t315+t380+t381;
t383 = q21.*t13.*t132.*2.0;
t384 = q19.*q26.*q28.*t13.*t129.*2.0;
t385 = t336-t359+t383+t384;
t386 = t311+t360+t361-t362;
t387 = t386.*u27;
t389 = t365.*u28;
t393 = t372.*u20;
t395 = t379.*u21;
t396 = t382.*u25;
t397 = t385.*u26;
t390 = t368+t374+t387+t389-t393-t395-t396-t397;
t391 = abs(t390);
t392 = t391.^t194;
t398 = t2.*t16.*t70.*2.0;
t399 = q21.*t13.*t64.*2.0;
t400 = q21.*t2.*t65.*2.0;
t401 = q19.*q20.*t16.*t60.*2.0;
t402 = t4.*t16.*t60.*2.0;
t403 = q19.*t13.*t105.*2.0;
t404 = q19.*t4.*t65.*2.0;
t405 = q18.*q21.*t16.*t70.*2.0;
t406 = q20.*t13.*t132.*2.0;
t407 = q19.*q26.*q27.*t13.*t129.*2.0;
t408 = q18.*t13.*t138.*2.0;
t409 = q21.*q25.*q28.*t13.*t129.*2.0;
t410 = -t141+t362+t408+t409;
out1 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t9+t10-t2.*t7-t3.*t7,-t8-q19.*q20.*t7.*2.0,t124-q19.*q21.*t7.*2.0,t114+t154+t155+t156+t158-t13.*t20-q21.*t13.*t26-q18.*t13.*t32-q18.*q20.*t16.*t40,t118+t159+t160+t161+t162-t13.*t44-q20.*t13.*t75-q21.*t13.*t81-q19.*q20.*t16.*t40,t170,t175,t178,t176,-t124+t127,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t8-q19.*q20.*t7.*2.0,-t9+t10+t12-t2.*t7,-t11-q20.*q21.*t7.*2.0,t87+t204+t205+t206+t207-t13.*t23-q18.*t13.*t26-q19.*t13.*t29-q18.*q21.*t16.*t20,t92+t208+t209+t210+t211-t13.*t40-q18.*t13.*t81-q21.*t13.*t83-q19.*q21.*t16.*t20,t163+t212+t213+t214+t215-t13.*t44-q19.*t13.*t93-q21.*t13.*t98-q20.*q21.*t16.*t20,t222,-t8+t125,t225,t223,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,q18.*q20.*t7.*-2.0-q19.*q21.*t7.*2.0,t11-q20.*q21.*t7.*2.0,t9-t10+t12-t2.*t7,t91+t250+t251+t252+t253-t13.*t40-q18.*t13.*t29-q20.*t13.*t32-q18.*q19.*t16.*t23,t259,t115+t157+t260+t261+t262-t13.*t20-q18.*t13.*t93-q19.*t13.*t99-q19.*q20.*t16.*t23,-t118+t216+t263+t264+t265+t266-t13.*t44-q19.*t13.*t109-q20.*t13.*t110,t267,-t11+t128,t269,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t121+t295+t296+t297-t13.*t60.*2.0-q18.*q19.*t16.*t67.*2.0-q18.*q20.*t16.*t70.*2.0,t104+t123+t299-q18.*t3.*t65.*2.0-q18.*t13.*t88.*2.0-t3.*t16.*t67.*2.0-q19.*q20.*t16.*t70.*2.0,t103+t301+t302-q21.*t4.*t65.*2.0-q21.*t13.*t105.*2.0-t4.*t16.*t70.*2.0-q19.*q20.*t16.*t67.*2.0,t307,0.0,0.0,0.0,t139-q19.*t13.*t130.*2.0-q18.*q25.*q26.*t13.*t129.*2.0-q21.*q25.*q27.*t13.*t129.*2.0,t141+t309+t310-q21.*q26.*q27.*t13.*t129.*2.0,t314,t315-q20.*t13.*t138.*2.0-q18.*q26.*q28.*t13.*t129.*2.0-q21.*q27.*q28.*t13.*t129.*2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t90+t349+t350+t351-t13.*t62.*2.0-q18.*q21.*t16.*t60.*2.0-q18.*q20.*t16.*t67.*2.0,t354+t355+t356+t357-t13.*t70.*2.0-q19.*q21.*t16.*t60.*2.0-q19.*q20.*t16.*t67.*2.0,t104+t300+t352-q18.*t4.*t65.*2.0-q18.*t13.*t105.*2.0-t4.*t16.*t67.*2.0-q20.*q21.*t16.*t60.*2.0,t121+t294+t358-q19.*t5.*t65.*2.0-q19.*t13.*t120.*2.0-t5.*t16.*t60.*2.0-q20.*q21.*t16.*t67.*2.0,0.0,0.0,0.0,t134-q20.*t13.*t130.*2.0-q18.*q25.*q27.*t13.*t129.*2.0-q19.*q25.*q28.*t13.*t129.*2.0,t359-q21.*t13.*t132.*2.0-q18.*q26.*q27.*t13.*t129.*2.0-q19.*q26.*q28.*t13.*t129.*2.0,t311+t360+t361-q19.*q27.*q28.*t13.*t129.*2.0,t365,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t103+t398+t399+t400-t13.*t70.*2.0-q18.*q19.*t16.*t62.*2.0-q18.*q21.*t16.*t67.*2.0,t90+t119+t401-q20.*t3.*t65.*2.0-q20.*t13.*t88.*2.0-t3.*t16.*t62.*2.0-q19.*q21.*t16.*t67.*2.0,t298+t402+t403+t404-t13.*t60.*2.0-q19.*q20.*t16.*t62.*2.0-q20.*q21.*t16.*t67.*2.0,t104-t123+t353+t405-q18.*t5.*t65.*2.0-q18.*t13.*t120.*2.0-t5.*t16.*t67.*2.0,0.0,0.0,0.0,t135-q21.*t13.*t130.*2.0-q18.*q25.*q28.*t13.*t129.*2.0-q20.*q25.*q26.*t13.*t129.*2.0,t134+t406+t407-q18.*q26.*q28.*t13.*t129.*2.0,t308-q19.*t13.*t136.*2.0-q18.*q27.*q28.*t13.*t129.*2.0-q20.*q26.*q27.*t13.*t129.*2.0,t410,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[106,6]);
if nargout > 1
    t412 = q18.*q21.*t16.*t67.*2.0;
    t411 = t103-t301-t357+t398+t399+t400-t412;
    t413 = t411.*u18;
    t414 = t3.*t16.*t62.*2.0;
    t415 = q20.*t13.*t88.*2.0;
    t416 = q20.*t3.*t65.*2.0;
    t417 = -t90-t119+t328-t401+t414+t415+t416;
    t437 = q19.*q20.*t16.*t62.*2.0;
    t418 = -t294+t298-t378+t402+t403+t404-t437;
    t419 = t418.*u20;
    t420 = t5.*t16.*t67.*2.0;
    t421 = q18.*t13.*t120.*2.0;
    t422 = q18.*t5.*t65.*2.0;
    t423 = -t104+t123-t353-t405+t420+t421+t422;
    t424 = q21.*t13.*t130.*2.0;
    t425 = q18.*q25.*q28.*t13.*t129.*2.0;
    t426 = -t135+t359+t424+t425;
    t427 = t134-t339+t406+t407;
    t428 = t427.*u26;
    t429 = q19.*t13.*t136.*2.0;
    t430 = q20.*q26.*q27.*t13.*t129.*2.0;
    t431 = -t308+t388+t429+t430;
    t432 = t410.*u28;
    t436 = t417.*u19;
    t438 = t423.*u21;
    t439 = t426.*u25;
    t440 = t431.*u27;
    t433 = t413+t419+t428+t432-t436-t438-t439-t440;
    t434 = abs(t433);
    t435 = t434.^t194;
    t441 = t143.*t148;
    t443 = t145.*t151;
    out2 = [E_sym.*(-t145.*t148+t143.*t151-t143.*t152+t145.*t150+q18.*t13.*t20+q21.*t13.*t23-q20.*t13.*t40+q19.*t13.*t44).*2.666666666666667e-4;E_sym.*(t143.^2.*2.573707911e-14+t145.^2.*2.573707911e-14+q18.*t13.*t23-q21.*t13.*t20+q19.*t13.*t40+q20.*t13.*t44).*2.666666666666667e-4;E_sym.*(t441+t443-t143.*t150-t145.*t152+q20.*t13.*t20-q19.*t13.*t23+q18.*t13.*t40+q21.*t13.*t44).*8.0e-4;E_sym.*(q18.*t13.*t60.*2.0+q21.*t13.*t62.*2.0-q19.*t13.*t67.*2.0-q20.*t13.*t70.*2.0).*4.266666666666667e-11;E_sym.*(q18.*t13.*t62.*2.0-q21.*t13.*t60.*2.0-q20.*t13.*t67.*2.0+q19.*t13.*t70.*2.0).*1.421066666666666e-8;E_sym.*(q20.*t13.*t60.*2.0-q19.*t13.*t62.*2.0+q18.*t13.*t70.*2.0-q21.*t13.*t67.*2.0).*4.75111111111111e-9];
end
if nargout > 2
    out3 = [-mu_v_sym.*t170.*t195.*u20+mu_v_sym.*t176.*t195.*u16+mu_v_sym.*t178.*t195.*u15-mu_v_sym.*t177.*t195.*u17-mu_v_sym.*t175.*t195.*u21-mu_v_sym.*t179.*t195.*u18-mu_v_sym.*t176.*t195.*u23-mu_v_sym.*t178.*t195.*u22-mu_v_sym.*t181.*t195.*u19+mu_v_sym.*t177.*t195.*u24;-mu_v_sym.*t224.*t239.*u15+mu_v_sym.*t223.*t239.*u17+mu_v_sym.*t225.*t239.*u16-mu_v_sym.*t222.*t239.*u21-mu_v_sym.*t226.*t239.*u18+mu_v_sym.*t224.*t239.*u22-mu_v_sym.*t223.*t239.*u24-mu_v_sym.*t228.*t239.*u19-mu_v_sym.*t225.*t239.*u23-mu_v_sym.*t230.*t239.*u20;-mu_v_sym.*t259.*t283.*u19+mu_v_sym.*t267.*t283.*u15-mu_v_sym.*t268.*t283.*u16+mu_v_sym.*t269.*t283.*u17-mu_v_sym.*t270.*t283.*u18-mu_v_sym.*t267.*t283.*u22+mu_v_sym.*t268.*t283.*u23-mu_v_sym.*t269.*t283.*u24-mu_v_sym.*t274.*t283.*u20-mu_v_sym.*t276.*t283.*u21;-mu_u_sym.*t307.*t344.*u21-mu_u_sym.*t316.*t344.*u18-mu_u_sym.*t314.*t344.*u27+mu_u_sym.*t322.*t344.*u19+mu_u_sym.*t327.*t344.*u20+mu_u_sym.*t333.*t344.*u25-mu_u_sym.*t334.*t344.*u26+mu_u_sym.*t341.*t344.*u28;-mu_u_sym.*t366.*t392.*u18+mu_u_sym.*t372.*t392.*u20-mu_u_sym.*t373.*t392.*u19-mu_u_sym.*t365.*t392.*u28+mu_u_sym.*t379.*t392.*u21+mu_u_sym.*t382.*t392.*u25+mu_u_sym.*t385.*t392.*u26-mu_u_sym.*t386.*t392.*u27;-mu_u_sym.*t411.*t435.*u18+mu_u_sym.*t417.*t435.*u19-mu_u_sym.*t410.*t435.*u28-mu_u_sym.*t418.*t435.*u20+mu_u_sym.*t423.*t435.*u21+mu_u_sym.*t426.*t435.*u25-mu_u_sym.*t427.*t435.*u26+mu_u_sym.*t431.*t435.*u27];
end
if nargout > 3
    out4 = [0.0;0.0;0.0;0.0;0.0;0.0];
end
if nargout > 4
    out5 = -t441-t443+sqrt(t14.^2+t15.^2+t17.^2)+t143.*t150+t145.*t152;
end
if nargout > 5
    t445 = E_sym.*t177.*2.666666666666667e-4;
    t446 = E_sym.*t224.*2.666666666666667e-4;
    t447 = E_sym.*t268.*8.0e-4;
    out6 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,E_sym.*t178.*(-2.666666666666667e-4),t446,E_sym.*t267.*(-8.0e-4),0.0,0.0,0.0,E_sym.*t176.*(-2.666666666666667e-4),E_sym.*t225.*(-2.666666666666667e-4),t447,0.0,0.0,0.0,t445,E_sym.*t223.*(-2.666666666666667e-4),E_sym.*t269.*(-8.0e-4),0.0,0.0,0.0,E_sym.*t179.*2.666666666666667e-4,E_sym.*t226.*2.666666666666667e-4,E_sym.*t270.*8.0e-4,E_sym.*t316.*4.266666666666667e-11,E_sym.*t366.*1.421066666666666e-8,E_sym.*t411.*4.75111111111111e-9,E_sym.*t181.*2.666666666666667e-4,E_sym.*t228.*2.666666666666667e-4,E_sym.*t259.*8.0e-4,E_sym.*t322.*(-4.266666666666667e-11),E_sym.*t373.*1.421066666666666e-8,E_sym.*t417.*(-4.75111111111111e-9),E_sym.*t170.*2.666666666666667e-4,E_sym.*t230.*2.666666666666667e-4,E_sym.*t274.*8.0e-4,E_sym.*t327.*(-4.266666666666667e-11),E_sym.*t372.*(-1.421066666666666e-8),E_sym.*t418.*4.75111111111111e-9,E_sym.*t175.*2.666666666666667e-4,E_sym.*t222.*2.666666666666667e-4,E_sym.*t276.*8.0e-4,E_sym.*t307.*4.266666666666667e-11,E_sym.*t379.*(-1.421066666666666e-8),E_sym.*t423.*(-4.75111111111111e-9),E_sym.*t178.*2.666666666666667e-4,-t446,E_sym.*t267.*8.0e-4,0.0,0.0,0.0,E_sym.*t176.*2.666666666666667e-4,E_sym.*t225.*2.666666666666667e-4,-t447,0.0,0.0,0.0,-t445,E_sym.*t223.*2.666666666666667e-4,E_sym.*t269.*8.0e-4,0.0,0.0,0.0,0.0,0.0,0.0,E_sym.*t333.*(-4.266666666666667e-11),E_sym.*t382.*(-1.421066666666666e-8),E_sym.*t426.*(-4.75111111111111e-9),0.0,0.0,0.0,E_sym.*t334.*4.266666666666667e-11,E_sym.*t385.*(-1.421066666666666e-8),E_sym.*t427.*4.75111111111111e-9,0.0,0.0,0.0,E_sym.*t314.*4.266666666666667e-11,E_sym.*t386.*1.421066666666666e-8,E_sym.*t431.*(-4.75111111111111e-9),0.0,0.0,0.0,E_sym.*t341.*(-4.266666666666667e-11),E_sym.*t365.*1.421066666666666e-8,E_sym.*t410.*4.75111111111111e-9,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,106]);
end
if nargout > 6
    t448 = mu_v_sym.*t178.*t195;
    t449 = mu_v_sym.*t176.*t195;
    t450 = mu_v_sym.*t225.*t239;
    t451 = mu_v_sym.*t223.*t239;
    t452 = mu_v_sym.*t267.*t283;
    t453 = mu_v_sym.*t269.*t283;
    out7 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t448,-mu_v_sym.*t224.*t239,t452,0.0,0.0,0.0,t449,t450,-mu_v_sym.*t268.*t283,0.0,0.0,0.0,-mu_v_sym.*t177.*t195,t451,t453,0.0,0.0,0.0,-mu_v_sym.*t179.*t195,-mu_v_sym.*t226.*t239,-mu_v_sym.*t270.*t283,-mu_u_sym.*t316.*t344,-mu_u_sym.*t366.*t392,-mu_u_sym.*t411.*t435,-mu_v_sym.*t181.*t195,-mu_v_sym.*t228.*t239,-mu_v_sym.*t259.*t283,mu_u_sym.*t322.*t344,-mu_u_sym.*t373.*t392,mu_u_sym.*t417.*t435,-mu_v_sym.*t170.*t195,-mu_v_sym.*t230.*t239,-mu_v_sym.*t274.*t283,mu_u_sym.*t327.*t344,mu_u_sym.*t372.*t392,-mu_u_sym.*t418.*t435,-mu_v_sym.*t175.*t195,-mu_v_sym.*t222.*t239,-mu_v_sym.*t276.*t283,-mu_u_sym.*t307.*t344,mu_u_sym.*t379.*t392,mu_u_sym.*t423.*t435,-t448,mu_v_sym.*t224.*t239,-t452,0.0,0.0,0.0,-t449,-t450,mu_v_sym.*t268.*t283,0.0,0.0,0.0,mu_v_sym.*t177.*t195,-t451,-t453,0.0,0.0,0.0,0.0,0.0,0.0,mu_u_sym.*t333.*t344,mu_u_sym.*t382.*t392,mu_u_sym.*t426.*t435,0.0,0.0,0.0,-mu_u_sym.*t334.*t344,mu_u_sym.*t385.*t392,-mu_u_sym.*t427.*t435,0.0,0.0,0.0,-mu_u_sym.*t314.*t344,-mu_u_sym.*t386.*t392,mu_u_sym.*t431.*t435,0.0,0.0,0.0,mu_u_sym.*t341.*t344,-mu_u_sym.*t365.*t392,-mu_u_sym.*t410.*t435,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,106]);
end
if nargout > 7
    out8 = 1.0;
end