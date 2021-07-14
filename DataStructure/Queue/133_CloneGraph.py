# 克隆图
'''
# Node 的定义
class Node(object):
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
'''
class Solution(object):

    def __init__(self):
        self.visited = {}
    
    def cloneGraph(self, node):
        if not node:
            return node # node是一个节点 如果不是一个节点
        if node in self.visited: # 这个节点访问过
            return self.visited[node] # ？？
        clone_node = Node(node.val, []) # 克隆一个node
        self.visited[node] = clone_node 

        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]

        return clone_node
