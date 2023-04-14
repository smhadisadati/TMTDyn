MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF56" > sprdmpF56_mex.mki
echo "CC=$CC" >> sprdmpF56_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF56_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF56_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF56_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF56_mex.mki
echo "CXX=$CXX" >> sprdmpF56_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF56_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF56_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF56_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF56_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF56_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF56_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF56_mex.mki
echo "Arch=$Arch" >> sprdmpF56_mex.mki
echo "LD=$LD" >> sprdmpF56_mex.mki
echo OMPFLAGS= >> sprdmpF56_mex.mki
echo OMPLINKFLAGS= >> sprdmpF56_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF56_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF56_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF56_mex.mk
