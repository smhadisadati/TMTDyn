% function varargout = radau(OdeFcn,tspan,y0,options,varargin)
function [tout, yout] = radau_edit_pinv(odefun,tspan,y0,vars,options)
%
%     Numerical solution of a stiff (or differential algebraic) system of
%     first order ordinary differential equations:
%                   Mass*y' = OdeFcn(t,y).
%     The system can be (linearly) implicit (mass-matrix Mass ~= I)
%     or explicit (Mass = I)
%     The code is based on implicit Runge-Kutta methods (Radau IIa)
%     with variable order (1, 5, 9, 13), with step size control and
%     continuous output.
%
%     AUTHORS: E. HAIRER AND G. WANNER
%              UNIVERSITE DE GENEVE, DEPT. DE MATHEMATIQUES
%              CH-1211 GENEVE 24, SWITZERLAND 
%              E-MAIL:  Ernst.Hairer@math.unige.ch
%                       Gerhard.Wanner@math.unige.ch
% 
%     For a description of the related code Radau5 see the book
%         E. HAIRER AND G. WANNER, SOLVING ORDINARY DIFFERENTIAL
%         EQUATIONS II. STIFF AND DIFFERENTIAL-ALGEBRAIC PROBLEMS.
%         SPRINGER SERIES IN COMPUTATIONAL MATHEMATICS 14,
%         SPRINGER-VERLAG 1991, SECOND EDITION 1996.
%
%     Matlab version:
%     Denis Bichsel
%     Rue des Deurres 58
%     2000 Neuchtel
%     Suisse
%     dbichsel@infomaniak.ch
%     Version of end 2015
%
% RADAU solve stiff differential equations, with variable order method.
%
% [tout,yout] = radau(OdeFcn,tspan,y0) with tspan = [t0, tfinal]
%   solve the system of first order differential (or differential -
%   algebraic) equations y' = OdeFcn(t,y) from t0 to tfinal with initial
%   conditions y0. OdeFcn is the name (or function handle) of the function   
%   which defines the system.
%  Input
%   y0:      must be a column vector of initial conditions
%   OdeFcn:  must return a column vector
%   tspan:   is a vector with at least two component, t0 and tfinal
%   tspan may also be a monotonic vector t0 < t1 < t2 ... < tfinal or
%   t0 > t1 > t2 ... > tfinal.
%   If tspan is a two components vector, the solver returns the solution 
%   at points evaluated by the solver.
%   If tspan is a vector with more than two components, the solutions are
%   only returned at these tspan values.
%
% [tout,yout] = radau(OdeFcn,tspan,y0,options) solves as above with
%   default integration parameters replaced by values in options, an 
%   argument created with the RDPSET function. See RDPSET for details.  
%
% [tout,yout] = radau(OdeFcn,tspan,y0,options,varargin) solves as above 
%   with parameters in varargin. These parameters may be used in OdeFcn,
%   JacFcn and or in MassFcn.
%
% radau(OdeFcn,tspan,y0) or 
% radau(OdeFcn,tspan,y0,options) or
% radau(OdeFcn,tspan,y0,options,varargin)
%   If radau is called without output parameters, radau calls odeplot to
%   show graphical solution.
%   	
% RADAU also solves problems M*y' = F(t,y) with a constant mass matrix M.
%   Define a function which define the mass matrix and let it know to RADAU
%   via the options (see RDPSET and the examples)(default = identity).
%
% The jacobian of the system may be defined analytically and the name
%   or the handle of this function may be given to RADAU via RDPSET
%   (default numerical jacobian).
% 
% [tout,yout,Stats] = radau(OdeFcn,tspan,y0) or
% [tout,yout,Stats] = radau(OdeFcn,tspan,y0,options) or
% [tout,yout,Stats] = radau(OdeFcn,tspan,y0,options,varargin)
%   solve the system like above and let know some informations on the 
%   calculations:
%  Stats.Stat gives the the following global informations. 
%   FcnNbr:     The call number to the OdeFcn.
%   JacNbr:     The call number to the jacobian. 
%   DecompNbr:  The number of LU decompositions
%   SolveNbr:   The number of non-linear system resolutions.
%   StepNbr:    The number of main steps. 
%   AccptNbr:   The number of accepted steps
%   StepRejNbr: The number of rejected steps
%   NewtRejNbr: The number of rejected Newton procedure.
%
% Stats.Dyn gives the following dynamical information 
%   Dyn.haccept_t:      Times when the step sizes are accepted
%   Dyn.haccepted_Step: Steps when the step sizes are accepted
%   Dyn.haccept:        Values of the accepted step sizes
%   Dyn.hreject_t:      Times when the steps are rejected 
%   Dyn.hreject_Step:   Steps when the step sizes are rejected
%   Dyn.hreject:        Values of the rejected step sizes
%   Dyn.Newt_t:         Times when Newton is iterated
%   Dyn.Newt_Step:      Steps when Newton is iterated
%   Dyn.NewtNbr:        Number of Newton iterations
%   Dyn.NbrStg_t:       Times when the numbers of stages are read
%   Dyn.NbrStg_Step:    Steps when the numbers of stages are read
%   Dyn.NbrStg:         Number of stages
% 
% -------------------------------------------------------------------------
        
Solver_Name = 'radau';

% Parameters initialisation

Ny  = length(y0);

% % ---------------------------
% % Default options values
% AbsTolDef           = 1e-6;       % General parameters
% RelTolDef           = 1e-3;
% InitialStepDef      = 1e-2;
% MaxStepDef          = tspan(end) - tspan(1);
% MaxNbrStepDef       = Inf;
% MassFcnDef          = [];
% EventsFcnDef        = [];
% RefineDef           = 1;
% OutputFcnDef        = [];
% OutputSelDef        = 1:Ny;
% ComplexDef          = false; 
% NbrInd1Def          = 0;
% NbrInd2Def          = 0;
% NbrInd3Def          = 0;
% JacFcnDef           = [];        % Implicit solver parameters
% JacRecomputeDef     = 1e-3;
% Start_NewtDef       = false;
% MaxNbrNewtonDef     = 7;
% NbrStgDef           = 3;
% MinNbrStgDef        = 3;    % 1 3 5 7
% MaxNbrStgDef        = 7;    % 1 3 5 7
% SafeDef             = 0.9;
% Quot1Def            = 1;
% Quot2Def            = 1.2;
% FacLDef             = 0.2;
% FacRDef             = 8.0;
% VituDef             = 0.002;
% VitdDef             = 0.8;
% hhouDef             = 1.2;
% hhodDef             = 0.8;
% GustafssonDef       = true;

% Default options values
Op.AbsTol            = options.AbsTol * ones(numel(y0),1); % 1e-6       % General parameters
Op.RelTol            = options.RelTol * ones(numel(y0),1); % 1e-3
Op.InitialStep       = options.InitialStep;
Op.MaxStep           = tspan(end) - tspan(1);
Op.MaxNbrStep        = Inf;
Op.MassFcn           = [];
Op.EventsFcn         = [];
Op.Refine            = 1;
Op.OutputFcn         = [];
Op.OutputSel         = 1:Ny;
Op.Complex           = false; 
Op.NbrInd1           = 0;
Op.NbrInd2           = 0;
Op.NbrInd3           = 0;
Op.JacFcn            = [];        % Implicit solver parameters
Op.JacRecompute      = 1e-3;
Op.Start_Newt        = false;
Op.MaxNbrNewton      = 7;
Op.NbrStg            = 3;
Op.MinNbrStg         = 3;    % 1 3 5 7
Op.MaxNbrStg         = 7;    % 1 3 5 7
Op.Safe              = 0.9;
Op.Quot1             = 1;
Op.Quot2             = 1.2;
Op.FacL              = 0.2;
Op.FacR              = 8.0;
Op.Vitu              = 0.002;
Op.Vitd              = 0.8;
Op.hhou              = 1.2;
Op.hhod              = 0.8;
Op.Gustafsson        = true;

Op.JacAnalytic = false;
Op.Stats = false;

% % ---------------------------
% OpDefault = {AbsTolDef;       RelTolDef;        InitialStepDef;  ...
%              MaxStepDef;      MaxNbrStepDef;                     ...
%              MassFcnDef;      EventsFcnDef;     RefineDef;       ...
%              OutputFcnDef;    OutputSelDef;     ComplexDef;      ...
%              NbrInd1Def;      NbrInd2Def;       NbrInd3Def;      ...
%              JacFcnDef;       JacRecomputeDef; ...
%              Start_NewtDef;   MaxNbrNewtonDef; ... 
%              NbrStgDef;       MinNbrStgDef;     MaxNbrStgDef; ...
%              SafeDef; ...
%              Quot1Def;        Quot2Def; ...
%              FacLDef;         FacRDef; ...
%              VituDef;         VitdDef;  ...
%              hhouDef;         hhodDef;  ...
%              GustafssonDef};  
% 
% OpNames = ['AbsTol          ';'RelTol          ';'InitialStep     '; ...
%            'MaxStep         ';'MaxNbrStep      ';                    ...
%            'MassFcn         ';'EventsFcn       ';'Refine          '; ...
%            'OutputFcn       ';'OutputSel       ';'Complex         '; ...
%            'NbrInd1         ';'NbrInd2         ';'NbrInd3         '; ...
%            'JacFcn          ';'JacRecompute    '; ...
%            'Start_Newt      ';'MaxNbrNewton    '; ...
%            'NbrStg          ';'MinNbrStg       ';'MaxNbrStg       '; ...           
%            'Safe            '; ...  
%            'Quot1           ';'Quot2           '; ...
%            'FacL            ';'FacR            '; ...
%            'Vitu            ';'Vitd            '; ...
%            'hhou            ';'hhod            '; ...
%            'Gustafsson      '];
           
% ---------------------------  
% Tests on inputs
% ---------------
% if (nargin < 3 )    % radau(OdeFcn,tspan,y0)
%   error ([Solver_Name,': Number of input arguments must be at least equal to 3.']);
% end   

% % nargin >= 3       % radau(OdeFcn,tspan,y0)
% if ~isa (OdeFcn, 'function_handle') && ~(exist(OdeFcn,'file') == 2)
%   error ([Solver_Name,': First input argument must be a valid function handle or name']);        
% end

if (~isvector (tspan) || length (tspan) <  2)
  error ([Solver_Name,': Third input argument must be a valid vector']);
end
% Test of tspan monotony
tspan  = tspan(:);                     % Column vector
PosNeg = sign(tspan(end) - tspan(1));  % Monotony check 
if any(PosNeg*diff(tspan)) <= 0
  error([Solver_Name,': Time vector must be strictly monotonic']);
end

if ~isvector (y0)
  error ([Solver_Name,': Initial conditions argument must be a valid vector or scalar']);
end
y0  = y0(:);
% OdeFcn tspan y options ok.

% ---------------------------
% Options test and set defaults
% ---------------------------

% if nargin < 4
%   options = [];
% end

% Arg.In = nargin > 4;
  
% options = [];
% Op  = [];
% for n = 1:size(OpNames,1)
%   Op.(deblank(OpNames(n,:))) =  ...
%              rdpget(options,deblank(OpNames(n,:)),OpDefault{n});  
% end 

% ------- ABSTOL
if ~isnumeric(Op.AbsTol)
   error([Solver_Name, ': Wrong input "AbsTol must be a positive number" ']); 
end
if any(Op.AbsTol <= 0 )
  error([Solver_Name,': Absolute tolerance are too small.']);
end
if (length(Op.AbsTol) ~= Ny) && (length(Op.AbsTol) ~=1)
  error([Solver_Name, ': AbsTol vector of length 1 or %d.',num2str(Ny)]);
