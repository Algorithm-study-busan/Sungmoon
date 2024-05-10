#include <bits/stdc++.h>
// namespace ran = std::ranges;
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;

    int N, M;
    string tmp;
    while (T--) {
        cin >> N >> M; // N: 국가의 수, M: 비행기의 종류

        cin.ignore(); // cin이후 getline 사용 전 `cin.ignore()` 꼭 써주기!
        for (int i = 0; i < M; i++) getline(cin, tmp); // M줄의 입력 무시
        cout << N-1 << '\n'; // Minimum Spanning Tree의 성질에 의해 간선 수는 `정점-1`
    }
}
