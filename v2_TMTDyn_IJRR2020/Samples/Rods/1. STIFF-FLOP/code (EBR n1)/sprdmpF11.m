function [out1,out2,out3,out4,out5,out6,out7,out8] = sprdmpF11(in1,in2,s)
%SPRDMPF11
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF11(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    05-Jan-2019 22:38:44

E_s_sym = in1(:,2);
gamma_sym = in1(:,21);
l_s_sym = in1(:,5);
lambda_sym = in1(:,34);
mu_xx_sym = in1(:,9);
mu_pow_sym = in1(:,12);
p1_sym = in1(:,22);
p2_sym = in1(:,23);
p3_sym = in1(:,24);
p4_sym = in1(:,25);
p5_sym = in1(:,26);
p6_sym = in1(:,27);
q11 = in2(:,11);
r_o_sym = in1(:,20);
r_p1_sym = in1(:,19);
r_s1_sym = in1(:,3);
r_s2_sym = in1(:,4);
u11 = in2(:,23);
out1 = [0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;0.0;1.0;0.0];
if nargout > 1
    out2 = (E_s_sym.*q11.*((pi.*(1.0./lambda_sym.^2.*(r_s1_sym.^4-r_s2_sym.^4)+r_p1_sym.^4.*1.0./sin(gamma_sym).^4.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).^2.*6.0))./4.0-(r_o_sym.^2.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*3.0)./lambda_sym).*2.0)./(l_s_sym.*lambda_sym);
end
if nargout > 2
    out3 = -mu_xx_sym.*u11.*abs(u11).^(mu_pow_sym-1.0);
end
if nargout > 3
    out4 = 1.0./sqrt(lambda_sym).*p1_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*(-2.71e2./2.89e2)-1.0./sqrt(lambda_sym).*p2_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*(2.71e2./2.89e2)+1.0./sqrt(lambda_sym).*p3_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*1.67999098695029e-1+1.0./sqrt(lambda_sym).*p4_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*7.697171642807495e-1+1.0./sqrt(lambda_sym).*p5_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*7.697171642807493e-1+1.0./sqrt(lambda_sym).*p6_sym.*r_o_sym.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*1.679990986950289e-1;
end
if nargout > 4
    out5 = q11;
end
if nargout > 5
    out6 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,(E_s_sym.*((pi.*(1.0./lambda_sym.^2.*(r_s1_sym.^4-r_s2_sym.^4)+r_p1_sym.^4.*1.0./sin(gamma_sym).^4.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).^2.*6.0))./4.0-(r_o_sym.^2.*r_p1_sym.^2.*pi.*1.0./sin(gamma_sym).^2.*(lambda_sym.^2.*cos(gamma_sym).^2-1.0).*3.0)./lambda_sym).*-2.0)./(l_s_sym.*lambda_sym),0.0];
end
if nargout > 6
    out7 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-mu_xx_sym.*u11.^(mu_pow_sym-1.0),0.0];
end
if nargout > 7
    out8 = 1.0;
end
