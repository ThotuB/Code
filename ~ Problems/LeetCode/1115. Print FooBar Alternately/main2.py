# threading module - Barrier Version

from threading import Thread, Barrier

def printFoo():
    print("foo")

def printBar():
    print("bar")

class FooBar:
    def __init__(self, n):
        self.n = n
        self.barrier1 = Barrier(2)
        self.barrier2 = Barrier(2)

    def foo(self) -> None:
        for _ in range(self.n):
            self.barrier1.wait()
            printFoo()
            self.barrier2.wait()
            
        self.barrier1.wait()


    def bar(self) -> None:
        self.barrier1.wait()

        for _ in range(self.n):
            self.barrier2.wait()
            printBar()
            self.barrier1.wait()


if __name__ == '__main__':
    obj = FooBar(25)
    Thread(target=obj.foo).start()
    Thread(target=obj.bar).start()