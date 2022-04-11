from threading import Thread, Semaphore
from time import sleep

sem1 = Semaphore(1)
# sem2 = Semaphore(1)

def thread(x: int):
    for _ in range(5):
        sem1.acquire()

        print(f"Thread {x}")

        sem1.release()
        
        sleep(1)

if __name__ == "__main__":
    Thread(target=thread, args=(1,)).start()
    Thread(target=thread, args=(2,)).start()
    Thread(target=thread, args=(3,)).start()
    Thread(target=thread, args=(4,)).start()