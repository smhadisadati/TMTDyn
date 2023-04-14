MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF6" > sprdmpF6_mex.mki
echo "CC=$CC" >> sprdmpF6_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF6_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF6_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF6_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF6_mex.mki
echo "CXX=$CXX" >> sprdmpF6_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF6_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF6_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF6_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF6_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF6_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF6_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF6_mex.mki
echo "Arch=$Arch" >> sprdmpF6_mex.mki
echo "LD=$LD" >> sprdmpF6_mex.mki
echo OMPFLAGS= >> sprdmpF6_mex.mki
echo OMPLINKFLAGS= >> sprdmpF6_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF6_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF6_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF6_mex.mk
