MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF73" > sprdmpF73_mex.mki
echo "CC=$CC" >> sprdmpF73_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF73_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF73_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF73_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF73_mex.mki
echo "CXX=$CXX" >> sprdmpF73_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF73_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF73_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF73_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF73_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF73_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF73_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF73_mex.mki
echo "Arch=$Arch" >> sprdmpF73_mex.mki
echo "LD=$LD" >> sprdmpF73_mex.mki
echo OMPFLAGS= >> sprdmpF73_mex.mki
echo OMPLINKFLAGS= >> sprdmpF73_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF73_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF73_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF73_mex.mk
