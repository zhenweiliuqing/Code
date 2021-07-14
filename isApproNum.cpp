#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> sset;
    sset.insert(1);
    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= sqrt(arr[i]); j++) {
            if (arr[i] % j == 0)
                sset.insert(j);
        }
    }

    int l, r;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        for (int j = l; j <= r; j++) {
            if (sset.count(j) == 1)
                ans++;
        }
        cout << ans;
        ans = 0;
    }
}