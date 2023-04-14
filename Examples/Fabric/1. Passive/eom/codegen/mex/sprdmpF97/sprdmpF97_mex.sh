MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF97" > sprdmpF97_mex.mki
echo "CC=$CC" >> sprdmpF97_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF97_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF97_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF97_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF97_mex.mki
echo "CXX=$CXX" >> sprdmpF97_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF97_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF97_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF97_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF97_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF97_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF97_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF97_mex.mki
echo "Arch=$Arch" >> sprdmpF97_mex.mki
echo "LD=$LD" >> sprdmpF97_mex.mki
echo OMPFLAGS= >> sprdmpF97_mex.mki
echo OMPLINKFLAGS= >> sprdmpF97_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF97_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF97_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF97_mex.mk
