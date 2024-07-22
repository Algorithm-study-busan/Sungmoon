class Solution {
public:
  vector<string> split(string str, string delim) {
    vector<string> ret;
    size_t fr = 0, rr = str.find(delim);
    while (rr != string::npos) {
      if (fr != rr) ret.push_back(str.substr(fr, rr-fr));
      fr = rr + delim.size();
      rr = str.find(delim, fr);
    }
    ret.push_back(str.substr(fr));

    return ret;
  }

  string simplifyPath(string path) {
    auto tmp = split(path, "/");

    stack<string> stk;
    for (const auto& it : tmp) {
      if (it == ".") {
        continue;
      } else if (it == "..") {
        if (stk.size()) stk.pop();
      } else stk.push(it);
    }

    string ret;
    while (stk.size()) {
      ret = "/" + stk.top() + ret;
      stk.pop();
    }

    ret.erase(ret.find_last_not_of("/")+1);
    return (ret.size() ? ret : "/");
  }
};

/*

split() 함수를 통해 `/`를 기준으로 `path`를 부분 문자열들로 분리한 다음, 스택을 활용했습니다.
분리된 부분 문자열이 `.`일 때는 continue, `..`일 때는 스택의 이전 원소를 pop() (가능한 경우), 다른 문자일 때는 스택에 push()해준 다음,
스택이 빌 때 까지 스택의 top을 ret의 앞에 붙이고 pop()연산을 수행했습니다.

*/
