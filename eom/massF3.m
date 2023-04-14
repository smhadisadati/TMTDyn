function [out1,out2,out3,out4] = massF3(in1,in2,s,ds,t_sym)
%MASSF3
%    [OUT1,OUT2,OUT3,OUT4] = MASSF3(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    10-Mar-2021 20:34:23

f_u1_ = in1(:,49);
f_u3_ = in1(:,51);
g_xsym = in1(:,33);
g_ysym = in1(:,34);
g_zsym = in1(:,35);
l_b2_ = in1(:,37);
l_s1_ = in1(:,39);
q1 = in2(1,:);
q2 = in2(2,:);
q3 = in2(3,:);
q4 = in2(4,:);
q5 = in2(5,:);
q6 = in2(6,:);
q7 = in2(7,:);
q8 = in2(8,:);
q9 = in2(9,:);
q10 = in2(10,:);
q11 = in2(11,:);
q12 = in2(12,:);
q13 = in2(13,:);
q14 = in2(14,:);
q15 = in2(15,:);
q16 = in2(16,:);
q17 = in2(17,:);
q18 = in2(18,:);
q19 = in2(19,:);
r_s21_ = in1(:,10);
r_s22_ = in1(:,11);
sigma_s_ = in1(:,1);
tau_u4_ = in1(:,52);
t2 = f_u1_+l_s1_;
t3 = f_u1_.*2.0;
t4 = f_u3_.*2.0;
t5 = l_b2_.*2.0;
t6 = l_s1_.*2.0;
t7 = r_s21_.^2;
t8 = r_s22_.^2;
t9 = s.^2;
t10 = s.^3;
t11 = q12.*s.*2.0;
t12 = q14.*s.*2.0;
t13 = q16.*s.*2.0;
t14 = -l_b2_;
t16 = sqrt(2.0);
t19 = f_u1_./2.0;
t20 = f_u3_./2.0;
t21 = l_b2_./2.0;
t22 = l_s1_./2.0;
t23 = s./2.0;
t24 = tau_u4_./2.0;
t15 = -t5;
t17 = t2.^2;
t18 = t2.^3;
t25 = q4.*t2.*2.0;
t26 = q6.*t2.*2.0;
t27 = q8.*t2.*2.0;
t28 = q10.*t2.*2.0;
t29 = -t8;
t30 = f_u3_+t14;
t31 = q13.*t9.*3.0;
t32 = q15.*t9.*3.0;
t33 = q17.*t9.*3.0;
t34 = -t20;
t35 = t7./4.0;
t36 = t8./4.0;
t37 = t2.*2.0;
t43 = (q18.*t9)./2.0;
t44 = (q19.*t10)./2.0;
t62 = s.*t2;
t38 = q5.*t17.*3.0;
t39 = q7.*t17.*3.0;
t40 = q9.*t17.*3.0;
t41 = q11.*t17.*3.0;
t42 = s.*t17.*3.0;
t45 = t4+t15;
t46 = t30.^2;
t47 = t30.^3;
t48 = q2.*t30.*2.0;
t49 = s.*t37;
t50 = t17./2.0;
t51 = t18./2.0;
t55 = t7+t29;
t56 = s.*t17.*(3.0./2.0);
t57 = (q1.*t30)./2.0;
t76 = t35+t36;
t85 = t19+t21+t22+t23+t34;
t52 = -t48;
t53 = q10.*t50;
t54 = q11.*t51;
t58 = q3.*t46.*3.0;
t59 = t46./2.0;
t60 = t47./2.0;
t61 = -t57;
t65 = sigma_s_.*t55.*pi;
t68 = t23.*t45;
t69 = s.*t46.*(3.0./2.0);
t70 = t18+t42;
t71 = q3.*t47.*(-1.0./2.0);
t72 = (t2.*t45)./2.0;
t73 = t2.*t46.*(3.0./2.0);
t75 = t17+t49;
t77 = t51+t56;
t78 = t50+t62;
t80 = t11+t25+t31+t38;
t81 = t12+t26+t32+t39;
t82 = t13+t27+t33+t40+1.0;
t63 = -t59;
t64 = -t60;
t66 = q2.*t59;
t67 = q3.*t60;
t74 = -t65;
t79 = q1+t52+t58;
t83 = t80.^2;
t84 = t81.^2;
t86 = t82.^2;
t87 = t65.*t76;
t88 = t74.*t76;
out1 = reshape([t74,0.0,0.0,0.0,0.0,0.0,0.0,t74,0.0,0.0,0.0,0.0,0.0,0.0,t74,0.0,0.0,0.0,0.0,0.0,0.0,t88,0.0,0.0,0.0,0.0,0.0,0.0,t88,0.0,0.0,0.0,0.0,0.0,0.0,t74.*(t7./2.0+t8./2.0)],[6,6]);
if nargout > 1
    t89 = (t2.*t79)./2.0;
    t90 = t28+t41+t79;
    t92 = t63+t68+t72;
    t93 = t64+t69+t73;
    t94 = t83+t84+t86;
    t91 = t23.*t90;
    t95 = 1.0./t94.^2;
    t96 = 1.0./sqrt(t94);
    t97 = t96.^3;
    t98 = s.*t96.*2.0;
    t99 = t9.*t96.*3.0;
    t100 = t17.*t96.*3.0;
    t101 = t37.*t96;
    t102 = t82.*t96;
    t115 = t24+t43+t44+t53+t54+t61+t66+t71+t89+t91;
    t103 = t102+1.0;
    t104 = s.*t86.*t97.*2.0;
    t106 = t9.*t86.*t97.*3.0;
    t111 = t17.*t86.*t97.*3.0;
    t112 = t37.*t86.*t97;
    t114 = t2.*t86.*t97.*-2.0;
    t116 = cos(t115);
    t117 = sin(t115);
    t105 = -t104;
    t107 = sqrt(t103);
    t108 = -t106;
    t113 = -t111;
    t118 = t116.^2;
    t119 = t117.^2;
    t123 = t101+t114;
    t109 = 1.0./t107;
    t120 = t98+t105;
    t121 = t99+t108;
    t122 = t100+t113;
    t110 = t109.^3;
    t124 = s.*t16.*t96.*t109.*t116;
    t125 = s.*t16.*t96.*t109.*t117;
    t126 = t9.*t16.*t96.*t109.*t116.*(3.0./2.0);
    t127 = t9.*t16.*t96.*t109.*t117.*(3.0./2.0);
    t128 = t16.*t17.*t96.*t109.*t116.*(3.0./2.0);
    t129 = t16.*t17.*t96.*t109.*t117.*(3.0./2.0);
    t130 = t2.*t16.*t96.*t109.*t116;
    t131 = t2.*t16.*t96.*t109.*t117;
    t132 = t16.*t80.*t96.*t109.*t116;
    t133 = t16.*t81.*t96.*t109.*t116;
    t134 = t16.*t80.*t96.*t109.*t117;
    t135 = t16.*t81.*t96.*t109.*t117;
    t137 = s.*t16.*t83.*t97.*t109.*t117;
    t138 = s.*t16.*t84.*t97.*t109.*t117;
    t139 = s.*t16.*t83.*t97.*t109.*t116;
    t140 = s.*t16.*t84.*t97.*t109.*t116;
    t155 = t9.*t16.*t83.*t97.*t109.*t116.*(3.0./2.0);
    t156 = t9.*t16.*t84.*t97.*t109.*t116.*(3.0./2.0);
    t157 = t9.*t16.*t83.*t97.*t109.*t117.*(3.0./2.0);
    t158 = t9.*t16.*t84.*t97.*t109.*t117.*(3.0./2.0);
    t163 = t16.*t17.*t83.*t97.*t109.*t116.*(3.0./2.0);
    t164 = t16.*t17.*t84.*t97.*t109.*t116.*(3.0./2.0);
    t165 = t16.*t17.*t83.*t97.*t109.*t117.*(3.0./2.0);
    t166 = t16.*t17.*t84.*t97.*t109.*t117.*(3.0./2.0);
    t171 = t2.*t16.*t83.*t97.*t109.*t116;
    t172 = t2.*t16.*t84.*t97.*t109.*t116;
    t173 = t2.*t16.*t83.*t97.*t109.*t117;
    t174 = t2.*t16.*t84.*t97.*t109.*t117;
    t188 = s.*t16.*t80.*t81.*t97.*t109.*t116;
    t190 = s.*t16.*t80.*t81.*t97.*t109.*t117;
    t191 = s.*t16.*t80.*t82.*t97.*t109.*t116;
    t192 = s.*t16.*t81.*t82.*t97.*t109.*t116;
    t193 = s.*t16.*t80.*t82.*t97.*t109.*t117;
    t194 = s.*t16.*t81.*t82.*t97.*t109.*t117;
    t207 = t9.*t16.*t80.*t81.*t97.*t109.*t116.*(3.0./2.0);
    t208 = t9.*t16.*t80.*t81.*t97.*t109.*t117.*(3.0./2.0);
    t212 = t9.*t16.*t80.*t82.*t97.*t109.*t116.*(3.0./2.0);
    t213 = t9.*t16.*t81.*t82.*t97.*t109.*t116.*(3.0./2.0);
    t215 = t9.*t16.*t80.*t82.*t97.*t109.*t117.*(3.0./2.0);
    t216 = t9.*t16.*t81.*t82.*t97.*t109.*t117.*(3.0./2.0);
    t219 = t16.*t17.*t80.*t81.*t97.*t109.*t116.*(3.0./2.0);
    t220 = t16.*t17.*t80.*t81.*t97.*t109.*t117.*(3.0./2.0);
    t223 = t16.*t17.*t80.*t82.*t97.*t109.*t116.*(3.0./2.0);
    t224 = t16.*t17.*t81.*t82.*t97.*t109.*t116.*(3.0./2.0);
    t226 = t16.*t17.*t80.*t82.*t97.*t109.*t117.*(3.0./2.0);
    t227 = t16.*t17.*t81.*t82.*t97.*t109.*t117.*(3.0./2.0);
    t233 = t2.*t16.*t80.*t81.*t97.*t109.*t116;
    t234 = t2.*t16.*t80.*t81.*t97.*t109.*t117;
    t240 = t2.*t16.*t80.*t82.*t97.*t109.*t116;
    t241 = t2.*t16.*t81.*t82.*t97.*t109.*t116;
    t243 = t2.*t16.*t80.*t82.*t97.*t109.*t117;
    t244 = t2.*t16.*t81.*t82.*t97.*t109.*t117;
    t136 = -t134;
    t141 = -t137;
    t142 = -t138;
    t143 = -t139;
    t144 = -t140;
    t145 = (t9.*t134)./4.0;
    t146 = (t10.*t134)./4.0;
    t147 = (t9.*t135)./4.0;
    t148 = (t10.*t135)./4.0;
    t149 = (t9.*t132)./4.0;
    t150 = (t10.*t132)./4.0;
    t151 = (t9.*t133)./4.0;
    t152 = (t10.*t133)./4.0;
    t159 = -t155;
    t160 = -t156;
    t161 = -t157;
    t162 = -t158;
    t167 = -t163;
    t168 = -t164;
    t169 = -t165;
    t170 = -t166;
    t175 = -t171;
    t176 = -t172;
    t177 = -t173;
    t178 = -t174;
    t179 = (t77.*t132)./2.0;
    t180 = (t77.*t133)./2.0;
    t181 = (t77.*t134)./2.0;
    t182 = (t77.*t135)./2.0;
    t184 = (t78.*t132)./2.0;
    t185 = (t78.*t133)./2.0;
    t186 = (t78.*t134)./2.0;
    t187 = (t78.*t135)./2.0;
    t195 = -t188;
    t196 = -t190;
    t197 = -t193;
    t198 = (t85.*t132)./2.0;
    t199 = (t85.*t133)./2.0;
    t200 = (t85.*t134)./2.0;
    t201 = (t85.*t135)./2.0;
    t202 = t16.*t23.*t82.*t83.*t95.*t110.*t116;
    t203 = t16.*t23.*t82.*t84.*t95.*t110.*t116;
    t204 = t16.*t23.*t82.*t83.*t95.*t110.*t117;
    t205 = t16.*t23.*t82.*t84.*t95.*t110.*t117;
    t209 = t9.*t16.*t82.*t83.*t95.*t110.*t117.*(3.0./4.0);
    t210 = t9.*t16.*t82.*t84.*t95.*t110.*t117.*(3.0./4.0);
    t211 = -t207;
    t214 = -t208;
    t217 = t9.*t16.*t82.*t83.*t95.*t110.*t116.*(3.0./4.0);
    t218 = t9.*t16.*t82.*t84.*t95.*t110.*t116.*(3.0./4.0);
    t221 = -t215;
    t222 = -t219;
    t225 = -t220;
    t228 = t16.*t17.*t82.*t83.*t95.*t110.*t116.*(3.0./4.0);
    t229 = t16.*t17.*t82.*t84.*t95.*t110.*t116.*(3.0./4.0);
    t230 = t16.*t17.*t82.*t83.*t95.*t110.*t117.*(3.0./4.0);
    t231 = t16.*t17.*t82.*t84.*t95.*t110.*t117.*(3.0./4.0);
    t232 = -t226;
    t235 = (t2.*t16.*t82.*t83.*t95.*t110.*t116)./2.0;
    t236 = (t2.*t16.*t82.*t84.*t95.*t110.*t116)./2.0;
    t237 = (t2.*t16.*t82.*t83.*t95.*t110.*t117)./2.0;
    t238 = (t2.*t16.*t82.*t84.*t95.*t110.*t117)./2.0;
    t239 = -t233;
    t242 = -t234;
    t245 = -t243;
    t246 = (t92.*t132)./2.0;
    t247 = (t92.*t133)./2.0;
    t248 = (t93.*t132)./2.0;
    t249 = (t93.*t133)./2.0;
    t250 = (t92.*t134)./2.0;
    t251 = (t92.*t135)./2.0;
    t252 = (t93.*t134)./2.0;
    t253 = (t93.*t135)./2.0;
    t256 = t16.*t23.*t80.*t81.*t82.*t95.*t110.*t116;
    t257 = t16.*t23.*t80.*t81.*t82.*t95.*t110.*t117;
    t258 = s.*t16.*t80.*t81.*t82.*t95.*t110.*t116.*(-1.0./2.0);
    t259 = s.*t16.*t80.*t81.*t82.*t95.*t110.*t117.*(-1.0./2.0);
    t260 = t9.*t16.*t80.*t81.*t82.*t95.*t110.*t116.*(3.0./4.0);
    t261 = t9.*t16.*t80.*t81.*t82.*t95.*t110.*t117.*(3.0./4.0);
    t264 = t16.*t17.*t80.*t81.*t82.*t95.*t110.*t116.*(3.0./4.0);
    t265 = t16.*t17.*t80.*t81.*t82.*t95.*t110.*t117.*(3.0./4.0);
    t268 = (t2.*t16.*t80.*t81.*t82.*t95.*t110.*t116)./2.0;
    t269 = (t2.*t16.*t80.*t81.*t82.*t95.*t110.*t117)./2.0;
    t272 = (t16.*t80.*t96.*t110.*t116.*t120)./4.0;
    t273 = (t16.*t81.*t96.*t110.*t116.*t120)./4.0;
    t274 = (t16.*t80.*t96.*t110.*t117.*t120)./4.0;
    t275 = (t16.*t81.*t96.*t110.*t117.*t120)./4.0;
    t277 = (t16.*t80.*t96.*t110.*t116.*t121)./4.0;
    t278 = (t16.*t81.*t96.*t110.*t116.*t121)./4.0;
    t279 = (t16.*t80.*t96.*t110.*t117.*t121)./4.0;
    t280 = (t16.*t81.*t96.*t110.*t117.*t121)./4.0;
    t282 = (t16.*t80.*t96.*t110.*t116.*t122)./4.0;
    t283 = (t16.*t81.*t96.*t110.*t116.*t122)./4.0;
    t284 = (t16.*t80.*t96.*t110.*t117.*t122)./4.0;
    t285 = (t16.*t81.*t96.*t110.*t117.*t122)./4.0;
    t287 = (t16.*t80.*t96.*t110.*t116.*t123)./4.0;
    t288 = (t16.*t81.*t96.*t110.*t116.*t123)./4.0;
    t289 = (t16.*t80.*t96.*t110.*t117.*t123)./4.0;
    t290 = (t16.*t81.*t96.*t110.*t117.*t123)./4.0;
    t292 = t132+t135;
    t153 = -t151;
    t154 = -t152;
    t183 = -t181;
    t189 = -t186;
    t206 = -t200;
    t254 = -t250;
    t255 = -t252;
    t262 = -t260;
    t263 = -t261;
    t266 = -t264;
    t267 = -t265;
    t270 = -t268;
    t271 = -t269;
    t276 = -t274;
    t281 = -t279;
    t286 = -t284;
    t291 = -t289;
    t293 = t133+t136;
    t294 = t147+t149;
    t295 = t148+t150;
    t298 = t179+t182;
    t300 = t184+t187;
    t302 = t198+t201;
    t304 = t246+t251;
    t305 = t248+t253;
    t308 = t191+t194+t272+t275;
    t309 = t124+t144+t190+t203+t259;
    t310 = t125+t141+t188+t204+t258;
    t311 = t124+t143+t196+t202+t257;
    t312 = t125+t142+t195+t205+t256;
    t314 = t212+t216+t277+t280;
    t317 = t127+t162+t210+t211+t260;
    t318 = t126+t159+t214+t217+t261;
    t320 = t223+t227+t282+t285;
    t321 = t128+t167+t225+t228+t265;
    t324 = t129+t170+t222+t231+t264;
    t326 = t130+t175+t235+t242+t269;
    t329 = t131+t178+t238+t239+t268;
    t330 = t240+t244+t287+t290;
    t296 = t145+t153;
    t297 = t146+t154;
    t299 = t180+t183;
    t301 = t185+t189;
    t303 = t199+t206;
    t306 = t247+t254;
    t307 = t249+t255;
    t313 = t192+t197+t273+t276;
    t315 = t213+t221+t278+t281;
    t316 = t127+t161+t207+t209+t262;
    t319 = t126+t160+t208+t218+t263;
    t322 = t128+t168+t220+t229+t267;
    t323 = t129+t169+t219+t230+t266;
    t325 = t224+t232+t283+t286;
    t327 = t130+t176+t234+t236+t271;
    t328 = t131+t177+t233+t237+t270;
    t331 = t241+t245+t288+t291;
    out2 = reshape([0.0,0.0,0.0,t16.*t107.*t116.*t302+t16.*t107.*t117.*t303-(t16.*t85.*t107.*t116.*t292)./2.0-(t16.*t85.*t107.*t117.*t293)./2.0,t16.*t107.*t116.*t303-t16.*t107.*t117.*t302-(t16.*t85.*t107.*t116.*t293)./2.0+(t16.*t85.*t107.*t117.*t292)./2.0,t292.*t302+t293.*t303+t85.*t103.*t118+t85.*t103.*t119,0.0,0.0,0.0,-t16.*t107.*t116.*t304-t16.*t107.*t117.*t306+(t16.*t92.*t107.*t116.*t292)./2.0+(t16.*t92.*t107.*t117.*t293)./2.0,t16.*t107.*t117.*t304-t16.*t107.*t116.*t306+(t16.*t92.*t107.*t116.*t293)./2.0-(t16.*t92.*t107.*t117.*t292)./2.0,-t292.*t304-t293.*t306-t92.*t103.*t118-t92.*t103.*t119,0.0,0.0,0.0,t16.*t107.*t116.*t305+t16.*t107.*t117.*t307-(t16.*t93.*t107.*t116.*t292)./2.0-(t16.*t93.*t107.*t117.*t293)./2.0,-t16.*t107.*t117.*t305+t16.*t107.*t116.*t307-(t16.*t93.*t107.*t116.*t293)./2.0+(t16.*t93.*t107.*t117.*t292)./2.0,t292.*t305+t293.*t307+t93.*t103.*t118+t93.*t103.*t119,t75,0.0,0.0,t240.*t293.*(-1.0./2.0)+(t243.*t292)./2.0+t16.*t107.*t117.*t326+t16.*t107.*t116.*t328,(t240.*t292)./2.0+(t243.*t293)./2.0+t16.*t107.*t116.*t326-t16.*t107.*t117.*t328,t293.*t326+t292.*t328,t70,0.0,0.0,t16.*t107.*t117.*t321+t16.*t107.*t116.*t323-t16.*t17.*t80.*t82.*t97.*t109.*t116.*t293.*(3.0./4.0)+t16.*t17.*t80.*t82.*t97.*t109.*t117.*t292.*(3.0./4.0),t16.*t107.*t116.*t321-t16.*t107.*t117.*t323+t16.*t17.*t80.*t82.*t97.*t109.*t116.*t292.*(3.0./4.0)+t16.*t17.*t80.*t82.*t97.*t109.*t117.*t293.*(3.0./4.0),t293.*t321+t292.*t323,0.0,t75,0.0,t241.*t293.*(-1.0./2.0)+(t244.*t292)./2.0-t16.*t107.*t116.*t327+t16.*t107.*t117.*t329,(t241.*t292)./2.0+(t244.*t293)./2.0+t16.*t107.*t117.*t327+t16.*t107.*t116.*t329,-t292.*t327+t293.*t329,0.0,t70,0.0,-t16.*t107.*t116.*t322+t16.*t107.*t117.*t324-t16.*t17.*t81.*t82.*t97.*t109.*t116.*t293.*(3.0./4.0)+t16.*t17.*t81.*t82.*t97.*t109.*t117.*t292.*(3.0./4.0),t16.*t107.*t117.*t322+t16.*t107.*t116.*t324+t16.*t17.*t81.*t82.*t97.*t109.*t116.*t292.*(3.0./4.0)+t16.*t17.*t81.*t82.*t97.*t109.*t117.*t293.*(3.0./4.0),-t292.*t322+t293.*t324,0.0,0.0,t75,t16.*t107.*t116.*t331-t16.*t107.*t117.*t330+(t16.*t109.*t116.*t123.*t293)./4.0-(t16.*t109.*t117.*t123.*t292)./4.0,-t16.*t107.*t116.*t330-t16.*t107.*t117.*t331-(t16.*t109.*t116.*t123.*t292)./4.0-(t16.*t109.*t117.*t123.*t293)./4.0,t292.*t331-t293.*t330,0.0,0.0,t70,-t16.*t107.*t117.*t320+t16.*t107.*t116.*t325+(t16.*t109.*t116.*t122.*t293)./4.0-(t16.*t109.*t117.*t122.*t292)./4.0,-t16.*t107.*t116.*t320-t16.*t107.*t117.*t325-(t16.*t109.*t116.*t122.*t292)./4.0-(t16.*t109.*t117.*t122.*t293)./4.0,-t293.*t320+t292.*t325,0.0,0.0,0.0,t16.*t107.*t116.*t300+t16.*t107.*t117.*t301-(t16.*t78.*t107.*t116.*t292)./2.0-(t16.*t78.*t107.*t117.*t293)./2.0,t16.*t107.*t116.*t301-t16.*t107.*t117.*t300-(t16.*t78.*t107.*t116.*t293)./2.0+(t16.*t78.*t107.*t117.*t292)./2.0,t292.*t300+t293.*t301+t78.*t103.*t118+t78.*t103.*t119,0.0,0.0,0.0,t16.*t107.*t116.*t298+t16.*t107.*t117.*t299-(t16.*t77.*t107.*t116.*t292)./2.0-(t16.*t77.*t107.*t117.*t293)./2.0,t16.*t107.*t116.*t299-t16.*t107.*t117.*t298-(t16.*t77.*t107.*t116.*t293)./2.0+(t16.*t77.*t107.*t117.*t292)./2.0,t292.*t298+t293.*t299+t77.*t103.*t118+t77.*t103.*t119,t9,0.0,0.0,t191.*t293.*(-1.0./2.0)+t16.*t107.*t116.*t310+t16.*t107.*t117.*t311+t16.*t23.*t80.*t82.*t97.*t109.*t117.*t292,t16.*t107.*t116.*t311-t16.*t107.*t117.*t310+t16.*t23.*t80.*t82.*t97.*t109.*t116.*t292+t16.*t23.*t80.*t82.*t97.*t109.*t117.*t293,t292.*t310+t293.*t311,t10,0.0,0.0,t16.*t107.*t116.*t316+t16.*t107.*t117.*t318-t9.*t16.*t80.*t82.*t97.*t109.*t116.*t293.*(3.0./4.0)+t9.*t16.*t80.*t82.*t97.*t109.*t117.*t292.*(3.0./4.0),-t16.*t107.*t117.*t316+t16.*t107.*t116.*t318+t9.*t16.*t80.*t82.*t97.*t109.*t116.*t292.*(3.0./4.0)+t9.*t16.*t80.*t82.*t97.*t109.*t117.*t293.*(3.0./4.0),t292.*t316+t293.*t318,0.0,t9,0.0,t192.*t293.*(-1.0./2.0)-t16.*t107.*t116.*t309+t16.*t107.*t117.*t312+t16.*t23.*t81.*t82.*t97.*t109.*t117.*t292,t16.*t107.*t117.*t309+t16.*t107.*t116.*t312+t16.*t23.*t81.*t82.*t97.*t109.*t116.*t292+t16.*t23.*t81.*t82.*t97.*t109.*t117.*t293,-t292.*t309+t293.*t312,0.0,t10,0.0,t16.*t107.*t117.*t317-t16.*t107.*t116.*t319-t9.*t16.*t81.*t82.*t97.*t109.*t116.*t293.*(3.0./4.0)+t9.*t16.*t81.*t82.*t97.*t109.*t117.*t292.*(3.0./4.0),t16.*t107.*t116.*t317+t16.*t107.*t117.*t319+t9.*t16.*t81.*t82.*t97.*t109.*t116.*t292.*(3.0./4.0)+t9.*t16.*t81.*t82.*t97.*t109.*t117.*t293.*(3.0./4.0),t293.*t317-t292.*t319,0.0,0.0,t9,-t16.*t107.*t117.*t308+t16.*t107.*t116.*t313+(t16.*t109.*t116.*t120.*t293)./4.0-(t16.*t109.*t117.*t120.*t292)./4.0,-t16.*t107.*t116.*t308-t16.*t107.*t117.*t313-(t16.*t109.*t116.*t120.*t292)./4.0-(t16.*t109.*t117.*t120.*t293)./4.0,-t293.*t308+t292.*t313,0.0,0.0,t10,t16.*t107.*t116.*t315-t16.*t107.*t117.*t314+(t16.*t109.*t116.*t121.*t293)./4.0-(t16.*t109.*t117.*t121.*t292)./4.0,-t16.*t107.*t116.*t314-t16.*t107.*t117.*t315-(t16.*t109.*t116.*t121.*t292)./4.0-(t16.*t109.*t117.*t121.*t293)./4.0,t292.*t315-t293.*t314,0.0,0.0,0.0,t16.*t107.*t116.*t294-t16.*t107.*t117.*t296-(t9.*t16.*t107.*t116.*t292)./4.0-(t9.*t16.*t107.*t117.*t293)./4.0,-t16.*t107.*t117.*t294-t16.*t107.*t116.*t296-(t9.*t16.*t107.*t116.*t293)./4.0+(t9.*t16.*t107.*t117.*t292)./4.0,t292.*t294-t293.*t296+(t9.*t103.*t118)./2.0+(t9.*t103.*t119)./2.0,0.0,0.0,0.0,t16.*t107.*t116.*t295-t16.*t107.*t117.*t297-(t10.*t16.*t107.*t116.*t292)./4.0-(t10.*t16.*t107.*t117.*t293)./4.0,-t16.*t107.*t117.*t295-t16.*t107.*t116.*t297-(t10.*t16.*t107.*t116.*t293)./4.0+(t10.*t16.*t107.*t117.*t292)./4.0,t292.*t295-t293.*t297+(t10.*t103.*t118)./2.0+(t10.*t103.*t119)./2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,24]);
end
if nargout > 2
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,24]);
end
if nargout > 3
    out4 = [g_xsym;g_ysym;g_zsym;0.0;0.0;0.0];
end
