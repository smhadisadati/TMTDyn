MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF107" > sprdmpF107_mex.mki
echo "CC=$CC" >> sprdmpF107_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF107_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF107_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF107_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF107_mex.mki
echo "CXX=$CXX" >> sprdmpF107_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF107_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF107_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF107_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF107_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF107_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF107_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF107_mex.mki
echo "Arch=$Arch" >> sprdmpF107_mex.mki
echo "LD=$LD" >> sprdmpF107_mex.mki
echo OMPFLAGS= >> sprdmpF107_mex.mki
echo OMPLINKFLAGS= >> sprdmpF107_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF107_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF107_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF107_mex.mk
