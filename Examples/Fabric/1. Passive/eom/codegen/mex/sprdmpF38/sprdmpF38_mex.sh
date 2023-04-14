MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF38" > sprdmpF38_mex.mki
echo "CC=$CC" >> sprdmpF38_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF38_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF38_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF38_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF38_mex.mki
echo "CXX=$CXX" >> sprdmpF38_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF38_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF38_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF38_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF38_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF38_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF38_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF38_mex.mki
echo "Arch=$Arch" >> sprdmpF38_mex.mki
echo "LD=$LD" >> sprdmpF38_mex.mki
echo OMPFLAGS= >> sprdmpF38_mex.mki
echo OMPLINKFLAGS= >> sprdmpF38_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF38_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF38_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF38_mex.mk
