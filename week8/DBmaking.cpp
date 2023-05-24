#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file;
    file = fopen("DBText.txt", "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    int intCount = 0, charCount = 0, stringCount = 0;

    int* i = NULL;
    char* c = NULL;
    char** s = NULL;

    char line[1024];

    while (fgets(line, sizeof(line), file)) {
        for (int j = 0; j < strlen(line); j++) {
            if (line[j] == '%') {
                j++;
                if (line[j] == 'd') {
                    intCount++;
                    i = (int*)realloc(i, sizeof(int) * intCount);
                }
                else if (line[j] == 'c') {
                    charCount++;
                    c = (char*)realloc(c, sizeof(char) * charCount);
                }
                else if (line[j] == 's') {
                    stringCount++;
                    s = (char**)realloc(s, sizeof(char*) * stringCount);
                    s[stringCount - 1] = (char*)malloc(sizeof(char) * 100);
                }
            }
        }
    }

    // ������ �� ����
    i[0] = 98;
    c[0] = 'A';
    strcpy(s[0], "���� ��������");

    printf("int(%d��): %d\n", intCount, i[0]);
    printf("char(%d��): %c\n", charCount, c[0]);
    printf("string(%d��): %s\n", stringCount, s[0]);

    fclose(file);

    printf("�� �̸��� %s�̰� �̹��б� ������ %d���̰� ������ %c�� �޾ҽ��ϴ�.\n", s[0], i[0], c[0]);

    free(i);
    free(c);
    for (int j = 0; j < stringCount; j++) {
        free(s[j]);
    }
    free(s);

    return 0;
}

