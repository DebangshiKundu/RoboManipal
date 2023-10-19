from itertools import permutations
sen=input("Enter the sentence: ").split()
words=permutations(sen,len(sen))
for i in words:
    s=' '.join(i)
    print(s)



