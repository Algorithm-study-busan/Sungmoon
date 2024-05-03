#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M; cin >> N >> M;

    string tmp;
    unordered_map<string, int> mp;
    for (int i = 0; i < N+M; i++) {
        cin >> tmp;
        mp[tmp]++;
    }

    vector<string> vs;
    for (const auto& [k, v] : mp) {
        if (v == 2) vs.push_back(k);
    }
    ran::sort(vs); // std::sort(vs.begin(), vs.end());

    cout << vs.size() << '\n';
    for (const auto& it : vs) cout << it << '\n';
}
