###########################################################################
## Makefile generated for component 'EOM'. 
## 
## Makefile     : EOM_rtw.mk
## Generated on : Wed Mar 10 21:23:21 2021
## Final product: .\EOM.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = EOM
MAKEFILE                  = EOM_rtw.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2020b
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2020b\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = C:\Users\customer\MEGAsync\Hadi\Postdoc\2_KCL\2_RESE~1\2E703~1.MOD\CTRTMT~1\eom\codegen\lib\EOM
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = EOM_rtw_comp.rsp
CMD_FILE                  = EOM_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = EOM.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2017 v15.0 | nmake (64-bit Windows)
# Supported Version(s):    15.0
# ToolchainInfo Version:   2020b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\EOM.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=EOM

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\EOM_data.c $(START_DIR)\EOM_initialize.c $(START_DIR)\EOM_terminate.c $(START_DIR)\EOM.c $(START_DIR)\romF.c $(START_DIR)\massF1.c $(START_DIR)\massF2.c $(START_DIR)\massF3.c $(START_DIR)\massF4.c $(START_DIR)\massF5.c $(START_DIR)\sprdmpF25.c $(START_DIR)\sprdmpF26.c $(START_DIR)\sprdmpF27.c $(START_DIR)\sprdmpF28.c $(START_DIR)\sprdmpF29.c $(START_DIR)\pinv.c $(START_DIR)\svd.c $(START_DIR)\xnrm2.c $(START_DIR)\xdotc.c $(START_DIR)\EOM_input.c $(START_DIR)\dyn_mid_step.c $(START_DIR)\xaxpy.c $(START_DIR)\xrotg.c $(START_DIR)\xrot.c $(START_DIR)\xswap.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = EOM_data.obj EOM_initialize.obj EOM_terminate.obj EOM.obj romF.obj massF1.obj massF2.obj massF3.obj massF4.obj massF5.obj sprdmpF25.obj sprdmpF26.obj sprdmpF27.obj sprdmpF28.obj sprdmpF29.obj pinv.obj svd.obj xnrm2.obj xdotc.obj EOM_input.obj dyn_mid_step.obj xaxpy.obj xrotg.obj xrot.obj xswap.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{C:\Users\customer\MEGAsync\Hadi\Postdoc\2_KCL\2_RESE~1\2E703~1.MOD\CTRTMT~1\eom}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{C:\Users\customer\MEGAsync\Hadi\Postdoc\2_KCL\2_RESE~1\2E703~1.MOD\CTRTMT~1\eom}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


EOM_data.obj : $(START_DIR)\EOM_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\EOM_data.c


EOM_initialize.obj : $(START_DIR)\EOM_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\EOM_initialize.c


EOM_terminate.obj : $(START_DIR)\EOM_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\EOM_terminate.c


EOM.obj : $(START_DIR)\EOM.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\EOM.c


romF.obj : $(START_DIR)\romF.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\romF.c


massF1.obj : $(START_DIR)\massF1.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\massF1.c


massF2.obj : $(START_DIR)\massF2.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\massF2.c


massF3.obj : $(START_DIR)\massF3.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\massF3.c


massF4.obj : $(START_DIR)\massF4.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\massF4.c


massF5.obj : $(START_DIR)\massF5.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\massF5.c


sprdmpF25.obj : $(START_DIR)\sprdmpF25.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sprdmpF25.c


sprdmpF26.obj : $(START_DIR)\sprdmpF26.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sprdmpF26.c


sprdmpF27.obj : $(START_DIR)\sprdmpF27.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sprdmpF27.c


sprdmpF28.obj : $(START_DIR)\sprdmpF28.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sprdmpF28.c


sprdmpF29.obj : $(START_DIR)\sprdmpF29.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\sprdmpF29.c


pinv.obj : $(START_DIR)\pinv.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\pinv.c


svd.obj : $(START_DIR)\svd.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\svd.c


xnrm2.obj : $(START_DIR)\xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xnrm2.c


xdotc.obj : $(START_DIR)\xdotc.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xdotc.c


EOM_input.obj : $(START_DIR)\EOM_input.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\EOM_input.c


dyn_mid_step.obj : $(START_DIR)\dyn_mid_step.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\dyn_mid_step.c


xaxpy.obj : $(START_DIR)\xaxpy.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xaxpy.c


xrotg.obj : $(START_DIR)\xrotg.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xrotg.c


xrot.obj : $(START_DIR)\xrot.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xrot.c


xswap.obj : $(START_DIR)\xswap.c
	$(CC) $(CFLAGS) -Fo"$@" $(START_DIR)\xswap.c


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


