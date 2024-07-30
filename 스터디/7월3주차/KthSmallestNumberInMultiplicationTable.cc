class Solution {
public:
  int fn(int m, int n, int k) {
    int ret = 0;
    for (int i = 1; i < m+1; i++) {
      ret += (k/i >= n ? n : k/i);
    }
    return ret;
  }

  int findKthNumber(int m, int n, int k) {
    int fr = 0, rr = m*n;
    while (fr <= rr) {
      int mid = fr + (rr-fr)/2;
      if (k <= fn(m, n, mid)) rr = mid-1;
      else fr = mid+1;
    }
    return fr;
  }
};

/* 우선순위 큐 활용 풀이 ( MLE, 메모리 초과 )

class Int {
public:
  Int(int i) : i(i) {}
  bool operator<(const Int& other) const { return i > other.i; }

  int i;
};

class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    priority_queue<Int> pq;
    for (int i = 1; i < m+1; i++) {
      for (int j = 1; j < n+1; j++) {
        pq.push({i*j});
      }
    }
    for (int i = 0; i < k-1; i++) pq.pop();
    return pq.top().i;
  }
};

*/
