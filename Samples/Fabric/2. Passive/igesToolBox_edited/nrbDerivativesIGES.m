function [dnurbs,d2nurbs] = nrbDerivativesIGES(nurbs)
% Returns the derivative(s) of NURBS
% Use nrbevalIGES for evaluations
%
% Usage:
% dnurbs = nrbDerivativesIGES(nurbs)
% [dnurbs,d2nurbs] = nrbDerivativesIGES(nurbs)
%
% Input:
% nurbs - NURBS object
%
% Output:
% dnurbs,d2nurbs - NURBS derivatives
%
% m-file can be downloaded at
% http://www.mathworks.com/matlabcentral/fileexchange/13253-iges-toolbox
%
% written by Per Bergström 2009-12-04
%


if length(nurbs.order)==2

    dnurbs=cell(1,2);

    dnurbs{1}.form='B-NURBS';
    dnurbs{1}.dim=4;
    dnurbs{1}.number=[(nurbs.number(1)-1),nurbs.number(2)];
    if nurbs.order(1)>1
        % Do the derivation
        reshkn1=nurbs.knots{1}((1+nurbs.order(1)):(nurbs.number(1)+nurbs.order(1)-1))-nurbs.knots{1}(2:nurbs.number(1));
        reshkn1(abs(reshkn1)<1e-10)=Inf;
        dnurbs{1}.coefs=(nurbs.order(1)-1)*(nurbs.coefs(:,2:nurbs.number(1),:)-nurbs.coefs(:,1:(nurbs.number(1)-1),:))./repmat(reshkn1,[4,1,nurbs.number(2)]);
        dnurbs{1}.knots={nurbs.knots{1}(2:(end-1)) nurbs.knots{2}};
    else
        % Do not do the derivation
        dnurbs{1}.coefs=nurbs.coefs;
        dnurbs{1}.knots=nurbs.knots;
    end
    dnurbs{1}.order=[(nurbs.order(1)-1) nurbs.order(2)];

    dnurbs{2}.form='B-NURBS';
    dnurbs{2}.dim=4;
    dnurbs{2}.number=[nurbs.number(1),(nurbs.number(2)-1)];

    if nurbs.order(2)>1
        % Do the derivation
        dcoefsv=zeros(4,nurbs.number(1),nurbs.number(2)-1);
        reshkn2=reshape(nurbs.knots{2}((1+nurbs.order(2)):(nurbs.number(2)+nurbs.order(2)-1))-nurbs.knots{2}(2:nurbs.number(2)),[1,1,(nurbs.number(2)-1)]);
        reshkn2(abs(reshkn2)<1e-10)=Inf;
        for ii=1:4
            for jj=1:nurbs.number(1)
                dcoefsv(ii,jj,:)=(nurbs.order(2)-1)*(nurbs.coefs(ii,jj,2:nurbs.number(2))-nurbs.coefs(ii,jj,1:(nurbs.number(2)-1)))./reshkn2;
            end
        end

        dnurbs{2}.coefs=dcoefsv;
        dnurbs{2}.knots={nurbs.knots{1} nurbs.knots{2}(2:(end-1))};
    else
        % Do not do the derivation
        dnurbs{2}.coefs=nurbs.coefs;
        dnurbs{2}.knots=nurbs.knots;
    end
    dnurbs{2}.order=[nurbs.order(1) (nurbs.order(2)-1)];

    if nargout==2

        d2nurbs11_12 = nrbDerivativesIGES(dnurbs{1});
        d2nurbs21_22 = nrbDerivativesIGES(dnurbs{2});

        d2nurbs=cell(1,3);

        d2nurbs{1}=d2nurbs11_12{1};
        d2nurbs{2}=d2nurbs11_12{2};
        d2nurbs{3}=d2nurbs21_22{2};

        %reduce roundoff error

        d2nurbs{2}.coefs=0.5*(d2nurbs11_12{2}.coefs+d2nurbs21_22{1}.coefs);

    end

elseif length(nurbs.order)==1

    dnurbs.form='B-NURBS';
    dnurbs.dim=4;
    dnurbs.number=(nurbs.number-1);
    if nurbs.order>1
        % Do the derivation
        reshkn1=nurbs.knots((1+nurbs.order):(nurbs.number+nurbs.order-1))-nurbs.knots(2:nurbs.number);
        reshkn1(abs(reshkn1)<1e-10)=Inf;        
        dnurbs.coefs=(nurbs.order-1)*(nurbs.coefs(:,2:nurbs.number,:)-nurbs.coefs(:,1:(nurbs.number-1),:))./repmat(reshkn1,[4,1]);
        dnurbs.knots=nurbs.knots(2:(end-1));
    else
        % Do not do the derivation
        dnurbs.coefs=nurbs.coefs;
        dnurbs.knots=nurbs.knots;
    end
    dnurbs.order=(nurbs.order-1);

    if nargout==2
        d2nurbs=nrbDerivativesIGES(dnurbs);
    end

end
