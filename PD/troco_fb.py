import sys

sys.setrecursionlimit(3000)

def troco(coins,qtd,val):
	if val >= 0 and qtd >= 0:
		if val == 0:
			return True
		elif(qtd < 0 and val > 0):
			return False
		else:
			return troco(coins,qtd-1,val - coins[qtd]) or troco(coins,qtd-1,val)
	else:
		return False

val = [int(i) for i in input().split()]
v = val[0]
m = val[1]
coins = [int(i) for i in input().split()]
if troco(coins,m-1,v) == True:
	print('S')
else:
	print('N')