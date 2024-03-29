import matplotlib.pyplot as plt
import numpy as npy

x = []
y = []
filename=input()
f=open(filename, 'r')
st = f.readline()
while st:
    x_v, y_v = map(float, st.split())
    x.append(x_v)
    y.append(y_v)
    st = f.readline()

X = npy.linspace(min(x),max(x),100)
fig, ax = plt.subplots()

ax.scatter(x, y, 5, 'b')

plt.grid(visible=True)
plt.show()