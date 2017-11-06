declare -a teamnames
teamnames[0]="India"
teamnames[1]="England"
teamnames[2]="Nepal"

echo "There are : ${#teamnames[*]} teams"
echo "They are : ${teamnames[*]}"
unset teamnames

#cd ~
#alias dir="ls -l"
#dir

x=1
x=`expr $x+1`
echo $x
x=`expr 2+3\*5`
echo $x
echo `expr \(4\>5\)`
Str="cat"
#echo ${#Str}
echo `expr length "cat"`
echo `expr substr "donkey" 4 3`

x=2
y=3
z=`expr $x + $y`
echo $z
x=4
y=6
#$z = $($x + $y)
#echo $z