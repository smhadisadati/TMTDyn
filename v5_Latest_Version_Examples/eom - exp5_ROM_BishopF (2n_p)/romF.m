function [out1,out2] = romF(in1,in2,s,ds,t_sym)
%ROMF
%    [OUT1,OUT2] = ROMF(IN1,IN2,S,DS,T_SYM)

%    This function was generated by the Symbolic Math Toolbox version 8.6.
%    27-Feb-2021 16:27:16

l_s_ = in1(:,5);
out1 = reshape([0.0,0.0,l_s_,0.0],[2,2]);
if nargout > 1
    out2 = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,l_s_,0.0,0.0,0.0,0.0,0.0,0.0],[6,3]);
end
