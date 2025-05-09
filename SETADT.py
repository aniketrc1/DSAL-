a={1,2,3,4};
b={1,2,3,4,5,6};
c={};
uni=set();


def  add():
    
    print("Enter the elemnt to add in set")
    num=int(input())
    if num not in a:
        a.add(num)
        print("Sucessfulyy addred")
    else:
        print("Element Already present")

def iterator():


    print("{",end=" ")
    for i in a:
        print(i,",",end="")
    print("}")  

def remove():

    print("enter elemnt you want to remove")
    num=int(input())
    if num not in a:
        print("element is not prsent")
    else:
       print("element Deleted")
       a.remove(num)

def contains():

    num=int(input("enter number which to be check"))
    if num not in a:
        print("number is not prsent");
    else:
       print("number is prsent");

def union():
  
    for i in a:
        uni.add(i);
    for j in b:
        if j not in uni:
            uni.add(j);
    
   
def intersction(a,b):
    intr=set();
    for i in a:
        if i in b:
            intr.add(i)
    print(intr)
def diffrenece(a,b):
    diff=set();
    for i in a:
        if i not in b:
            diff.add(i);
    print(diff);

def subset(a,b):

    for i in a:
        if i not in b:
          print("NOT subset")
          return
    print(" subset")





# iterator()         

# uni=a

# union()
# print(uni);

# intersction()
diffrenece(a,b);

subset(a,b);






