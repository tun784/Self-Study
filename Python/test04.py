a = 2e3 # 2 * 10^3 = 2000
b = 1.8e307 # 1.8 * 10^307
c = 1.8e308 # 1.8 * 10^308
d = 5.0e-324 # 5.0 * 10^-324
e = 5.0e-325 # 5.0 * 10^-325
print(a) # 2000.0
print(b) # 1.8e+307
print(c) # inf
print(d) # 5e-324
print(e) # 0.0
print("")
x = 28.0460742734
y = 28.0440742735
z = 28.0450742734
print('%.3f' % x) # 28.046
print(round(x , 3)) # 28.044
print('{:.3f}'.format(x)) # 28.045

print('%.3f' % y) # 28.044
print(round(y , 3)) # 28.044
print('{:.3f}'.format(y)) # 28.044

print('%.3f' % z) # 28.045
print(round(z , 3)) # 28.045
print('{:.3f}'.format(z)) # 28.045
