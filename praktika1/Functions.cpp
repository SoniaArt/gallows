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
    printf("  ������� ����: \n ����� ������ �������� ����� �� ������ �� ��������� ����.\n �� ��� ��� ����� 6 �������. ���� ����� ������ 6 ���, �� �� �����������.\n");
    printf("�� ������ ������� ������� ����� � ����� ��������.\n");
    printf("��� ���������� ��������� � �������� ������� R (����) � '������� �����'.\n");
    printf("���� �� ������ ��������� (������ ���������� ���� � �����), ������� N (����) � '������� �����'.\n");
}
void help(int n) {
    printf("���������� ���� � �����: %d\n", n);
}
void play() {
    char towns[5][MaxM] = { "������", "�����������", "������", "����", "��������" };
    char animals[5][MaxM] = { "������", "����", "�����", "������", "������" };
    char plants[5][MaxM] = { "�����", "����", "����������", "�����", "��������" };
    char countries[5][MaxM] = { "���������", "�����", "����������", "������", "�������" };
    char word[20]; //�����, � ������� ��������
    char word_guess[20]; //����� ��� ����������
    int theme, tries = 0, MaxTries = 6, num_word, word_len, found = 0;
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
    int count = 0;
    char povt[32] = { 0 };
    char letter;//�����
    while (tries < MaxTries && (found == 0)) {
        int correct = 0;
        int cnt_gallows[6] = { 0 };
        printf("�� ������������ �����: ");
        for (int i = 0; i < 32; i++) {
            if (povt[i] != 0) { printf("%c ", povt[i]); }
        }
        printf("\n���������� �����: %s\n", word_guess);
        printf("������� �����: ");
        getchar();
        scanf_s("%c", &letter);
        if (letter >= '�' && letter <= '�') { letter -= 32; }
        for (int i = 0; i < count + 1; i++)
        {
            if (letter == povt[i])
            {
                printf("����� ����� ��� ���������!\n");
                printf("������� �����: ");
                getchar();
                scanf_s("%c", &letter);
                if (letter >= '�' && letter <= '�') { letter -= 32; }
                i = -1;
            }
        }
        while ((letter >= ' ' && letter <= '@') || (letter >= '[' && letter >= '`') || (letter >= '{' && letter >= '~'))
        {
            printf("����������� ����� �������� �����.\n");
            printf("������� �����: ");
            getchar();
            scanf_s("%c", &letter);
        }
        
        while ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'M') || (letter >= 'O' && letter <= 'Q') || (letter >= 'S' && letter <= 'Z'))
        {
            printf("����������� ����� �������� �����.\n");
            printf("������� �����: ");
            getchar();
            scanf_s("%c", &letter);
        }
        if (letter == 'R') { Rules(); }
        else if (letter == 'N') { help(word_len); }
        else
        {
            if (letter >= '�' && letter <= '�') { letter -= 32; }
            povt[count] = letter;
            count++;
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
        }
    }
    if (found == 1)
        if (found == 1) {
            printf("�� �������� �����! %s\n", word);
        }
        else {
            printf("�� ���������. ���������� ����� ����: %s\n", word);
        }
}