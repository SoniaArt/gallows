#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <ctype.h> //для toupper
#include <Windows.h>
#define MaxM 25
void gallows(int tries) {
	switch (tries) {
	case 0: 
		printf("  _____\n");
		printf(" |     |\n |\n |\n |\n");
		printf("----------\n");
		printf("\n");
		break;
	case 1: 
		printf("  _____\n");
		printf(" |     |\n |     O\n |\n |\n");
		printf("----------\n");
		printf("\n");
		break;
	case 2: 
		printf("  _____\n");
		printf(" |     |\n |     O\n |     |\n |\n");
		printf("----------\n");
		printf("\n");
		break;
	case 3: 
		printf("  _____\n");
		printf(" |     |\n |     O\n |    /|\n |\n");
		printf("----------\n");
		printf("\n");
		break;
	case 4: 
		printf("  _____\n");
		printf(" |     |\n |     O\n |    /|\\\n |\n");
		printf("----------\n");
		printf("\n");
		break;
	case 5: 
		printf("  _____\n");
		printf(" |     |\n |     O\n |    /|\\\n |    /\n");
		printf("----------\n");
		printf("\n");
		break;
	case 6:
		printf("  _____\n");
		printf(" |     |\n |     O\n |    /|\\\n |    / \\\n");
		printf("----------\n");
		break;
}

}
void Rules() {
	printf("  Правила игры: \n Игрок должен отдагать слово по буквам на выбранную тему.\n На это ему даётся 6 попыток. Если игрок ошибся 6 раз, то он проигрывает.\n");
	printf("Вы можете вводить русские буквы в любом регистре.\n");
	printf("Для повторного обращения к правилам введите R (англ) в 'Введите букву'.\n");
	printf("Если вы хотите подсказку (узнать количество букв в слове), введите N (англ) в 'Введите букву'.\n");
}
void help(int n) {
	printf("Количество букв в слове: %d\n", n);
}
void play() {
	char towns[5][MaxM] = { "МОСКВА", "ВЛАДИВОСТОК", "КАЗАНЬ", "ОМСК", "СМОЛЕНСК" };
	char animals[5][MaxM] = { "СОБАКА", "МЫШЬ", "КОШКА", "КУРИЦА", "ЛОШАДЬ" };
	char plants[5][MaxM] = { "ЛИЛИИ", "РОЗЫ", "ХРИЗАНТЕМЫ", "ПИОНЫ", "ТЮЛЬПАНЫ" };
	char countries[5][MaxM] = { "АРГЕНТИНА", "ГАИТИ", "МАДАГАСКАР", "ТУРЦИЯ", "РУМЫНИЯ" };
	char word[20]; //слово, с которым работаем
	char word_guess[20]; //маска для угадывания
	int theme, tries = 0, MaxTries = 6, num_word, word_len, found = 0;
	do {
		printf("Выберите тему: \n1.Города \n2.Животные \n3.Растения \n4.Страны\n");
		printf("Ваш выбор: "); scanf_s("%d", &theme);
		if ((theme < 1) || (theme > 5)) { printf("Некоректно выбрана котегория. Повторите попытку.\n"); }
	} while ((theme < 1) || (theme > 5));
	switch (theme) {
	case 1:
		num_word = rand() % 4;
		strcpy_s(word, towns[num_word]);
		break;
	case 2:
		num_word = rand() % 4;
		strcpy_s(word, animals[num_word]);
		break;
	case 3:
		num_word = rand() % 4;
		strcpy_s(word, plants[num_word]);
		break;
	case 4:
		num_word = rand() % 4;
		strcpy_s(word, countries[num_word]);
		break;
	}
	word_len = strlen(word);
	for (int i = 0; i < word_len; i++) {
		word_guess[i] = '_';
	}
	word_guess[word_len] = '\0';
	gallows(0);
	while (tries < MaxTries && (found == 0)) {
		char letter;//буква
		int correct = 0;
		int cnt_gallows[6] = { 0 };
		printf("\nОтгаданное слово: %s\n", word_guess);
		do {
			getchar();
			printf("Введите букву: ");
			scanf_s("%c", &letter);
			if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) { printf("Используйте буквы русского языка.\n"); }
		} while ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'));
		if (letter >= 'а' && letter <= 'я') { letter -= 32; }
		if (letter == 'R') { Rules(); }
		if (letter == 'N') { help(word_len); }
		else {
			if (letter >= 'а' && letter <= 'я') { letter -= 32; }
			for (int i = 0; i < word_len; i++) {
				if (word[i] == letter) {
					word_guess[i] = letter;
					correct = 1;
				}
			}
			if (correct == 0) {
				printf("Неверно. Осталось попыток: %d\n", MaxTries - tries - 1);
				tries++;
				if (cnt_gallows[tries] == 0) { gallows(tries); cnt_gallows[tries] += 1; }
			}
			if (strcmp(word, word_guess) == 0) {
				found = 1;
			}
			
			
		}
	}
	if (found == 1) {
		printf("Вы отгадали слово! %s\n", word);
	}
	else {
		gallows(6);
		printf("Вы проиграли. Загаданное слово было: %s\n", word);
	}
}
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