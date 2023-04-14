function [out1,out2,out3,out4,out5,out6,out7] = sprdmpF17(in1,in2,s,ds,t_sym)
%SPRDMPF17
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7] = SPRDMPF17(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    15-Jun-2021 01:20:43

E_s_ = in1(:,2);
gamma_ = in1(:,21);
l_s_ = in1(:,5);
lambda_ = in1(:,34);
mu_xx_ = in1(:,9);
p1_ = in1(:,22);
p2_ = in1(:,23);
p3_ = in1(:,24);
p4_ = in1(:,25);
p5_ = in1(:,26);
p6_ = in1(:,27);
q17 = in2(17,:);
r_o_ = in1(:,20);
r_p1_ = in1(:,19);
r_s1_ = in1(:,3);
r_s2_ = in1(:,4);
u17 = in2(35,:);
out1 = [0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;1.0;0.0];
if nargout > 1
    t2 = cos(gamma_);
    t3 = sin(gamma_);
    t4 = lambda_.^2;
    t5 = r_p1_.^2;
    t7 = 1.0./lambda_;
    t9 = 1.0./sqrt(lambda_);
    t6 = t2.^2;
    t8 = 1.0./t3.^2;
    t10 = t4.*t6;
    t11 = t10-1.0;
    out2 = (E_s_.*q17.*t7.*((pi.*((r_s1_.^4-r_s2_.^4)./t4+t5.^2.*t8.^2.*t11.^2.*6.0))./4.0-r_o_.^2.*t5.*t7.*t8.*t11.*pi.*3.0).*3.0)./l_s_;
end
if nargout > 2
    out3 = -mu_xx_.*u17;
end
if nargout > 3
    out4 = p1_.*r_o_.*t5.*t8.*t9.*t11.*pi.*(-2.71e+2./2.89e+2)-p2_.*r_o_.*t5.*t8.*t9.*t11.*pi.*(2.71e+2./2.89e+2)+p3_.*r_o_.*t5.*t8.*t9.*t11.*pi.*1.67999098695029e-1+p4_.*r_o_.*t5.*t8.*t9.*t11.*pi.*7.697171642807495e-1+p5_.*r_o_.*t5.*t8.*t9.*t11.*pi.*7.697171642807493e-1+p6_.*r_o_.*t5.*t8.*t9.*t11.*pi.*1.679990986950289e-1;
end
if nargout > 4
    out5 = zeros(0,0);
end
if nargout > 5
    out6 = 1.0;
end
if nargout > 6
    out7 = q17;
end
