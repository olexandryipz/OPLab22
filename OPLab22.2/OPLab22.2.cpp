#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

int isPalindrome(const char* word) {
    int length = strlen(word);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(word[i]) != tolower(word[length - i - 1])) {
            return 0;
        }
    }
    return 1;
}

void checkPalindromes(char* inputString) {
    char* token;
    char* nextToken = 0;

    printf("Паліндроми:\n");
    token = strtok_s(inputString, " ", &nextToken);
    while (token != 0) {
        if (isPalindrome(token)) {
            printf("Слово '%s' є паліндромом.\n", token);
        }

        token = strtok_s(0, " ", &nextToken);
    }
}

void countWordOccurrences(char* inputString) {
    char* token;
    char* nextToken = 0;

    struct WordCount {
        char word[100];
        int count;
    };

    struct WordCount wordCounts[100];
    int count = 0;

    token = strtok_s(inputString, " ", &nextToken);
    while (token != 0) {
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(wordCounts[i].word, token) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy_s(wordCounts[count].word, token);
            wordCounts[count].count = 1;
            count++;
        }

        token = strtok_s(0, " ", &nextToken);
    }

    int maxCountIndex = 0;
    for (int i = 1; i < count; i++) {
        if (wordCounts[i].count > wordCounts[maxCountIndex].count) {
            maxCountIndex = i;
        }
    }

    printf("\nКількість повторень кожного слова:\n");
    for (int i = 0; i < count; i++) {
        printf("Слово '%s' повторюється %d раз.\n", wordCounts[i].word, wordCounts[i].count);
    }

    printf("\nСлово, що повторюється найбільше разів: '%s' (з повторенням %d разів)\n",
        wordCounts[maxCountIndex].word, wordCounts[maxCountIndex].count);

    char uniqueWords[1000] = "";
    for (int i = 0; i < count; i++) {
        strcat_s(uniqueWords, wordCounts[i].word);
        strcat_s(uniqueWords, " ");
    }
}

void removeDuplicateWords(char* inputString) {
    char* token;
    char* nextToken = 0;

    char uniqueWords[1000] = "";

    token = strtok_s(inputString, " ", &nextToken);
    while (token != 0) {
        if (strstr(uniqueWords, token) == 0) {
            strcat_s(uniqueWords, sizeof(uniqueWords), token);
            strcat_s(uniqueWords, sizeof(uniqueWords), " ");
        }

        token = strtok_s(0, " ", &nextToken);
    }

    strcpy_s(inputString, sizeof(uniqueWords), uniqueWords);
}

void rewriteWordLikeAlphabet(char* word) {
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (tolower(word[j]) > tolower(word[j + 1])) {
                char temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
}

int main() {
    char inputString[1000];

    printf("Введіть рядок слів: ");
    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    checkPalindromes(inputString);

    countWordOccurrences(inputString);

    removeDuplicateWords(inputString);
    printf("\nРядок після видалення повторень: %s\n", inputString);

    char* token;
    char* nextToken = 0;

    token = strtok_s(inputString, " ", &nextToken);
    while (token != 0) {
        rewriteWordLikeAlphabet(token);
        printf("Переставлене слово в алфавітному порядку: %s\n", token);

        token = strtok_s(0, " ", &nextToken);
    }

    return 0;
}
