import queue
class MyStack(object):

    def __init__(self):
        self.q1=queue.Queue()
        self.q2=queue.Queue()

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.q1.put(x)
       # for i in range(self.q1.qsize()):
        #    if not(self.q1.empty()):
        #      c=self.q1.get()

                

        

    def pop(self):
        """
        :rtype: int
        """
        while not(self.q1.empty()):
            c=self.q1.get()
            self.q2.put(c)
        while not(self.q2.empty()):
            v=self.q2.get()
            if v!=c:
                self.q1.put(v)
        return c
        

    def top(self):
        """
        :rtype: int
        """
        while not(self.q1.empty()):
            c=self.q1.get()
            self.q2.put(c)
        while not(self.q2.empty()):
            self.q1.put(self.q2.get())
        return c

    def empty(self):
        """
        :rtype: bool
        """
        return self.q1.empty()
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()