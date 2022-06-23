#include <iostream>
#include <vector>
using namespace std;

int dx[] ={0,0,1,-1};
int dy[] ={1,-1,0,0};

int n, m;
bool check[500];
vector<string> map(20);

int fun(int i, int j)
{
    
    int ans =0;
    for(int k =0; k<4; k ++)
    {
        
                          
        int ni = i + dx[k];
        int nj = j + dy[k];
        int temp;
        
        if (ni <0 || ni>=n || nj<0 || nj>=m)
            continue;
        if ( check[ map[ni][nj] ] ) 
            continue;
            
        check[ map[ni][nj]  ]= true;
        temp = fun(ni, nj);
        check[ map[ni][nj] ] = false;
        if ( ans < temp) 
            ans = temp;
        
    }
    
    return ans+1;
}

int main()
{
    cin >> n >> m;
    for (int i=0;i<n; i++) {
        cin >> map[i];
    }
    
    check[map[0][0]]=true;
    
    cout << fun(0,0) << endl;
    
}