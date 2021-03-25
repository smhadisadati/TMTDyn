function [out1,out2,out3,out4] = massF4(in1,in2,s,ds,t_sym)
%MASSF4
%    [OUT1,OUT2,OUT3,OUT4] = MASSF4(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    26-Feb-2021 21:20:47

g_x_ = in1(:,13);
g_y_ = in1(:,14);
g_z_ = in1(:,15);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
q22 = in2(22,:);
q23 = in2(23,:);
q24 = in2(24,:);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
sigma_s_ = in1(:,1);
u22 = in2(46,:);
u23 = in2(47,:);
u24 = in2(48,:);
t2 = l_s_.^2;
t3 = lambda_.^2;
t4 = q22.*2.0;
t5 = q23.*2.0;
t6 = q24.*2.0;
t7 = q22.^2;
t8 = q23.^2;
t9 = q24.^2;
t10 = r_p1_.^2;
t11 = r_s1_.^2;
t12 = r_s2_.^2;
t13 = 1.0./lambda_;
t14 = t10.*6.0;
t15 = t11.*3.0;
t16 = t12.*3.0;
t17 = -t7;
t18 = -t8;
t19 = -t9;
t20 = -t12;
t23 = (t2.*t3)./1.92e+2;
t21 = t11+t20;
t22 = t15+t16;
t26 = t17+t18+t19+1.0;
t24 = t14+t21;
t25 = (t13.*t22)./1.2e+1;
t29 = sqrt(t26);
t27 = (l_s_.*sigma_s_.*t24.*pi)./4.0;
t30 = 1.0./t29;
t32 = t29.*2.0;
t47 = t23+t25;
t28 = -t27;
t31 = t30.^3;
t33 = t4.*t30;
t34 = t5.*t30;
t35 = t6.*t30;
t49 = (l_s_.*sigma_s_.*t21.*t47.*pi)./4.0;
t36 = q23.*t33;
t37 = q24.*t33;
t38 = q24.*t34;
t39 = q23.*q24.*t4.*t31;
t40 = t4.*t8.*t31;
t41 = q22.*q23.*t4.*t31;
t42 = t4.*t9.*t31;
t43 = q22.*q24.*t4.*t31;
t44 = t5.*t9.*t31;
t45 = q23.*q24.*t5.*t31;
t50 = -t49;
out1 = reshape([t28,0.0,0.0,0.0,0.0,0.0,0.0,t28,0.0,0.0,0.0,0.0,0.0,0.0,t28,0.0,0.0,0.0,0.0,0.0,0.0,t50,0.0,0.0,0.0,0.0,0.0,0.0,t50,0.0,0.0,0.0,0.0,0.0,0.0,l_s_.*sigma_s_.*t13.*t21.*pi.*(t11./2.0+t12./2.0).*(-1.0./4.0)],[6,6]);
if nargout > 1
    out2 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,t32+q22.*t33,-t6+t36,t5+t37,0.0,0.0,0.0,t6+t36,t32+q23.*t34,-t4+t38,0.0,0.0,0.0,-t5+t37,t4+t38,t32+q24.*t35],[6,24]);
end
if nargout > 2
    t46 = t39+2.0;
    t48 = t39-2.0;
    t51 = t33+t40;
    t52 = t33+t42;
    t53 = t34+t41;
    t54 = t34+t44;
    t55 = t35+t43;
    t56 = t35+t45;
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t53.*u23+t55.*u24+u22.*(t33+t4.*t7.*t31),t46.*u24+t53.*u22-u23.*(t33-q22.*t8.*t31.*2.0),t48.*u23+t55.*u22-u24.*(t33-q22.*t9.*t31.*2.0),0.0,0.0,0.0,t48.*u24+t51.*u23-u22.*(t34-q23.*t7.*t31.*2.0),t51.*u22+t56.*u24+u23.*(t34+t5.*t8.*t31),t46.*u22+t56.*u23-u24.*(t34-q23.*t9.*t31.*2.0),0.0,0.0,0.0,t46.*u23+t52.*u24-u22.*(t35-q24.*t7.*t31.*2.0),t48.*u22+t54.*u24-u23.*(t35-q24.*t8.*t31.*2.0),t52.*u22+t54.*u23+u24.*(t35+t6.*t9.*t31)],[6,24]);
end
if nargout > 3
    out4 = [g_x_;g_y_;g_z_;0.0;0.0;0.0];
end