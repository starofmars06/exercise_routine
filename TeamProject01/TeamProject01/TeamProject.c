#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_RESET    "\x1b[0m"

char name[20];

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

void bmi_calculation(char* name) {
	int height, weight;
	float fatness;      //비만도

	//신체 정보 입력(키, 몸무게)
	printf("\n*******************\n");            //구분선
	printf("반갑습니다, %s님!\n", name);            //환영문구
	printf("신체 정보를 입력해주세요.\n");

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

}

void daily_routine(char* name) {
	int choice;   // 선택값
	int choice1, choice2, choice3, choice4; // 운동 목표에 따른 운동 종류 선택값
	int c;

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
		printf("경고! 올바른 값을 입력하세요.\n");
		while ((c = getchar()) != '\n' && c != EOF);  // 잘못된 입력값 비워주기
		daily_routine(name);  // 재귀 호출 (daily_routine 함수 처음부터 다시 실행)
	}
	// 입력받은 선택값에 따라 해당 번호의 운동 출력
	switch (choice)
	{
	case 1: // 심폐 지구력 향상
		printf("\n[심폐 지구력 향상]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1: 걷기 \n2: 등산 \n3: 줄넘기 \n4: 배드민턴 \n5: 계단 오르기 \n6: 인터벌 트레이닝 \n");
		printf("\n선택할 운동: ");
		scanf("%d", &choice1);
		// 원하는 운동 번호에 따라 운동 설명 출력
		switch (choice1)
		{
		case 1:
			printf("\n[걷기]운동을 선택하셨습니다.\n");
			printf("설명: 밖에서 걷거나, 실내에서 트레드밀을 이용해서 걸어봅시다.\n");
			printf("시간: 30분 이상\n");
			break;
		case 2:
			printf("\n[등산]운동을 선택하셨습니다. \n");
			printf("설명: 근처 산, 산림, 혹은 등산로를 찾아 등산화와 편한 옷을 입고 산을 오르세요.\n");
			printf("시간: 30분 ~ 2시간 이상\n");
			break;
		case 3:
			printf("\n[줄넘기]운동을 선택하셨습니다. \n");
			printf("설명: 줄을 가지고 양쪽 손으로 손잡이를 잡고, 발을 조금 들어올려 줄을 넘어 뛰어 넘기세요.\n");
			printf("시간: 30분~1시간\n");
			break;
		case 4:
			printf("\n[배드민턴]운동을 선택하셨습니다. \n");
			printf("설명: 빠른 속도로 이동하면서 라켓으로 셔틀콕을 치세요. 상대방과 게임을 한다면, 서로 셔틀콕을 라켓으로 주고 받을 수 있습니다.\n");
			printf("시간: 1시간 이상\n");
		case 5:
			printf("\n[계단 오르기]운동을 선택하셨습니다. \n");
			printf("설명: 건물 내부 또는 야외의 계단을 오르내리기를 반복하세요.\n");
			printf("시간: 30분 이상\n");
			break;
		case 6:
			printf("\n[인터벌 트레이닝]운동을 선택하셨습니다. \n");
			printf("설명: 5분의 워밍업 후 8~10의 속도로 3분간 달립니다. 그 후 5~6의 속도로 2분간 걷습니다. 해당 루틴을 30분동안 반복한 후 쿨 다운이 들어가 5~10분간 천천히 걷습니다. \n자신의 체력 수준에 따라 속도와 시간을 조절하여 수행합시다.\n");
			printf("시간: 30분 이상\n");
			break;
		}
		break;
	case 2: //유연성 향상
		printf("\n[유연성 향상]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.반달 자세 \n2: 독수리 자세 \n3: 나무 자세 \n4:필라테스 \n5: 다리 찢기");
		printf("\n선택할 운동: ");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			printf("\n[반달 자세]운동을 선택하셨습니다. \n");
			printf("설명: 몸을 한 쪽으로 기울여 하나의 손을 바닥에 놓고 다른 팔을 천장 쪽으로 뻗어서 유지하다가 방향을 바꿉시다.");
			printf("시간: 30초 ~ 1분\n");
			break;
		case 2:
			printf("\n[독수리 자세]운동을 선택하셨습니다. \n");
			printf("설명:오른팔을 왼팔 밑으로 해 팔꿈치를 교차하고 양 손바닥이 맞닿도록 합니다. \n오른쪽 다리를 비틀고 오른발을 왼쪽 종아리에 걸친 상태로 유지하다가 방향을 바꿉시다. \n");
			printf("시간: 30초 ~ 1분\n");
			break;

		case 3:
			printf("\n[나무 자세]운동을 선택하셨습니다. \n");
			printf("설명: 한 쪽 발을 반대쪽 허벅지 안쪽에 붙이고, 두 손은 머리 위로 올려 깍지를 낀 채로 서서 자세를 유지하다가 방향을 바꿉시다.\n");
			printf("시간: 1분 ~ 1분 30초\n");
			break;
		case 4:
			printf("\n[필라테스]운동을 선택하셨습니다. \n");
			printf("설명: 필라테스 매트를 사용하여 다양한 동작을 수행하거나, 필라테스 기구를 활용합시다. \n");
			printf("시간: 30분 ~ 1시간 \n");
			break;
		case 5:
			printf("\n[다리 찢기]운동을 선택하셨습니다. \n");
			printf("설명: 다리를 앞으로 뻗고 있다가 천천히 좌우로 벌립니다. \n");
			break;
		}
		break;
	case 3: //근육 증량
		printf("\n[근육 증량]을 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.스쿼트 \n2.데드리프트 \n3.벤치프레스 \n4.팔굽혀펴기 \n5.윗몸 일으키기 \n6.풀업 \n");
		printf("\n원하는 운동: ");
		scanf("%d", &choice3);
		switch (choice3)
		{
		case 1:
			printf("\n[스쿼트]운동을 선택하셨습니다.\n");
			printf("설명: 어깨 너비로 다리를 벌린 후, 골반 뒤로 빼고 무릎을 굽히고, 90도 각도에 이를 때까지 내려갑니다. 이후 엉덩이를 위로 올려 초기 위치로 돌아갑니다.\n");
			printf("시간: 15 ~ 30분(10~15회 반복)\n");
			break;
		case 2:
			printf("\n[데드리프트]운동을 선택하셨습니다.\n");
			printf("설명: 바벨의 정중앙에 서서 발을 어깨 너비로 벌리고, 바벨을 어깨 너비보다 살짝 넓게 잡습니다. 시선은 아래 사선방향으로 하고 허리가 굽어지지 않게 편 상태로 바벨을 들어올립니다.\n하체의 힘으로 무릎까지 바벨을 올리고 무릎 위부터는 등의 힘으로 들어올립니다\n");
			printf("반복: 6 ~ 10회\n");
			break;
		case 3:
			printf("\n[벤치 프레스]운동을 선택하셨습니다.\n");
			printf("설명: 미쉬먼트 바벨 또는 덤벨을 사용하여 가슴을 들어 올리고 내리는 동작을 반복합니다.\n");
			printf("반복: 3세트(8 ~ 12회)\n");
			break;
		case 4:
			printf("\n[팔굽혀펴기]운동을 선택하셨습니다.\n");
			printf("설명: 손을 어깨 너비로 놓고 몸을 바닥과 평행하게 들어올리고 다시 내리는 동작을 반복합니다\n");
			break;
		case 5:
			printf("\n[윗몸 일으키기]운동을 선택하셨습니다.\n");
			printf("설명: 등을 매트에 눕고 손을 귀 뒤에 두고 상체를 들어올려 다시 내려놓는 동작을 반복합니다\n");
			printf("반복: 3세트(15 ~ 20회)\n");
			break;
		case 6:
			printf("\n[풀업]운동을 선택하셨습니다.\n");
			printf("설명: 팔꿈치를 편 상태에서 어깨너비보다 조금 더 넓게 바를 잡은 뒤 가슴은 열어 살짝 들어주고 어깨는 내립니다. 그대로 가슴을 바에 터치한다는 느낌으로 당겨올립니다.\n상체 근력이 적은 편이라면 밴드의 도움을 받읍시다.\n");
			break;
		}
		break;
	case 4:
		printf("\n[체지방 감소]를 목표로 설정하셨습니다.\n");
		printf("아래 운동들 중 원하는 운동의 번호를 선택하세요.\n");
		printf("1.조깅 \n2.달리기 \n3.자전거타기 \n4.수영 \n5.크로스핏 \n6.복싱 \n");
		printf("\n원하는 운동: ");
		scanf("%d", &choice4);
		switch (choice4)
		{
		case 1:
			printf("\n[조깅]운동을 선택하셨습니다.\n");
			printf("설명: 신발을 신고 편안한 의류를 입은 후, 야외나 트랙에서 느긋한 속도로 뛰거나 걷는 것을 반복합니다.\n");
			printf("시간: 30분 이상\n");
			break;
		case 2:
			printf("\n[달리기]운동을 선택하셨습니다.\n");
			printf("설명: 적절한 신발을 신고, 경주 트랙이나 자연 환경에서 최대한 빠른 속도로 달리세요.\n");
			printf("시간: 20분 이상\n");
			break;
		case 3:
			printf("\n[자전거타기]운동을 선택하셨습니다.\n");
			printf("설명: 자전거를 타고 도로, 자전거 도로, 혹은 자전거 트레일을 따라 이동하세요. \n");
			printf("시간: 45분 이상\n");
			break;
		case 4:
			printf("\n[수영]운동을 선택하셨습니다.\n");
			printf("설명: 수영장이나 자연 수영장에서 자유형, 접영, 등에 적합한 스트로크로 수영하세요.\n");
			printf("시간: 30분 ~ 1시간\n");
			break;
		case 5:
			printf("\n[크로스핏]운동을 선택하셨습니다.\n");
			printf("설명: 크로스핏 피트니스 센터에서 다양한 웨이트 리프팅, 유산소, 체중 운동을 수행하세요\n");
			printf("시간: 1시간 이상\n");
			break;
		case 6:
			printf("\n[복싱]운동을 선택하셨습니다.\n");
			printf("설명: 복싱 피트니스 센터에서 훈련을 받거나 복싱 가방을 사용하여 기본 복싱 기술을 연습하세요.\n");
			printf("시간: 30분 ~ 1시간\n");
			break;
		}
		break;
	}
}

int main() {
	//1. 이름 저장하고 불러오기
	save_load_name();

	//2. BMI 측정(신체 정보 입력)
	bmi_calculation(name);

	//3. 운동 종목 선택하기
	daily_routine(name);

}
