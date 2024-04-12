#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> coins;
    int tmp;
    while(N--){
        cin >> tmp;
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end(), [](int a, int b){ return a > b; }); // 람다함수 이용 내림차순 정렬
    // reverse(coins.begin(), coins.end()); // coins 배열이 오름차순임이 보장되므로 그냥 뒤집기. 어떤게 더 효과적..?

    int cnt{};
    auto iter = coins.begin();
    while(K>0 && iter != coins.end()){
        if(*iter > K){
            iter++;
            continue;
        }; // 현재 단위가 남은 돈보다 크면 단위를 하나 낮추고 다시 반복
        K -= *iter;
        cnt++;
    }
    cout << cnt;
}
