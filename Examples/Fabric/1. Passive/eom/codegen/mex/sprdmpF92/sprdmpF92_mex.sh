MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF92" > sprdmpF92_mex.mki
echo "CC=$CC" >> sprdmpF92_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF92_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF92_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF92_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF92_mex.mki
echo "CXX=$CXX" >> sprdmpF92_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF92_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF92_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF92_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF92_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF92_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF92_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF92_mex.mki
echo "Arch=$Arch" >> sprdmpF92_mex.mki
echo "LD=$LD" >> sprdmpF92_mex.mki
echo OMPFLAGS= >> sprdmpF92_mex.mki
echo OMPLINKFLAGS= >> sprdmpF92_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF92_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF92_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF92_mex.mk
