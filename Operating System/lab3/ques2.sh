echo "Enter Directory"
read directory
cd $HOME
cd $directory
rm `ls -t | tail -1`