end
% Op.AbsTol = Op.AbsTol + zeros(size(y0));
% ------- RELTOL
if ~isnumeric(Op.RelTol)
  error([Solver_Name, ': Wrong input "RelTol" must be a positve number" ']); 
end
if any(Op.RelTol < 10*eps)  
  error([Solver_Name,': Relative tolerance are too small.']);
end
if (length(Op.RelTol) ~= Ny) && (length(Op.RelTol) ~=1)
  error([Solver_Name, ': RelTol vector of length 1 or %d.',num2str(Ny)]);
end
% Op.RelTol = Op.RelTol + zeros(size(y0));
% ------- INITIAL STEP SIZE
if ~isnumeric( Op.InitialStep)
  error([Solver_Name, ': Wrong input "InitialStep" must be a number']);
end 
% ------- MAXIMAL STEP SIZE
if ~isnumeric(Op.MaxStep)
  error([Solver_Name, ': Wrong input "MaxStep" must be a number ']);
end
% ------- MAXIMAL NUMBER OF STEPS
if ~isnumeric(Op.MaxNbrStep)
  error([Solver_Name,': Wrong input "MaxNbrStep" must be a positive number']);
elseif Op.MaxNbrStep <= 0
  error([Solver_Name,': Wrong input "MaxNbrStep" ',num2str(Op.MaxNbrStep),', must be > 0']);
end
% ------- MASS  

% % ------- EVENTS  
% EventsExist = ~isempty(Op.EventsFcn);
% % ------- REFINE
% if ~isempty(Op.Refine)
%   if ~isnumeric(Op.Refine)
%     error([Solver_Name,': Wrong input "Refine" must empty be or a positive number']);
%   end
% end
% % ------- OUTPUTFCN 
% if ~isempty(Op.OutputFcn)
%   if isa (Op.OutputFcn,'function_handle')
%     Op.OutputFcn = func2str(Op.OutputFcn);
%   end
%   if ~(exist(Op.OutputFcn,'file') == 2)
%     error ([Solver_Name,': OutputFcn must be a valid function handle']);  
%   end  
% end
% % ------- OUTPUTSEL  
% if ~isempty(Op.OutputSel) 
%   if ~isvector (Op.OutputSel)
%     error ([Solver_Name,': OutputSel must be a scalar or a vector of positive integer']);  
%   end 
%   IndComp = 1:1:Ny;
%   for n = 1:length(Op.OutputSel)
%     if ~ismember(Op.OutputSel(n),IndComp)
%       error ([Solver_Name,': OutputSel must be an integer in 1 .. ',num2str(Ny)]);
%     end
%   end    
% end
% ------- COMPLEX
if ~islogical(Op.Complex)
  error ([Solver_Name,': Complex must be logical']);
end
% Op.RealXY = ~Op.Complex;
% ------- INDEX1 INDEX2 INDEX3
if ~isnumeric(Op.NbrInd1)
  error([Solver_Name,': Wrong input "NbrInd1" must be a number >= 0']);
elseif Op.NbrInd1 < 0
  error([Solver_Name,': Wrong input "NbrInd1" ',num2str(Op.NbrInd1),', must be > 0']);
elseif Op.NbrInd1 == 0
  Op.NbrInd1 = Ny;  
end
if ~isnumeric(Op.NbrInd2)
  error([Solver_Name,': Wrong input "NbrInd2" must be a number >= 0']);
elseif Op.NbrInd2 < 0
  error([Solver_Name,': Wrong input "NbrInd2" ',num2str(Op.NbrInd2),', must be > 0']);
end
if ~isnumeric(Op.NbrInd3)
  error([Solver_Name,': Wrong input "NbrInd3" must be a number >= 0']);
elseif Op.NbrInd3 < 0
  error([Solver_Name,': Wrong input "NbrInd3" ',num2str(Op.NbrInd3),', must be > 0']);
end
if Op.NbrInd1 + Op.NbrInd2 + Op.NbrInd3 ~= Ny
  error([Solver_Name,': Curious input for NbrInd1 + NbrInd2 + NbrInd3 ~= Ny']);
end
% ------- JACOBIAN
% if isempty(Op.JacFcn)
%   Op.JacAnalytic = false;
% else
%   Op.JacAnalytic = true; 
% end
% ------- JACRECOMPUTE
if ~isnumeric(Op.JacRecompute)
  error([Solver_Name, ': Wrong input "JacRecompute" must be numeric {0.001} ']);    
elseif abs(Op.JacRecompute) >= 1
  error([Solver_Name, ': Curious input for "JacRecompute" ', num2str(Op.JacRecompute)]);
end
% ------- START_NEWT   Predict: switch for starting values of newton iterations.
if ~isempty(Op.Start_Newt)
  if ~islogical(Op.Start_Newt)
    error ([Solver_Name,': Start_Newt must be logical'])
  end
end
% -------- MAXIMAL NUMBER OF NEWTON ITERATIONS
if ~isnumeric(Op.MaxNbrNewton)
  error([Solver_Name,': Wrong input "MaxNbrNewton" must be a positive number >= 4']);
elseif Op.MaxNbrNewton < 4
  error([Solver_Name,': Wrong input "MaxNbrNewton" ',num2str(Op.MaxNbrNewton),', must be > 4']);
end  
% ------- NUMBER OF STAGES (MIN  INITIAL  MAX)
Stage = [1 3 5 7];
if ~isnumeric(Op.NbrStg)
  error([Solver_Name,': Wrong input "NbrStg" must be in [ 1 3 5 7]']);
elseif ~ismember(Op.NbrStg,Stage)
  error([Solver_Name,': Wrong input "NbrStg" must be in [ 1 3 5 7]']);
end  
if ~isnumeric(Op.MinNbrStg)
  error([Solver_Name,': Wrong input "MinNbrStg" must be in [ 1 3 5 7]']);
elseif ~ismember(Op.MinNbrStg,Stage)
  error([Solver_Name,': Wrong input "MinNbrStg" must be in [ 1 3 5 7]']);
end  
if ~isnumeric(Op.MaxNbrStg)
  error([Solver_Name,': Wrong input "MaxNbrStg" must be in [ 1 3 5 7]']);
elseif ~ismember(Op.MaxNbrStg,Stage)
  error([Solver_Name,': Wrong input "MaxNbrStg" must be in [ 1 3 5 7]']);
end
if Op.MinNbrStg > Op.MaxNbrStg 
  error([Solver_Name,': Wrong input MaxNbrStg >= MinNbrStg please ']);
end
if Op.NbrStg < Op.MinNbrStg || Op.NbrStg > Op.MaxNbrStg
  error([Solver_Name,': Curious input for "NbrStg" ']);
end
% --------- SAFE SAFETY FACTOR IN STEP SIZE PREDICTION    % SAFE == WORK(2)
if ~isnumeric(Op.Safe)
   error([Solver_Name, ': Wrong input "Safe" must be a positive number ']);  
elseif Op.Safe <= 0.001 || Op.Safe >= 1 
  error([Solver_Name,': Curious input for Safe,' num2str(Op.Safe),' must be in ]0.001 .. 1[ ']);
end
% --- QUOT1 AND QUOT2: IF QUOT1 < HNEW/HOLD < QUOT2, STEP SIZE = CONST. 
% work(5:6) = [quot1; quot2], parameters for step size selection
%   if quot1 < hnew/hold < quot2, then the step size is not changed.
%   this saves, together with a large work(3), LU-decompositions and
%   computing time for large systems. for small systems one may have
%   quot1 = 1, quot2=1.2, for large full systems quot1 = 0.99, quot2 =
%   2 might be good. defaults quot1 = 1, quot2 = 1.2 .
if ~isnumeric(Op.Quot1)
  error([Solver_Name, ': Wrong input "Quot1"  must be numeric ']);
elseif Op.Quot1 > 1
  error([Solver_name,': Curious input for Quot1 = ', num2str(Op.Quot1), ' must be in <= 1']);
end
if ~isnumeric(Op.Quot2)
  error([Solver_Name, ': Wrong input "Quot2" must be numeric ']);
elseif Op.Quot2 < 1
  error([Solver_name,': Curious input for Quot2 = ', num2str(Op.Quot2), ' must be  > 1']);
end
% -------  FACL,FACR     PARAMETERS FOR STEP SIZE SELECTION
if ~isnumeric(Op.FacL)
  error([Solver_Name, ': Wrong input "Facl" must be numeric default 0.2 '])
end
if Op.FacL > 1.0 
   error([Solver_Name, ': Curious input for "FacL" default 0.2 ']);
end  
if ~isnumeric(Op.FacR)
  error([Solver_Name, ': Wrong input "FacR" must be numeric default 8 ']);  
end
if Op.FacR < 1.0 
   error([Solver_Name, ': Curious input for "FacR" default 8 '])
end  
% ------- VITU VITD HHOU HHOD PARAMETERS FOR ORDER SELECTION STRATEGY
if ~isnumeric(Op.Vitu)
  error([Solver_Name, ': Wrong input "Vitu" must be numeric default 0.002 ']);
end
if ~isnumeric(Op.Vitd)
  error([Solver_Name, ': Wrong input "Vitd" must be numeric default 0.8']);
end
if ~isnumeric(Op.hhou)
  error([Solver_Name, ': Wrong input "hhou" must be numeric default 1.2']);
end
if ~isnumeric(Op.hhod)
  error([Solver_Name, ': Wrong input "hhod" must be numeric default 0.8']);
end
% ------- GUSTAFSSON
if ~islogical(Op.Gustafsson)
  error([Solver_Name, ': Wrong input "Gustafsson" must be logical']);
end

% solver54 = {'radausolver',OdeFcn,tspan,y0,Op};
% if Arg.In
%   solver54 = [solver54, {varargin{:}}];
% end 

% % ---------------------------
% % Tests on outputs
% % ---------------
% % OutputNbr = abs(nargout());
% if OutputNbr == 0  
%   Op.Stats = false;
%   if isempty(Op.OutputFcn)
%     Op.OutputFcn = rdpget(options,'OutputFcn','odeplot');       
%   end  
% elseif OutputNbr == 2 
%   Op.Stats = false;
% elseif OutputNbr == 3
%   Op.Stats = true;
% elseif OutputNbr == 5 
%   Op.Stats = false;
%   if ~EventsExist
%      error([Solver_Name,': Events not set, too much output']);
%   end
% elseif OutputNbr == 6
%   Op.Stats = true;
%   if ~EventsExist 
%     error([Solver_Name,': Events and Stats must be set for 6 outputs']);
%   end
% else
%   error([Solver_Name,': Outputs number not correct']);
% end

% solverradau = {'radausolver',OdeFcn,tspan,y0,Op};
% if Arg.In
%   solverradau = [solverradau, {varargin{:}}];
% end 

% switch OutputNbr
%   case 0
%     feval(solverradau{:});
%   case 2
%     [tout,yout] = feval(solverradau{:});
%     varargout = {tout,yout};
%   case 3
%     [tout,yout,Stats] = feval(solverradau{:});
%     varargout = {tout,yout,Stats};
%   case 5
%     [tout,yout,teout,yeout,ieout] = feval(solverradau{:});
%     varargout = {tout,yout,teout,yeout,ieout};
%   case 6
%     [tout,yout,teout,yeout,ieout,Stats] = feval(solverradau{:});
%     varargout = {tout,yout,teout,yeout,ieout,Stats};
% end

[tout,yout] = radausolver(odefun,tspan,y0,Op,vars);
    
return
% ------------------------------------------------------------------------
% ------------------------------------------------------------------------
% ------------------------------------------------------------------------
% ------------------------------------------------------------------------
% function varargout = radausolver(OdeFcn,tspan,y,Op,varargin)
function [tout, yout] = radausolver(odefun,tspan,y,Op,vars)

global T TI ValP C Dd ...
   
Solver_Name = 'radausolver';
% ------- INPUT PARAMETERS

