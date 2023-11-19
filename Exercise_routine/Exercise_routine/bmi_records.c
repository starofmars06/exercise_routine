#include "common.h"

// bmi ����, ����� ���� �ҷ�����
void bmi_load() {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int loadedHeight, loadedWeight;
	float loadedBMI;

	int fatness;
	int year, month, day, selected_date;

	printf("Ȯ���ϰ� ���� ��¥�� �Է����ּ��� (YYYY.MM.DD): ");
	scanf("%d.%d.%d", &year, &month, &day);

	selected_date = (year * 10000 + month * 100 + day);

	// �ؽ�Ʈ ���� �̸� ����
	sprintf(filename, "%d.txt", selected_date);

	fbmi = fopen(filename, "r");

	if (fbmi == NULL) {
		printf("�ش� ��¥���� ��ü������ ������� �ʾҽ��ϴ�.\n");
		return;
	}


	// �о�� ������ ���
	fscanf(fbmi, "��¥: %d\n", &loadedDate);
	fscanf(fbmi, "����: %d cm\n", &loadedHeight);
	fscanf(fbmi, "ü��: %d kg\n", &loadedWeight);
	fscanf(fbmi, "BMI: %f\n", &loadedBMI);

	printf("\n");
	printf("����: %d cm\n", loadedHeight);
	printf("ü��: %d kg\n", loadedWeight);
	printf("BMI: %.2f\n", loadedBMI);

	//bmi ����� ���ؼ�
	//18.5 ���� ��ü��, 18.5~22.9 ����, 23.0~24.9 ��ü��, 25 �̻� ��
	fatness = loadedBMI;

	if (fatness < 18.5) {
		printf(ANSI_COLOR_YELLOW ".........<��ü��>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 23.0) {
		printf(ANSI_COLOR_GREEN ".........<����ü��>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 25.0) {
		printf(ANSI_COLOR_BLUE ".........<��ü��>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 30.0) {
		printf(ANSI_COLOR_MAGENTA ".........<��>\n" ANSI_COLOR_RESET);
	}
	else {
		printf(ANSI_COLOR_RED ".........<����>\n" ANSI_COLOR_RESET);
	}


	// ���� �ݱ�
	fclose(fbmi);
}


//�̹��� ���� ��� ������
void bmi_monthly_record() {
	char filename[20];
	FILE* fbmi;

	int loadedDate;
	int loadedHeight, loadedWeight;
	float loadedBMI;

	int fatness;
	int foundRecords = 0;  // ������ ����� ����� ã�Ҵ��� ����

	int count = 0;


	//�̹��� ���� ��¥ ���ϱ�
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
	printf("\n********** ��ϵ� ���� **********\n");

	for (int i = this_month_start_date; i <= today; i++) {
		// �ؽ�Ʈ ���� �̸� ����
		sprintf(filename, "%d.txt", i);

		fbmi = fopen(filename, "r");

		if (fbmi != NULL) {
			// �о�� ������ ���
			fscanf(fbmi, "��¥: %d\n", &loadedDate);
			fscanf(fbmi, "����: %d cm\n", &loadedHeight);
			fscanf(fbmi, "ü��: %d kg\n", &loadedWeight);
			fscanf(fbmi, "BMI: %f\n", &loadedBMI);

			printf("\n");
			// loadedDate�� ����, ��, �Ϸ� �и��Ͽ� ���
			int back_to_year = loadedDate / 10000;
			int back_to_month = (loadedDate % 10000) / 100;
			int back_to_day = loadedDate % 100;


			// bmi ����� ���ؼ�
			// 18.5 ���� ��ü��, 18.5~22.9 ����, 23.0~24.9 ��ü��, 25 �̻� ��
			fatness = loadedBMI;

			printf("�� ");
			printf("%d�� %d�� %d��\n", back_to_year, back_to_month, back_to_day);

			if (fatness < 18.5) {
				printf("��");
				printf("��������");
				printf("��");

				printf(ANSI_COLOR_YELLOW "%d��......<��ü��>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("��");
				printf("��������");
				printf("��\n");
				printf("�� ");


			}
			else if (fatness < 23.0) {
				printf("��");
				printf("����������������");
				printf("��");

				printf(ANSI_COLOR_GREEN "%d��......<����ü��>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("��");
				printf("����������������");
				printf("��\n");
				printf("�� ");
			}
			else if (fatness < 25.0) {
				printf("��");
				printf("��������������������������");
				printf("��");

				printf(ANSI_COLOR_BLUE "%d��......<��ü��>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("��");
				printf("��������������������������");
				printf("��\n");
				printf("�� ");

			}
			else if (fatness < 30.0) {
				printf("��");
				printf("������������������������������������");
				printf("��");

				printf(ANSI_COLOR_MAGENTA "%d��......<��>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);


				printf("��");
				printf("������������������������������������");
				printf("��\n");
				printf("�� ");
			}
			else {
				printf("��");
				printf("����������������������������������������������");
				printf("��");

				printf(ANSI_COLOR_RED "%d��......<����>", loadedWeight);
				printf("\n" ANSI_COLOR_RESET);

				printf("��");
				printf("����������������������������������������������");
				printf("��\n");
				printf("�� ");
			}

			fclose(fbmi);
			foundRecords = 1;  // ����� ã������ ǥ��

			count++;
		}
	}

	if (!foundRecords) {
		printf("������ ��¥ ������ ��ϵ� ������ �����ϴ�.\n");
	}

	//-----------------------------------------
	printf("\n\n�̹� �޿��� �� %d �� ��ü����� �ϼ̽��ϴ�.\n", count);


}