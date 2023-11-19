#include "common.h"


// 메뉴 선택을 통한 기능 선택
void select_menu() {
	int select_menu, choice1;

	SelectMenu:
	printf("\n*******************\n\n");

	printf("어떤 기능을 선택하시겠습니까?\n");
	printf("1. 운동 목표별 루틴 선택\n");
	printf("2. 신체 정보 기록 확인하기(날짜 선택)     3. 이번달 신체 기록 확인하기   \n");
	printf("4. 운동 기록 확인하기                     5. 누적 운동 기록 확인하기   \n\n");

	printf("\n\n(*:그만두시려면 0을 눌러주세요)\n");
	scanf("%d", &select_menu);

	printf("\n*******************\n\n");

	if (select_menu == 1) {
		printf("본 메뉴는 운동 목표별로 루틴을 선택해서 정보를 확인하고, 운동 후 만족도 평가 및 기록할 수 있습니다.\n");
		printf("진행하시려면 1번, 뒤로 가려면 2번을 눌러주세요.\n\n");

		printf("1번 : 운동하기        2번 : 뒤로가기\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//3. 운동 종목 선택하기
			daily_routine(name);

			//4. 운동 후 만족도 평가
			user_feedback();
		}

		goto SelectMenu;
	}
	else if (select_menu == 2) {

		printf("본 메뉴는 날짜별로 기록한 신체정보를 확인할 수 있습니다.\n");
		printf("진행하시려면 1번, 뒤로 가려면 2번을 눌러주세요.\n\n");

		printf("1번 : 기록 확인하기        2번 : 뒤로가기\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//날짜별 신체 기록 확인
			bmi_load();
		}

		goto SelectMenu;
	}
	else if (select_menu == 3) {
		printf("본 메뉴는 이번달에 기록한 신체정보를 누적 그래프로 확인할 수 있습니다.\n");
		printf("진행하시려면 1번, 뒤로 가려면 2번을 눌러주세요.\n\n");

		printf("1번 : 기록 확인하기        2번 : 뒤로가기\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//이번달 누적 신체 기록 확인
			bmi_monthly_record();
		}
		goto SelectMenu;
	}
	else if (select_menu == 4) {
		printf("본 메뉴는 날짜별로 기록한 신체정보를 확인할 수 있습니다.\n");
		printf("진행하시려면 1번, 뒤로 가려면 2번을 눌러주세요.\n\n");

		printf("1번 : 기록 확인하기        2번 : 뒤로가기\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//날짜별 운동 기록 확인
			exercise_load();
		}

		goto SelectMenu;
	}
	else if (select_menu == 5) {
		printf("본 메뉴는 이번달에 기록한 운동 시간을 누적 그래프로 확인할 수 있습니다.\n");
		printf("진행하시려면 1번, 뒤로 가려면 2번을 눌러주세요.\n\n");

		printf("1번 : 기록 확인하기        2번 : 뒤로가기\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//이번달 누적 운동 시간 기록 확인
			exercise_monthly_record();
		}
		goto SelectMenu;
	}
	else if (select_menu == 0) {
		printf("프로그램을 종료합니다.\n");
		printf("충분한 휴식을 취해주세요, 오늘도 수고하셨습니다!\n");
	}

}