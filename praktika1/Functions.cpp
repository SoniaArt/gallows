#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <Windows.h>
#include "Header.h"
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
	printf("  ������� ����: \n ����� ������ �������� ���������� ����� �� ������ �� ��������� ����.\n �� ��� ��� ����� 6 �������. ���� ����� ������ 6 ���, �� �� �����������.\n");
	printf("�� ������ ������� ���������� ����� � ����� ��������.\n");
	printf("��� ���������� ��������� � �������� ������� � (���) � '������� �����'.\n");
	printf("���� �� ������ ��������� (������ ���������� ���� � �����), ������� � (���) � '������� �����'.\n");
}
void help(int n) {
	printf("���������� ���� � �����: %d\n", n);
}
void play() {
	char towns[5][MaxM] = { "MOSCOW", "VLADIVOSTOK", "KAZAN", "OMSK", "SMOLENSK" };
	char animals[5][MaxM] = { "DOG", "MOUSE", "CAT", "CHICKEN", "HORSE" };
	char plants[5][MaxM] = { "LILIES", "ROSE", "CHRYSANTHEMUMS", "PIONS", "TULIPS" };
	char countries[5][MaxM] = { "ARGENTINA", "HAITI", "MADAGASCAR", "TURKEY", "ROMANIA" };
	char word[20]; //�����, � ������� ��������
	char word_guess[20]; //����� ��� ����������
	int theme, tries = 0, MaxTries = 6, num_word, word_len, found = 0;
	char input[MaxM] = { 0 };
	int ind = 0;
	do {
		printf("�������� ����: \n1.������ \n2.�������� \n3.�������� \n4.������\n");
		printf("��� �����: "); scanf_s("%d", &theme);
		if ((theme < 1) || (theme > 5)) { printf("���������� ������� ���������. ��������� �������.\n"); }
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
		char letter;//�����
		int correct = 0;
		int cnt_gallows[6] = { 0 };
		printf("�� ������������ �����: ");
		for (int i = 0; i < MaxM; i++) {
			if (input[i] != 0) { printf("%c", input[i]); }
		}
		printf("\n���������� �����: %s\n", word_guess);
		do {
			getchar();
			printf("������� �����: ");
			scanf_s("%c", &letter);
			if (letter >= 'a' && letter <= 'z') { letter -= 32; }
			if (strchr(input, letter) != 0) { printf("�� ��� ������������ ����� �����.\n"); }
		} while (((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) && (strchr(input, letter) != 0));
		if (letter >= 'a' && letter <= 'z') { letter -= 32; }
		if (letter == '�') { Rules(); }
		else if (letter == '�') { help(word_len); }
		else {
			input[ind] = letter;
			for (int i = 0; i < word_len; i++) {
				if (word[i] == letter) {
					word_guess[i] = letter;
					correct = 1;
				}
			}
			if (correct == 0) {
				printf("�������. �������� �������: %d\n", MaxTries - tries - 1);
				tries++;
				if (cnt_gallows[tries] == 0) { gallows(tries); cnt_gallows[tries] += 1; }
			}
			if (strcmp(word, word_guess) == 0) {
				found = 1;
			}
			ind++;
		}
	}
	if (found == 1) {
		printf("�� �������� �����! %s\n", word);
	}
	else {
		gallows(6);
		printf("�� ���������. ���������� ����� ����: %s\n", word);
	}
}