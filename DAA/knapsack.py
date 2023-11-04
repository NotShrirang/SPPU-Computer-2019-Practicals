def knapsack(items: list, capacity):
    items.sort(key=lambda x: x['profit']/x['weight'])
    items.reverse()
    final_profit = 0
    final_weight = 0
    available_capacity = capacity
    for item in items:
        if item['weight'] <= available_capacity:
            final_profit += item['profit']
            final_weight += item['weight']
            available_capacity -= item['weight']
        else:
            final_profit += item['profit'] * (available_capacity / item['weight'])
            final_weight += item['weight'] * (available_capacity / item['weight'])
            break
    return final_profit, final_weight


if __name__ == '__main__':
    items = [
        {'profit': 10, 'weight': 2},
        {'profit': 5, 'weight': 3},
        {'profit': 15, 'weight': 6}
    ]
    capacity = 7
    print(knapsack(items, capacity))
