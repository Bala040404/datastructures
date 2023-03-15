temp = 10


class node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1


class avl:
    def __init__(self):
        pass

    def height(self, node):
        if node is None:
            return 0
        return node.height

    def balanceFactor(self, root):
        if root is not None:
            return self.height(root.left) - self.height(root.right)

    def rightRotate(self, root):
        x = root.left
        z = root.left.right
        x.right = root
        root.left = z
        root.height = 1 + max(self.height(root.left), self.height(root.right))
        x.height = 1 + max(self.height(x.left), self.height(x.right))
        return x

    def leftRotate(self, root):
        x = root.right
        z = root.right.left
        x.left = root
        root.right = z
        root.height = 1 + max(self.height(root.left), self.height(root.right))
        x.height = 1 + max(self.height(x.left), self.height(x.right))
        return x

    def insert(self, root, value):

        if root is None:
            return node(value)
        else:
            if root.value > value:
                root.left = self.insert(root.left, value)
            elif root.value < value:
                root.right = self.insert(root.right, value)
            root.height = 1 + max(self.height(root.left),
                                  self.height(root.right))

            bf = self.balanceFactor(root)

            if bf > 1 and value < root.left.value:
                return self.rightRotate(root)
            elif bf < -1 and value > root.right.value:
                return self.leftRotate(root)
            elif bf < -1 and value < root.right.value:
                root.right = self.rightRotate(root.right)
                return self.leftRotate(root)
            elif bf > 1 and value > root.left.value:
                root.left = self.leftRotate(root.left)
                return self.rightRotate

            return root

    def inorder(self, root):
        if (root is not None):
            self.inorder(root.left)
            print(root.value)
            self.inorder(root.right)

    def preorder(self, root):
        if (root is not None):
            print(root.value)
            self.preorder(root.left)
            self.preorder(root.right)

    def getmin(self,root):
        prev = None
        while root is not None:
            prev = root
            root =root.left
        return prev

    def print3d(self, root, space=0):
        if root is not None:
            print()
            space += temp
            self.print3d(root.right, space)
            for i in range(temp, space):
                print(end=" ")
            print(root.value)
            self.print3d(root.left, space)

    def delete(self,root,val):
        if not root:
            return root
        else:
            if root.value>val:
                root.left = self.delete(root.left,val)
            elif root.value<val:
                root.right = self.delete(root.right,val)
            else:
                if root.left is None:
                    temp = root.right
                    root = None
                    return temp
                elif root.right is None:
                    temp = root.left
                    root = None
                    return temp
                else:
                    temp = self.getmin(root.right)
                    root.value = temp.value
                    root.right = self.delete(root.right,temp.value)

            if root is None:
                return root

            else:
                root.height = 1 + max(self.height(root.left),
                                  self.height(root.right))
                
                bf = self.balanceFactor(root)

                if bf > 1: 
                    if self.balanceFactor(root.left)>=0:
                        return self.rightRotate(root)
                    else:
                        root.left = self.leftRotate(root.left)
                        return self.rightRotate(root)
                elif bf < -1 :
                    if self.balanceFactor(root.right)<=0:
                        
                        return self.leftRotate(root)
                    else:
                        root.right = self.rightRotate(root.right)
                        return self.leftRotate(root)



            return root

a = avl()
root = None
root = a.insert(root, 10)
root = a.insert(root, 20)
root = a.insert(root, 30)
root = a.insert(root, 40)

root = a.insert(root, 50)
root = a.insert(root, 35)
root = a.insert(root, 25)
# root = a.insert(root,11)
# root = a.insert(root,50)
# root = a.insert(root,25)
# root = a.insert(root,75)
# root = a.insert(root,15)

root = a.delete(root,30)

a.print3d(root)

