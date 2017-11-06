echo "Enter Name"
read name

echo "Enter Directory"
read dir

cd ~/$dir

#checking directory
file=`ls -d */`
for f in $file
do
	if [ $name == $f ]
	then
		echo "It's a Directory"
	fi
done

#checking file
file=`ls`
for f in $file
do
	if [ $name == $f ]
	then
		echo "It's a File"
	fi
done

#checking subdirectory
file=`ls -R`
for f in $file
do 
	if [ $name == $f ]
	then
		echo "It's a subdirectory"
	fi
done