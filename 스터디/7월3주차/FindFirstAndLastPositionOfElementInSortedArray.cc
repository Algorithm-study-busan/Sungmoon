class Solution {
public:
  int lower_bound(const vector<int>& vec, int val) {
    int fr = 0, rr = vec.size()-1;
    while (fr <= rr) {
      int mid = fr + (rr-fr)/2;
      if (vec[mid] < val) {
        fr = mid+1;
      } else rr = mid-1;
    }
    return fr;
  }

  int upper_bound(const vector<int>& vec, int val) {
    int fr = 0, rr = vec.size()-1;
    while (fr <= rr) {
      int mid = fr + (rr-fr)/2;
      if (vec[mid] <= val) {
        fr = mid+1;
      } else rr = mid-1;
    }
    return fr;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    int lb = lower_bound(nums, target);
    int ub = upper_bound(nums, target);

    vector<int> ret;
    if (lb == ub) {
      ret.push_back(-1);
      ret.push_back(-1);
      return ret;
    };
    ret.push_back(lb);
    ret.push_back(ub-1);
    return ret;
  }
};
