function save_report( q , u , lambda , s , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , q0 , n_m , n_sd , n_cn , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Dcn , r_jtip , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom )
fprintf( 'save derivations... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% matlabpool('open', 4);
opv = par.opv ;
vars = { par.sym , [ q lambda u ] , s } ;
vars_mex = '{ zeros( 1 , numel( par.sym ) ) , zeros( 1 , numel( [ q lambda u ] ) ) , 0 }' ;

n_m
n_sd
n_cn
n_ex
nq
matlabFunction ( sym(nq) , sym(nlambda) , sym(q0) , sym(n_m) , sym(n_sd) , sym(n_cn) , sym(n_ex) , sym( rom.mass ) , sym( rom.sprdmp ) , ...
    'file' , 'code/nqF.m' , 'vars' , { par.sym } , 'Optimize' , opv ); % save as matlab function
save_select = [ 3 , 4 , 5 , 6 , 14 , 20 ] ; % dof.s and Animation only

switch par.derive_collect
    case 1 % unified structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction ( sym( mass(i).M ) , sym( mass(i).T ) , sym( mass(i).Dd ) , sym( mass(i).fg ) , ...
                    'file' , sprintf('code/massF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).Tt ) , sym( sprdmp(i).kx ) , sym( sprdmp(i).vd ) , sym( sprdmp(i).in ) , sym( sprdmp(i).dl ) , ...
                    'file' , sprintf('code/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
%                 matlabFunction ( sym( sprdmp(i).Tt ) , sym( sprdmp(i).kx ) , sym( sprdmp(i).vd ) , sym( sprdmp(i).in ) , sym( sprdmp(i).dl ) , sym( sprdmp(i).k_mat ) , sym( sprdmp(i).vd_mat ) , sym( sprdmp(i).dir ) , ...
%                     'file' , sprintf('code/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction ( sym( cnst(i).r ) , sym( cnst(i).T ) , sym( cnst(i).D ) , ...
                    'file' , sprintf('code/cnstF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction ( sym( loads(i).Tt ) , sym( loads(i).ftau ) , ...
                    'file' , sprintf('code/loadsF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        
    case 2 % deperate structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction ( sym( mass(i).M ) , 'file' , sprintf('code/massM%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym( mass(i).T ) , 'file' , sprintf('code/massT%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym( mass(i).Dd ) , 'file' , sprintf('code/massDd%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym( mass(i).fg ) , 'file' , sprintf('code/massFg%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).Tt ) , 'file' , sprintf('code/sprdmpTt%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).kx ) , 'file' , sprintf('code/sprdmpKx%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).vd ) , 'file' , sprintf('code/sprdmpVd%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).dl ) , 'file' , sprintf('code/sprdmpDl%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).in ) , 'file' , sprintf('code/sprdmpIn%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
%             parfor i = 1 : n_sd
%                 matlabFunction ( sym( sprdmp(i).k_mat ) , 'file' , sprintf('code/sprdmpKmat%i.m', i) , 'vars' , vars , 'Optimize' , opv );
%             end
%             parfor i = 1 : n_sd
%                 matlabFunction ( sym( sprdmp(i).vd_mat ) , 'file' , sprintf('code/sprdmpVdmat%i.m', i) , 'vars' , vars , 'Optimize' , opv );
%             end
            parfor i = 1 : n_sd
                matlabFunction ( sym( sprdmp(i).dir ) , 'file' , sprintf('code/sprdmpDir%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction ( sym( cnst(i).r ) ,'file' , sprintf('code/cnstT%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_cn
                matlabFunction ( sym( cnst(i).T ) ,'file' , sprintf('code/cnstT%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_cn
                matlabFunction ( sym( cnst(i).D ) , 'file' , sprintf('code/cnstD%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction ( sym( loads(i).Tt ) , 'file' , sprintf('code/loadsTt%i.m', i) , 'vars' , vars , 'Optimize' , opv );
                matlabFunction ( sym( loads(i).ftau ) , 'file' , sprintf('code/loadsFtau%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        
    case 3 % collect for Matlab
        save_select = 1 : 22 ; % matlab func.s
%         save_select = 1 : 43 ; % all
        
    case 4 % collect for Matlab & C
        save_select = 1 : 43 ; % all
        
end

parfor i = 1 : numel( save_select )
    switch save_select(i)
        % matlab functions
        case 1
            matlabFunction ( M , 'file' , 'code/MF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 2
            matlabFunction ( T , 'file' , 'code/TF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 3
            matlabFunction ( fj_k , 'file' , 'code/fj_kF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 4
            matlabFunction ( fj_vd , 'file' , 'code/fj_vdF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 5
            matlabFunction ( fj_in , 'file' , 'code/fj_inF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 6
%             matlabFunction ( fj_k_mat, 'file' , 'code/fj_k_matF.m' , 'vars' , vars , 'Optimize' , opv );
%             matlabFunction ( fj_vd_mat, 'file' , 'code/fj_vd_matF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 7
            matlabFunction ( fgv , 'file' , 'code/fgvF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 8
            matlabFunction ( Dd , 'file' , 'code/DdF.m' , 'vars' , vars , 'Optimize' , opv );
              
        case 9
            matlabFunction ( ref , 'file' , 'code/refF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 10
            matlabFunction ( rcn , 'file' , 'code/rcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 11
            matlabFunction ( Ttef , 'file' , 'code/TtefF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 12
            matlabFunction ( Tcn , 'file' , 'code/TcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 13
            matlabFunction ( Dcn , 'file' , 'code/DcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 14
            matlabFunction ( r_jtip , 'file' , 'code/rjtipF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 15
            matlabFunction ( ftau_ef , 'file' , 'code/ftau_efF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 16
            matlabFunction ( w_sdi , 'file' , 'code/w_sdiF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 17
            matlabFunction ( w_k , 'file' , 'code/w_kF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 18
            matlabFunction ( w_vd , 'file' , 'code/w_vdF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 19
            matlabFunction ( w_in , 'file' , 'code/w_inF.m' , 'vars' , vars , 'Optimize' , opv );
              
        case 20
            matlabFunction ( r_ks , 'file' , 'code/rksF.m' , 'vars' , vars , 'Optimize' , opv );
               
        case 21
%             matlabFunction ( k_mat , 'file' , 'code/k_matF.m' , 'vars' , vars , 'Optimize' , opv );
%             matlabFunction ( vd_mat , 'file' , 'code/vd_matF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 22
            matlabFunction ( fj_sdi , 'file' , 'code/fj_sdiF.m' , 'vars' , vars , 'Optimize' , opv );
        
        % C codes
        case 23
            if ~isempty( M )
                ccode ( M , 'file' , 'code/MF.cpp' );
            end
            
        case 24
            if ~isempty( T )
                ccode ( T , 'file' , 'code/TF.cpp' );
            end
            
        case 25
            if ~isempty( fj_k )
                ccode ( fj_k , 'file' , 'code/fj_kF.cpp' );
            end
            
        case 26
            if ~isempty( fj_vd )
                ccode ( fj_vd , 'file' , 'code/fj_vdF.cpp' );
            end
           
        case 27
            if ~isempty( fj_in )
                ccode ( fj_in , 'file' , 'code/fj_inF.cpp' );
            end
            
        case 28
%             if ~isempty( fj_k_mat )
%                 ccode ( fj_k_mat , 'file' , 'code/fj_k_matF.cpp' );
%             end
            
        case 29
            if ~isempty( fgv )
                ccode ( fgv , 'file' , 'code/fgvF.cpp' );
            end
            
        case 30
            if ~isempty( Dd )
                ccode ( Dd , 'file' , 'code/DdF.cpp' );
            end
            
        case 31
            if ~isempty( ref )
                ccode ( ref , 'file' , 'code/refF.cpp' );
            end
            
        case 32
            if ~isempty( rcn )
                ccode ( rcn , 'file' , 'code/rcnF.cpp' );
            end
            
        case 33
            if ~isempty( Ttef )
                ccode ( Ttef , 'file' , 'code/TtefF.cpp' );
            end
            
        case 34
            if ~isempty( Tcn )
                ccode ( Tcn , 'file' , 'code/TcnF.cpp' );
            end
            
        case 35
            if ~isempty( Dcn )
                ccode ( Dcn , 'file' , 'code/DcnF.cpp' );
            end
            
        case 36
            if ~isempty( r_jtip )
                ccode ( r_jtip , 'file' , 'code/rjtipF.cpp' );
            end
            
        case 37
            if ~isempty( w_sdi )
                ccode ( w_sdi , 'file' , 'code/w_sdiF.cpp' );
            end
            
        case 38
            if ~isempty( w_k )
                ccode ( w_k , 'file' , 'code/w_kF.cpp' );
            end
            
        case 39
            if ~isempty( w_vd )
                ccode ( w_vd , 'file' , 'code/w_vdF.cpp' );
            end
            
        case 40
            if ~isempty( w_in )
                ccode ( w_in , 'file' , 'code/w_inF.cpp' );
            end
            
        case 41
            if ~isempty( r_ks )
                ccode ( r_ks , 'file' , 'code/rksF.cpp' );
            end

        case 42
%             if ~isempty( k_mat )
%                 ccode ( k_mat , 'file' , 'code/k_matF.cpp' );
%             end
            
        case 43
            if ~isempty( fj_sdi )
                ccode ( fj_sdi , 'file' , 'code/fj_sdiF.cpp' );
            end
            
    end    
end


if par.derive_mex
    save_mex( q , u , lambda , s , par , ...
        mass , sprdmp , cnst , loads , ...
        nq , nlambda , q0 , n_m , n_sd , n_cn , n_ex , ...
        M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , ...
        fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Dcn , r_jtip , w_sdi , ...
        w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom ) ;
end
