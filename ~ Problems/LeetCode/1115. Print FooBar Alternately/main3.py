# threading module - Lock Version

from threading import Thread, Lock

def printFoo():
    print("foo")

def printBar():
    print("bar")

class FooBar:
    def __init__(self, n):
        self.n = n
        self.lockFoo = Lock()
        self.lockBar = Lock()
        self.lockBar.acquire()

    def foo(self) -> None:
        for _ in range(self.n):
            self.lockFoo.acquire()
            printFoo()
            self.lockBar.release()


    def bar(self) -> None:
        for _ in range(self.n):
            self.lockBar.acquire()
            printBar()
            self.lockFoo.release()


if __name__ == '__main__':
    obj = FooBar(25)
    Thread(target=obj.foo).start()
    Thread(target=obj.bar).start()