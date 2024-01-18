
class Inventory:
    def __init__(self):
        self.list1={}
    def ADD(self,item,quan):
        if item in self.list1:
            self.list1[item]+=quan
            print(f'UPDATED item: {item}')
        else:
            self.list1[item]=quan
    def DELETE(self,item,quan):
        if item not in self.list1 :
            print(f'{item} does not exist ')
        elif self.list1[item]<quan:
            print(f'Not enough quantity; {item} has quantity of {self.list1[item]}')
        else:
            self.list1[item]-=quan
            print(f'{self.list1[item]} of {item} is DELETED')
    def display(self):
        for i,q in self.list1.items():
            print(i,q)


list11=Inventory()
list11.ADD('beaker',20)
list11.ADD('pippete',20)
list11.ADD('burner',10)
list11.ADD('test tube',30)

print('''
1)Add item
2)Delete item
3)Display list1
4)exit''')
ch=0
while(ch!=4):
    ch=int(input("\nEnter choice:"))
    if ch==1:
        item=input("Enter item:")
        quan=int(input("Enter Quantity:"))
        list11.ADD(item,quan)
    elif ch==2:
        item=input("Enter item to delete:")
        quan=int(input("Enter Quantity to Delete:"))
        list11.DELETE(item,quan)
    elif ch==3:
        list11.display()
    elif ch==4:
        print('exit')
    else:
        print('Invalid Choice')





