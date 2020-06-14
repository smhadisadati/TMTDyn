MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF119" > sprdmpF119_mex.mki
echo "CC=$CC" >> sprdmpF119_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF119_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF119_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF119_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF119_mex.mki
echo "CXX=$CXX" >> sprdmpF119_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF119_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF119_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF119_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF119_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF119_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF119_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF119_mex.mki
echo "Arch=$Arch" >> sprdmpF119_mex.mki
echo "LD=$LD" >> sprdmpF119_mex.mki
echo OMPFLAGS= >> sprdmpF119_mex.mki
echo OMPLINKFLAGS= >> sprdmpF119_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF119_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF119_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF119_mex.mk
