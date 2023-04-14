MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for sprdmpF96" > sprdmpF96_mex.mki
echo "CC=$CC" >> sprdmpF96_mex.mki
echo "CFLAGS=$CFLAGS" >> sprdmpF96_mex.mki
echo "CLIBS=$CLIBS" >> sprdmpF96_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> sprdmpF96_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> sprdmpF96_mex.mki
echo "CXX=$CXX" >> sprdmpF96_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> sprdmpF96_mex.mki
echo "CXXLIBS=$CXXLIBS" >> sprdmpF96_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> sprdmpF96_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> sprdmpF96_mex.mki
echo "LDFLAGS=$LDFLAGS" >> sprdmpF96_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> sprdmpF96_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> sprdmpF96_mex.mki
echo "Arch=$Arch" >> sprdmpF96_mex.mki
echo "LD=$LD" >> sprdmpF96_mex.mki
echo OMPFLAGS= >> sprdmpF96_mex.mki
echo OMPLINKFLAGS= >> sprdmpF96_mex.mki
echo "EMC_COMPILER=gcc" >> sprdmpF96_mex.mki
echo "EMC_CONFIG=optim" >> sprdmpF96_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f sprdmpF96_mex.mk
