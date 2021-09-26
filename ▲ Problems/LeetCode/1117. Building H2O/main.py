from threading import Thread, Semaphore, Barrier

class H2O:
    def __init__(self):
        self.molecule = Barrier(3)
        self.H = Semaphore(2)
        self.O = Semaphore(1)


    def hydrogen(self) -> None:
        self.H.acquire()
        self.molecule.wait()
        print("H")
        self.H.release()

    def oxygen(self) -> None:
        self.O.acquire()
        self.molecule.wait()
        print("O")
        self.O.release()




if __name__ == "__main__":
    h2o = H2O()
    Thread(target=h2o.oxygen).start()
    Thread(target=h2o.oxygen).start()
    Thread(target=h2o.hydrogen).start()
    Thread(target=h2o.hydrogen).start()
    Thread(target=h2o.hydrogen).start()
    Thread(target=h2o.hydrogen).start()
