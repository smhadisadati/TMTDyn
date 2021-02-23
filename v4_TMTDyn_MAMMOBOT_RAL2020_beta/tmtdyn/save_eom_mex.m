function par = save_eom_mex( z0 , par , analysis )
% analysis: equil, dyn, dz0, J
global par_mex

fprintf( 'generate EOM_mex... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )

% par_mex
par_mex = par.par_mex ;

string_1 = '';
string_rigid = '';
string_rom = '';
string_all = '';
string_rom_Ttu_1 = '';
string_rom_Ttu_2 = '';
string_rom_Ttu_3 = '';

if par.derive_mex
    strmex = '_mex';
else
    strmex = '';
end

if ismember( par.equil , [ 1 2 ] ) || ismember( par.dyn , [ 1 2 ] ) % not using old m-file
    switch analysis
        case 'equil' % equil. (static) sym.
            string_1 = [
                'function res = EOM_eq ( z )' ] ;
        case 'dyn' % Sundials ODE solver
            switch par.solver
                case { 1, 2, 4 , 5 , 6 } % matlab, sundials ode, radau
                    string_1 = [
                        'function [ dz , flag , new_data ] = EOM ( t , z , par_mex )' ] ;
                case 3 % sundials dae
                    string_1 = [
                        'function [ res , flag , new_data ] = EOM ( t , z , dz , par_mex )' ] ;
            end
        case 'dz0' % Sundials DAE
            string_1 = [
                'function [ dz , flag , new_data ] = EOM ( t , z , par_mex )' ] ; 
        case 'J' % Jacobian
            string_1 = [
                'function [ J , flag , new_data ] = EOM ( t , z , fz , par_mex )' ] ;        
    end

    switch analysis
        case 'equil' % equil. (static) sym.
            string_1 = [ string_1 newline ...
                'global par_mex' newline ...
                'par_mex.t_equil_i;' newline ....
                'z = [ z 0*z ]'' ;' newline ...
                newline ...
                'u = z( ' num2str( par.nq + par.nlambda + par.ngamma + 1 ) ' : end ) ;' newline ...
                'uq = u( 1 : ' num2str( par.nq ) ' ) ;' newline ...
                newline ...
                '[ z , par_mex ] = static_mid_step( par_mex.t_equil_i , z , par_mex ) ;' newline ... % integration mid-step
                newline ...
                'fj_k = fj_kF' strmex '( par_mex.var , z ) ; ' newline ... % state stiffness/input
                'fj_in = fj_inF' strmex '( par_mex.var , z ) ;' newline ...
                'Tj_u = Tj_uF' strmex '( par_mex.var , z ) ;' newline ] ;
        otherwise % dyn. sim.
%             if par.t_rep ~= 0
%                 string_1 = [ string_1 newline ...
%                     newline ...
%                     'global t_report' newline ...
%                     'if t > t_report' newline ...
%                     '    t ' newline ... % report time
%                     '    t_report = t + ' num2str( par.t_rep ) ' ; ' newline ... % report once
%                     'end' ] ;
%             end
            string_1 = [ string_1 newline ...
                ...'t ' newline ...
                newline ...
                'u = z( ' num2str( par.nq ) ' + ' num2str( par.nlambda ) ' + ' num2str( par.ngamma ) ' + 1 : end ) ;' newline ...
                'uq = u( 1 : ' num2str( par.nq ) ' ) ;' newline ...
                newline ...
                '[ z , par_mex ] = dyn_mid_step( t , z , par_mex ) ;' newline ... % integration mid-step
                newline ...
                'fj_k = fj_kF' strmex '( par_mex.var , z ) ; ' newline ... % state stiffness/input
                'fj_vd = fj_vdF' strmex '( par_mex.var , z ) ;' newline ...
                'fj_in = fj_inF' strmex '( par_mex.var , z ) ;' newline ...
                'Tj_u = Tj_uF' strmex '( par_mex.var , z ) ;' newline ] ;
    end

    if par.sparse
        string_1 = [ string_1 newline ...
            'fj_k = sparse( fj_k(:,1) , fj_k(:,2) , fj_k(:,3) ) ; ' newline ...
            'fj_vd = sparse( fj_vd(:,1) , fj_vd(:,2) , fj_vd(:,3) ) ; ' newline ...
            'fj_in = sparse( fj_in(:,1) , fj_in(:,2) , fj_in(:,3) ) ; ' newline ...
            'TMT = sparse(' num2str(par.nq) ',' num2str(par.nq) ') ; TMfd = sparse(' num2str(par.nq) ',1) ;' newline ...
            'w_vd_j = sparse(' num2str(par.nq) ',1) ; w_sd = sparse(' num2str(par.nq) ',1) ; w_in = sparse(' num2str(par.nq) ',1) ;' newline ...
            'w_f = sparse(' num2str(par.nq) ',1) ;' newline ...
            'Tc = sparse( [] ) ; Tct = sparse( Tj_u(:,1) , Tj_u(:,2) , Tj_u(:,3) ) ; dc = sparse( [] ) ;' newline ...
            'u = sparse( u ) ; uq = sparse( uq ) ;' ] ;
    else
        string_1 = [ string_1 newline ...
            'TMT = zeros(' num2str(par.nq) ',' num2str(par.nq) ') ; TMfd = zeros(' num2str(par.nq) ',1) ;' newline ...
            'w_vd_j = zeros(' num2str(par.nq) ',1) ; w_sd = zeros(' num2str(par.nq) ',1) ; w_in = zeros(' num2str(par.nq) ',1) ;' newline ...
            'w_f = zeros(' num2str(par.nq) ',1) ;' newline ...
            'Tc = [] ; Tct = Tj_u ; dc = [] ;' newline ] ;
    end
    
    [rom_mass, rom_sprdmp] = romF(par.var, z0', 0) ;
    if max( max( abs( [ rom_mass; rom_sprdmp ] ) ) ) ~= 0 % there are rom elements
        string_1 = [string_1 ...
            '[rom_mass, rom_sprdmp] = romF(par_mex.var , z , 0) ;' newline ];
    end
    string_all = string_1;
    
    s0 = 1e-6 ;
    for i = 1 : par.n_m
        if max( abs( rom_mass(i,:) ) ) == 0
            if par.derive_collect == 1
                string_rigid = [ string_rigid newline ...
                    '[ M , T , Dd , fg ] = massF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
            elseif par.derive_collect == 2
                string_rigid = [ string_rigid newline ...
                    'M = massM' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                    'T = massT' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                    'Dd = massDd' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                    'fg = massFg' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;                
            end
            if par.sparse
                string_rigid = [string_rigid newline ...
                    'M = sparse( M(:,1) , M(:,2) , M(:,3) ) ;' newline ...
                    'T = sparse( T(:,1) , T(:,2) , T(:,3) , 6 , ' num2str(par.nq) ' ) ;' newline ...
                    'Dd = sparse( Dd(:,1) , Dd(:,2) , Dd(:,3) 6 , ' num2str(par.nq) ' ) ;' newline ...
                    'fg = sparse( fg(:,1) , fg(:,2) , fg(:,3) 6 , 1 ) ;' ] ;
            end
            string_rigid = [ string_rigid newline ...
                'Tt = T'' ;' newline ...
                'TMT = TMT + Tt * M * T ;' newline ...
                'TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) ;' newline ] ;
        else
            ds = [ '( rom_mass(' num2str(i) ',2) - rom_mass(' num2str(i) ',1) )' ] ;  % will be devided by par.n_int later
            if par.derive_collect == 1
                string_rom = [ string_rom newline ...
                    '    [ M , T , Dd , fg ] = massF' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_mass(' num2str(i) ',1) ) ;' ] ;
            elseif par.derive_collect == 2
                string_rom = [ string_rom newline ...
                    '    M = massM' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_mass(' num2str(i) ',1) ) ;' newline ...
                    '    T = massT' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_mass(' num2str(i) ',1) ) ;' newline ...
                    '    Dd = massDd' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_mass(' num2str(i) ',1) ) ;' newline ...
                    '    fg = massFg' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_mass(' num2str(i) ',1) ) ;' ] ;
            end
            if par.sparse
                string_rom = [string_rom newline ...
                    '    M = sparse( M(:,1) , M(:,2) , M(:,3) ) ;' newline ...
                    '    T = sparse( T(:,1) , T(:,2) , T(:,3) , 6 , ' num2str(par.nq) ' ) ;' newline ...
                    '    Dd = sparse( Dd(:,1) , Dd(:,2) , Dd(:,3) , 6 , ' num2str(par.nq) ' ) ;' newline ...
                    '    fg = sparse( fg(:,1) , fg(:,2) , fg(:,3) , 6 , 1 ) ;' ] ;
            end
            string_rom = [ string_rom newline ...
                '    Tt = T'' ;' newline ...
                '    TMT = TMT + Tt * M * T * ' ds ' ;' newline ...
                '    TMfd = TMfd + Tt * M * ( - Dd * uq + fg ) * ' ds ' ;' newline ] ;
        end
    end

    for i = par.nq + 1 : par.n_sd
        [ ~ , ~ , ~ , ~ , Ttu_temp ] = eval( [ 'sprdmpF' num2str(i) '( par_mex.var , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , 0 )' ] ) ;
%         Ttu_temp = [];
        if isempty( Ttu_temp ) % no Ttu        
            if max( abs( rom_sprdmp(i,:) ) ) == 0
                if par.derive_collect == 1
                    string_rigid = [ string_rigid newline ...
                        '[ Tt , kx , vd , in , ~ , dir ] = sprdmpF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;                    
                elseif par.derive_collect == 2
                    string_rigid = [ string_rigid newline ...
                        'Tt = sprdmpTt' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...   
                        'kx = sprdmpKx' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'vd = sprdmpVd' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'in = sprdmpIn' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'dir = sprdmpDir' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;                      
                end
                if par.sparse
                    string_rigid = [string_rigid newline ...
                        'Tt = sparse( Tt(:,1) , Tt(:,2) , Tt(:,3) , ' num2str(par.nq) ' , 6 ) ;' newline ...
                        'kx = sparse( kx(:,1) , kx(:,2) , kx(:,3) , 6 , 1 ) ;' newline ...
                        'vd = sparse( vd(:,1) , vd(:,2) , vd(:,3) , 6 , 1 ) ;' newline ...
                        'in = sparse( in(:,1) , in(:,2) , in(:,3) , 6 , 1 ) ;' ] ;
                end
                string_rigid = [ string_rigid newline ...
                    'w_vd_j = w_vd_j + dir * Tt * vd ;' newline ...
                    'w_sd = w_sd + dir * Tt * kx ;' newline ...
                    'w_in = w_in + dir * Tt * in ;' newline ] ;
            else
                ds = [ '( rom_sprdmp(' num2str(i) ',2) - rom_sprdmp(' num2str(i) ',1) )' ] ; % will be devided by par.n_int later
                if par.derive_collect == 1
                    string_rom = [ string_rom newline ...
                        '    [ Tt , kx , vd , in , ~ , dir ] = sprdmpF' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' ] ;
                elseif par.derive_collect == 2
                    string_rom = [ string_rom newline ...
                        '    Tt = sprdmpTt' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    kx = sprdmpKx' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    vd = sprdmpVd' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    in = sprdmpIn' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    dir = sprdmpDir' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' ] ;
                end
                if par.sparse
                    string_rom = [string_rom newline ...
                        '    Tt = sparse( Tt(:,1) , Tt(:,2) , Tt(:,3) , ' num2str(par.nq) ' , 6 ) ;' newline ...
                        '    kx = sparse( kx(:,1) , kx(:,2) , kx(:,3) , 6 , 1 ) ;' newline ...
                        '    vd = sparse( vd(:,1) , vd(:,2) , vd(:,3) , 6 , 1 ) ;' newline ...
                        '    in = sparse( in(:,1) , in(:,2) , in(:,3) , 6 , 1 ) ;' ] ;
                end
                string_rom = [ string_rom newline ...
                    '    w_vd_j = w_vd_j + dir * Tt * vd * ' ds ' ;' newline ...
                    '    w_sd = w_sd + dir * Tt * kx * ' ds ' ;' newline ...
                    '    w_in = w_in + dir * Tt * in * ' ds ' ;' newline ] ;
            end

        else % with Ttu
            if max( abs(rom_sprdmp(i,:) ) ) == 0
                if par.derive_collect == 1
                    string_rigid = [ string_rigid newline ...
                        '[ Tt , kx , vd , in , Ttu , dir ] = sprdmpF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
                elseif par.derive_collect == 2
                    string_rigid = [ string_rigid newline ...
                        'Tt = sprdmpTt' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'kx = sprdmpKx' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'vd = sprdmpVd' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'in = sprdmpIn' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'Ttu = sprdmpTtu' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'dir = sprdmpDir' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
                end
                if par.sparse
                    string_rigid = [string_rigid newline ...
                        'Tt = sparse( Tt(:,1) , Tt(:,2) , Tt(:,3) , ' num2str(par.nq) ' , 6 ) ;' newline ...
                        'kx = sparse( kx(:,1) , kx(:,2) , kx(:,3) , 6 , 1 ) ;' newline ...
                        'vd = sparse( vd(:,1) , vd(:,2) , vd(:,3) , 6 , 1 ) ;' newline ...
                        'in = sparse( in(:,1) , in(:,2) , in(:,3) , 6 , 1 ) ;' newline ...
                        'Ttu = sparse( Ttu(:,1) , Ttu(:,2) , Ttu(:,3) , 6 , 1 ) ;' ] ;
                end
                string_rigid = [ string_rigid newline ...
                    'w_vd_j = w_vd_j + dir * Tt * vd ;' newline ...
                    'w_sd = w_sd + dir * Tt * kx ;' newline ...
                    'w_in = w_in + dir * Tt * in ;' newline ...
                    'Tct = [ Tct , Ttu ] ;' newline ] ;
            else
                ds = [ '( rom_sprdmp(' num2str(i) ',2) - rom_sprdmp(' num2str(i) ',1) )' ] ; % will be devided by par.n_int later
                [ temp1 , temp2 ] = size( Ttu_temp ) ;
                if par.sparse
                    string_rom_Ttu_1 = [ string_rom_Ttu_1 newline ...
                        'Ttu_' num2str(i) ' = sparse( ' num2str( temp1 ) ' , ' num2str( temp2 ) ' ) ;' ] ;
                else
                    string_rom_Ttu_1 = [ string_rom_Ttu_1 newline ...
                        'Ttu_' num2str(i) ' = zeros( ' num2str( temp1 ) ' , ' num2str( temp2 ) ' ) ;' ] ;
                end
                if par.derive_collect == 1
                    string_rom = [ string_rom newline ...
                        '    [ Tt , kx , vd , in , ttu , dir ] = sprdmpF' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' ] ;
                elseif par.derive_collect == 2
                    string_rom = [ string_rom newline ...
                        '    Tt = sprdmpTt' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    kx = sprdmpKx' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    vd = sprdmpVd' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    in = sprdmpIn' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    ttu = sprdmpTtu' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' newline ...
                        '    dir = sprdmpDir' num2str(i) strmex '( par_mex.var , z , sn * ' ds ' + rom_sprdmp(' num2str(i) ',1) ) ;' ] ;
                end
                if par.sparse
                    string_rom = [string_rom newline ...
                        '    Tt = sparse( Tt(:,1) , Tt(:,2) , Tt(:,3) , ' num2str(par.nq) ' , 6 ) ;' newline ...
                        '    kx = sparse( kx(:,1) , kx(:,2) , kx(:,3) , 6 , 1 ) ;' newline ...
                        '    vd = sparse( vd(:,1) , vd(:,2) , vd(:,3) , 6 , 1 ) ;' newline ...
                        '    in = sparse( in(:,1) , in(:,2) , in(:,3) , 6 , 1 ) ;' newline ...
                        '    ttu = sparse( ttu(:,1) , ttu(:,2) , ttu(:,3) , 6 , 1 ) ;' ] ;
                end
                string_rom = [ string_rom newline ...
                    '    w_vd_j = w_vd_j + dir * Tt * vd * ' ds ' ;' newline ...
                    '    w_sd = w_sd + dir * Tt * kx * ' ds ' ;' newline ...
                    '    w_in = w_in + dir * Tt * in * ' ds ' ;' newline ...
                    '    Ttu_' num2str(i) ' = Ttu_' num2str(i) ' + ttu * ' ds ' ;' newline ] ;
                string_rom_Ttu_2 = [ string_rom_Ttu_2 newline ...
                    'Ttu_' num2str(i) ' = Ttu_' num2str(i) ' / 2 ; ' newline ] ;
				if isempty( string_rom_Ttu_3 )
					string_rom_Ttu_3 = [ string_rom_Ttu_3 'Ttu_' num2str(i) ] ;
				else
					string_rom_Ttu_3 = [ string_rom_Ttu_3 ' , Ttu_' num2str(i) ] ;				
				end
            end

        end
    end
    
    % rom trapz spatial integral
    if max( max( abs( [ rom_mass; rom_sprdmp ] ) ) ) ~= 0 % there are rom elements
        string_all = [ string_all newline ...
			string_rom_Ttu_1 newline ...
            'sn = 0 ; ' newline ...
            string_rom newline... 
            'sn = 1 ; ' newline ...
            string_rom newline...   
            'TMT = TMT / 2 ; TMfd = TMfd / 2 ;' newline ... % will be devided by par.n_int later
            'w_vd_j = w_vd_j / 2 ; w_sd = w_sd / 2 ; w_in = w_in / 2 ;' newline ... 
			string_rom_Ttu_2 newline ...
            newline ...
            'for sn = ' num2str( s0 ) ' + ' num2str( 1 / par.n_int ) ' : ' num2str( 1 / par.n_int ) ' : ' num2str( 1 ) ' + ' num2str( s0 ) ' - ' num2str( 1 / par.n_int ) newline ...
            string_rom newline ...
            'end' newline ...
            'TMT = TMT / ' num2str( par.n_int ) ' ; TMfd = TMfd / ' num2str( par.n_int ) ' ;' newline ...
            'w_vd_j = w_vd_j / ' num2str( par.n_int ) ' ; w_sd = w_sd / ' num2str( par.n_int ) ' ; w_in = w_in / ' num2str( par.n_int ) ' ;' newline ] ; 
        if 	~isempty( string_rom_Ttu_3 )
            string_all = [ string_all newline ...
                'Tct = [ Tct , [ ' string_rom_Ttu_3 ' ]/' num2str( par.n_int ) ' ] ;' newline ] ;
        end
    end
    
    % rigid body terms
    string_all = [ string_all newline ...
        string_rigid newline ] ;
    

    for i = 1 : par.n_ex
        if par.derive_collect == 1
            string_all = [ string_all newline ...
                '[ Ttf , ftau_ex , Tto ] = loadsF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
        elseif par.derive_collect == 2
            string_all = [ string_all newline ...
                'Ttf = loadsTt' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                'ftau_ex = loadsFtau' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                'Tto = loadsTto' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
        end
            if par.sparse
                string_all = [string_all newline ...
                    'Ttf = sparse( Ttf(:,1) , Ttf(:,2) , Ttf(:,3) , ' num2str(par.nq) ' , 6 ) ;' newline ...
                    'ftau_ex = sparse( ftau_ex(:,1) , ftau_ex(:,2) , ftau_ex(:,3) , 6 , 1 ) ;' newline ...
                    'Tto = sparse( Tto(:,1) , Tto(:,2) , Tto(:,3) , ' num2str(par.nq) ' , 6 ) ;' ] ;
            end
            string_all = [ string_all newline ...
            'w_f = w_f + Ttf * ftau_ex ;' newline ...
            'Tct = [ Tct , Tto ] ;' newline ] ;
    end

    switch analysis
        case 'equil' % equil. (static) sym.
            for i = 1 : par.n_cn
                if par.derive_collect == 1
                    string_all = [ string_all newline ...
                        '[ ~ , tct , ~ , in , rc ] = cnstF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
                elseif par.derive_collect == 2
                    string_all = [ string_all newline ...
                        'tct = cnstTt' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'in = cnstIn' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'rc = cnstR' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;                    
                end
                if par.sparse
                    string_all = [string_all newline ...
                        'tct = sparse( tct(:,1) , tct(:,2) , tct(:,3) , 1 , ' num2str(par.nq) ' ) ;' newline ...
                        'rc = sparse( rc(:,1) , rc(:,2) , rc(:,3) , 1 , ' num2str(par.nq) ' ) ;' ] ;
                end
                string_all = [ string_all newline ...
                    'Tct = [ Tct , tct ] ;' newline ...
                    'dc = [ dc ; ( rc - in ) ] ; %% in is geometry-positions' newline ] ;
            end
            
        otherwise % dyn. sim.
            for i = 1 : par.n_cn
                if par.derive_collect == 1
                    string_all = [ string_all newline ...
                        '[ tc , tct , Dc , in ] = cnstF' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
                elseif par.derive_collect == 2
                    string_all = [ string_all newline ...
                        'tc = cnstT' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'tct = cnstTt' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'Dc = cnstD' num2str(i) strmex '( par_mex.var , z , 0 ) ;' newline ...
                        'in = cnstIn' num2str(i) strmex '( par_mex.var , z , 0 ) ;' ] ;
                end
                if par.sparse
                    string_all = [string_all newline ...
                        'tc = sparse( tc(:,1) , tc(:,2) , tc(:,3) , 1 , ' num2str(par.nq) ' ) ;' newline ...
                        'tct = sparse( tct(:,1) , tct(:,2) , tct(:,3) , 1 , ' num2str(par.nq) ' ) ;' newline ...
                        'Dc = sparse( Dc(:,1) , Dc(:,2) , Dc(:,3) , 1 , ' num2str(par.nq) ' ) ;' ] ;
                end
                string_all = [ string_all newline ...
                    'Tc = [ Tc ; tc ] ;' newline ...
                    'Tct = [ Tct , tct ] ;' newline ...
                    'dc = [ dc ; ( - Dc * uq + in ) ] ; %% in is accelerations' newline ] ;
            end
            
    end

    switch analysis
        case 'equil' % equil. (static) sym.
            if par.nlambda + par.ngamma == 0
                lg_str = ' ' ; % for lambda-gamma
            else
                lg_str = [ ' + Tct * z(end/2-' num2str( par.nlambda + par.ngamma ) '+1:end/2) ' ] ;                
            end
            string_all = [ string_all newline ... % in Cartesian space
                '%% EOM' newline ...
                'res = [ ( TMfd + fj_k + fj_in + w_sd + w_in + w_f' lg_str ') ; dc ] ;' newline ] ;
                % string_all = [ string_all newline ... % in state space
                %     '%% EOM' newline ...
                %     'TMT = [ TMT , -Tct ; Tc , zeros(' num2str(par_mex.n_cn) ',' num2str(par.nlambda+par.ngamma) ') ] ;' newline ...
                %     'd_eom = [ ( TMfd + fj_k + fj_in + w_sd + w_in + w_f ) ; dc ] ;' newline ...
                %     'res = TMT \\ d_eom ;' newline ] ;
        otherwise % dyn. sim.
            string_all = [ string_all newline ...
                '%% EOM' newline ...
                'TMTb = [ TMT , -Tct ; ' newline ...
                '         Tc  , zeros(' num2str(par.n_cn) ',' num2str(par.nlambda+par.ngamma) ') ] ;' newline ...
                'd_eom = [ ( TMfd + fj_k + fj_vd + fj_in + w_sd + w_in + w_vd_j + w_f ) ; dc ] ;' newline ...
                newline ...
                'dY = u ;' ] ;
                ...'dY = [ eye(' num2str(par.nq) ',' num2str(par.nq) ') , -Tct ; ' newline ...
                ...'       Tc , zeros(' num2str(par.n_cn) ',' num2str(par.nlambda+par.ngamma) ') ] * u ;' ] ;
      			% 'TMTu = [ eye(' num2str(par.nq) ',' num2str(par.nq) ') , -Tct ; ' newline ...
      			% '       Tc , zeros(' num2str(par.n_cn) ',' num2str(par.nlambda+par.ngamma) ') ] ;' ] ;
            if par.sparse % for pinv
               string_all = [ string_all newline ...
                   'TMTb = full( TMTb ) ;' newline ] ;
            end
    end

    switch analysis
        case 'dyn'
            switch par.solver 
                case { 1 , 2 , 4 , 5 , 6 } % Matlab & Sundials ODE
                    string_all = [ string_all newline ...
                        ...'ddY = TMTb \\ d_eom ;' newline newline ...
                        ...'dY = TMTu \\ u ;' newline ...
                        'ddY = pinv( TMTb ) * d_eom ;' newline ...
                        ...'dY = pinv( TMTu ) * u ;' newline ...
                        ...'ddY = lsqminnorm( TMTb , d_eom ) ;' newline ...
                        ...'dY = lsqminnorm( TMTu , u ) ;' newline ...
                        newline ...
                        'dz = [ dY ; ddY ];' ] ;
                case 3 % Sundials DAE
                    string_all = [ string_all newline ...
                        newline ...
                        'res = [ ( TMTu * dz( 1 : ' num2str( par.nq ) ' + ' num2str( par.nlambda ) ' ) - u ) ; ' newline ...
                        '        ( TMTb * dz( ' num2str( par.nq ) ' + ' num2str( par.nlambda ) ' + 1 : end ) - d_eom ) ] ;' ] ;
            end
        case 'dz0'
            string_all = [ string_all newline ...
                ...'ddY = TMTb \\ d_eom ;' newline newline ...
                ...'dY = TMTu \\ u ;' newline ...
                'ddY = pinv( TMTb ) * d_eom ;' newline ...
                ...'dY = pinv( TMTu ) * u ;' newline ...
                ...'ddY = lsqminnorm( TMTb , d_eom ) ;' newline ...
                ...'dY = lsqminnorm( TMTu , u ) ;' newline ...
                newline ...
                'dz = [ dY ; ddY ];' ] ;
        case 'J'
            string_all = [ string_all newline ...
                'J = TMTb ;' ] ;	
    end

    string_all = [ string_all newline ...
        'flag = 0;' newline ...
        'new_data = [];' ] ;

    %  write m-file
    switch analysis
        case 'equil'
            EOM_m = fopen( 'eom/EOM_eq.m', 'wt' ) ;
        case 'dyn'
            EOM_m = fopen( 'eom/EOM.m', 'wt' ) ;
        case 'dz0'
            EOM_m = fopen( 'eom/EOM_0.m', 'wt' ) ;
        case 'J'
            EOM_m = fopen( 'eom/EOM_J.m', 'wt' ) ;
    end

    fprintf( EOM_m , string_all ) ;
    fclose( EOM_m ) ;
end

if ismember( par.equil , [ 2 , 4 ] )
    cd eom
    switch analysis
        case 'equil' % equil. (static) sym.
            % mex
            vars_mex = { zeros( 1 , ( par.nq + par.nlambda + par.ngamma ) ) } ;
            codegen EOM_eq -args vars_mex
    end
    cd ..
end

if ismember( par.dyn , [ 2 , 4 ] )
    cd eom
    switch analysis
        case 'dyn' % dyn sim
            % mex
            switch par.solver
                case { 1 , 2 , 4 , 5 , 6 } % Matlab & Sundials ODE & Radau
                    vars_mex = { 0 , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , par_mex } ;
                case 3 % Sundials DAE
                    vars_mex = { 0 , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , zeros( 2 * ( par.nq + par.nlambda + par.ngamma )  , 1 ) , par_mex } ;
            end
            codegen EOM -args vars_mex
        case 'dz0'
            % mex
            vars_mex = { 0 , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , par_mex } ;
            codegen EOM_0 -args vars_mex
        case 'J'
            % mex
            vars_mex = { 0 , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , zeros( 2 * ( par.nq + par.nlambda + par.ngamma ) , 1 ) , par_mex } ;
            codegen EOM_J -args vars_mex
    end
    cd ..
end

% for inputs
user_pars = par_mex.user_pars;
save( './eom/user_pars.mat' , 'user_pars' );
string_in = [ 'function [tspan, nz, z0, par_mex] = EOM_input()' newline ...
	'tspan = [ ' num2str( [ par.t0, par.stepT, par.t0+par.dt ] ) ' ] ;' newline ...
	'nz = ' num2str( numel( par.z0 ) ) ' ;' newline ...
    'z0 = [ ' num2str( par.z0 ) ' ]'' ;' newline ...
    'temp = coder.load( ''./eom/user_pars.mat'' );' newline ...
    'par_mex.user_pars = temp.user_pars ;' newline ...
    ...'par_mex.user_pars = [ ' num2str( par_mex.user_pars ) ' ] ;' newline ...
    'par_mex.var = [ ' num2str( par_mex.var ) ' ] ;' newline ...
    'par_mex.t_equil_i = [ ' num2str( par_mex.t_equil_i ) ' ] ;' ] ;
    
EOM_in = fopen( 'eom/EOM_input.m', 'wt' ) ;
fprintf( EOM_in , string_in ) ;
fclose( EOM_in ) ;

fprintf( 'mex file generated. continue... \n' )
par.elapsed_time = [ par.elapsed_time toc( par.timer ) ] ;
toc( par.timer )


