MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF10" > sprdmpF10_mex.mki
echo "CC=$CC" >> sprdmpF10_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF10_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF10_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF10_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF10_mex.mki
echo "CXX=$CXX" >> sprdmpF10_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF10_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF10_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF10_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF10_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF10_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF10_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF10_mex.mki
echo "Arch=$Arch" >> sprdmpF10_mex.mki
echo "LD=$LD" >> sprdmpF10_mex.mki
echo OMPFLAGS= >> sprdmpF10_mex.mki
echo OMPLINKFLAGS= >> sprdmpF10_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF10_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF10_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF10_mex.mk
