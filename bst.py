temp = 10

class node:
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None


class Bst:
    def __init__(self):
        self.root = None

    def insert(self,value,root,prev = None):
        cur = root
        if (cur is not None):
            if(cur.value>value):
                self.insert(value,cur.left,cur)

            elif (cur.value<value):
                self.insert(value,cur.right,cur)

        #checking if the tree is empty (if both prev and cur is none)
        elif (prev is None):
            self.root = node(value)
            
        else:
            if (prev.value>value):
                prev.left = node(value)
            else:
                prev.right = node(value)

    def inorder(self,root):
        if (root is not None):
            self.inorder(root.left)
            print(root.value)
            self.inorder(root.right)


    def search(self,value):
        cur = self.root
        while cur is not None:
            if cur.value>value:
                cur = cur.left
            elif cur.value<value:
                cur = cur.right
            elif cur.value == value:

                return True
            
        else:
            return False
        
    def findMin(self,root):
        prev = None
        while root is not None:
            prev = root
            root = root.left
        return prev


    def printTree(self,root, space=0):
        if (root != None):
            space += temp
            self.printTree(root.right, space)
            print()
            for i in range(temp, space):
                print(end=" ")
            print(root.value)
            self.printTree(root.left, space)

    def delete(self,value):
        if not self.search(value):
            print("cant remove something that is not present")
        else:
            cur = self.root
            prev= None
            while cur is not None:
                if cur.value>value:
                    prev = cur
                    cur = cur.left
                elif cur.value<value:
                    prev = cur
                    cur = cur.right
                elif cur.value == value:
                    break

            if prev is not None:

                #IF THE VALUE TO BE DELETED IS IN THE LEFT OF PREV
                if value == prev.left.value:
                    #if the value to be deleted has no children
                    if prev.left.right is None and prev.left.left is None:
                        prev.left = None

                    #if the value to be deleted has only right child
                    elif prev.left.right is not None and prev.left.left is None:
                        prev.left = prev.left.right
                    
                    #if the value to be deleted has only left child
                    elif prev.left.left is not None and prev.left.right is None:
                        prev.left = prev.left.left

                    else:
                        temp = self.findMin(prev.left.right).value
                        self.delete(temp)
                        prev.left.value = temp


                    
                    
                #IF THE VALUE TO BE DELETED IS IN THE RIGHT OF PREV
                elif value == prev.right.value:
                    #if the value to be deleted has no children
                    if prev.right.right is None and prev.right.left is None:
                        prev.right = None

                    #if the value to be deleted has only left child
                    elif prev.right.left is not None and prev.right.right is None:
                        prev.right = prev.right.left

                    #if the value to be deleted has only right child
                    elif prev.right.right is not None and prev.right.left is None:
                        prev.right = prev.right.right

                    else:
                        temp = self.findMin(prev.right.right).value
                        self.delete(temp)
                        prev.right.value = temp
            
            else:
                if self.root.right is None and self.root.left is None:
                    self.root = None
                elif self.root.right is None:
                    self.root = self.root.left
                elif self.root.left is None:
                    self.root = self.root.right
                else:
                    temp = self.findMin(self.root.right).value
                    self.delete(temp)
                    self.root.value = temp

 

b = Bst()

b.insert(50,b.root)
b.insert(25,b.root)
b.insert(75,b.root)
b.insert(15,b.root)
b.insert(35,b.root)
b.insert(65,b.root)
b.insert(85,b.root)
b.insert(30,b.root)
b.insert(40,b.root)
b.insert(60,b.root)
b.insert(70,b.root)
b.insert(80,b.root)
b.insert(90,b.root)
b.insert(10,b.root)
b.insert(20,b.root)

b.delete(50)

b.printTree(b.root)




