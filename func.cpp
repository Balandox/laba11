#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include <string.h>

char* get_string(int* len) {
    *len = 0; 
    int capacity = 1; 
    char* s = (char*)malloc(sizeof(char)); 
    char c = getchar(); 
    while (c != '\n') {
        s[(*len)++] = c; 
        if (*len >= capacity) {
            capacity *= 2;
            s = (char*)realloc(s, capacity * sizeof(char));
        }
        c = getchar();      
    }
    s[*len] = '\0'; 
    return s;
}

int word_len(char* arr, int* i) {
    int k = *i;
    int len = 0;
    while ((arr[k] >= 'A' && arr[k] <= 'Z') || (arr[k] >= 'a' && arr[k] <= 'z')) {
        len++;
        k++;
    }
    return len;
}

int letter_chk(char* arr, int* i) {
    if ((arr[*i] >= 'A' && arr[*i] <= 'Z') || (arr[*i] >= 'a' && arr[*i] <= 'z'))
        return 1;
    else
        return 0;
}

void argssplit(char* args, int* argc, char** argv[]) {
    int idx = 0, len = 0, start_w = 0;
    int index_wrd = 0, j = 0, capacity = 1;
    char* word = NULL;
    char** word_ptr = (char**)malloc(sizeof(char*));
    while (args[idx - 1] != '\0') {
        if (letter_chk(args, &idx) == 1) {
            len = word_len(args, &idx);                 // имеем длину слова и его начальный индекс и индекс следующего символа после слова
            start_w = idx;
            word = (char*)malloc((len + 1) * sizeof(char));
            for (int i = start_w; i < start_w + len; i++) {
                word[j] = args[i];
                j++;
            }
            word[j] = '\0';
            j = 0;
            *argc += 1;
            if (*argc == capacity) {
                capacity *= 2;
                word_ptr = (char**)realloc(word_ptr, sizeof(char*) * capacity);
                if (word_ptr == NULL) {
                    printf("Memory allocation error!");
                    exit(1);
                }
            }
            word_ptr[*argc - 1] = word;
            idx = start_w + len;
        }
        idx++;
    }
    *argv = word_ptr;
    }
