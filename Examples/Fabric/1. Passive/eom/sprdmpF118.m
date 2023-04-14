function [out1,out2,out3,out4,out5,out6,out7,out8] = sprdmpF118(in1,in2,s)
%SPRDMPF118
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF118(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    06-Jul-2019 07:26:50

E_sym = in1(:,1);
mu_u_sym = in1(:,4);
mu_v_sym = in1(:,3);
mu_pow_sym = in1(:,2);
phi_sym = in1(:,5);
q43 = in2(:,43);
q44 = in2(:,44);
q45 = in2(:,45);
q46 = in2(:,46);
q47 = in2(:,47);
q48 = in2(:,48);
q49 = in2(:,49);
q50 = in2(:,50);
q51 = in2(:,51);
q52 = in2(:,52);
q53 = in2(:,53);
q54 = in2(:,54);
q55 = in2(:,55);
q56 = in2(:,56);
u43 = in2(:,155);
u44 = in2(:,156);
u45 = in2(:,157);
u46 = in2(:,158);
u47 = in2(:,159);
u48 = in2(:,160);
u49 = in2(:,161);
u50 = in2(:,162);
u51 = in2(:,163);
u52 = in2(:,164);
u53 = in2(:,165);
u54 = in2(:,166);
u55 = in2(:,167);
u56 = in2(:,168);
t2 = q46.^2;
t3 = q47.^2;
t4 = q48.^2;
t5 = q49.^2;
t6 = t2+t3+t4+t5;
t7 = 1.0./t6;
t8 = q46.*q49.*t7.*2.0;
t9 = t4.*t7;
t10 = t5.*t7;
t11 = q46.*q47.*t7.*2.0;
t12 = t3.*t7;
t13 = 1.0./sqrt(t6);
t14 = q43-q50;
t15 = q44-q51;
t16 = 1.0./t6.^(3.0./2.0);
t17 = q45-q52;
t18 = q46.*t13.*t14;
t19 = q49.*t13.*t15;
t45 = q48.*t13.*t17;
t20 = t18+t19-t45;
t21 = q46.*t13.*t15;
t22 = q47.*t13.*t17;
t37 = q49.*t13.*t14;
t23 = t21+t22-t37;
t24 = t13.*t15;
t25 = q46.*q49.*t14.*t16;
t49 = t2.*t15.*t16;
t50 = q46.*q47.*t16.*t17;
t26 = t24+t25-t49-t50;
t27 = t13.*t17;
t28 = q46.*q47.*t15.*t16;
t47 = t2.*t16.*t17;
t48 = q46.*q48.*t14.*t16;
t29 = t27+t28-t47-t48;
t30 = t13.*t14;
t31 = q46.*q48.*t16.*t17;
t51 = t2.*t14.*t16;
t52 = q46.*q49.*t15.*t16;
t32 = t30+t31-t51-t52;
t33 = q46.*q47.*t14.*t16;
t34 = q46.*q48.*t15.*t16;
t35 = q46.*q49.*t16.*t17;
t36 = t33+t34+t35;
t38 = q48.*t13.*t14;
t39 = q46.*t13.*t17;
t46 = q47.*t13.*t15;
t40 = t38+t39-t46;
t41 = q47.*t13.*t14;
t42 = q48.*t13.*t15;
t43 = q49.*t13.*t17;
t44 = t41+t42+t43;
t53 = q47.*t13;
t54 = q53.^2;
t55 = q54.^2;
t56 = q55.^2;
t57 = q56.^2;
t58 = t54+t55+t56+t57;
t59 = 1.0./sqrt(t58);
t68 = q54.*t59;
t60 = t53-t68;
t61 = q48.*t13;
t63 = q55.*t59;
t62 = t61-t63;
t72 = t2.*t16;
t64 = t13-t72;
t65 = 1.0./t6.^2;
t66 = q46.*t13;
t73 = q53.*t59;
t67 = t66-t73;
t69 = q49.*t13;
t71 = q56.*t59;
t70 = t69-t71;
t74 = q47.*q48.*t14.*t16;
t84 = t3.*t15.*t16;
t75 = t24+t50+t74-t84;
t76 = t3.*t14.*t16;
t77 = q47.*q48.*t15.*t16;
t78 = q47.*q49.*t16.*t17;
t79 = -t30+t76+t77+t78;
t80 = q47.*q49.*t14.*t16;
t85 = t3.*t16.*t17;
t81 = t27-t28+t80-t85;
t82 = q47.*q49.*t15.*t16;
t86 = q47.*q48.*t16.*t17;
t83 = t33+t82-t86;
t87 = q46.*q47.*t16.*t40;
t89 = t3.*t16;
t88 = t13-t89;
t90 = q46.*q47.*t16.*t70.*2.0;
t91 = q46.*q48.*t16.*t20;
t92 = q47.*q48.*t16.*t44;
t100 = t4.*t14.*t16;
t93 = t30-t31+t77-t100;
t94 = t4.*t15.*t16;
t95 = q48.*q49.*t16.*t17;
t96 = -t24+t74+t94+t95;
t97 = q48.*q49.*t15.*t16;
t101 = t4.*t16.*t17;
t98 = t27+t48+t97-t101;
t102 = q48.*q49.*t14.*t16;
t99 = t34+t86-t102;
t103 = q46.*q48.*t16.*t60.*2.0;
t104 = t13.*t67.*2.0;
t106 = t4.*t16;
t105 = t13-t106;
t107 = t13.*t23;
t108 = q47.*q49.*t16.*t44;
t116 = t5.*t14.*t16;
t109 = t30+t52+t78-t116;
t117 = t5.*t15.*t16;
t110 = t24-t25+t95-t117;
t111 = t5.*t16.*t17;
t112 = -t27+t80+t97+t111;
t113 = t35-t82+t102;
t114 = q46.*q49.*t16.*t23;
t115 = q48.*q49.*t16.*t44;
t118 = q47.*q49.*t16.*t23;
t119 = t13.*t62.*2.0;
t122 = t5.*t16;
t120 = t13-t122;
t121 = q46.*q49.*t16.*t62.*2.0;
t123 = q47.*q49.*t16.*t62.*2.0;
t124 = q46.*q48.*t7.*2.0;
t125 = q47.*q48.*t7.*2.0;
t126 = t2.*t7;
t127 = q47.*q49.*t7.*2.0;
t128 = q48.*q49.*t7.*2.0;
t129 = 1.0./t58.^(3.0./2.0);
t131 = t54.*t129;
t130 = t59-t131;
t133 = t55.*t129;
t132 = t59-t133;
t134 = q49.*q53.*q54.*t13.*t129.*2.0;
t135 = q47.*q53.*q55.*t13.*t129.*2.0;
t137 = t56.*t129;
t136 = t59-t137;
t140 = t57.*t129;
t138 = t59-t140;
t139 = q48.*q53.*q56.*t13.*t129.*2.0;
t141 = q48.*q54.*q56.*t13.*t129.*2.0;
t142 = phi_sym./2.0;
t143 = cos(t142);
t144 = t143./2.5e1;
t145 = sin(t142);
t146 = t143./4.0;
t147 = t145./2.5e1;
t148 = t146-t147;
t149 = t143.*(8.1e1./5.0e2);
t150 = t145./4.0;
t151 = t144+t150;
t152 = t145.*(8.1e1./5.0e2);
t153 = t144+t152;
t154 = t13.*t20;
t155 = q48.*t13.*t29;
t156 = q47.*t13.*t36;
t157 = t2.*t16.*t20;
t158 = q46.*q48.*t16.*t40;
t159 = q46.*q47.*t16.*t44;
t160 = q47.*t13.*t79;
t161 = q46.*t13.*t83;
t162 = t3.*t16.*t44;
t163 = q46.*q47.*t16.*t20;
t164 = q47.*q48.*t16.*t40;
t165 = t13.*t40;
t166 = q48.*t13.*t93;
t167 = q46.*t13.*t98;
t168 = q47.*t13.*t96;
t169 = q49.*t13.*t99;
t170 = q48.*q49.*t16.*t23;
t184 = t4.*t16.*t40;
t171 = t91+t92+t165+t166+t167+t168+t169+t170-t184;
t172 = q49.*t13.*t109;
t173 = q47.*t13.*t112;
t174 = t5.*t16.*t23;
t175 = q46.*q49.*t16.*t20;
t186 = q46.*t13.*t110;
t187 = q48.*t13.*t113;
t188 = q48.*q49.*t16.*t40;
t176 = -t107+t108+t172+t173+t174+t175-t186-t187-t188;
t177 = t8+t125;
t178 = t124-t127;
t179 = -t9-t10+t12+t126;
t197 = q46.*t13.*t32;
t198 = q49.*t13.*t26;
t180 = t114-t154+t155+t156+t157-t158+t159-t197-t198;
t181 = t180.*u46;
t199 = t13.*t44;
t200 = q48.*t13.*t75;
t201 = q49.*t13.*t81;
t182 = t118+t160+t161+t162+t163-t164-t199-t200-t201;
t183 = t182.*u47;
t185 = t171.*u48;
t189 = t176.*u49;
t190 = t178.*u45;
t191 = t177.*u51;
t192 = t179.*u50;
t202 = t177.*u44;
t203 = t178.*u52;
t204 = t179.*u43;
t193 = t181+t183+t185+t189+t190+t191+t192-t202-t203-t204;
t194 = abs(t193);
t195 = mu_pow_sym-1.0;
t196 = t194.^t195;
t205 = q49.*t13.*t32;
t206 = q48.*t13.*t36;
t207 = t2.*t16.*t23;
t208 = q46.*q48.*t16.*t44;
t209 = q47.*t13.*t75;
t210 = q48.*t13.*t79;
t211 = t3.*t16.*t40;
t212 = q46.*q47.*t16.*t23;
t213 = q48.*t13.*t96;
t214 = q46.*t13.*t99;
t215 = t4.*t16.*t44;
t216 = q46.*q48.*t16.*t23;
t217 = q48.*q49.*t16.*t20;
t218 = q46.*t13.*t109;
t219 = q49.*t13.*t110;
t220 = q48.*t13.*t112;
t221 = q47.*t13.*t113;
t222 = q47.*q49.*t16.*t40;
t233 = t5.*t16.*t20;
t223 = t114+t115+t154+t218+t219+t220+t221+t222-t233;
t224 = t11+t128;
t225 = t8-t125;
t226 = t9-t10-t12+t126;
t241 = q46.*t13.*t26;
t242 = q47.*t13.*t29;
t227 = t87-t107-t175+t205+t206+t207+t208-t241-t242;
t228 = t227.*u46;
t243 = q46.*t13.*t81;
t244 = q49.*t13.*t83;
t245 = q47.*q49.*t16.*t20;
t229 = t92-t165+t209+t210+t211+t212-t243-t244-t245;
t230 = t229.*u47;
t246 = q47.*t13.*t93;
t247 = q49.*t13.*t98;
t231 = t164-t199+t213+t214+t215+t216-t217-t246-t247;
t232 = t231.*u48;
t234 = t223.*u49;
t235 = t225.*u43;
t236 = t224.*u52;
t237 = t226.*u51;
t248 = t224.*u45;
t249 = t225.*u50;
t250 = t226.*u44;
t238 = t228+t230+t232+t234+t235+t236+t237-t248-t249-t250;
t239 = abs(t238);
t240 = t239.^t195;
t251 = q47.*t13.*t26;
t252 = q49.*t13.*t36;
t253 = t2.*t16.*t40;
t254 = q46.*q49.*t16.*t44;
t255 = q46.*t13.*t75;
t256 = q49.*t13.*t79;
t257 = q47.*t13.*t81;
t258 = q48.*t13.*t83;
t259 = q47.*q48.*t16.*t20;
t273 = t3.*t16.*t23;
t260 = t87+t107+t108+t255+t256+t257+t258+t259-t273;
t261 = q48.*t13.*t98;
t262 = q49.*t13.*t96;
t263 = t4.*t16.*t20;
t264 = q49.*t13.*t112;
t265 = q46.*t13.*t113;
t266 = t5.*t16.*t44;
t267 = q46.*q49.*t16.*t40;
t268 = t124+t127;
t269 = t11-t128;
t270 = -t9+t10-t12+t126;
t285 = q46.*t13.*t29;
t286 = q48.*t13.*t32;
t271 = t91-t165-t212+t251+t252+t253+t254-t285-t286;
t272 = t271.*u46;
t274 = t260.*u47;
t287 = q46.*t13.*t93;
t288 = q47.*t13.*t99;
t289 = q47.*q48.*t16.*t23;
t275 = t115-t154+t158+t261+t262+t263-t287-t288-t289;
t276 = t275.*u48;
t290 = q47.*t13.*t109;
t291 = q48.*t13.*t110;
t277 = -t118-t199+t217+t264+t265+t266+t267-t290-t291;
t278 = t277.*u49;
t279 = t269.*u44;
t280 = t268.*u50;
t281 = t270.*u52;
t292 = t268.*u43;
t293 = t269.*u51;
t294 = t270.*u45;
t282 = t272+t274+t276+t278+t279+t280+t281-t292-t293-t294;
t283 = abs(t282);
t284 = t283.^t195;
t295 = t13.*t60.*2.0;
t296 = t2.*t16.*t60.*2.0;
t297 = q47.*t13.*t64.*2.0;
t298 = q47.*t2.*t65.*2.0;
t299 = q46.*q48.*t16.*t70.*2.0;
t300 = q46.*q47.*t16.*t60.*2.0;
t301 = q47.*q48.*t16.*t70.*2.0;
t302 = t13.*t70.*2.0;
t303 = q48.*q49.*t16.*t62.*2.0;
t304 = t5.*t16.*t62.*2.0;
t305 = q48.*t13.*t120.*2.0;
t306 = q48.*t5.*t65.*2.0;
t307 = q46.*q49.*t16.*t60.*2.0;
t329 = q47.*q49.*t16.*t67.*2.0;
t330 = q48.*q49.*t16.*t70.*2.0;
t308 = -t119+t304+t305+t306+t307-t329-t330;
t309 = q49.*q53.*q55.*t13.*t129.*2.0;
t310 = q46.*t13.*t132.*2.0;
t311 = q47.*q53.*q54.*t13.*t129.*2.0;
t312 = q49.*q54.*q55.*t13.*t129.*2.0;
t313 = q49.*t13.*t136.*2.0;
t314 = q48.*q55.*q56.*t13.*t129.*2.0;
t337 = q46.*q54.*q55.*t13.*t129.*2.0;
t315 = t135+t313+t314-t337;
t316 = q47.*q53.*q56.*t13.*t129.*2.0;
t318 = q46.*q47.*t16.*t67.*2.0;
t317 = t121-t295+t296+t297+t298-t299-t318;
t319 = t317.*u46;
t320 = t3.*t16.*t67.*2.0;
t321 = q46.*t13.*t88.*2.0;
t322 = q46.*t3.*t65.*2.0;
t323 = -t104-t123-t300+t301+t320+t321+t322;
t324 = t4.*t16.*t70.*2.0;
t325 = q49.*t13.*t105.*2.0;
t326 = q49.*t4.*t65.*2.0;
t327 = q47.*q48.*t16.*t67.*2.0;
t328 = -t103-t302-t303+t324+t325+t326+t327;
t331 = t308.*u49;
t332 = q47.*t13.*t130.*2.0;
t333 = q46.*q53.*q54.*t13.*t129.*2.0;
t334 = -t139+t309+t332+t333;
t335 = t141+t310+t311-t312;
t336 = t335.*u54;
t338 = t315.*u55;
t339 = q48.*t13.*t138.*2.0;
t340 = q46.*q54.*q56.*t13.*t129.*2.0;
t341 = q49.*q55.*q56.*t13.*t129.*2.0;
t342 = -t316+t339+t340+t341;
t346 = t323.*u47;
t347 = t328.*u48;
t348 = t334.*u53;
t349 = t342.*u56;
t343 = t319+t331+t336+t338-t346-t347-t348-t349;
t344 = abs(t343);
t345 = t344.^t195;
t350 = t2.*t16.*t62.*2.0;
t351 = q48.*t13.*t64.*2.0;
t352 = q48.*t2.*t65.*2.0;
t353 = q46.*q48.*t16.*t62.*2.0;
t354 = q48.*q49.*t16.*t60.*2.0;
t355 = t3.*t16.*t70.*2.0;
t356 = q49.*t13.*t88.*2.0;
t357 = q49.*t3.*t65.*2.0;
t358 = q46.*q47.*t16.*t62.*2.0;
t359 = q47.*q49.*t16.*t70.*2.0;
t360 = q48.*q53.*q54.*t13.*t129.*2.0;
t361 = q46.*t13.*t136.*2.0;
t362 = q48.*q53.*q55.*t13.*t129.*2.0;
t363 = q47.*q55.*q56.*t13.*t129.*2.0;
t364 = q47.*t13.*t138.*2.0;
t365 = q49.*q54.*q56.*t13.*t129.*2.0;
t389 = q46.*q55.*q56.*t13.*t129.*2.0;
t366 = t139+t364+t365-t389;
t368 = q46.*q48.*t16.*t67.*2.0;
t367 = t90-t119-t307+t350+t351+t352-t368;
t369 = t367.*u46;
t370 = t4.*t16.*t67.*2.0;
t371 = q46.*t13.*t105.*2.0;
t372 = q46.*t4.*t65.*2.0;
t373 = -t104-t301-t353+t354+t370+t371+t372;
t395 = q47.*q49.*t16.*t60.*2.0;
t374 = -t302-t327+t355+t356+t357+t358-t395;
t375 = t374.*u47;
t376 = t5.*t16.*t60.*2.0;
t377 = q47.*t13.*t120.*2.0;
t378 = q47.*t5.*t65.*2.0;
t379 = q48.*q49.*t16.*t67.*2.0;
t380 = -t121-t295-t359+t376+t377+t378+t379;
t381 = q48.*t13.*t130.*2.0;
t382 = q46.*q53.*q55.*t13.*t129.*2.0;
t383 = -t134+t316+t381+t382;
t384 = q49.*t13.*t132.*2.0;
t385 = q47.*q54.*q56.*t13.*t129.*2.0;
t386 = t337-t360+t384+t385;
t387 = t312+t361+t362-t363;
t388 = t387.*u55;
t390 = t366.*u56;
t394 = t373.*u48;
t396 = t380.*u49;
t397 = t383.*u53;
t398 = t386.*u54;
t391 = t369+t375+t388+t390-t394-t396-t397-t398;
t392 = abs(t391);
t393 = t392.^t195;
t399 = t2.*t16.*t70.*2.0;
t400 = q49.*t13.*t64.*2.0;
t401 = q49.*t2.*t65.*2.0;
t402 = q47.*q48.*t16.*t60.*2.0;
t403 = t4.*t16.*t60.*2.0;
t404 = q47.*t13.*t105.*2.0;
t405 = q47.*t4.*t65.*2.0;
t406 = q46.*q49.*t16.*t70.*2.0;
t407 = q48.*t13.*t132.*2.0;
t408 = q47.*q54.*q55.*t13.*t129.*2.0;
t409 = q46.*t13.*t138.*2.0;
t410 = q49.*q53.*q56.*t13.*t129.*2.0;
t411 = -t141+t363+t409+t410;
out1 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t9+t10-t2.*t7-t3.*t7,-t8-q47.*q48.*t7.*2.0,t124-q47.*q49.*t7.*2.0,t114+t155+t156+t157+t159-t13.*t20-q49.*t13.*t26-q46.*t13.*t32-q46.*q48.*t16.*t40,t118+t160+t161+t162+t163-t13.*t44-q48.*t13.*t75-q49.*t13.*t81-q47.*q48.*t16.*t40,t171,t176,t179,t177,-t124+t127,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t8-q47.*q48.*t7.*2.0,-t9+t10+t12-t2.*t7,-t11-q48.*q49.*t7.*2.0,t87+t205+t206+t207+t208-t13.*t23-q46.*t13.*t26-q47.*t13.*t29-q46.*q49.*t16.*t20,t92+t209+t210+t211+t212-t13.*t40-q46.*t13.*t81-q49.*t13.*t83-q47.*q49.*t16.*t20,t164+t213+t214+t215+t216-t13.*t44-q47.*t13.*t93-q49.*t13.*t98-q48.*q49.*t16.*t20,t223,-t8+t125,t226,t224,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,q46.*q48.*t7.*-2.0-q47.*q49.*t7.*2.0,t11-q48.*q49.*t7.*2.0,t9-t10+t12-t2.*t7,t91+t251+t252+t253+t254-t13.*t40-q46.*t13.*t29-q48.*t13.*t32-q46.*q47.*t16.*t23,t260,t115+t158+t261+t262+t263-t13.*t20-q46.*t13.*t93-q47.*t13.*t99-q47.*q48.*t16.*t23,-t118+t217+t264+t265+t266+t267-t13.*t44-q47.*t13.*t109-q48.*t13.*t110,t268,-t11+t128,t270,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t121+t296+t297+t298-t13.*t60.*2.0-q46.*q47.*t16.*t67.*2.0-q46.*q48.*t16.*t70.*2.0,t104+t123+t300-q46.*t3.*t65.*2.0-q46.*t13.*t88.*2.0-t3.*t16.*t67.*2.0-q47.*q48.*t16.*t70.*2.0,t103+t302+t303-q49.*t4.*t65.*2.0-q49.*t13.*t105.*2.0-t4.*t16.*t70.*2.0-q47.*q48.*t16.*t67.*2.0,t308,0.0,0.0,0.0,t139-q47.*t13.*t130.*2.0-q46.*q53.*q54.*t13.*t129.*2.0-q49.*q53.*q55.*t13.*t129.*2.0,t141+t310+t311-q49.*q54.*q55.*t13.*t129.*2.0,t315,t316-q48.*t13.*t138.*2.0-q46.*q54.*q56.*t13.*t129.*2.0-q49.*q55.*q56.*t13.*t129.*2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t90+t350+t351+t352-t13.*t62.*2.0-q46.*q49.*t16.*t60.*2.0-q46.*q48.*t16.*t67.*2.0,t355+t356+t357+t358-t13.*t70.*2.0-q47.*q49.*t16.*t60.*2.0-q47.*q48.*t16.*t67.*2.0,t104+t301+t353-q46.*t4.*t65.*2.0-q46.*t13.*t105.*2.0-t4.*t16.*t67.*2.0-q48.*q49.*t16.*t60.*2.0,t121+t295+t359-q47.*t5.*t65.*2.0-q47.*t13.*t120.*2.0-t5.*t16.*t60.*2.0-q48.*q49.*t16.*t67.*2.0,0.0,0.0,0.0,t134-q48.*t13.*t130.*2.0-q46.*q53.*q55.*t13.*t129.*2.0-q47.*q53.*q56.*t13.*t129.*2.0,t360-q49.*t13.*t132.*2.0-q46.*q54.*q55.*t13.*t129.*2.0-q47.*q54.*q56.*t13.*t129.*2.0,t312+t361+t362-q47.*q55.*q56.*t13.*t129.*2.0,t366,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t103+t399+t400+t401-t13.*t70.*2.0-q46.*q47.*t16.*t62.*2.0-q46.*q49.*t16.*t67.*2.0,t90+t119+t402-q48.*t3.*t65.*2.0-q48.*t13.*t88.*2.0-t3.*t16.*t62.*2.0-q47.*q49.*t16.*t67.*2.0,t299+t403+t404+t405-t13.*t60.*2.0-q47.*q48.*t16.*t62.*2.0-q48.*q49.*t16.*t67.*2.0,t104-t123+t354+t406-q46.*t5.*t65.*2.0-q46.*t13.*t120.*2.0-t5.*t16.*t67.*2.0,0.0,0.0,0.0,t135-q49.*t13.*t130.*2.0-q46.*q53.*q56.*t13.*t129.*2.0-q48.*q53.*q54.*t13.*t129.*2.0,t134+t407+t408-q46.*q54.*q56.*t13.*t129.*2.0,t309-q47.*t13.*t136.*2.0-q46.*q55.*q56.*t13.*t129.*2.0-q48.*q54.*q55.*t13.*t129.*2.0,t411,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[106,6]);
if nargout > 1
    t413 = q46.*q49.*t16.*t67.*2.0;
    t412 = t103-t302-t358+t399+t400+t401-t413;
    t414 = t412.*u46;
    t415 = t3.*t16.*t62.*2.0;
    t416 = q48.*t13.*t88.*2.0;
    t417 = q48.*t3.*t65.*2.0;
    t418 = -t90-t119+t329-t402+t415+t416+t417;
    t438 = q47.*q48.*t16.*t62.*2.0;
    t419 = -t295+t299-t379+t403+t404+t405-t438;
    t420 = t419.*u48;
    t421 = t5.*t16.*t67.*2.0;
    t422 = q46.*t13.*t120.*2.0;
    t423 = q46.*t5.*t65.*2.0;
    t424 = -t104+t123-t354-t406+t421+t422+t423;
    t425 = q49.*t13.*t130.*2.0;
    t426 = q46.*q53.*q56.*t13.*t129.*2.0;
    t427 = -t135+t360+t425+t426;
    t428 = t134-t340+t407+t408;
    t429 = t428.*u54;
    t430 = q47.*t13.*t136.*2.0;
    t431 = q48.*q54.*q55.*t13.*t129.*2.0;
    t432 = -t309+t389+t430+t431;
    t433 = t411.*u56;
    t437 = t418.*u47;
    t439 = t424.*u49;
    t440 = t427.*u53;
    t441 = t432.*u55;
    t434 = t414+t420+t429+t433-t437-t439-t440-t441;
    t435 = abs(t434);
    t436 = t435.^t195;
    t442 = t143.*t148;
    t443 = t147-t149;
    t444 = t143.*t443;
    t445 = t145.*t153;
    out2 = [E_sym.*(t145.*t148+t143.*t151-t143.*t153+t145.*(t145./2.5e1-t149)-q46.*t13.*t20-q49.*t13.*t23+q48.*t13.*t40-q47.*t13.*t44).*(-2.666666666666667e-4);E_sym.*(t143.^2.*2.728750558000001e-14+t145.^2.*2.728750558000001e-14-q46.*t13.*t23+q49.*t13.*t20-q47.*t13.*t40-q48.*t13.*t44).*(-2.666666666666667e-4);E_sym.*(t442+t444+t445-t145.*t151+q48.*t13.*t20-q47.*t13.*t23+q46.*t13.*t40+q49.*t13.*t44).*8.0e-4;E_sym.*(q46.*t13.*t60.*2.0+q49.*t13.*t62.*2.0-q47.*t13.*t67.*2.0-q48.*t13.*t70.*2.0).*4.266666666666667e-11;E_sym.*(q46.*t13.*t62.*2.0-q49.*t13.*t60.*2.0-q48.*t13.*t67.*2.0+q47.*t13.*t70.*2.0).*1.421066666666666e-8;E_sym.*(q48.*t13.*t60.*2.0-q47.*t13.*t62.*2.0+q46.*t13.*t70.*2.0-q49.*t13.*t67.*2.0).*4.75111111111111e-9];
