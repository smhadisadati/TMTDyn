MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF112" > sprdmpF112_mex.mki
echo "CC=$CC" >> sprdmpF112_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF112_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF112_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF112_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF112_mex.mki
echo "CXX=$CXX" >> sprdmpF112_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF112_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF112_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF112_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF112_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF112_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF112_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF112_mex.mki
echo "Arch=$Arch" >> sprdmpF112_mex.mki
echo "LD=$LD" >> sprdmpF112_mex.mki
echo OMPFLAGS= >> sprdmpF112_mex.mki
echo OMPLINKFLAGS= >> sprdmpF112_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF112_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF112_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF112_mex.mk
