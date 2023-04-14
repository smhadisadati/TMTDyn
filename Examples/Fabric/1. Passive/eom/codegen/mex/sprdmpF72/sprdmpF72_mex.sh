MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF72" > sprdmpF72_mex.mki
echo "CC=$CC" >> sprdmpF72_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF72_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF72_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF72_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF72_mex.mki
echo "CXX=$CXX" >> sprdmpF72_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF72_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF72_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF72_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF72_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF72_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF72_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF72_mex.mki
echo "Arch=$Arch" >> sprdmpF72_mex.mki
echo "LD=$LD" >> sprdmpF72_mex.mki
echo OMPFLAGS= >> sprdmpF72_mex.mki
echo OMPLINKFLAGS= >> sprdmpF72_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF72_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF72_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF72_mex.mk
