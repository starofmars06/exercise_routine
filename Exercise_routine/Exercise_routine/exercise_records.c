#include "common.h"

// ��� ����, ����� ���� �ҷ�����
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

    printf("Ȯ���ϰ� ���� ��¥�� �Է����ּ��� (YYYY.MM.DD): ");
    scanf("%d.%d.%d", &year, &month, &day);

    selected_date = (year * 10000 + month * 100 + day);

    // �ؽ�Ʈ ���� �̸� ����
    sprintf(filename, "%d.txt", selected_date);

    fbmi = fopen(filename, "r");

    if (fbmi == NULL) {
        printf("�ش� ��¥���� ������� ������� �ʾҽ��ϴ�.\n");
        return;
    }
    
    // ���� �����͸� ������ ó������ �̵�
    fseek(fbmi, 0, SEEK_SET);

    // �о�� ������ ���
    fscanf(fbmi, "��¥: %d\n", &loadedDate);
    fscanf(fbmi, "����: %d cm\n", &loadedHeight);
    fscanf(fbmi, "ü��: %d kg\n", &loadedWeight);
    fscanf(fbmi, "BMI: %f\n", &loadedBMI);
    fscanf(fbmi, "%s\n", &loadedExerciseName);
    fscanf(fbmi, "��� �ð�: %d\n", &exerciseTime);
    fscanf(fbmi, "������: %d\n", &feedback);


    printf("\n");
    printf("����� ��¥: %d\n\n", loadedDate);
    printf("�� ���� [%s]��(��) �ϼ̽��ϴ�.\n", loadedExerciseName);

    //� �ð� ����ϱ�
    separateDigits(exerciseTime);

    //�������� ���� �ٸ� ���� ����ϱ�
    if (feedback == 1) {
        printf("���������ٰ� ������ ���Ͻ� ����� �ֽ��ϴ�.\n\n");
    }
    else {
        printf("�Ҹ��������ٰ� ������ ���Ͻ� ����� �ֽ��ϴ�.\n\n");
    }

    // ���� �ݱ�
    fclose(fbmi);
}


//����� ��ð�
//�ð� ������ �ٽ� ������ �����ֱ�
void separateDigits(int number) {
	if (number >= 1000) { // �� �ڸ� ������ ���
		int thousands = number / 1000;
		int hundreds = (number % 1000) / 100;
		int tens = (number % 100) / 10;
		int units = number % 10;

		printf("��� �ð�: %d%d�ð� %d%d��\n", thousands, hundreds, tens, units);
	}
	else if (number >= 100) { // �� �ڸ� ������ ���
		int hundreds = number / 100;
		int tens = (number % 100) / 10;
		int units = number % 10;

		printf("��� �ð�: %d�ð� %d%d��\n", hundreds, tens, units);
	}
	else if (number >= 10) { // �� �ڸ� ������ ���
		int tens = number / 10;
		int units = number % 10;

		printf("��� �ð�: %d%d��\n", tens, units);
	}
	else if(number >0 && number < 10){ // �� �ڸ� ������ ���
		printf("��� �ð�: %d��\n", number);
	}
	else {
		printf("\n");
	}
}


//�̹��� ���� ��� ������
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
			fscanf(fbmi, "%s\n", &loadedExerciseName);
			fscanf(fbmi, "��� �ð�: %d\n", &exerciseTime);
			fscanf(fbmi, "������: %d\n", &feedback);

			printf("\n");
			// loadedDate�� ����, ��, �Ϸ� �и��Ͽ� ���
			int back_to_year = loadedDate / 10000;
			int back_to_month = (loadedDate % 10000) / 100;
			int back_to_day = loadedDate % 100;


			if (exerciseTime < 0) {
				temp_time = 0;
			}
			else {
				temp_time = exerciseTime;
			}


			printf("�� ");
			printf("%d�� %d�� %d��", back_to_year, back_to_month, back_to_day);

			printf("\n");


			if (exerciseTime < 0) {
				printf("�� \n");
				printf("�� \n");
				printf("�� ");
			}
			else if(exerciseTime < 30) {
				printf("��");
				printf("��������");
				printf("��");

				separateDigits(exerciseTime);


				printf("��");
				printf("��������");
				printf("��\n");
				printf("�� ");


			}
			else if (exerciseTime < 100) {
				printf("��");
				printf("����������������");
				printf("��");

				separateDigits(exerciseTime);

				printf("��");
				printf("����������������");
				printf("��\n");
				printf("�� ");
			}
			else if (exerciseTime < 130) {
				printf("��");
				printf("��������������������������");
				printf("��");

				separateDigits(exerciseTime);

				printf("��");
				printf("��������������������������");
				printf("��\n");
				printf("�� ");

			}
			else if (exerciseTime < 200) {
				printf("��");
				printf("������������������������������������");
				printf("��");

				separateDigits(exerciseTime);


				printf("��");
				printf("������������������������������������");
				printf("��\n");
				printf("�� ");
			}
			else if( exerciseTime >= 200){
				printf("��");
				printf("����������������������������������������������");
				printf("��");

				separateDigits(exerciseTime);

				printf("��");
				printf("����������������������������������������������");
				printf("��\n");
				printf("�� ");
			}
			else {
				printf("�� \n");
				printf("�� \n");
				printf("�� ");
			}

			fclose(fbmi);
			foundRecords = 1;  // ����� ã������ ǥ��
		}
	}

	if (!foundRecords) {
		printf("������ ��¥ ������ ��ϵ� ������ �����ϴ�.\n");
	}


}








