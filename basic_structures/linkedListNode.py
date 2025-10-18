class Node:
    def __init__(self, value=None, next_node=None):
        self.value = value
        self.next = next_node

    def set_next(self, next_node):
        self.next = next_node

    def get_next_node(self):
        return self.next

    def get_value(self):
        return self.value


myNode = Node(33)
secondNode = Node()
secondNode.value = 66
myNode.next_node = secondNode
