function [out1,out2,out3,out4,out5,out6,out7,out8] = sprdmpF130(in1,in2,s)
%SPRDMPF130
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF130(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    06-Jul-2019 08:43:45

q99 = in2(:,99);
q100 = in2(:,100);
q101 = in2(:,101);
q106 = in2(:,106);
t3 = q106./2.0;
t2 = cos(t3);
t4 = sin(t3);
t5 = t2.^2;
t6 = t4.^2;
t7 = t2.*t4.*2.0;
t8 = t5-t6;
t9 = t2.*(3.0./1.0e2);
t10 = t4.*(1.9e1./5.0e2);
t11 = t9+t10;
t12 = t2.*(1.9e1./5.0e2);
t13 = t4.*(3.0./1.0e2);
t14 = t12-t13;
t15 = t2.*(1.9e1./1.0e3);
t16 = t4.*(3.0./2.0e2);
t17 = t15-t16;
t18 = t2.*(3.0./2.0e2);
t19 = t4.*(1.9e1./1.0e3);
t20 = t18+t19;
t21 = (t4.*t11)./2.0;
t22 = t4.*t20;
t35 = (t2.*t14)./2.0;
t36 = t2.*t17;
t23 = t21+t22-t35-t36;
t24 = t4.*t11;
t34 = t2.*t14;
t25 = q99+t24-t34;
t26 = (t2.*t11)./2.0;
t27 = t2.*t20;
t28 = (t4.*t14)./2.0;
t29 = t4.*t17;
t30 = t26+t27+t28+t29;
t31 = t2.*t11;
t32 = t4.*t14;
t33 = q101+t31+t32;
t37 = t2.*t23;
t38 = (t4.*t33)./2.0;
t39 = t37+t38-(t2.*t25)./2.0-t4.*t30;
t40 = t2.*t30;
t41 = t4.*t23;
t42 = t2.*t25;
t43 = t42-t4.*t33;
t44 = t2.*t33;
t45 = t4.*t25;
t46 = t44+t45;
out1 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t8,0.0,-t7,0.0,0.0,0.0,0.0,t4.*t39-(t4.*t43)./2.0-(t2.*t46)./2.0+t2.*(t40+t41-(t4.*t25)./2.0-(t2.*t33)./2.0),0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t5+t6,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t7,0.0,t8,0.0,0.0,0.0,0.0,-t2.*t39+(t2.*t43)./2.0-(t4.*t46)./2.0+t4.*(t40+t41-(t4.*t25)./2.0-(t2.*t33)./2.0)],[106,3]);
if nargout > 1
    t47 = [0.0;0.0;0.0];
    out2 = t47;
end
if nargout > 2
    out3 = t47;
end
if nargout > 3
    out4 = t47;
end
if nargout > 4
    out5 = sqrt(q100.^2+t25.^2+t33.^2);
end
if nargout > 5
    t48 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[3,106]);
    out6 = t48;
end
if nargout > 6
    out7 = t48;
end
if nargout > 7
    out8 = 1.0;
end