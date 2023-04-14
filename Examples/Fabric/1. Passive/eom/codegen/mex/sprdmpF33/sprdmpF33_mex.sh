MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF33" > sprdmpF33_mex.mki
echo "CC=$CC" >> sprdmpF33_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF33_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF33_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF33_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF33_mex.mki
echo "CXX=$CXX" >> sprdmpF33_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF33_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF33_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF33_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF33_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF33_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF33_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF33_mex.mki
echo "Arch=$Arch" >> sprdmpF33_mex.mki
echo "LD=$LD" >> sprdmpF33_mex.mki
echo OMPFLAGS= >> sprdmpF33_mex.mki
echo OMPLINKFLAGS= >> sprdmpF33_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF33_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF33_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF33_mex.mk
