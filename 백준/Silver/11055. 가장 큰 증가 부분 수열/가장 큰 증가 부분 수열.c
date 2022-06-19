#include <stdio.h>
#define MAX_N 1000
#define MAX_NUM 1000
#define MIN_NUM 1
#define MAX(a,b) ((a)>(b))?(a):(b)

int n;
int arr[MAX_N+1];
int dp[MAX_N+1];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}
	/**************************/
	int max = MIN_NUM-1;
	for (int i=1; i<=n; i++){
		for (int j=1; j<i; j++)
		{
			if ( (arr[j] < arr[i]) && (dp[j]+arr[i] > dp[i]) )
			{
				dp[i] = arr[i] + dp[j];
			}
		}
		max = MAX(max, dp[i]);
	}

	printf("%d\n", max);

	return 0;
}