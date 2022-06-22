#include <iostream>
#include <queue>
using namespace std;

int check[100001] = {0,};
int n, k;

int main()    
{
    cin >> n >> k;
    if (n==k) 
      {
        cout << 0 << endl;
        return 0;
        }
    
    queue<int> q;
    check[n] = 1;
    q.push(n);
    
    while(!q.empty())
    {
        int num = q.front();
        q.pop();
       
        if ( num-1 >=0 && check[num-1] == 0)
        {
            if (num-1 == k) 
            {
                cout << check[num] << endl;
                return 0;
            }
            q.push(num-1);
            check[num-1] = check[num] +1;
        }
        
        if ( num+1<= 100000 && check[num+1] == 0)
        {
            if (num+1 == k) 
            {
                cout << check[num] << endl;
                return 0;
            }
            q.push(num+1);
            check[num+1] = check[num] +1;
        }
        
        if ( num*2 <= 100000 && check[num*2] == 0)
        {
            if (num*2 == k) 
            {
                cout << check[num] << endl;
                return 0;
            }
            q.push(num*2);
            check[num*2] = check[num] +1;
        }
        
        
    }
}