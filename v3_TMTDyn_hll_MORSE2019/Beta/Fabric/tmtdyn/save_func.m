function save_func( q , u , lambda , dlambda , s , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , q0 , n_m , n_sd , n_cn , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Dcn , r_jtip , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom )

global par_simpify
par_simpify = par.simplify ;

fprintf( 'save derivations... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% matlabpool('open', 4);
opv = par.opv ;
vars = { par.sym , [ q lambda u dlambda dlambda ] , s } ;
vars_mex = '{ zeros( 1 , numel( par.sym ) ) , zeros( 1 , numel( [ q lambda u dlambda ] ) ) , 0 }' ;

n_m
n_sd
n_cn
n_ex
nq
matlabFunction ( sym(nq) , sym(nlambda) , sym(q0) , sym(n_m) , sym(n_sd) , sym(n_cn) , sym(n_ex) , sym( rom.mass ) , sym( rom.sprdmp ) , ...
    'file' , 'eom/nqF.m' , 'vars' , { par.sym } , 'Optimize' , opv ); % save as matlab function
save_select = [ 3 , 4 , 5 , 6 , 14 , 20 ] ; % dof.s and Animation only

switch par.derive_collect
    case 1 % unified structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction ( sym_simp( mass(i).M ) , sym_simp( mass(i).T ) , sym_simp( mass(i).Dd ) , sym_simp( mass(i).fg ) , ...
                    'file' , sprintf('eom/massF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
%                 matlabFunction ( sym_simp( sprdmp(i).Tt ) , sym_simp( sprdmp(i).kx ) , sym_simp( sprdmp(i).vd ) , sym_simp( sprdmp(i).in ) , sym_simp( sprdmp(i).dl ) , ...
%                     'file' , sprintf('eom/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
                matlabFunction ( sym_simp( sprdmp(i).Tt ) , sym_simp( sprdmp(i).kx ) , sym_simp( sprdmp(i).vd ) , sym_simp( sprdmp(i).in ) , sym_simp( sprdmp(i).dl ) , sym_simp( sprdmp(i).k_mat ) , sym_simp( sprdmp(i).vd_mat ) , sym_simp( sprdmp(i).dir ) , ...
                    'file' , sprintf('eom/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction ( sym_simp( cnst(i).T ) , sym_simp( cnst(i).D ) , sym_simp( cnst(i).in ) , ...
                    'file' , sprintf('eom/cnstF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction ( sym_simp( loads(i).Tt ) , sym_simp( loads(i).ftau ) , ...
                    'file' , sprintf('eom/loadsF%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        
    case 2 % deperate structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction ( sym_simp( mass(i).M ) , 'file' , sprintf('eom/massM%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym_simp( mass(i).T ) , 'file' , sprintf('eom/massT%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym_simp( mass(i).Dd ) , 'file' , sprintf('eom/massDd%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_m
                matlabFunction ( sym_simp( mass(i).fg ) , 'file' , sprintf('eom/massFg%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).Tt ) , 'file' , sprintf('eom/sprdmpTt%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).kx ) , 'file' , sprintf('eom/sprdmpKx%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).vd ) , 'file' , sprintf('eom/sprdmpVd%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).dl ) , 'file' , sprintf('eom/sprdmpDl%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).in ) , 'file' , sprintf('eom/sprdmpIn%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).k_mat ) , 'file' , sprintf('eom/sprdmpKmat%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).vd_mat ) , 'file' , sprintf('eom/sprdmpVdmat%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_sd
                matlabFunction ( sym_simp( sprdmp(i).dir ) , 'file' , sprintf('eom/sprdmpDir%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction ( sym_simp( cnst(i).T ) ,'file' , sprintf('eom/cnstT%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_cn
                matlabFunction ( sym_simp( cnst(i).D ) , 'file' , sprintf('eom/cnstD%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
            parfor i = 1 : n_cn
                matlabFunction ( sym_simp( cnst(i).in ) , 'file' , sprintf('eom/cnstIn%i.m', i) , 'vars' , vars , 'Optimize' , opv );
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction ( sym_simp( loads(i).Tt ) , 'file' , sprintf('eom/loadsTt%i.m', i) , 'vars' , vars , 'Optimize' , opv );
                matlabFunction ( sym_simp( loads(i).ftau ) , 'file' , sprintf('eom/loadsFtau%i.m', i) , 'vars' , vars , 'Optimize' , opv );
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
            matlabFunction ( M , 'file' , 'eom/MF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 2
            matlabFunction ( T , 'file' , 'eom/TF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 3
            matlabFunction ( fj_k , 'file' , 'eom/fj_kF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 4
            matlabFunction ( fj_vd , 'file' , 'eom/fj_vdF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 5
            matlabFunction ( fj_in , 'file' , 'eom/fj_inF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 6
            matlabFunction ( fj_k_mat, 'file' , 'eom/fj_k_matF.m' , 'vars' , vars , 'Optimize' , opv );
            matlabFunction ( fj_vd_mat, 'file' , 'eom/fj_vd_matF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 7
            matlabFunction ( fgv , 'file' , 'eom/fgvF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 8
            matlabFunction ( Dd , 'file' , 'eom/DdF.m' , 'vars' , vars , 'Optimize' , opv );
              
        case 9
            matlabFunction ( ref , 'file' , 'eom/refF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 10
            matlabFunction ( rcn , 'file' , 'eom/rcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 11
            matlabFunction ( Ttef , 'file' , 'eom/TtefF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 12
            matlabFunction ( Tcn , 'file' , 'eom/TcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 13
            matlabFunction ( Dcn , 'file' , 'eom/DcnF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 14
            matlabFunction ( r_jtip , 'file' , 'eom/rjtipF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 15
            matlabFunction ( ftau_ef , 'file' , 'eom/ftau_efF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 16
            matlabFunction ( w_sdi , 'file' , 'eom/w_sdiF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 17
            matlabFunction ( w_k , 'file' , 'eom/w_kF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 18
            matlabFunction ( w_vd , 'file' , 'eom/w_vdF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 19
            matlabFunction ( w_in , 'file' , 'eom/w_inF.m' , 'vars' , vars , 'Optimize' , opv );
              
        case 20
            matlabFunction ( r_ks , 'file' , 'eom/rksF.m' , 'vars' , vars , 'Optimize' , opv );
               
        case 21
            matlabFunction ( k_mat , 'file' , 'eom/k_matF.m' , 'vars' , vars , 'Optimize' , opv );
            matlabFunction ( vd_mat , 'file' , 'eom/vd_matF.m' , 'vars' , vars , 'Optimize' , opv );
            
        case 22
            matlabFunction ( fj_sdi , 'file' , 'eom/fj_sdiF.m' , 'vars' , vars , 'Optimize' , opv );
        
        % C codes
        case 23
            if ~isempty( M )
                ccode ( M , 'file' , 'eom/MF.cpp' );
            end
            
        case 24
            if ~isempty( T )
                ccode ( T , 'file' , 'eom/TF.cpp' );
            end
            
        case 25
            if ~isempty( fj_k )
                ccode ( fj_k , 'file' , 'eom/fj_kF.cpp' );
            end
            
        case 26
            if ~isempty( fj_vd )
                ccode ( fj_vd , 'file' , 'eom/fj_vdF.cpp' );
            end
           
        case 27
            if ~isempty( fj_in )
                ccode ( fj_in , 'file' , 'eom/fj_inF.cpp' );
            end
            
        case 28
            if ~isempty( fj_k_mat )
                ccode ( fj_k_mat , 'file' , 'eom/fj_k_matF.cpp' );
            end
            
        case 29
            if ~isempty( fgv )
                ccode ( fgv , 'file' , 'eom/fgvF.cpp' );
            end
            
        case 30
            if ~isempty( Dd )
                ccode ( Dd , 'file' , 'eom/DdF.cpp' );
            end
            
        case 31
            if ~isempty( ref )
                ccode ( ref , 'file' , 'eom/refF.cpp' );
            end
            
        case 32
            if ~isempty( rcn )
                ccode ( rcn , 'file' , 'eom/rcnF.cpp' );
            end
            
        case 33
            if ~isempty( Ttef )
                ccode ( Ttef , 'file' , 'eom/TtefF.cpp' );
            end
            
        case 34
            if ~isempty( Tcn )
                ccode ( Tcn , 'file' , 'eom/TcnF.cpp' );
            end
            
        case 35
            if ~isempty( Dcn )
                ccode ( Dcn , 'file' , 'eom/DcnF.cpp' );
            end
            
        case 36
            if ~isempty( r_jtip )
                ccode ( r_jtip , 'file' , 'eom/rjtipF.cpp' );
            end
            
        case 37
            if ~isempty( w_sdi )
                ccode ( w_sdi , 'file' , 'eom/w_sdiF.cpp' );
            end
            
        case 38
            if ~isempty( w_k )
                ccode ( w_k , 'file' , 'eom/w_kF.cpp' );
            end
            
        case 39
            if ~isempty( w_vd )
                ccode ( w_vd , 'file' , 'eom/w_vdF.cpp' );
            end
            
        case 40
            if ~isempty( w_in )
                ccode ( w_in , 'file' , 'eom/w_inF.cpp' );
            end
            
        case 41
            if ~isempty( r_ks )
                ccode ( r_ks , 'file' , 'eom/rksF.cpp' );
            end

        case 42
            if ~isempty( k_mat )
                ccode ( k_mat , 'file' , 'eom/k_matF.cpp' );
            end
            
        case 43
            if ~isempty( fj_sdi )
                ccode ( fj_sdi , 'file' , 'eom/fj_sdiF.cpp' );
            end
            
    end    
end


save_mex( q , u , lambda , dlambda , s , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , q0 , n_m , n_sd , n_cn , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Dcn , r_jtip , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom ) ;


function out = sym_simp( in )
global par_simpify

if par_simpify
    out = simplify( sym( in ) ) ;
else
    out = sym( in ) ;
end


