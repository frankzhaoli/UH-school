def f(m,n)
{
   if m==2:
      return n-1
   else:
      return f(m-1,n+2)
}

def f2(i)
{
   if i==0:
      return 1
   else:
      return f(i)
}

f2(0)
f(3,4)
