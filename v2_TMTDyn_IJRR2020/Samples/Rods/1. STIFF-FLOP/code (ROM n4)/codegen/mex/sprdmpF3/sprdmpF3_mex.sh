MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF3" > sprdmpF3_mex.mki
echo "CC=$CC" >> sprdmpF3_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF3_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF3_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF3_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF3_mex.mki
echo "CXX=$CXX" >> sprdmpF3_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF3_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF3_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF3_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF3_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF3_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF3_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF3_mex.mki
echo "Arch=$Arch" >> sprdmpF3_mex.mki
echo "LD=$LD" >> sprdmpF3_mex.mki
echo OMPFLAGS= >> sprdmpF3_mex.mki
echo OMPLINKFLAGS= >> sprdmpF3_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF3_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF3_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF3_mex.mk
