MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF95" > sprdmpF95_mex.mki
echo "CC=$CC" >> sprdmpF95_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF95_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF95_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF95_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF95_mex.mki
echo "CXX=$CXX" >> sprdmpF95_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF95_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF95_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF95_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF95_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF95_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF95_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF95_mex.mki
echo "Arch=$Arch" >> sprdmpF95_mex.mki
echo "LD=$LD" >> sprdmpF95_mex.mki
echo OMPFLAGS= >> sprdmpF95_mex.mki
echo OMPLINKFLAGS= >> sprdmpF95_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF95_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF95_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF95_mex.mk
