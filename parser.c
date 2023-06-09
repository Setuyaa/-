#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "memory.h"
#define MAX_TOKEN_LENGTH 100

// Список терминальных символов
typedef enum {
    END_TOKEN, NUMBER_TOKEN, ADD_TOKEN, SUB_TOKEN, MULT_TOKEN, DIV_TOKEN, ERROR_TOKEN
} TokenType;

// Структура лексемы (token)
typedef struct {
    TokenType type;
    stack st;
} Token;

// Глобальное хранилище для текущей лексемы
Token currentToken;

// Функция для получения следующей лексемы из входного потока
Token getNextToken (FILE *fp) {
    char c;
    Token token;

    // // Очистка текущей лексемы
    // memset(token.str, '\0', MAX_TOKEN_LENGTH + 1);
    token.type = ERROR_TOKEN;

    // Чтение первого символа
    c = fgetc(fp);

    // Пропуск пробельных символов
    while (isspace(c)) {
        c = fgetc(fp);
    }

    if (isdigit(c)) {
        // Обработка цифровой константы
        token.type = NUMBER_TOKEN;
        int i = 0;
        while (isdigit(c) && i < MAX_TOKEN_LENGTH) {
            push(&token.st, c);
            i++;
            c = fgetc(fp);
        }
        ungetc(c, fp);
    } else {
        // Обработка операторов
        switch (c) {
            case '+':
                token.type = ADD_TOKEN;
                break;
            case '-':
                token.type = SUB_TOKEN;
                break;
            case '*':
                token.type = MULT_TOKEN;
                break;
            case '/':
                token.type = DIV_TOKEN;
                break;
            case EOF:
                token.type = END_TOKEN;
                break;
            default:
                token.type = ERROR_TOKEN;
                break;
        }
    }

    if (token.type != ERROR_TOKEN) {
        currentToken.st = token.st;
        currentToken.type = token.type;
    }
    return token;
}

// Функция-помощник для проверки типа текущей лексемы
int checkToken(TokenType type) {
    return currentToken.type == type;
}

// Функция для обработки операндов
int expression();

// Функция для обработки умножения и деления
int term(FILE *fp) {
    int result =  1; //expression(fp);
    while (checkToken(MULT_TOKEN) || checkToken(DIV_TOKEN)) {
        Token op = getNextToken(fp);
        int factor = expression(fp);
        if (op.type == MULT_TOKEN) {
            result *= factor;
        } else {
            result /= factor;
        }
    }
    return result;
}

// Функция для обработки сложения и вычитания
int expression( FILE *fp) {
    int result = 0; // term(fp);
    while (checkToken(ADD_TOKEN) || checkToken(SUB_TOKEN)) {
        Token op = getNextToken(fp);
        int termVal = term(fp);
        if (op.type == ADD_TOKEN) {
            result += termVal;
        } else {
            result -= termVal;
        }
    }
    return result;
}

// Точка входа в программу
int main() {
    int result;
    FILE *fp;
    currentToken.st = create_stack(MAX_TOKEN_LENGTH + 1);
    char name[] = "my.txt";
     if ((fp = fopen(name, "r")) == NULL)
  {
    printf("Не удалось открыть файл");
    getchar();
    return 0;
  }
    // Получение первой лексемы
    currentToken = getNextToken(fp);
    // Вычисление выражения
    result = expression(fp);
    if (currentToken.type != END_TOKEN) {
        printf("Ошибка: неверная лексема в конце выражения: %c\n", pop(&currentToken.st));
        return 1;
    }
    printf("Результат: %d\n", result);
    fclose(fp);
    getchar();
    return 0;
}