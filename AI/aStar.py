import copy


class Node:
    def __init__(self, data, level, fval):
        self.data = data
        self.level = level
        self.fval = fval

    def get_children(self):
        x, y = self.find()
        moves = [[x-1, y], [x, y-1], [x+1, y], [x, y+1]]
        children = []
        for move in moves:
            child = self.move(x, y, move[0], move[1])
            if child is not None:
                child_node = Node(child, self.level+1, 0)
                children.append(child_node)
        return children

    def move(self, x, y, x2, y2):
        if (x2 < len(self.data) and (x2 >= 0) and (y2 < len(self.data)) and (y2 >= 0) ):
            temp_data = copy.deepcopy(self.data)
            temp = temp_data[x2][y2]
            temp_data[x2][y2] = temp_data[x][y]
            temp_data[x][y] = temp
            return temp_data
        else:
            return None

    def find(self):
        for i in range(len(self.data)):
            for j in range(len(self.data)):
                if self.data[i][j] == "_":
                    return i, j

class Puzzle:
    def __init__(self, size) -> None:
        self.size = size
        self.open = []
        self.closed = []

    def getMat(self):
        puzzle = []
        for _ in range(0, self.size):
            temp = input().split(" ")
            puzzle.append(temp)
        return puzzle

    def f(self, start, goal):
        return self.h(start.data, goal) + start.level
    
    def h(self, start, goal):
        hval = 0
        for i in range(0, self.size):
            for j in range(0, self.size):
                if start[i][j] != goal[i][j] and start[i][j] != "_":
                    hval += 1
        return hval

    def solve(self):
        print("Input starting state: ")
        start = self.getMat()
        print("Goal State: ")
        goal = self.getMat()
        print("Solution:\n")
        start = Node(start, 0, 0)
        fval = self.f(start, goal)
        self.open.append(start)
        while True:
            current_node: Node = self.open[0]
            print()
            for i in current_node.data:
                for j in i:
                    print(j, end=" ")
                print("")
            
            if self.h(current_node.data, goal) == 0:
                break
            for i in current_node.get_children():
                i.fval = self.f(i, goal)
                self.open.append(i)
            self.closed.append(current_node)
            del self.open[0]
            self.open.sort(key=lambda x: x.fval, reverse=False)

if __name__ == "__main__":
    puzzle = Puzzle(3)
    puzzle.solve()