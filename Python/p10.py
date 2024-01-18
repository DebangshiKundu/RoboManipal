# 10)	Write a function in Python to parse a string such that it accepts a parameter- an encoded string. This encoded string will contain a first name, last name, and an id. You can separate the values in the string by any number of zeros. The id will not contain any zeros. The function should return a Python dictionary with the first name, last name, and id values. For example, if the input would be "John000Doe000123". Then the function should return: { "first_name": "John", "last_name": "Doe", "id": "123" }
s=input("Enter the string:").split('000')

res={}
res["first_name"]=s[0]
res["last_name"]=s[1]
res["id"]=s[2]

print(res)
