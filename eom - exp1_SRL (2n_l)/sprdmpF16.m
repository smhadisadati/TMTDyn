function [out1,out2,out3,out4,out5,out6,out7] = sprdmpF16(in1,in2,s,ds,t_sym)
%SPRDMPF16
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF16(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    15-Jun-2021 01:20:43

E_s_ = in1(:,2);
gamma_ = in1(:,21);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
mu_zz_ = in1(:,11);
q16 = in2(16,:);
r_o_ = in1(:,20);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
u16 = in2(34,:);
out1 = [0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;1.0;0.0;0.0];
if nargout > 1
    t2 = cos(gamma_);
    t3 = sin(gamma_);
    t4 = lambda_.^2;
    t5 = t2.^2;
    t6 = t4.*t5;
    t7 = t6-1.0;
    out2 = (E_s_.*q16.*((pi.*((r_s1_.^4-r_s2_.^4)./t4+r_p1_.^4.*1.0./t3.^4.*t7.^2.*6.0))./2.0-lambda_.*r_o_.^2.*r_p1_.^2.*1.0./t3.^2.*t7.*pi))./(l_s_.*lambda_);
end
if nargout > 2
    out3 = -mu_zz_.*u16;
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
    out7 = q16;
end