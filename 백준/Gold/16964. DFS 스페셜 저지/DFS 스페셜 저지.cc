#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, idx=0;
vector<int> graph[100001];
int check[100001];
int order[100001];

queue<int> q;

class Functor
{
    public:
    bool operator() (int a, int b)
    {
        return order[a] < order[b];
    }
};

void dfs( int a[] , int v)
{
    check[v] =1;
    if( a[idx++] != v)
    {
        cout << 0 <<endl;
        exit(0);
    }
    
    for( auto i :graph[v])
    {
        if ( check[i] == 0 )
        dfs(a, i);
    }
}


int main()
{
    cin >> n;
    
    int from, to;
    for(int i=1; i<n; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    int ans[n];
    int k =1;
    for(int i=0; i<n; i++) {
        cin >> ans[i];
        order[ans[i]] = k++;
    }
    
    if( ans[0] != 1)
    {
        cout << 0 <<endl;
        return 0;
    }
    for (int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end(), Functor() );
    }
    
     dfs(ans, 1);
    
    
    
    
    
   
    
    
    cout <<1 << endl;
   
    

} 