% Time properties
tspan  = tspan(:);                     % Column vector
ntspan = length(tspan);
t      = tspan(1);
tfinal = tspan(end);
PosNeg = sign(tfinal-t);

% Number of equations, y is a column vector
Ny  = length(y);

% ------- OPTIONS PARAMETERS
% General options
RelTol        = Op.RelTol;
AbsTol        = Op.AbsTol;
h             = Op.InitialStep;         % h may be positive or negative
hmax          = Op.MaxStep;             % hmax is positive
MassFcn       = Op.MassFcn;
EventsFcn     = Op.EventsFcn;
OutputFcn     = Op.OutputFcn;
OutputSel     = Op.OutputSel;
RealYN        = ~Op.Complex;
NbrInd1       = Op.NbrInd1;
NbrInd2       = Op.NbrInd2;
NbrInd3       = Op.NbrInd3;
Refine        = Op.Refine;
MaxNbrStep    = Op.MaxNbrStep;

% Parameter for implicit procedure
MaxNbrNewton  = Op.MaxNbrNewton;
Start_Newt    = Op.Start_Newt;
JacFcn        = Op.JacFcn;
JacAnalytic   = Op.JacAnalytic;
Thet          = Op.JacRecompute;   % Jacobian Recompute
Safe          = Op.Safe;
Quot1         = Op.Quot1;
Quot2         = Op.Quot2;
FacL          = 1/Op.FacL;
FacR          = 1/Op.FacR;

% Order selection parameters
NbrStg        = Op.NbrStg;
MinNbrStg     = Op.MinNbrStg;
MaxNbrStg     = Op.MaxNbrStg;
Vitu          = Op.Vitu;
Vitd          = Op.Vitd;
hhou          = Op.hhou;
hhod          = Op.hhod;
Gustafsson    = Op.Gustafsson;

% Initialisation of Stat parameters
Stat.FcnNbr     = 0;
Stat.JacNbr     = 0;
Stat.DecompNbr  = 0;
Stat.SolveNbr   = 0;
Stat.StepNbr    = 0;
Stat.AccptNbr   = 0;
Stat.StepRejNbr = 0;
Stat.NewtRejNbr = 0;

% Initialisation of Dyn parameters
Dyn.Jac_t        = [];
Dyn.Jac_Step     = [];
Dyn.haccept_t    = [];
Dyn.haccept_Step = [];
Dyn.haccept      = [];
Dyn.hreject_t    = [];
Dyn.hreject_Step = [];
Dyn.hreject      = [];
Dyn.Newt_t       = [];
Dyn.Newt_Step    = [];
Dyn.NewtNbr      = [];
Dyn.NbrStg_t     = [t];
Dyn.NbrStg_Step  = [0];
Dyn.NbrStg       = [NbrStg];
 
StatsExist = false;
if nargout == 3 || nargout == 6
  StatsExist       = true;
  Dyn.haccept_t    = [];
  Dyn.haccept_Step = [];
  Dyn.haccept      = [];
  Dyn.hreject_t    = [];
  Dyn.hreject_Step = [];
  Dyn.hreject      = [];  
end
% -------  ARGUMENTS
% Arg.In = abs(nargin) > 4;
  
% % ------- ODEFCN arguments or not  
% if isa (OdeFcn, 'function_handle')
%   OdeError  = func2str(OdeFcn);
% else
%   OdeError  = OdeFcn;
% end 
% Arg.Ode = abs(nargin(OdeFcn)) > 2;
% if Arg.Ode && ~Arg.In
%   error([Solver_Name,':  ',OdeError,', parameters are missing']);
% end

% % ------- MASSFCN with arguments or not
% if isempty(MassFcn)
%   Mass = sparse(1:Ny,1:Ny,1); % Sparse identity matrix
% else 
%   if nargin(MassFcn) == 0
%     Mass = MassFcn(); 
%   else
%     if isa (MassFcn, 'function_handle')
%       MassError  = func2str(MassFcn);
%     else
%       MassError  = MassFcn;
%     end
%     if ~Arg.In
%       error([Solver_Name,':  ',MassError,', parameters are missing']);
%     else
%       Mass = MassFcn(varargin{:});
%     end
%   end
% end

Mass = sparse(1:Ny,1:Ny,1); % Sparse identity matrix

% % ------- JACFCN with arguments or not
% if ~isempty(JacFcn)
%   if isa (JacFcn, 'function_handle')
%     JacError  = func2str(JacFcn);
%   else
%     JacError  = JacFcn;
%   end 
%   Arg.Jac = abs(nargin(JacFcn)) > 2;  
%   if Arg.Jac
%     if Arg.Jac && ~Arg.In
%       error([Solver_Name,':  ',JacError,', parameters are missing']);
%     end        
%   end
% end

% Set the output flag and output buffer
if ntspan == 2                                               
  if Refine <= 1                       % Computed points only
    OutFlag = 1;
    nBuffer = 100;
    nout    = 0;
    tout    = zeros(nBuffer,1);
    yout    = zeros(nBuffer,Ny);                             
  else
    OutFlag = 2;     
    nBuffer = 10*Refine;
    nout    = 0;
    tout    = zeros(nBuffer,1);
    yout    = zeros(nBuffer,Ny);       % Computed + refined points    
  end
else  % ntspan > 2
  OutFlag = 3;                         % Computed points  
  nout    = 0;
  nout3   = 0;
  tout = zeros(ntspan,1);
  yout = zeros(ntspan,Ny); 
  if Refine > 1
    Refine = 1;
%     warning([Solver_Name,': Refine set equal 1, because length(tspan) > 2 '])
  end
end

OutputFcnExist = false;
% if ~isempty(OutputFcn) 
%   OutputFcnExist = true;   
%   % Initialize the OutputFcn
%   OutputFcnArg = {OutputFcn,[t tfinal],y(OutputSel),'init'};
%   feval(OutputFcnArg{:}); 
% end

% Initialiation of internal constants
UnExpStepRej = false;
UnExpNewtRej = false;
Keep         = false;
ChangeNbr    = 0;
ChangeFlag   = false;
Theta        = 0;            % 
Thetat       = 0;            % Change orderparameter
Variab       = MaxNbrStg - MinNbrStg ~= 0;

InitNbrStg = true;
Coertv(MinNbrStg,MaxNbrStg,RealYN,InitNbrStg);
InitNbrStg = false;
Coertv(NbrStg,NbrStg,RealYN,InitNbrStg);

switch NbrStg
  case 1
    Nit = MaxNbrNewton - 3;
  case 3 
    Nit = MaxNbrNewton;
  case 5
    Nit = MaxNbrNewton + 5;
  case 7
    Nit = MaxNbrNewton + 10;
end
% --------------
% Integration step, step min, step max
hmaxn = min(abs(hmax),abs(tspan(end)-tspan(1))); % hmaxn positive
if abs(h) <= 10*eps 
  h = 1e-6; 
end
h     = PosNeg * min(abs(h),hmaxn);              % h sign ok 
h_old = h;
hmin  = abs(16*eps*(abs(t)+1));                  % hmin positive
hmin  = min(hmin,hmax);
hopt  = h;

if ( (t+ h*1.0001-tfinal)*PosNeg >= 0 )
  h = tfinal-t;
  Last = true;
else
  Last = false;
end

% Initialize
FacConv = 1;
N_Sing  = 0;
Reject  = false;
First   = true;

% Change tolerances
ExpmNs    = (NbrStg+1)/(2*NbrStg);
QuotTol   = AbsTol./RelTol;
RelTol1   = 0.1*RelTol.^(ExpmNs);                % RelTol > 10*eps (radau)
AbsTol1   = RelTol1.*QuotTol;
Scal      = AbsTol1 + RelTol1 .* abs(y);
hhfac     = h;
if NbrInd2 > 0      
  Scal(NbrInd1+1: NbrInd1+NbrInd2) = ...
  Scal(NbrInd1+1: NbrInd1+NbrInd2) / hhfac;
end
if NbrInd3 > 0
  Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) = ...
  Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) / hhfac^2;
end

% if Arg.Ode   
%   f0 = feval(OdeFcn,t,y,varargin{:});   % OdeFcn needs parameters
% else  
%   f0 = feval(OdeFcn,t,y);               % OdeFcn needs no parameters
% end
f0 = feval(odefun,t,y,vars);
if any(isnan(f0))
  error([Solver_Name, ': Some components of OdeFcn not a number']);
end
Stat.FcnNbr = Stat.FcnNbr+1;
[m,n]           = size(f0);
if n > 1
  error([Solver_Name,':  Function ', OdeError ,'(t,y) must return a column vector.']);
elseif m ~= Ny
  error([Solver_Name,':  Vector ', OdeError, '(t,y) must be same length as initial conditions.']);
end

cont       = zeros(Ny,NbrStg);
f          = zeros(Ny,NbrStg);  
NeedNewJac = true;
NeedNewLU  = true;
SqrtStgNy  = sqrt(NbrStg*Ny);
Newt       = 0;
%-------------------------------------------------------------------------------
EventsExist = false;
% if ~isempty(EventsFcn) 
%   EventsExist = true;
%   if nargin(EventsFcn) == 0
%     error([Solver_Name,'  EventsFcn needs input arguments']);
%   end 
%   teout = [];
%   yeout = [];
%   ieout = [];
%   [teout,yeout,ieout] = EventZeroFcn(EventsFcn,t,h,y,[],f0,'init',varargin{:});
% end

% ------- MAIN LOOP
while (Stat.StepNbr <= MaxNbrStep && PosNeg*t < PosNeg*tfinal) % ligne 849 fortran

  if abs(h) <= hmin            % h et hmin are positive 
%     warning(['Radau:Failure',' at t=%e.  Unable to meet integration ' ...
% 	           'tolerances without reducing the step size below ' ...
% 	           'the smallest value allowed (%e) at time t. \n'], t,hmin);      
    if nargout ~= 0
	  tout(1:nout) = tout(1:nout);
      yout(1:nout,:) = yout(1:nout,:);	    
    end
%     if ~isempty(OutputFcn)
%       feval(OutputFcn,[],[],'done');
%     end    
    return;
  end
  Stat.StepNbr = Stat.StepNbr + 1;
  
  FacConv = max(FacConv, eps)^0.8;   % Convergence factor      
  
  if NeedNewJac	     
    if JacAnalytic   
%       if Arg.Jac 
%         Jac = feval(JacFcn,t,y,varargin{:});
%       else
%         Jac = feval(JacFcn,t,y);
%       end  
%       if any(isnan(Jac))
%         error([Solver_Name, ': Some components of ', JacError , 'are NAN']);       
%       end
    else	                    
