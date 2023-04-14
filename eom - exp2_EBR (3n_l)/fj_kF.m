function out1 = fj_kF(in1,in2,s,ds,t_sym)
%FJ_KF
%    OUT1 = FJ_KF(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    14-Jun-2021 23:16:02

E_s_ = in1(:,2);
gamma_ = in1(:,21);
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
q10 = in2(10,:);
q11 = in2(11,:);
q12 = in2(12,:);
q13 = in2(13,:);
q14 = in2(14,:);
q15 = in2(15,:);
q16 = in2(16,:);
q17 = in2(17,:);
q18 = in2(18,:);
r_o_ = in1(:,20);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
t2 = cos(gamma_);
t3 = sin(gamma_);
t4 = lambda_.^2;
t5 = r_o_.^2;
t6 = r_p1_.^2;
t8 = r_s1_.^2;
t9 = r_s2_.^2;
t13 = 1.0./l_s_;
t14 = 1.0./lambda_;
t7 = t6.^2;
t10 = t8.^2;
t11 = t9.^2;
t12 = t2.^2;
t15 = 1.0./t4;
t16 = 1.0./t3.^2;
t18 = -t9;
t17 = t16.^2;
t19 = -t11;
t20 = t4.*t12;
t21 = t8+t18;
t22 = t10+t19;
t23 = t20-1.0;
t25 = t14.*t21;
t24 = t23.^2;
t26 = t15.*t22;
t27 = t6.*t16.*t23.*6.0;
t30 = lambda_.*t5.*t6.*t16.*t23.*pi;
t37 = t5.*t6.*t14.*t16.*t23.*pi.*3.0;
t39 = t5.*t6.*t14.*t16.*t23.*pi.*3.0;
t28 = -t27;
t29 = t7.*t17.*t24.*6.0;
t31 = -t30;
t38 = -t37;
t40 = -t39;
t32 = t25+t28;
t33 = t26+t29;
t34 = (t33.*pi)./2.0;
t35 = (t33.*pi)./4.0;
t36 = t31+t34;
t41 = t35+t38;
t42 = t35+t40;
out1 = [E_s_.*q1.*t13.*t14.*t32.*pi;E_s_.*q2.*t13.*t14.*t32.*pi;E_s_.*q3.*t13.*t14.*t32.*pi.*3.0;E_s_.*q4.*t13.*t14.*t42.*3.0;E_s_.*q5.*t13.*t14.*t41.*3.0;-E_s_.*q6.*t13.*t14.*(t30-t34);E_s_.*q7.*t13.*t14.*t32.*pi;E_s_.*q8.*t13.*t14.*t32.*pi;E_s_.*q9.*t13.*t14.*t32.*pi.*3.0;E_s_.*q10.*t13.*t14.*t42.*3.0;E_s_.*q11.*t13.*t14.*t41.*3.0;-E_s_.*q12.*t13.*t14.*(t30-t34);E_s_.*q13.*t13.*t14.*t32.*pi;E_s_.*q14.*t13.*t14.*t32.*pi;E_s_.*q15.*t13.*t14.*t32.*pi.*3.0;E_s_.*q16.*t13.*t14.*t42.*3.0;E_s_.*q17.*t13.*t14.*t41.*3.0;-E_s_.*q18.*t13.*t14.*(t30-t34)];
