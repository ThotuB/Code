# Time: O(n)
# Space: O(1)

def maxProfit(prices: list[int]) -> int:
    profit = 0;
    
    for i in range(1, len(prices)):
        if prices[i-1] < prices[i]:
            profit += prices[i] - prices[i-1]
    
    return profit


if __name__ == "__main__":
    print(maxProfit([7, 1, 5, 3, 6, 4]))
    print(maxProfit([1, 2, 3, 4, 5]))
    print(maxProfit([7, 6, 4, 3, 1]))