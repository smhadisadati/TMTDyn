MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF34" > sprdmpF34_mex.mki
echo "CC=$CC" >> sprdmpF34_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF34_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF34_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF34_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF34_mex.mki
echo "CXX=$CXX" >> sprdmpF34_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF34_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF34_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF34_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF34_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF34_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF34_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF34_mex.mki
echo "Arch=$Arch" >> sprdmpF34_mex.mki
echo "LD=$LD" >> sprdmpF34_mex.mki
echo OMPFLAGS= >> sprdmpF34_mex.mki
echo OMPLINKFLAGS= >> sprdmpF34_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF34_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF34_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF34_mex.mk
