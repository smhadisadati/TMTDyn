function [out1,out2] = loadsF1(in1,in2,s)
%LOADSF1
%    [OUT1,OUT2] = LOADSF1(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.0.
%    11-Jan-2019 21:59:39

f_tx_sym = in1(:,28);
f_ty_sym = in1(:,29);
f_tz_sym = in1(:,30);
l_f_sym = in1(:,17);
l_s_sym = in1(:,5);
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
q29 = in2(:,29);
q30 = in2(:,30);
tau_tx_sym = in1(:,31);
tau_ty_sym = in1(:,32);
tau_tz_sym = in1(:,33);
t2 = l_s_sym.^2;
t3 = t2.^2;
t12 = l_s_sym.*q16;
t13 = q17.*t2;
t14 = l_s_sym.*q18.*t2;
t15 = q19.*t3;
t16 = l_s_sym.*q20.*t3;
t4 = t12+t13+t14+t15+t16;
t17 = l_s_sym.*q21;
t18 = q22.*t2;
t19 = l_s_sym.*q23.*t2;
t20 = q24.*t3;
t21 = l_s_sym.*q25.*t3;
t5 = t17+t18+t19+t20+t21;
t6 = l_s_sym.*q26;
t7 = q27.*t2;
t8 = l_s_sym.*q28.*t2;
t9 = q29.*t3;
t10 = l_s_sym.*q30.*t3;
t11 = t6+t7+t8+t9+t10;
t22 = t4.^2;
t23 = t5.^2;
t24 = t11.^2;
t25 = -t22-t23-t24+1.0;
t26 = 1.0./sqrt(t25);
t27 = sqrt(t25);
t28 = l_f_sym.*l_s_sym.*t11.*2.0;
t29 = l_s_sym.*t4.*t5.*t26.*2.0;
t30 = l_s_sym.*t27.*2.0;
t31 = l_f_sym.*t2.*t11.*2.0;
t32 = t2.*t4.*t5.*t26.*2.0;
t33 = t2.*t27.*2.0;
t34 = l_f_sym.*l_s_sym.*t2.*t11.*2.0;
t35 = l_s_sym.*t2.*t4.*t5.*t26.*2.0;
t36 = l_s_sym.*t2.*t27.*2.0;
t37 = l_f_sym.*t3.*t11.*2.0;
t38 = t3.*t4.*t5.*t26.*2.0;
t39 = t3.*t27.*2.0;
t40 = l_f_sym.*l_s_sym.*t3.*t11.*2.0;
t41 = l_s_sym.*t3.*t4.*t5.*t26.*2.0;
t42 = l_s_sym.*t3.*t27.*2.0;
t43 = l_s_sym.*t5.*2.0;
t44 = l_s_sym.*t4.*t11.*t26.*2.0;
t45 = l_s_sym.*t5.*t11.*t26.*2.0;
t46 = t2.*t5.*2.0;
t47 = t2.*t4.*t11.*t26.*2.0;
t48 = t2.*t5.*t11.*t26.*2.0;
t49 = l_s_sym.*t2.*t5.*2.0;
t50 = l_s_sym.*t2.*t4.*t11.*t26.*2.0;
t51 = l_s_sym.*t2.*t5.*t11.*t26.*2.0;
t52 = t3.*t5.*2.0;
t53 = t3.*t4.*t11.*t26.*2.0;
t54 = t3.*t5.*t11.*t26.*2.0;
t55 = l_s_sym.*t3.*t5.*2.0;
t56 = l_s_sym.*t3.*t4.*t11.*t26.*2.0;
t57 = l_s_sym.*t3.*t5.*t11.*t26.*2.0;
out1 = reshape([t2,l_s_sym.*t2,t3,l_s_sym.*t3,t2.*t3,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t28-l_f_sym.*l_s_sym.*t4.*t5.*t26.*2.0,t31-l_f_sym.*t2.*t4.*t5.*t26.*2.0,t34-l_f_sym.*l_s_sym.*t2.*t4.*t5.*t26.*2.0,t37-l_f_sym.*t3.*t4.*t5.*t26.*2.0,t40-l_f_sym.*l_s_sym.*t3.*t4.*t5.*t26.*2.0,l_f_sym.*l_s_sym.*t27.*2.0-l_f_sym.*l_s_sym.*t23.*t26.*2.0,l_f_sym.*t2.*t27.*2.0-l_f_sym.*t2.*t23.*t26.*2.0,l_f_sym.*l_s_sym.*t2.*t27.*2.0-l_f_sym.*l_s_sym.*t2.*t23.*t26.*2.0,l_f_sym.*t3.*t27.*2.0-l_f_sym.*t3.*t23.*t26.*2.0,l_f_sym.*l_s_sym.*t3.*t27.*2.0-l_f_sym.*l_s_sym.*t3.*t23.*t26.*2.0,l_f_sym.*l_s_sym.*t4.*2.0-l_f_sym.*l_s_sym.*t5.*t11.*t26.*2.0,l_f_sym.*t2.*t4.*2.0-l_f_sym.*t2.*t5.*t11.*t26.*2.0,l_f_sym.*l_s_sym.*t2.*t4.*2.0-l_f_sym.*l_s_sym.*t2.*t5.*t11.*t26.*2.0,l_f_sym.*t3.*t4.*2.0-l_f_sym.*t3.*t5.*t11.*t26.*2.0,l_f_sym.*l_s_sym.*t3.*t4.*2.0-l_f_sym.*l_s_sym.*t3.*t5.*t11.*t26.*2.0,0.0,0.0,0.0,0.0,0.0,t2,l_s_sym.*t2,t3,l_s_sym.*t3,t2.*t3,0.0,0.0,0.0,0.0,0.0,l_f_sym.*l_s_sym.*t27.*-2.0+l_f_sym.*l_s_sym.*t22.*t26.*2.0,l_f_sym.*t2.*t27.*-2.0+l_f_sym.*t2.*t22.*t26.*2.0,l_f_sym.*l_s_sym.*t2.*t27.*-2.0+l_f_sym.*l_s_sym.*t2.*t22.*t26.*2.0,l_f_sym.*t3.*t27.*-2.0+l_f_sym.*t3.*t22.*t26.*2.0,l_f_sym.*l_s_sym.*t3.*t27.*-2.0+l_f_sym.*l_s_sym.*t3.*t22.*t26.*2.0,t28+l_f_sym.*l_s_sym.*t4.*t5.*t26.*2.0,t31+l_f_sym.*t2.*t4.*t5.*t26.*2.0,t34+l_f_sym.*l_s_sym.*t2.*t4.*t5.*t26.*2.0,t37+l_f_sym.*t3.*t4.*t5.*t26.*2.0,t40+l_f_sym.*l_s_sym.*t3.*t4.*t5.*t26.*2.0,l_f_sym.*l_s_sym.*t5.*2.0+l_f_sym.*l_s_sym.*t4.*t11.*t26.*2.0,l_f_sym.*t2.*t5.*2.0+l_f_sym.*t2.*t4.*t11.*t26.*2.0,l_f_sym.*l_s_sym.*t2.*t5.*2.0+l_f_sym.*l_s_sym.*t2.*t4.*t11.*t26.*2.0,l_f_sym.*t3.*t5.*2.0+l_f_sym.*t3.*t4.*t11.*t26.*2.0,l_f_sym.*l_s_sym.*t3.*t5.*2.0+l_f_sym.*l_s_sym.*t3.*t4.*t11.*t26.*2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t2,l_s_sym.*t2,t3,l_s_sym.*t3,t2.*t3,l_f_sym.*l_s_sym.*t4.*-4.0,l_f_sym.*t2.*t4.*-4.0,l_f_sym.*l_s_sym.*t2.*t4.*-4.0,l_f_sym.*t3.*t4.*-4.0,l_f_sym.*l_s_sym.*t3.*t4.*-4.0,l_f_sym.*l_s_sym.*t5.*-4.0,l_f_sym.*t2.*t5.*-4.0,l_f_sym.*l_s_sym.*t2.*t5.*-4.0,l_f_sym.*t3.*t5.*-4.0,l_f_sym.*l_s_sym.*t3.*t5.*-4.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t30+l_s_sym.*t22.*t26.*2.0,t33+t2.*t22.*t26.*2.0,t36+l_s_sym.*t2.*t22.*t26.*2.0,t39+t3.*t22.*t26.*2.0,t42+l_s_sym.*t3.*t22.*t26.*2.0,t29+l_s_sym.*t11.*2.0,t32+t2.*t11.*2.0,t35+l_s_sym.*t2.*t11.*2.0,t38+t3.*t11.*2.0,t41+l_s_sym.*t3.*t11.*2.0,-t43+t44,-t46+t47,-t49+t50,-t52+t53,-t55+t56,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t29-l_s_sym.*t11.*2.0,t32-t2.*t11.*2.0,t35-l_s_sym.*t2.*t11.*2.0,t38-t3.*t11.*2.0,t41-l_s_sym.*t3.*t11.*2.0,t30+l_s_sym.*t23.*t26.*2.0,t33+t2.*t23.*t26.*2.0,t36+l_s_sym.*t2.*t23.*t26.*2.0,t39+t3.*t23.*t26.*2.0,t42+l_s_sym.*t3.*t23.*t26.*2.0,t45+l_s_sym.*t4.*2.0,t48+t2.*t4.*2.0,t51+l_s_sym.*t2.*t4.*2.0,t54+t3.*t4.*2.0,t57+l_s_sym.*t3.*t4.*2.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t43+t44,t46+t47,t49+t50,t52+t53,t55+t56,t45-l_s_sym.*t4.*2.0,t48-t2.*t4.*2.0,t51-l_s_sym.*t2.*t4.*2.0,t54-t3.*t4.*2.0,t57-l_s_sym.*t3.*t4.*2.0,t30+l_s_sym.*t24.*t26.*2.0,t33+t2.*t24.*t26.*2.0,t36+l_s_sym.*t2.*t24.*t26.*2.0,t39+t3.*t24.*t26.*2.0,t42+l_s_sym.*t3.*t24.*t26.*2.0],[30,6]);
if nargout > 1
    t58 = t4.*tau_tx_sym;
    t59 = t5.*tau_ty_sym;
    t60 = t11.*tau_tz_sym;
    t61 = t58+t59+t60;
    t62 = t5.*tau_tx_sym;
    t63 = t27.*tau_tz_sym;
    t73 = t4.*tau_ty_sym;
    t64 = t62+t63-t73;
    t65 = t11.*tau_ty_sym;
    t66 = t27.*tau_tx_sym;
    t72 = t5.*tau_tz_sym;
    t67 = t65+t66-t72;
    t68 = t4.*tau_tz_sym;
    t69 = t27.*tau_ty_sym;
    t71 = t11.*tau_tx_sym;
    t70 = t68+t69-t71;
    out2 = [f_tx_sym;f_ty_sym;f_tz_sym;t4.*t61-t5.*t64+t11.*t70+t27.*t67;t5.*t61+t4.*t64-t11.*t67+t27.*t70;t5.*t67+t11.*t61-t4.*t70+t27.*t64];
end
