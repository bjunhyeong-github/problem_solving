#include <iostream>
#include <stdio.h>

using namespace std;

int rev(int n) {
	int r = 0;
	while (n != 0) {
		r *= 10;
		r += n % 10;
		n /= 10;
	}
	return r;
}
int main() {
	unsigned short n;
	cout << "값 입력: ";
	cin >> n;
	if (n > 65535) {
		cout << "예외발생.. 다시 입력해주세요";
	}
	else {
		cout << "입력받은 값: " << n << endl;
		cout << "역순으로 출력: " << rev(n) << endl;
	}
	return 0;
}
