#include <stdio.h>
#include <string.h>
#define MAX(a,b) ((a)>(b))?(a):(b)

int n;
int arr[1001];
int dp[1001];
int dp2[1001];

int max(int a, int b) { return a;}
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	
	for (int i=1; i<=n; i++)
	{
		dp[i] = 1;
		for (int j=1; j<i; j++){
			if (arr[i]>arr[j]){
				dp[i] = MAX(dp[i], dp[j]+1);
			}
		}
	}
	int max_num = dp[n];
	while(n-- > 0){
		max_num = MAX(dp[n+1], max_num);
	}
	printf("%d\n", max_num);
	return 0;
}