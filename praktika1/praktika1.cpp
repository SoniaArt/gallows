#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <Windows.h>
#define MaxM 25
#include "Header.h"
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	printf("                                                   Виселица\n");
	char t;
	do {
		printf("Если вы хотите начать игру, введите 1. Если вы хотите выйти, введите 0: "); 
		do {
			printf("Ваш выбор: "); scanf_s("%c", &t); getchar();
			if (t < 48 || t > 49) { printf("Некорректный ввод. Повторите попытку\n"); getchar(); }
		} while (t < 48 || t > 49);
		t = t - '0';
		switch (t) {
		case 1:
			Rules();
			play(); break;
		case 0: printf("Выход"); break;
		default: printf("Некорректный ввод. Повторите попытку.\n"); break;
		}
	} while (t != 0);
	return 0;
}