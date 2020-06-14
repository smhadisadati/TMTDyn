MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF116" > sprdmpF116_mex.mki
echo "CC=$CC" >> sprdmpF116_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF116_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF116_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF116_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF116_mex.mki
echo "CXX=$CXX" >> sprdmpF116_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF116_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF116_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF116_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF116_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF116_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF116_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF116_mex.mki
echo "Arch=$Arch" >> sprdmpF116_mex.mki
echo "LD=$LD" >> sprdmpF116_mex.mki
echo OMPFLAGS= >> sprdmpF116_mex.mki
echo OMPLINKFLAGS= >> sprdmpF116_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF116_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF116_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF116_mex.mk
