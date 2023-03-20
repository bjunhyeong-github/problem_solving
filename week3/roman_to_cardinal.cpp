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

    cout << "�θ��ڸ� �Է��ϼ��� ";
    cout << " {I=1},{V=5},{X=10},{L=50},{C=100},{D=500},{M=1000}]:  ";
    while (true) {
        c = _getch();
        if (c == 27) { // ESCŰ�� ������ ���α׷� ����
            cout << "EscŰ�� ���� ���α׷��� �����" << endl;
            break;
        }
        else if (isalpha(c)) { // ���ĺ��� �Էµ� ���
            roman += c;

            if (c >= 'a' && c <= 'z') // �Էµ� ���ڰ� ���� �ҹ����� ���
            {
                cout << "�ҹ��� �Է�, �빮�ڸ� �Է����ּ���!: " << endl;
            }
            else if (c != 'I' && c != 'V' && c != 'X' && c != 'L' && c != 'C' && c != 'D' && c != 'M')
            {
                cout << "�ùٸ� �θ��ڸ� �Է����ּ���: " << endl;
            }
            else // �Էµ� ���ڰ� ���� �ҹ��ڰ� �ƴ� ���
            {
                cout << c;
            }

        }
        else if (c == '\r') { // Enter Ű�� ������ ���
            int num = romanToInt(roman);
            cout << "�� ������ ��ȯ�� ���� " << num << "�Դϴ�." << endl;
            roman = "";
            cout << "�θ��ڸ� �Է��ϼ��� : ";
        }
        else if (c == ' ') {
            cout << endl << "��ȣ�Է�, �θ��ڸ� �Է��ϼ���!: ";
        }
        else if (c == '\b') {
            cout << endl << "ó�� ���� ���� ������ ������..: ";
        }
        else if (c == '1', '2', '3', '4', '5', '6', '7', '8', '9', '0') {
            cout << "�����Է�, �θ��ڸ� �Է��ϼ���!: " << endl;
        }
        // �齺���̽� Ű�� �������� ���� ���� �ٽþ��� ���ֱ�


    }
    return 0;
}
