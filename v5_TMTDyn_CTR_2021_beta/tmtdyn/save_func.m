function save_func( q , u , lambda , dlambda , gamma , dgamma , s , ds , sw , t_sym , par , ...
    mass , sprdmp , cnst , loads , ...
    nq , nlambda , ngamma , q0 , n_m , n_sd , n_cn , n_co , n_ex , ...
    M , T , fj_k , fj_vd , fj_in , fj_sdi , fj_k_mat , fj_vd_mat , Tj_u , ...
    fgv , Dd , ref , rcn , Ttef , ftau_ef , Tcn , Tcu , Dcn , r_jtips , w_sdi , ...
    w_k , w_vd , w_k_mat , w_vd_mat , w_in , r_ks , k_mat , vd_mat , rom )

global par_simplify pw2lg
par_simplify = par.simplify ;
pw2lg = par.pw2lg ; % piecewise to logistic function for simpler derivations

fprintf( 'save derivations... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

if par.clean && par.cores ~= 1 % in case of limited memory use only 1 core, unless specified otherwise
    par.cores = 1 ;
end

delete(gcp('nocreate'));
myCluster = parcluster('local');
delete(myCluster.Jobs);
if par.cores ~= 0 % otherwise run on all cores by default
    parpool(par.cores);
end

opv = par.opv ;
% sprs = par.sparse ;
sprs = 0 ;
vars = { par.sym , [ q lambda gamma u dlambda dgamma ].' , s , ds , t_sym } ;
vars_mex = '{ zeros( 1 , numel( par.sym ) ) , zeros( 2*numel( [ q lambda gamma ] ) , 1 ) , 0 , 0 , 0 }' ;

n_m
n_sd
n_cn
n_ex
nq
matlabFunction( subs( sym(nq), sw, s) , subs( sym(nlambda), sw, s) , subs( sym(ngamma), sw, s) , subs( sym(q0), sw, s) , subs( sym(n_m), sw, s) , subs( sym(n_sd), sw, s) , subs( sym(n_cn), sw, s) , subs( sym(n_co), sw, s) , subs( sym(n_ex), sw, s ) , ...
    'file' , 'eom/nqF.m' , 'vars' , { par.sym } , 'Optimize' , opv , 'Sparse' , sprs ); % save as matlab function
matlabFunction(  subs( sym( rom.mass ), sw, s) , subs( sym( rom.sprdmp ), sw, s) , ...
    'file' , 'eom/romF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs ); % save as matlab function
save_select = [ 3 , 4 , 5 , 6 , 14 , 20 ] ; % dof.s and Animation only

switch par.derive_collect
    case 1 % unified structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).M ) ), sw, s) , subs( sym( piecewise2logistic( mass(i).T ) ), sw, s) , subs( sym( piecewise2logistic( mass(i).Dd ) ), sw, s) , subs( sym( piecewise2logistic( mass(i).fg ) ), sw, s ) , ...
                    'file' , sprintf('eom/massF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).M = []; mass(i).T = []; mass(i).Dd = []; mass(i).fg = []; 
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).Tt ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).kx ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).vd ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).in ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).Tt_u ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).dir ) ), sw, s ) , subs( sym( piecewise2logistic( sprdmp(i).dl ) ), sw, s) , ...
                    'file' , sprintf('eom/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv ,'Sparse' , sprs );
%                 matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).Tt ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).kx ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).vd ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).in ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).Tt_u ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).dir ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).dl ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).k_mat ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).vd_mat ) ) ) , ...
%                     'file' , sprintf('eom/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv ,'Sparse' , sprs );
                sprdmp(i).Tt = []; sprdmp(i).kx = []; sprdmp(i).vd = []; sprdmp(i).in = []; sprdmp(i).Tt_u = []; sprdmp(i).dir = []; sprdmp(i).dl = []; sprdmp(i).k_mat = []; sprdmp(i).vd_mat = []; 
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).T ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).Tt ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).D ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).in ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).r ) ), sw, s ) , ...
                    'file' , sprintf('eom/cnstF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).T = []; cnst(i).Tt = []; cnst(i).D = []; cnst(i).in = []; cnst(i).r = [];
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction( subs( sym( piecewise2logistic( loads(i).Tt ) ), sw, s) , subs( sym( piecewise2logistic( loads(i).ftau ) ), sw, s) , subs( sym( piecewise2logistic( loads(i).Tt_o ) ), sw, s) , ...
                    'file' , sprintf('eom/loadsF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                loads(i).Tt = []; loads(i).ftau = []; loads(i).Tt_o = []; 
            end
        end
        
    case 2 % separate structures
        
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).M ) ), sw, s) , 'file' , sprintf('eom/massM%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).M = [];
            end
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).T ) ), sw, s) , 'file' , sprintf('eom/massT%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).T = [];
            end
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).Dd ) ), sw, s) , 'file' , sprintf('eom/massDd%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).Dd = [];
            end
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).fg ) ), sw, s) , 'file' , sprintf('eom/massFg%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).fg = [];
            end
        end
                
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).Tt ) ), sw, s) , 'file' , sprintf('eom/sprdmpTt%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).Tt = [];
            end
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).kx ) ), sw, s) , 'file' , sprintf('eom/sprdmpKx%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).kx = [];
            end
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).vd ) ), sw, s) , 'file' , sprintf('eom/sprdmpVd%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).vd = [];
            end
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).dir ) ), sw, s) , 'file' , sprintf('eom/sprdmpDir%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).dir = [];
            end
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).in ) ), sw, s) , 'file' , sprintf('eom/sprdmpIn%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).in = [];
            end
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).Tt_u ) ), sw, s) , 'file' , sprintf('eom/sprdmpTtu%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                sprdmp(i).Tt_u = [];
            end
%             parfor i = 1 : n_sd
%                 matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).dl ) ), sw, s) , 'file' , sprintf('eom/sprdmpDl%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%               sprdmp(i).dl = [];
%             end
%             parfor i = 1 : n_sd
%                 matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).k_mat ) ), sw, s) , 'file' , sprintf('eom/sprdmpKmat%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%                 sprdmp(i).k_mat = [];
%             end
%             parfor i = 1 : n_sd
%                 matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).vd_mat ) ), sw, s) , 'file' , sprintf('eom/sprdmpVdmat%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%                 sprdmp(i).vd_mat = [];
%             end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).T ) ), sw, s) ,'file' , sprintf('eom/cnstT%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).T = [];
            end
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).Tt ) ), sw, s) ,'file' , sprintf('eom/cnstTt%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).Tt = [];
            end
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).D ) ), sw, s) , 'file' , sprintf('eom/cnstD%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).D = [];
            end
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).in ) ), sw, s) , 'file' , sprintf('eom/cnstIn%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).in = [];
            end
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).r ) ), sw, s) , 'file' , sprintf('eom/cnstR%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).r = [];
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction( subs( sym( piecewise2logistic( loads(i).Tt ) ), sw, s) , 'file' , sprintf('eom/loadsTt%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                loads(i).Tt = [];
            end
            parfor i = 1 : n_ex
                matlabFunction( subs( sym( piecewise2logistic( loads(i).ftau ) ), sw, s) , 'file' , sprintf('eom/loadsFtau%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                loads(i).ftau = [];
            end
            parfor i = 1 : n_ex
                matlabFunction( subs( sym( piecewise2logistic( loads(i).Tt_o ) ), sw, s) , 'file' , sprintf('eom/loadsTto%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                loads(i).Tt_o = [];
            end
        end
        
    case 3 % collect for Matlab
        save_select = 1 : 22 ; % matlab func.s
%         save_select = 1 : 43 ; % all
        
    case 4 % collect for Matlab & C
        save_select = 1 : 43 ; % all
        
    case 5 % collect most terms
        if n_m ~= 0
            parfor i = 1 : n_m
                matlabFunction( subs( sym( piecewise2logistic( mass(i).TMT ) ), sw, s) , subs( sym( piecewise2logistic( mass(i).TMfd ) ), sw, s) , ...
                    'file' , sprintf('eom/massF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                mass(i).M = []; mass(i).T = []; mass(i).Dd = []; mass(i).fg = []; 
            end
        end
        if n_sd ~= 0
            parfor i = 1 : n_sd
                matlabFunction( subs( sym( piecewise2logistic( sprdmp(i).w_vd_j ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).w_sd ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).w_in ) ), sw, s) , subs( sym( piecewise2logistic( sprdmp(i).Tt_u ) ), sw, s) , ...
                    'file' , sprintf('eom/sprdmpF%i.m', i) , 'vars' , vars , 'Optimize' , opv ,'Sparse' , sprs );
                sprdmp(i).Tt = []; sprdmp(i).kx = []; sprdmp(i).vd = []; sprdmp(i).in = []; sprdmp(i).Tt_u = []; sprdmp(i).dir = []; sprdmp(i).dl = []; sprdmp(i).k_mat = []; sprdmp(i).vd_mat = []; 
            end
        end
        if n_cn ~= 0
            parfor i = 1 : n_cn
                matlabFunction( subs( sym( piecewise2logistic( cnst(i).T ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).Tt ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).dc ) ), sw, s) , subs( sym( piecewise2logistic( cnst(i).r ) ), sw, s ) , ...
                    'file' , sprintf('eom/cnstF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                cnst(i).T = []; cnst(i).Tt = []; cnst(i).D = []; cnst(i).in = []; cnst(i).r = [];
            end
        end
        if n_ex ~= 0
            parfor i = 1 : n_ex
                matlabFunction( subs( sym( piecewise2logistic( loads(i).w_f ) ), sw, s) , subs( sym( piecewise2logistic( loads(i).Tt_o ) ), sw, s) , ...
                    'file' , sprintf('eom/loadsF%i.m', i) , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
                loads(i).Tt = []; loads(i).ftau = []; loads(i).Tt_o = []; 
            end
        end
end

parfor i = 1 : numel( save_select )
    switch save_select(i)
        % matlab functions
        case 1
            matlabFunction( subs( sym( piecewise2logistic( M ) ), sw, s) , 'file' , 'eom/MF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 2
            matlabFunction( subs( sym ( piecewise2logistic( T ) ), sw, s) , 'file' , 'eom/TF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 3
            matlabFunction( subs( sym( piecewise2logistic( fj_k ) ), sw, s) , 'file' , 'eom/fj_kF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             fj_k = [];
            
        case 4
            matlabFunction( subs( sym( piecewise2logistic( fj_vd ) ), sw, s) , 'file' , 'eom/fj_vdF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             fj_vd = [];
            
        case 5
            matlabFunction( subs( sym( piecewise2logistic( fj_in ) ), sw, s) , 'file' , 'eom/fj_inF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            matlabFunction( subs( sym( piecewise2logistic( Tj_u ) ), sw, s) , 'file' , 'eom/Tj_uF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             fj_in = [];
%             Tj_u = [];
            
        case 6
            matlabFunction( subs( sym( piecewise2logistic( fj_k_mat ) ), sw, s) , 'file' , 'eom/fj_k_matF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            matlabFunction( subs( sym( piecewise2logistic( fj_vd_mat ) ), sw, s) , 'file' , 'eom/fj_vd_matF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             fj_k_mat = [];
%             fj_vd_mat = [];
            
        case 7
            matlabFunction( subs( sym( piecewise2logistic( fgv ) ), sw, s) , 'file' , 'eom/fgvF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 8
            matlabFunction( subs( sym( piecewise2logistic( Dd ) ), sw, s) , 'file' , 'eom/DdF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
              
        case 9
            matlabFunction( subs( sym( piecewise2logistic( ref ) ), sw, s) , 'file' , 'eom/refF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 10
            matlabFunction( subs( sym( piecewise2logistic( rcn ) ), sw, s) , 'file' , 'eom/rcnF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 11
            matlabFunction( subs( sym( piecewise2logistic( Ttef ) ), sw, s) , 'file' , 'eom/TtefF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 12
            matlabFunction( subs( sym( piecewise2logistic( Tcn ) ), sw, s) , 'file' , 'eom/TcnF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            matlabFunction( subs( sym( piecewise2logistic( Tcu ) ), sw, s) , 'file' , 'eom/TcuF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 13
            matlabFunction( subs( sym( piecewise2logistic( Dcn ) ), sw, s) , 'file' , 'eom/DcnF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 14
            matlabFunction( subs( sym( piecewise2logistic( r_jtips ) ), sw, s) , 'file' , 'eom/rjtipF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             r_jtips = [];
            
        case 15
            matlabFunction( subs( sym( piecewise2logistic( ftau_ef ) ), sw, s) , 'file' , 'eom/ftau_efF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 16
            matlabFunction( subs( sym( piecewise2logistic( w_sdi ) ), sw, s) , 'file' , 'eom/w_sdiF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 17
            matlabFunction( subs( sym( piecewise2logistic( w_k ) ), sw, s) , 'file' , 'eom/w_kF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 18
            matlabFunction( subs( sym( piecewise2logistic( w_vd ) ), sw, s) , 'file' , 'eom/w_vdF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 19
            matlabFunction( subs( sym( piecewise2logistic( w_in ) ), sw, s) , 'file' , 'eom/w_inF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
              
        case 20
            matlabFunction( subs( sym( piecewise2logistic( r_ks ) ), sw, s) , 'file' , 'eom/rksF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
%             r_ks = [];
               
        case 21
            matlabFunction( subs( sym( piecewise2logistic( k_mat ) ), sw, s) , 'file' , 'eom/k_matF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            matlabFunction( subs( sym( piecewise2logistic( vd_mat ) ), sw, s) , 'file' , 'eom/vd_matF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
            
        case 22
            matlabFunction( subs( sym( piecewise2logistic( fj_sdi ) ), sw, s) , 'file' , 'eom/fj_sdiF.m' , 'vars' , vars , 'Optimize' , opv , 'Sparse' , sprs );
        
        % C codes
        case 23
            if ~isempty( M )
                ccode ( subs( sym( piecewise2logistic( M ) ), sw, s) , 'file' , 'eom/MF.cpp' );
            end
            
        case 24
            if ~isempty( T )
                ccode ( subs( sym( piecewise2logistic( T ) ), sw, s) , 'file' , 'eom/TF.cpp' );
            end
            
        case 25
            if ~isempty( fj_k )
                ccode ( subs( sym( piecewise2logistic( fj_k ) ), sw, s) , 'file' , 'eom/fj_kF.cpp' );
            end
            
        case 26
            if ~isempty( fj_vd )
                ccode ( subs( sym( piecewise2logistic( fj_vd ) ), sw, s) , 'file' , 'eom/fj_vdF.cpp' );
            end
           
        case 27
            if ~isempty( fj_in )
                ccode ( subs( sym( piecewise2logistic( fj_in ) ), sw, s) , 'file' , 'eom/fj_inF.cpp' );
            end
            
        case 28
            if ~isempty( fj_k_mat )
                ccode ( subs( sym( piecewise2logistic( fj_k_mat ) ), sw, s) , 'file' , 'eom/fj_k_matF.cpp' );
            end
            
        case 29
            if ~isempty( fgv )
                ccode ( subs( sym( piecewise2logistic( fgv ) ), sw, s) , 'file' , 'eom/fgvF.cpp' );
            end
            
        case 30
            if ~isempty( Dd )
                ccode ( subs( sym( piecewise2logistic( Dd ) ), sw, s) , 'file' , 'eom/DdF.cpp' );
            end
            
        case 31
            if ~isempty( ref )
                ccode ( subs( sym( piecewise2logistic( ref ) ), sw, s) , 'file' , 'eom/refF.cpp' );
            end
            
        case 32
            if ~isempty( rcn )
                ccode ( subs( sym( piecewise2logistic( rcn ) ), sw, s) , 'file' , 'eom/rcnF.cpp' );
            end
            
        case 33
            if ~isempty( Ttef )
                ccode ( subs( sym( piecewise2logistic( Ttef ) ), sw, s) , 'file' , 'eom/TtefF.cpp' );
            end
            
        case 34
            if ~isempty( Tcn )
                ccode ( subs( sym( piecewise2logistic( Tcn ) ), sw, s) , 'file' , 'eom/TcnF.cpp' );
            end
            
        case 35
            if ~isempty( Dcn )
                ccode ( subs( sym( piecewise2logistic( Dcn ) ), sw, s) , 'file' , 'eom/DcnF.cpp' );
            end
            
        case 36
            if ~isempty( r_jtip )
                ccode ( subs( sym( piecewise2logistic( r_jtip ) ), sw, s) , 'file' , 'eom/rjtipF.cpp' );
            end
            
        case 37
            if ~isempty( w_sdi )
                ccode ( subs( sym( piecewise2logistic( w_sdi ) ), sw, s) , 'file' , 'eom/w_sdiF.cpp' );
            end
            
        case 38
            if ~isempty( w_k )
                ccode ( subs( sym( piecewise2logistic( w_k ) ), sw, s) , 'file' , 'eom/w_kF.cpp' );
            end
            
        case 39
            if ~isempty( w_vd )
                ccode ( subs( sym( piecewise2logistic( w_vd ) ), sw, s) , 'file' , 'eom/w_vdF.cpp' );
            end
            
        case 40
            if ~isempty( w_in )
                ccode ( subs( sym( piecewise2logistic( w_in ) ), sw, s) , 'file' , 'eom/w_inF.cpp' );
            end
            
        case 41
            if ~isempty( r_ks )
                ccode ( subs( sym( piecewise2logistic( r_ks ) ), sw, s) , 'file' , 'eom/rksF.cpp' );
            end

        case 42
            if ~isempty( k_mat )
                ccode ( subs( sym( piecewise2logistic( k_mat ) ), sw, s) , 'file' , 'eom/k_matF.cpp' );
            end
            
        case 43
            if ~isempty( fj_sdi )
                ccode ( subs( sym( piecewise2logistic( fj_sdi ) ), sw, s) , 'file' , 'eom/fj_sdiF.cpp' );
            end
            
    end    
end

if par.clean % clean up memory
    clearvars -except q u lambda dlambda gamma dgamma s ds t_sym par n_m n_sd n_cn n_co n_ex
end

save_mex( q , u , lambda , dlambda , gamma , dgamma , s , ds , t_sym , par , n_m , n_sd , n_cn , n_co , n_ex ) ;

delete(gcp('nocreate'));
myCluster = parcluster('local');
delete(myCluster.Jobs);


