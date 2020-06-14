MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF78" > sprdmpF78_mex.mki
echo "CC=$CC" >> sprdmpF78_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF78_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF78_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF78_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF78_mex.mki
echo "CXX=$CXX" >> sprdmpF78_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF78_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF78_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF78_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF78_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF78_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF78_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF78_mex.mki
echo "Arch=$Arch" >> sprdmpF78_mex.mki
echo "LD=$LD" >> sprdmpF78_mex.mki
echo OMPFLAGS= >> sprdmpF78_mex.mki
echo OMPLINKFLAGS= >> sprdmpF78_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF78_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF78_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF78_mex.mk
