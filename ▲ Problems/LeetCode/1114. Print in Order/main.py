from threading import Thread, Lock

class Foo:
    def __init__(self):
        self.lock2 = Lock()
        self.lock3 = Lock()
        self.lock2.acquire()
        self.lock3.acquire()


    def first(self) -> None:
        print('first')
        self.lock2.release()


    def second(self) -> None:
        self.lock2.acquire()
        print('second')
        self.lock3.release()


    def third(self) -> None:
        self.lock3.acquire()
        print('third')


if __name__ == '__main__':
    obj1 = Foo()
    Thread(target=obj1.first).start()
    Thread(target=obj1.second).start()
    Thread(target=obj1.third).start()

    
    obj2 = Foo()
    Thread(target=obj2.first).start()
    Thread(target=obj2.third).start()
    Thread(target=obj2.second).start()