#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file;
    char path[200];
    int num_strings;
    char** strings;

    printf("읽고자 하는 파일의 경로를 입력해주세요 (예: C:\\\\Users\\\\YourUsername\\\\Desktop\\\\input.txt):\n");
    scanf("%s", path);

    file = fopen(path, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    printf("원하는 배열의 크기를 입력하세요: ");
    scanf("%d", &num_strings);

    strings = (char**)malloc(num_strings * sizeof(char*));
    for (int i = 0; i < num_strings; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        fgets(strings[i], 100, file);
        strtok(strings[i], "\n"); // 줄바꿈 문자 삭제
    }

    fclose(file);

    printf("\n출력:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("문자열 %d: %s\n", i + 1, strings[i]);
    }

    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
