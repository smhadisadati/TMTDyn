MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF59" > sprdmpF59_mex.mki
echo "CC=$CC" >> sprdmpF59_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF59_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF59_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF59_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF59_mex.mki
echo "CXX=$CXX" >> sprdmpF59_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF59_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF59_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF59_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF59_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF59_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF59_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF59_mex.mki
echo "Arch=$Arch" >> sprdmpF59_mex.mki
echo "LD=$LD" >> sprdmpF59_mex.mki
echo OMPFLAGS= >> sprdmpF59_mex.mki
echo OMPLINKFLAGS= >> sprdmpF59_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF59_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF59_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF59_mex.mk
