#include <iostream>
#include <queue>
#include <cstdlib>
#include <windows.h>

using namespace std;

const int ROW = 10;
const int COL = 20;

int maze[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void moveCursor(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                cout << "#";
            }
            else if (maze[i][j] == 1) {
                cout << " ";
            }
            else if (maze[i][j] == 2) {
                cout << "*";
            }
        }
        cout << endl;
    }
}

struct Node {
    int row;
    int col;
    int dist;
    Node(int r, int c, int d) : row(r), col(c), dist(d) {}
};

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze[row][col] == 1);
}

void bfs(int startRow, int startCol, int endRow, int endCol) {
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    queue<Node> q;

    visited[startRow][startCol] = true;
    q.push(Node(startRow, startCol, 0));

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.row == endRow && curr.col == endCol) {
            int dist = curr.dist;
            while (!q.empty()) q.pop();
            moveCursor(0, ROW + 1);
            cout << "Distance: " << dist << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = curr.row + dx[i];
            int nextCol = curr.col + dy[i];

            if (isValid(nextRow, nextCol) && !visited[nextRow][nextCol]) {
                visited[nextRow][nextCol] = true;
                q.push(Node(nextRow, nextCol, curr.dist + 1));
                maze[nextRow][nextCol] = 2; // mark visited node with *
            }
        }

        // draw current state of maze
        moveCursor(0, 0);
        drawMaze();
        Sleep(50); // delay to show each step of BFS algorithm
    }
    moveCursor(0, ROW + 1);
    cout << "No path found" << endl;
}

int main() {
    int startRow = 1;
    int startCol = 1;
    int endRow = 8;
    int endCol = 18;

    bfs(startRow, startCol, endRow, endCol);

    return 0;
}

