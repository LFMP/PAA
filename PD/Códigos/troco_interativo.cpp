//https://www.urionlinejudge.com.br/judge/pt/problems/view/2446
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int troco(int coins[], int m, int v){
  // Alocação dinâmica do memo
  int ** memo = (int**)malloc(sizeof(int*) * (m+1)), i, ans;
  for(i=0; i<m+1; i++)
    memo[i] = (int*)malloc(sizeof(int) * (v+1));

	for (int i = 0; i < m+1; ++i){
		memo[i][0] = 1;
	}
	for (int i = 1; i < v+1; ++i){
		memo[0][i] = 0;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= v; j++){
			if (j < coins[i-1]){
				memo[i][j] = memo[i-1][j];
			}
			else{
				memo[i][j] = memo[i-1][j] || memo[i-1][j-coins[i-1]];
			}
		}
	}
	return memo[m][v];
}

int main(){
	int v = 0,m = 0,s=0;
	cin >> v >> m;
	int coins[m];

	for (s = 0; s < m; s++){
		cin >>coins[s];
	}

	if (troco(coins,m,v) == 1){
		printf("S\n");
	}else{
		printf("N\n");
	}
}