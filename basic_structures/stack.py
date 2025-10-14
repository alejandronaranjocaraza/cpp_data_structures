class stack:
    def __init__(self):
        self.data = []

    def isEmpty(self):
        return bool(not self.data)

    def push(self, x):
        self.data.insert(0, x)

    def pop(self):
        if self.data:
            res = self.data.pop(0)
        else:
            print("Empty")
            res = None
        return res

    def peek(self):
        if self.data:
            res = self.data[0]
        else:
            print("Empty")
            res = None
        return res


myStack = stack()
myStack.push(1)
myStack.push(2)
print(myStack.peek())
print(myStack.pop())
myStack.pop()
print(myStack.isEmpty())
