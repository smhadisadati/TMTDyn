MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF22" > sprdmpF22_mex.mki
echo "CC=$CC" >> sprdmpF22_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF22_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF22_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF22_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF22_mex.mki
echo "CXX=$CXX" >> sprdmpF22_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF22_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF22_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF22_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF22_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF22_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF22_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF22_mex.mki
echo "Arch=$Arch" >> sprdmpF22_mex.mki
echo "LD=$LD" >> sprdmpF22_mex.mki
echo OMPFLAGS= >> sprdmpF22_mex.mki
echo OMPLINKFLAGS= >> sprdmpF22_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF22_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF22_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF22_mex.mk
