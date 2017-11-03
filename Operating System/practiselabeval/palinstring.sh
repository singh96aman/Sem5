read name
len=`expr length $name`

while [ $len -gt 0 ]
do
	y=`expr substr $name $len 1`
	x=${x}$y
	len=`expr $len -1`
done
if [ $x -eq43 $name ]
	then
	echo "Palindrome"
else
	echo "Not a Palindrome"
fi