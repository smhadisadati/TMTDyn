MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF31" > sprdmpF31_mex.mki
echo "CC=$CC" >> sprdmpF31_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF31_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF31_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF31_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF31_mex.mki
echo "CXX=$CXX" >> sprdmpF31_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF31_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF31_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF31_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF31_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF31_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF31_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF31_mex.mki
echo "Arch=$Arch" >> sprdmpF31_mex.mki
echo "LD=$LD" >> sprdmpF31_mex.mki
echo OMPFLAGS= >> sprdmpF31_mex.mki
echo OMPLINKFLAGS= >> sprdmpF31_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF31_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF31_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF31_mex.mk
