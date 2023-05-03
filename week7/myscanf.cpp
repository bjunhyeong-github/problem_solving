#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

int my_scanf(const char* str, void* a, void* b, void* c, void* d) {
    char input_str[1024]; // 입력 문자열을 저장할 임시 배열
    char* token; // 문자열 파싱을 위한 포인터
    int dex = 0; // 지정된 자료형을 저장하기 위한 인덱스 변수

    // 입력 문자열 받기
    gets_s(input_str, sizeof(input_str));

    // 문자열 파싱을 통해 지정된 자료형의 변수에 값을 할당하기
    token = strtok(input_str, " "); // 공백 문자로 문자열을 분리
    while (token != NULL && dex < 4) {
        switch (dex) {
        case 0:
            *((int*)a) = atoi(token);
            break;
        case 1:
            *((char*)b) = *token;
            break;
        case 2:
            *((float*)c) = atof(token);
            break;
        case 3:
            strcpy((char*)d, token);
            break;
        }
        dex++;
        token = strtok(NULL, " "); // 다음 토큰 얻기
    }

    // 값 할당에 실패한 경우 -1 반환
    if (dex < 4) {
        return -1;
    }

    // 값 할당에 성공한 경우 0 반환
    return 0;
}

int main() {
    int a;
    char b;
    float c;
    char d[1024];

    // 사용자 입력 받기
    printf("값을 입력하세요 ex) 1 a 1.1 abc : ");
    if (my_scanf("%d %c %.0f %s", &a, &b, &c, &d) == -1) {
        printf("에러입니다. 다시 입력해주세요\n");
        return -1;
    }

    // 입력 받은 값을 출력하기
    printf("입력값: %d %c %f %s\n", a, b, c, d);

    return 0;
}