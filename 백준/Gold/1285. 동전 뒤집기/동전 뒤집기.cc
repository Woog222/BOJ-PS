#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

vector<string> map;
int n;

inline int MIN(int a, int b) {
    return (a<b) ? a : b;
}


int main()
{
    cin >> n;
    map.resize(n);
    for(int i=0; i<n; i++) {
        cin >> map[i];
    }
    
    int MAX = 1<<n;
    int ans= 401;
    
    for (int b=0; b<MAX; b++) 
    {
        int sum =0;
        
        for(int i=0; i<n; i++) {
            int row_sum=0;
            for(int j=0; j<n; j++) {
                if( (b & (1<<j)) && map[i][j] =='T')
                    row_sum++;
                else if ( !(b & (1<<j)) && map[i][j] =='H')
                    row_sum++;                
            }
            sum += MIN(row_sum, n-row_sum);
        }
        
        ans = MIN(sum, ans);
    }
  
    cout << ans << endl;  
}