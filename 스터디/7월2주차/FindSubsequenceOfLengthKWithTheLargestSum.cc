class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    size_t sz = nums.size();
    vector<pair<int, int>> vp;
    for (int i = 0; i < sz; i++) {
      vp.push_back({nums[i], i});
    }

    ranges::sort(vp, [](const auto& a, const auto& b) {
      return a.first < b.first;
    }); // sort(vp.begin(), vp.end(), [](){});

    unordered_map<int, int> excl;
    for (int i = 0; i < sz-k; i++) excl[vp[i].second]++;

    vector<int> ret;
    for (int i = 0; i < sz; i++) {
      if (excl[i]) continue;
      else ret.push_back(nums[i]);
    }

    return ret;
  }
};

/*

pair 자료형을 이용해 `nums` 배열의 값과 그 값의 인덱스를 vp 벡터에 저장한 다음,
std::sort() 를 이용해 배열의 값의 크기를 기준으로 정렬합니다.

정렬된 값을 활용해 unordered_map 자료형에 배열의 값이 작은 순서대로 인덱스들을 저장한 다음,
nums 배열을 순회하며 해당 인덱스가 해시맵에 없는 경우에만 return 벡터에 추가합니다.

*/
