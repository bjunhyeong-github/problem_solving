#include <iostream>  
#include <vector>         
#include <queue>          
#include <algorithm>
#include <random>
#include <unordered_map>
#include <conio.h>

using namespace std;          // std:: 생략

class MapGenerator {
public:   //클래스 외부에서도 사용가능
    MapGenerator(int width, int height, int numObstacles, unsigned int seed) :         //멤벼변수들을 입력받은 값으로 초기화
        width_(width), height_(height), numObstacles_(numObstacles), rng_(seed) {}     //rng_는 랜덤넘버 생성기 초기화

    vector<std::vector<bool>> generate() {                                             //height*width 크기 맵 생성
        vector<std::vector<bool>> map(height_, std::vector<bool>(width_, false));     

        //장애물 개수만큼 for문을 반복하여 랜덤위치에 생성
        for (int i = 0; i < numObstacles_; i++) {
            int x = randInt(0, width_ - 1);       //0~width_ - 1 범위 안에 랜덤한 x좌표
            int y = randInt(0, height_ - 1);      //0~height_ - 1 범위 안에 랜덤한 y좌표
            map[y][x] = true;                     //좌표 결정 후 장애물 생성
        }
        return map;
    }

private:   //클래스 내부에서만 사용가능
    int width_;             //가로       
    int height_;            //세로
    int numObstacles_;      //장애물 개수
    mt19937 rng_;           // C++11부터 제공되는 난수 생성기
    
    //맵 사이즈 범위안에서 난수를 생성하는 함수 = 장애물이 맵밖으로 넘어가지 않게 하는 함수
    int randInt(int min, int max) {                       
        uniform_int_distribution<int> dist(min, max);     //"min"에서 "max" 범위 내에서 정수값을 반환
        return dist(rng_);
    }
};

struct Node {   //경로 탐색 알고리즘에서 사용되는 방문 여부 정보 등을 함께 저장가능
    int x;      //노드의 위치정보 저장
    int y;      //노드의 위치정보 저장
    int dist;   //출발점으로부터 해당 노드까지의 거리 정보를 저장
};

//BFS알고리즘을 사용한 출발점에서 도착점까지의 최단경로를 구하는 함수
int bfs(const vector<vector<bool>>& map, int startX, int startY, int endX, int endY) { 
    int height = map.size();           //맵의 크기 정보를 저장
    int width = map[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width, false)); //해당 노드를 방문했는지 여부를 저장
    vector<vector<int>> dist(height, vector<int>(width, -1));         //출발점에서 해당 노드까지의 최단 거리를 저장
    queue<Node> q;                  // 큐 객체 생성
    q.push({ startX, startY, 0 });  // 출발점과 같은 좌표를 가진 노드를 푸쉬
    visited[startY][startX] = true; //출발점을 방문시 true로 설정 == 출발점에서 시작하기때문
    dist[startY][startX] = 0;       //출발점의 거리를 0으로 설정 == 출발점에서 시작하기때문

    while (!q.empty()) {        //BFS실행
        Node curr = q.front();  //처음노드를 curr 변수에 저장
        q.pop();

        if (curr.x == endX && curr.y == endY) { 
        //만약 curr이 목적지 노드가 아니면, 현재 노드의 이웃들을 차례로 방문하여 visited와 dist를 업데이트하고, 이웃 노드를 큐에 추가
           return curr.dist;
        }

        //현재 위치에서 갈 수 있는 4방향 체크
        int dx[4] = { -1, 0, 1, 0 };  //상,하,좌,우
        int dy[4] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];
            if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && !visited[nextY][nextX] && !map[nextY][nextX]) {
                visited[nextY][nextX] = true;
                q.push({ nextX, nextY, curr.dist + 1 });
            }// 큐에 들어간 노드부터 이전 노드에서의 거리에 1을 더한 값으로 갱신하며 반복하여 목적지에 도달하는 최단 거리를 반환
        }
    }

    //도착점에 도달하지 못한 경우
    return -1;
}

int main() {
    //맵 사이즈와 장애물 설정
    int width, height, numObstacles;
    int sx, sy, ex, ey;

    char c;
    cout << "시작 하려면 아무키나 눌러주세요(ESC키를 누르면 종료됩니다....)" << endl ;
    
    while (true) {
        c = _getch();
        if (c == 27) { // ESC키를 누르면 프로그램 종료
            cout << "Esc키를 눌러 프로그램이 종료됨" << endl;
            break;
        }
    cout << "길찾기를 시작하겠습니다!" << endl;

    cout << "맵 사이즈를 입력해주세요(x y): ";
    cin >> width >> height;
    cout << "장애물 개수를 입력해주세요: ";
    cin >> numObstacles;
    cout << "출발점을 입력해주세요(x y): ";
    cin >> sx >> sy;
    cout << "도착점을 입력해주세요(x y): ";
    cin >> ex >> ey;

    cout << "맵을 생성합니다" << endl;
        // 사용자에게 입력받고 랜덤시드를 통해 맵생성
        std::random_device rd;
        MapGenerator mapGen(width, height, numObstacles, rd());

        //맵 생성
        vector<vector<bool>> map = mapGen.generate();
        int dist = bfs(map, sx, sy, ex, ey);
        //맵 출력
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (sx == j && sy == i) {
                    cout << "☆ ";      //출발점
                }
                else if (ex == j && ey == i) {
                    cout << "★ ";      //도착점
                }
                else if (map[i][j]) {
                    cout << "# ";      //장애물
                }
                else {
                    cout << "- ";     //길
                }
            }
            cout << endl;
        }
        int shortestDist = bfs(map, sx, sy, ex, ey);  //BFS함수를 호출하여 최단거리 출력
        cout << "최단 거리: " << shortestDist << endl;
        cout << "계속 사용하시겠습니까?(ESC: 종료/ 아무키나 누르면 재시작)";
    }
    return 0;
}

