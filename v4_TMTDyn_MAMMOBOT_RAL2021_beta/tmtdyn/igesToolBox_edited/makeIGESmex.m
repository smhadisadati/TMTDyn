function makeIGESmex()
% Makefile
% run
% >> makeIGESmex
% in MATLAB to compile the source code in the IGES-toolbox
%
% Remark! The compilation might take a couple of minutes

listing = dir('*.c');

for i=1:length(listing)
    try
        mex(listing(i).name)
    end
end
