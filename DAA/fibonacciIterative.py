def fibonacciIterative(n):
    t1 = 0
    t2 = 1
    for i in range(n):
        t1, t2 = t2, t1+t2
    return t1
