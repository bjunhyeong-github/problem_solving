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
	cout << "�� �Է�: ";
	cin >> n;
	if (n > 65535) {
		cout << "���ܹ߻�.. �ٽ� �Է����ּ���";
	}
	else {
		cout << "�Է¹��� ��: " << n << endl;
		cout << "�������� ���: " << rev(n) << endl;
	}
	return 0;
}
