from threading import Thread, Barrier
from time import sleep

barrier = Barrier(2)

def Thread1():
    for i in range(5):
        print("Thread 1")
        barrier.wait()
        sleep(0.001)
    

def Thread2():
    for i in range(5):
        barrier.wait()
        print("Thread 2")


if __name__ == "__main__":
    Thread(target=Thread1).start()
    Thread(target=Thread2).start()