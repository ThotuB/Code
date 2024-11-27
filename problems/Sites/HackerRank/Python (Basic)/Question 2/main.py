class VendingMachine:
    def __init__(self, num_items, item_price):
        self.num_items = num_items
        self.item_price = item_price

    def buy(self, req_items: int, money: int) -> int:
        if req_items > self.num_items:
            raise ValueError("Not enough items in the machine")
            
        price = self.item_price * req_items
        if money < price:
            raise ValueError("Not enough coins")
        
        self.num_items -= req_items
        
        return money - price


if __name__ == '__main__':
    vm = VendingMachine(10, 2)

    print(vm.buy(1, 5))
    # print(vm.buy(10, 100))
    print(vm.buy(7, 100))
    # print(vm.buy(2, 3))