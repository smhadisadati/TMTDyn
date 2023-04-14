MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF74" > sprdmpF74_mex.mki
echo "CC=$CC" >> sprdmpF74_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF74_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF74_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF74_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF74_mex.mki
echo "CXX=$CXX" >> sprdmpF74_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF74_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF74_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF74_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF74_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF74_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF74_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF74_mex.mki
echo "Arch=$Arch" >> sprdmpF74_mex.mki
echo "LD=$LD" >> sprdmpF74_mex.mki
echo OMPFLAGS= >> sprdmpF74_mex.mki
echo OMPLINKFLAGS= >> sprdmpF74_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF74_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF74_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF74_mex.mk
