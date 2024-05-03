#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int K;
    cin >> K;

    stack<int> stk;
    while(K--){
        int tmp;
        cin >> tmp;
        if(!tmp) stk.pop(); // tmp가 0이면 pop
        else stk.push(tmp); // 0이 아니면 push
    }

    int ans{};
    while(stk.size()){ // 스택에 남아 있는 값들을 모두 ans에 더해주기
        ans += stk.top();
        stk.pop();
    }

    cout << ans;
}
