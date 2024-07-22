class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
      int res = students.size();

      queue<int> q;
      for (const auto& it : students) q.push(it);

      int idx = 0, rep = 0;
      while (idx < students.size()) {
        if (sandwiches[idx] == q.front()) {
          res--; idx++;
          q.pop();
          rep = 0;
        } else {
          rep++;
          if (rep > q.size()) break;
          int tmp = q.front(); q.pop();
          q.push(tmp);
        }
      }

      return res;
    }
};

/*

`students` 배열을 큐에 옮긴 다음, while문을 통해 `sandwiches` 배열의 원소들을 확인합니다
0으로 초기화된 idx 변수가 가리키는 sandwiches 배열의 값이
  1. 큐의 front와 같을 경우 q.pop(), res-- (res는 students 배열의 크기로 초기화되어 있습니다), idx++을 수행합니다
  2. 큐의 front와 다를 경우, 현재 큐의 front를 맨 뒤로 옮겨준 다음 rep카운터를 1 증가시킵니다
    - 이때 rep 카운터의 값이 현재 큐의 크기보다 클 경우 루프를 종료합니다
루프가 끝난 뒤의 res값을 출력합니다

*/

// circular = 0, square = 1
