function out1 = rjtipF(in1,in2,s,ds,t_sym)
%RJTIPF
%    OUT1 = RJTIPF(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 16:28:44

l_f_ = in1(:,17);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
q1 = in2(1,:);
q2 = in2(2,:);
q3 = in2(3,:);
q4 = in2(4,:);
q5 = in2(5,:);
r_f_ = in1(:,18);
r_s2_ = in1(:,4);
t2 = NaN;
t3 = l_s_.^2;
t4 = q1.^2;
t5 = q2.^2;
t6 = s.^2;
t7 = l_s_.*q3.*2.0;
t8 = sqrt(2.0);
t13 = (l_s_.*q4)./2.0;
t9 = q1.*t3;
t10 = q2.*t3;
t11 = q3.*t3;
t12 = s.*t7;
t14 = t7+1.0;
t16 = s.*t13;
t17 = (q5.*t3)./2.0;
t19 = t3.*t4.*4.0;
t20 = t3.*t5.*4.0;
t15 = t12+1.0;
t18 = t14.^2;
t22 = t6.*t17;
t23 = t6.*t19;
t24 = t6.*t20;
t25 = t13+t17;
t21 = t15.^2;
t26 = cos(t25);
t27 = sin(t25);
t28 = t16+t22;
t31 = t18+t19+t20;
t29 = cos(t28);
t30 = sin(t28);
t32 = 1.0./sqrt(t31);
t33 = t21+t23+t24;
t34 = t14.*t32;
t35 = 1.0./sqrt(t33);
t36 = t34+1.0;
t39 = t15.*t35;
t37 = sqrt(t36);
t40 = t39+1.0;
t38 = 1.0./t37;
t41 = sqrt(t40);
t43 = (t8.*t26.*t37)./2.0;
t44 = (t8.*t27.*t37)./2.0;
t42 = 1.0./t41;
t45 = l_s_.*q1.*t8.*t26.*t32.*t38;
t46 = l_s_.*q2.*t8.*t26.*t32.*t38;
t47 = l_s_.*q1.*t8.*t27.*t32.*t38;
t48 = l_s_.*q2.*t8.*t27.*t32.*t38;
t49 = -t46;
t50 = -t47;
t51 = t45+t48;
t52 = t46+t50;
t53 = t47+t49;
out1 = reshape([t6.*t9,t9,t6.*t10,t10,l_s_.*s+t6.*t11,l_s_+t11,t2,t9+l_f_.*t8.*t26.*t37.*t51-l_f_.*t8.*t27.*t37.*t52,t2,t10+l_f_.*t8.*t26.*t37.*t52+l_f_.*t8.*t27.*t37.*t51,t2,l_s_+t11-l_f_.*t51.^2-l_f_.*t52.^2+(l_f_.*t26.^2.*t36)./2.0+(l_f_.*t27.^2.*t36)./2.0,(t8.*t29.*t41)./2.0,t43,l_s_.*q1.*s.*t8.*t30.*t35.*t42-l_s_.*q2.*s.*t8.*t29.*t35.*t42,t53,l_s_.*q1.*s.*t8.*t29.*t35.*t42+l_s_.*q2.*s.*t8.*t30.*t35.*t42,t51,(t8.*t30.*t41)./2.0,t44,t2,t43,t2,t53,t2,t51,t2,t44,1.0./sqrt(lambda_).*r_s2_,r_f_],[2,15]);
