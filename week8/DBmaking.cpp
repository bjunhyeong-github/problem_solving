#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* file;
    char path[200];
    int num_strings;
    char** strings;

    printf("�а��� �ϴ� ������ ��θ� �Է����ּ��� (��: C:\\\\Users\\\\YourUsername\\\\Desktop\\\\input.txt):\n");
    scanf("%s", path);

    file = fopen(path, "r");
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    printf("���ϴ� �迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &num_strings);

    strings = (char**)malloc(num_strings * sizeof(char*));
    for (int i = 0; i < num_strings; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        fgets(strings[i], 100, file);
        strtok(strings[i], "\n"); // �ٹٲ� ���� ����
    }

    fclose(file);

    printf("\n���:\n");
    for (int i = 0; i < num_strings; i++) {
        printf("���ڿ� %d: %s\n", i + 1, strings[i]);
    }

    for (int i = 0; i < num_strings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
