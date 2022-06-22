#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Edge
{
    int to;
    int weight;
    Edge(int a, int b)
    {
        to = a;
        weight = b;
    }
};

vector<Edge> tree[100001];
int check[100001];
int d[100001];
int n;

void dfs(int v)
{
    check[v] = true;
    
    
    for(auto i : tree[v])
    {
        if( check[i.to] ) continue;
        
        d[i.to] = d[v] + i.weight;
        dfs(i.to);
    }
}



int main()
{
    cin >>n;
    int a, b;
    for(int i=1; i<=n; i++)
    {
        int a, v, w;
        cin >> a;
        
        while(true) {
            cin >> v;
            if( v==-1) break;
            cin >> w;
            tree[a].push_back(Edge(v, w));
        }       
    }
    
    dfs(1);
    
    
    int start = 1;
    for(int i=2; i<=n; i++)
    {
        if (d[i] > d[start]) 
        start = i;
    }
    
    memset(check, 0, sizeof(check));
    memset(d, 0, sizeof(d));
    
    dfs(start);
    
    
    for(int i=1; i<=n; i++)
    {
        if (d[i] > d[start]) 
        start = i;
    }
    
    
    cout << d[start] << endl;
   
    
    
}