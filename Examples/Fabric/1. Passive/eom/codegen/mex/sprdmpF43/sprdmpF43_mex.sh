MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF43" > sprdmpF43_mex.mki
echo "CC=$CC" >> sprdmpF43_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF43_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF43_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF43_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF43_mex.mki
echo "CXX=$CXX" >> sprdmpF43_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF43_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF43_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF43_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF43_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF43_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF43_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF43_mex.mki
echo "Arch=$Arch" >> sprdmpF43_mex.mki
echo "LD=$LD" >> sprdmpF43_mex.mki
echo OMPFLAGS= >> sprdmpF43_mex.mki
echo OMPLINKFLAGS= >> sprdmpF43_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF43_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF43_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF43_mex.mk
