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

//*************메인 기능*************
char* save_load_name();
void bmi_calculation(char* name);
void daily_routine(char* name);
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[]);

//+++++++++++++추가 기능+++++++++++++
void select_menu();													//부가 기능 선택 메뉴

int date_to_file_name();											//년도날짜를 txt 제목으로 사용할 수 있도록 변환한 함수
void bmi_save(int date, int height, int weight, float bmi);			//bmi 및 신체 기록 저장하는 함수
void bmi_load(int date);											//신체 기록 txt 파일 불러오는 함수
void bmi_monthly_record();											//이번달 기준 누적 기록 보여주기


//--------------------------------------------------------------
int main() {
	//1. 이름 저장하고 불러오기
	save_load_name();

	//2. BMI 측정(신체 정보 입력)
	bmi_calculation(name);

	//3. 운동 종목 선택하기
	daily_routine(name);

	// 누적된 기록 확인하기(부가 기능)
	select_menu();


	return 0;
}

//-----------------------------------------------------------
//
// 메인 기능 함수
//
//-----------------------------------------------------------
//1. 이름 저장하고 불러오는 함수
char* save_load_name() {
	FILE* file;

	printf("\n*******************\n\n");

	// 1. 저장된 기록이 있는지 살펴보기
	//  파일 읽기를 사용하여 텍스트 파일 열기
	file = fopen("username.txt", "r");

	// 1-1. 저장된 이름 텍스트 파일이 없을 때, name.txt 생성하고 이름 저장하기
	if (file == NULL) {

		//처음으로 접속할 때 나오는 환영 문구
		printf("환영합니다. 운동을 시작해볼까요?\n");

		// 사용자 이름을 담을 텍스트 파일 생성
		file = fopen("username.txt", "a+");

		// 텍스트 파일에 아무것도 입력되어 있지 않거나 문제가 있다면, 종료함.
		if (file == NULL) {
			printf("파일을 열 수 없습니다.\n");
			return 1;
		}

		// 이름 입력하기
		printf("이름을 입력해주세요 : ");
		scanf("%s", name);

		//이름을 파일에 저장하기
		fprintf(file, "%s\n", name);

		//파일 닫기
		fclose(file);

		//저장한 이름 출력
		printf("\n%s", name);
		printf("님 건강한 삶을 위한 첫걸음이 시작됩니다!\n");
		printf("열심히 운동해봅시다!\n");

		// 파일 닫기
		fclose(file);

	}  //1-2. 저장된 이름 텍스트 파일이 있을 때(기록이 있을 때), 불러오기
	else {
		// 파일에서 이름 읽기
		while (fscanf(file, "%s", name) != EOF) {
			printf("%s", name);
		}
		printf("님! 다시 만나서 반갑습니다.\n");
		printf("지난번보다 더 열심히 운동해봅시다!\n");

		// 파일 닫기
		fclose(file);
	}

	return name;
}

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

