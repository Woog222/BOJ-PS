#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    vi cand = { x, y, h - y, w - x };
    cout << *min_element(cand.begin(), cand.end());
}