#include <stdio.h>
#include <string.h>
#include <Windows.h>

void addQuestionMarkBeforeWord(char* sentence) {
    char* word = strtok_s(sentence, " ", &sentence);
    while (word != 0) {
        printf("?%s ", word);
        word = strtok_s(0, " ", &sentence);
    }
}

int main() {
    char sentence[100];
    printf("Введіть рядок символів: ");
    fgets(sentence, 100, stdin);
    addQuestionMarkBeforeWord(sentence);
    return 0;
}