end
if nargout > 2
    out3 = [-mu_v_sym.*t171.*t196.*u48+mu_v_sym.*t177.*t196.*u44+mu_v_sym.*t179.*t196.*u43-mu_v_sym.*t178.*t196.*u45-mu_v_sym.*t176.*t196.*u49-mu_v_sym.*t180.*t196.*u46-mu_v_sym.*t177.*t196.*u51-mu_v_sym.*t179.*t196.*u50-mu_v_sym.*t182.*t196.*u47+mu_v_sym.*t178.*t196.*u52;-mu_v_sym.*t225.*t240.*u43+mu_v_sym.*t224.*t240.*u45+mu_v_sym.*t226.*t240.*u44-mu_v_sym.*t223.*t240.*u49-mu_v_sym.*t227.*t240.*u46+mu_v_sym.*t225.*t240.*u50-mu_v_sym.*t224.*t240.*u52-mu_v_sym.*t229.*t240.*u47-mu_v_sym.*t226.*t240.*u51-mu_v_sym.*t231.*t240.*u48;-mu_v_sym.*t260.*t284.*u47+mu_v_sym.*t268.*t284.*u43-mu_v_sym.*t269.*t284.*u44+mu_v_sym.*t270.*t284.*u45-mu_v_sym.*t271.*t284.*u46-mu_v_sym.*t268.*t284.*u50+mu_v_sym.*t269.*t284.*u51-mu_v_sym.*t270.*t284.*u52-mu_v_sym.*t275.*t284.*u48-mu_v_sym.*t277.*t284.*u49;-mu_u_sym.*t308.*t345.*u49-mu_u_sym.*t317.*t345.*u46-mu_u_sym.*t315.*t345.*u55+mu_u_sym.*t323.*t345.*u47+mu_u_sym.*t328.*t345.*u48+mu_u_sym.*t334.*t345.*u53-mu_u_sym.*t335.*t345.*u54+mu_u_sym.*t342.*t345.*u56;-mu_u_sym.*t367.*t393.*u46+mu_u_sym.*t373.*t393.*u48-mu_u_sym.*t374.*t393.*u47-mu_u_sym.*t366.*t393.*u56+mu_u_sym.*t380.*t393.*u49+mu_u_sym.*t383.*t393.*u53+mu_u_sym.*t386.*t393.*u54-mu_u_sym.*t387.*t393.*u55;-mu_u_sym.*t412.*t436.*u46+mu_u_sym.*t418.*t436.*u47-mu_u_sym.*t411.*t436.*u56-mu_u_sym.*t419.*t436.*u48+mu_u_sym.*t424.*t436.*u49+mu_u_sym.*t427.*t436.*u53-mu_u_sym.*t428.*t436.*u54+mu_u_sym.*t432.*t436.*u55];
