MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF63" > sprdmpF63_mex.mki
echo "CC=$CC" >> sprdmpF63_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF63_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF63_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF63_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF63_mex.mki
echo "CXX=$CXX" >> sprdmpF63_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF63_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF63_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF63_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF63_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF63_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF63_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF63_mex.mki
echo "Arch=$Arch" >> sprdmpF63_mex.mki
echo "LD=$LD" >> sprdmpF63_mex.mki
echo OMPFLAGS= >> sprdmpF63_mex.mki
echo OMPLINKFLAGS= >> sprdmpF63_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF63_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF63_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF63_mex.mk
