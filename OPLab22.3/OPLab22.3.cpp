#include <stdio.h>
#include <Windows.h>

int main() {
    int grade;

    printf("Введіть ціле число від 2 до 5: ");
    scanf_s("%d", &grade);

    switch (grade) {
    case 2:
        printf("Незадовільно\n");
        break;
    case 3:
        printf("Задовільно\n");
        break;
    case 4:
        printf("Добре\n");
        break;
    case 5:
        printf("Відмінно\n");
        break;
    default:
        printf("Відсутність такої оцінки\n");
    }

    return 0;
}