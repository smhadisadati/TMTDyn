MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF89" > sprdmpF89_mex.mki
echo "CC=$CC" >> sprdmpF89_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF89_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF89_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF89_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF89_mex.mki
echo "CXX=$CXX" >> sprdmpF89_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF89_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF89_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF89_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF89_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF89_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF89_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF89_mex.mki
echo "Arch=$Arch" >> sprdmpF89_mex.mki
echo "LD=$LD" >> sprdmpF89_mex.mki
echo OMPFLAGS= >> sprdmpF89_mex.mki
echo OMPLINKFLAGS= >> sprdmpF89_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF89_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF89_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF89_mex.mk
