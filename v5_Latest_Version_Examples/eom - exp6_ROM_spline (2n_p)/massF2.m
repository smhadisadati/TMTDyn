function [out1,out2,out3,out4] = massF2(in1,in2,s,ds,t_sym)
%MASSF2
%    [OUT1,OUT2,OUT3,OUT4] = MASSF2(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 16:41:05

g_x_ = in1(:,13);
g_y_ = in1(:,14);
g_z_ = in1(:,15);
l_f_ = in1(:,17);
l_s_ = in1(:,5);
m_f_ = in1(:,16);
q1 = in2(1,:);
q2 = in2(2,:);
q3 = in2(3,:);
q4 = in2(4,:);
q5 = in2(5,:);
q6 = in2(6,:);
q7 = in2(7,:);
q8 = in2(8,:);
q9 = in2(9,:);
r_f_ = in1(:,18);
t2 = l_s_.*q7;
t3 = l_s_.*2.0;
t4 = l_f_.^2;
t5 = l_s_.^2;
t6 = r_f_.^2;
t11 = l_s_.*q1.*-2.0;
t12 = l_s_.*q3.*-2.0;
t13 = l_s_.*q5.*-2.0;
t15 = sqrt(2.0);
t17 = l_s_.*2.0e+2;
t19 = l_s_./2.0e+1;
t21 = q1./2.0e+1;
t22 = q3./2.0e+1;
t23 = q5./2.0e+1;
t24 = q8./2.0e+1;
t25 = q7./4.0e+1;
t29 = l_s_-1.0./4.0e+1;
t35 = q8./1.6e+3;
t7 = q1.*t3;
t8 = q3.*t3;
t9 = q5.*t3;
t10 = t6.*3.0;
t14 = -t2;
t16 = q8.*t5;
t18 = t2./2.0;
t20 = -t17;
t26 = t5./2.0;
t28 = -t19;
t32 = (m_f_.*t4)./4.0;
t34 = q7+t24;
t36 = t3-1.0./2.0e+1;
t37 = t29.^2;
t27 = -t16;
t30 = t20+5.0;
t31 = -t26;
t33 = t16./2.0;
t38 = t4+t10;
t41 = q2.*t36;
t42 = q4.*t36;
t43 = q6.*t36;
t44 = q9.*t37;
t47 = t29.*t34;
t48 = t5+t28+6.25e-4;
t39 = exp(t30);
t46 = (m_f_.*t38)./1.2e+1;
t49 = t11+t21+t41;
t50 = t12+t22+t42;
t51 = t13+t23+t43;
t70 = t14+t25+t27+t35+t44+t47;
t40 = t39+1.0;
t52 = t32+t46;
out1 = reshape([m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,t52,0.0,0.0,0.0,0.0,0.0,0.0,t52,0.0,0.0,0.0,0.0,0.0,0.0,(m_f_.*t6)./2.0],[6,6]);
if nargout > 1
    t45 = 1.0./t40;
    t53 = t36.*t45;
    t54 = t37.*t45;
    t57 = t45.*t48;
    t60 = t45.*t49;
    t61 = t45.*t50;
    t62 = t45.*t51;
    t71 = (t45.*t70)./2.0;
    t55 = -t53;
    t58 = -t57;
    t59 = t57./2.0;
    t63 = t7+t60;
    t64 = t8+t61;
    t66 = t9+t62+1.0;
    t72 = t18+t33+t71;
    t56 = t3+t55;
    t65 = t31+t59;
    t67 = t63.^2;
    t68 = t64.^2;
    t69 = t66.^2;
    t73 = cos(t72);
    t74 = sin(t72);
    t75 = t73.^2;
    t76 = t74.^2;
    t77 = t67+t68+t69;
    t78 = 1.0./t77.^2;
    t79 = 1.0./sqrt(t77);
    t80 = t79.^3;
    t81 = t53.*t79;
    t82 = t56.*t79;
    t83 = t66.*t79;
    t84 = t83+1.0;
    t88 = t53.*t69.*t80;
    t89 = t55.*t69.*t80;
    t90 = t56.*t69.*t80;
    t85 = sqrt(t84);
    t91 = -t90;
    t92 = t81+t89;
    t86 = 1.0./t85;
    t93 = t82+t91;
    t87 = t86.^3;
    t94 = (t15.*t73.*t81.*t86)./2.0;
    t95 = (t15.*t74.*t81.*t86)./2.0;
    t96 = (t15.*t73.*t82.*t86)./2.0;
    t97 = (t15.*t74.*t82.*t86)./2.0;
    t98 = t15.*t63.*t73.*t79.*t86;
    t99 = t15.*t64.*t73.*t79.*t86;
    t100 = t15.*t63.*t74.*t79.*t86;
    t101 = t15.*t64.*t74.*t79.*t86;
    t118 = (t15.*t53.*t67.*t74.*t80.*t86)./2.0;
    t119 = (t15.*t53.*t68.*t74.*t80.*t86)./2.0;
    t120 = (t15.*t53.*t67.*t73.*t80.*t86)./2.0;
    t121 = (t15.*t53.*t68.*t73.*t80.*t86)./2.0;
    t126 = (t15.*t56.*t67.*t73.*t80.*t86)./2.0;
    t127 = (t15.*t56.*t68.*t73.*t80.*t86)./2.0;
    t128 = (t15.*t56.*t67.*t74.*t80.*t86)./2.0;
    t129 = (t15.*t56.*t68.*t74.*t80.*t86)./2.0;
    t139 = (t15.*t53.*t63.*t64.*t73.*t80.*t86)./2.0;
    t140 = (t15.*t53.*t63.*t64.*t74.*t80.*t86)./2.0;
    t142 = (t15.*t53.*t63.*t66.*t73.*t80.*t86)./2.0;
    t143 = (t15.*t53.*t64.*t66.*t73.*t80.*t86)./2.0;
    t145 = (t15.*t53.*t63.*t66.*t74.*t80.*t86)./2.0;
    t146 = (t15.*t53.*t64.*t66.*t74.*t80.*t86)./2.0;
    t152 = (t15.*t56.*t63.*t64.*t73.*t80.*t86)./2.0;
    t153 = (t15.*t56.*t63.*t64.*t74.*t80.*t86)./2.0;
    t159 = (t15.*t56.*t63.*t66.*t73.*t80.*t86)./2.0;
    t160 = (t15.*t56.*t64.*t66.*t73.*t80.*t86)./2.0;
    t162 = (t15.*t56.*t63.*t66.*t74.*t80.*t86)./2.0;
    t163 = (t15.*t56.*t64.*t66.*t74.*t80.*t86)./2.0;
    t102 = -t100;
    t103 = t98./2.0;
    t104 = t99./2.0;
    t105 = t100./2.0;
    t106 = t101./2.0;
    t108 = (l_s_.*t98)./4.0;
    t109 = (l_s_.*t99)./4.0;
    t110 = (l_s_.*t100)./4.0;
    t111 = (l_s_.*t101)./4.0;
    t113 = (t54.*t98)./4.0;
    t114 = (t54.*t99)./4.0;
    t115 = (t54.*t100)./4.0;
    t116 = (t54.*t101)./4.0;
    t122 = -t118;
    t123 = -t119;
    t124 = -t120;
    t125 = -t121;
    t130 = -t126;
    t131 = -t127;
    t132 = -t128;
    t133 = -t129;
    t134 = t98.*(t26-t59).*(-1.0./2.0);
    t135 = t99.*(t26-t59).*(-1.0./2.0);
    t136 = t100.*(t26-t59).*(-1.0./2.0);
    t137 = t101.*(t26-t59).*(-1.0./2.0);
    t141 = -t139;
    t144 = -t140;
    t147 = (t15.*t53.*t66.*t67.*t73.*t78.*t87)./4.0;
    t148 = (t15.*t53.*t66.*t68.*t73.*t78.*t87)./4.0;
    t149 = (t15.*t53.*t66.*t67.*t74.*t78.*t87)./4.0;
    t150 = (t15.*t53.*t66.*t68.*t74.*t78.*t87)./4.0;
    t151 = -t145;
    t154 = (t15.*t56.*t66.*t67.*t73.*t78.*t87)./4.0;
    t155 = (t15.*t56.*t66.*t68.*t73.*t78.*t87)./4.0;
    t156 = (t15.*t56.*t66.*t67.*t74.*t78.*t87)./4.0;
    t157 = (t15.*t56.*t66.*t68.*t74.*t78.*t87)./4.0;
    t158 = -t152;
    t161 = -t153;
    t164 = -t162;
    t165 = (t15.*t53.*t63.*t64.*t66.*t73.*t78.*t87)./4.0;
    t166 = (t15.*t53.*t63.*t64.*t66.*t74.*t78.*t87)./4.0;
    t169 = (t15.*t56.*t63.*t64.*t66.*t73.*t78.*t87)./4.0;
    t170 = (t15.*t56.*t63.*t64.*t66.*t74.*t78.*t87)./4.0;
    t173 = (t15.*t63.*t73.*t79.*t87.*t92)./4.0;
    t174 = (t15.*t64.*t73.*t79.*t87.*t92)./4.0;
    t175 = (t15.*t63.*t74.*t79.*t87.*t92)./4.0;
    t176 = (t15.*t64.*t74.*t79.*t87.*t92)./4.0;
    t178 = (t15.*t63.*t73.*t79.*t87.*t93)./4.0;
    t179 = (t15.*t64.*t73.*t79.*t87.*t93)./4.0;
    t180 = (t15.*t63.*t74.*t79.*t87.*t93)./4.0;
    t181 = (t15.*t64.*t74.*t79.*t87.*t93)./4.0;
    t183 = t98+t101;
    t107 = -t105;
    t112 = -t110;
    t117 = -t115;
    t138 = t105.*(t26-t59);
    t167 = -t165;
    t168 = -t166;
    t171 = -t169;
    t172 = -t170;
    t177 = -t175;
    t182 = -t180;
    t184 = t99+t102;
    t185 = t103+t106;
    t187 = t108+t111;
    t189 = t113+t116;
    t191 = t134+t137;
    t193 = t94+t124+t144+t147+t166;
    t196 = t95+t123+t141+t150+t165;
    t197 = t96+t130+t154+t161+t170;
    t200 = t97+t133+t157+t158+t169;
    t201 = t142+t146+t173+t176;
    t203 = t159+t163+t178+t181;
    t186 = t104+t107;
    t188 = t109+t112;
    t190 = t114+t117;
    t192 = t135+t138;
    t194 = t94+t125+t140+t148+t168;
    t195 = t95+t122+t139+t149+t167;
    t198 = t96+t131+t153+t155+t172;
    t199 = t97+t132+t152+t156+t171;
    t202 = t143+t151+t174+t177;
    t204 = t160+t164+t179+t182;
    out2 = reshape([t5+t58+(l_f_.*t15.*t73.*t85.*t197)./2.0+(l_f_.*t15.*t74.*t85.*t199)./2.0-(l_f_.*t15.*t56.*t63.*t66.*t73.*t80.*t86.*t185)./4.0+(l_f_.*t15.*t56.*t63.*t66.*t74.*t80.*t86.*t186)./4.0,(l_f_.*t15.*t74.*t85.*t197)./2.0-(l_f_.*t15.*t73.*t85.*t199)./2.0-(l_f_.*t15.*t56.*t63.*t66.*t73.*t80.*t86.*t186)./4.0-(l_f_.*t15.*t56.*t63.*t66.*t74.*t80.*t86.*t185)./4.0,-l_f_.*t185.*t197+l_f_.*t186.*t199-(l_f_.*t56.*t63.*t66.*t75.*t80)./4.0-(l_f_.*t56.*t63.*t66.*t76.*t80)./4.0,t15.*t74.*t85.*t197+t15.*t73.*t85.*t199-(t15.*t56.*t63.*t66.*t73.*t80.*t86.*t184)./4.0+(t15.*t56.*t63.*t66.*t74.*t80.*t86.*t183)./4.0,t15.*t73.*t85.*t197-t15.*t74.*t85.*t199+(t15.*t56.*t63.*t66.*t73.*t80.*t86.*t183)./4.0+(t15.*t56.*t63.*t66.*t74.*t80.*t86.*t184)./4.0,t184.*t197+t183.*t199,t54+(l_f_.*t15.*t73.*t85.*t193)./2.0+(l_f_.*t15.*t74.*t85.*t195)./2.0-(l_f_.*t15.*t53.*t63.*t66.*t73.*t80.*t86.*t185)./4.0+(l_f_.*t15.*t53.*t63.*t66.*t74.*t80.*t86.*t186)./4.0,(l_f_.*t15.*t74.*t85.*t193)./2.0-(l_f_.*t15.*t73.*t85.*t195)./2.0-(l_f_.*t15.*t53.*t63.*t66.*t73.*t80.*t86.*t186)./4.0-(l_f_.*t15.*t53.*t63.*t66.*t74.*t80.*t86.*t185)./4.0,-l_f_.*t185.*t193+l_f_.*t186.*t195-(l_f_.*t53.*t63.*t66.*t75.*t80)./4.0-(l_f_.*t53.*t63.*t66.*t76.*t80)./4.0,t15.*t74.*t85.*t193+t15.*t73.*t85.*t195-(t15.*t53.*t63.*t66.*t73.*t80.*t86.*t184)./4.0+(t15.*t53.*t63.*t66.*t74.*t80.*t86.*t183)./4.0,t15.*t73.*t85.*t193-t15.*t74.*t85.*t195+(t15.*t53.*t63.*t66.*t73.*t80.*t86.*t183)./4.0+(t15.*t53.*t63.*t66.*t74.*t80.*t86.*t184)./4.0,t184.*t193+t183.*t195,l_f_.*t15.*t74.*t85.*t198.*(-1.0./2.0)+(l_f_.*t15.*t73.*t85.*t200)./2.0-(l_f_.*t15.*t56.*t64.*t66.*t73.*t80.*t86.*t185)./4.0+(l_f_.*t15.*t56.*t64.*t66.*t74.*t80.*t86.*t186)./4.0,t5+t58+(l_f_.*t15.*t73.*t85.*t198)./2.0+(l_f_.*t15.*t74.*t85.*t200)./2.0-(l_f_.*t15.*t56.*t64.*t66.*t73.*t80.*t86.*t186)./4.0-(l_f_.*t15.*t56.*t64.*t66.*t74.*t80.*t86.*t185)./4.0,-l_f_.*t186.*t198-l_f_.*t185.*t200-(l_f_.*t56.*t64.*t66.*t75.*t80)./4.0-(l_f_.*t56.*t64.*t66.*t76.*t80)./4.0,-t15.*t73.*t85.*t198+t15.*t74.*t85.*t200-(t15.*t56.*t64.*t66.*t73.*t80.*t86.*t184)./4.0+(t15.*t56.*t64.*t66.*t74.*t80.*t86.*t183)./4.0,t15.*t74.*t85.*t198+t15.*t73.*t85.*t200+(t15.*t56.*t64.*t66.*t73.*t80.*t86.*t183)./4.0+(t15.*t56.*t64.*t66.*t74.*t80.*t86.*t184)./4.0,-t183.*t198+t184.*t200,l_f_.*t15.*t74.*t85.*t194.*(-1.0./2.0)+(l_f_.*t15.*t73.*t85.*t196)./2.0-(l_f_.*t15.*t53.*t64.*t66.*t73.*t80.*t86.*t185)./4.0+(l_f_.*t15.*t53.*t64.*t66.*t74.*t80.*t86.*t186)./4.0,t54+(l_f_.*t15.*t73.*t85.*t194)./2.0+(l_f_.*t15.*t74.*t85.*t196)./2.0-(l_f_.*t15.*t53.*t64.*t66.*t73.*t80.*t86.*t186)./4.0-(l_f_.*t15.*t53.*t64.*t66.*t74.*t80.*t86.*t185)./4.0,-l_f_.*t186.*t194-l_f_.*t185.*t196-(l_f_.*t53.*t64.*t66.*t75.*t80)./4.0-(l_f_.*t53.*t64.*t66.*t76.*t80)./4.0,-t15.*t73.*t85.*t194+t15.*t74.*t85.*t196-(t15.*t53.*t64.*t66.*t73.*t80.*t86.*t184)./4.0+(t15.*t53.*t64.*t66.*t74.*t80.*t86.*t183)./4.0,t15.*t74.*t85.*t194+t15.*t73.*t85.*t196+(t15.*t53.*t64.*t66.*t73.*t80.*t86.*t183)./4.0+(t15.*t53.*t64.*t66.*t74.*t80.*t86.*t184)./4.0,-t183.*t194+t184.*t196,l_f_.*t15.*t73.*t85.*t203.*(-1.0./2.0)+(l_f_.*t15.*t74.*t85.*t204)./2.0+(l_f_.*t15.*t73.*t86.*t93.*t185)./4.0-(l_f_.*t15.*t74.*t86.*t93.*t186)./4.0,l_f_.*t15.*t73.*t85.*t204.*(-1.0./2.0)-(l_f_.*t15.*t74.*t85.*t203)./2.0+(l_f_.*t15.*t73.*t86.*t93.*t186)./4.0+(l_f_.*t15.*t74.*t86.*t93.*t185)./4.0,t5+t58+(l_f_.*t75.*t93)./4.0+(l_f_.*t76.*t93)./4.0+l_f_.*t185.*t203+l_f_.*t186.*t204,t15.*t73.*t85.*t204-t15.*t74.*t85.*t203+(t15.*t73.*t86.*t93.*t184)./4.0-(t15.*t74.*t86.*t93.*t183)./4.0,-t15.*t73.*t85.*t203-t15.*t74.*t85.*t204-(t15.*t73.*t86.*t93.*t183)./4.0-(t15.*t74.*t86.*t93.*t184)./4.0,t183.*t204-t184.*t203,l_f_.*t15.*t73.*t85.*t201.*(-1.0./2.0)+(l_f_.*t15.*t74.*t85.*t202)./2.0+(l_f_.*t15.*t73.*t86.*t92.*t185)./4.0-(l_f_.*t15.*t74.*t86.*t92.*t186)./4.0,l_f_.*t15.*t73.*t85.*t202.*(-1.0./2.0)-(l_f_.*t15.*t74.*t85.*t201)./2.0+(l_f_.*t15.*t73.*t86.*t92.*t186)./4.0+(l_f_.*t15.*t74.*t86.*t92.*t185)./4.0,t54+(l_f_.*t75.*t92)./4.0+(l_f_.*t76.*t92)./4.0+l_f_.*t185.*t201+l_f_.*t186.*t202,t15.*t73.*t85.*t202-t15.*t74.*t85.*t201+(t15.*t73.*t86.*t92.*t184)./4.0-(t15.*t74.*t86.*t92.*t183)./4.0,-t15.*t73.*t85.*t201-t15.*t74.*t85.*t202-(t15.*t73.*t86.*t92.*t183)./4.0-(t15.*t74.*t86.*t92.*t184)./4.0,t183.*t202-t184.*t201,(l_f_.*t15.*t73.*t85.*t188)./2.0+(l_f_.*t15.*t74.*t85.*t187)./2.0-(l_f_.*l_s_.*t15.*t73.*t85.*t186)./4.0-(l_f_.*l_s_.*t15.*t74.*t85.*t185)./4.0,l_f_.*t15.*t73.*t85.*t187.*(-1.0./2.0)+(l_f_.*t15.*t74.*t85.*t188)./2.0+(l_f_.*l_s_.*t15.*t73.*t85.*t185)./4.0-(l_f_.*l_s_.*t15.*t74.*t85.*t186)./4.0,-l_f_.*t185.*t188+l_f_.*t186.*t187,t15.*t73.*t85.*t187+t15.*t74.*t85.*t188-(l_s_.*t15.*t73.*t85.*t183)./4.0-(l_s_.*t15.*t74.*t85.*t184)./4.0,t15.*t73.*t85.*t188-t15.*t74.*t85.*t187-(l_s_.*t15.*t73.*t85.*t184)./4.0+(l_s_.*t15.*t74.*t85.*t183)./4.0,t183.*t187+t184.*t188+(l_s_.*t75.*t84)./2.0+(l_s_.*t76.*t84)./2.0,(l_f_.*t15.*t74.*t85.*(t103.*(t26-t59)+t106.*(t26-t59)))./2.0+(l_f_.*t15.*t73.*t85.*(t104.*(t26-t59)+t107.*(t26-t59)))./2.0-(l_f_.*t15.*t73.*t85.*t186.*(t26-t59))./2.0-(l_f_.*t15.*t74.*t85.*t185.*(t26-t59))./2.0,l_f_.*t15.*t73.*t85.*(t103.*(t26-t59)+t106.*(t26-t59)).*(-1.0./2.0)+(l_f_.*t15.*t74.*t85.*(t104.*(t26-t59)+t107.*(t26-t59)))./2.0+(l_f_.*t15.*t73.*t85.*t185.*(t26-t59))./2.0-(l_f_.*t15.*t74.*t85.*t186.*(t26-t59))./2.0,l_f_.*t186.*(t103.*(t26-t59)+t106.*(t26-t59))-l_f_.*t185.*(t104.*(t26-t59)+t107.*(t26-t59)),t15.*t73.*t85.*(t103.*(t26-t59)+t106.*(t26-t59))+t15.*t74.*t85.*(t104.*(t26-t59)+t107.*(t26-t59))-(t15.*t73.*t85.*t183.*(t26-t59))./2.0-(t15.*t74.*t85.*t184.*(t26-t59))./2.0,-t15.*t74.*t85.*(t103.*(t26-t59)+t106.*(t26-t59))+t15.*t73.*t85.*(t104.*(t26-t59)+t107.*(t26-t59))-(t15.*t73.*t85.*t184.*(t26-t59))./2.0+(t15.*t74.*t85.*t183.*(t26-t59))./2.0,t183.*(t103.*(t26-t59)+t106.*(t26-t59))+t184.*(t104.*(t26-t59)+t107.*(t26-t59))+t75.*t84.*(t26-t59)+t76.*t84.*(t26-t59),(l_f_.*t15.*t73.*t85.*t190)./2.0+(l_f_.*t15.*t74.*t85.*t189)./2.0-(l_f_.*t15.*t54.*t73.*t85.*t186)./4.0-(l_f_.*t15.*t54.*t74.*t85.*t185)./4.0,l_f_.*t15.*t73.*t85.*t189.*(-1.0./2.0)+(l_f_.*t15.*t74.*t85.*t190)./2.0+(l_f_.*t15.*t54.*t73.*t85.*t185)./4.0-(l_f_.*t15.*t54.*t74.*t85.*t186)./4.0,-l_f_.*t185.*t190+l_f_.*t186.*t189,t15.*t73.*t85.*t189+t15.*t74.*t85.*t190-(t15.*t54.*t73.*t85.*t183)./4.0-(t15.*t54.*t74.*t85.*t184)./4.0,t15.*t73.*t85.*t190-t15.*t74.*t85.*t189-(t15.*t54.*t73.*t85.*t184)./4.0+(t15.*t54.*t74.*t85.*t183)./4.0,t183.*t189+t184.*t190+(t54.*t75.*t84)./2.0+(t54.*t76.*t84)./2.0],[6,9]);
end
if nargout > 2
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[6,9]);
end
if nargout > 3
    out4 = [g_x_;g_y_;g_z_;0.0;0.0;0.0];
end
