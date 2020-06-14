MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF66" > sprdmpF66_mex.mki
echo "CC=$CC" >> sprdmpF66_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF66_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF66_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF66_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF66_mex.mki
echo "CXX=$CXX" >> sprdmpF66_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF66_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF66_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF66_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF66_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF66_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF66_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF66_mex.mki
echo "Arch=$Arch" >> sprdmpF66_mex.mki
echo "LD=$LD" >> sprdmpF66_mex.mki
echo OMPFLAGS= >> sprdmpF66_mex.mki
echo OMPLINKFLAGS= >> sprdmpF66_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF66_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF66_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF66_mex.mk