%       if Arg.Ode 
%         Jac = NumJac(OdeFcn,t,y,varargin{:});   % OdeFcn needs parameters
%       else
%         Jac = NumJac(OdeFcn,t,y);               % OdeFcn needs no parameters
%       end
      Jac = NumJac(odefun,t,y,vars);   % OdeFcn needs parameters
      if any(isnan(Jac))
        error('isnan(Jac): Some components of numerical jacobian are NAN');
      end
    end 

    Stat.JacNbr = Stat.JacNbr + 1; % Info1	     
    NeedNewJac      = false;
    NeedNewLU       = true;  
    if StatsExist
      Dyn.Jac_t    = [Dyn.Jac_t; t];
      Dyn.Jac_Step = [Dyn.Jac_Step;Stat.StepNbr];      
    end
  end                                % Ligne 897   Fortran

  if Variab && ~Keep  
    ChangeNbr = ChangeNbr+1;    
    NbrStgNew = NbrStg;      
    hquot     = h/h_old;
    Thetat    = min(10,max(Theta,Thetat*0.5));
    if Newt > 1 && Thetat <= Vitu && hquot < hhou && hquot > hhod         
      NbrStgNew = min(MaxNbrStg,NbrStg+2);
    end
    if Thetat >= Vitd || UnExpStepRej       
      NbrStgNew = max(MinNbrStg,NbrStg-2); 
    end    
    if ChangeNbr >= 1 && UnExpNewtRej         
      NbrStgNew = max(MinNbrStg,NbrStg-2);
    end
    if ChangeNbr <= 10          
      NbrStgNew = min(NbrStg,NbrStgNew);
    end
    ChangeFlag   = NbrStg ~= NbrStgNew;
    UnExpNewtRej = false;
    UnExpStepRej = false;
    if ChangeFlag           
      NbrStg    = NbrStgNew;        
      ChangeNbr = 1;                               
      ExpmNs    = (NbrStg+1)/(2*NbrStg);                                   
      RelTol1   = 0.1*RelTol.^(ExpmNs);     % Change tolerances    
      AbsTol1   = RelTol1.*QuotTol;
      Scal      = AbsTol1 + RelTol1 .* abs(y);       
      if NbrInd2 > 0      
        Scal(NbrInd1+1: NbrInd1+NbrInd2) = ...
        Scal(NbrInd1+1: NbrInd1+NbrInd2) / hhfac;
      end
      if NbrInd3 > 0
        Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) = ...
        Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) / hhfac^2;
      end
      
      NeedNewLU = true;
      SqrtStgNy = sqrt(NbrStg*Ny);
      switch NbrStg
        case 1
          Nit = MaxNbrNewton - 3;
        case 3 
          Nit = MaxNbrNewton;
        case 5
          Nit = MaxNbrNewton + 5;
        case 7
          Nit = MaxNbrNewton + 10;
      end
      Coertv(NbrStg,NbrStg,RealYN,InitNbrStg);   
      if StatsExist
        Dyn.NbrStg_t     = [Dyn.NbrStg_t;t];
        Dyn.NbrStg_Step  = [Dyn.NbrStg_Step;Stat.StepNbr];
        Dyn.NbrStg       = [Dyn.NbrStg;NbrStg];        
      end
    end   
  end   % if Variab
    
% ------- COMPUTE THE MATRICES E1 AND E2 AND THEIR DECOMPOSITIONS L U P 
  if NeedNewLU                                           
    U_Sing             = DecomRC(h,ValP,Mass,Jac,RealYN);
    Stat.DecompNbr = Stat.DecompNbr+1;
    NeedNewLU          = false;      % LU ok  but ...
    if U_Sing > 0                    % GOTO 78
      UnExpStepRej = true;
      N_Sing       = N_Sing + 1;
      if N_Sing >= 5
        error([Solver_Name,': Matrix is repeatedly singular at stage ',num2str(U_Sing)]);
      end
      h                   = h*0.5;
      hhfac               = 0.5;
      Reject              = true;
      Last                = false;
      NeedNewLU           = true;
      continue    % ----> While(Stat.StepNbr <= MaxNbrStep ...        
    end  % end  U_Sing > 0	       %  End GOTO 78     
  end  % if NeedNewLU
    
  if Variab && Keep                          % GOTO 30   
    Keep = false;
    ChangeNbr = ChangeNbr+1;
    if ChangeNbr >= 10 && NbrStg < MaxNbrStg
      NeedNewJac = false;
      NeedNewLu  = false;          
    end
  end
  
  if 0.1*abs(h) <= abs(t)*eps
    error([Solver_Name,' Step size too small ']);
  end
  ExpmNs    = (NbrStg+1)/(2*NbrStg);
  QuotTol   = AbsTol./RelTol;
  RelTol1   = 0.1*RelTol.^(ExpmNs);                % RelTol > 10*eps (radau)
  AbsTol1   = RelTol1.*QuotTol;
  Scal      = AbsTol1 + RelTol1 .* abs(y);
  if NbrInd2 > 0       
    Scal(NbrInd1+1:NbrInd1+NbrInd2) = ...
    Scal(NbrInd1+1:NbrInd1+NbrInd2)/hhfac;
  end
  if NbrInd3 > 0
    Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) = ...
    Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3)/(hhfac^2);  
  end  
  % Initialisation of z w cont f
  if ( First || Start_Newt || ChangeFlag )             
	  z    = zeros(Ny,NbrStg);
	  w    = zeros(Ny,NbrStg);
    cont = zeros(Ny,NbrStg);
  else  % Variables already defined 
    hquot  = h/h_old;
    cq     = C*hquot;            
    for q = 1:NbrStg
      z(:,q) = (cq(q)-C(1)+1)* cont(:,NbrStg);
      for q1 = 2:NbrStg
        z(:,q) = (z(:,q) + cont(:,NbrStg+1-q1))*(cq(q)-C(q1)+1);
      end
    end    
    for n = 1:Ny                 %   w <-> FF   cont c <-> AK   cq(1) <-> C1Q  
      w(n,:) = TI(1,:) * z(n,1);
      for q = 2 : NbrStg
        w(n,:) = w(n,:) + TI(q,:)*z(n,q);
      end                      
    end 
  end     % End of starting values                                       	                  

% ------- LOOP FOR THE SIMPLIFIED NEWTON ITERATION 
     
  % FNewt: stopping crierion for newton's method, usually chosen <1. 
  %        smaller values the code slower, but safer.
  %        Default min(0.03d0,RelTol(1)**0.5d0)
  FNewt    = max(10*eps/min(RelTol1),min(0.03,min(RelTol1)^(1/ExpmNs-1)));
  if NbrStg == 1
    FNewt = max(10*eps/min(RelTol1),0.03);
  end
  FacConv  = max(FacConv,eps).^0.8;
  Theta    = abs(Thet);
    
  Newt         = 0;
  NewtContinue = true;  
  while NewtContinue
    Reject = false;
    Newt   = Newt + 1;      
    if Newt > Nit              % GOTO 78
      UnExpStepRej        = true; 
      Stat.StepRejNbr = Stat.StepRejNbr + 1;
      Stat.NewtRejNbr = Stat.NewtRejNbr + 1;
      h                   = h*0.5;
      hhfac               = 0.5;
      Reject              = true; 
      Last                = false;
      NeedNewLU           = true;  
      break                    % GOTO 20 ou 10                 
    end
    if NeedNewLU
      continue
    end
      
 % ------ COMPUTE THE RIGHT HAND SIDE    
    for q = 1:NbrStg     % Function evaluation 
%       if Arg.Ode
%         f(:,q) = feval(OdeFcn,t+C(q)*h, y+z(:,q),varargin{:}); % OdeFcn needs parameters
%       else
%         f(:,q) = feval(OdeFcn,t+C(q)*h, y+z(:,q));         % OdeFcn needs no parameters
%       end
      f(:,q) = feval(odefun,t+C(q)*h, y+z(:,q),vars); % OdeFcn needs parameters
      if any(isnan(f))
        error([Solver_Name, ': Some components of ', OdeError , ' are NAN']);        
      end
    end
	  Stat.FcnNbr = Stat.FcnNbr + NbrStg;     

    for n = 1:Ny
      z(n,:) = TI(1,:)* f(n,1);
      for q = 2:NbrStg
        z(n,:) = z(n,:) +TI(q,:)* f(n,q);
      end
    end
% ------- SOLVE THE LINEAR SYSTEMS    % Ligne 1037                    
    z                 = Solvrad(z,w,ValP,h,Mass,RealYN); 
	  Stat.SolveNbr = Stat.SolveNbr + 1;

    % Estimate the error in the current iteration step
    NewNrm = 0;
    for q = 1: NbrStg     
      NewNrm = NewNrm + norm(z(:,q)./Scal);
    end                      
    NewNrm = NewNrm/SqrtStgNy;                       % DYNO	
% ------- TEST FOR BAD CONVERGENCE OR NUMBER OF NEEDED ITERATIONS TO LARGE        1050	   
	  if ( Newt > 1 && Newt < Nit )	   % Check for slow convergence
	    thq = NewNrm/OldNrm;
	    if ( Newt == 2 )
	      Theta = thq;
      else
	      Theta = sqrt(thq*thqold);
      end      
	    thqold = thq;                                      % 1058	 

	    if Theta < 0.99        % Convergence at least          
	      FacConv = Theta/(1-Theta);
	      dyth    = FacConv*NewNrm*Theta^(Nit-1-Newt)/FNewt;        
	      if ( dyth >= 1 )  
	        % We can not  expect convergence after Nit steps. 
	        qNewt               = max(1.e-4,min(20,dyth));
          hhfac               = 0.8*qNewt^(-1/(4+Nit-1-Newt));
	        h                   = hhfac*h; 
          Reject              = true;
          Last                = false;
          UnExpNewtRej        = hhfac <= 0.5;
          Stat.NewtRejNbr = Stat.NewtRejNbr + 1;
          Stat.StepRejNbr = Stat.StepRejNbr + 1;
          NeedNewLU           = true;  % GOTO 20 or GOTO 10  
          break            % ----> While(Stat.StepNbr <= MaxNbrStep ...     
        end
      else 	                                         % GOTO 78            
        h                   = h*0.5;
        hhfac               = 0.5;
        Reject              = true;     
        Last                = false;
        UnExpStepRej        = true;
        Stat.StepRejNbr = Stat.StepRejNbr+1;
        NeedNewLU           = true;    
        break                                        % GOTO 20 or 10 
      end  % if ( Theta < 0.99 )           
    end   % Check for slow convergence
    if NeedNewLU 
      continue
    end  
    OldNrm = max(NewNrm,eps);
    w      = w+z;                % w  <-> FF,  z  <->  ZZ     
    
    for n = 1:Ny 
      z(n,:) = T(1,:) * w(n,1);
      for q = 2:NbrStg              
        z(n,:) = z(n,:) + T(q,:) * w(n,q); 
      end
    end    
	  if (FacConv*NewNrm > FNewt)
      continue                  % GOTO 40 il faut mettre continue en Matlab
    end    
    NewtContinue = false;
  end     % Newton ok, perform one step
  
  if NeedNewLU     
    continue
  end  
  
  if StatsExist
    Dyn.Newt_t    = [Dyn.Newt_t;t];
    Dyn.Newt_Step = [Dyn.Newt_Step;Stat.StepNbr];
    Dyn.NewtNbr   = [Dyn.NewtNbr;Newt];
  end  
  
  % ------ ERROR ESTIMATION     
  % At this point the Newton iteration converged to a solution. 
  % Our next task is to estimate the local error.
%   [err,Stat] = Estrad(z,Dd,h,Mass,Scal,f0, ...
%                           First, Reject,Stat,OdeFcn,t,y,varargin{:});
  [err,Stat] = Estrad(odefun,z,Dd,h,Mass,Scal,f0, ...
                          First, Reject,Stat,t,y,vars);
   
% ------- COMPUTATION OF HNEW                                       % 1561
% ------- WE REQUIRE .2<=HNEW/H<=8. 1/FacL <= hnew/h <= 1/FacR        
  fac  = min(Safe, (2*Nit+1)/(2*Nit+Newt));
  quot = max(FacR,min(FacL,(err^(1/NbrStg+1))/fac));
  hnew = h/quot;
% ------- IS THE ERROR SMALL ENOUGH ?    
  if ( err < 1)                  % ------- STEP IS ACCEPTED       
    First             = false;  
    Stat.AccptNbr = Stat.AccptNbr+1;
    if StatsExist
      Dyn.haccept_t    = [Dyn.haccept_t;t];
      Dyn.haccept_Step = [Dyn.haccept_Step;Stat.StepNbr];
      Dyn.haccept      = [Dyn.haccept;h];
      Dyn.NbrStg_t     = [Dyn.NbrStg_t;t];
      Dyn.NbrStg_Step  = [Dyn.NbrStg_Step;Stat.StepNbr];
      Dyn.NbrStg       = [Dyn.NbrStg;NbrStg];
    end
% ------- PREDICTIVE CONTROLLER OF GUSTAFSSON  
    if (Gustafsson && ~ChangeFlag)    
      if (Stat.AccptNbr > 1)
        facgus = (hacc/h)*(err^2/erracc)^(1/(NbrStg+1))/Safe;
        facgus = max(FacR,min(FacL,facgus));
        quot   = max(quot,facgus);
        hnew   = h/quot;
      end
      hacc   = h;
      erracc = max(1.0e-2,err);
    end
    h_old = h;    
    t     = t+h
    % ----- UPDATE SCALING                                       % 1587                 
    Scal = AbsTol1 + RelTol1 .* abs(y);
    if NbrInd2 > 0      
      Scal(NbrInd1+1:NbrInd1+NbrInd2) = ...
      Scal(NbrInd1+1:NbrInd1+NbrInd2)/hhfac;
    end
    if NbrInd3 
      Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3) = ...
      Scal(NbrInd1+NbrInd2+1:NbrInd1+NbrInd2+NbrInd3)/(hhfac^2);  
    end  
    
    % Solution 
    y = y+z(:,NbrStg);    
    % Collocation polynomial    
    cont(:,NbrStg) = z(:,1)/C(1);
    for q = 1:NbrStg-1
      Fact      = 1/(C(NbrStg-q) - C(NbrStg-q+1));
      cont(:,q) = (z(:,NbrStg-q) - z(:,NbrStg-q+1))*Fact;
    end
    for jj = 2:NbrStg
      for k = NbrStg:-1:jj
        if NbrStg - k ==0
          Fact = 1/( - C(jj) );
        else              
          Fact = 1/(C(NbrStg-k) - C(NbrStg - k + jj) );
        end
        cont(:,k) = (cont(:,k) - cont(:,k-1))*Fact;
      end
    end
    
