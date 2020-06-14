MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF11" > sprdmpF11_mex.mki
echo "CC=$CC" >> sprdmpF11_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF11_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF11_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF11_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF11_mex.mki
echo "CXX=$CXX" >> sprdmpF11_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF11_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF11_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF11_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF11_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF11_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF11_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF11_mex.mki
echo "Arch=$Arch" >> sprdmpF11_mex.mki
echo "LD=$LD" >> sprdmpF11_mex.mki
echo OMPFLAGS= >> sprdmpF11_mex.mki
echo OMPLINKFLAGS= >> sprdmpF11_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF11_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF11_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF11_mex.mk
