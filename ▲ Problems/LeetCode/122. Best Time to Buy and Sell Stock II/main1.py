# Time: O(n)
# Space: O(1)

def maxProfit(prices: list[int]) -> int:
    profit = 0;
    
    i = 0;
    while i < len(prices) - 1:
        # Find valley
        while i < len(prices) - 1 and prices[i] >= prices[i + 1]:
            i += 1
        valley_price = prices[i]
        # Find peak
        while i < len(prices) - 1 and prices[i] <= prices[i + 1]:
            i += 1
        peak_price = prices[i]

        # Calculate profit: peak - valley
        profit += peak_price - valley_price

    return profit;


if __name__ == "__main__":
    print(maxProfit([7, 1, 5, 3, 6, 4]))
    print(maxProfit([1, 2, 3, 4, 5]))
    print(maxProfit([7, 6, 4, 3, 1]))