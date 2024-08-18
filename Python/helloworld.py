import string
import time
text = 'Hello World Im Gay'
temp = ''
for ch in text:
    for i in string.printable:
        if i == ch or ch == ' ':
            time.sleep(0.02)
            print(temp+i)
            temp +=ch
            break
        else:
            time.sleep(0.02)
            print(temp+i)