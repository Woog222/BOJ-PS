#include <stdio.h>
#define MAX_N 1000001 //1,000,001
#define MAX_NUM 1000001


int n; 
int arr[MAX_N];
int dp[MAX_N];
int dp2[MAX_N +1];
int bi_search(int a, int b, int num);

int main()
{
	dp2[0]=0;
	int k=0;
	while (k++<MAX_N){ dp2[k]=MAX_NUM; }

	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &arr[i]);
	}
	/**************************/
	for (int i=1; i<=n; i++)
	{
		dp[i] = bi_search(0,i, arr[i]);
		dp2[dp[i]] = arr[i];
	}
	/**************************/
	int max_num =1;
	while(dp2[max_num++] != MAX_NUM ) {;}
	printf("%d\n", max_num-2);
	return 0;
}

int bi_search(int a, int b, int num)
{
	if (a>b) {return 0;}
	
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