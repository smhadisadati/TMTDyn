MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF99" > sprdmpF99_mex.mki
echo "CC=$CC" >> sprdmpF99_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF99_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF99_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF99_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF99_mex.mki
echo "CXX=$CXX" >> sprdmpF99_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF99_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF99_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF99_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF99_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF99_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF99_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF99_mex.mki
echo "Arch=$Arch" >> sprdmpF99_mex.mki
echo "LD=$LD" >> sprdmpF99_mex.mki
echo OMPFLAGS= >> sprdmpF99_mex.mki
echo OMPLINKFLAGS= >> sprdmpF99_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF99_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF99_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF99_mex.mk
