MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF51" > sprdmpF51_mex.mki
echo "CC=$CC" >> sprdmpF51_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF51_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF51_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF51_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF51_mex.mki
echo "CXX=$CXX" >> sprdmpF51_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF51_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF51_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF51_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF51_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF51_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF51_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF51_mex.mki
echo "Arch=$Arch" >> sprdmpF51_mex.mki
echo "LD=$LD" >> sprdmpF51_mex.mki
echo OMPFLAGS= >> sprdmpF51_mex.mki
echo OMPLINKFLAGS= >> sprdmpF51_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF51_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF51_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF51_mex.mk
