#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector<pair<string, ll>> v;
        for(int i=0; i<N; i++){
            string name;
            ll amount;
            cin >> name >> amount;
            v.push_back({name, amount});
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        cout << v[0].first << '\n';
    }
}
