MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for EOM_eq" > EOM_eq_mex.mki
echo "CC=$CC" >> EOM_eq_mex.mki
echo "CFLAGS=$CFLAGS" >> EOM_eq_mex.mki
echo "CLIBS=$CLIBS" >> EOM_eq_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> EOM_eq_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> EOM_eq_mex.mki
echo "CXX=$CXX" >> EOM_eq_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> EOM_eq_mex.mki
echo "CXXLIBS=$CXXLIBS" >> EOM_eq_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> EOM_eq_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> EOM_eq_mex.mki
echo "LDFLAGS=$LDFLAGS" >> EOM_eq_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> EOM_eq_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> EOM_eq_mex.mki
echo "Arch=$Arch" >> EOM_eq_mex.mki
echo "LD=$LD" >> EOM_eq_mex.mki
echo OMPFLAGS= >> EOM_eq_mex.mki
echo OMPLINKFLAGS= >> EOM_eq_mex.mki
echo "EMC_COMPILER=gcc" >> EOM_eq_mex.mki
echo "EMC_CONFIG=optim" >> EOM_eq_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f EOM_eq_mex.mk
