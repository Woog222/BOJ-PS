#include <iostream>
#include <tuple>
#include <deque>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> ans;
int n,m,k;
vector<int> group_bound;

void fun(int st, int end, int a_left, int b_left)
{
}

int main()
{
    cin >> n>> m >> k;
    
    // boundary check
    if(n>k*m || n<m+k-1) {
        cout <<-1<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        ans.push_back(i);
        
    
    group_bound.push_back(0);
    while( m>1 &&  ( (n-k) / (m-1) ) > 0 ) {
        group_bound.push_back(group_bound.back()+k);
        n-=k; m--;
    }
    
    if( m>1 ) {
    for(int i=k-1; ; i--) {
        if(  ( (n-i) / (m-1) ) > 0   )
        {
            group_bound.push_back(group_bound.back()+i);
            m--;
            while(m--) {
                group_bound.push_back(group_bound.back()+1);
            }
            break;
        }
    } // for
    }
    else 
        group_bound.push_back(group_bound.back()+n);
    
    
    
    
    int limit = (int)group_bound.size()-1;
    auto iter = ans.begin();
    for(int i=0; i< limit; i++ )
    {
        reverse(iter+group_bound[i], iter+group_bound[i+1]);
    }
    
    for (int i : ans)
        cout <<i<<" ";        
    cout<<endl;
    
}