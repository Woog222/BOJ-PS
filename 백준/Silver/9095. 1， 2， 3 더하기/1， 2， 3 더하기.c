#include <stdio.h>
#define NUM 11


int main()
{
	int arr[NUM];
	int t, n, num_3;
	scanf("%d", &t);
	
	arr[0] = 1; 
	arr[1] = 1; // 1
	arr[2] = 2; // 2, 1+1
	// arr[3] =  ;  3, 2+1, 1+2, 1+1+1;
	
	for (int i=1; i<=t; i++)
	{
		scanf("%d", &n);
		
		for (int j=3; j<=n; j++){
			arr[j] = arr[j-3] + arr[j-2] + arr[j-1];
		}
		
		printf("%d\n", arr[n]);
	}
	
	
		
	return 0;
}
