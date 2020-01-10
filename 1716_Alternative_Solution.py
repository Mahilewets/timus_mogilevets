n, s=map (int, input (). split ()) 
yes=s-2*n
no=n-yes
ans=n-(yes**2 + no*(no-1))/n
print (ans)
