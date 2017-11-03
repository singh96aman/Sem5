echo The name of this script is $0
echo the first argument is $1
echo a list of all the arguments is $*
echo this script places the date into a temp file
echo called $1.$$
date > $1.$$
ls $1.$$
rm $1.$$

firstname=Rakesh
lastname=Sharma
echo firstname
echo $firstname
echo $lastname
#export firstname
#sh
echo $firstname $lastname
#^D
echo $firstname $lastname

verb=sing
echo I like ${verb}ing
date
startDate=${startDate-`date`}
echo $startDate
x=5
echo x=${x=10}
echo $x

echo "Please Enter Your Name : "
read name
echo your name is $name

sort no.txt

password=manipal
echo $password
readonly password
readonly
echo $password

ps
kill 1662
sleep 2
echo "aman"

wait 2


