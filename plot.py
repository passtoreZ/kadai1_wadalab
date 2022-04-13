import numpy as np
import matplotlib.pyplot as plt

output_data_0_8 = open("output.dat")
out_0_8 = []
for value in output_data_0_8:
    out_0_8.append(float(value))

plt.plot(out_0_8)

plt.savefig('test.png')