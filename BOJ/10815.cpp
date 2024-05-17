#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    ll N; cin >> N;
    vector<ll> vll(N);
    for (int i = 0; i < N; i++) cin >> vll[i];
    ran::sort(vll);

    ll M, tmp; cin >> M;
    while (M--) {
        cin >> tmp;
        cout << ran::binary_search(vll, tmp) << ' ';
    }
}

// bool binarySearch(vector<ll>& vec, ll fr, ll rr, ll val) {
//     while (fr <= rr) {
//         ll mid = (fr+rr)/2;
//         if (vec[mid] == val) return true;
//         else if (vec[mid] > val) rr = mid-1;
//         else fr = mid+1;
//     }
//     return false;
// }

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     ll N; cin >> N;
//     vector<ll> vll(N);
//     for (int i = 0; i < N; i++) cin >> vll[i];
//     ran::sort(vll);

//     ll M, tmp; cin >> M;
//     while (M--) {
//         cin >> tmp;
//         cout << binarySearch(vll, 0, vll.size(), tmp) << ' ';
//     }
// }
