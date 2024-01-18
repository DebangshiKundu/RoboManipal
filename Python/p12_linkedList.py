
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
class LinkedList:
    def __init__(self):
        self.head=None
    def isEmpty(self):
        return self.head==None
    def insert(self,data):
        nn=Node(data)
        if not self.isEmpty():
            temp=self.head
            while temp.next:
                temp=temp.next
            temp.next=nn
        else:
            self.head = nn
    def insert_first(self,data):
        nn=Node(data)
        nn.next=self.head
        self.head=nn
    def delete(self,data):
        if self.head == None:
            return
        if self.head.data==data:
            self.head=self.head.next
            return
        current=self.head
        while current.next:
            if current.next.data==data:
                current.next=current.next.next
                return
            current=current.next
    def print(self):
        temp=self.head
        while temp:
            print (temp.data,end=" ")
            temp=temp.next
        print()

ll=LinkedList()
ch=0
print('''
      1)insert
      2)insert at beginning
      3)delete
      4)isEmpty
      5)dispaly
      6)exit''')
while (ch!=6):
    ch=int(input('\nEnter choice:'))
    if(ch==1):
        n=int(input("Enter data:"))
        ll.insert(n)
    elif(ch==2):
        n=int(input("Enter data:"))
        ll.insert_first(n)
    elif(ch==3):
        n=int(input("Enter data:"))
        ll.delete(n)
    elif(ch==4):
        print('List empty?',ll.isEmpty())
    elif(ch==5):
        ll.print()
    elif(ch==6):
        print('exit')
    else:
        print('Invalid choice')

         
    


        
