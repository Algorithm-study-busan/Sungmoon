#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> vi(2*n);

    for(int i{}; i<2*n; i++) cin >> vi[i];
    sort(vi.begin(), vi.end());

    int tmp{}, res = vi[0] + vi[2*n-1];
    for(int i=1; i<n; i++){
        tmp = vi[i] + vi[2*n-i-1];
        res = min(res, tmp);
    }
    cout << res;
}
