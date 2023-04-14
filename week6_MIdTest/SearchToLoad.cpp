#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>

using namespace std;

class MapGenerator {
public:
    MapGenerator(int width, int height, int numObstacles, unsigned int seed) :
        width_(width), height_(height), numObstacles_(numObstacles), rng_(seed) {}

    vector<std::vector<bool>> generate() {
        vector<std::vector<bool>> map(height_, std::vector<bool>(width_, false));

        //��ֹ� ������ġ�� ����
        for (int i = 0; i < numObstacles_; i++) {
            int x = randInt(0, width_ - 1);
            int y = randInt(0, height_ - 1);
            map[y][x] = true;
        }
        return map;
    }

private:
    int width_;
    int height_;
    int numObstacles_;
    mt19937 rng_; // �������� ���̺귯��

    int randInt(int min, int max) {
        uniform_int_distribution<int> dist(min, max);
        return dist(rng_);
    }
};

struct Node {
    int x;
    int y;
    int dist;
};

int bfs(const vector<vector<bool>>& map, int startX, int startY, int endX, int endY) {
    int height = map.size();
    int width = map[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    vector<vector<int>> dist(height, vector<int>(width, -1));
    queue<Node> q;
    q.push({ startX, startY, 0 });
    visited[startY][startX] = true;
    dist[startY][startX] = 0;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.x == endX && curr.y == endY) {
           return curr.dist;
        }

        //���� ��ġ���� �� �� �ִ� 4���� üũ
        int dx[4] = { -1, 0, 1, 0 };
        int dy[4] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];
            if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && !visited[nextY][nextX] && !map[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({ nextX, nextY, curr.dist + 1 });
            }
        }
    }

    //�������� �������� ���� ���
    return -1;
}

int main() {
    //�� ������� ��ֹ� ����
    int width, height, numObstacles;
    int sx, sy, ex, ey;

    cout << "�� ������ �Է�(x y): ";
    cin >> width >> height;
    cout << "��ֹ� ���� �Է�: ";
    cin >> numObstacles;
    cout << "����� �Է�(x y): ";
    cin >> sx >> sy;
    cout << "������ �Է�(x y): ";
    cin >> ex >> ey;

    // ����ڿ��� �Է¹ް� �����õ带 ���� �ʻ���
    std::random_device rd;
    MapGenerator mapGen(width, height, numObstacles, rd());

    //�� ����
    vector<vector<bool>> map = mapGen.generate();
    int dist = bfs(map, sx, sy, ex, ey);
    //�� ���
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (sx == j && sy == i) {
                cout << "�� ";      //�����
            }
            else if (ex == j && ey == i) {
                cout << "�� ";      //������
            }
            else if (map[i][j]) {
                cout << "# ";      //��ֹ�
            }
            else {
                cout << "- ";     //��
            }
        }
        cout << endl;
    }
    int shortestDist = bfs(map, sx, sy, ex, ey);
    cout << "�ִ� �Ÿ�: " << shortestDist << endl;

    return 0;
}

