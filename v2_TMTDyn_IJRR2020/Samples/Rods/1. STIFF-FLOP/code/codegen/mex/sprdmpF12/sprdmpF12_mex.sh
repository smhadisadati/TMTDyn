MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF12" > sprdmpF12_mex.mki
echo "CC=$CC" >> sprdmpF12_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF12_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF12_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF12_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF12_mex.mki
echo "CXX=$CXX" >> sprdmpF12_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF12_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF12_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF12_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF12_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF12_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF12_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF12_mex.mki
echo "Arch=$Arch" >> sprdmpF12_mex.mki
echo "LD=$LD" >> sprdmpF12_mex.mki
echo OMPFLAGS= >> sprdmpF12_mex.mki
echo OMPLINKFLAGS= >> sprdmpF12_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF12_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF12_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF12_mex.mk
