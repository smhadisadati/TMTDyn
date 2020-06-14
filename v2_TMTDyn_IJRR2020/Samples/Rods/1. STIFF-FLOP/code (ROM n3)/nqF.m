function [out1,out2,out3,out4,out5,out6,out7,out8,out9] = nqF(in1)
%NQF
%    [OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7,OUT8,OUT9] = NQF(IN1)

%    This function was generated by the Symbolic Math Toolbox version 8.2.
%    04-Jan-2019 16:00:51

l_s_sym = in1(:,5);
out1 = 1.8e1;
if nargout > 1
    out2 = 0.0;
end
if nargout > 2
    out3 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
end
if nargout > 3
    out4 = 2.0;
end
if nargout > 4
    out5 = 1.9e1;
end
if nargout > 5
    out6 = 0.0;
end
if nargout > 6
    out7 = 1.0;
end
if nargout > 7
    out8 = [l_s_sym,0.0];
end
if nargout > 8
    out9 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,l_s_sym];
end