%     if EventsExist
%       [te,ye,ie,Stop] = EventZeroFcn(EventsFcn,t,h,y,cont,[],'',varargin{:});
%       if ie > 0
%         teout = [teout;te];
%         yeout = [yeout;ye'];
%         ieout = [ieout;ie];
%         if Stop 
%           t = te;
%           y = ye;
%           break 
%         end
%       end      
%     end
        
%     if nargout > 0
      switch OutFlag        
        case 1          % Computed points, no Refinement 
          nout = nout + 1;
          if nout > length(tout)
            tout = [tout;zeros(nBuffer,1)];
            yout = [yout;zeros(nBuffer,Ny)];  
          end
          tout(nout)   = t;
          yout(nout,:) = y';           
        case 2          % Computed points, with refinement 
          oldnout      = nout;
          nout         = nout + Refine;
          S            = (1:Refine-1)' / Refine;
          tout         = [tout; zeros(Refine,1)]; 	
          yout         = [yout; zeros(Refine,Ny)];
          ii           = oldnout+1:nout-1;
          tinterp      = t+h*S - h;
          yinterp      = ntrprad(tinterp,t,y,h,cont);
          tout(ii)     = tinterp;
          yout(ii,:)   = yinterp(1:Ny,:)';
          tout(nout)   = t;
          yout(nout,:) = y';                                     
        case 3          % Output only at tspan points
          ntspan = length(tspan);
          PosNeg = sign(tspan(end) - tspan(1));
          next   = nout+1;
          while next <= ntspan
            if PosNeg * (t - tspan(next)) < 0
	            break;
	          elseif t == tspan(next)
	            nout         = nout + 1;
              tout(nout)   = t;
	            yout(nout,:) = y(OutputSel)';	  
	            break;
            end
            nout         = nout + 1;     % tout and yout are already allocated
            tout(nout)   = tspan(next);  
            yinterp      = ntrprad(tspan(next),t,y,h,cont);
            yout(nout,:) = yinterp(OutputSel,:)';        
            next         = next + 1; 
          end
      end     
%     end

%     if ~isempty(OutputFcn)
%       switch OutFlag      % Output function required
%         case 1            % Computed points, no Refinement 
%           feval(OutputFcn,t,y(OutputSel)','');
%         case 2            % Computed points, with refinement 
%           [tout2,yout2] = OutFcnSolout2(t,h,y,cont,OutputSel,Refine);
%           for k = 1 : length(tout2)
%             feval(OutputFcn,tout2(k),yout2(k,:),'');                    
%           end       
%         case 3            % Output only at tspan points
%           [nout3,tout3,yout3] = OutFcnSolout3(nout3,t,h,y,cont,OutputSel,tspan); 
%           if ~isempty(tout3)
%             for k = 1 : length(tout3)
%               feval(OutputFcn,tout3(k),yout3(k,:),'');   
%             end
%           end
%       end  
%     end
    
    NeedNewJac = true;      % Ligne 1613
    if (Last),
      h = hopt;             % Est-ce dfini????
      Stat.StepRejNbr = Stat.StepRejNbr + 1;
      break;
    end
%     if Arg.Ode   
%       f0 = feval(OdeFcn,t,y,varargin{:});    % OdeFcn needs parameters  
%     else
%       f0 = feval(OdeFcn,t,y);            % OdeFcn needs no parameters
%     end
    f0 = feval(odefun,t,y,vars);    % OdeFcn needs parameters 
    if any(isnan(f0))
      error([Solver_Name, ': Some components of ', OdeError , ' are NAN']);      
    end
    Stat.FcnNbr = Stat.FcnNbr+1;
    hnew            = PosNeg * min(abs(hnew),abs(hmaxn));
    hopt            = PosNeg * min(abs(h),abs(hnew));
  
    if (Reject)
      hnew = PosNeg*min(abs(hnew),abs(h)); 
    end
    Reject = false; 
    if ( (t+hnew/Quot1-tfinal)*PosNeg >= 0 )
      h    = tfinal-t;
      Last = true;                 
    else
      qt    = hnew/h;                                % (8.21) page 134
      hhfac = h;
      if Theta <= Thet && qt >= Quot1 && qt <= Quot2 
        Keep       = true;
        NeedNewJac = false;
        NeedNewLU  = false;
        continue
      end
      h = hnew;
    end
    hhfac     = h;
    NeedNewLU = true;
    if Theta <= Thet       
      NeedNewJac = false;           
    end  
    
  else %  --- STEP IS REJECTED       
    if StatsExist
      Dyn.hreject_t    = [Dyn.hreject_t;t];
      Dyn.hreject_Step = [Dyn.hreject_Step;Stat.StepNbr];
      Dyn.hreject      = [Dyn.hreject;h];           
    end
    Reject = true;
    Last   = false;          
    if First
      h     = h/10;
      hhfac = 0.1;
    else
      hhfac = hnew/h;
      h     = hnew;
    end      
    if ( Stat.AccptNbr >= 1 )
      Stat.StepRejNbr = Stat.StepRejNbr+1;      
    end	     
    NeedNewLU = true;      
  end        
   
end     % while Stat.StepNbr <= MaxNbrStep && PosNeg*t < PosNeg*tfinal

if StatsExist
  Stats.Stat = Stat;
  Stats.Dyn  = Dyn;
end

OutputNbr = abs(nargout);

if OutputNbr > 0 
  nout         = nout + 1;
  tout(nout)   = t;
  yout(nout,:) = y';
  tout(1:nout) = tout(1:nout);
  yout(1:nout,:) = yout(1:nout,:);
%   varargout    = {tout,yout};
%   if EventsExist    
%     varargout = [varargout,{teout,yeout,ieout}];
%   end
%   if StatsExist
%     varargout = [varargout,{Stats}];
%   end      
end  
 
% if OutputFcnExist   % Close the OutputFcn        
%   OutputFcnArg = {OutputFcn,t,y(OutputSel)',''};
%   feval(OutputFcnArg{:}); 
%   OutputFcnArg = {OutputFcn,t,y(OutputSel)','done'};
%   feval(OutputFcnArg{:});
% end

% if Stat.StepNbr > MaxNbrStep  % GOTO 178
%   warning([' More than MaxNbrStep = ',num2str(MaxNbrStep),' steps are needed']) 
% end


return


function yinterp = ntrprad(tinterp,t,y,h,cont)
global C
%NTRPRAD Interpolation helper function for RADAU.
%   YINTERP = NTRPRAD(TINTERP,T,Y,TNEW,YNEW,H,F) uses data computed in RADAU
%   to approximate the solution at time TINTERP.
%  fprintf('yinterp = ntrprad(tinterp,t,y,tnew,ynew,h,cont)\n');
Cm     = C-1;
NbrStg = length(C);
s      = ((tinterp - t) / h)';
m      = length(tinterp);
Ny     = length(y);

yi = (s(ones(Ny,1),:)-Cm(1)).*cont(:,zeros(m,1)+NbrStg);
for q = 1:NbrStg-1
  yi = (s(ones(Ny,1),:)-Cm(q+1)).*(yi+cont(:,zeros(m,1)+NbrStg-q));
end
for k = 1: m
  yinterp(:,k)= yi(:,k) + y;
end
return


% function Jac = NumJac(OdeFcn,t,y,varargin)
function Jac = NumJac(odefun,t,y,vars)
Fcn_Name = 'NumJac';
% Arg.Ode =  abs(nargin(OdeFcn)) > 2;
% if Arg.Ode
%   yPrime0 = feval(OdeFcn,t,y,varargin{:}); 
% else
%   yPrime0 = feval(OdeFcn,t,y);
% end
yPrime0 = feval(odefun,t,y,vars);
if any(isnan(yPrime0))
%   if isa (OdeFcn, 'function_handle')
%     FcnError  = func2str(OdeFcn);
%   else
%     FcnError  = OdeFcn;
%   end 
  error('isnan(yPrime0): Some components of are NAN');
end

Ny  = length(y);
Jac = sparse(zeros(Ny));
dy  = sparse(zeros(size(y)));

for ny = 1:Ny
  Delta = sqrt(eps*max(1e-5,abs(y(ny))));  
  dy(ny)= Delta;
%   if Arg.Ode
%     yPrime1 = feval(OdeFcn,t,y+dy,varargin{:});
%   else
%     yPrime1 = feval(OdeFcn,t,y+dy);
%   end
  yPrime1 = feval(odefun,t,y+dy,vars);
  if any(isnan(yPrime1))
%     if isa (OdeFcn, 'function_handle')
%       FcnError  = func2str(OdeFcn);
%     else
%       FcnError  = OdeFcn;
%     end 
    error('isnan(yPrime1): Some components of are NAN');
  end
  Jac(:,ny) = (yPrime1-yPrime0)/Delta; 
  dy(ny)    = 0;  
end
return
 
function  U_Sing = DecomRC(h,ValP,Mass,Jac,RealYN)
global L U P 

valp   = ValP/h;
NbrStg = length(valp);

if RealYN 
  NuMax            = (NbrStg+1)/2; 
  B                =  valp(1)*Mass-Jac;  
  [L(:,:,1),U(:,:,1),P(:,:,1)]=lu(B);   
  if NbrStg > 1
    for q = 1:(NbrStg-1)/2
      q1                  = q+1;
      q2                  = 2*q;
      q3                  = q2+1;     
      B                   = (valp(q2) + 1i*valp(q3))*Mass-Jac;    
      [L(:,:,q1),U(:,:,q1),P(:,:,q1)]=lu(B);
    end
  end           
else   % complex
  NuMax = NbrStg;
  for q = 1:NbrStg      
    [L(:,:,q),U(:,:,q),P(:,:,q)] = lu( valp(q)*Mass-Jac );
  end
end

U_Sing = 0;
for q = 1:NuMax
  if (any(abs(diag(U(:,:,q))))<eps) 
    fprintf('WARNING: g*Mass-Jac is singular.\n');
    U_Sing = NbrStg;
  end
end

return
 
function z = Solvrad(z,w,ValP,h,Mass,RealYN)
% Solve the linear systems
global U L P 

valp   = ValP/h;
NbrStg = length(ValP);

if ~isempty(Mass)
  Mw = Mass*w;
else
  Mw = w;
end
if RealYN
  z(:,1) = z(:,1) - valp(1)*Mw(:,1);    %real  
  z(:,1) = pinv(U(:,:,1))*(pinv(L(:,:,1))*(P(:,:,1)*z(:,1)));
  if NbrStg > 1
    for q = 1:(NbrStg-1)/2
      q1 = q+1;
      q2 = 2*q;
      q3 = q2+1;
      z2 = z(:,q2) - valp(q2)*Mw(:,q2) + valp(q3)*Mw(:,q3);
	    z3 = z(:,q3) - valp(q3)*Mw(:,q2) - valp(q2)*Mw(:,q3);    
      z2 = pinv(U(:,:,q1))*(pinv(L(:,:,q1))*(P(:,:,q1)*(z2+1i*z3)));
      z(:,q2) = real(z2);
      z(:,q3) = imag(z2);
    end
  end
else
  for q = 1:NbrStg     
    z(:,q) = z(:,q)-valp(q)*Mw(:,q);
    z(:,q) = U(:,:,q)\(L(:,:,q)\(P(:,:,q)*z(:,q)));
  end
end
return

% function [err,Stat] = Estrad(z,Dd,h,Mass,Scal,f0, ...
%                                  First, Reject,Stat,...
%                                  OdeFcn,t,y,varargin)
function [err,Stat] = Estrad(odefun,z,Dd,h,Mass,Scal,f0, ...
                                 First, Reject,Stat,...
                                 t,y,vars)  
global U L P 
SqrtNy = sqrt(length(y));

temp = z*(Dd/h);
if ~isempty(Mass) 
  temp = Mass*temp;
end

err_v = U(:,:,1)\(L(:,:,1)\(P(:,:,1)*(f0+temp)));
err = norm(err_v./Scal,2);
err = max(err/SqrtNy,1e-10);

if err < 1
  return
end
if  First || Reject
%   Arg.Ode =  abs(nargin(OdeFcn)) > 2;
%   if Arg.Ode
%     err_v = feval(OdeFcn,t,y+err,varargin{:});
%   else
%     err_v = feval(OdeFcn,t,y+err);
%   end
  err_v = feval(odefun,t,y+err,vars);
  Stat.FcnNbr = Stat.FcnNbr + 1;  
  err_v = U(:,:,1)\(L(:,:,1)\(P(:,:,1)*(err_v+temp)));
  err = norm(err_v./Scal,2);
  err = max(err/SqrtNy,1e-10);  
end

% Computed points, with Refinement
function [tout,yout] = OutFcnSolout2(t,h,y,cont,OutputSel,Refine)
S              = (1:Refine-1)' / Refine;
tout           = zeros(Refine,1); 	
yout           = zeros(Refine,length(OutputSel));
ii             = 1:Refine-1;
tinterp        = t+h*S - h;
yinterp        = ntrprad(tinterp,t,y,h,cont);
tout(ii)       = tinterp;
yout(ii,:)     = yinterp(OutputSel,:)';
tout(Refine)   = t;
yout(Refine,:) = y(OutputSel)';

% Output only at tspan points 
function [nout,tout,yout] = OutFcnSolout3(nout,t,h,y,cont,OutputSel,tspan)
PosNeg = sign(tspan(end) - tspan(1));
tout   = [];
yout   = [];
if nout == 0
  nout = 1;
end
while (t - tspan(nout)) * PosNeg > 0 % tout = t-vec for interpolation
  tout = [tout;tspan(nout)];
  nout = nout+1;
end
if t == tspan(nout)
  tout = [tout;t];
end

if ~isempty(tout)
  yinterp = ntrprad(tout,t,y,h,cont);
  yout    = [yout;yinterp(OutputSel,:)'];
end
return
% -------------------------------------------------------------------
% -------------------------------------------------------------------

% function [tout,yout,iout,Stop] = EventZeroFcn(EvFcn,t,h,y,...
%                                  cont,f0,Flag,varargin)
% % EventZeroFcn evaluate, if it exist, the value of the zero of the Events
% % function. The t interval is [t, t+h]. The method is the Regula Falsi
% % of order 2.
% 
% persistent t1 E1v 
% 
% tout = [];
% yout = [];
% iout = [];
% Stop = 0;
% t2   = t; 
% 
% EvFcnArgNbr = abs(nargin(EvFcn));
% switch EvFcnArgNbr
%   case 1   
%     EvFcnVar = {EvFcn,t2};
%   case 2
%     EvFcnVar = {EvFcn,t2,y};
%   otherwise
%     EvFcnVar = {EvFcn,t2,y,varargin{:}};
% end
%  
% if strcmp(Flag,'init')
%   [E1v,Stopv,Slopev] = feval(EvFcnVar{:});
%   t1                 = t;
%   Ind = find(E1v == 0);
%   if ~isempty (Ind)
%     IndL = length(Ind);
%     for k = 1 : IndL
%       if sign(f0(Ind(k))) == Slopev(k)
%         tout = t;
%         yout = y';
%         iout = Ind(k); 
%         Stop = false;
%       end
%     end
%   end
%   return
% end
% 
% [E2v,Stopv,Slopev] = feval(EvFcnVar{:});
% IterMax = 50; 
% 
% %tol     = 1e-6;                                  % --> ~1e-7
% %tol     = 1024*max([eps,eps(t2),eps(t1)]);       % --> ~1e-12
% %tol     = 131072 * max([eps,eps(t2),eps(t1)]);   % --> ~1e-10
% tol     = 65536 * max([eps,eps(t2),eps(t1)]);    % --> ~1e-9
% 
% tol     = min(tol, abs(t2 - t1));
% tAbsTol = tol; 
% tRelTol = tol;
% EAbsTol = tol;
% 
% Indk = 0;
% NE1v = length(E1v);
% for k = 1: NE1v 
%   t1N = t1;
%   t2N = t2;
%   E1  = E1v(k);
%   E2  = E2v(k);  
%   E12 = E1*E2;
%   p12 = (E2-E1)/(t2N-t1N);
%     
%   if (E12 < 0) && (p12*Slopev(k) >= 0) % An event is there    
%     Indk = Indk + 1;   % Buffer index  
%     Done = false;
%     Iter = 0;    
%     tNew = t2N;
%     yNew = y;
%     ENew = E2; 
%     
%     while ~Done      
%       Iter = Iter + 1;     
%       if Iter >= IterMax 
%         warning('EventZeroFcn: iteration number > maximal iteration number \n')    
%         break
%       end
%       tRel = abs(t1N-t2N)*tRelTol < max(abs(t1N),abs(t2N));
%       tAbs = abs(t1N-t2N) < tAbsTol;
%       if (abs(ENew) < EAbsTol && tRel && tAbs) || (abs(ENew) == 0)   %Ok        
%         break
%       else          
%         % Dichotomy or pegasus
%         if abs(E1) < 200*EAbsTol || abs(E2) < 200*EAbsTol              
%           tNew = 0.5*(t1N + t2N);    
%         else  
%           % tNew = (t1N*E2-t2N*E1)/(E2-E1);
%           dt   = -ENew/(E2-E1)*(t2N-t1N);
%           tNew = tNew + dt;
%         end
%         yNew = ntrprad(tNew,t,y,h,cont);
%         switch EvFcnArgNbr
%           case 1   
%             EvFcnVar = {EvFcn,tNew};
%           case 2
%             EvFcnVar = {EvFcn,tNew,yNew};
%           otherwise
%             EvFcnVar = {EvFcn,tNew,yNew,varargin{:}};
%         end   
%         ENew = feval(EvFcnVar{:});  
%         ENew = ENew(k);
%         if ENew * E2 < 0 
%           t1N = t2N;
%           E1  = E2;
%         else
%           E1  = E1*E2/(E2+ENew);
%         end
%         t2N = tNew;
%         E2  = ENew;        
%       end
%     end
%     ioutk(Indk)   = k;   
%     toutk(Indk)   = tNew;
%     youtk(Indk,:) = yNew;
%     Stopk(Indk)   = Stopv(k);
%   end
%   if exist('toutk')
%     if t1 < t2
%       [mt,Ind] = min(toutk);
%     else
%       [mt,Ind] = max(toutk);
%     end
%     iout = ioutk(Ind(1));
%     tout = mt(1);
%     yout = youtk(Ind(1),:)';
%     Stop = Stopk(Ind(1));
%   end
% end
% t1  = t2;
% E1v = E2v;
% % -------------------------------------------------------------------
% % -------------------------------------------------------------------

function Coertv(MinNbrStg,MaxNbrStg,RealYN,Init)

global T   TI   C  ValP  Dd  ...
       T_1 TI_1 C1 ValP1 Dd1 ...
       T_3 TI_3 C3 ValP3 Dd3 ...
       T_5 TI_5 C5 ValP5 Dd5 ...
       T_7 TI_7 C7 ValP7 Dd7  
             
Fcn_Name = 'Coertv';

% coder.varsize('T', 'TI', [7, 7]);
% coder.varsize('C', 'ValP', 'Dd', [7, 1]);

if Init
  for NbrStg = MinNbrStg:MaxNbrStg
    switch NbrStg
      case 1
        Coertv1(RealYN);
      case 3
        Coertv3(RealYN);
      case 5
        Coertv5(RealYN);
      case 7
        Coertv7(RealYN);
    end
  end
else
  if MinNbrStg ~= MaxNbrStg
    error('MinNbrStg ~= MaxNbrStg: The Number of steps is wrong');
  end
  NbrStg = MinNbrStg;
  switch NbrStg
    case 1
      T = T_1; TI = TI_1; ValP = ValP1; C = C1; Dd = Dd1;
    case 3
      T = T_3; TI = TI_3; ValP = ValP3; C = C3; Dd = Dd3;
    case 5
      T = T_5; TI = TI_5; ValP = ValP5; C = C5; Dd = Dd5;
    case 7
      T = T_7; TI = TI_7; ValP = ValP7; C = C7; Dd = Dd7;
  end
end
return

function Coertv1(RealYN)
% Implict Euler'method
global T_1 TI_1 C1 ValP1 Dd1
C1    =  1;
T_1   =  1;
TI_1  =  1;
ValP1 =  1;
Dd1   = -1;

function Coertv3(RealYN)
% See page 78 in Stiff differential Equations:  Radau IIa order 5
% Butcher representation
%  C(1) |  A(1,1)  A(1,2)  A(1,3)
%  C(1) |  A(2,1)  A(2,2)  A(2,3)
%  C(1) |  A(3,1)  A(3,2)  A(3,3)
%  --------------------------
%          B(1)    B(2)    B(3)
% See page 131 in Stiff differential Equations, matrices T and TI:
% are defined such as:
% inv(T)*inv(A)*T = [ gamma 0 0; 0 Alpha -Beta; 0 Beta Alpha]
% where gamma, Alpha +- i*Beta are eigenvalue of A, in the case, 
% Radau IIa order 5. 
global T_3 TI_3 C3 ValP3 Dd3 ...       
%        Ta3 TIa3
   
ValP = [0, 0, 0];
Dd = ValP;
T3 = complex(zeros(3,3), 0);
TI3 = T3;
   
Sq6   = sqrt(6);
C3(1) = (4.0 - Sq6)/10.0;
C3(2) = (4.0 + Sq6)/10.0;
C3(3) = 1;

Dd(1) = -(13 + 7*Sq6)/3;             % See Reymond pages 11, 12
Dd(2) = (-13 + 7*Sq6)/3; 
Dd(3) = -1.0/3; 
Dd3   = Dd(:);

if RealYN
  T3(1,1)  =  9.1232394870892942792e-02;
  T3(1,2)  = -0.14125529502095420843;
  T3(1,3)  = -3.0029194105147424492e-02;
  T3(2,1)  =  0.24171793270710701896;
  T3(2,2)  =  0.20412935229379993199;
  T3(2,3)  =  0.38294211275726193779;
  T3(3,1)  =  0.96604818261509293619;
  T3(3,2)  =  1;
  T3(3,3)  =  0;
  TI3(1,1) =  4.3255798900631553510;
  TI3(1,2) =  0.33919925181580986954;
  TI3(1,3) =  0.54177053993587487119;
  TI3(2,1) = -4.1787185915519047273;
  TI3(2,2) = -0.32768282076106238708;
  TI3(2,3) =  0.47662355450055045196;
  TI3(3,1) = -0.50287263494578687595;
  TI3(3,2) =  2.5719269498556054292;
  TI3(3,3) = -0.59603920482822492497;
  
  ST9      = 9^(1/3);
  ValP(1) = (6.0+ST9*(ST9-1))/30.0;     % Page 132,  U1 in Fortran
  ValP(2) = (12.0-ST9*(ST9-1))/60.0;    % Real part of eigen value of A
  ValP(3) = ST9*(ST9+1)*sqrt(3.0)/60.0; % Imag part of eigen value of A
  Cno      = ValP(2)^2+ValP(3)^2;      % Inverse of eigen value
  ValP3(1) = 1.0/ValP(1);
  ValP3(2) = ValP(2)/Cno;
  ValP3(3) = ValP(3)/Cno;    
else  
  % A, matrix construction from the C values (Hairer .. page 78) 
  CP3 = [1  C3(1) C3(1)^2 
         1  C3(2) C3(2)^2 
         1  C3(3) C3(3)^2 ];
     
  CQ3 = [C3(1) C3(1)^2/2  C3(1)^3/3 
         C3(2) C3(2)^2/2  C3(2)^3/3 
         C3(3) C3(3)^2/2  C3(3)^3/3 ];
       
  A3  = CQ3 / CP3;
  [T3,D3]  = eig(A3);
  D3       = eye(3)/D3;
  TI3      = T3\eye(3);
  ValP3(1) = D3(1,1);
  ValP3(2) = D3(2,2);
  ValP3(3) = D3(3,3); 
end 

T_3(1,:) = [T3(1,1),T3(2,1),T3(3,1)];
T_3(2,:) = [T3(1,2),T3(2,2),T3(3,2)];
T_3(3,:) = [T3(1,3),T3(2,3),T3(3,3)]; 

TI_3(1,:) = [TI3(1,1),TI3(2,1),TI3(3,1)];
TI_3(2,:) = [TI3(1,2),TI3(2,2),TI3(3,2)];
TI_3(3,:) = [TI3(1,3),TI3(2,3),TI3(3,3)];

return

function Coertv5(RealYN) 
global T_5 TI_5 C5 ValP5 Dd5

T5 = complex(zeros(5,5), 0);
TI5 = T5;

% See page 78 in Stiff differential Equations:  Radau IIa order 5
% Butcher representation
%  C(1) |  A(1,1)  A(1,2)  A(1,3)
%  C(1) |  A(2,1)  A(2,2)  A(2,3)
%  C(1) |  A(3,1)  A(3,2)  A(3,3)
%  --------------------------
%          B(1)    B(2)    B(3)
% See page 131 in Stiff differential Equations, matrices T and TI:
% are defined such as:
% inv(T)*inv(A)*T = [ gamma 0 0; 0 Alpha -Beta; 0 Beta Alpha]
% where gamma, Alpha +- i*Beta are eigenvalue of A, in the case, 
% Radau IIa order 9. 

C5(1)  =  0.5710419611451768219312e-01;
C5(2)  =  0.2768430136381238276800e+00;
C5(3)  =  0.5835904323689168200567e+00;
C5(4)  =  0.8602401356562194478479e+00;
C5(5)  =  1.0;

Dd5(1) = -0.2778093394406463730479D+02;
Dd5(2) =  0.3641478498049213152712D+01;
Dd5(3) = -0.1252547721169118720491D+01;
Dd5(4) =  0.5920031671845428725662D+00;
Dd5(5) = -0.2000000000000000000000D+00;
Dd5    = Dd5(:);

if RealYN
  T5(1,1)   = -0.1251758622050104589014D-01;
  T5(1,2)   = -0.1024204781790882707009D-01;
  T5(1,3)   =  0.4767387729029572386318D-01;
  T5(1,4)   = -0.1147851525522951470794D-01;
  T5(1,5)   = -0.1401985889287541028108D-01;
  T5(2,1)   = -0.1491670151895382429004D-02;
  T5(2,2)   =  0.5017286451737105816299D-01;
  T5(2,3)   = -0.9433181918161143698066D-01;
  T5(2,4)   = -0.7668830749180162885157D-02;
  T5(2,5)   =  0.2470857842651852681253D-01;
  T5(3,1)   = -0.7298187638808714862266D-01;
  T5(3,2)   = -0.2305395340434179467214D+00;
  T5(3,3)   =  0.1027030453801258997922D+00;
  T5(3,4)   =  0.1939846399882895091122D-01;
  T5(3,5)   =  0.8180035370375117083639D-01;
  T5(4,1)   = -0.3800914400035681041264D+00;
  T5(4,2)   =  0.3778939022488612495439D+00;
  T5(4,3)   =  0.4667441303324943592896D+00;
  T5(4,4)   =  0.4076011712801990666217D+00;
  T5(4,5)   =  0.1996824278868025259365D+00;
  T5(5,1)   = -0.9219789736812104884883D+00;
  T5(5,2)   =  1;
  T5(5,3)   =  0;
  T5(5,4)   =  1;
  T5(5,5)   =  0;
  
  TI5(1,1)  = -0.3004156772154440162771D+02;
  TI5(1,2)  = -0.1386510785627141316518D+02;
  TI5(1,3)  = -0.3480002774795185561828D+01;
  TI5(1,4)  =  0.1032008797825263422771D+01;
  TI5(1,5)  = -0.8043030450739899174753D+00;
  TI5(2,1)  =  0.5344186437834911598895D+01;
  TI5(2,2)  =  0.4593615567759161004454D+01;
  TI5(2,3)  = -0.3036360323459424298646D+01;
  TI5(2,4)  =  0.1050660190231458863860D+01;
  TI5(2,5)  = -0.2727786118642962705386D+00;
  TI5(3,1)  =  0.3748059807439804860051D+01;
  TI5(3,2)  = -0.3984965736343884667252D+01;
  TI5(3,3)  = -0.1044415641608018792942D+01;
  TI5(3,4)  =  0.1184098568137948487231D+01;
  TI5(3,5)  = -0.4499177701567803688988D+00;
  TI5(4,1)  = -0.3304188021351900000806D+02;
  TI5(4,2)  = -0.1737695347906356701945D+02;
  TI5(4,3)  = -0.1721290632540055611515D+00;
  TI5(4,4)  = -0.9916977798254264258817D-01;
  TI5(4,5)  =  0.5312281158383066671849D+00;
  TI5(5,1)  = -0.8611443979875291977700D+01;
  TI5(5,2)  =  0.9699991409528808231336D+01;
  TI5(5,3)  =  0.1914728639696874284851D+01;
  TI5(5,4)  =  0.2418692006084940026427D+01;
  TI5(5,5)  = -0.1047463487935337418694D+01;  
 
  ValP5(1) =  0.6286704751729276645173D+01;  % U1 in Fortran
  ValP5(2) =  0.3655694325463572258243D+01;  % Ce sont les val propres
  ValP5(3) =  0.6543736899360077294021D+01;  % de inv(A)
  ValP5(4) =  0.5700953298671789419170D+01;
  ValP5(5) = 0.3210265600308549888425D+01; 
  % Le signe - ci-dessus n'existe pas dans la version fortran.
  % Il amliore le changement de "stage" dans Robertson
  
else
  
  CP5  = [1  C5(1) C5(1)^2 C5(1)^3 C5(1)^4
          1  C5(2) C5(2)^2 C5(2)^3 C5(2)^4
          1  C5(3) C5(3)^2 C5(3)^3 C5(3)^4
          1  C5(4) C5(4)^2 C5(4)^3 C5(4)^4
          1  C5(5) C5(5)^2 C5(5)^3 C5(5)^4];
      
  CQ5 = [C5(1) C5(1)^2/2 C5(1)^3/3 C5(1)^4/4 C5(1)^5/5
         C5(2) C5(2)^2/2 C5(2)^3/3 C5(2)^4/4 C5(2)^5/5
         C5(3) C5(3)^2/2 C5(3)^3/3 C5(3)^4/4 C5(3)^5/5
         C5(4) C5(4)^2/2 C5(4)^3/3 C5(4)^4/4 C5(4)^5/5
         C5(5) C5(5)^2/2 C5(5)^3/3 C5(5)^4/4 C5(5)^5/5];

  A5 = CQ5 / CP5 ;

  [T5,D5]  = eig(A5);
  D5       = eye(5)/D5;
  TI5      = T5\eye(5);
  ValP5(1) = D5(1,1);
  ValP5(2) = D5(2,2);
  ValP5(3) = D5(3,3);
  ValP5(4) = D5(4,4);
  ValP5(5) = D5(5,5);
end

T_5(1,:) = [T5(1,1),T5(2,1),T5(3,1),T5(4,1),T5(5,1)];
T_5(2,:) = [T5(1,2),T5(2,2),T5(3,2),T5(4,2),T5(5,2)];
T_5(3,:) = [T5(1,3),T5(2,3),T5(3,3),T5(4,3),T5(5,3)];
T_5(4,:) = [T5(1,4),T5(2,4),T5(3,4),T5(4,4),T5(5,4)];
T_5(5,:) = [T5(1,5),T5(2,5),T5(3,5),T5(4,5),T5(5,5)];

TI_5(1,:) = [TI5(1,1),TI5(2,1),TI5(3,1),TI5(4,1),TI5(5,1)];
TI_5(2,:) = [TI5(1,2),TI5(2,2),TI5(3,2),TI5(4,2),TI5(5,2)];
TI_5(3,:) = [TI5(1,3),TI5(2,3),TI5(3,3),TI5(4,3),TI5(5,3)];
TI_5(4,:) = [TI5(1,4),TI5(2,4),TI5(3,4),TI5(4,4),TI5(5,4)];
TI_5(5,:) = [TI5(1,5),TI5(2,5),TI5(3,5),TI5(4,5),TI5(5,5)];
return

function Coertv7(RealYN)
% See page 78 in Stiff differential Equations:  Radau IIa order 5
% Butcher representation
%  C(1) |  A(1,1)  A(1,2)  A(1,3)
%  C(1) |  A(2,1)  A(2,2)  A(2,3)
%  C(1) |  A(3,1)  A(3,2)  A(3,3)
%  --------------------------
%          B(1)    B(2)    B(3)
% See page 131 in Stiff differential Equations, matrices T and TI:
% are defined such as:
% inv(T)*inv(A)*T = [ gamma 0 0; 0 Alpha -Beta; 0 Beta Alpha]
% where gamma, Alpha +- i*Beta are eigenvalue of A, in the case, 
% Radau IIa order 13. 
global T_7 TI_7 C7 ValP7 Dd7

T7 = complex(zeros(7,7), 0);
TI7 = T7;

C7(1) = 0.2931642715978489197205D-01;
C7(2) = 0.1480785996684842918500D+00;
C7(3) = 0.3369846902811542990971D+00;
C7(4) = 0.5586715187715501320814D+00;
C7(5) = 0.7692338620300545009169D+00;
C7(6) = 0.9269456713197411148519D+00;
C7(7) = 1;

Dd7(1) = -0.5437443689412861451458D+02;
Dd7(2) =  0.7000024004259186512041D+01;
Dd7(3) = -0.2355661091987557192256D+01;
Dd7(4) =  0.1132289066106134386384D+01;
Dd7(5) = -0.6468913267673587118673D+00;
Dd7(6) =  0.3875333853753523774248D+00;
Dd7(7) = -0.1428571428571428571429D+00;
Dd7    = Dd7(:);

if RealYN
  T7(1,1) = -0.2153754627310526422828D-02;
  T7(1,2) =  0.2156755135132077338691D-01;
  T7(1,3) =  0.8783567925144144407326D-02;
  T7(1,4) = -0.4055161452331023898198D-02;
  T7(1,5) =  0.4427232753268285479678D-02;
  T7(1,6) = -0.1238646187952874056377D-02;
  T7(1,7) = -0.2760617480543852499548D-02;
  T7(2,1) =  0.1600025077880428526831D-02;
  T7(2,2) = -0.3813164813441154669442D-01;
  T7(2,3) = -0.2152556059400687552385D-01;
  T7(2,4) =  0.8415568276559589237177D-02;
  T7(2,5) = -0.4031949570224549492304D-02;
  T7(2,6) = -0.6666635339396338181761D-04;
  T7(2,7) =  0.3185474825166209848748D-02;
  T7(3,1) = -0.4059107301947683091650D-02;
  T7(3,2) =  0.5739650893938171539757D-01;
  T7(3,3) =  0.5885052920842679105612D-01;
  T7(3,4) = -0.8560431061603432060177D-02;
  T7(3,5) = -0.6923212665023908924141D-02;
  T7(3,6) = -0.2352180982943338340535D-02;
  T7(3,7) =  0.4169077725297562691409D-03;
  T7(4,1) = -0.1575048807937684420346D-01;
  T7(4,2) = -0.3821469359696835048464D-01;
  T7(4,3) = -0.1657368112729438512412D+00;
  T7(4,4) = -0.3737124230238445741907D-01;
  T7(4,5) =  0.8239007298507719404499D-02;
  T7(4,6) =  0.3115071152346175252726D-02;
  T7(4,7) =  0.2511660491343882192836D-01;
  T7(5,1) = -0.1129776610242208076086D+00;
  T7(5,2) = -0.2491742124652636863308D+00;
  T7(5,3) =  0.2735633057986623212132D+00;
  T7(5,4) =  0.5366761379181770094279D-02;
  T7(5,5) =  0.1932111161012620144312D+00;
  T7(5,6) =  0.1017177324817151468081D+00;
  T7(5,7) =  0.9504502035604622821039D-01;
  T7(6,1) = -0.4583810431839315010281D+00;
  T7(6,2) =  0.5315846490836284292051D+00;
  T7(6,3) =  0.4863228366175728940567D+00;
  T7(6,4) =  0.5265742264584492629141D+00;
  T7(6,5) =  0.2755343949896258141929D+00;
  T7(6,6) =  0.5217519452747652852946D+00;
  T7(6,7) =  0.1280719446355438944141D+00;
  T7(7,1) = -0.8813915783538183763135D+00;
  T7(7,2) =  1;
  T7(7,3) =  0;
  T7(7,4) =  1;
  T7(7,5) =  0;
  T7(7,6) =  1;
  T7(7,7) =  0;
  
  TI7(1,1) = -0.2581319263199822292761D+03;
  TI7(1,2) = -0.1890737630813985089520D+03;
  TI7(1,3) = -0.4908731481793013119445D+02;
  TI7(1,4) = -0.4110647469661428418112D+01;
  TI7(1,5) = -0.4053447889315563304175D+01;
  TI7(1,6) =  0.3112755366607346076554D+01;
  TI7(1,7) = -0.1646774913558444650169D+01;
  TI7(2,1) = -0.3007390169451292131731D+01;
  TI7(2,2) = -0.1101586607876577132911D+02;
  TI7(2,3) =  0.1487799456131656281486D+01;
  TI7(2,4) =  0.2130388159559282459432D+01;
  TI7(2,5) = -0.1816141086817565624822D+01;
  TI7(2,6) =  0.1134325587895161100083D+01;
  TI7(2,7) = -0.4146990459433035319930D+00;
  TI7(3,1) = -0.8441963188321084681757D+01;
  TI7(3,2) = -0.6505252740575150028169D+00;
  TI7(3,3) =  0.6940670730369876478804D+01;
  TI7(3,4) = -0.3205047525597898431565D+01;
  TI7(3,5) =  0.1071280943546478589783D+01;
  TI7(3,6) = -0.3548507491216221879730D+00;
  TI7(3,7) =  0.9198549132786554154409D-01;
  TI7(4,1) =  0.7467833223502269977153D+02;
  TI7(4,2) =  0.8740858897990081640204D+02;
  TI7(4,3) =  0.4024158737379997877014D+01;
  TI7(4,4) = -0.3714806315158364186639D+01;
  TI7(4,5) = -0.3430093985982317350741D+01;
  TI7(4,6) =  0.2696604809765312378853D+01;
  TI7(4,7) = -0.9386927436075461933568D+00;
  TI7(5,1) =  0.5835652885190657724237D+02;
  TI7(5,2) = -0.1006877395780018096325D+02;
  TI7(5,3) = -0.3036638884256667120811D+02;
  TI7(5,4) = -0.1020020865184865985027D+01;
  TI7(5,5) = -0.1124175003784249621267D+00;
  TI7(5,6) =  0.1890640831000377622800D+01;
  TI7(5,7) = -0.9716486393831482282172D+00;
  TI7(6,1) = -0.2991862480282520966786D+03;
  TI7(6,2) = -0.2430407453687447911819D+03;
  TI7(6,3) = -0.4877710407803786921219D+02;
  TI7(6,4) = -0.2038671905741934405280D+01;
  TI7(6,5) =  0.1673560239861084944268D+01;
  TI7(6,6) = -0.1087374032057106164456D+01;
  TI7(6,7) =  0.9019382492960993738427D+00;
  TI7(7,1) = -0.9307650289743530591157D+02;
  TI7(7,2) =  0.2388163105628114427703D+02;
  TI7(7,3) =  0.3927888073081384382710D+02;
  TI7(7,4) =  0.1438891568549108006988D+02;
  TI7(7,5) = -0.3510438399399361221087D+01;
  TI7(7,6) =  0.4863284885566180701215D+01;
  TI7(7,7) = -0.2246482729591239916400D+01;
  
  ValP7(1) =  0.8936832788405216337302D+01;     % U1 dans le code
  ValP7(2) =  0.4378693561506806002523D+01;
  ValP7(3) =  0.1016969328379501162732D+02;
  ValP7(4) =  0.7141055219187640105775D+01;
  ValP7(5) =  0.6623045922639275970621D+01;
  ValP7(6) =  0.8511834825102945723051D+01;
  ValP7(7) =  0.3281013624325058830036D+01;
else
  CP7 = [1  C7(1) C7(1)^2 C7(1)^3 C7(1)^4 C7(1)^5 C7(1)^6
         1  C7(2) C7(2)^2 C7(2)^3 C7(2)^4 C7(2)^5 C7(2)^6
         1  C7(3) C7(3)^2 C7(3)^3 C7(3)^4 C7(3)^5 C7(3)^6
         1  C7(4) C7(4)^2 C7(4)^3 C7(4)^4 C7(4)^5 C7(4)^6
         1  C7(5) C7(5)^2 C7(5)^3 C7(5)^4 C7(5)^5 C7(5)^6
         1  C7(6) C7(6)^2 C7(6)^3 C7(6)^4 C7(6)^5 C7(6)^6
         1  C7(7) C7(7)^2 C7(7)^3 C7(7)^4 C7(7)^5 C7(7)^6];
                 
  CQ7 = [C7(1) C7(1)^2/2 C7(1)^3/3 C7(1)^4/4 C7(1)^5/5 C7(1)^6/6 C7(1)^7/7
         C7(2) C7(2)^2/2 C7(2)^3/3 C7(2)^4/4 C7(2)^5/5 C7(2)^6/6 C7(2)^7/7
         C7(3) C7(3)^2/2 C7(3)^3/3 C7(3)^4/4 C7(3)^5/5 C7(3)^6/6 C7(3)^7/7
         C7(4) C7(4)^2/2 C7(4)^3/3 C7(4)^4/4 C7(4)^5/5 C7(4)^6/6 C7(4)^7/7
         C7(5) C7(5)^2/2 C7(5)^3/3 C7(5)^4/4 C7(5)^5/5 C7(5)^6/6 C7(5)^7/7
         C7(6) C7(6)^2/2 C7(6)^3/3 C7(6)^4/4 C7(6)^5/5 C7(6)^6/6 C7(6)^7/7
         C7(7) C7(7)^2/2 C7(7)^3/3 C7(7)^4/4 C7(7)^5/5 C7(7)^6/6 C7(7)^7/7];
 
  A7 = CQ7 / CP7 ;

  [T7,D7]   = eig(A7);
  D7        = eye(7)/D7;
  TI7       = T7\eye(7);
  ValP7(1)  = D7(1,1);
  ValP7(2)  = D7(2,2);
  ValP7(3)  = D7(3,3);
  ValP7(4)  = D7(4,4);
  ValP7(5)  = D7(5,5);
  ValP7(6)  = D7(6,6);
  ValP7(7)  = D7(7,7);  
end  
T_7(1,:) = [T7(1,1),T7(2,1),T7(3,1),T7(4,1),T7(5,1),T7(6,1),T7(7,1)];
T_7(2,:) = [T7(1,2),T7(2,2),T7(3,2),T7(4,2),T7(5,2),T7(6,2),T7(7,2)];
T_7(3,:) = [T7(1,3),T7(2,3),T7(3,3),T7(4,3),T7(5,3),T7(6,3),T7(7,3)];
T_7(4,:) = [T7(1,4),T7(2,4),T7(3,4),T7(4,4),T7(5,4),T7(6,4),T7(7,4)];
T_7(5,:) = [T7(1,5),T7(2,5),T7(3,5),T7(4,5),T7(5,5),T7(6,5),T7(7,5)];
T_7(6,:) = [T7(1,6),T7(2,6),T7(3,6),T7(4,6),T7(5,6),T7(6,6),T7(7,6)];
T_7(7,:) = [T7(1,7),T7(2,7),T7(3,7),T7(4,7),T7(5,7),T7(6,7),T7(7,7)];

TI_7(1,:) = [TI7(1,1),TI7(2,1),TI7(3,1),TI7(4,1),TI7(5,1),TI7(6,1),TI7(7,1)];
TI_7(2,:) = [TI7(1,2),TI7(2,2),TI7(3,2),TI7(4,2),TI7(5,2),TI7(6,2),TI7(7,2)];
TI_7(3,:) = [TI7(1,3),TI7(2,3),TI7(3,3),TI7(4,3),TI7(5,3),TI7(6,3),TI7(7,3)];
TI_7(4,:) = [TI7(1,4),TI7(2,4),TI7(3,4),TI7(4,4),TI7(5,4),TI7(6,4),TI7(7,4)];
TI_7(5,:) = [TI7(1,5),TI7(2,5),TI7(3,5),TI7(4,5),TI7(5,5),TI7(6,5),TI7(7,5)];
TI_7(6,:) = [TI7(1,6),TI7(2,6),TI7(3,6),TI7(4,6),TI7(5,6),TI7(6,6),TI7(7,6)];
TI_7(7,:) = [TI7(1,7),TI7(2,7),TI7(3,7),TI7(4,7),TI7(5,7),TI7(6,7),TI7(7,7)];
return

