def nQueens(n):
    res = []
    board = [["." for _ in range(n)] for _ in range(n)]

    def isSafe(row, col) -> bool:
        for i in range(row):
            if board[i][col] == 'Q':
                return False

        i = row
        j = col
        while i >= 0 and j < len(board):
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        i = row
        j = col
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        return True

    def backtracking(row):
        if row == len(board):
            res.append(["".join(row) for row in board])
            return False
        for col in range(n):
            if (isSafe(row, col)):
                board[row][col] = "Q"
                possible = backtracking(row+1)
                if possible:
                    return True
                board[row][col] = "."
        return False

    backtracking(0)
    return res


def printSolutions(boards):
    for board in enumerate(boards):
        print(f"Solution {board[0]+1}")
        for row in board[1]:
            for col in row:
                print(col, end=' ')
            print()
        print()
