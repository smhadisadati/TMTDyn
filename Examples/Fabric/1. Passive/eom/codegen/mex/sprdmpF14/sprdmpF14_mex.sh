MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF14" > sprdmpF14_mex.mki
echo "CC=$CC" >> sprdmpF14_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF14_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF14_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF14_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF14_mex.mki
echo "CXX=$CXX" >> sprdmpF14_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF14_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF14_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF14_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF14_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF14_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF14_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF14_mex.mki
echo "Arch=$Arch" >> sprdmpF14_mex.mki
echo "LD=$LD" >> sprdmpF14_mex.mki
echo OMPFLAGS= >> sprdmpF14_mex.mki
echo OMPLINKFLAGS= >> sprdmpF14_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF14_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF14_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF14_mex.mk
