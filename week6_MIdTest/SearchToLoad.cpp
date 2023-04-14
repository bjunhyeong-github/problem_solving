#include <iostream>  
#include <vector>         
#include <queue>          
#include <algorithm>
#include <random>
#include <unordered_map>
#include <conio.h>

using namespace std;          // std:: ����

class MapGenerator {
public:   //Ŭ���� �ܺο����� ��밡��
    MapGenerator(int width, int height, int numObstacles, unsigned int seed) :         //�⺭�������� �Է¹��� ������ �ʱ�ȭ
        width_(width), height_(height), numObstacles_(numObstacles), rng_(seed) {}     //rng_�� �����ѹ� ������ �ʱ�ȭ

    vector<std::vector<bool>> generate() {                                             //height*width ũ�� �� ����
        vector<std::vector<bool>> map(height_, std::vector<bool>(width_, false));     

        //��ֹ� ������ŭ for���� �ݺ��Ͽ� ������ġ�� ����
        for (int i = 0; i < numObstacles_; i++) {
            int x = randInt(0, width_ - 1);       //0~width_ - 1 ���� �ȿ� ������ x��ǥ
            int y = randInt(0, height_ - 1);      //0~height_ - 1 ���� �ȿ� ������ y��ǥ
            map[y][x] = true;                     //��ǥ ���� �� ��ֹ� ����
        }
        return map;
    }

private:   //Ŭ���� ���ο����� ��밡��
    int width_;             //����       
    int height_;            //����
    int numObstacles_;      //��ֹ� ����
    mt19937 rng_;           // C++11���� �����Ǵ� ���� ������
    
    //�� ������ �����ȿ��� ������ �����ϴ� �Լ� = ��ֹ��� �ʹ����� �Ѿ�� �ʰ� �ϴ� �Լ�
    int randInt(int min, int max) {                       
        uniform_int_distribution<int> dist(min, max);     //"min"���� "max" ���� ������ �������� ��ȯ
        return dist(rng_);
    }
};

struct Node {   //��� Ž�� �˰��򿡼� ���Ǵ� �湮 ���� ���� ���� �Բ� ���尡��
    int x;      //����� ��ġ���� ����
    int y;      //����� ��ġ���� ����
    int dist;   //��������κ��� �ش� �������� �Ÿ� ������ ����
};

//BFS�˰����� ����� ��������� ������������ �ִܰ�θ� ���ϴ� �Լ�
int bfs(const vector<vector<bool>>& map, int startX, int startY, int endX, int endY) { 
    int height = map.size();           //���� ũ�� ������ ����
    int width = map[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width, false)); //�ش� ��带 �湮�ߴ��� ���θ� ����
    vector<vector<int>> dist(height, vector<int>(width, -1));         //��������� �ش� �������� �ִ� �Ÿ��� ����
    queue<Node> q;                  // ť ��ü ����
    q.push({ startX, startY, 0 });  // ������� ���� ��ǥ�� ���� ��带 Ǫ��
    visited[startY][startX] = true; //������� �湮�� true�� ���� == ��������� �����ϱ⶧��
    dist[startY][startX] = 0;       //������� �Ÿ��� 0���� ���� == ��������� �����ϱ⶧��

    while (!q.empty()) {        //BFS����
        Node curr = q.front();  //ó����带 curr ������ ����
        q.pop();

        if (curr.x == endX && curr.y == endY) { 
        //���� curr�� ������ ��尡 �ƴϸ�, ���� ����� �̿����� ���ʷ� �湮�Ͽ� visited�� dist�� ������Ʈ�ϰ�, �̿� ��带 ť�� �߰�
           return curr.dist;
        }

        //���� ��ġ���� �� �� �ִ� 4���� üũ
        int dx[4] = { -1, 0, 1, 0 };  //��,��,��,��
        int dy[4] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];
            if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && !visited[nextY][nextX] && !map[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({ nextX, nextY, curr.dist + 1 });
            }// ť�� �� ������ ���� ��忡���� �Ÿ��� 1�� ���� ������ �����ϸ� �ݺ��Ͽ� �������� �����ϴ� �ִ� �Ÿ��� ��ȯ
        }
    }

    //�������� �������� ���� ���
    return -1;
}

int main() {
    //�� ������� ��ֹ� ����
    int width, height, numObstacles;
    int sx, sy, ex, ey;

    char c;
    cout << "���� �Ϸ��� �ƹ�Ű�� �����ּ���(ESCŰ�� ������ ����˴ϴ�....)" << endl ;
    
    while (true) {
        c = _getch();
        if (c == 27) { // ESCŰ�� ������ ���α׷� ����
            cout << "EscŰ�� ���� ���α׷��� �����" << endl;
            break;
        }
    cout << "��ã�⸦ �����ϰڽ��ϴ�!" << endl;

    cout << "�� ����� �Է����ּ���(x y): ";
    cin >> width >> height;
    cout << "��ֹ� ������ �Է����ּ���: ";
    cin >> numObstacles;
    cout << "������� �Է����ּ���(x y): ";
    cin >> sx >> sy;
    cout << "�������� �Է����ּ���(x y): ";
    cin >> ex >> ey;

    cout << "���� �����մϴ�" << endl;
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
        int shortestDist = bfs(map, sx, sy, ex, ey);  //BFS�Լ��� ȣ���Ͽ� �ִܰŸ� ���
        cout << "�ִ� �Ÿ�: " << shortestDist << endl;
        cout << "��� ����Ͻðڽ��ϱ�?(ESC: ����/ �ƹ�Ű�� ������ �����)";
    }
    return 0;
}

