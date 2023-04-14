MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF18" > sprdmpF18_mex.mki
echo "CC=$CC" >> sprdmpF18_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF18_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF18_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF18_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF18_mex.mki
echo "CXX=$CXX" >> sprdmpF18_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF18_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF18_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF18_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF18_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF18_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF18_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF18_mex.mki
echo "Arch=$Arch" >> sprdmpF18_mex.mki
echo "LD=$LD" >> sprdmpF18_mex.mki
echo OMPFLAGS= >> sprdmpF18_mex.mki
echo OMPLINKFLAGS= >> sprdmpF18_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF18_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF18_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF18_mex.mk
