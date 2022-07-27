#include <stdio.h>
#include <limits.h>

int n, tmp;
int rc[501];  //1 : (0,1) .. k : (k-1,k)
int dp[501][501];

int min(int a, int b) { return (a<b) ? a : b ;}

int main()
{
	scanf("%d", &n); //printf("n : %d\n", n);
	scanf("%d %d", &rc[0], &rc[1]);
	for (int i=2; i<=n; i++){
		scanf("%d %d", &tmp, &rc[i] );
	}
	/*
	for (int i=0; i<n; i++){
		printf("%dth matrix : %2d *%2d\n", i+1, rc[i], rc[i+1]);
	}*/
	
	
	for (int i=1; i<=n; i++){ dp[i][i] = 0; }
	
	for (int k=1; k<n; k++){
		for (int i=1; i<=n-k; i++){
			int j = i+k; int min_cnt = INT_MAX;
			for (int r=i; r<j; r++){
				min_cnt = min( min_cnt, dp[i][r]+dp[r+1][j]+ rc[i-1]*rc[r]*rc[j] );
			}
			dp[i][j] = min_cnt;
		}
	}
	
	printf("%d\n", dp[1][n]);
	return 0;
}