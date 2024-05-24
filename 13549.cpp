#include <bits/stdc++.h>
namespace ran = std::ranges;
using namespace std;
using ll = long long;

int arr[100004];

int main() {
  int N, K;
  cin >> N >> K; // 5, 17

  deque<int> dq;
  dq.push_back(N);
  arr[N] = 1;
  while (!dq.empty() && !arr[K]) {
    int tmp = dq.front(); dq.pop_front();
    if (tmp*2 <= 100000 && !arr[tmp*2]) {
      arr[tmp*2] = arr[tmp];
      dq.push_front(tmp*2);
    }
    if (tmp-1 >= 0 && !arr[tmp-1]) {
      arr[tmp-1] = arr[tmp]+1;
      dq.push_back(tmp-1);
    }
    if (tmp+1 <= 100000 && !arr[tmp+1]) {
      arr[tmp+1] = arr[tmp]+1;
      dq.push_back(tmp+1);
    }
  }
  cout << arr[K]-1 << '\n';
}
