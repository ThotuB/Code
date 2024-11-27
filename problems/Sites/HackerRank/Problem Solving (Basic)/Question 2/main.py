active_thresh = 0.05

def mostActive(customers):
    total_trades = len(customers)
    active_trades_thresh = total_trades * active_thresh

    customer_trades = {}
    for customer in customers:
        if customer in customer_trades:
            customer_trades[customer] += 1
        else:
            customer_trades[customer] = 1

    print(active_trades_thresh)

    active_customers = filter(lambda customer: customer_trades[customer] >= active_trades_thresh, customer_trades)
    oredered_active_customers = sorted(active_customers)

    return oredered_active_customers
    

def test_5():
    customers = ['Ampprswkdkobdagw', 'Wcfa', 'Zooot', 'Zn', 'Zooot', 'Wufeesrvn', 'Zn', 'Xillkfdvpfpxabqlngd', 'Zn', 'Zn', 'Qvwdrm', 'Zn', 'Zooot', 'Qvwdrm', 'Zooot', 'Zn', 'Zn', 'Zooot', 'Xillkfdvpfpxabqlngd', 'Rskcw']
    return mostActive(customers)


if __name__ == '__main__':
    customers = ['1', '2', '3', '4', '3', '5', '4', '6', '4', '4', '7', '4', '3', '7', '3', '4', '4', '3', '6', '8']

    print(test_5())