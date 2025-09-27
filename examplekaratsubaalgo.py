def karatSuba(x,y):
    if x<10 or y<10:
        return x*y
        
    else :
        n = max(len(str(x)),len (str(y)))
        half=n//2
        a = x//(10**(half))
        b=x%(10**(half))
        c=y//(10**(half))
        d=y%(10**(half))
        ac=karatSuba(a,c)
        bd=karatSuba(b,d)
        ad_plus_bc=karatSuba(a+b,c+d)-ac-bd
        return ac*(10**(2*half))+(ad_plus_bc*(10**half))+bd
        
        
n1=1432
n2=1500
z=karatSuba(n1,n2)
print('The multiplication of the given two numbers is',z)