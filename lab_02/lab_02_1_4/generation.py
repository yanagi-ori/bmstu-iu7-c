import random

f = open('data.txt', 'w')
f.write('10000\n')
for i in range(10000):
    f.write(str(random.randint(-10000, 10000)) + " ")
f.close
