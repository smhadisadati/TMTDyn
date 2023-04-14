MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF50" > sprdmpF50_mex.mki
echo "CC=$CC" >> sprdmpF50_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF50_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF50_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF50_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF50_mex.mki
echo "CXX=$CXX" >> sprdmpF50_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF50_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF50_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF50_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF50_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF50_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF50_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF50_mex.mki
echo "Arch=$Arch" >> sprdmpF50_mex.mki
echo "LD=$LD" >> sprdmpF50_mex.mki
echo OMPFLAGS= >> sprdmpF50_mex.mki
echo OMPLINKFLAGS= >> sprdmpF50_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF50_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF50_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF50_mex.mk
