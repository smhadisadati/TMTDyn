MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF71" > sprdmpF71_mex.mki
echo "CC=$CC" >> sprdmpF71_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF71_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF71_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF71_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF71_mex.mki
echo "CXX=$CXX" >> sprdmpF71_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF71_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF71_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF71_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF71_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF71_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF71_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF71_mex.mki
echo "Arch=$Arch" >> sprdmpF71_mex.mki
echo "LD=$LD" >> sprdmpF71_mex.mki
echo OMPFLAGS= >> sprdmpF71_mex.mki
echo OMPLINKFLAGS= >> sprdmpF71_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF71_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF71_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF71_mex.mk
