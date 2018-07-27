# echo "Setting KPi3Alg KPi3Alg-00-00-00 in /besfs/users/songyx/workArea_664"

if test "${CMTROOT}" = ""; then
  CMTROOT=/afs/ihep.ac.cn/bes3/offline/ExternalLib/contrib/CMT/v1r20p20081118; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh

tempfile=`${CMTROOT}/mgr/cmt -quiet build temporary_name`
if test ! $? = 0 ; then tempfile=/tmp/cmt.$$; fi
${CMTROOT}/mgr/cmt setup -sh -pack=KPi3Alg -version=KPi3Alg-00-00-00 -path=/besfs/users/songyx/workArea_664  -no_cleanup $* >${tempfile}; . ${tempfile}
/bin/rm -f ${tempfile}

