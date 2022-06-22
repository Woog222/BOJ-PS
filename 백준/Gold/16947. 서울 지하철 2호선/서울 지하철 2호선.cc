#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> graph[3001];
vector<int> check;
queue<int> q;

int dfs(int cur, int prev)
{ 
// 1~n : 사이클찾음(시작정점)
// 0 : 못찾음
// -1 : 찾고 사이클끝남. 사이클아닌 시작부분
    if (check[cur] == -1) {
        return cur;
    }
    
    check[cur] = -1;
    
    for ( int next : graph[cur] )
    {
        if( next == prev) continue;
        int res = dfs(next, cur);
        
        if(res > 0)
        {
            check[cur] = 0;
            q.push(cur);
            if ( res == cur ){
                return -1;
            }
            else 
                return res;
        }
        
        if ( res == -1 )
            return -1;
    }
    
    return 0;
}


int main()
{
    cin >> n;
    
    int from, to;
    for(int i=1; i<=n; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    check.assign(n+1, -2);
    dfs(1,1);
    
    while ( !q.empty())
    {
        int v = q.front(); q.pop();
        
        for ( auto i : graph[v])
        {
            if( check[i] >= 0) continue;
            
            check[i] = check[v] +1;
            q.push(i);
        }
    }
    
    for (int i=1; i<= n ; i++) {
        cout << check[i] << " ";
    }
    cout << endl;
    
    
    
}