end
if nargout > 3
    out4 = [0.0;0.0;0.0;0.0;0.0;0.0];
end
if nargout > 4
    out5 = -t442-t444-t445+sqrt(t14.^2+t15.^2+t17.^2)+t145.*t151;
end
if nargout > 5
    t446 = E_sym.*t178.*2.666666666666667e-4;
    t447 = E_sym.*t225.*2.666666666666667e-4;
    t448 = E_sym.*t269.*8.0e-4;
    out6 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,E_sym.*t179.*(-2.666666666666667e-4),t447,E_sym.*t268.*(-8.0e-4),0.0,0.0,0.0,E_sym.*t177.*(-2.666666666666667e-4),E_sym.*t226.*(-2.666666666666667e-4),t448,0.0,0.0,0.0,t446,E_sym.*t224.*(-2.666666666666667e-4),E_sym.*t270.*(-8.0e-4),0.0,0.0,0.0,E_sym.*t180.*2.666666666666667e-4,E_sym.*t227.*2.666666666666667e-4,E_sym.*t271.*8.0e-4,E_sym.*t317.*4.266666666666667e-11,E_sym.*t367.*1.421066666666666e-8,E_sym.*t412.*4.75111111111111e-9,E_sym.*t182.*2.666666666666667e-4,E_sym.*t229.*2.666666666666667e-4,E_sym.*t260.*8.0e-4,E_sym.*t323.*(-4.266666666666667e-11),E_sym.*t374.*1.421066666666666e-8,E_sym.*t418.*(-4.75111111111111e-9),E_sym.*t171.*2.666666666666667e-4,E_sym.*t231.*2.666666666666667e-4,E_sym.*t275.*8.0e-4,E_sym.*t328.*(-4.266666666666667e-11),E_sym.*t373.*(-1.421066666666666e-8),E_sym.*t419.*4.75111111111111e-9,E_sym.*t176.*2.666666666666667e-4,E_sym.*t223.*2.666666666666667e-4,E_sym.*t277.*8.0e-4,E_sym.*t308.*4.266666666666667e-11,E_sym.*t380.*(-1.421066666666666e-8),E_sym.*t424.*(-4.75111111111111e-9),E_sym.*t179.*2.666666666666667e-4,-t447,E_sym.*t268.*8.0e-4,0.0,0.0,0.0,E_sym.*t177.*2.666666666666667e-4,E_sym.*t226.*2.666666666666667e-4,-t448,0.0,0.0,0.0,-t446,E_sym.*t224.*2.666666666666667e-4,E_sym.*t270.*8.0e-4,0.0,0.0,0.0,0.0,0.0,0.0,E_sym.*t334.*(-4.266666666666667e-11),E_sym.*t383.*(-1.421066666666666e-8),E_sym.*t427.*(-4.75111111111111e-9),0.0,0.0,0.0,E_sym.*t335.*4.266666666666667e-11,E_sym.*t386.*(-1.421066666666666e-8),E_sym.*t428.*4.75111111111111e-9,0.0,0.0,0.0,E_sym.*t315.*4.266666666666667e-11,E_sym.*t387.*1.421066666666666e-8,E_sym.*t432.*(-4.75111111111111e-9),0.0,0.0,0.0,E_sym.*t342.*(-4.266666666666667e-11),E_sym.*t366.*1.421066666666666e-8,E_sym.*t411.*4.75111111111111e-9,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,106]);
