//https://www.urionlinejudge.com.br/judge/pt/problems/view/2446

#include <stdio.h>
#include <stdlib.h>

bool troco(int coins[], int m, int v){
	bool ans,memo[m][v];
	int k,l,i,j;

	for (i = 0; i < m; i++){
		for (j = 0; j < v; j++){
			memo[i][j] = false;
		}
	}

	for (k = 0; k < m; k++){
		for (l = 0; l < v; l++){
			if (k == 0){
				if (l == 0){
					ans = true;
				}else{
					ans = false;
				}
			}else{
				ans = memo[k-1][l];
				if (ans == false && coins[k] <= l){
					ans = memo[k-1][l - coins[k]];
				}
			}
			memo[k][l] = ans;
		}
	}
	return memo[m-1][v-1];
}

int main(){
	int v,m;
	scanf("%d %d", &v, &m);
	int *coins,s=0;
	coins = (int*)malloc(m*sizeof(int));

	for (s = 0; s < m-1; ++s){
		scanf("%d ", &coins[s]);
	}
	scanf("%d", &coins[s]);

	if (troco(coins,m,v) == 1){
		printf("S\n");
	}else{
		printf("N\n");
	}
}