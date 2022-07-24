#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
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
#include <set>
#include <iterator>
#include <cstdlib>
#include <climits>
#define el '\n';
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

struct bigint {
    vector<int> num;
    int n; // 자리수

    bigint(ll k) {
        num.resize(0);
        while (k) {
            num.push_back(k % 10);
            k /= 10;
        }
        n = num.size();
    }

    bigint(const string& s) {
        n = s.length();
        for (int i = n - 1; i >= 0; --i)
            num.push_back(s[i]);
    }


    bigint operator * (const bigint& b) const {

        bigint ret(0);
        ret.num.resize(n + b.n,0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < b.n; ++j) {
                ret.num[i + j] += num[i] * b.num[j];
            }
        }

        ret.normalize();
        return ret;
    }

    void normalize() {
        
        // 올림에 대비
        num.push_back(0);
        for (int i = 0; i + 1 < num.size(); ++i) {
            if (num[i] < 0) {
                int borrow = (abs(num[i]) + 9) / 10;
                num[i + 1] -= borrow;
                num[i] += borrow * 10;
            }
            else {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }

        while (num.size() > 1 && num.back() == 0) num.pop_back();
        n = num.size();
    }

    string toString() const {
        // 음수인 경우와 양수인 경우 따로 처리
        // 음수인 경우는 맨 마지막 

        vector<char> ret;
        for (auto riter = num.rbegin(); riter != num.rend(); ++riter) {
            ret.push_back((*riter) + '0');
        }
        return string(ret.begin(), ret.end());
    }
};
vi primeFactorization(int num);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vi div;
    for (int i = 1; i <= m; ++i) {
        auto primes = primeFactorization(i);
        div.insert(div.end(), primes.begin(), primes.end());
    }

    bigint ans(1);
    for (int i = 0; i < m; ++i) 
    {
        int temp = n - i;
        while (!div.empty()) {
            bool erased = false;
            for (auto iter = div.begin(); iter != div.end(); ++iter) {
                if (temp % (*iter) == 0) {
                    temp /= *iter;
                    div.erase(iter);
                    erased = true;
                    break;
                }
            }
            if (!erased)
                break;
        }
        ans = ans * bigint(temp);
    }

    cout << ans.toString() << '\n';
}

vi primeFactorization(int num) {
    vi ret;
    int last = sqrt(num);
    for (int i = 2; i <= last; ++i) {
        while (num % i == 0) {
            ret.push_back(i);
            num /= i;
        }
    }

    if (num > 1)
        ret.push_back(num);
    return ret;
}