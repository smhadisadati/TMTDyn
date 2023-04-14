function varargout = igesToolBoxGUI(varargin)
% IGESTOOLBOXGUI M-file for igesToolBoxGUI.fig
%      IGESTOOLBOXGUI, by itself, creates a new IGESTOOLBOXGUI or raises the existing
%      singleton*.
%
%      H = IGESTOOLBOXGUI returns the handle to a new IGESTOOLBOXGUI or the handle to
%      the existing singleton*.
%
%      IGESTOOLBOXGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in IGESTOOLBOXGUI.M with the given input arguments.
%
%      IGESTOOLBOXGUI('Property','Value',...) creates a new IGESTOOLBOXGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before igesToolBoxGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to igesToolBoxGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help igesToolBoxGUI

% Last Modified by GUIDE v2.5 24-Nov-2015 17:35:33

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @igesToolBoxGUI_OpeningFcn, ...
    'gui_OutputFcn',  @igesToolBoxGUI_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

% --- Executes just before igesToolBoxGUI is made visible.
function igesToolBoxGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to igesToolBoxGUI (see VARARGIN)

% Choose default command line output for igesToolBoxGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

initialize_gui(hObject, handles);

% UIWAIT makes igesToolBoxGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);

% --- Outputs from this function are returned to the command line.
function varargout = igesToolBoxGUI_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --------------------------------------------------------------------
function menuProductHelp_Callback(hObject, eventdata, handles)
% hObject    handle to menuProductHelp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

msgbox('No help is available for the moment.','Product Help','help');

