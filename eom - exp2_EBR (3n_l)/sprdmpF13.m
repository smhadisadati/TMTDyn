function [out1,out2,out3,out4,out5,out6,out7] = sprdmpF13(in1,in2,s,ds,t_sym)
%SPRDMPF13
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF13(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    14-Jun-2021 23:15:55

E_s_ = in1(:,2);
gamma_ = in1(:,21);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
mu_x_ = in1(:,6);
q13 = in2(13,:);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
u13 = in2(31,:);
out1 = [0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;1.0;0.0;0.0;0.0;0.0;0.0];
if nargout > 1
    t2 = 1.0./lambda_;
    out2 = (E_s_.*q13.*t2.*pi.*(t2.*(r_s1_.^2-r_s2_.^2)-r_p1_.^2.*1.0./sin(gamma_).^2.*(1.0./t2.^2.*cos(gamma_).^2-1.0).*6.0))./l_s_;
end
if nargout > 2
    out3 = -mu_x_.*u13;
end
if nargout > 3
    out4 = 0.0;
end
if nargout > 4
    out5 = zeros(0,0);
end
if nargout > 5
    out6 = 1.0;
end
if nargout > 6
    out7 = q13;
end
