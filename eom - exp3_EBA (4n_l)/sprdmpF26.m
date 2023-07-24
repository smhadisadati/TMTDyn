function [out1,out2,out3,out4,out5,out6] = sprdmpF26(in1,in2,s,ds,t_sym)
%SPRDMPF26
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6] = SPRDMPF26(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    26-Feb-2021 21:20:51

E_s_ = in1(:,2);
gamma_ = in1(:,21);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
mu_x_ = in1(:,6);
mu_y_ = in1(:,7);
mu_z_ = in1(:,8);
mu_xx_ = in1(:,9);
mu_yy_ = in1(:,10);
mu_zz_ = in1(:,11);
p1_ = in1(:,22);
p2_ = in1(:,23);
p3_ = in1(:,24);
p4_ = in1(:,25);
p5_ = in1(:,26);
p6_ = in1(:,27);
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
r_o_ = in1(:,20);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
u1 = in2(25,:);
u2 = in2(26,:);
u3 = in2(27,:);
u4 = in2(28,:);
u5 = in2(29,:);
u6 = in2(30,:);
u7 = in2(31,:);
u8 = in2(32,:);
u9 = in2(33,:);
u10 = in2(34,:);
u11 = in2(35,:);
u12 = in2(36,:);
t2 = cos(gamma_);
t3 = sin(gamma_);
t4 = lambda_.^2;
t5 = q4.*2.0;
t6 = q5.*2.0;
t7 = q6.*2.0;
t8 = q10.*2.0;
t9 = q11.*2.0;
t10 = q12.*2.0;
t11 = q4.^2;
t12 = q5.^2;
t13 = q6.^2;
t14 = q10.^2;
t15 = q11.^2;
t16 = q12.^2;
t17 = r_o_.^2;
t18 = r_p1_.^2;
t20 = r_s1_.^2;
t21 = r_s2_.^2;
t28 = 1.0./l_s_;
t29 = 1.0./lambda_;
t31 = -q1;
t32 = -q2;
t33 = -q3;
t34 = -q7;
t35 = -q8;
t36 = -q9;
t37 = -q10;
t38 = -q11;
t39 = -q12;
t45 = q4.*q5.*-2.0;
t46 = q4.*q6.*-2.0;
t47 = q5.*q6.*-2.0;
t65 = 1.0./sqrt(lambda_);
t66 = sqrt(7.0e+1);
t19 = t18.^2;
t22 = t20.^2;
t23 = t21.^2;
t24 = t2.^2;
t25 = q5.*t5;
t26 = q6.*t5;
t27 = q6.*t6;
t30 = 1.0./t4;
t40 = q4.*t5;
t41 = q5.*t6;
t42 = q6.*t7;
t43 = 1.0./t3.^2;
t48 = -t11;
t49 = t11.*-2.0;
t50 = -t12;
t51 = t12.*-2.0;
t52 = -t13;
t53 = t13.*-2.0;
t54 = -t14;
t55 = -t15;
t56 = -t16;
t57 = -t21;
t59 = q1+t34;
t60 = q2+t35;
t61 = q3+t36;
t62 = q4+t37;
t63 = q5+t38;
t64 = q6+t39;
t44 = t43.^2;
t58 = -t23;
t67 = t4.*t24;
t68 = q4.*t59;
t69 = q5.*t59;
t70 = q4.*t60;
t71 = q6.*t59;
t72 = q5.*t60;
t73 = q4.*t61;
t74 = q6.*t60;
t75 = q5.*t61;
t76 = q6.*t61;
t77 = t6.*t59;
t78 = t5.*t60;
t79 = t7.*t59;
t80 = t5.*t61;
t81 = t7.*t60;
t82 = t6.*t61;
t83 = t20+t57;
t99 = t40+t41-1.0;
t100 = t40+t42-1.0;
t101 = t41+t42-1.0;
t104 = t48+t50+t52+1.0;
t105 = t54+t55+t56+1.0;
t84 = t22+t58;
t85 = -t68;
t86 = -t70;
t87 = t69.*-2.0;
t88 = -t71;
t89 = t70.*-2.0;
t90 = -t72;
t91 = t71.*-2.0;
t92 = t73.*-2.0;
t93 = -t75;
t94 = t74.*-2.0;
t95 = t75.*-2.0;
t96 = -t76;
t97 = t67-1.0;
t102 = t29.*t83;
t109 = sqrt(t104);
t110 = sqrt(t105);
t113 = t68+t72+t76;
t98 = t97.^2;
t103 = t30.*t84;
t106 = t18.*t43.*t97.*6.0;
t111 = 1.0./t109;
t112 = 1.0./t110;
t114 = t109.*2.0;
t115 = t110.*2.0;
t116 = t5.*t109;
t117 = t6.*t109;
t118 = t7.*t109;
t119 = -t110;
t121 = q4.*t109.*-2.0;
t122 = q5.*t109.*-2.0;
t123 = q6.*t109.*-2.0;
t142 = t59.*t109;
t143 = t60.*t109;
t144 = t61.*t109;
t107 = -t106;
t108 = t19.*t44.*t98.*6.0;
t120 = -t115;
t124 = t25.*t111;
t125 = t26.*t111;
t126 = t27.*t111;
t127 = q10.*t5.*t112;
t128 = q11.*t5.*t112;
t129 = q10.*t6.*t112;
t130 = q12.*t5.*t112;
t131 = q11.*t6.*t112;
t132 = q10.*t7.*t112;
t133 = q12.*t6.*t112;
t134 = q11.*t7.*t112;
t135 = q12.*t7.*t112;
t136 = t40.*t111;
t137 = t41.*t111;
t138 = t42.*t111;
t139 = t45.*t111;
t140 = t46.*t111;
t141 = t47.*t111;
t145 = t27+t116;
t146 = t26+t117;
t147 = t25+t118;
t148 = -t142;
t149 = -t143;
t150 = -t144;
t151 = t69.*t111;
t152 = t70.*t111;
t153 = t71.*t111;
t154 = t73.*t111;
t155 = t74.*t111;
t156 = t75.*t111;
t157 = t47+t116;
t158 = t46+t117;
t159 = t45+t118;
t163 = q5.*t68.*t111;
t164 = q6.*t68.*t111;
t166 = q6.*t72.*t111;
t169 = t5.*t62.*t111;
t170 = t6.*t62.*t111;
t171 = t5.*t63.*t111;
t172 = t7.*t62.*t111;
t173 = t6.*t63.*t111;
t174 = t5.*t64.*t111;
t175 = t7.*t63.*t111;
t176 = t6.*t64.*t111;
t177 = t7.*t64.*t111;
t178 = q6.*t85.*t111;
t179 = q5.*t86.*t111;
t180 = q6.*t93.*t111;
t205 = t69+t86+t144;
t206 = t73+t88+t143;
t207 = t74+t93+t142;
t208 = t109+t119;
t160 = t5+t133;
t161 = t6+t132;
t162 = t7+t128;
t165 = q5.*t152;
t167 = q6.*t154;
t168 = q6.*t156;
t181 = t102+t107;
t182 = t59+t155;
t183 = q8+t32+t153;
t184 = t61+t151;
t185 = q7+t31+t156;
t186 = t60+t154;
t187 = q9+t33+t152;
t188 = t103+t108;
t209 = t114+t127;
t210 = t114+t131;
t211 = t114+t135;
t218 = t9+t140+t172;
t219 = t10+t139+t171;
t220 = t8+t141+t176;
t221 = q4.*t111.*t205;
t222 = q4.*t111.*t206;
t223 = q5.*t111.*t205;
t224 = q4.*t111.*t207;
t225 = q5.*t111.*t206;
t226 = q6.*t111.*t205;
t227 = q5.*t111.*t207;
t228 = q6.*t111.*t206;
t229 = q6.*t111.*t207;
t189 = q4.*t182;
t190 = q4.*t185;
t191 = q5.*t183;
t192 = q4.*t186;
t193 = q4.*t187;
t194 = q5.*t184;
t195 = q5.*t185;
t196 = q6.*t182;
t197 = q6.*t183;
t198 = q5.*t186;
t199 = q6.*t184;
t200 = q6.*t187;
t204 = (t188.*pi)./4.0;
t212 = t109.*t182;
t213 = t109.*t183;
t214 = t109.*t184;
t215 = t109.*t185;
t216 = t109.*t186;
t217 = t109.*t187;
t201 = -t193;
t202 = -t195;
t203 = -t197;
t233 = t70+t87+t150+t178+t192+t217+t222;
t234 = t75+t94+t148+t179+t194+t215+t223;
t235 = t71+t92+t149+t180+t196+t213+t229;
t230 = t73+t91+t143+t163+t201+t216+t221;
t231 = t69+t89+t144+t166+t202+t214+t227;
t232 = t74+t95+t142+t167+t203+t212+t228;
out1 = reshape([t101,t45+t123,t158,t85+t90+t96-t198+t200+t224,t231,t235,t51+t53+1.0,t147,t26+t122,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t159,t100,t47+t121,t233,t85+t90+t96+t190-t199+t225,t232,t25+t123,t49+t53+1.0,t145,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t46+t122,t157,t99,t230,t234,t85+t90+t96-t189+t191+t226,t146,t27+t121,t49+t51+1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t120+t169+t49.*t111,-t10+t139+t170,t218,0.0,0.0,0.0,t209,t162,-t6+t130,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t219,t120+t173+t51.*t111,-t8+t141+t175,0.0,0.0,0.0,-t7+t129,t210,t160,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-t9+t140+t174,t220,t120+t177+t53.*t111,0.0,0.0,0.0,t161,-t5+t134,t211,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[24,6]);
if nargout > 1
    out2 = [E_s_.*t28.*t29.*t181.*pi.*(q4.*t113-q5.*t205+q6.*t206+t109.*t207).*(-4.0./3.0);E_s_.*t28.*t29.*t181.*pi.*(q5.*t113+q4.*t205-q6.*t207+t109.*t206).*(-4.0./3.0);E_s_.*t28.*t29.*t181.*pi.*(l_s_./4.0+q6.*t113-q4.*t206+q5.*t207+t109.*t205).*-4.0;E_s_.*t28.*t29.*(t204-t17.*t18.*t29.*t43.*t97.*pi.*3.0).*(q6.*t63.*2.0-t6.*t64+t62.*t114-t5.*t208).*-4.0;E_s_.*t28.*t29.*(t204-t17.*t18.*t29.*t43.*t97.*pi.*3.0).*(q4.*t64.*2.0-t7.*t62+t63.*t114-t6.*t208).*-4.0;E_s_.*t28.*t29.*t188.*pi.*(q5.*t62.*2.0-t5.*t63+t64.*t114-t7.*t208).*(-2.0./3.0)];
end
if nargout > 2
    out3 = [-mu_x_.*(t101.*u1-t101.*u7-t147.*u2+t147.*u8+t158.*u3-t158.*u9+t231.*u5+t235.*u6-u4.*(t113+t198-t200-t224));-mu_y_.*(t100.*u2-t100.*u8-t145.*u3+t145.*u9+t159.*u1-t159.*u7+t233.*u4+t232.*u6-u5.*(t113-t190+t199-t225));-mu_z_.*(t99.*u3-t99.*u9-t146.*u1+t146.*u7+t157.*u2-t157.*u8+t230.*u4+t234.*u5-u6.*(t113+t189-t191-t226));-mu_xx_.*(t162.*u11+t209.*u10+t218.*u6-u12.*(t6-q4.*q12.*t112.*2.0)-u5.*(t10+t124-q5.*t62.*t111.*2.0)-u4.*(t115+t136-q4.*t62.*t111.*2.0));-mu_yy_.*(t160.*u12+t210.*u11+t219.*u4-u10.*(t7-q5.*q10.*t112.*2.0)-u6.*(t8+t126-q6.*t63.*t111.*2.0)-u5.*(t115+t137-q5.*t63.*t111.*2.0));-mu_zz_.*(t161.*u10+t211.*u12+t220.*u5-u11.*(t5-q6.*q11.*t112.*2.0)-u4.*(t9+t125-q4.*t64.*t111.*2.0)-u6.*(t115+t138-q6.*t64.*t111.*2.0))];
end
if nargout > 3
    out4 = [0.0;0.0;-t18.*t43.*t97.*pi.*(p1_+p2_+p3_+p4_+p5_+p6_);p1_.*r_o_.*t18.*t43.*t65.*t97.*pi.*(-2.71e+2./2.89e+2)-p2_.*r_o_.*t18.*t43.*t65.*t97.*pi.*(2.71e+2./2.89e+2)+p3_.*r_o_.*t18.*t43.*t65.*t97.*pi.*1.67999098695029e-1+p4_.*r_o_.*t18.*t43.*t65.*t97.*pi.*7.697171642807495e-1+p5_.*r_o_.*t18.*t43.*t65.*t97.*pi.*7.697171642807493e-1+p6_.*r_o_.*t18.*t43.*t65.*t97.*pi.*1.679990986950289e-1;p3_.*r_o_.*t18.*t43.*t65.*t97.*pi.*9.857871488499218e-1+p4_.*r_o_.*t18.*t43.*t65.*t97.*pi.*6.383850617077452e-1-p5_.*r_o_.*t18.*t43.*t65.*t97.*pi.*6.383850617077454e-1-p6_.*r_o_.*t18.*t43.*t65.*t97.*pi.*9.857871488499218e-1-p1_.*r_o_.*t18.*t43.*t65.*t66.*t97.*pi.*(1.2e+1./2.89e+2)+p2_.*r_o_.*t18.*t43.*t65.*t66.*t97.*pi.*(1.2e+1./2.89e+2);0.0];
end
if nargout > 4
    out5 = zeros(0,0);
end
if nargout > 5
    out6 = 1.0;
end