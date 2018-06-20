//https://www.urionlinejudge.com.br/judge/pt/problems/view/2446
#include <stdio.h>
#include <stdlib.h>

bool troco(int coins[], int m, int v){
	if (m >= 0 && m<=1000 && v >= 0 && v<=100000){
		bool memo[m][v];
		int k = 0,l = 0,i = 0,j = 0;

		for (i = 0; i < m; i++){
			for (j = 0; j < v; j++){
				memo[i][j] = false;
			}
		}

		for (k = 0; k < m; k++){
			for (l = 0; l < v; l++){
			    if (memo[k][l] == v){
			        return true;
			    }
				else if (k == 0){
					if (l == 0){
                        memo[k][l] = true;
					}else{
                        memo[k][l] = false;
					}
				}else{
                    memo[k][l] = memo[k-1][l];
					if (memo[k][l] == false && coins[k] <= l){
                        memo[k][l] = memo[k-1][l - coins[k]];
					}
				}
			}
		}
		return memo[m-1][v-1];
	}
	return 0;
}

int main(){
	int v = 0,m = 0,s=0;
	scanf("%d %d", &v, &m);
	int coins[m];

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