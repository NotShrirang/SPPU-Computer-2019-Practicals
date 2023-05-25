import json


class Queue:
    def __init__(self):
        self.queue = []

    def push(self, data):
        if type(data) == list:
            self.queue.extend(data)
        else:
            self.queue.append(data)

    def pop(self):
        try:
            return self.queue.pop(0)
        except IndexError as ie:
            IndexError("The queue is empty.")
            

def depthFirstSearch(node: int | str, visited: set, graph: dict):
    if node not in visited:
        print(f"Node: {node}")
        visited.add(node)
        for next_node in graph[node]:
            depthFirstSearch(next_node, visited, graph)

def breadthFirstSearch(node: int | str, graph: dict):
    queue = Queue()
    queue.push(node)
    visited = set()
    visited.add(node)
    while queue.queue:
        next_node = queue.pop()
        print(f"Node: {next_node}")
        for next_node in graph[next_node]:
            if str(next_node) not in visited:
                visited.add(next_node)
                queue.push(next_node)

if __name__ == "__main__":
    with open("graph.json", 'r') as f:
        graph = dict(json.load(f))
    print(f"Graph : {graph}")
    print("\nDFS: ")
    depthFirstSearch(node=list(graph.keys())[0], visited=set(), graph=graph)
    print("\nBFS: ")
    breadthFirstSearch(node=list(graph.keys())[0], graph=graph)