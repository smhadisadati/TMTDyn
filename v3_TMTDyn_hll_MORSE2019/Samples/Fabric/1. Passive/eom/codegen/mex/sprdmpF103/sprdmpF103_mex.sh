MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF103" > sprdmpF103_mex.mki
echo "CC=$CC" >> sprdmpF103_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF103_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF103_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF103_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF103_mex.mki
echo "CXX=$CXX" >> sprdmpF103_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF103_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF103_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF103_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF103_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF103_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF103_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF103_mex.mki
echo "Arch=$Arch" >> sprdmpF103_mex.mki
echo "LD=$LD" >> sprdmpF103_mex.mki
echo OMPFLAGS= >> sprdmpF103_mex.mki
echo OMPLINKFLAGS= >> sprdmpF103_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF103_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF103_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF103_mex.mk
