MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF87" > sprdmpF87_mex.mki
echo "CC=$CC" >> sprdmpF87_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF87_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF87_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF87_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF87_mex.mki
echo "CXX=$CXX" >> sprdmpF87_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF87_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF87_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF87_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF87_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF87_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF87_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF87_mex.mki
echo "Arch=$Arch" >> sprdmpF87_mex.mki
echo "LD=$LD" >> sprdmpF87_mex.mki
echo OMPFLAGS= >> sprdmpF87_mex.mki
echo OMPLINKFLAGS= >> sprdmpF87_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF87_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF87_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF87_mex.mk
