MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF69" > sprdmpF69_mex.mki
echo "CC=$CC" >> sprdmpF69_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF69_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF69_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF69_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF69_mex.mki
echo "CXX=$CXX" >> sprdmpF69_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF69_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF69_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF69_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF69_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF69_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF69_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF69_mex.mki
echo "Arch=$Arch" >> sprdmpF69_mex.mki
echo "LD=$LD" >> sprdmpF69_mex.mki
echo OMPFLAGS= >> sprdmpF69_mex.mki
echo OMPLINKFLAGS= >> sprdmpF69_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF69_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF69_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF69_mex.mk
