MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF80" > sprdmpF80_mex.mki
echo "CC=$CC" >> sprdmpF80_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF80_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF80_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF80_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF80_mex.mki
echo "CXX=$CXX" >> sprdmpF80_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF80_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF80_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF80_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF80_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF80_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF80_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF80_mex.mki
echo "Arch=$Arch" >> sprdmpF80_mex.mki
echo "LD=$LD" >> sprdmpF80_mex.mki
echo OMPFLAGS= >> sprdmpF80_mex.mki
echo OMPLINKFLAGS= >> sprdmpF80_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF80_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF80_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF80_mex.mk
