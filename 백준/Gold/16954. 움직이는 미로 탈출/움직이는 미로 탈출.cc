#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;




vector<string> map(8);
int visit[8][8][9];

int dr[] = {0,1,0,-1,1,1,-1,-1,0};
int dc[] = {1,0,-1,0,1,-1,1,-1,0};

inline int MIN(int a, int b) {
    return (a<b) ? a : b;
}
inline bool valid(int x,int y) {
    return !( x<0 || x>7 || y <0 || y >7);
}

int main()
{
    for(int i=0; i<8;i++) {
        cin >> map[i];
    } 
   
    queue<tuple<int,int,int>> q;
    
    q.push(make_tuple(7,0,0));
    visit[7][0][0] =1;
    
    int r, c, t;
    while( !q.empty())
    {
        tie(r, c, t) =q.front();
        q.pop();                
        
        for( int i =0; i<9; i++)
        {
            int nr = r+dr[i];
            int nc = c+dc[i];
            int nt = min(t+1,8);
            
            if ( !valid(nr, nc) )
            continue;             
            if(visit[nr][nc][nt]!=0) continue;
            // present          
            if (nr-nt+1>=0 && map[nr-nt+1][nc] == '#'  ) 
                continue;
            // soon
            if(nr-nt>=0 && map[nr-nt][nc]=='#')
                continue;            
            // finally..go!
            visit[nr][nc][nt] = visit[r][c][t]+1;
            q.push(make_tuple(nr,nc,nt));           
        } //for   
    } // bfs while
    
    if (visit[0][7][8]!=0)
        cout<< 1 << endl;
    else
        cout << 0 << endl;
}