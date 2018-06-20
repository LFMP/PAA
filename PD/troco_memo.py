import sys

sys.setrecursionlimit(1003)

def troco(coins,qtd,val,memo):
	if qtd < 0 or val <0:
		return False
	else:
		if memo[qtd][val] == -1:
				if val == 0:
					ans = True
				elif(qtd < 0 and val > 0):
					ans = False
				else:
					ans = troco(coins,qtd-1,val - coins[qtd],memo) or troco(coins,qtd-1,val,memo)
				memo[qtd][val] = ans
	return memo[qtd][val]

val0 = [int(i) for i in input().split()]
v = val0[0]
m = val0[1]
coins = [int(i) for i in input().split()]
memo = []
for x in range(m+1):
	lines = []
	for x in range(v+1):
		lines.append(-1)
	memo.append(lines)
	
if troco(coins,m-1,v,memo) == True:
	print('S')
else:
	print('N')