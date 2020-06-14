MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF61" > sprdmpF61_mex.mki
echo "CC=$CC" >> sprdmpF61_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF61_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF61_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF61_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF61_mex.mki
echo "CXX=$CXX" >> sprdmpF61_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF61_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF61_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF61_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF61_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF61_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF61_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF61_mex.mki
echo "Arch=$Arch" >> sprdmpF61_mex.mki
echo "LD=$LD" >> sprdmpF61_mex.mki
echo OMPFLAGS= >> sprdmpF61_mex.mki
echo OMPLINKFLAGS= >> sprdmpF61_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF61_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF61_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF61_mex.mk
