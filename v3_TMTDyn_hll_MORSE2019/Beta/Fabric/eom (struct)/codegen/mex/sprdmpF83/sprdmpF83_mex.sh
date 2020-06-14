MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF83" > sprdmpF83_mex.mki
echo "CC=$CC" >> sprdmpF83_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF83_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF83_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF83_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF83_mex.mki
echo "CXX=$CXX" >> sprdmpF83_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF83_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF83_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF83_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF83_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF83_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF83_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF83_mex.mki
echo "Arch=$Arch" >> sprdmpF83_mex.mki
echo "LD=$LD" >> sprdmpF83_mex.mki
echo OMPFLAGS= >> sprdmpF83_mex.mki
echo OMPLINKFLAGS= >> sprdmpF83_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF83_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF83_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF83_mex.mk
