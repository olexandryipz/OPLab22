#include <stdio.h>
#include <Windows.h>

int main() {
    int grade;

    printf("Введіть ціле число від 2 до 5: ");
    scanf_s("%d", &grade);

    const char* grades[] = { "Відсутність такої оцінки", "Незадовільно", "Задовільно", "Добре", "Відмінно" };

    if (grade >= 2 && grade <= 5) {
        printf("%s\n", grades[grade]);
    }
    else {
        printf("%s\n", grades[0]);
    }

    return 0;
}
