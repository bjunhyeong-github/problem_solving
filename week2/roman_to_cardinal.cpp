#include <iostream>
#include <unordered_map>
#include <conio.h>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanMap = 
    { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    int result = 0;
    int prev = 0;
    for (char c : s) {
        int curr = romanMap[c];
        result += (curr > prev) ? (curr - 2 * prev) : curr;
        prev = curr;
    }
    return result;
}

int main() {
    string roman;
    char c;
    cout << "�θ��ڸ� �Է��ϼ���: ";
    while (true) {
        c = _getch();
        if (c == 27) { // ESCŰ�� ������ ���α׷� ����
            break;
        }
        else if (isalpha(c)) { // ���ĺ��� �Էµ� ���
            roman += c;
            cout << c;
        }
        else if (c == '\r') { // Enter Ű�� ������ ���
            int num = romanToInt(roman);
            cout << "�� ������ " << num << "�Դϴ�." << endl;
            roman = "";
            cout << "�θ��ڸ� �Է��ϼ���: ";
        }
       
    }
    return 0;
}