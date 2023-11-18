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


def knapsack_01(items: list, capacity):
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
            continue
    return final_profit, final_weight


if __name__ == '__main__':
    items = [
        {'profit': 1, 'weight': 4},
        {'profit': 2, 'weight': 5},
        {'profit': 3, 'weight': 1}
    ]
    capacity = 4
    print(knapsack(items, capacity))
    print(knapsack_01(items, capacity))