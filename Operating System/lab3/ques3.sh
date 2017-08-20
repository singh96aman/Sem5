directory=$1
cd $directory
home=`ls`
for files in $home
do
if [ `grep $files TOC.txt | wc -l` -eq 0 ] 
then
echo $files>>TOC.txt 
fi
done