% --------------------------------------------------------------------
function menuAbout_Callback(hObject, eventdata, handles)
% hObject    handle to menuAbout (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

msgbox('Written by Per Bergström 2015-12-01.','About','help');

% --------------------------------------------------------------------
function menuOpenIGES_Callback(hObject, eventdata, handles)
% hObject    handle to menuOpenIGES (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    if isdir(handles.plotdata.path)
        currentFolder = cd(handles.plotdata.path);
        [file, path] = uigetfile({'*.igs';'*.iges'},'Select the IGES-file');
        cd(currentFolder);
    else
        [file, path] = uigetfile({'*.igs';'*.iges'},'Select the IGES-file');
    end
else
    [file, path] = uigetfile({'*.igs';'*.iges'},'Select the IGES-file');
end

if ischar(file)
    
    initialize_gui(hObject, handles);
    
    handles.plotdata.filename = file;
    handles.plotdata.path = path;
    
    set(handles.textFile,'String',file);
    
    % Load parameter data from IGES-file
    [ParameterData,EntityType,numEntityType,unknownEntityType,numunknownEntityType]=iges2matlab([path,file]);
    
    % Plot the IGES object
    axes(handles.axesCAD);
    hold on
    
    handles.plotdata.handlePlot=plotIGES(ParameterData,1,0);
    
    handles.igesdata.PlotAccuracy = 0;
    set(handles.IGESplotA0, 'Checked', 'on');
    
    material default
    
    axis on
    set(handles.checkboxXYZdir,'Value',0);
    set(handles.checkboxAxis,'Value',1);
    set(handles.checkboxTransp,'Value',0);
    set(handles.checkboxLight,'Value',0);
    
    set(handles.checkboxMetal,'Value',0);
    set(handles.checkboxShiny,'Value',0);
    set(handles.checkboxDull,'Value',0);
    set(handles.checkboxMatMetal,'Value',0);
    
    axis tight
    
    sc=0.1;
    
    xl=xlim;
    dx=xl(2)-xl(1);
    xl(1)=xl(1)-sc*dx;
    xl(2)=xl(2)+sc*dx;
    xlim(xl);
    
    yl=ylim;
    dy=yl(2)-yl(1);
    yl(1)=yl(1)-sc*dy;
    yl(2)=yl(2)+sc*dy;
    ylim(yl);
    
    zl=zlim;
    dz=zl(2)-zl(1);
    zl(1)=zl(1)-sc*dz;
    zl(2)=zl(2)+sc*dz;
    zlim(zl);
    
    handles.igesdata.igesfile = true;
    
    handles.plotdata.xl = xl;
    handles.plotdata.yl = yl;
    handles.plotdata.zl = zl;
    
    handles.plotdata.dx = dx;
    handles.plotdata.dy = dy;
    handles.plotdata.dz = dz;
    
    handles.igesdata.ParameterData = ParameterData;
    handles.igesdata.EntityType = EntityType;
    handles.igesdata.numEntityType = numEntityType;
    handles.igesdata.unknownEntityType = unknownEntityType;
    handles.igesdata.numunknownEntityType = numunknownEntityType;
    
    % Update handles structure
    guidata(handles.figure1, handles);
    
    if not(isempty(unknownEntityType))
        msgbox(['There are entity types in "',file,'" that are not compatible with this version of IGES Toolbox. These are entity type numbers ',num2str(unknownEntityType),'.'],'Warning','warn');
    end
    
end

% --------------------------------------------------------------------
function menuOpenSTL_Callback(hObject, eventdata, handles)
% hObject    handle to menuOpenSTL (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    if isdir(handles.plotdata.path)
        currentFolder = cd(handles.plotdata.path);
        [file, path] = uigetfile({'*.stl'},'Select the STL-file');
        cd(currentFolder);
    else
        [file, path] = uigetfile({'*.stl'},'Select the STL-file');
    end
else
    [file, path] = uigetfile({'*.stl'},'Select the STL-file');
end

if ischar(file)
    
    initialize_gui(hObject, handles);
    
    handles.plotdata.filename = file;
    handles.plotdata.path = path;
    
    set(handles.textFile,'String',file);
    
    % Load data from STL-file
    [VertexData,FVCD,isBinary]=stl2matlab([path,file]);
    
    % Plot the STL object
    axes(handles.axesCAD);
    hold on
    
    handles.plotdata.handlePlot=plotSTL(VertexData,[],0);
    
    material default
    
    light
    
    axis on
    
    set(handles.checkboxXYZdir,'Value',0);
    set(handles.checkboxAxis,'Value',1);
    set(handles.checkboxTransp,'Value',0);
    set(handles.checkboxLight,'Value',1);
    
    set(handles.checkboxMetal,'Value',0);
    set(handles.checkboxShiny,'Value',0);
    set(handles.checkboxDull,'Value',0);
    set(handles.checkboxMatMetal,'Value',0);
    
    axis tight
    
    sc=0.1;
    
    xl=xlim;
    dx=xl(2)-xl(1);
    xl(1)=xl(1)-sc*dx;
    xl(2)=xl(2)+sc*dx;
    xlim(xl);
    
    yl=ylim;
    dy=yl(2)-yl(1);
    yl(1)=yl(1)-sc*dy;
    yl(2)=yl(2)+sc*dy;
    ylim(yl);
    
    zl=zlim;
    dz=zl(2)-zl(1);
    zl(1)=zl(1)-sc*dz;
    zl(2)=zl(2)+sc*dz;
    zlim(zl);
    
    handles.igesdata.igesfile = false;
    handles.stldata.stlfile = true;
    
    handles.plotdata.xl = xl;
    handles.plotdata.yl = yl;
    handles.plotdata.zl = zl;
    
    handles.plotdata.dx = dx;
    handles.plotdata.dy = dy;
    handles.plotdata.dz = dz;
    
    handles.stldata.VertexData = VertexData;
    handles.stldata.FVCD = FVCD;
    handles.stldata.isBinary = isBinary;
    
    % Update handles structure
    guidata(handles.figure1, handles);
    
end

% --------------------------------------------------------------------
function menuOpenData_Callback(hObject, eventdata, handles)
% hObject    handle to ToolbarOpenData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    if isdir(handles.plotdata.path)
        currentFolder = cd(handles.plotdata.path);
        [filename, pathname] = uigetfile('*.mat','Select file');
        cd(currentFolder);
    else
        [filename, pathname] = uigetfile('*.mat','Select file');
    end
else
    [filename, pathname] = uigetfile('*.mat','Select file');
end

if ischar(filename)
    
    load([pathname,filename],'plotdata','igesdata','stldata');
    
    initialize_gui(hObject, handles);
    
    handles.plotdata=plotdata;
    handles.igesdata=igesdata;
    handles.stldata=stldata;
    
    set(handles.textFile,'String',handles.plotdata.filename);
    
    if handles.igesdata.igesfile
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0);
        
        handles.igesdata.PlotAccuracy = 0;
        set(handles.IGESplotA0, 'Checked', 'on');
        
        material default
        
        set(handles.checkboxLight,'Value',0);
        
    elseif handles.stldata.stlfile
        
        % Plot the STL object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotSTL(handles.stldata.VertexData,[],0);
        
        material default
        
        light
        
        set(handles.checkboxLight,'Value',1);
        
    end
    
    axis on
    set(handles.checkboxXYZdir,'Value',0);
    set(handles.checkboxAxis,'Value',1);
    set(handles.checkboxTransp,'Value',0);
    
    set(handles.checkboxMetal,'Value',0);
    set(handles.checkboxShiny,'Value',0);
    set(handles.checkboxDull,'Value',0);
    set(handles.checkboxMatMetal,'Value',0);
    
    xlim(handles.plotdata.xl);
    ylim(handles.plotdata.yl);
    zlim(handles.plotdata.zl);
    
    % Update handles structure
    
    guidata(handles.figure1, handles);
    
end

% --------------------------------------------------------------------
function menuSave_Callback(hObject, eventdata, handles)
% hObject    handle to menuSave (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if handles.plotdata.saveas
    plotdata=handles.plotdata;
    igesdata=handles.igesdata;
    stldata=handles.stldata;
    save(handles.plotdata.file,'plotdata','igesdata','stldata');
else
    menuSaveDataAs_Callback(hObject, eventdata, handles);
end

% --------------------------------------------------------------------
function menuSaveDataAs_Callback(hObject, eventdata, handles)
% hObject    handle to menuSaveDataAs (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.plotdata.saveas=true;

[filename, pathname] = uiputfile('*.mat','Save as');

handles.plotdata.file=[pathname,filename];

plotdata=handles.plotdata;
igesdata=handles.igesdata;
stldata=handles.stldata;

save(handles.plotdata.file,'plotdata','igesdata','stldata');

% --------------------------------------------------------------------
function menuExportFig_Callback(hObject, eventdata, handles)
% hObject    handle to menuExportFig (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

[filename, pathname] = uiputfile({'*.jpg';'*.png';'*.eps';'*.pdf';'*.bmp';'*.emf';'*.pbm';'*.pcx';'*.pgm';'*.ppm';'*.tif'},'Export as');

saveas(handles.axesCAD,[pathname,filename]);

% --------------------------------------------------------------------
function menuNew_Callback(hObject, eventdata, handles)
% hObject    handle to menuNew (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

initialize_gui(hObject, handles);

% --------------------------------------------------------------------
function MenuExit_Callback(hObject, eventdata, handles)
% hObject    handle to MenuExit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

selection = questdlg('Close This Program?','Close Request Function','Yes','No','Yes');
switch selection,
    case 'Yes',
        delete(handles.figure1)
    case 'No'
        return
end

% --- Executes on button press in checkboxTransp.
function checkboxTransp_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxTransp

hoval=get(hObject,'Value');

if handles.igesdata.igesfile
    if hoval
        set(handles.plotdata.handlePlot{3},'FaceAlpha',0.5);
    else
        set(handles.plotdata.handlePlot{3},'FaceAlpha',1);
    end
elseif handles.stldata.stlfile
    if hoval
        set(handles.plotdata.handlePlot,'FaceAlpha',0.5);
    else
        set(handles.plotdata.handlePlot,'FaceAlpha',1);
    end
end

% --- Executes on button press in checkboxTransp.
function checkboxLight_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxTransp

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    
    hoval=get(hObject,'Value');
    
    if hoval
        light
    else
        material default
        hlght=findobj(gca,'Type','Light');
        delete(hlght);
        set(handles.checkboxShiny,'Value',0);
        set(handles.checkboxDull,'Value',0);
        set(handles.checkboxMatMetal,'Value',0);
    end
    
else
    set(handles.checkboxLight,'Value',0);
end

% --- Executes on button press in checkboxMetal.
function checkboxMetal_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxMetal

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    
    myclr=[0.9,0.9,0.95];
    
    hoval=get(hObject,'Value');
    
    if handles.igesdata.igesfile
        if hoval
            set(handles.plotdata.handlePlot{1},'Color',myclr);
            set(handles.plotdata.handlePlot{3},'FaceColor',myclr);
        else
            set(handles.checkboxMetal,'Value',1);
        end
    elseif handles.stldata.stlfile
        if hoval
            set(handles.plotdata.handlePlot,'FaceColor',myclr);
        else
            set(handles.checkboxMetal,'Value',1);
        end
    end
    
else
    set(handles.checkboxMetal,'Value',0);
end

% --- Executes on button press in checkboxMatMetal.
function checkboxMatMetal_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxMatMetal

if and(or(handles.igesdata.igesfile,handles.stldata.stlfile),get(handles.checkboxLight,'Value'))
    
    hoval=get(hObject,'Value');
    
    if hoval
        material metal
        set(handles.checkboxShiny,'Value',0);
        set(handles.checkboxDull,'Value',0);
    else
        material default
    end
    
else
    set(handles.checkboxMatMetal,'Value',0);
end

% --- Executes on button press in checkboxDull.
function checkboxDull_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxDull

if and(or(handles.igesdata.igesfile,handles.stldata.stlfile),get(handles.checkboxLight,'Value'))
    
    hoval=get(hObject,'Value');
    
    if hoval
        material dull
        set(handles.checkboxShiny,'Value',0);
        set(handles.checkboxMatMetal,'Value',0);
    else
        material default
    end
    
else
    set(handles.checkboxDull,'Value',0);
end

% --- Executes on button press in checkboxShiny.
function checkboxShiny_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxTransp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxShiny

if and(or(handles.igesdata.igesfile,handles.stldata.stlfile),get(handles.checkboxLight,'Value'))
    
    hoval=get(hObject,'Value');
    
    if hoval
        material shiny
        set(handles.checkboxDull,'Value',0);
        set(handles.checkboxMatMetal,'Value',0);
    else
        material default
    end
    
else
    set(handles.checkboxShiny,'Value',0);
end

% --- Executes on button press in checkboxXYZdir.
function checkboxXYZdir_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxXYZdir (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxXYZdir

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    
    hoval=get(hObject,'Value');
    
    le=0.175*min([handles.plotdata.dx, handles.plotdata.dy, handles.plotdata.dz]);
    
    if hoval
        
        axes(handles.axesCAD);
        
        hold on
        
        handles.plotdata.hxyz=plotAxis([handles.plotdata.xl(1), handles.plotdata.yl(1), handles.plotdata.zl(1)]+0.04*[handles.plotdata.dx, handles.plotdata.dy, handles.plotdata.dz],le);
        
        xlim(handles.plotdata.xl);
        ylim(handles.plotdata.yl);
        zlim(handles.plotdata.zl);
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    else
        
        delete(handles.plotdata.hxyz{1});
        delete(handles.plotdata.hxyz{2});
        delete(handles.plotdata.hxyz{3});
        delete(handles.plotdata.hxyz{4});
        delete(handles.plotdata.hxyz{5});
        delete(handles.plotdata.hxyz{6});
        
        handles.plotdata.hxyz{1}(:)=0;
        handles.plotdata.hxyz{2}(:)=0;
        handles.plotdata.hxyz{3}(:)=0;
        handles.plotdata.hxyz{4}(:)=0;
        handles.plotdata.hxyz{5}(:)=0;
        handles.plotdata.hxyz{6}(:)=0;
        
    end
    
else
    set(handles.checkboxXYZdir,'Value',0);
end

% --- Executes on button press in checkboxAxis.
function checkboxAxis_Callback(hObject, eventdata, handles)
% hObject    handle to checkboxAxis (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkboxAxis

if or(handles.igesdata.igesfile,handles.stldata.stlfile)
    
    hoval=get(hObject,'Value');
    
    axes(handles.axesCAD);
    if hoval
        axis on
    else
        axis off
    end
    
else
    set(handles.checkboxAxis,'Value',1);
end

% --------------------------------------------------------------------
function initialize_gui(fig_handle, handles)
% If the plotdata field is present and the reset flag is false, it means
% we are we are just re-initializing a GUI by calling it from the cmd line
% while it is up. So, bail out as we dont want to reset the data.

handles.plotdata.filename = '';
handles.plotdata.path = '';
set(handles.textFile,'String','');

handles.plotdata.xl = [0,1];
handles.plotdata.yl = [0,1];
handles.plotdata.zl = [0,1];

handles.plotdata.dx = 1;
handles.plotdata.dy = 1;
handles.plotdata.dz = 1;

handles.plotdata.hxyz=cell(6,1);
handles.plotdata.hxyz{1}=0;
handles.plotdata.hxyz{2}=0;
handles.plotdata.hxyz{3}=0;
handles.plotdata.hxyz{4}=0;
handles.plotdata.hxyz{5}=0;
handles.plotdata.hxyz{6}=0;

handles.plotdata.saveas=false;
handles.plotdata.file='';

set(handles.checkboxXYZdir,'Value',0);
set(handles.checkboxAxis,'Value',1);
set(handles.checkboxTransp,'Value',0);
set(handles.checkboxLight,'Value',0);

set(handles.checkboxMetal,'Value',0);
set(handles.checkboxShiny,'Value',0);
set(handles.checkboxDull,'Value',0);
set(handles.checkboxMatMetal,'Value',0);

set(handles.IGESplotA0, 'Checked', 'off');
set(handles.IGESplotA1, 'Checked', 'off');
set(handles.IGESplotA2, 'Checked', 'off');
set(handles.IGESplotA3, 'Checked', 'off');

handles.igesdata.igesfile = false;
handles.igesdata.ParameterData = 0;
handles.igesdata.EntityType = 0;
handles.igesdata.numEntityType = 0;
handles.igesdata.unknownEntityType = 0;
handles.igesdata.numunknownEntityType = 0;
handles.igesdata.PlotAccuracy = -1;

handles.stldata.stlfile = false;
handles.stldata.VertexData = 0;
handles.stldata.FVCD = 0;
handles.stldata.isBinary = 0;

axes(handles.axesCAD);

hold off
cla
cla(handles.axesCAD,'reset')

xlim(handles.plotdata.xl);
ylim(handles.plotdata.yl);
zlim(handles.plotdata.zl);

% Update handles structure

guidata(handles.figure1, handles);

% --------------------------------------------------------------------
function IGESplotA0_Callback(hObject, eventdata, handles)
% hObject    handle to IGESplotA0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if handles.igesdata.igesfile
    
    if eq(handles.igesdata.PlotAccuracy,-1)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],0);
        handles.igesdata.PlotAccuracy = 0;
        
        set(handles.IGESplotA0, 'Checked', 'on');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    elseif ne(handles.igesdata.PlotAccuracy,0)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        delete(handles.plotdata.handlePlot{1});
        delete(handles.plotdata.handlePlot{2});
        delete(handles.plotdata.handlePlot{3});
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],0);
        handles.igesdata.PlotAccuracy = 0;
        
        set(handles.IGESplotA0, 'Checked', 'on');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    else
        msgbox('Plot accuracy is already 0.');
    end
else
    msgbox('Plot accuracy is only available for IGES plots.');
end

% --------------------------------------------------------------------
function IGESplotA1_Callback(hObject, eventdata, handles)
% hObject    handle to IGESplotA1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if handles.igesdata.igesfile
    
    if eq(handles.igesdata.PlotAccuracy,-1)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],0,1);
        handles.igesdata.PlotAccuracy = 1;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'on');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    elseif ne(handles.igesdata.PlotAccuracy,1)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        delete(handles.plotdata.handlePlot{1});
        delete(handles.plotdata.handlePlot{2});
        delete(handles.plotdata.handlePlot{3});
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],1,1);
        handles.igesdata.PlotAccuracy = 1;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'on');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    else
        msgbox('Plot accuracy is already 1.');
    end
