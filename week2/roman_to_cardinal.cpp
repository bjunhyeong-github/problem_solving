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
    
    cout << "[로마자를 입력하세요 ";
    cout << " {I=1},{V=5},{X=10},{L=50},{C=100},{D=500},{M=1000}]:  ";
    while (true) {
        c = _getch();
        if (c == 27) { // ESC키를 누르면 프로그램 종료
            break;
        }
        else if (isalpha(c)) { // 알파벳이 입력될 경우
            roman += c;
            if (c >= 'a' && c <= 'z') // 입력된 문자가 영어 소문자인 경우
            {
                cout << "오류발생 대문자를 입력하세요: " << endl;
            }
            else // 입력된 문자가 영어 소문자가 아닌 경우
            {
                cout << c;
            }
            
        }
        else if (c == '\r') { // Enter 키가 눌렸을 경우
            int num = romanToInt(roman);
            cout << "는 정수로 " << num << "입니다." << endl;
            roman = "";
            cout << "[로마자를 입력하세요]: ";
        }
        else if (c == ' ') {
            cout << "오류발생 로마자를 입력하세요: " << endl;
        }
        else if (c == '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' ) {
            cout << "오류발생 로마자를 입력하세요: " << endl;
        }
       
       
    }
    return 0;
}