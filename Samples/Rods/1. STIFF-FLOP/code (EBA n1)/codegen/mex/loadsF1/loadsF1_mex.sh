MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for loadsF1" > loadsF1_mex.mki
echo "CC=$CC" >> loadsF1_mex.mki
echo "CFLAGS=$CFLAGS" >> loadsF1_mex.mki
echo "CLIBS=$CLIBS" >> loadsF1_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> loadsF1_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> loadsF1_mex.mki
echo "CXX=$CXX" >> loadsF1_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> loadsF1_mex.mki
echo "CXXLIBS=$CXXLIBS" >> loadsF1_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> loadsF1_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> loadsF1_mex.mki
echo "LDFLAGS=$LDFLAGS" >> loadsF1_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> loadsF1_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> loadsF1_mex.mki
echo "Arch=$Arch" >> loadsF1_mex.mki
echo "LD=$LD" >> loadsF1_mex.mki
echo OMPFLAGS= >> loadsF1_mex.mki
echo OMPLINKFLAGS= >> loadsF1_mex.mki
echo "EMC_COMPILER=gcc" >> loadsF1_mex.mki
echo "EMC_CONFIG=optim" >> loadsF1_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f loadsF1_mex.mk
