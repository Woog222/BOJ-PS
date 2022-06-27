#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <deque>
#include <cstdlib>
using namespace std;
struct Point {
	int x, y;
};

bool comp_x(Point &a, Point &b) {
	return a.x < b.x;
}
bool comp_y(Point &a, Point &b) {
	return a.y < b.y;
}


const int MAX = 987654321;


inline int MIN(int a, int b){
	return (a<b) ? a : b;
}

inline int distance (Point a, Point b) {
	return (a.x-b.x)*(a.x-b.x) + 
		(b.y-a.y)*(b.y-a.y);
}

int brute_force(vector<Point> &a, int start, int end) {
    int ans = -1;
    for (int i=start; i<=end-1; i++) {
        for (int j=i+1; j<=end; j++) {
            int d = distance(a[i], a[j]);
            if (ans == -1 || ans > d) {
                ans = d;
            }
        }
    }
    return ans;
}

int fun(vector<Point> &a, int low, int high)
{
	if(high-low <=3) return brute_force(a, low, high);

	int mid = (low+high)/2; 
	//cout << low << mid << high << endl;
	int left =fun(a, low, mid);
	int right = fun(a, mid+1, high);
	int d = MIN( left, right );
	int res = d;

	
	vector<Point> middle;
	for (int i = mid+1;i<=high;++i) {
		int diff = a[mid].x - a[i].x;
		if (diff * diff >= d) break;
		middle.push_back(a[i]);
	}
	for (int i = mid;i>=low;--i) {
		int diff =a[mid+1].x - a[i].x;
		if (diff * diff >= d) break;
		middle.push_back(a[i]);
	}
	
	sort(middle.begin(), middle.end(), comp_y);
	int size = middle.size();
for(int i=0; i<size-1; ++i){
		for (int j = i+1; j<size; ++j) {
			int diff = middle[i].y - middle[j].y;
			if (diff * diff >= d) break;
			
			res = MIN( res, distance( middle[i],middle[j] ) );			
		}
	}
	
	return res;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<Point> a(n);
	int temp_x, temp_y;
	for (int i=0; i<n; ++i) {
		cin >> temp_x >> temp_y;
		a[i] = {temp_x, temp_y};
	}
	
	sort(a.begin(), a.end(), comp_x);
	cout << fun(a,0,n-1) << endl;
}