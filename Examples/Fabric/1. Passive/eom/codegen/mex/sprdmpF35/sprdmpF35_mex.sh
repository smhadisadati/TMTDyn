MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF35" > sprdmpF35_mex.mki
echo "CC=$CC" >> sprdmpF35_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF35_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF35_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF35_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF35_mex.mki
echo "CXX=$CXX" >> sprdmpF35_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF35_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF35_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF35_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF35_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF35_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF35_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF35_mex.mki
echo "Arch=$Arch" >> sprdmpF35_mex.mki
echo "LD=$LD" >> sprdmpF35_mex.mki
echo OMPFLAGS= >> sprdmpF35_mex.mki
echo OMPLINKFLAGS= >> sprdmpF35_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF35_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF35_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF35_mex.mk
