MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF79" > sprdmpF79_mex.mki
echo "CC=$CC" >> sprdmpF79_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF79_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF79_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF79_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF79_mex.mki
echo "CXX=$CXX" >> sprdmpF79_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF79_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF79_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF79_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF79_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF79_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF79_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF79_mex.mki
echo "Arch=$Arch" >> sprdmpF79_mex.mki
echo "LD=$LD" >> sprdmpF79_mex.mki
echo OMPFLAGS= >> sprdmpF79_mex.mki
echo OMPLINKFLAGS= >> sprdmpF79_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF79_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF79_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF79_mex.mk
