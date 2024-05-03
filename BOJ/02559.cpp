#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> vi(N);
    for (int i = 0; i < N; i++) cin >> vi[i];

    int fr = 0, rr = K;
    vector<int> res;
    while (rr <= N) {
        res.push_back(reduce(&vi[fr], &vi[rr]));
        fr++, rr++;
    }
    cout << ran::max(res); // std::ranges::max();
}
