

class Stack:
    def __init__(self):
        self.s=[]
    def push(self,n):
            self.s.append(n)
            print(f'{n} pushed into stack')
    def pop(self):
        if not self.isEmpty():
            self.s.pop()
            print("element popped")
        else:
            print('stack is empty')
    def peek(self):
        if not self.isEmpty():
            print(f'Top element {self.s[-1]}')
        else:
            print('stack is empty')
    def isEmpty(self):
        return self.s==[]
    def size(self):
        print('The size is:',len(self.s))
    def __str__(self):
        return str(self.s)

stack=Stack()
ch=0
print('''
      1)push
      2)pop
      3)peek
      4)isEmpty
      5)size
      6)dispaly''')
while (ch!=7):
    ch=int(input('\nEnter choice:'))
    if(ch==1):
        n=int(input("Enter data:"))
        stack.push(n)
    elif(ch==2):
        stack.pop()
    elif(ch==3):
        stack.peek()
    elif(ch==4):
        print('Stack empty?',stack.isEmpty())
    elif(ch==5):
        stack.size()
    elif(ch==6):
        print(stack)
    elif(ch==7):
        print('exit')
    else:
        print('Invalid choice')

         
    

