class Queue:
    def __init__(self):
        self.data = []

    def enqueue(self, x: int):
        self.data.append(x)

    def dequeue(self):
        if self.isEmpty():
            print("Empty")
            res = None
        else:
            res = self.data.pop()
        return res

    def isEmpty(self):
        return bool(not self.data)

    def first(self):
        if self.isEmpty():
            print("Empty")
            res = None
        else:
            res = self.data[0]
        return res


q = Queue()
q.enqueue(2)
q.enqueue(3)
print(q.dequeue())
print(q.dequeue())
print(q.isEmpty())