//3. 운동 종목 선택
void daily_routine(char* name) {
	int choice;   // 선택값
	int choice1, choice2, choice3, choice4; // 운동 목표에 따른 운동 종류 선택값
	int c;

	char exercise_name[MAX_STRING_LENGTH]; // 운동 이름
	char descr[MAX_STRING_LENGTH];     // 운동 설명
	char time[MAX_STRING_LENGTH];      // 운동 시간
	char level[MAX_STRING_LENGTH];     // 운동 강도
	int cal;                           // 예상 소모 칼로리
	char url[MAX_STRING_LENGTH];       // 운동 영상 주소

	printf("\n*******************\n");
	printf("관심 있는 운동 목표를 선택하시면 %s님께 알맞는 운동 루틴을 추천드리겠습니다.\n", name);

	// 운동 목표 목록 출력
	printf("\n운동 목표를 선택하세요.\n");
	printf("1. 심폐지구력 향상\n2. 유연성 향상\n3. 근육량 증가\n4. 체지방 감소\n");
	printf("\n선택할 운동 목표: ");
	// 선택값 입력
	c = scanf("%d", &choice);

	// 예외 처리 - 숫자가 아닌 입력 혹은 선택지에 없는 숫자 입력 시

	if (c != 1 || choice < 1 || choice > 4) {

		// 경고문 출력 후 처음부터 다시 실행
		printf(":::올바른 값을 입력하세요:::\n");
		while ((c = getchar()) != '\n' && c != EOF);  // 잘못된 입력값 비워주기
		daily_routine(name);  // 재귀 호출 (daily_routine 함수 처음부터 다시 실행)
	}
	// 입력받은 선택값에 따라 해당 번호의 운동 출력
	switch (choice)
	{
	case 1: // 심폐 지구력 향상
		printf("\n*******************\n");
		printf("\n[심폐 지구력 향상]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1: 걷기 \n2: 등산 \n3: 줄넘기 \n4: 배드민턴 \n5: 계단 오르기 \n6: 인터벌 트레이닝 \n");
		printf("\n선택할 운동: ");
		scanf("%d", &choice1);
		// 원하는 운동 번호에 따라 운동 설명 출력
		switch (choice1)
		{
		case 1:
			strcpy(exercise_name, "걷기");
			strcpy(descr, "밖에서 걷거나, 실내에서 트레드밀을 이용해서 걸어봅시다.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "하");
			cal = 110;
			strcpy(url, "운동 효과를 높이기 위해 바르게 걷는 방법\n	   https://youtu.be/rVoB0heVow0?si=QsUqPhefBghZ_jDy");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "등산");
			strcpy(descr, "근처 산, 산림, 혹은 등산로를 찾아 등산화와 편한 옷을 입고 산을 오르세요.");
			strcpy(time, "30분 ~ 2시간 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 204;
			strcpy(url, "등산할 때 올바른 보행법\n	   https://youtu.be/NTEaUa8SSpM?si=maVK23YRfzmlr1b-");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "줄넘기");
			strcpy(descr, "줄을 가지고 양쪽 손으로 손잡이를 잡고, 발을 조금 들어올려 줄을 넘어 뛰어 넘기세요.");
			strcpy(time, "30분~1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 371;
			strcpy(url, "줄넘기 초보자를 위한 간단한 설명\n	   https://youtu.be/_yWerNDS2AQ?si=KbnH8guZX_JJ0Oa1");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "배드민턴");
			strcpy(descr, "빠른 속도로 이동하면서 라켓으로 셔틀콕을 치세요. 상대방과 게임을 한다면, 서로 셔틀콕을 라켓으로 주고 받을 수 있습니다.");
			strcpy(time, "1시간 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 246;
			strcpy(url, "배드민턴 입문자용 기초 설명\n	   https://youtu.be/giXK9YAeJEI?si=nKTfS_rM72A3MSHe");

			exercise_details(exercise_name, descr, time, level, cal, url);
		case 5:
			strcpy(exercise_name, "계단 오르기");
			strcpy(descr, "건물 내부 또는 야외의 계단을 오르내리기를 반복하세요.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "하");
			cal = 261;
			strcpy(url, "효과적으로 계단오르기 운동 하는 방법\n	   https://youtu.be/5K_-Bz9VfHw?si=QPudFsNtw9pQxmgs");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "인터벌 트레이닝");
			strcpy(descr, "5분의 워밍업 후 8~10의 속도로 3분간 달립니다. 그 후 5~6의 속도로 2분간 걷습니다. 해당 루틴을 30분동안 반복한 후 쿨 다운이 들어가 5~10분간 천천히 걷습니다. \n자신의 체력 수준에 따라 속도와 시간을 조절하여 수행합시다.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 157;
			strcpy(url, "인터벌트레이닝의 방법과 효과\n	   https://youtu.be/RKcfpPNlMvE?si=z6nWkIUmKrZNBclu");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 2: //유연성 향상
		printf("\n*******************\n");
		printf("\n[유연성 향상]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.반달 자세 \n2: 독수리 자세 \n3: 나무 자세 \n4:필라테스 \n5: 다리 찢기");
		printf("\n선택할 운동: ");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			strcpy(exercise_name, "반달 자세");
			strcpy(descr, "몸을 한 쪽으로 기울여 하나의 손을 바닥에 놓고 다른 팔을 천장 쪽으로 뻗어서 유지하다가 방향을 바꿉시다.");
			strcpy(time, "30초 ~ 1분");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			strcpy(url, "반달자세 하는 방법\n	   https://youtu.be/E93q2CDmp14?si=O0PUMTEwNRqx9RbS");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "독수리 자세");
			strcpy(descr, "오른팔을 왼팔 밑으로 해 팔꿈치를 교차하고 양 손바닥이 맞닿도록 합니다. \n오른쪽 다리를 비틀고 오른발을 왼쪽 종아리에 걸친 상태로 유지하다가 방향을 바꿉시다.");
			strcpy(time, "30초 ~ 1분");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			strcpy(url, 독수리자세 하는 방법\n	   "https://youtu.be/0yVcCuc_uGE?si=iWOupRitjG_7uKSP");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;

		case 3:
			strcpy(exercise_name, "나무 자세");
			strcpy(descr, "한 쪽 발을 반대쪽 허벅지 안쪽에 붙이고, 두 손은 머리 위로 올려 깍지를 낀 채로 서서 자세를 유지하다가 방향을 바꿉시다.");
			strcpy(time, "1분 ~ 1분 30초");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			strcpy(url, "나무자세 하는 방법\n	   https://youtu.be/TptsloulelU?si=EyVohJpO7mhmq-H2");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "필라테스");
			strcpy(descr, "필라테스 매트를 사용하여 다양한 동작을 수행하거나, 필라테스 기구를 활용합시다.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 30;
			strcpy(url, "집에서 하는 전신필라테스 20가지 동작\n	   https://youtu.be/L5QnCr_vdJE?si=miiZhZyb5_M2xbc3");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "다리 찢기");
			strcpy(descr, "다리를 앞으로 뻗고 있다가 천천히 좌우로 벌립니다.");
			strcpy(time, "30초 ~ 1분");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			strcpy(url, "다리 찢기 늘리는 방법\n	   https://youtu.be/MYdr0deU5N4?si=Ez9h_3KQExrR102M");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 3: //근육 증량
		printf("\n*******************\n");
		printf("\n[근육 증량]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.스쿼트 \n2.데드리프트 \n3.벤치프레스 \n4.팔굽혀펴기 \n5.윗몸 일으키기 \n6.풀업 \n");
		printf("\n원하는 운동: ");
		scanf("%d", &choice3);
		switch (choice3)
		{
		case 1:
			strcpy(exercise_name, "스쿼트");
			strcpy(descr, "어깨 너비로 다리를 벌린 후, 골반 뒤로 빼고 무릎을 굽히고, 90도 각도에 이를 때까지 내려갑니다. 이후 엉덩이를 위로 올려 초기 위치로 돌아갑니다.");
			strcpy(time, "15 ~ 30분(10~15회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 147;
			strcpy(url, "스쿼트 올바른 자세 배우기\n	   https://youtu.be/fy9URmTqNio?si=8MubMXaGBXLmGgB8");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "데드리프트");
			strcpy(descr, "바벨의 정중앙에 서서 발을 어깨 너비로 벌리고, 바벨을 어깨 너비보다 살짝 넓게 잡습니다. 시선은 아래 사선방향으로 하고 허리가 굽어지지 않게 편 상태로 바벨을 들어올립니다.\n하체의 힘으로 무릎까지 바벨을 올리고 무릎 위부터는 등의 힘으로 들어올립니다.");
			strcpy(time, "15 ~ 30분(6~10회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 100;
			strcpy(url, "데드리프트 올바르게 하는 방법 배우기\n	   https://youtu.be/EBjYQeeBI-0?si=fZ1gasghn-ZRCTge");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "벤치 프레스");
			strcpy(descr, "미쉬먼트 바벨 또는 덤벨을 사용하여 가슴을 들어 올리고 내리는 동작을 반복합니다.");
			strcpy(time, "10 ~ 20분(8~12회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 50;
			strcpy(url, "벤치프레스 올바르게 하는 방법 배우기\n	   https://youtu.be/0DsXTSHo3lU?si=_qOT7u-ZiMAYnVP5");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "팔굽혀펴기");
			strcpy(descr, "손을 어깨 너비로 놓고 몸을 바닥과 평행하게 들어올리고 다시 내리는 동작을 반복합니다.");
			strcpy(time, "10분 (15~20회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 49;
			strcpy(url, "팔굽혀펴기 자세 및 효과 배우기\n	   https://youtu.be/-_DUjHxgmWk?si=o1ukxpoBJRzOdseA");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "윗몸 일으키기");
			strcpy(descr, "등을 매트에 눕고 손을 귀 뒤에 두고 상체를 들어올려 다시 내려놓는 동작을 반복합니다.");
			strcpy(time, "10분 (15~20회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 98;
			strcpy(url, "윗몸일으키기 통증 없이 올바르게 하는 방법 배우기\n	   https://youtu.be/kWKqlIKnIG0?si=X6-hqBvlAK1uLCEY");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "풀업");
			strcpy(descr, "팔꿈치를 편 상태에서 어깨너비보다 조금 더 넓게 바를 잡은 뒤 가슴은 열어 살짝 들어주고 어깨는 내립니다. 그대로 가슴을 바에 터치한다는 느낌으로 당겨올립니다.\n상체 근력이 적은 편이라면 밴드의 도움을 받읍시다.");
			strcpy(time, "10분 (10~15회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 15;
			strcpy(url, "풀업 자세 배우기\n	   https://youtu.be/nWhS28U6bCY?si=S3j7U4EYrv-XAOcY");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 4:
		printf("\n*******************\n");
		printf("\n[체지방 감소]를 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.조깅 \n2.달리기 \n3.자전거타기 \n4.수영 \n5.크로스핏 \n6.복싱 \n");
		printf("\n원하는 운동: ");
		scanf("%d", &choice4);
		switch (choice4)
		{
		case 1:
			strcpy(exercise_name, "조깅");
			strcpy(descr, "신발을 신고 편안한 의류를 입은 후, 야외나 트랙에서 느긋한 속도로 뛰거나 걷는 것을 반복합니다.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "하");
			cal = 220;
			strcpy(url, "운동 효과 높이는 조깅 방법\n	   https://youtu.be/4OZKcJ_Ze6E?si=Rdgk6ANeKmPd83Zy");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "달리기");
			strcpy(descr, "적절한 신발을 신고, 경주 트랙이나 자연 환경에서 최대한 빠른 속도로 달리세요.");
			strcpy(time, "20분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 230;
			strcpy(url, "효율적으로 달릴 수 있는 자세와 호흡 방법\n	   https://youtu.be/th7Wi9DsmFo?si=eX_XuLisgdLFsY82");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "자전거타기");
			strcpy(descr, "자전거를 타고 도로, 자전거 도로, 혹은 자전거 트레일을 따라 이동하세요.");
			strcpy(time, "45분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 366;
			strcpy(url, "자전거 타는 방법 배우기\n	   https://youtu.be/M9vqn0R9HmE?si=hJxua2LB7Fh-MP-L");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "수영");
			strcpy(descr, "수영장이나 자연 수영장에서 자유형, 접영, 등에 적합한 스트로크로 수영하세요.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 159;
			strcpy(url, "여러 가지 수영법 배우기\n	   https://youtu.be/7PqEAls1wjE?si=tx4FXGP6qx7CZusA");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "크로스핏");
			strcpy(descr, "크로스핏 피트니스 센터에서 다양한 웨이트 리프팅, 유산소, 체중 운동을 수행하세요.");
			strcpy(time, "1시간 이상");
			// 상세 설명
			strcpy(level, "상");
			cal = 270;
			strcpy(url, "크로스핏 기본 동작 배우기\n	   https://youtu.be/7oGstYEb-_k?si=gYyBOccRRkt03wRP");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "복싱");
			strcpy(descr, "복싱 피트니스 센터에서 훈련을 받거나 복싱 가방을 사용하여 기본 복싱 기술을 연습하세요.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "상");
			cal = 245;
			strcpy(url, "기본 원투 하는 방법 배우기\n	   https://youtu.be/4THFtd5K5TI?si=rD-dObdshI1DpgJJ");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	}
}

// 출력 양식
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[]) {
	
	printf("\n*******************\n");
	printf("\n[%s]운동을 선택하셨습니다.\n", exercise_name);
	printf("설명: %s\n", descr);
	printf("시간: %s\n", time);
	printf("\n***상세 설명***\n");
	printf("강도: %s\n", level);
	printf("예상 소모 칼로리는 %dkcal 입니다.\n", cal);
	printf("참고 영상: %s\n", url);
}

//***********************************************************
//
// 부가 기능 
//
//***********************************************************

// 메뉴 선택을 통한 기능 선택
void select_menu() {
	int select_menu;
	int selected_date, year, month, day;

	printf("\n*******************\n\n");

	printf("어떤 기능을 선택하시겠습니까?\n");
	printf("1. 신체 정보 기록 확인하기(날짜 선택)     2. 이번달 신체 기록 확인하기   \n");
	printf("3. 운동 기록 확인하기                     4. 누적 운동 기록 확인하기   \n\n");

	scanf("%d", &select_menu);

	printf("\n*******************\n\n");

	if (select_menu == 1) {
		printf("확인하고 싶은 날짜를 입력해주세요 (YYYY.MM.DD): ");
		scanf("%d.%d.%d", &year, &month, &day);

		selected_date = (year * 10000 + month * 100 + day);

		bmi_load(selected_date);
	}
	else if (select_menu == 2) {
		bmi_monthly_record();
	}

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

// bmi 정보, 기록한 정보 불러오기
void bmi_load(int selected_date) {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int loadedHeight, loadedWeight;
	float loadedBMI;

	int fatness;

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
			

			//printf("체중: %d kg\n", loadedWeight);
			//printf("BMI: %.2f\n", loadedBMI);

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
