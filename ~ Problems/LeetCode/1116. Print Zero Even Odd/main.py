from threading import Thread, Semaphore

def printNumber(n: int):
    print(n, end='')

class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n

        self.zero_sem = Semaphore(1)
        self.even_sem = Semaphore(0)
        self.odd_sem = Semaphore(0)
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self) -> None:
        for num in range(self.n):
            self.zero_sem.acquire()
            printNumber(0)

            (self.even_sem if num % 2 else self.odd_sem).release()
        
        
    def even(self) -> None:
        for num in range(2, self.n+1, 2):
            self.even_sem.acquire()
            printNumber(num)
            self.zero_sem.release()
        
        
    def odd(self) -> None:
        for num in range(1, self.n+1, 2):
            self.odd_sem.acquire()
            printNumber(num)
            self.zero_sem.release()
        

if __name__ == "__main__":
    obj = ZeroEvenOdd(5)
    Thread(target=obj.zero).start()
    Thread(target=obj.even).start()
    Thread(target=obj.odd).start()