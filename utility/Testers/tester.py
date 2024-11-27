class Tester:
    def __init__(self, *tests):
        self.passed_tests = 0
        self.total_tests = len(tests)
        
        self.tests = tests
        
    def run_test(self, test, index):
        print(f"Test {index}:", end=" ")
        result = test.run()
        
        if result:
            self.passed_tests += 1
        
    def run_all(self):
        for index, test in enumerate(self.tests):
            self.run_test(test, index)
            
        print(f"\nPASSED {self.passed_tests} / {self.total_tests} TESTS")
        

class Test:
    def __init__(self, **kwargs):
        self.func = kwargs["func"]
        
        self.args = kwargs["args"] if "args" in kwargs else []
        self.kwargs = kwargs["kwargs"] if "kwargs" in kwargs else {}
        
        self.expected_output = kwargs["expected_output"]

    def run(self):
        try:
            output = self.func(*self.args, **self.kwargs)
        except NotImplementedError as e:
            print("Not implemented!")
            return False
        except Exception as e:
            output = e
            
        if output != self.expected_output:
            print("Failed")
            print(f" - OUTPUT: {output}")
            print(f" - EXPECTED: {self.expected_output}")
            return False
        
        print("Passed")
        return True
            
            
if __name__ == "__main__":
    def test_func():
        raise ConnectionAbortedError("plsdgsd")
    
    test1 = Test(func=test_func, expected_output=1)
    test2 = Test(func=test_func, expected_output=1)
    Tester(test1, test2).run_all()