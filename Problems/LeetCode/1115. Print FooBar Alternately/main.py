import threading
from asyncio import run, sleep

def printFoo():
    print("foo")

def printBar():
    print("bar")

class FooBar:
    def __init__(self, n):
        self.n = n
        self.barrier = threading.Semaphore(0)


    async def foo(self) -> None:
        for _ in range(self.n):
            # printFoo() outputs "foo". Do not change or remove this line.
        	printFoo()


    async def bar(self) -> None:
        for _ in range(self.n):
            # printBar() outputs "bar". Do not change or remove this line.
        	printBar()


async def main():
    obj = FooBar(1000)
    


if __name__ == '__main__':
    run(main())
