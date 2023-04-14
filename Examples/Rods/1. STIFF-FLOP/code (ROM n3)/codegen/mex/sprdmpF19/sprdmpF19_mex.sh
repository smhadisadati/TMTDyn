MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF19" > sprdmpF19_mex.mki
echo "CC=$CC" >> sprdmpF19_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF19_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF19_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF19_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF19_mex.mki
echo "CXX=$CXX" >> sprdmpF19_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF19_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF19_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF19_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF19_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF19_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF19_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF19_mex.mki
echo "Arch=$Arch" >> sprdmpF19_mex.mki
echo "LD=$LD" >> sprdmpF19_mex.mki
echo OMPFLAGS= >> sprdmpF19_mex.mki
echo OMPLINKFLAGS= >> sprdmpF19_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF19_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF19_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF19_mex.mk
