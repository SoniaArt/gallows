#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <ctype.h> //для toupper
#include <Windows.h>
#define MaxM 25
void Rules() {
	printf("  Правила игры: \n Игорк должен отдагать словно по буквам на выбранную тему.\n На это ему даётся 6 попыток. Если игрок ошибся 6 раз, то он проигрывает.\n");
}
int main() {
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	printf("                                                   Виселица\n");
	Rules();
	char towns[5][MaxM] = { "Москва", "Владивосток", "Казань", "Омск", "Смоленск" };
	char animals[5][MaxM] = { "Собака", "Мышь", "Кошка", "Курица", "Лошадь" };
	char plants[5][MaxM] = { "Лилии", "Розы", "Хризантемы", "Пионы", "Тюльпаны" };
	char countries[5][MaxM] = { "Аргентина", "Гаити", "Мадагаскар", "Турция", "Румыния" };
	char word[20]; //слово, с которым работаем
	char word_guess[20]; //маска для угадывания
	int theme, tries=0, MaxTries=6, num_word, word_len, found = 0;
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
	while (tries < MaxTries && (found == 0)) {
		char letter;//буква
		int correct = 0;
		printf("\nОтгаданное слово: %s\n", word_guess);
		getchar();
		printf("Введите букву: ");
		scanf_s("%c", &letter);
		for (int i = 0; i < word_len; i++) {
			if ((word[i] == letter) /*|| (word[i] == toupper(letter))*/) { //сделать, чтобы оба регистра учитывались, toupper тут не работает
				word_guess[i] = letter;
				correct = 1;
			}
		}
		if (correct == 0) {
			printf("Неверно. Осталось попыток: %d\n", MaxTries - tries - 1);
			tries++;
		}
		if (strcmp(word, word_guess) == 0) {
			found = 1;
		}
	}
		if (found == 1) {
			printf("Вы отгадали слово! %s\n", word);
		}
		else {
			printf("Вы проиграли. Загаданное слово было: %s\n", word);
		}
	return 0;
}
