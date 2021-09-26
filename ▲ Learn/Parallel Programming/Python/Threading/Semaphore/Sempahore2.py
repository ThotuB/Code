from threading import Thread, Semaphore

sem1 = Semaphore(0)
sem2 = Semaphore(2)

def Thread1():
    for i in range(6):
        sem2.acquire()

        print("Thread 1")

        sem1.release()
    

def Thread2():
    for i in range(6):
        sem1.acquire()
        sem1.acquire()

        print("Thread 2")

        sem2.release()


if __name__ == "__main__":
    Thread(target=Thread1).start()
    Thread(target=Thread2).start()