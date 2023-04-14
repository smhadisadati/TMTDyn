MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF53" > sprdmpF53_mex.mki
echo "CC=$CC" >> sprdmpF53_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF53_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF53_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF53_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF53_mex.mki
echo "CXX=$CXX" >> sprdmpF53_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF53_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF53_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF53_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF53_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF53_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF53_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF53_mex.mki
echo "Arch=$Arch" >> sprdmpF53_mex.mki
echo "LD=$LD" >> sprdmpF53_mex.mki
echo OMPFLAGS= >> sprdmpF53_mex.mki
echo OMPLINKFLAGS= >> sprdmpF53_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF53_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF53_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF53_mex.mk
