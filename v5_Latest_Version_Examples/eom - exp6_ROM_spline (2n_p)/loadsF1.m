function [out1,out2,out3] = loadsF1(in1,in2,s,ds,t_sym)
%LOADSF1
%    [OUT1,OUT2,OUT3] = LOADSF1(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 16:49:38

f_tx_ = in1(:,28);
f_ty_ = in1(:,29);
f_tz_ = in1(:,30);
l_f_ = in1(:,17);
l_s_ = in1(:,5);
q1 = in2(1,:);
q2 = in2(2,:);
q3 = in2(3,:);
q4 = in2(4,:);
q5 = in2(5,:);
q6 = in2(6,:);
q7 = in2(7,:);
q8 = in2(8,:);
q9 = in2(9,:);
tau_tx_ = in1(:,31);
tau_ty_ = in1(:,32);
tau_tz_ = in1(:,33);
t2 = l_s_.*q7;
t3 = l_s_.*2.0;
t4 = l_s_.^2;
t8 = l_s_.*q1.*-2.0;
t9 = l_s_.*q3.*-2.0;
t10 = l_s_.*q5.*-2.0;
t12 = sqrt(2.0);
t14 = l_s_.*2.0e+2;
t16 = l_s_./2.0e+1;
t18 = q1./2.0e+1;
t19 = q3./2.0e+1;
t20 = q5./2.0e+1;
t21 = q8./2.0e+1;
t22 = q7./4.0e+1;
t26 = l_s_-1.0./4.0e+1;
t31 = q8./1.6e+3;
t5 = q1.*t3;
t6 = q3.*t3;
t7 = q5.*t3;
t11 = -t2;
t13 = q8.*t4;
t15 = t2./2.0;
t17 = -t14;
t23 = t4./2.0;
t25 = -t16;
t30 = q7+t21;
t32 = t3-1.0./2.0e+1;
t33 = t26.^2;
t24 = -t13;
t27 = t17+5.0;
t28 = -t23;
t29 = t13./2.0;
t36 = q2.*t32;
t37 = q4.*t32;
t38 = q6.*t32;
t39 = q9.*t33;
t41 = t26.*t30;
t42 = t4+t25+6.25e-4;
t34 = exp(t27);
t43 = t8+t18+t36;
t44 = t9+t19+t37;
t45 = t10+t20+t38;
t63 = t11+t22+t24+t31+t39+t41;
t35 = t34+1.0;
t40 = 1.0./t35;
t46 = t32.*t40;
t47 = t33.*t40;
t50 = t40.*t42;
t53 = t40.*t43;
t54 = t40.*t44;
t55 = t40.*t45;
t64 = (t40.*t63)./2.0;
t48 = -t46;
t51 = -t50;
t52 = t50./2.0;
t56 = t5+t53;
t57 = t6+t54;
t59 = t7+t55+1.0;
t65 = t15+t29+t64;
t49 = t3+t48;
t58 = t28+t52;
t60 = t56.^2;
t61 = t57.^2;
t62 = t59.^2;
t66 = cos(t65);
t67 = sin(t65);
t68 = t66.^2;
t69 = t67.^2;
t70 = t60+t61+t62;
t71 = 1.0./t70.^2;
t72 = 1.0./sqrt(t70);
t73 = t72.^3;
t74 = t46.*t72;
t75 = t49.*t72;
t76 = t59.*t72;
t77 = t76+1.0;
t81 = t46.*t62.*t73;
t82 = t48.*t62.*t73;
t83 = t49.*t62.*t73;
t78 = sqrt(t77);
t84 = -t83;
t92 = t74+t82;
t79 = 1.0./t78;
t85 = (t12.*t66.*t78.*tau_tx_)./2.0;
t86 = (t12.*t66.*t78.*tau_ty_)./2.0;
t87 = (t12.*t66.*t78.*tau_tz_)./2.0;
t88 = (t12.*t67.*t78.*tau_tx_)./2.0;
t89 = (t12.*t67.*t78.*tau_ty_)./2.0;
t90 = (t12.*t67.*t78.*tau_tz_)./2.0;
t93 = t75+t84;
t80 = t79.^3;
t91 = -t86;
t94 = (t12.*t66.*t74.*t79)./2.0;
t95 = (t12.*t67.*t74.*t79)./2.0;
t96 = (t12.*t66.*t75.*t79)./2.0;
t97 = (t12.*t67.*t75.*t79)./2.0;
t98 = t12.*t56.*t66.*t72.*t79;
t99 = t12.*t57.*t66.*t72.*t79;
t100 = t12.*t56.*t67.*t72.*t79;
t101 = t12.*t57.*t67.*t72.*t79;
t118 = (t12.*t46.*t60.*t67.*t73.*t79)./2.0;
t119 = (t12.*t46.*t61.*t67.*t73.*t79)./2.0;
t120 = (t12.*t46.*t60.*t66.*t73.*t79)./2.0;
t121 = (t12.*t46.*t61.*t66.*t73.*t79)./2.0;
t126 = (t12.*t49.*t60.*t66.*t73.*t79)./2.0;
t127 = (t12.*t49.*t61.*t66.*t73.*t79)./2.0;
t128 = (t12.*t49.*t60.*t67.*t73.*t79)./2.0;
t129 = (t12.*t49.*t61.*t67.*t73.*t79)./2.0;
t139 = (t12.*t46.*t56.*t57.*t66.*t73.*t79)./2.0;
t140 = (t12.*t46.*t56.*t57.*t67.*t73.*t79)./2.0;
t142 = (t12.*t46.*t56.*t59.*t66.*t73.*t79)./2.0;
t143 = (t12.*t46.*t57.*t59.*t66.*t73.*t79)./2.0;
t145 = (t12.*t46.*t56.*t59.*t67.*t73.*t79)./2.0;
t146 = (t12.*t46.*t57.*t59.*t67.*t73.*t79)./2.0;
t152 = (t12.*t49.*t56.*t57.*t66.*t73.*t79)./2.0;
t153 = (t12.*t49.*t56.*t57.*t67.*t73.*t79)./2.0;
t159 = (t12.*t49.*t56.*t59.*t66.*t73.*t79)./2.0;
t160 = (t12.*t49.*t57.*t59.*t66.*t73.*t79)./2.0;
t162 = (t12.*t49.*t56.*t59.*t67.*t73.*t79)./2.0;
t163 = (t12.*t49.*t57.*t59.*t67.*t73.*t79)./2.0;
t102 = -t100;
t103 = t98./2.0;
t104 = t99./2.0;
t105 = t100./2.0;
t106 = t101./2.0;
t108 = (l_s_.*t98)./4.0;
t109 = (l_s_.*t99)./4.0;
t110 = (l_s_.*t100)./4.0;
t111 = (l_s_.*t101)./4.0;
t113 = (t47.*t98)./4.0;
t114 = (t47.*t99)./4.0;
t115 = (t47.*t100)./4.0;
t116 = (t47.*t101)./4.0;
t122 = -t118;
t123 = -t119;
t124 = -t120;
t125 = -t121;
t130 = -t126;
t131 = -t127;
t132 = -t128;
t133 = -t129;
t134 = t98.*(t23-t52).*(-1.0./2.0);
t135 = t99.*(t23-t52).*(-1.0./2.0);
t136 = t100.*(t23-t52).*(-1.0./2.0);
t137 = t101.*(t23-t52).*(-1.0./2.0);
t141 = -t139;
t144 = -t140;
t147 = (t12.*t46.*t59.*t60.*t66.*t71.*t80)./4.0;
t148 = (t12.*t46.*t59.*t61.*t66.*t71.*t80)./4.0;
t149 = (t12.*t46.*t59.*t60.*t67.*t71.*t80)./4.0;
t150 = (t12.*t46.*t59.*t61.*t67.*t71.*t80)./4.0;
t151 = -t145;
t154 = (t12.*t49.*t59.*t60.*t66.*t71.*t80)./4.0;
t155 = (t12.*t49.*t59.*t61.*t66.*t71.*t80)./4.0;
t156 = (t12.*t49.*t59.*t60.*t67.*t71.*t80)./4.0;
t157 = (t12.*t49.*t59.*t61.*t67.*t71.*t80)./4.0;
t158 = -t152;
t161 = -t153;
t164 = -t162;
t165 = (t12.*t46.*t56.*t57.*t59.*t66.*t71.*t80)./4.0;
t166 = (t12.*t46.*t56.*t57.*t59.*t67.*t71.*t80)./4.0;
t169 = (t12.*t49.*t56.*t57.*t59.*t66.*t71.*t80)./4.0;
t170 = (t12.*t49.*t56.*t57.*t59.*t67.*t71.*t80)./4.0;
t173 = (t12.*t56.*t66.*t72.*t80.*t92)./4.0;
t174 = (t12.*t57.*t66.*t72.*t80.*t92)./4.0;
t175 = (t12.*t56.*t67.*t72.*t80.*t92)./4.0;
t176 = (t12.*t57.*t67.*t72.*t80.*t92)./4.0;
t178 = (t12.*t56.*t66.*t72.*t80.*t93)./4.0;
t179 = (t12.*t57.*t66.*t72.*t80.*t93)./4.0;
t180 = (t12.*t56.*t67.*t72.*t80.*t93)./4.0;
t181 = (t12.*t57.*t67.*t72.*t80.*t93)./4.0;
t183 = t98+t101;
t107 = -t105;
t112 = -t110;
t117 = -t115;
t138 = t105.*(t23-t52);
t167 = -t165;
t168 = -t166;
t171 = -t169;
t172 = -t170;
t177 = -t175;
t182 = -t180;
t184 = t99+t102;
t185 = t103+t106;
t190 = t108+t111;
t197 = t113+t116;
t199 = t134+t137;
t205 = t94+t124+t144+t147+t166;
t208 = t95+t123+t141+t150+t165;
t209 = t96+t130+t154+t161+t170;
t212 = t97+t133+t157+t158+t169;
t213 = t142+t146+t173+t176;
t215 = t159+t163+t178+t181;
t186 = t104+t107;
t187 = t185.*tau_tx_;
t188 = t185.*tau_ty_;
t189 = t185.*tau_tz_;
t194 = t109+t112;
t198 = t114+t117;
t200 = t135+t138;
t206 = t94+t125+t140+t148+t168;
t207 = t95+t122+t139+t149+t167;
t210 = t96+t131+t153+t155+t172;
t211 = t97+t132+t152+t156+t171;
t214 = t143+t151+t174+t177;
t216 = t160+t164+t179+t182;
out1 = reshape([t4+t51+l_f_.*t162.*t186+l_f_.*t12.*t66.*t78.*t209+l_f_.*t12.*t67.*t78.*t211-(l_f_.*t12.*t49.*t56.*t59.*t66.*t73.*t79.*t185)./2.0,t47+l_f_.*t145.*t186+l_f_.*t12.*t66.*t78.*t205+l_f_.*t12.*t67.*t78.*t207-(l_f_.*t12.*t46.*t56.*t59.*t66.*t73.*t79.*t185)./2.0,l_f_.*t163.*t186-l_f_.*t12.*t67.*t78.*t210+l_f_.*t12.*t66.*t78.*t212-(l_f_.*t12.*t49.*t57.*t59.*t66.*t73.*t79.*t185)./2.0,l_f_.*t146.*t186-l_f_.*t12.*t67.*t78.*t206+l_f_.*t12.*t66.*t78.*t208-(l_f_.*t12.*t46.*t57.*t59.*t66.*t73.*t79.*t185)./2.0,-l_f_.*t12.*t66.*t78.*t215+l_f_.*t12.*t67.*t78.*t216+(l_f_.*t12.*t66.*t79.*t93.*t185)./2.0-(l_f_.*t12.*t67.*t79.*t93.*t186)./2.0,-l_f_.*t12.*t66.*t78.*t213+l_f_.*t12.*t67.*t78.*t214+(l_f_.*t12.*t66.*t79.*t92.*t185)./2.0-(l_f_.*t12.*t67.*t79.*t92.*t186)./2.0,l_f_.*t12.*t67.*t78.*t190+l_f_.*t12.*t66.*t78.*t194-(l_f_.*l_s_.*t12.*t66.*t78.*t186)./2.0-(l_f_.*l_s_.*t12.*t67.*t78.*t185)./2.0,l_f_.*t12.*t67.*t78.*(t103.*(t23-t52)+t106.*(t23-t52))+l_f_.*t12.*t66.*t78.*(t104.*(t23-t52)+t107.*(t23-t52))-l_f_.*t12.*t66.*t78.*t186.*(t23-t52)-l_f_.*t12.*t67.*t78.*t185.*(t23-t52),l_f_.*t12.*t66.*t78.*t198+l_f_.*t12.*t67.*t78.*t197-(l_f_.*t12.*t47.*t66.*t78.*t186)./2.0-(l_f_.*t12.*t47.*t67.*t78.*t185)./2.0,l_f_.*t12.*t67.*t78.*t209-l_f_.*t12.*t66.*t78.*t211-(l_f_.*t12.*t49.*t56.*t59.*t66.*t73.*t79.*t186)./2.0-(l_f_.*t12.*t49.*t56.*t59.*t67.*t73.*t79.*t185)./2.0,l_f_.*t12.*t67.*t78.*t205-l_f_.*t12.*t66.*t78.*t207-(l_f_.*t12.*t46.*t56.*t59.*t66.*t73.*t79.*t186)./2.0-(l_f_.*t12.*t46.*t56.*t59.*t67.*t73.*t79.*t185)./2.0,t4+t51+l_f_.*t12.*t66.*t78.*t210+l_f_.*t12.*t67.*t78.*t212-(l_f_.*t12.*t49.*t57.*t59.*t66.*t73.*t79.*t186)./2.0-(l_f_.*t12.*t49.*t57.*t59.*t67.*t73.*t79.*t185)./2.0,t47+l_f_.*t12.*t66.*t78.*t206+l_f_.*t12.*t67.*t78.*t208-(l_f_.*t12.*t46.*t57.*t59.*t66.*t73.*t79.*t186)./2.0-(l_f_.*t12.*t46.*t57.*t59.*t67.*t73.*t79.*t185)./2.0,-l_f_.*t12.*t66.*t78.*t216-l_f_.*t12.*t67.*t78.*t215+(l_f_.*t12.*t66.*t79.*t93.*t186)./2.0+(l_f_.*t12.*t67.*t79.*t93.*t185)./2.0,-l_f_.*t12.*t66.*t78.*t214-l_f_.*t12.*t67.*t78.*t213+(l_f_.*t12.*t66.*t79.*t92.*t186)./2.0+(l_f_.*t12.*t67.*t79.*t92.*t185)./2.0,-l_f_.*t12.*t66.*t78.*t190+l_f_.*t12.*t67.*t78.*t194+(l_f_.*l_s_.*t12.*t66.*t78.*t185)./2.0-(l_f_.*l_s_.*t12.*t67.*t78.*t186)./2.0,-l_f_.*t12.*t66.*t78.*(t103.*(t23-t52)+t106.*(t23-t52))+l_f_.*t12.*t67.*t78.*(t104.*(t23-t52)+t107.*(t23-t52))+l_f_.*t12.*t66.*t78.*t185.*(t23-t52)-l_f_.*t12.*t67.*t78.*t186.*(t23-t52),-l_f_.*t12.*t66.*t78.*t197+l_f_.*t12.*t67.*t78.*t198+(l_f_.*t12.*t47.*t66.*t78.*t185)./2.0-(l_f_.*t12.*t47.*t67.*t78.*t186)./2.0,l_f_.*t185.*t209.*-2.0+l_f_.*t186.*t211.*2.0-(l_f_.*t49.*t56.*t59.*t68.*t73)./2.0-(l_f_.*t49.*t56.*t59.*t69.*t73)./2.0,l_f_.*t185.*t205.*-2.0+l_f_.*t186.*t207.*2.0-(l_f_.*t46.*t56.*t59.*t68.*t73)./2.0-(l_f_.*t46.*t56.*t59.*t69.*t73)./2.0,l_f_.*t186.*t210.*-2.0-l_f_.*t185.*t212.*2.0-(l_f_.*t49.*t57.*t59.*t68.*t73)./2.0-(l_f_.*t49.*t57.*t59.*t69.*t73)./2.0,l_f_.*t186.*t206.*-2.0-l_f_.*t185.*t208.*2.0-(l_f_.*t46.*t57.*t59.*t68.*t73)./2.0-(l_f_.*t46.*t57.*t59.*t69.*t73)./2.0,t4+t51+(l_f_.*t68.*t93)./2.0+(l_f_.*t69.*t93)./2.0+l_f_.*t185.*t215.*2.0+l_f_.*t186.*t216.*2.0,t47+(l_f_.*t68.*t92)./2.0+(l_f_.*t69.*t92)./2.0+l_f_.*t185.*t213.*2.0+l_f_.*t186.*t214.*2.0,l_f_.*t186.*t190.*2.0-l_f_.*t185.*t194.*2.0,l_f_.*t186.*(t103.*(t23-t52)+t106.*(t23-t52)).*2.0-l_f_.*t185.*(t104.*(t23-t52)+t107.*(t23-t52)).*2.0,l_f_.*t185.*t198.*-2.0+l_f_.*t186.*t197.*2.0,t12.*t67.*t78.*t209+t12.*t66.*t78.*t211-(t12.*t49.*t56.*t59.*t66.*t73.*t79.*t184)./4.0+(t12.*t49.*t56.*t59.*t67.*t73.*t79.*t183)./4.0,t12.*t67.*t78.*t205+t12.*t66.*t78.*t207-(t12.*t46.*t56.*t59.*t66.*t73.*t79.*t184)./4.0+(t12.*t46.*t56.*t59.*t67.*t73.*t79.*t183)./4.0,-t12.*t66.*t78.*t210+t12.*t67.*t78.*t212-(t12.*t49.*t57.*t59.*t66.*t73.*t79.*t184)./4.0+(t12.*t49.*t57.*t59.*t67.*t73.*t79.*t183)./4.0,-t12.*t66.*t78.*t206+t12.*t67.*t78.*t208-(t12.*t46.*t57.*t59.*t66.*t73.*t79.*t184)./4.0+(t12.*t46.*t57.*t59.*t67.*t73.*t79.*t183)./4.0,t12.*t66.*t78.*t216-t12.*t67.*t78.*t215+(t12.*t66.*t79.*t93.*t184)./4.0-(t12.*t67.*t79.*t93.*t183)./4.0,t12.*t66.*t78.*t214-t12.*t67.*t78.*t213+(t12.*t66.*t79.*t92.*t184)./4.0-(t12.*t67.*t79.*t92.*t183)./4.0,t12.*t66.*t78.*t190+t12.*t67.*t78.*t194-(l_s_.*t12.*t66.*t78.*t183)./4.0-(l_s_.*t12.*t67.*t78.*t184)./4.0,t12.*t66.*t78.*(t103.*(t23-t52)+t106.*(t23-t52))+t12.*t67.*t78.*(t104.*(t23-t52)+t107.*(t23-t52))-(t12.*t66.*t78.*t183.*(t23-t52))./2.0-(t12.*t67.*t78.*t184.*(t23-t52))./2.0,t12.*t66.*t78.*t197+t12.*t67.*t78.*t198-(t12.*t47.*t66.*t78.*t183)./4.0-(t12.*t47.*t67.*t78.*t184)./4.0,t12.*t66.*t78.*t209-t12.*t67.*t78.*t211+(t12.*t49.*t56.*t59.*t66.*t73.*t79.*t183)./4.0+(t12.*t49.*t56.*t59.*t67.*t73.*t79.*t184)./4.0,t12.*t66.*t78.*t205-t12.*t67.*t78.*t207+(t12.*t46.*t56.*t59.*t66.*t73.*t79.*t183)./4.0+(t12.*t46.*t56.*t59.*t67.*t73.*t79.*t184)./4.0,t12.*t67.*t78.*t210+t12.*t66.*t78.*t212+(t12.*t49.*t57.*t59.*t66.*t73.*t79.*t183)./4.0+(t12.*t49.*t57.*t59.*t67.*t73.*t79.*t184)./4.0,t12.*t67.*t78.*t206+t12.*t66.*t78.*t208+(t12.*t46.*t57.*t59.*t66.*t73.*t79.*t183)./4.0+(t12.*t46.*t57.*t59.*t67.*t73.*t79.*t184)./4.0,-t12.*t66.*t78.*t215-t12.*t67.*t78.*t216-(t12.*t66.*t79.*t93.*t183)./4.0-(t12.*t67.*t79.*t93.*t184)./4.0,-t12.*t66.*t78.*t213-t12.*t67.*t78.*t214-(t12.*t66.*t79.*t92.*t183)./4.0-(t12.*t67.*t79.*t92.*t184)./4.0,-t12.*t67.*t78.*t190+t12.*t66.*t78.*t194-(l_s_.*t12.*t66.*t78.*t184)./4.0+(l_s_.*t12.*t67.*t78.*t183)./4.0,-t12.*t67.*t78.*(t103.*(t23-t52)+t106.*(t23-t52))+t12.*t66.*t78.*(t104.*(t23-t52)+t107.*(t23-t52))-(t12.*t66.*t78.*t184.*(t23-t52))./2.0+(t12.*t67.*t78.*t183.*(t23-t52))./2.0,t12.*t66.*t78.*t198-t12.*t67.*t78.*t197-(t12.*t47.*t66.*t78.*t184)./4.0+(t12.*t47.*t67.*t78.*t183)./4.0,t184.*t209+t183.*t211,t184.*t205+t183.*t207,-t183.*t210+t184.*t212,-t183.*t206+t184.*t208,t183.*t216-t184.*t215,t183.*t214-t184.*t213,t183.*t190+t184.*t194+(l_s_.*t68.*t77)./2.0+(l_s_.*t69.*t77)./2.0,t183.*(t103.*(t23-t52)+t106.*(t23-t52))+t184.*(t104.*(t23-t52)+t107.*(t23-t52))+t68.*t77.*(t23-t52)+t69.*t77.*(t23-t52),t183.*t197+t184.*t198+(t47.*t68.*t77)./2.0+(t47.*t69.*t77)./2.0],[9,6]);
if nargout > 1
    t191 = t186.*tau_tx_;
    t192 = t186.*tau_ty_;
    t193 = t186.*tau_tz_;
    t195 = -t189;
    t196 = -t191;
    t201 = t88+t91+t193;
    t202 = t85+t89+t195;
    t203 = t87+t187+t192;
    t204 = t90+t188+t196;
    out2 = [f_tx_;f_ty_;f_tz_;-t185.*t203-t186.*t204+(t12.*t66.*t78.*t202)./2.0-(t12.*t67.*t78.*(-t86+t88+t193))./2.0;t185.*t204-t186.*t203-(t12.*t67.*t78.*t202)./2.0-(t12.*t66.*t78.*(-t86+t88+t193))./2.0;t185.*t202-t186.*(-t86+t88+t193)+(t12.*t66.*t78.*t203)./2.0+(t12.*t67.*t78.*t204)./2.0];
end
if nargout > 2
    out3 = zeros(0,0);
end
