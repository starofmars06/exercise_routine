#include "common.h"

// 운동한 정보, 기록한 정보 불러오기
void exercise_load() {
    char filename[20];
    FILE* fbmi;

    int loadedDate;
    int exerciseTime;
    int feedback;
    int loadedHeight, loadedWeight;
    float loadedBMI;
    char loadedExerciseName[256];

    int year, month, day, selected_date;

    printf("확인하고 싶은 날짜를 입력해주세요 (YYYY.MM.DD): ");
    scanf("%d.%d.%d", &year, &month, &day);

    selected_date = (year * 10000 + month * 100 + day);

    // 텍스트 파일 이름 지정
    sprintf(filename, "%d.txt", selected_date);

    fbmi = fopen(filename, "r");

    if (fbmi == NULL) {
        printf("해당 날짜에는 운동정보를 기록하지 않았습니다.\n");
        return;
    }
    
    // 파일 포인터를 파일의 처음으로 이동
    fseek(fbmi, 0, SEEK_SET);

    // 읽어온 데이터 출력
    fscanf(fbmi, "날짜: %d\n", &loadedDate);
    fscanf(fbmi, "신장: %d cm\n", &loadedHeight);
    fscanf(fbmi, "체중: %d kg\n", &loadedWeight);
    fscanf(fbmi, "BMI: %f\n", &loadedBMI);
    fscanf(fbmi, "%s\n", &loadedExerciseName);
    fscanf(fbmi, "운동한 시간: %d\n", &exerciseTime);
    fscanf(fbmi, "만족도: %d\n", &feedback);


    printf("\n");
    printf("기록한 날짜: %d\n\n", loadedDate);
    printf("이 날은 [%s]을(를) 하셨습니다.\n", loadedExerciseName);

    //운동 시간 출력하기
    separateDigits(exerciseTime);

    //만족도에 따라서 다른 문구 출력하기
    if (feedback == 1) {
        printf("만족스럽다고 이전에 평가하신 기록이 있습니다.\n\n");
    }
    else {
        printf("불만족스럽다고 이전에 평가하신 기록이 있습니다.\n\n");
    }

    // 파일 닫기
    fclose(fbmi);
}


//저장된 운동시간
//시간 분으로 다시 형식을 나눠주기
void separateDigits(int number) {
	if (number >= 1000) { // 네 자리 숫자인 경우
		int thousands = number / 1000;
		int hundreds = (number % 1000) / 100;
		int tens = (number % 100) / 10;
		int units = number % 10;

		printf("운동한 시간: %d%d시간 %d%d분\n", thousands, hundreds, tens, units);
	}
	else if (number >= 100) { // 세 자리 숫자인 경우
		int hundreds = number / 100;
		int tens = (number % 100) / 10;
		int units = number % 10;

		printf("운동한 시간: %d시간 %d%d분\n", hundreds, tens, units);
	}
	else if (number >= 10) { // 두 자리 숫자인 경우
		int tens = number / 10;
		int units = number % 10;

		printf("운동한 시간: %d%d분\n", tens, units);
	}
	else if(number >0 && number < 10){ // 한 자리 숫자인 경우
		printf("운동한 시간: %d분\n", number);
	}
	else {
		printf("\n");
	}
}


//이번달 누적 기록 들고오기
void exercise_monthly_record() {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int exerciseTime;
	int feedback;
	int loadedHeight, loadedWeight;
	float loadedBMI;
	char loadedExerciseName[256];

	int sum = 0, temp_time = 0;
	int thousands = 0, hundreds = 0, tens = 0, units = 0;
	int sum_thousands = 0, sum_hundreds = 0, sum_tens = 0, sum_units = 0;

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
			fscanf(fbmi, "%s\n", &loadedExerciseName);
			fscanf(fbmi, "운동한 시간: %d\n", &exerciseTime);
			fscanf(fbmi, "만족도: %d\n", &feedback);

			printf("\n");
			// loadedDate를 연도, 월, 일로 분리하여 출력
			int back_to_year = loadedDate / 10000;
			int back_to_month = (loadedDate % 10000) / 100;
			int back_to_day = loadedDate % 100;


			if (exerciseTime < 0) {
				temp_time = 0;
			}
			else {
				temp_time = exerciseTime;
			}


			printf("┃ ");
			printf("%d년 %d월 %d일", back_to_year, back_to_month, back_to_day);

			printf("\n");


			if (exerciseTime < 0) {
				printf("┃ \n");
				printf("┃ \n");
				printf("┃ ");
			}
			else if(exerciseTime < 30) {
				printf("┗");
				printf("━━━━");
				printf("┓");

				separateDigits(exerciseTime);


				printf("┏");
				printf("━━━━");
				printf("┛\n");
				printf("┃ ");


			}
			else if (exerciseTime < 100) {
				printf("┗");
				printf("━━━━━━━━");
				printf("┓");

				separateDigits(exerciseTime);

				printf("┏");
				printf("━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}
			else if (exerciseTime < 130) {
				printf("┗");
				printf("━━━━━━━━━━━━━");
				printf("┓");

				separateDigits(exerciseTime);

				printf("┏");
				printf("━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");

			}
			else if (exerciseTime < 200) {
				printf("┗");
				printf("━━━━━━━━━━━━━━━━━━");
				printf("┓");

				separateDigits(exerciseTime);


				printf("┏");
				printf("━━━━━━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}
			else if( exerciseTime >= 200){
				printf("┗");
				printf("━━━━━━━━━━━━━━━━━━━━━━━");
				printf("┓");

				separateDigits(exerciseTime);

				printf("┏");
				printf("━━━━━━━━━━━━━━━━━━━━━━━");
				printf("┛\n");
				printf("┃ ");
			}
			else {
				printf("┃ \n");
				printf("┃ \n");
				printf("┃ ");
			}

			fclose(fbmi);
			foundRecords = 1;  // 기록을 찾았음을 표시
		}
	}

	if (!foundRecords) {
		printf("선택한 날짜 이전에 기록된 정보가 없습니다.\n");
	}


}








