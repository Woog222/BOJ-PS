#include <iostream>
#include <algorithm>
#include <iterator>


using namespace std;

int permutation[10001];

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> permutation[i];
    }

    int idx1 = 0, idx2 = n;
    for (int i = 1; i <= n-1; i++) 
    {
        if (permutation[i] < permutation[i + 1]) {
            idx1 = i;
        }
    } // 7216543 -> 1 is idx
    if (idx1 == 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = n; i > idx1; i--) 
    {
        if (permutation[i] > permutation[idx1]){
            idx2 = i;
            break;
        }
    }

 
    swap(permutation[idx1], permutation[idx2]);

    reverse(permutation + idx1 + 1, permutation + n+1);
    for (int i = 1; i <= n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
    return 0;
}