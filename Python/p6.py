# 6)	Compress the given string S. If the string contains a character 'c,' that 
# occurs X times consecutively. Replace 'c' with (X, c) in the string.

def com(s):
    comp=""
    c=1
    for i in range(1,len(s)):
        if(s[i]==s[i-1]):
            c+=1
        else:
            if(c>1):
                comp+=f"({c}, {s[i-1]})"
            else:
                comp+=s[i-1]
            c=1
   
    if(c>1):
        comp+=f"({c}, {s[i-1]})"
    else:
        comp+=s[i]

    return comp


s=input("Enter the string: ")
print("The compressed string is:\n",com(s))

