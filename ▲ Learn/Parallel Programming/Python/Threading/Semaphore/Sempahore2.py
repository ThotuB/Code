# Coin Flip Generator
from threading import Thread, Semaphore

class Coin:
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
        

if __name__ == "__main__":
    coin = Coin()
    coin.flip(10)