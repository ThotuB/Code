from threading import Thread, Lock

lock1 = Lock()
lock2 = Lock()
lock2.acquire()

def Thread1():
    lock1.acquire()

    print("Thread 1")

    lock2.release()
    

def Thread2():
    lock2.acquire()

    print("Thread 2")

    lock1.release()


if __name__ == "__main__":
    Thread(target=Thread1).start()
    Thread(target=Thread2).start()