#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> list;
void getpow(int n) {
    for (int i = 1; i * i <= n; i++)
        list.push_back(i);
}

int dfs(int num, int cnt, int i) {
    if (num == n)
        return cnt;
    if (num > n)
        return;
    for (int j = i; j >= 0; j--) {
        dfs(num + list[i], cnt + 1, j);
    }
}

int main() {
    // cin >> n;
    n = 12;
    getpow(n);
    int min = 9999999;
    for (int i = list.size() - 1; i >= 0; i--) {
        int res = dfs(list[i], 1, i);
        if (res < min)
            min = res;
    }
    cout << min << endl;
}