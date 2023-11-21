#include "common.h"

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
	int flex;                          // 운동 목표가 유연성인지 아닌지 판별
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
			flex = 0;
			strcpy(url, "운동 효과를 높이기 위해 바르게 걷는 방법\n	   https://youtu.be/rVoB0heVow0?si=QsUqPhefBghZ_jDy");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 2:
			strcpy(exercise_name, "등산");
			strcpy(descr, "근처 산, 산림, 혹은 등산로를 찾아 등산화와 편한 옷을 입고 산을 오르세요.");
			strcpy(time, "30분 ~ 2시간 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 204;
			flex = 0;
			strcpy(url, "등산할 때 올바른 보행법\n	   https://youtu.be/NTEaUa8SSpM?si=maVK23YRfzmlr1b-");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 3:
			strcpy(exercise_name, "줄넘기");
			strcpy(descr, "줄을 가지고 양쪽 손으로 손잡이를 잡고, 발을 조금 들어올려 줄을 넘어 뛰어 넘기세요.");
			strcpy(time, "30분~1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 371;
			flex = 0;
			strcpy(url, "줄넘기 초보자를 위한 간단한 설명\n	   https://youtu.be/_yWerNDS2AQ?si=KbnH8guZX_JJ0Oa1");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 4:
			strcpy(exercise_name, "배드민턴");
			strcpy(descr, "빠른 속도로 이동하면서 라켓으로 셔틀콕을 치세요. 상대방과 게임을 한다면, 서로 셔틀콕을 라켓으로 주고 받을 수 있습니다.");
			strcpy(time, "1시간 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 246;
			flex = 0;
			strcpy(url, "배드민턴 입문자용 기초 설명\n	   https://youtu.be/giXK9YAeJEI?si=nKTfS_rM72A3MSHe");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
		case 5:
			strcpy(exercise_name, "계단 오르기");
			strcpy(descr, "건물 내부 또는 야외의 계단을 오르내리기를 반복하세요.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "하");
			cal = 261;
			flex = 0;
			strcpy(url, "효과적으로 계단오르기 운동 하는 방법\n	   https://youtu.be/5K_-Bz9VfHw?si=QPudFsNtw9pQxmgs");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 6:
			strcpy(exercise_name, "인터벌 트레이닝");
			strcpy(descr, "5분의 워밍업 후 8~10의 속도로 3분간 달립니다. 그 후 5~6의 속도로 2분간 걷습니다. 해당 루틴을 30분동안 반복한 후 쿨 다운이 들어가 5~10분간 천천히 걷습니다. \n자신의 체력 수준에 따라 속도와 시간을 조절하여 수행합시다.");
			strcpy(time, "30분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 157;
			flex = 0;
			strcpy(url, "인터벌트레이닝의 방법과 효과\n	   https://youtu.be/RKcfpPNlMvE?si=z6nWkIUmKrZNBclu");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
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
			flex = 1;
			strcpy(url, "반달자세 하는 방법\n	   https://youtu.be/E93q2CDmp14?si=O0PUMTEwNRqx9RbS");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 2:
			strcpy(exercise_name, "독수리 자세");
			strcpy(descr, "오른팔을 왼팔 밑으로 해 팔꿈치를 교차하고 양 손바닥이 맞닿도록 합니다. \n오른쪽 다리를 비틀고 오른발을 왼쪽 종아리에 걸친 상태로 유지하다가 방향을 바꿉시다.");
			strcpy(time, "30초 ~ 1분");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			flex = 1;
			strcpy(url, "독수리자세 하는 방법\n		https://youtu.be/0yVcCuc_uGE?si=iWOupRitjG_7uKSP");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;

		case 3:
			strcpy(exercise_name, "나무 자세");
			strcpy(descr, "한 쪽 발을 반대쪽 허벅지 안쪽에 붙이고, 두 손은 머리 위로 올려 깍지를 낀 채로 서서 자세를 유지하다가 방향을 바꿉시다.");
			strcpy(time, "1분 ~ 1분 30초");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			flex = 1;
			strcpy(url, "나무자세 하는 방법\n	   https://youtu.be/TptsloulelU?si=EyVohJpO7mhmq-H2");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 4:
			strcpy(exercise_name, "필라테스");
			strcpy(descr, "필라테스 매트를 사용하여 다양한 동작을 수행하거나, 필라테스 기구를 활용합시다.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 30;
			flex = 1;
			strcpy(url, "집에서 하는 전신필라테스 20가지 동작\n	   https://youtu.be/L5QnCr_vdJE?si=miiZhZyb5_M2xbc3");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 5:
			strcpy(exercise_name, "다리 찢기");
			strcpy(descr, "다리를 앞으로 뻗고 있다가 천천히 좌우로 벌립니다.");
			strcpy(time, "30초 ~ 1분");
			// 상세 설명
			strcpy(level, "하");
			cal = 30;
			flex = 1;
			strcpy(url, "다리 찢기 늘리는 방법\n	   https://youtu.be/MYdr0deU5N4?si=Ez9h_3KQExrR102M");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
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
			flex = 0;
			strcpy(url, "스쿼트 올바른 자세 배우기\n	   https://youtu.be/fy9URmTqNio?si=8MubMXaGBXLmGgB8");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 2:
			strcpy(exercise_name, "데드리프트");
			strcpy(descr, "바벨의 정중앙에 서서 발을 어깨 너비로 벌리고, 바벨을 어깨 너비보다 살짝 넓게 잡습니다. 시선은 아래 사선방향으로 하고 허리가 굽어지지 않게 편 상태로 바벨을 들어올립니다.\n하체의 힘으로 무릎까지 바벨을 올리고 무릎 위부터는 등의 힘으로 들어올립니다.");
			strcpy(time, "15 ~ 30분(6~10회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 100;
			flex = 0;
			strcpy(url, "데드리프트 올바르게 하는 방법 배우기\n	   https://youtu.be/EBjYQeeBI-0?si=fZ1gasghn-ZRCTge");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 3:
			strcpy(exercise_name, "벤치 프레스");
			strcpy(descr, "미쉬먼트 바벨 또는 덤벨을 사용하여 가슴을 들어 올리고 내리는 동작을 반복합니다.");
			strcpy(time, "10 ~ 20분(8~12회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 50;
			flex = 0;
			strcpy(url, "벤치프레스 올바르게 하는 방법 배우기\n	   https://youtu.be/0DsXTSHo3lU?si=_qOT7u-ZiMAYnVP5");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 4:
			strcpy(exercise_name, "팔굽혀펴기");
			strcpy(descr, "손을 어깨 너비로 놓고 몸을 바닥과 평행하게 들어올리고 다시 내리는 동작을 반복합니다.");
			strcpy(time, "10분 (15~20회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 49;
			flex = 0;
			strcpy(url, "팔굽혀펴기 자세 및 효과 배우기\n	   https://youtu.be/-_DUjHxgmWk?si=o1ukxpoBJRzOdseA");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 5:
			strcpy(exercise_name, "윗몸 일으키기");
			strcpy(descr, "등을 매트에 눕고 손을 귀 뒤에 두고 상체를 들어올려 다시 내려놓는 동작을 반복합니다.");
			strcpy(time, "10분 (15~20회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 98;
			flex = 0;
			strcpy(url, "윗몸일으키기 통증 없이 올바르게 하는 방법 배우기\n	   https://youtu.be/kWKqlIKnIG0?si=X6-hqBvlAK1uLCEY");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 6:
			strcpy(exercise_name, "풀업");
			strcpy(descr, "팔꿈치를 편 상태에서 어깨너비보다 조금 더 넓게 바를 잡은 뒤 가슴은 열어 살짝 들어주고 어깨는 내립니다. 그대로 가슴을 바에 터치한다는 느낌으로 당겨올립니다.\n상체 근력이 적은 편이라면 밴드의 도움을 받읍시다.");
			strcpy(time, "10분 (10~15회 반복)");
			// 상세 설명
			strcpy(level, "중");
			cal = 15;
			flex = 0;
			strcpy(url, "풀업 자세 배우기\n	   https://youtu.be/nWhS28U6bCY?si=S3j7U4EYrv-XAOcY");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
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
			flex = 0;
			strcpy(url, "운동 효과 높이는 조깅 방법\n	   https://youtu.be/4OZKcJ_Ze6E?si=Rdgk6ANeKmPd83Zy");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 2:
			strcpy(exercise_name, "달리기");
			strcpy(descr, "적절한 신발을 신고, 경주 트랙이나 자연 환경에서 최대한 빠른 속도로 달리세요.");
			strcpy(time, "20분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 230;
			flex = 0;
			strcpy(url, "효율적으로 달릴 수 있는 자세와 호흡 방법\n	   https://youtu.be/th7Wi9DsmFo?si=eX_XuLisgdLFsY82");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 3:
			strcpy(exercise_name, "자전거타기");
			strcpy(descr, "자전거를 타고 도로, 자전거 도로, 혹은 자전거 트레일을 따라 이동하세요.");
			strcpy(time, "45분 이상");
			// 상세 설명
			strcpy(level, "중");
			cal = 366;
			flex = 0;
			strcpy(url, "자전거 타는 방법 배우기\n	   https://youtu.be/M9vqn0R9HmE?si=hJxua2LB7Fh-MP-L");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 4:
			strcpy(exercise_name, "수영");
			strcpy(descr, "수영장이나 자연 수영장에서 자유형, 접영, 등에 적합한 스트로크로 수영하세요.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "중");
			cal = 159;
			flex = 0;
			strcpy(url, "여러 가지 수영법 배우기\n	   https://youtu.be/7PqEAls1wjE?si=tx4FXGP6qx7CZusA");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 5:
			strcpy(exercise_name, "크로스핏");
			strcpy(descr, "크로스핏 피트니스 센터에서 다양한 웨이트 리프팅, 유산소, 체중 운동을 수행하세요.");
			strcpy(time, "1시간 이상");
			// 상세 설명
			strcpy(level, "상");
			cal = 270;
			flex = 0;
			strcpy(url, "크로스핏 기본 동작 배우기\n	   https://youtu.be/7oGstYEb-_k?si=gYyBOccRRkt03wRP");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		case 6:
			strcpy(exercise_name, "복싱");
			strcpy(descr, "복싱 피트니스 센터에서 훈련을 받거나 복싱 가방을 사용하여 기본 복싱 기술을 연습하세요.");
			strcpy(time, "30분 ~ 1시간");
			// 상세 설명
			strcpy(level, "상");
			cal = 245;
			flex = 0;
			strcpy(url, "기본 원투 하는 방법 배우기\n	   https://youtu.be/4THFtd5K5TI?si=rD-dObdshI1DpgJJ");

			exercise_details(exercise_name, descr, time, level, cal, url, flex);
			break;
		}
		break;
	}


	//----------------------------------------------------------
	//오늘 날짜인지 확인하기
	date = date_to_file_name();

	chosen_routine_save(date, exercise_name);
	printf("\n\n 선택한 운동은 : %s 입니다.\n\n", exercise_name);




}

// 출력 양식
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[], int flex) {
	printf("\n*******************\n");
	printf("\n[%s]운동을 선택하셨습니다.\n", exercise_name);
	printf("설명: %s\n", descr);
	printf("시간: %s\n", time);
	printf("\n***상세 설명***\n");
	printf("강도: %s\n", level);
	if (flex == 0)
	{
		printf("예상 소모 칼로리는 %dkcal 입니다.\n", cal);
		printf("참고 영상: %s\n", url);
	}
	else if (flex == 1)
	{
		printf("참고 영상: %s\n", url);
	}
}


// bmi 신체 정보를 기록한 파일에
// 운동 시간과 만족도를 추가해서 기록하고자 함.
void chosen_routine_save(int date, char* exercise_name) {
	char filename[20];
	FILE* fbmi;

	//텍스트 파일 이름 지정
	sprintf(filename, "%d.txt", date);

	fbmi = fopen(filename, "a");


	//텍스트 파일에 운동 정보 저장
	fprintf(fbmi, "%s\n", exercise_name);

	// 파일 닫기
	fclose(fbmi);

	printf("\n\n운동 기록이 성공적으로 저장되었습니다.\n");
}
