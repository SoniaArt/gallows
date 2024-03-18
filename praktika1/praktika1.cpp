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
	int t;
	do {
		printf("Если вы хотите начать игру, введите 1. Если вы хотите выйти, введите 0: "); scanf_s("%d", &t);
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