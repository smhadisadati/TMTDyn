function Ptrs=findEntityIGES(ParameterData,entityTypeNumber,flag,entityTypeNumber2)
% findEntityIGES finds indices in ParameterData with
% a given entity type number
%
% Usage:
%
% Ptrs=findEntityIGES(ParameterData,entityTypeNumber)
%
% Input:
%
% ParameterData - Parameter data from IGES file. ParameterData
%                 is the output from IGES2MATLAB.
% entityTypeNumber - Given entity type number
%
% Output:
%
% Ptrs - Vector with indices in ParameterData having the given entity type number
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2012-01-05
%

Ptrs=[];

if not(iscell(ParameterData))
    error('ParameterData must be a cell array!');
end

siz=length(ParameterData);

if nargin==2
    for i=1:siz
        if ParameterData{i}.type==entityTypeNumber
            Ptrs=[Ptrs,i];
        end
    end
else
    if entityTypeNumber==144
        if flag==1
            for i=1:siz
                if ParameterData{i}.type==entityTypeNumber
                    if ParameterData{ParameterData{i}.pts}.type==entityTypeNumber2
                        Ptrs=[Ptrs,i];
                    end
                end
            end
        elseif flag==2
            for i=1:siz
                if ParameterData{i}.type==entityTypeNumber
                    if and(ParameterData{ParameterData{i}.pts}.type==entityTypeNumber2,ParameterData{i}.n2>0)
                        Ptrs=[Ptrs,i];
                    end
                end
            end
        elseif flag==3
            for i=1:siz
                if ParameterData{i}.type==entityTypeNumber
                    try
                        if ParameterData{i}.pto==entityTypeNumber2
                            Ptrs=[Ptrs,i];
                        end
                    end
                end
            end
        elseif flag==4
            for i=1:siz
                if ParameterData{i}.type==entityTypeNumber
                    if not(ParameterData{i}.original)
                        Ptrs=[Ptrs,i];
                    end
                end
            end            
        end            
    end
end
