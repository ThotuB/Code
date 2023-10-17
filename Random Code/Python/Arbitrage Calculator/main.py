def is_win_possible(odds, size):
    best_odds = [0] * size

    for odd in odds:
        for idx, nr in enumerate(odd):
            if nr > best_odds[idx]:
                best_odds[idx] = nr

    print(f"Best odds: {best_odds}")
    implied_probability = sum(1 / nr for nr in best_odds)
    print(f"Total implied probability: {implied_probability:.2%}")
    print("WIN" if implied_probability < 1 else "LOSE")


def unbiased_arbitrage(odds, stake):
    for nr1, nr2 in odds:
        print(f"Total implied probability: {1 / nr1 + 1 / nr2:.2%}")

    best_odds = (0, 0)
    for nr1, nr2 in odds:
        if nr1 > best_odds[0]:
            best_odds = (nr1, best_odds[1])
        if nr2 > best_odds[1]:
            best_odds = (best_odds[0], nr2)

    print(f"Best odds: {best_odds}")

    # x + y = 100
    # x * (nr1 - 1) - y = y * (nr2 - 1) - x
    # => x * nr1 = y * nr2
    # => x = (y * nr2) / nr1
    # => y * nr2 + y * nr1 = 100 * nr1
    # => y * (nr2 + nr1) = 100 * nr1
    # => y = (100 * nr1) / (nr2 + nr1)

    odd1, odd2 = best_odds
    stake1 = (stake * odd2) / (odd1 + odd2)
    stake2 = stake - stake1

    print(f"Stake 1: {stake1:.2f}")
    print(f"Stake 2: {stake2:.2f}")


if __name__ == '__main__':
    site_odds = [
        (1.66, 3.40, 5.00),
        (1.71, 3.71, 5.10),
        (1.72, 3.55, 5.60),
        (1.72, 3.60, 5.30),
        (1.7, 3.47, 5.44)
    ]

    is_win_possible(site_odds, 3)

    stake = 100

    # unbiased_arbitrage(site_odds, stake)
