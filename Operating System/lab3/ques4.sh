cat file1.txt file2.txt > "file3.txt"
x=`sort ./file3.txt -u -n`
echo $x > file3.txt
