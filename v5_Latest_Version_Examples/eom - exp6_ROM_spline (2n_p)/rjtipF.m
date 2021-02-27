function out1 = rjtipF(in1,in2,s,ds,t_sym)
%RJTIPF
%    OUT1 = RJTIPF(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 16:49:40

l_f_ = in1(:,17);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
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
r_s2_ = in1(:,4);
t2 = NaN;
t3 = l_s_.*q7;
t4 = l_s_.*s;
t5 = l_s_.*2.0;
t6 = l_s_.^2;
t7 = s.^2;
t13 = -l_s_;
t14 = l_s_.*q1.*-2.0;
t15 = l_s_.*q3.*-2.0;
t16 = l_s_.*q5.*-2.0;
t18 = sqrt(2.0);
t26 = l_s_.*2.0e+2;
t34 = q1./2.0e+1;
t35 = q3./2.0e+1;
t36 = q5./2.0e+1;
t37 = q8./2.0e+1;
t38 = q7./4.0e+1;
t45 = l_s_-1.0./4.0e+1;
t54 = q1./1.6e+3;
t55 = q3./1.6e+3;
t56 = q5./1.6e+3;
t57 = q8./1.6e+3;
t8 = q1.*t5;
t9 = q3.*t5;
t10 = q5.*t5;
t11 = t4.*2.0;
t12 = s.*t3;
t17 = -t3;
t19 = q1.*t6;
t20 = q3.*t6;
t21 = q5.*t6;
t22 = q8.*t6;
t27 = t3./2.0;
t28 = t4.*2.0e+2;
t29 = q1.*t4.*-2.0;
t30 = q3.*t4.*-2.0;
t31 = q5.*t4.*-2.0;
t33 = -t26;
t47 = t36+1.0;
t48 = q1.*t4.^2;
t49 = q3.*t4.^2;
t50 = q5.*t4.^2;
t51 = q8.*t4.^2;
t53 = q7+t37;
t58 = t5-1.0./2.0e+1;
t59 = t45.^2;
t61 = t4-1.0./4.0e+1;
t80 = t34.*t45;
t81 = t35.*t45;
t23 = q1.*t11;
t24 = q3.*t11;
t25 = q5.*t11;
t32 = -t12;
t39 = -t28;
t40 = -t19;
t41 = -t20;
t42 = -t21;
t43 = -t22;
t44 = t12./2.0;
t46 = t33+5.0;
t52 = t22./2.0;
t64 = -t51;
t65 = t11-1.0./2.0e+1;
t66 = t51./2.0;
t68 = q2.*t58;
t69 = q4.*t58;
t70 = q6.*t58;
t71 = q2.*t59;
t72 = q4.*t59;
t73 = q6.*t59;
t74 = q9.*t59;
t75 = t61.^2;
t85 = t45.*t47;
t86 = t45.*t53;
t87 = t53.*t61;
t60 = exp(t46);
t62 = t39+5.0;
t77 = q2.*t65;
t78 = q4.*t65;
t79 = q6.*t65;
t82 = q9.*t75;
t88 = t14+t34+t68;
t89 = t15+t35+t69;
t90 = t16+t36+t70;
t97 = t40+t54+t71+t80;
t98 = t41+t55+t72+t81;
t114 = t13+t42+t56+t73+t85+1.0./4.0e+1;
t115 = t17+t38+t43+t57+t74+t86;
t63 = exp(t62);
t67 = t60+1.0;
t91 = t29+t34+t77;
t92 = t30+t35+t78;
t93 = t31+t36+t79;
t118 = t32+t38+t57+t64+t82+t87;
t76 = t63+1.0;
t83 = 1.0./t67;
t84 = 1.0./t76;
t94 = t83.*t88;
t95 = t83.*t89;
t96 = t83.*t90;
t116 = t83.*t97;
t117 = t83.*t98;
t119 = t83.*t114;
t120 = (t83.*t115)./2.0;
t99 = t84.*t91;
t100 = t84.*t92;
t101 = t84.*t93;
t102 = t8+t94;
t103 = t9+t95;
t104 = t10+t96+1.0;
t121 = (t84.*t118)./2.0;
t122 = t27+t52+t120;
t105 = t102.^2;
t106 = t103.^2;
t107 = t104.^2;
t108 = t23+t99;
t109 = t24+t100;
t110 = t25+t101+1.0;
t123 = cos(t122);
t124 = sin(t122);
t125 = t44+t66+t121;
t111 = t108.^2;
t112 = t109.^2;
t113 = t110.^2;
t126 = cos(t125);
t127 = sin(t125);
t128 = t105+t106+t107;
t129 = 1.0./sqrt(t128);
t130 = t111+t112+t113;
t131 = 1.0./sqrt(t130);
t132 = t104.*t129;
t133 = t132+1.0;
t136 = t110.*t131;
t134 = sqrt(t133);
t137 = t136+1.0;
t135 = 1.0./t134;
t138 = sqrt(t137);
t140 = (t18.*t123.*t134)./2.0;
t141 = (t18.*t124.*t134)./2.0;
t139 = 1.0./t138;
t142 = (t18.*t102.*t123.*t129.*t135)./2.0;
t143 = (t18.*t103.*t123.*t129.*t135)./2.0;
t144 = (t18.*t102.*t124.*t129.*t135)./2.0;
t145 = (t18.*t103.*t124.*t129.*t135)./2.0;
t146 = -t143;
t147 = -t144;
t148 = t142+t145;
t149 = t144+t146;
t150 = t143+t147;
out1 = reshape([t48+t84.*(-t48+t54+q2.*t75+t34.*t61),t19+t116,t49+t84.*(-t49+t55+q4.*t75+t35.*t61),t20+t117,t4+t50+t84.*(-t4-t50+t56+q6.*t75+t47.*t61+1.0./4.0e+1),l_s_+t21+t119,t2,t19+t116+l_f_.*t18.*t123.*t134.*t148-l_f_.*t18.*t124.*t134.*t150,t2,t20+t117+l_f_.*t18.*t124.*t134.*t148+l_f_.*t18.*t123.*t134.*t150,t2,l_s_+t21+t119-l_f_.*t148.^2-l_f_.*t150.^2+(l_f_.*t123.^2.*t133)./2.0+(l_f_.*t124.^2.*t133)./2.0,(t18.*t126.*t138)./2.0,t140,(t18.*t108.*t127.*t131.*t139)./2.0-(t18.*t109.*t126.*t131.*t139)./2.0,t149,(t18.*t108.*t126.*t131.*t139)./2.0+(t18.*t109.*t127.*t131.*t139)./2.0,t148,(t18.*t127.*t138)./2.0,t141,t2,t140,t2,t149,t2,t148,t2,t141,1.0./sqrt(lambda_).*r_s2_,r_f_],[2,15]);
