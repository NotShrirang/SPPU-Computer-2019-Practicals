def solveNQueens(n):
    col = set()
    forwardDiag = set()
    backwardDiag = set()

    result = []
    board = [['.'] * n for i in range(n)]

    def backtracking(r):
        if r == n:
            copy = [" ".join(row) for row in board]
            result.append(copy)
            return

        for c in range(n):
            if c in col or (r - c) in forwardDiag or (r + c) in backwardDiag:
                continue

            col.add(c)
            backwardDiag.add(r + c)
            forwardDiag.add(r - c)
            board[r][c] = "Q"

            backtracking(r + 1)

            col.remove(c)
            backwardDiag.remove(r + c)
            forwardDiag.remove(r - c)
            board[r][c] = "."

    backtracking(0)
    return result

def printSolutions(boards):
    print("All solutions:")
    for i, board in enumerate(boards):
        print(f"Solution {i + 1}:")
        for row in board:
            print(row)


if __name__ == '__main__':
    n = int(input("Enter number of queens :"))

    boards = solveNQueens(n)
    printSolutions(boards)
    