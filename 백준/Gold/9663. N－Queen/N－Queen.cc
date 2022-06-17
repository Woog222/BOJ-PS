#include <iostream>
using namespace std;

int n, ans=0;
int map[20][20];
int col[20];
int d1[39];
int d2[39];

bool check(int r, int c)
{
    if (col[c] || d1[r+c] || d2[r-c+n-1])
        return false;
    else
        return true;
}

void fun( int r)
{
    if (r == n) {
        ans +=1;
        return ;
    }
    
    for (int i=0; i<n;i++) 
    {
        if (! check(r,i) ) continue;
        
        col[i] = true;
        d1[r+i] = true;
        d2[r-i+n-1] =true;
        fun(r+1);
        col[i] = false;
        d1[r+i] = false;
        d2[r-i+n-1] = false;                
    }
}


int main()
{
    cin >> n;
    fun(0);
    cout << ans << endl;
}