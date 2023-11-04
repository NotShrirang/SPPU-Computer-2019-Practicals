cache = {0: 0, 1: 1}


def fibonacciDP(n):
    if n in cache:
        return cache[n]
    else:
        cache[n] = fibonacciDP(n-1) + fibonacciDP(n-2)
        return cache[n]
