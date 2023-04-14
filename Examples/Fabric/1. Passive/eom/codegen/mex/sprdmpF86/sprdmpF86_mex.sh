MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF86" > sprdmpF86_mex.mki
echo "CC=$CC" >> sprdmpF86_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF86_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF86_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF86_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF86_mex.mki
echo "CXX=$CXX" >> sprdmpF86_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF86_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF86_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF86_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF86_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF86_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF86_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF86_mex.mki
echo "Arch=$Arch" >> sprdmpF86_mex.mki
echo "LD=$LD" >> sprdmpF86_mex.mki
echo OMPFLAGS= >> sprdmpF86_mex.mki
echo OMPLINKFLAGS= >> sprdmpF86_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF86_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF86_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF86_mex.mk
