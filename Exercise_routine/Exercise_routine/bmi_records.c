#include "common.h"

// bmi 정보, 기록한 정보 불러오기
void bmi_load() {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int loadedHeight, loadedWeight;
	float loadedBMI;

	int fatness;
	int year, month, day, selected_date;

	printf("확인하고 싶은 날짜를 입력해주세요 (YYYY.MM.DD): ");
	scanf("%d.%d.%d", &year, &month, &day);

	selected_date = (year * 10000 + month * 100 + day);

	// 텍스트 파일 이름 지정
	sprintf(filename, "%d.txt", selected_date);

	fbmi = fopen(filename, "r");

	if (fbmi == NULL) {
		printf("해당 날짜에는 신체정보를 기록하지 않았습니다.\n");
		return;
	}


	// 읽어온 데이터 출력
	fscanf(fbmi, "날짜: %d\n", &loadedDate);
	fscanf(fbmi, "신장: %d cm\n", &loadedHeight);
	fscanf(fbmi, "체중: %d kg\n", &loadedWeight);
	fscanf(fbmi, "BMI: %f\n", &loadedBMI);

	printf("\n");
	printf("신장: %d cm\n", loadedHeight);
	printf("체중: %d kg\n", loadedWeight);
	printf("BMI: %.2f\n", loadedBMI);

	//bmi 결과에 대해서
	//18.5 이하 저체중, 18.5~22.9 정상, 23.0~24.9 과체중, 25 이상 비만
	fatness = loadedBMI;

	if (fatness < 18.5) {
		printf(ANSI_COLOR_YELLOW ".........<저체중>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 23.0) {
		printf(ANSI_COLOR_GREEN ".........<정상체중>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 25.0) {
		printf(ANSI_COLOR_BLUE ".........<과체중>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 30.0) {
		printf(ANSI_COLOR_MAGENTA ".........<비만>\n" ANSI_COLOR_RESET);
	}
	else {
		printf(ANSI_COLOR_RED ".........<고도비만>\n" ANSI_COLOR_RESET);
	}


	// 파일 닫기
	fclose(fbmi);
}


//이번달 누적 기록 들고오기
void bmi_monthly_record() {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int loadedHeight, loadedWeight;
	float loadedBMI;

	int fatness;
	int foundRecords = 0;  // 이전에 저장된 기록을 찾았는지 여부

	int count = 0;


	//이번달 시작 날짜 구하기
	int year, month, day, start_day;
	struct tm* t;
	time_t timer;

	timer = time(NULL);
	t = localtime(&timer);

	year = t->tm_year + 1900;
	month = t->tm_mon + 1;
	day = t->tm_mday;
	start_day = 01;

	int today = (year * 10000 + month * 100 + day);
	int this_month_start_date = (year * 10000 + month * 100 + start_day);
	//------------------------------------------
	printf("\n********** 기록된 정보 **********\n");

	for (int i = this_month_start_date; i <= today; i++) {
		// 텍스트 파일 이름 지정
		sprintf(filename, "%d.txt", i);

		fbmi = fopen(filename, "r");

		if (fbmi != NULL) {
			// 읽어온 데이터 출력
			fscanf(fbmi, "날짜: %d\n", &loadedDate);
			fscanf(fbmi, "신장: %d cm\n", &loadedHeight);
			fscanf(fbmi, "체중: %d kg\n", &loadedWeight);
			fscanf(fbmi, "BMI: %f\n", &loadedBMI);

			printf("\n");
			// loadedDate를 연도, 월, 일로 분리하여 출력
			int back_to_year = loadedDate / 10000;
			int back_to_month = (loadedDate % 10000) / 100;
			int back_to_day = loadedDate % 100;


			// bmi 결과에 대해서
			// 18.5 이하 저체중, 18.5~22.9 정상, 23.0~24.9 과체중, 25 이상 비만
			fatness = loadedBMI;

			printf("┃ ");
			printf("%d년 %d월 %d일\n", back_to_year, back_to_month, back_to_day);

			if (fatness < 18.5) {
				printf("┗");
				printf("━━━━");
				printf("┓");

				printf(ANSI_COLOR_YELLOW "%d㎏......<저체중>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("┏");
				printf("━━━━");
				printf("┛\n");
				printf("┃ ");


			}
			else if (fatness < 23.0) {
				printf("┗");
				printf("━━━━━━━━");
				printf("┓");

				printf(ANSI_COLOR_GREEN "%d㎏......<정상체중>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("┏");
				printf("━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}
			else if (fatness < 25.0) {
				printf("┗");
				printf("━━━━━━━━━━━━━");
				printf("┓");

				printf(ANSI_COLOR_BLUE "%d㎏......<과체중>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("┏");
				printf("━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");

			}
			else if (fatness < 30.0) {
				printf("┗");
				printf("━━━━━━━━━━━━━━━━━━");
				printf("┓");

				printf(ANSI_COLOR_MAGENTA "%d㎏......<비만>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);


				printf("┏");
				printf("━━━━━━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}
			else {
				printf("┗");
				printf("━━━━━━━━━━━━━━━━━━━━━━━");
				printf("┓");

				printf(ANSI_COLOR_RED "%d㎏......<고도비만>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("┏");
				printf("━━━━━━━━━━━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}

			fclose(fbmi);
			foundRecords = 1;  // 기록을 찾았음을 표시

			count++;
		}
	}

	if (!foundRecords) {
		printf("선택한 날짜 이전에 기록된 정보가 없습니다.\n");
	}

	//-----------------------------------------
	printf("\n\n이번 달에는 총 %d 번 신체기록을 하셨습니다.\n", count);


}