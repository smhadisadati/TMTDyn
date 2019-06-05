MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for fj_k_matF" > fj_k_matF_mex.mki
echo "CC=$CC" >> fj_k_matF_mex.mki
echo "CFLAGS=$CFLAGS" >> fj_k_matF_mex.mki
echo "CLIBS=$CLIBS" >> fj_k_matF_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> fj_k_matF_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> fj_k_matF_mex.mki
echo "CXX=$CXX" >> fj_k_matF_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> fj_k_matF_mex.mki
echo "CXXLIBS=$CXXLIBS" >> fj_k_matF_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> fj_k_matF_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> fj_k_matF_mex.mki
echo "LDFLAGS=$LDFLAGS" >> fj_k_matF_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> fj_k_matF_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> fj_k_matF_mex.mki
echo "Arch=$Arch" >> fj_k_matF_mex.mki
echo "LD=$LD" >> fj_k_matF_mex.mki
echo OMPFLAGS= >> fj_k_matF_mex.mki
echo OMPLINKFLAGS= >> fj_k_matF_mex.mki
echo "EMC_COMPILER=gcc" >> fj_k_matF_mex.mki
echo "EMC_CONFIG=optim" >> fj_k_matF_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f fj_k_matF_mex.mk
