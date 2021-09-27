# Coin Flip Generator
from threading import Thread, Semaphore
from time import sleep

# More realistic coin flip
class Coin1:
    def __init__(self):
        self.sem = Semaphore(0)

    def Heads(self):
        self.sem.acquire()
        print("H", end='')

    def Tails(self):
        self.sem.acquire()
        print("T", end='')

    def flip(self, n: int):
        for _ in range(n):
            Thread(target=self.Heads).start()
            Thread(target=self.Tails).start()

        for _ in range(2*n):
            self.sem.release()


# Prints in chunks of 'HHHH...' and 'TTTT...'
class Coin2:
    def __init__(self):
        self.sem = Semaphore(0)

    def Heads(self, n):
        for _ in range(n):
            self.sem.acquire()
            print("H", end='')

    def Tails(self, n):
        for _ in range(n):
            self.sem.acquire()
            print("T", end='')

    def flip(self, n: int):
        Thread(target=self.Heads, args=(n,)).start()
        Thread(target=self.Tails, args=(n,)).start()

        for _ in range(2*n):
            self.sem.release()
        

if __name__ == "__main__":
    coin1 = Coin1()
    coin1.flip(100)
    sleep(1)
    print()
    coin2 = Coin2()
    coin2.flip(100)
