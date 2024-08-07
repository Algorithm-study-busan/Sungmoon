class Node {
public:
  Node(int idx1, int idx2, int sum) : idx1(idx1), idx2(idx2), sum(sum) {}
  bool operator<(const Node& rhs) const {return sum > rhs.sum;}

  int idx1 = 0;
  int idx2 = 0;
  int sum = 0;
};

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    map<pair<int, int>, int> vst;
    priority_queue<Node> pq;
    vector<vector<int>> ret;
    pq.push({0, 0, nums1[0]+nums2[0]});
    vst[{0, 0}]++;

    while (k) {
      auto tmp = pq.top();
      ret.push_back({nums1[tmp.idx1], nums2[tmp.idx2]});
      pq.pop();

      if (tmp.idx1+1 < nums1.size() && !vst[{tmp.idx1+1, tmp.idx2}]) {
        pq.push({tmp.idx1+1, tmp.idx2, nums1[tmp.idx1+1]+nums2[tmp.idx2]});
        vst[{tmp.idx1+1, tmp.idx2}]++;
      }
      if (tmp.idx2+1 < nums2.size() && !vst[{tmp.idx1, tmp.idx2+1}]) {
        pq.push({tmp.idx1, tmp.idx2+1, nums1[tmp.idx1]+nums2[tmp.idx2+1]});
        vst[{tmp.idx1, tmp.idx2+1}]++;
      }
      k--;
    }
    return ret;
  }
};
