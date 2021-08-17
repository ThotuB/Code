import math

class Hamming:
    def create(data: list):
        check0 = 0
        check = 0
        k = 0
        hamming = []
        for i in range(len(data)):
            while k & (k-1) == 0:
                hamming.append(0)
                k += 1
            hamming.append(data[i])
            k += 1
        hamming[0] = check0

        print(hamming)
        return hamming        


    def check(data: list):
        check0 = 0
        check = 0
        for i in range(len(data)):
            check ^= data[i] * i
            check0 ^= data[i]
            # print(f'{i:02} - {data[i]} - {check:04b} - {check0}')

        return ( check0 == 0 and check == 0 )


if __name__ == "__main__":
    data = []
    with open("c:/Users/bogda/OneDrive/Documents/GitHub/Code/Python/Hamming Codes/data.txt", "r") as file:
        datastr = file.read()
        datalist = datastr.replace("\n", " ").split(" ")
        data = [int(i) for i in datalist[2:]]

    Hamming.create(data)