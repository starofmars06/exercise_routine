#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 256
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_RESET    "\x1b[0m"

char name[20];
int date;

//1. ����� �̸� �Է¹ޱ�
//username.c
char* save_load_name();

//2. �񸸵�(bmi) ���� �� ���
//bmi_calculation.c
void bmi_calculation(char* name);
void bmi_save(int date, int height, int weight, float bmi);			//bmi �� ��ü ��� �����ϴ� �Լ�
int date_to_file_name();											//�⵵��¥�� txt �������� ����� �� �ֵ��� ��ȯ�� �Լ�
int hasRecordedToday(char* name);

//3. �޴� ����
//select_menu.c
void select_menu();

//4. � ��ƾ ����
//exercise_routine.c
void daily_routine(char* name);
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[]);

//cf. �ΰ� ���
// ���� ��ü ��� Ȯ���ϱ�
//bmi_records.c
void bmi_load();											//��ü ��� txt ���� �ҷ����� �Լ�
void bmi_monthly_record();											//�̹��� ���� ���� ��� �����ֱ�

// � �� ������ ��
//user_feedback.c
void user_feedback();
void feedback_save(int date, int exercise_time_record, int feedback);

//exercise_records.c
void exercise_load();
void exercise_monthly_record();
void separateDigits(int num);
void chosen_routine_save(int date, char* exercise_name);