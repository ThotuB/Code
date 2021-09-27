from threading import Thread, Semaphore

def printFizz():
	print("Fizz", end=" ")

def printBuzz():
	print("Buzz", end=" ")

def printFizzBuzz():
	print("FizzBuzz", end=" ")

def printNumber(x):
	print(x, end=" ")

class FizzBuzz:
	def __init__(self, n: int):
		self.n = n

		self.running = True

		self.fizz_sem = Semaphore(0)
		self.buzz_sem = Semaphore(0)
		self.fizzbuzz_sem = Semaphore(0)
		self.number_sem = Semaphore(1)

	# printFizz() outputs "fizz"
	def fizz(self) -> None:
		while True:
			self.fizz_sem.acquire()
			if not self.running:
				break
			printFizz()
			self.number_sem.release()

	# printBuzz() outputs "buzz"
	def buzz(self) -> None:
		while True:
			self.buzz_sem.acquire()
			if not self.running:
				break
			printBuzz()
			self.number_sem.release()

	# printFizzBuzz() outputs "fizzbuzz"
	def fizzbuzz(self) -> None:
		while True:
			self.fizzbuzz_sem.acquire()
			if not self.running:
				break
			printFizzBuzz()
			self.number_sem.release()
		
	# printNumber(x) outputs "x", where x is an integer.
	def number(self) -> None:
		for num in range(1, self.n + 1):
			self.number_sem.acquire()

			if num % 15 == 0:
				self.fizzbuzz_sem.release()
			elif num % 5 == 0:
				self.buzz_sem.release()
			elif num % 3 == 0:
				self.fizz_sem.release()
			else:
				printNumber(num)
				self.number_sem.release()
		
		self.number_sem.acquire()
		self.running = False
		self.fizz_sem.release()
		self.buzz_sem.release()
		self.fizzbuzz_sem.release()


if __name__ == "__main__":
	fizzbuzz = FizzBuzz(15)
	Thread(target=fizzbuzz.fizz).start()
	Thread(target=fizzbuzz.buzz).start()
	Thread(target=fizzbuzz.fizzbuzz).start()
	Thread(target=fizzbuzz.number).start()