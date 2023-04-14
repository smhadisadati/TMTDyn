MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF54" > sprdmpF54_mex.mki
echo "CC=$CC" >> sprdmpF54_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF54_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF54_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF54_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF54_mex.mki
echo "CXX=$CXX" >> sprdmpF54_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF54_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF54_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF54_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF54_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF54_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF54_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF54_mex.mki
echo "Arch=$Arch" >> sprdmpF54_mex.mki
echo "LD=$LD" >> sprdmpF54_mex.mki
echo OMPFLAGS= >> sprdmpF54_mex.mki
echo OMPLINKFLAGS= >> sprdmpF54_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF54_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF54_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF54_mex.mk
