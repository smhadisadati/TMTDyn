MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF62" > sprdmpF62_mex.mki
echo "CC=$CC" >> sprdmpF62_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF62_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF62_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF62_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF62_mex.mki
echo "CXX=$CXX" >> sprdmpF62_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF62_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF62_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF62_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF62_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF62_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF62_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF62_mex.mki
echo "Arch=$Arch" >> sprdmpF62_mex.mki
echo "LD=$LD" >> sprdmpF62_mex.mki
echo OMPFLAGS= >> sprdmpF62_mex.mki
echo OMPLINKFLAGS= >> sprdmpF62_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF62_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF62_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF62_mex.mk
