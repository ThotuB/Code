from threading import Thread
import pprint

class ThreadReturn(Thread):
    def __init__(self, group=None, target=None, name=None, args=(), kwargs={}, daemon=None):
        Thread.__init__(self, group=group, target=target, name=name, args=args, kwargs=kwargs, daemon=daemon)
        self._return = None
        
    def run(self):
        if self._target is None:
            return
        
        self._return = self._target(*self._args, **self._kwargs)
        
    def join(self, timeout=None):
        Thread.join(self, timeout=timeout)
        return self._return
    
    
if __name__ == '__main__':
    pass