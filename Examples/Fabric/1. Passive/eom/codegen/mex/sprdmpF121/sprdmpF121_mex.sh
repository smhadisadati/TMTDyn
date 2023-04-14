MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF121" > sprdmpF121_mex.mki
echo "CC=$CC" >> sprdmpF121_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF121_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF121_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF121_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF121_mex.mki
echo "CXX=$CXX" >> sprdmpF121_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF121_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF121_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF121_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF121_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF121_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF121_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF121_mex.mki
echo "Arch=$Arch" >> sprdmpF121_mex.mki
echo "LD=$LD" >> sprdmpF121_mex.mki
echo OMPFLAGS= >> sprdmpF121_mex.mki
echo OMPLINKFLAGS= >> sprdmpF121_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF121_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF121_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF121_mex.mk
