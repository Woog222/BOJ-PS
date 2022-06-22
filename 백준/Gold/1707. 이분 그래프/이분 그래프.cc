#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> graph[20001];
int check[20001] = {0,};
int v, e;

bool bfs(int v)
{
    if (check[v])
    return true;
    
    queue<int> q;
    check[v] =1;
    q.push(v);
    
    int tmp;
    while( !q.empty())
    {
        tmp =q.front();
        q. pop();
        
        for( auto i : graph[tmp])
        {
            if(check[i] == check[tmp]){
                return false;
            }
            if( !check[i] )
            {
                check[i] = check[tmp]*(-1);
                q.push(i);
            }
        }
    }
    
    return true;
}



int main()
{
    
    int t; cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for (int i=1; i<=v; i++)
        {
            vector<int>().swap(graph[i]);
            check[i] =0;
        }
        
        int from, to;
        while(e--)
        {
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }// edge input while
        
        bool result = true;
        
        for (int i=1; i <= v; i++)
        {
            if (!check[i])
            {
                if (!bfs(i))
                {
                    result = false;
                    break;
                }          
            }            
        }
        
        if ( result )
        cout << "YES" << '\n';
        else
        cout << "NO" << '\n';
        
        
    } // case while
}