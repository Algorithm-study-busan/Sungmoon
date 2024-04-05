#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<int, 5004> dp;

int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    fill(dp.begin(), dp.end(), 1667); // 5000 / 3 = 1666.66666666이기 때문에, 1667은 나올 수 없는 값
    dp[3] = 1; dp[5] = 1;

    int N;
    cin >> N;

    for(int i=6; i<=N; i++){
        if(dp[i-3] == 1667 and dp[i-5] == 1667) continue;
        dp[i] = min(dp[i-3], dp[i-5]) + 1;
    }

    if(dp[N] == 1667) cout << -1;
    else cout << dp[N];
}
