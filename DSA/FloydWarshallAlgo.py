"Module for Floyd-Warshall algorithm for finding all pair shortest paths."

from math import inf

def floydWarshall(matrix: list) -> list:
    """Function for Floyd-Warshall algorithm.
        Args:
            matrix (list): adjacency matrix.
        Returns:
            list: adjacency matrix.
    """
    n = len(matrix)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])
    return matrix

if __name__ == "__main__":
    total = int(input("Enter the number of vertices: "))
    matrix = [[inf for i in range(total)] for j in range(total)]
    for i in range(total):
        for j in range(total):
            if i == j:
                matrix[i][j] = 0
            else:
                item = int(input(f"Enter the distance between vertices {i+1} and {j+1} (If not connected enter -1): "))
                if item == -1:
                    matrix[i][j] =  inf
                    continue
                matrix[i][j] = item
    print("\nThe matrix is: ")
    j = 0
    for i in range(total):
            print(matrix[i])
            j += 1
    matrix = floydWarshall(matrix)
    print("\nThe shortest path matrix is: ")
    for i in range(total):
            print(matrix[i])
            j += 1