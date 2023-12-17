
# ------------------- Another way to implement singleton ------------------- #
class Singleton: 
    __instance = None
    
    @staticmethod
    def getInstance():
        if Singleton.__instance == None:
            Singleton()
        return Singleton.__instance
    
    def __init__(self):
        if Singleton.__instance != None:
            raise Exception("This class is a singleton!")
        else:
            Singleton.__instance = self
            
# ------------------- Another way to implement singleton ------------------- #
class Singleton2:
    
    __instance = None
    name = None
    
    def __new__(cls, *args, **kwargs):
        if Singleton2.__instance == None:
            Singleton2.__instance =object.__new__(cls, *args, **kwargs)
        return Singleton2.__instance
    
    def __init__(self, name = None):
        self.name = name
    
    @staticmethod
    def getInstance():
        if Singleton2.__instance == None:
            Singleton2()
        return Singleton2.__instance
    
    def setName(self, name):
        self.name = name
        
    def getName(self):
        return self.name

# ------------------- Another way to implement singleton ------------------- #
def singleton(cls):
    instance = {}

    def wrapper(*args, **kwargs):
        if cls not in instance:
            instance[cls] = cls(*args, **kwargs)
        return instance[cls]
    wrapper.__name__ = cls.__name__
    wrapper.__doc__ = cls.__doc__
    return wrapper
    
@singleton
class Singleton3:

    def __init__(self, name = None):
        self.name = name
    
    def setName(self, name):
        self.name = name
        
    def getName(self):
        return self.name
  
if __name__ == "__main__":
    a = Singleton.getInstance()
    print(a)
    b = Singleton.getInstance()
    print(b)
    
    s = Singleton2()
    s.setName('AmitKumar')
    print(s, s.getName())
    
    s2 = Singleton2("Singleton2")
    print(s2.getName(),s.getName())
    s3 = Singleton2.getInstance()
    print(s3)
    
    s4 = Singleton3()
    print(s4)
    s5 = Singleton3()
    print(s5)
    