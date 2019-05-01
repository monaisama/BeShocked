b = [[0,1],[0,0],[1,1]]
import random
import numpy as np
MAX_TIME = 100000
ball_arr = np.array([[0,0],[0,0]])
for i in range(MAX_TIME):
	p1 = int(random.random() * 3)
	p2 = int(random.random() / 0.5)
	
	ball1 = b[p1][p2]
	ball2 = b[p1][1-p2]
	
	ball_arr[ball1][ball2] += 1
	
print("redred ball:{}".format(ball_arr[0][0]))
print("redblue ball:{}".format(ball_arr[0][1]))
print("bluered ball:{}".format(ball_arr[1][0]))
print("blueblue ball:{}".format(ball_arr[1][1]))

print("blueblue/(bluered+blueblue):{}".format(float(ball_arr[1][1])/(ball_arr[1][1]+ball_arr[1][0])))
