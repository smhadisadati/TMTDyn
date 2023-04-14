MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF42" > sprdmpF42_mex.mki
echo "CC=$CC" >> sprdmpF42_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF42_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF42_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF42_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF42_mex.mki
echo "CXX=$CXX" >> sprdmpF42_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF42_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF42_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF42_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF42_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF42_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF42_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF42_mex.mki
echo "Arch=$Arch" >> sprdmpF42_mex.mki
echo "LD=$LD" >> sprdmpF42_mex.mki
echo OMPFLAGS= >> sprdmpF42_mex.mki
echo OMPLINKFLAGS= >> sprdmpF42_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF42_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF42_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF42_mex.mk
