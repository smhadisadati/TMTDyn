MATLAB="/usr/local/MATLAB/R2018b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/hadi/.matlab/R2018b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for fj_vd_matF" > fj_vd_matF_mex.mki
echo "CC=$CC" >> fj_vd_matF_mex.mki
echo "CFLAGS=$CFLAGS" >> fj_vd_matF_mex.mki
echo "CLIBS=$CLIBS" >> fj_vd_matF_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> fj_vd_matF_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> fj_vd_matF_mex.mki
echo "CXX=$CXX" >> fj_vd_matF_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> fj_vd_matF_mex.mki
echo "CXXLIBS=$CXXLIBS" >> fj_vd_matF_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> fj_vd_matF_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> fj_vd_matF_mex.mki
echo "LDFLAGS=$LDFLAGS" >> fj_vd_matF_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> fj_vd_matF_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> fj_vd_matF_mex.mki
echo "Arch=$Arch" >> fj_vd_matF_mex.mki
echo "LD=$LD" >> fj_vd_matF_mex.mki
echo OMPFLAGS= >> fj_vd_matF_mex.mki
echo OMPLINKFLAGS= >> fj_vd_matF_mex.mki
echo "EMC_COMPILER=gcc" >> fj_vd_matF_mex.mki
echo "EMC_CONFIG=optim" >> fj_vd_matF_mex.mki
"/usr/local/MATLAB/R2018b/bin/glnxa64/gmake" -j 1 -B -f fj_vd_matF_mex.mk
