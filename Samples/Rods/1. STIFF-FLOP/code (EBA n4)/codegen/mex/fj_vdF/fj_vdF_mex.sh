MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for fj_vdF" > fj_vdF_mex.mki
echo "CC=$CC" >> fj_vdF_mex.mki
echo "CFLAGS=$CFLAGS" >> fj_vdF_mex.mki
echo "CLIBS=$CLIBS" >> fj_vdF_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> fj_vdF_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> fj_vdF_mex.mki
echo "CXX=$CXX" >> fj_vdF_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> fj_vdF_mex.mki
echo "CXXLIBS=$CXXLIBS" >> fj_vdF_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> fj_vdF_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> fj_vdF_mex.mki
echo "LDFLAGS=$LDFLAGS" >> fj_vdF_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> fj_vdF_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> fj_vdF_mex.mki
echo "Arch=$Arch" >> fj_vdF_mex.mki
echo "LD=$LD" >> fj_vdF_mex.mki
echo OMPFLAGS= >> fj_vdF_mex.mki
echo OMPLINKFLAGS= >> fj_vdF_mex.mki
echo "EMC_COMPILER=gcc" >> fj_vdF_mex.mki
echo "EMC_CONFIG=optim" >> fj_vdF_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f fj_vdF_mex.mk
