x1=int(input("Enter x1 :"))
y1=int(input("Enter y1 :"))
x2=int(input("Enter x2 :"))
y2=int(input("Enter y1 :"))

Dx = x2 - x1
print("\nDx = ", Dx)
Dy = y2 - y1
print("Dy = ", Dy)

flag = 0

mDx = Dx
mDy = Dy
if(Dx<0):
    mDx = Dx*(-1)
    flag = 1
if(Dy<0):
    mDy = Dy*(-1)
    flag = 1

if(mDx>mDy):
    xinc = Dx/mDx
    yinc = Dy/mDx
    steps = mDx
    if(x2>x1):
        xinc = 1
    else:
        xinc = -1
        flag = 1
    
else:
    xinc = Dx/mDy
    yinc = Dy/mDy
    steps = mDy
    if(y2>y1):
        yinc = 1
    else:
        yinc = -1
        flag = 1

print(f"xinc = {xinc}\nyinc = {yinc}")
x=x1
y=y1
print(f"x | y")
print(f"{x} | {y}")
i=0
while(i<steps):
    x = x+xinc
    y = y+yinc                              
    # print(f"{x} | {y}")
    xi = round(x)
    yi = round(y)
    if(x==(int(x)+0.5)):
            xi = xi + 1
    if(y==(int(y)+0.5)):
            yi = yi + 1
    print(f"{xi} | {yi}")
    i = i + 1