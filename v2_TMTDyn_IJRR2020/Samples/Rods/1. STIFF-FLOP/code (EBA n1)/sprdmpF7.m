function [out1,out2,out3,out4,out5,out6,out7,out8] = sprdmpF7(in1,in2,s)
%SPRDMPF7
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8] = SPRDMPF7(IN1,IN2,S)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    15-May-2019 14:15:55

lambda_sym = in1(:,34);
p1_sym = in1(:,22);
p3_sym = in1(:,24);
p5_sym = in1(:,26);
q1 = in2(:,1);
q2 = in2(:,2);
q3 = in2(:,3);
q4 = in2(:,4);
q5 = in2(:,5);
q6 = in2(:,6);
u1 = in2(:,7);
u2 = in2(:,8);
u3 = in2(:,9);
u4 = in2(:,10);
u5 = in2(:,11);
u6 = in2(:,12);
out1 = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,2.0,0.0,0.0,0.0,0.0,0.0,0.0,2.0,0.0,0.0,0.0,0.0,0.0,0.0,2.0],[6,6]);
if nargout > 1
    t2 = 1.0./lambda_sym;
    t3 = t2.*1.36e-4;
    t4 = lambda_sym.^2;
    t5 = t4.*1.672238728974578e-7;
    t6 = t3+t5-3.766722387289746e-5;
    t8 = t4.*4.439506172839557e-3;
    t7 = t8-1.0;
    t9 = t7.^2;
    t10 = t9.*2.36469959048496e-10;
    t11 = 1.0./lambda_sym.^2;
    t16 = t11.*2.4004e-8;
    t12 = t10-t16;
    t13 = t12.*pi.*1.025e6;
    t14 = t4.*2.787064548290963e-8;
    t15 = t14-6.277870645482909e-6;
    t17 = 1.0./sqrt(lambda_sym);
    t18 = t2.*t6.*pi.*1.366666666666667e6;
    t19 = t13-t2.*t15.*pi.*8.886750000000001e2;
    t20 = t13-t2.*t15.*pi.*8.886749999999999e2;
    out2 = [q1.*t2.*t6.*pi.*(-1.366666666666667e6);q2.*t2.*t6.*pi.*(-1.366666666666667e6);t2.*t6.*pi.*(q3-1.0./2.0e1).*-4.1e6;q4.*t2.*t19.*2.0;q5.*t2.*t20.*2.0;q6.*t2.*t12.*pi.*1.366666666666667e6];
end
if nargout > 2
    t21 = abs(u1);
    t22 = abs(u2);
    t23 = abs(u3);
    t24 = abs(u4);
    t25 = abs(u5);
    t26 = abs(u6);
    out3 = [t21.*u1.*-1.0e2;t22.*u2.*-1.0e2;t23.*u3.*-1.0e2;t24.*u4.*(-1.0./2.5e1);t25.*u5.*(-1.0./2.5e1);t26.*u6.*(-1.0./2.5e1)];
end
if nargout > 3
    out4 = [0.0;0.0;-t15.*pi.*(p1_sym.*2.0+p3_sym.*2.0+p5_sym.*2.0);p1_sym.*t15.*t17.*pi.*(-1.594117647058824e-2)+p3_sym.*t15.*t17.*pi.*7.970588235294118e-3+p5_sym.*t15.*t17.*pi.*7.970588235294115e-3;p1_sym.*t15.*t17.*pi.*1.301042606982605e-18+p3_sym.*t15.*t17.*pi.*1.380546378974017e-2-p5_sym.*t15.*t17.*pi.*1.380546378974017e-2;0.0];
end
if nargout > 4
    out5 = sqrt(q1.^2+q2.^2+q3.^2)-1.0./2.0e1;
end
if nargout > 5
    out6 = reshape([t18,0.0,0.0,0.0,0.0,0.0,0.0,t18,0.0,0.0,0.0,0.0,0.0,0.0,t2.*t6.*pi.*4.1e6,0.0,0.0,0.0,0.0,0.0,0.0,t2.*t19.*-2.0,0.0,0.0,0.0,0.0,0.0,0.0,t2.*t20.*-2.0,0.0,0.0,0.0,0.0,0.0,0.0,t2.*t12.*pi.*(-1.366666666666667e6)],[6,6]);
end
if nargout > 6
    out7 = reshape([t21.*-1.0e2,0.0,0.0,0.0,0.0,0.0,0.0,t22.*-1.0e2,0.0,0.0,0.0,0.0,0.0,0.0,t23.*-1.0e2,0.0,0.0,0.0,0.0,0.0,0.0,t24.*(-1.0./2.5e1),0.0,0.0,0.0,0.0,0.0,0.0,t25.*(-1.0./2.5e1),0.0,0.0,0.0,0.0,0.0,0.0,t26.*(-1.0./2.5e1)],[6,6]);
end
if nargout > 7
    out8 = 1.0;
end
