MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF1" > sprdmpF1_mex.mki
echo "CC=$CC" >> sprdmpF1_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF1_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF1_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF1_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF1_mex.mki
echo "CXX=$CXX" >> sprdmpF1_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF1_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF1_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF1_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF1_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF1_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF1_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF1_mex.mki
echo "Arch=$Arch" >> sprdmpF1_mex.mki
echo "LD=$LD" >> sprdmpF1_mex.mki
echo OMPFLAGS= >> sprdmpF1_mex.mki
echo OMPLINKFLAGS= >> sprdmpF1_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF1_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF1_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF1_mex.mk
