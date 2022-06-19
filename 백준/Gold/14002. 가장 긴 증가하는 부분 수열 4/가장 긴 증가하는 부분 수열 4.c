#include <stdio.h>
#define MAX_N 1000 
#define MAX_NUM 1000
#define MIN_NUM 1

int n, tmp, lis_len=0; 
int arr[MAX_N+1];
int dp[MAX_N+1];
int dp2[MAX_N+1];
int bi_search(int a, int b, int num);

int main()
{
	dp2[0]=MIN_NUM-1;
	tmp=0;
	while ( tmp++ < (MAX_N) ){ dp2[tmp]=MAX_NUM+1; }

	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	/**************************/
	for (int i=1; i<=n; i++)
	{
		if (dp2[lis_len]<arr[i])
		{
			dp2[++lis_len] = arr[i];
			dp[i] = lis_len;
		}
		else
		{
			dp[i] = bi_search(0,lis_len, arr[i]);
			dp2[dp[i]] = arr[i];
		}
	}
	printf("%d\n", lis_len);
	/**************************/
	tmp = n+1; lis_len++;
	while( lis_len-- > 1 ) /* lis_len ~ 1 */
	{
		while(tmp-- > 1) /* n -> 1 */
		{
			if (dp[tmp] == lis_len){
				dp2[lis_len] = arr[tmp];
				break;
			}	
		}
	}

	tmp = 0;
	while( dp2[++tmp] != MAX_NUM+1){
		printf("%d ", dp2[tmp]);
	}
	printf("\n");
	return 0;
}

int bi_search(int a, int b, int num)
{
	int med = (a+b)/2;
	if (dp2[med] == num){
		return med; 
	}
	else if ( dp2[med]<num && num<dp2[med+1] ){
		return med+1;
	}
	
	if (num>dp2[med]){
		return bi_search(med+1,b, num);
	}
	else{
		return bi_search(a,med-1, num);
	}
}