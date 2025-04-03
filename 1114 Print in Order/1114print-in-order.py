import threading

class Foo:
    def __init__(self):
        self.lock1 = threading.Lock()
        self.lock2 = threading.Lock()
        
        # Verrouiller les deux locks au départ
        self.lock1.acquire()
        self.lock2.acquire()

    def first(self, printFirst):
        """
        :type printFirst: method
        :rtype: void
        """
        printFirst()  # Imprime "first"
        self.lock1.release()  # Débloque second()

    def second(self, printSecond):
        """
        :type printSecond: method
        :rtype: void
        """
        self.lock1.acquire()  # Attend que first() soit terminé
        printSecond()  # Imprime "second"
        self.lock2.release()  # Débloque third()

    def third(self, printThird):
        """
        :type printThird: method
        :rtype: void
        """
        self.lock2.acquire()  # Attend que second() soit terminé
        printThird()  # Imprime "third"