end
if nargout > 6
    t449 = mu_v_sym.*t179.*t196;
    t450 = mu_v_sym.*t177.*t196;
    t451 = mu_v_sym.*t226.*t240;
    t452 = mu_v_sym.*t224.*t240;
    t453 = mu_v_sym.*t268.*t284;
    t454 = mu_v_sym.*t270.*t284;
    out7 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t449,-mu_v_sym.*t225.*t240,t453,0.0,0.0,0.0,t450,t451,-mu_v_sym.*t269.*t284,0.0,0.0,0.0,-mu_v_sym.*t178.*t196,t452,t454,0.0,0.0,0.0,-mu_v_sym.*t180.*t196,-mu_v_sym.*t227.*t240,-mu_v_sym.*t271.*t284,-mu_u_sym.*t317.*t345,-mu_u_sym.*t367.*t393,-mu_u_sym.*t412.*t436,-mu_v_sym.*t182.*t196,-mu_v_sym.*t229.*t240,-mu_v_sym.*t260.*t284,mu_u_sym.*t323.*t345,-mu_u_sym.*t374.*t393,mu_u_sym.*t418.*t436,-mu_v_sym.*t171.*t196,-mu_v_sym.*t231.*t240,-mu_v_sym.*t275.*t284,mu_u_sym.*t328.*t345,mu_u_sym.*t373.*t393,-mu_u_sym.*t419.*t436,-mu_v_sym.*t176.*t196,-mu_v_sym.*t223.*t240,-mu_v_sym.*t277.*t284,-mu_u_sym.*t308.*t345,mu_u_sym.*t380.*t393,mu_u_sym.*t424.*t436,-t449,mu_v_sym.*t225.*t240,-t453,0.0,0.0,0.0,-t450,-t451,mu_v_sym.*t269.*t284,0.0,0.0,0.0,mu_v_sym.*t178.*t196,-t452,-t454,0.0,0.0,0.0,0.0,0.0,0.0,mu_u_sym.*t334.*t345,mu_u_sym.*t383.*t393,mu_u_sym.*t427.*t436,0.0,0.0,0.0,-mu_u_sym.*t335.*t345,mu_u_sym.*t386.*t393,-mu_u_sym.*t428.*t436,0.0,0.0,0.0,-mu_u_sym.*t315.*t345,-mu_u_sym.*t387.*t393,mu_u_sym.*t432.*t436,0.0,0.0,0.0,mu_u_sym.*t342.*t345,-mu_u_sym.*t366.*t393,-mu_u_sym.*t411.*t436,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,106]);
end
if nargout > 7
    out8 = 1.0;
end