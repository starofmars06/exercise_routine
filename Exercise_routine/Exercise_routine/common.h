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

//1. 사용자 이름 입력받기
//username.c
char* save_load_name();

//2. 비만도(bmi) 측정 및 출력
//bmi_calculation.c
void bmi_calculation(char* name);
void bmi_save(int date, int height, int weight, float bmi);			//bmi 및 신체 기록 저장하는 함수
int date_to_file_name();											//년도날짜를 txt 제목으로 사용할 수 있도록 변환한 함수
int hasRecordedToday(char* name);

//3. 메뉴 선택
//select_menu.c
void select_menu();

//4. 운동 루틴 선택
//exercise_routine.c
void daily_routine(char* name);
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[]);

//cf. 부가 기능
// 누적 신체 기록 확인하기
//bmi_records.c
void bmi_load();											//신체 기록 txt 파일 불러오는 함수
void bmi_monthly_record();											//이번달 기준 누적 기록 보여주기

// 운동 후 만족도 평가
//user_feedback.c
void user_feedback();
void feedback_save(int date, int exercise_time_record, int feedback);

//exercise_records.c
void exercise_load();
void exercise_monthly_record();
void separateDigits(int num);
void chosen_routine_save(int date, char* exercise_name);