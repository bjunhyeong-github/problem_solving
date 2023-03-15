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
    
    cout << "[�θ��ڸ� �Է��ϼ��� ";
    cout << " {I=1},{V=5},{X=10},{L=50},{C=100},{D=500},{M=1000}]:  ";
    while (true) {
        c = _getch();
        if (c == 27) { // ESCŰ�� ������ ���α׷� ����
            break;
        }
        else if (isalpha(c)) { // ���ĺ��� �Էµ� ���
            roman += c;
            if (c >= 'a' && c <= 'z') // �Էµ� ���ڰ� ���� �ҹ����� ���
            {
                cout << "�����߻� �빮�ڸ� �Է��ϼ���: " << endl;
            }
            else // �Էµ� ���ڰ� ���� �ҹ��ڰ� �ƴ� ���
            {
                cout << c;
            }
            
        }
        else if (c == '\r') { // Enter Ű�� ������ ���
            int num = romanToInt(roman);
            cout << "�� ������ " << num << "�Դϴ�." << endl;
            roman = "";
            cout << "[�θ��ڸ� �Է��ϼ���]: ";
        }
        else if (c == ' ') {
            cout << "�����߻� �θ��ڸ� �Է��ϼ���: " << endl;
        }
        else if (c == '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' ) {
            cout << "�����߻� �θ��ڸ� �Է��ϼ���: " << endl;
        }
       
       
    }
    return 0;
}