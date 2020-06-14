MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF47" > sprdmpF47_mex.mki
echo "CC=$CC" >> sprdmpF47_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF47_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF47_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF47_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF47_mex.mki
echo "CXX=$CXX" >> sprdmpF47_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF47_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF47_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF47_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF47_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF47_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF47_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF47_mex.mki
echo "Arch=$Arch" >> sprdmpF47_mex.mki
echo "LD=$LD" >> sprdmpF47_mex.mki
echo OMPFLAGS= >> sprdmpF47_mex.mki
echo OMPLINKFLAGS= >> sprdmpF47_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF47_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF47_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF47_mex.mk
