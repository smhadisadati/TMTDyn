MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF102" > sprdmpF102_mex.mki
echo "CC=$CC" >> sprdmpF102_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF102_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF102_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF102_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF102_mex.mki
echo "CXX=$CXX" >> sprdmpF102_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF102_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF102_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF102_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF102_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF102_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF102_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF102_mex.mki
echo "Arch=$Arch" >> sprdmpF102_mex.mki
echo "LD=$LD" >> sprdmpF102_mex.mki
echo OMPFLAGS= >> sprdmpF102_mex.mki
echo OMPLINKFLAGS= >> sprdmpF102_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF102_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF102_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF102_mex.mk
