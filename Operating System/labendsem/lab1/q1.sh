mkdir ~/dir
cd ~/dir
mkdir dir1 dir2
cd dir1
cat > file1.txt << DELIMETER
You are in File 1 
DELIMETER
cat > file2.txt << DELIMETER
You are in File 2
DELIMETER
cat > file3.txt << DELIMETER
You are in File 3
DELIMETER
cp file1.txt ../dir2
cd ../dir2
cat > anoofusers.txt << DELIMETER
echo Users : `who|wc -l` Files : `ls -l | grep "^-" | wc -l`
DELIMETER
cd ~
echo `ls -p | grep -v \ | grep -E "^[aA]"`
cd dir/dir2
cat > cprog.c << DELIMETER
#include<stdio.h>
int main()
{
	printf("\n Hello World");
}
DELIMETER
cc cprog.c && ./a.out
