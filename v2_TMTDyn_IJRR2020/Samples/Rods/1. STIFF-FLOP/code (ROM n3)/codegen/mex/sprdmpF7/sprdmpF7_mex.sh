MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF7" > sprdmpF7_mex.mki
echo "CC=$CC" >> sprdmpF7_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF7_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF7_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF7_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF7_mex.mki
echo "CXX=$CXX" >> sprdmpF7_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF7_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF7_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF7_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF7_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF7_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF7_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF7_mex.mki
echo "Arch=$Arch" >> sprdmpF7_mex.mki
echo "LD=$LD" >> sprdmpF7_mex.mki
echo OMPFLAGS= >> sprdmpF7_mex.mki
echo OMPLINKFLAGS= >> sprdmpF7_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF7_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF7_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF7_mex.mk
