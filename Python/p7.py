
# 7)	Given 2 points (x1,y1) and (x2,y2), where x1, x2 are x-coordinates and y1, y2 are y-coordinates of the points. Compute the distance between them.

x1=float(input("Enter x1:"))
y1=float(input("Enter y1:"))
x2=float(input("Enter x2:"))
y2=float(input("Enter y2:"))

res=((x2-x1)** 2 + (y2-y1)**2)**0.5
print("The ditance between the 2 points is:",res)
