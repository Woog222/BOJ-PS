#include <stdio.h>
#define MAX_N 100000 /* 100,000 */
#define MAX(a,b) ((a)>(b))?(a):(b)

int n, arr[MAX_N+1], d[MAX_N+1][2];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++) { scanf("%d", &arr[i]); }
	
	d[1][0] = arr[1]; d[1][1] = arr[1];
	for (int i=2; i<=n; i++)
	{
		d[i][0] = MAX( d[i-1][0], d[i-1][1] );
		d[i][1] = MAX( d[i-1][1]+arr[i], arr[i]);
	}

	printf("%d\n", MAX(d[n][0], d[n][1]) );
	return 0;
}