else
    msgbox('Plot accuracy is only available for IGES plots.');
end

% --------------------------------------------------------------------
function IGESplotA2_Callback(hObject, eventdata, handles)
% hObject    handle to IGESplotA2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if handles.igesdata.igesfile
    
    if eq(handles.igesdata.PlotAccuracy,-1)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],2);
        handles.igesdata.PlotAccuracy = 2;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'on');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    elseif ne(handles.igesdata.PlotAccuracy,2)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        delete(handles.plotdata.handlePlot{1});
        delete(handles.plotdata.handlePlot{2});
        delete(handles.plotdata.handlePlot{3});
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],2);
        handles.igesdata.PlotAccuracy = 2;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'on');
        set(handles.IGESplotA3, 'Checked', 'off');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    else
        msgbox('Plot accuracy is already 2.');
    end
else
    msgbox('Plot accuracy is only available for IGES plots.');
end

% --------------------------------------------------------------------
function IGESplotA3_Callback(hObject, eventdata, handles)
% hObject    handle to IGESplotA3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if handles.igesdata.igesfile
    
    if eq(handles.igesdata.PlotAccuracy,-1)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],3);
        handles.igesdata.PlotAccuracy = 3;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'on');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    elseif ne(handles.igesdata.PlotAccuracy,3)
        
        % Plot the IGES object
        axes(handles.axesCAD);
        hold on
        
        delete(handles.plotdata.handlePlot{1});
        delete(handles.plotdata.handlePlot{2});
        delete(handles.plotdata.handlePlot{3});
        
        handles.plotdata.handlePlot=plotIGES(handles.igesdata.ParameterData,1,0,[],[],3);
        handles.igesdata.PlotAccuracy = 3;
        
        set(handles.IGESplotA0, 'Checked', 'off');
        set(handles.IGESplotA1, 'Checked', 'off');
        set(handles.IGESplotA2, 'Checked', 'off');
        set(handles.IGESplotA3, 'Checked', 'on');
        
        % Update handles structure
        guidata(handles.figure1, handles);
        
    else
        msgbox('Plot accuracy is already 3.');
    end
else
    msgbox('Plot accuracy is only available for IGES plots.');
end
