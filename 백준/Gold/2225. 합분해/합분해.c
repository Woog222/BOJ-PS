#include <stdio.h>
#define MAX_NUM 200
#define DIVISOR 1000000000 /* 1,000,000,000 */

int n,k;
int d[MAX_NUM+1][MAX_NUM+1]; /* d[k][n]*/

int main()
{
	scanf("%d %d", &n, &k);
	
	for (int i=0; i<=n; i++){ d[1][i] = 1; }
	for (int i=0; i<=k; i++){ d[i][0] = 1; }
	
	for (int i=2; i<=k; i++){
		for (int j=1; j<=n; j++)
		{
			d[i][j] = ( d[i-1][j] + d[i][j-1] )%DIVISOR;
		}
	}

	printf("%d\n", d[k][n]);
	return 0;
}