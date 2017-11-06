cd TOCFOLDER
x=`ls`
for files in $x
do
	if [ `grep $files TOC.txt | wc -l` -eq 0 ]
	then
		echo $files >> TOC.txt
	fi
done                                                  