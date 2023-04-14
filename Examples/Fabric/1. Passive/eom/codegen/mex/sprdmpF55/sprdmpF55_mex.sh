MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF55" > sprdmpF55_mex.mki
echo "CC=$CC" >> sprdmpF55_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF55_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF55_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF55_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF55_mex.mki
echo "CXX=$CXX" >> sprdmpF55_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF55_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF55_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF55_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF55_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF55_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF55_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF55_mex.mki
echo "Arch=$Arch" >> sprdmpF55_mex.mki
echo "LD=$LD" >> sprdmpF55_mex.mki
echo OMPFLAGS= >> sprdmpF55_mex.mki
echo OMPLINKFLAGS= >> sprdmpF55_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF55_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF55_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF55_mex.mk
