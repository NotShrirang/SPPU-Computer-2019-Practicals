def fibonacciRecursive(n):
    if n <= 1:
        return 1
    else:
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2)
