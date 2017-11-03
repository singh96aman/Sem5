echo "Enter the number"
read number
if [ $number -lt 0 ]
then
echo "negative"
elif [ $number -eq 0 ]
then
echo "zero"
else
echo "positive"
fi

echo "1. Date 2/3. PWD 4.Exit"
read reply
echo
case $reply in
"1") date
;;
"2"|"3")pwd
;;
"4") exit
esac

X=0
while [ $X -le 20 ]
do
	echo $X
	X=$((X+1))
done

x=1
until [ $x -gt 3 ]
do
	echo x=$x
	x=`expr $x + 1`
done