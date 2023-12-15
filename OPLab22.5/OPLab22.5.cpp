#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char grades(char result[100]);

char grades(char result[100]) {

    char grades[4][100] = { "Unsatisfactorily", "Satisfactorily", "Good", "Perfectly" };

    for (int index = 0; strlen(grades[index]) > 0; index++) {
        if (strcmp(result, grades[index]) == 0) {
            return index + 2;
        }
    }
    return 0;
}

int main() {
    printf("Введіть оцінку: ");
    char result[100];scanf("%s", &result);

    if (!grades(result)) { printf("Відсутність такої оцінки"); }
    else { printf("%d", grades(result)); }
    return 0;
}