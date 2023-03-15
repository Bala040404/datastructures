class node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.parent = None


class splaytree:
    def __init__(self):
        self.root = None

    def leftrotate(self, root):
        y = root.right
        z = y.left
        root.right = z

        if (z is not None):
            z.parent = root

        if root.parent == None:
            y.parent = None
            self.root = y

        else:
            if root == root.parent.right:
                root.parent.right = y
                y.parent = root.parent
            elif root == root.parent.left:
                root.parent.left = y
                y.parent = root.parent

        y.left = root
        root.parent = y

    def rightRotate(self, root):
        y = root.left
        z = y.right
        root.left = z

        if (z is not None):
            z.parent = root

        if (root.parent == None):
            y.parent = None
            self.root = y

        else:
            if (root == root.parent.left):
                root.parent.left = y
                y.parent = root.parent
            elif (root == root.parent.right):
                root.parent.right = y
                y.parent = root.parent

        y.right = root
        root.parent = y

    def splay(self, root):
        while root.parent != None:
            if root.parent.parent is None:
                if root == root.parent.left:
                    self.rightRotate(root.parent)
                elif root == root.parent.right:
                    self.leftrotate(root.parent)

            else:
                # print("here")
                g = root.parent.parent
                p = root.parent

                if g.left == p and p.left == root:
                    self.rightRotate(g)
                    self.rightRotate(p)

                elif g.right == p and p.right == root:
                    self.leftrotate(g)
                    self.leftrotate(p)

                elif g.left == p and p.right == root:
                    self.leftrotate(p)
                    self.rightRotate(g)

                elif g.right == p and p.left == root:
                    self.rightRotate(p)
                    self.leftrotate(g)

    def insert(self, value):
        prev = None
        cur = self.root
        n = node(value)
        while cur is not None:
            if value < cur.value:
                prev = cur
                cur = cur.left
            elif value > cur.value:
                prev = cur
                cur = cur.right
            else:
                return

        n.parent = prev

        if prev is None:
            self.root = n
        elif value > prev.value:
            prev.right = n
        elif value < prev.value:
            prev.left = n

        self.splay(n)

    def search(self, value):

        cur = self.root

        while cur != None:
            if cur.value == value:
                self.splay(cur)
                return True
            elif cur.value < value:
                cur = cur.right
            elif cur.value > value:
                cur = cur.left
        return False

    def preorder(self, root):
        if root is not None:
            print(root.value)
            self.preorder(root.left)
            self.preorder(root.right)


s = splaytree()
s.insert(10)
s.insert(20)
s.insert(30)
s.insert(100)
s.insert(90)
s.insert(40)
s.insert(50)
s.insert(60)
s.insert(70)
s.insert(80)
s.insert(150)
s.insert(110)
s.insert(120)

s.search(40)
# print(s.root.value)
s.preorder(s.root)
