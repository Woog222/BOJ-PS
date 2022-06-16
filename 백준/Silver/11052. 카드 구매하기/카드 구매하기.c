#include <stdio.h>
#define MAX_N 1000
#define MAX_NUM 10000
#define MAX(a,b) ((a)>(b))?(a):(b)

int n, max;
int arr[MAX_N+1];
int dp[MAX_N+1];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	
	for (int i=1; i<=n; i++)
	{ 	
		max = arr[i];
		for (int j=1; j<=i/2; j++){
			max = MAX(max, dp[j]+dp[i-j]);
		}
		dp[i] = max;
	}
	
	printf("%d\n", dp[n] );
	return 0;
}