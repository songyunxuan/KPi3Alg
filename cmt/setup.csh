# echo "Setting KPi3Alg KPi3Alg-00-00-00 in /besfs/users/songyx/workArea_664"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /afs/ihep.ac.cn/bes3/offline/ExternalLib/contrib/CMT/v1r20p20081118
endif
source ${CMTROOT}/mgr/setup.csh

set tempfile=`${CMTROOT}/mgr/cmt -quiet build temporary_name`
if $status != 0 then
  set tempfile=/tmp/cmt.$$
endif
${CMTROOT}/mgr/cmt setup -csh -pack=KPi3Alg -version=KPi3Alg-00-00-00 -path=/besfs/users/songyx/workArea_664  -no_cleanup $* >${tempfile}; source ${tempfile}
/bin/rm -f ${tempfile}

