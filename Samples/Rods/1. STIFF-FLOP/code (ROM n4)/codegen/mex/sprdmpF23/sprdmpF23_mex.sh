MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF23" > sprdmpF23_mex.mki
echo "CC=$CC" >> sprdmpF23_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF23_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF23_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF23_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF23_mex.mki
echo "CXX=$CXX" >> sprdmpF23_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF23_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF23_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF23_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF23_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF23_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF23_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF23_mex.mki
echo "Arch=$Arch" >> sprdmpF23_mex.mki
echo "LD=$LD" >> sprdmpF23_mex.mki
echo OMPFLAGS= >> sprdmpF23_mex.mki
echo OMPLINKFLAGS= >> sprdmpF23_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF23_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF23_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF23_mex.mk
