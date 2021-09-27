# threading module - Semaphore Version

from threading import Thread, Semaphore

def printFoo():
    print("foo")

def printBar():
    print("bar")

class FooBar:
    def __init__(self, n):
        self.n = n
        self.semaphoreFoo = Semaphore(0)
        self.semaphoreBar = Semaphore(1)

    def foo(self) -> None:
        for _ in range(self.n):
            self.semaphoreBar.acquire()
            printFoo()
            self.semaphoreFoo.release()


    def bar(self) -> None:
        for _ in range(self.n):
            self.semaphoreFoo.acquire()
            printBar()
            self.semaphoreBar.release()


if __name__ == '__main__':
    obj = FooBar(25)
    Thread(target=obj.foo).start()
    Thread(target=obj.bar).start()