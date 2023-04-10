#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <conio.h>
#include <random> // ���� �Լ� ����� ���� ��� ����

using namespace std;

const int WALL = 1; // ��
const int EMPTY = 0; // �� ĭ

// n x m ũ���� ���� �� ����
vector<vector<int>> generateRandomMap(int n, int m) {
    vector<vector<int>> map(n, vector<int>(m, EMPTY)); // �� �� ����

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, n * m - 1); // 0���� n*m-1������ ������ �����ϰ� �����ϴ� ����

    int wall_count = n * m / 3; // ���� ����
    for (int i = 0; i < wall_count; i++) {
        int x = dis(gen) % n;
        int y = dis(gen) % m;
        map[x][y] = WALL;
    }

    return map;
}

// (sx, sy)���� (ex, ey)�� ���� �ִ� �Ÿ��� ���ϴ� BFS �Լ�
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

            // �����¿� �̵�
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

    return -1; // �������� ������ �� ���� ���
}



int main() {
    
    int n, m;
    char c;

    cout << "�����Ϸ��� �ƹ�Ű�� �����ּ���(ESC�� ������ ����˴ϴ�..)" << endl;
    while (true) {    
        c = _getch();     //���α׷� ����

        if (c == 27) {
            cout << "EscŰ�� ���� ���α׷��� �����" << endl;
            break;
        }
        else {
            // �� ũ�� �Է�
            cout << "��ã�� ����� �����մϴ�" << endl;
            cout << "���� ũ�⸦ �Է��ϼ��� (n m): ";
            cin >> n >> m;

            // �� ����
            vector<vector<int>> map = generateRandomMap(n, m);
            cout << "�� �����Ϸ� 1:��, 0:��" << endl;

            // �� ���
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << map[i][j] << " ";
                }
                cout << endl;
            }

            // ����� �Է�
            int sx, sy;
            cout << "������� �Է��ϼ��� (x y / 0 0 ~ n-1 n-1����): ";
            cin >> sx >> sy;

            // ������ �Է�
            int ex, ey;
            cout << "�������� �Է��ϼ��� (x y / 0 0 ~ n-1 n-1����): ";
            cin >> ex >> ey;

            // �ִܰŸ� ���ϱ�
            int shortest_distance = bfs(map, sx, sy, ex, ey);

            // ��� ���
            if (shortest_distance == -1) {
                cout << "���� �ɸ�, �������� ������ �� �����ϴ�." << endl;
            }
            else {
                cout << "�ִܰŸ�: " << shortest_distance << endl;
            }
        }
    }
    return 0;
}