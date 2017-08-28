a=0
b=1
n=98
sum_total=0
for i in range(3,101):
    sum=a+b
    sum_total+=sum
    a=b
    b=sum
    print i

print sum_total
