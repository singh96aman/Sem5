read num
x=0
y=num
while [ $num -gt 0 ]
do
	y=`expr $num % 10`
	x=`expr $x \* 10 + $y`
	num=`expr $num / 10`
done
echo $y
if [ $x -eq $y ]
then 
echo "palindrome"
else 
echo "Not a palindrome"
fi 