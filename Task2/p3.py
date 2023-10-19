
n=int(input("no of elements: "))
# nums=[]
# for i in range(n):
#     a=int(input())
#     nums.append(a)

nums=list(map(int,input().split()))

nums.sort(reverse=True)
if len(nums)>=2:
    print("secend largest number: ",nums[1])
else:
    print("not enough input")