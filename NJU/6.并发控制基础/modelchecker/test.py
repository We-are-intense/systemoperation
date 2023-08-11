import threading

class MyClass:
    my_var = 0

def increment():
    for i in range(100000000):
        MyClass.my_var += 1

def decrement():
    for i in range(100000000):
        MyClass.my_var -= 1

t1 = threading.Thread(target=increment)
t2 = threading.Thread(target=decrement)

t1.start()
t2.start()

t1.join()
t2.join()

print(MyClass.my_var)