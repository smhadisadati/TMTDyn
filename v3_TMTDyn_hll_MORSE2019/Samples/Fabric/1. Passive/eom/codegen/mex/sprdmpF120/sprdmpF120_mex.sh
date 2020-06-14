MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF120" > sprdmpF120_mex.mki
echo "CC=$CC" >> sprdmpF120_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF120_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF120_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF120_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF120_mex.mki
echo "CXX=$CXX" >> sprdmpF120_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF120_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF120_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF120_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF120_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF120_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF120_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF120_mex.mki
echo "Arch=$Arch" >> sprdmpF120_mex.mki
echo "LD=$LD" >> sprdmpF120_mex.mki
echo OMPFLAGS= >> sprdmpF120_mex.mki
echo OMPLINKFLAGS= >> sprdmpF120_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF120_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF120_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF120_mex.mk
