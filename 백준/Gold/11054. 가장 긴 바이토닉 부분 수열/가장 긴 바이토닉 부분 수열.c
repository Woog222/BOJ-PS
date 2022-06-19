#include <stdio.h>
#define MAX_N 1000
#define MAX_NUM 1000
#define MIN_NUM 1
#define MAX(a,b) ((a)>(b))?(a):(b)

int n, tmp, lis_len=0, max_bitonic_len=0;
int arr[MAX_N+1], arr_reverse[MAX_N+1];
int dp_aug[MAX_N+1];
int dp_reverse_aug[MAX_N+1];
int dp_sub[MAX_N+1] = {MIN_NUM-1};
int bi_search(int a, int b, int num);

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{ 
		scanf("%d", &tmp); 
		arr[i] = arr_reverse[n+1-i] = tmp;
	}

	/* aug index 구하기 */
	tmp = n+1; /* n-> 1*/
	while (tmp-- > 1) { dp_sub[tmp] = MAX_NUM+1; }
	
	for (int i=1; i<=n; i++)
	{
		if ( arr[i] > dp_sub[lis_len] )
		{
			dp_sub[++lis_len] = arr[i];
			dp_aug[i] = lis_len;
		}
		else
		{
			dp_aug[i] = bi_search(1,lis_len, arr[i]);
			dp_sub[ dp_aug[i] ] = arr[i];
		}
	}
	
	/* reverse_aug index 구하기 */
	tmp = lis_len+1; /* tmp lis_len -> 1 */
	while (tmp-- > 1) { dp_sub[tmp] = MAX_NUM+1; }
	lis_len = 0;
	
	for (int i=1; i <=n ; i++)
	{
		if ( arr_reverse[i] > dp_sub[lis_len])
		{
			dp_sub[++lis_len] = arr_reverse[i];
			dp_reverse_aug[i] = lis_len;
		}
		else 
		{
			dp_reverse_aug[i] = bi_search(1, lis_len, arr_reverse[i]);
			dp_sub[ dp_reverse_aug[i] ] = arr_reverse[i];
		}
	}
	
	/* max_bitonic_len 구하기 */
	for (int i=1; i<=n; i++)
	{
		max_bitonic_len = MAX( max_bitonic_len, 
							   dp_aug[i] + dp_reverse_aug[n+1-i] -1 );
	}
	
	printf("%d\n", max_bitonic_len);
	return 0;
}

int bi_search(int a, int b, int num)
{
	if (a>b) {return -1;}
	int med = (a+b)/2;
	if ( dp_sub[med-1]<num && num<=dp_sub[med] ){
		return med; 
	}
	
	if ( num > dp_sub[med] ){
		return bi_search(med+1,b, num);
	}
	else{
		return bi_search(a,med-1, num);
	}
}