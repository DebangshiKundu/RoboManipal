
nums=list(map(int,input("Enter the numbers: ").split()))
res=[]
for i in nums:
    if(i%7==0 and i%5 !=0 and i>=2000 and i<=3200 ):
        res.append(str(i))

res=', '.join(res)

print(res)

