#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

map<ll, int> dist;
map<ll, pair<ll, char>> how;


int N;
void print_path(ll last);
int fun(const vvi& grid, int nth);
int main()
{
    ll s, t; cin >> s >> t;

    // num ,d


    queue<ll> q;
    q.push(s);
    dist[s] = 0;
    how[s] = make_pair(-1, '0');
    bool one = false;
    if (s == 1)
        one = true;


    while (!q.empty()) 
    {
        ll cur = q.front(); q.pop();
        int d = dist[cur];

        if (cur == t) {
            print_path(cur);
            return 0;
        }




        ll ncur;
        
        ncur = cur * cur;
        if ( ncur <= t && dist.find(ncur) == dist.end()) {
            q.push(ncur);
            dist[ncur] = d + 1;
            how[ncur] = make_pair(cur, '*');
        }
        
        ncur = cur + cur;
        if (  ncur <= t && dist.find(ncur) == dist.end()) {
            q.push(ncur);
            dist[ncur] = d + 1;
            how[ncur] = make_pair(cur, '+');
        }

        // zero.. no need
        /*
        ncur = cur - cur;
        if (ncur <= t && dist.find(ncur) != dist.end()) {
            q.push(ncur);
            dist[ncur] = d + 1;
        }*/


        ncur = cur / cur;
        if (!one) {
            q.push(ncur);
            dist[ncur] = d + 1;
            one = true;
            how[ncur] = make_pair(cur, '/');
        }
        
    }


    if (dist.find(t) == dist.end())
        cout << -1 << endl;
}

void print_path(ll last)
{
    ll cur = last;
    vector<char> ans;
    while (true) {
        pair<ll, char> temp = how[cur];

        if (temp.first == -1)
            break;

        ans.push_back(temp.second);
        cur = temp.first;
    }

    auto riter = ans.rbegin();
    for (; riter != ans.rend(); riter++)
        cout << *riter;

    if (ans.size() == 0)
        cout << 0;
    cout << endl;
}