#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

ll K, N;

bool check(vector<ll>& vec, ll len) {
    int cnt = 0;

    for (ll i = 0; i < K; i++) cnt += vec[i] / len;

    if (cnt >= N) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> K >> N;
    vector<ll> vi(K);
    for (ll i = 0; i < K; i++) cin >> vi[i];
    ran::sort(vi);

    ll fr = 1, rr = vi[vi.size()-1], res = 0; // DivisionByZero 피하기 위해

    while (fr <= rr) {
        ll mid = (fr+rr) / 2;
        if (check(vi, mid)) {
            res = max(res, mid);
            fr = mid+1;
        } else {
            rr = mid-1;
        }
    }
    cout << res;
}
