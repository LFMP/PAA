#https://www.urionlinejudge.com.br/judge/pt/problems/view/2446
def troco(coins,m,v):
	memo = [['' for j in range(v)] for i in range(m)]
	for i in range(m):
		for j in range(v):
			if memo[i][j] == v:
				return 'S'
			elif i == 0:
				if j == 0:
					ans = 'S'
				else:
					ans = 'N'
			else:
				ans = memo[i-1][j]
				if ans == 'N' and coins[i] <= j:
					ans = memo[i-1][j - coins[i]]
			memo[i][j] = ans
	return memo[m-1][v-1]

val = [int(i) for i in input().split()]
v = val[0]
m = val[1]
coins = [int(i) for i in input().split()]
print(troco(coins,m,v))