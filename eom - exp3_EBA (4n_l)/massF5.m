function [out1,out2,out3,out4] = massF5(in1,in2,s,ds,t_sym)
%MASSF5
%    [OUT1,OUT2,OUT3,OUT4] = MASSF5(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    26-Feb-2021 21:20:47

g_x_ = in1(:,13);
g_y_ = in1(:,14);
g_z_ = in1(:,15);
l_f_ = in1(:,17);
m_f_ = in1(:,16);
q22 = in2(22,:);
q23 = in2(23,:);
q24 = in2(24,:);
r_f_ = in1(:,18);
u22 = in2(46,:);
u23 = in2(47,:);
u24 = in2(48,:);
t2 = l_f_.*q24;
t3 = l_f_.^2;
t4 = q22.*2.0;
t5 = q23.*2.0;
t6 = q24.*2.0;
t7 = q22.^2;
t8 = q22.^3;
t9 = q23.^2;
t10 = q23.^3;
t11 = q24.^2;
t12 = r_f_.^2;
t13 = t12.*3.0;
t14 = -t7;
t15 = -t9;
t16 = -t11;
t17 = (m_f_.*t3)./4.0;
t18 = t3+t13;
t20 = t14+t15+t16+1.0;
t19 = (m_f_.*t18)./1.2e+1;
t22 = sqrt(t20);
t21 = t17+t19;
out1 = reshape([m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,m_f_,0.0,0.0,0.0,0.0,0.0,0.0,t21,0.0,0.0,0.0,0.0,0.0,0.0,t21,0.0,0.0,0.0,0.0,0.0,0.0,(m_f_.*t12)./2.0],[6,6]);
if nargout > 1
    t23 = 1.0./t22;
    t25 = l_f_.*t22;
    t26 = t22.*2.0;
    t24 = t23.^3;
    t27 = t4.*t23;
    t28 = t5.*t23;
    t29 = t6.*t23;
    t30 = l_f_.*q22.*t23;
    t31 = l_f_.*q23.*t23;
    t32 = t2.*t23;
    t33 = q23.*t27;
    t34 = q24.*t27;
    t35 = q24.*t28;
    t36 = q23.*t30;
    out2 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,t2-t36,-t25+l_f_.*t7.*t23,l_f_.*q22.*-2.0,t26+q22.*t27,-t6+t33,t5+t34,t25+l_f_.*t15.*t23,t2+t36,l_f_.*q23.*-2.0,t6+t33,t26+q23.*t28,-t4+t35,l_f_.*q22-q23.*t32,l_f_.*q23+q22.*t32,0.0,-t5+t34,t4+t35,t26+q24.*t29],[6,24]);
end
if nargout > 2
    t37 = q23.*q24.*t4.*t24;
    t38 = q22.*q23.*t2.*t24;
    t39 = l_f_.*q22.*t9.*t24;
    t40 = l_f_.*q23.*t7.*t24;
    t41 = t2.*t7.*t24;
    t42 = t2.*t9.*t24;
    t43 = t4.*t9.*t24;
    t44 = q22.*q23.*t4.*t24;
    t45 = t4.*t11.*t24;
    t46 = q22.*q24.*t4.*t24;
    t47 = t5.*t11.*t24;
    t48 = q23.*q24.*t5.*t24;
    t49 = l_f_+t38;
    t50 = t37+2.0;
    t51 = -t38;
    t52 = t37-2.0;
    t54 = t30+t39;
    t55 = t31+t40;
    t56 = t32+t41;
    t57 = t32+t42;
    t58 = t27+t43;
    t59 = t27+t45;
    t60 = t28+t44;
    t61 = t28+t47;
    t62 = t29+t46;
    t63 = t29+t48;
    t53 = l_f_+t51;
    t64 = t55.*u22;
    t65 = t54.*u23;
    out3 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-t64-t65+t53.*u24,t55.*u23+t56.*u24+u22.*(t30.*3.0+l_f_.*t8.*t24),l_f_.*u22.*-2.0,t60.*u23+t62.*u24+u22.*(t27+t4.*t7.*t24),t50.*u24+t60.*u22-u23.*(t27-q22.*t9.*t24.*2.0),t52.*u23+t62.*u22-u24.*(t27-q22.*t11.*t24.*2.0),-t54.*u22-t57.*u24-u23.*(t31.*3.0+l_f_.*t10.*t24),t64+t65+t49.*u24,l_f_.*u23.*-2.0,t52.*u24+t58.*u23-u22.*(t28-q23.*t7.*t24.*2.0),t58.*u22+t63.*u24+u23.*(t28+t5.*t9.*t24),t50.*u22+t63.*u23-u24.*(t28-q23.*t11.*t24.*2.0),t53.*u22-t57.*u23-u24.*(t31+q23.*q24.*t2.*t24),t49.*u23+t56.*u22+u24.*(t30+q22.*q24.*t2.*t24),0.0,t50.*u23+t59.*u24-u22.*(t29-q24.*t7.*t24.*2.0),t52.*u22+t61.*u24-u23.*(t29-q24.*t9.*t24.*2.0),t59.*u22+t61.*u23+u24.*(t29+t6.*t11.*t24)],[6,24]);
end
if nargout > 3
    out4 = [g_x_;g_y_;g_z_;0.0;0.0;0.0];
end
