function out1 = fj_vdF(in1,in2,s,ds,t_sym)
%FJ_VDF
%    OUT1 = FJ_VDF(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    26-Feb-2021 18:56:22

mu_x_ = in1(:,6);
mu_y_ = in1(:,7);
mu_z_ = in1(:,8);
mu_xx_ = in1(:,9);
mu_yy_ = in1(:,10);
mu_zz_ = in1(:,11);
mu_pow_ = in1(:,12);
u1 = in2(13,:);
u2 = in2(14,:);
u3 = in2(15,:);
u4 = in2(16,:);
u5 = in2(17,:);
u6 = in2(18,:);
u7 = in2(19,:);
u8 = in2(20,:);
u9 = in2(21,:);
u10 = in2(22,:);
u11 = in2(23,:);
u12 = in2(24,:);
t2 = mu_pow_-1.0;
out1 = [-mu_x_.*u1.*abs(u1).^t2;-mu_y_.*u2.*abs(u2).^t2;-mu_z_.*u3.*abs(u3).^t2;-mu_zz_.*u4.*abs(u4).^t2;-mu_xx_.*u5.*abs(u5).^t2;-mu_yy_.*u6.*abs(u6).^t2;-mu_x_.*u7.*abs(u7).^t2;-mu_y_.*u8.*abs(u8).^t2;-mu_z_.*u9.*abs(u9).^t2;-mu_zz_.*u10.*abs(u10).^t2;-mu_xx_.*u11.*abs(u11).^t2;-mu_yy_.*u12.*abs(u12).^t2];