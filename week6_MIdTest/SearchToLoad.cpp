#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <conio.h>
#include <random> // 랜덤 함수 사용을 위한 헤더 파일

using namespace std;

const int WALL = 1; // 벽
const int EMPTY = 0; // 빈 칸

// n x m 크기의 랜덤 맵 생성
vector<vector<int>> generateRandomMap(int n, int m) {
    vector<vector<int>> map(n, vector<int>(m, EMPTY)); // 빈 맵 생성

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, n * m - 1); // 0부터 n*m-1까지의 정수를 랜덤하게 생성하는 분포

    int wall_count = n * m / 3; // 벽의 개수
    for (int i = 0; i < wall_count; i++) {
        int x = dis(gen) % n;
        int y = dis(gen) % m;
        map[x][y] = WALL;
    }

    return map;
}

// (sx, sy)에서 (ex, ey)로 가는 최단 거리를 구하는 BFS 함수
int bfs(vector<vector<int>>& map, int sx, int sy, int ex, int ey) {
    int n = map.size();
    int m = map[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    visited[sx][sy] = true;
    q.push({ sx, sy });
    int dist = 0;

    while (!q.empty()) {
        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == ex && y == ey) {
                return dist;
            }

            // 상하좌우 이동
            int dx[] = { -1, 0, 1, 0 };
            int dy[] = { 0, 1, 0, -1 };

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }

                if (map[nx][ny] == WALL || visited[nx][ny]) {
                    continue;
                }

                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }

        dist++;
    }

    return -1; // 도착점에 도달할 수 없는 경우
}



int main() {
    
    int n, m;
    char c;

    cout << "시작하려면 아무키나 눌러주세요(ESC를 누르면 종료됩니다..)" << endl;
    while (true) {    
        c = _getch();     //프로그램 종료

        if (c == 27) {
            cout << "Esc키를 눌러 프로그램이 종료됨" << endl;
            break;
        }
        else {
            // 맵 크기 입력
            cout << "길찾기 기능을 시작합니다" << endl;
            cout << "맵의 크기를 입력하세요 (n m): ";
            cin >> n >> m;

            // 맵 생성
            vector<vector<int>> map = generateRandomMap(n, m);
            cout << "맵 생성완료 1:벽, 0:길" << endl;

            // 맵 출력
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }

            // 출발점 입력
            int sx, sy;
            cout << "출발점을 입력하세요 (x y / 0 0 ~ n-1 n-1까지): ";
            cin >> sx >> sy;

            // 도착점 입력
            int ex, ey;
            cout << "도착점을 입력하세요 (x y / 0 0 ~ n-1 n-1까지): ";
            cin >> ex >> ey;

            // 최단거리 구하기
            int shortest_distance = bfs(map, sx, sy, ex, ey);

            // 결과 출력
            if (shortest_distance == -1) {
                cout << "벽에 걸림, 도착점에 도달할 수 없습니다." << endl;
            }
            else {
                cout << "최단거리: " << shortest_distance << endl;
            }
        }
    }
    return 0;
}