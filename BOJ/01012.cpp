#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[52][52];
int vst[52][52];

int M, N, K;

int dy[]{0, 1, 0, -1};
int dx[]{1, 0, -1, 0};

void dfs(int y, int x){
    if(vst[y][x]) return;
    vst[y][x] = 1;

    for(int i: {0, 1, 2, 3}){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 or nx < 0 or ny > N or nx > M or !arr[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    int TC;
    cin >> TC;

    while(TC--){
        cin >> M >> N >> K; // x coor, y coor ord
        memset(arr, 0, sizeof(arr));
        memset(vst, 0, sizeof(vst));
        
        while(K--){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        int ans{};

        for(int i=0; i<N; i++){ // y coor
            for(int j=0; j<M; j++){ // x coor
                if(!arr[i][j] or vst[i][j]) continue;
                dfs(i, j);
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
