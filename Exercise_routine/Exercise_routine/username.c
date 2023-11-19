#include "common.h"

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