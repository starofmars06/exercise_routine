#include "common.h"

//2. 신체 정보 입력 및 bmi 측정
void bmi_calculation(char* name) {
	int height, weight;
	float fatness;      //비만도

	//신체 정보 입력(키, 몸무게)
	printf("\n*******************\n\n");            //구분선
	printf("반갑습니다, %s님!\n", name);            //환영문구
	printf("신체 정보를 입력해주세요.\n\n");

	printf("키는 얼마입니까?(cm) : ");
	scanf("%d", &height);

	printf("몸무게는 얼마입니까?(kg) : ");
	scanf("%d", &weight);

	//----------------------------------------------------------------------------
	// --> 비만도 계산

	//카우프 지수에 따르면 "비만도" = 체중(kg) / (신장(m) * 신장(m))
	fatness = (float)weight / ((float)height * 0.01 * (float)height * 0.01);   //미터값을 기준으로 하기 때문에 키에 각각 0.01을 곱해줌.

	//18.5 이하 저체중, 18.5~23.0 정상, 23.0~25.0 과체중, 25.0~30.0 비만, 30.0 이상 비만
	if (fatness < 18.5) {
		printf(ANSI_COLOR_YELLOW ".........□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".........□□□□\n");
		printf("........□□□□□□□\n");
		printf("......□□□□□□□□□□\n");
		printf("....□□□□□□□□□□□□□□\n");
		printf("...□□   □□□□□□   □□\n");
		printf("..□□    □□□□□□    □□\n");
		printf("........□□□□□□\n");
		printf("........□□  □□\n");
		printf("........□□  □□\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf(".........<저체중입니다.건강에 유의해주세요.>\n");

		printf("\n체중 증량을 위해 [근육 증량] 운동을 권장합니다.\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 23.0) {
		printf(ANSI_COLOR_GREEN ".........□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".........□□□□\n");
		printf("........□□□□□□□\n");
		printf("......□□□□□□□□□□\n");
		printf("....□□□□□□□□□□□□□□\n");
		printf("...□□   □□□□□□   □□\n");
		printf("..□□    □□□□□□    □□\n");
		printf("........■■■■■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");

		printf(".........<정상체중입니다>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 25.0) {
		printf(ANSI_COLOR_BLUE ".........□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".........□□□□\n");
		printf("........□□□□□□□\n");
		printf("......■■■■■■■■■■\n");
		printf("....■■■■■■■■■■■■■■\n");
		printf("...■■   ■■■■■■   ■■\n");
		printf("..■■    ■■■■■■    ■■\n");
		printf("........■■■■■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");

		printf(".........<과체중입니다. 건강에 유의해주세요.>\n");

		printf("\n체중 감량을 위해 [체지방 감소] 운동을 권장합니다.\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 30.0) {
		printf(ANSI_COLOR_MAGENTA ".........□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".......□□□□□□□□\n");
		printf(".........■■■■\n");
		printf("........■■■■■■■\n");
		printf("......■■■■■■■■■■\n");
		printf("....■■■■■■■■■■■■■■\n");
		printf("...■■   ■■■■■■   ■■\n");
		printf("..■■    ■■■■■■    ■■\n");
		printf("........■■■■■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");

		printf(".........<비만입니다. 건강에 유의해주세요.>\n");

		printf("\n체중 감량을 위해 [체지방 감소] 운동을 권장합니다.\n" ANSI_COLOR_RESET);
	}
	else {
		printf(ANSI_COLOR_RED ".........■■■■\n");
		printf(".......■■■■■■■■\n");
		printf(".......■■■■■■■■\n");
		printf(".........■■■■\n");
		printf("........■■■■■■■\n");
		printf("......■■■■■■■■■■\n");
		printf("....■■■■■■■■■■■■■■\n");
		printf("...■■   ■■■■■■   ■■\n");
		printf("..■■    ■■■■■■    ■■\n");
		printf("........■■■■■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");
		printf("........■■  ■■\n");

		printf(".........<고도비만입니다. 건강에 유의해주세요.>\n");

		printf("\n체중 감량을 위해 [체지방 감소] 운동을 권장합니다.\n" ANSI_COLOR_RESET);
	}


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//신체 정보 기록하기

	//오늘 날짜 기록하기
	date = date_to_file_name();

	//오늘 날짜, 키, 몸무게, bmi 저장하기.
	bmi_save(date, height, weight, fatness);
}

// bmi 신체 정보 기록을 위해서
// 텍스트 파일 제목을 날짜로 저장하고자 함.
void bmi_save(int date, int height, int weight, float bmi) {
	char filename[20];
	FILE* fbmi;

	//텍스트 파일 이름 지정
	sprintf(filename, "%d", date);
	strcat(filename, ".txt");

	fbmi = fopen(filename, "w");

	//텍스트 파일에 bmi 정보 저장
	fprintf(fbmi, "날짜: %d\n", date);
	fprintf(fbmi, "신장: %d cm\n", height);
	fprintf(fbmi, "체중: %d kg\n", weight);
	fprintf(fbmi, "BMI: %.2f\n", bmi);

	// 파일 닫기
	fclose(fbmi);

	printf("BMI 정보가 성공적으로 저장되었습니다.\n");
}


// 파일 이름으로 쓸 수 있도록, 날짜 정보 변환하기
int date_to_file_name()
{
	int year, month, day;
	struct tm* t;
	time_t timer;

	timer = time(NULL);
	t = localtime(&timer);

	year = t->tm_year + 1900;
	month = t->tm_mon + 1;
	day = t->tm_mday;

	return (year * 10000 + month * 100 + day);
}

// 이미 오늘 기록된 파일이 있는지 확인하는 함수
int hasRecordedToday(char* name) {
	char filename[20];
	FILE* fbmi;

	int today;

	today = date_to_file_name();

	sprintf(filename, "%d.txt", today);

	// 파일 열기 시도
	fbmi = fopen(filename, "r");

	if (fbmi == NULL) {
		// 파일이 존재하지 않으면 기록이 되어있지 않은 것
		bmi_calculation(name);

		return 0;
	}
	else {
		// 파일이 존재하면 이미 기록된 것
		fclose(fbmi);

		printf("\n\n오늘은 이미 신체 기록을 했습니다.\n");

		return 1;
	}
}