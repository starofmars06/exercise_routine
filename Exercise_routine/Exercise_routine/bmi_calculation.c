#include "common.h"

//2. ��ü ���� �Է� �� bmi ����
void bmi_calculation(char* name) {
	int height, weight;
	float fatness;      //�񸸵�

	//��ü ���� �Է�(Ű, ������)
	printf("\n*******************\n\n");            //���м�
	printf("�ݰ����ϴ�, %s��!\n", name);            //ȯ������
	printf("��ü ������ �Է����ּ���.\n\n");

	printf("Ű�� ���Դϱ�?(cm) : ");
	scanf("%d", &height);

	printf("�����Դ� ���Դϱ�?(kg) : ");
	scanf("%d", &weight);

	//----------------------------------------------------------------------------
	// --> �񸸵� ���

	//ī���� ������ ������ "�񸸵�" = ü��(kg) / (����(m) * ����(m))
	fatness = (float)weight / ((float)height * 0.01 * (float)height * 0.01);   //���Ͱ��� �������� �ϱ� ������ Ű�� ���� 0.01�� ������.

	//18.5 ���� ��ü��, 18.5~23.0 ����, 23.0~25.0 ��ü��, 25.0~30.0 ��, 30.0 �̻� ��
	if (fatness < 18.5) {
		printf(ANSI_COLOR_YELLOW ".........�����\n");
		printf(".......���������\n");
		printf(".......���������\n");
		printf(".........�����\n");
		printf("........��������\n");
		printf("......�����������\n");
		printf("....���������������\n");
		printf("...���   �������   ���\n");
		printf("..���    �������    ���\n");
		printf("........�������\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf(".........<��ü���Դϴ�.�ǰ��� �������ּ���.>\n");

		printf("\nü�� ������ ���� [���� ����] ��� �����մϴ�.\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 23.0) {
		printf(ANSI_COLOR_GREEN ".........�����\n");
		printf(".......���������\n");
		printf(".......���������\n");
		printf(".........�����\n");
		printf("........��������\n");
		printf("......�����������\n");
		printf("....���������������\n");
		printf("...���   �������   ���\n");
		printf("..���    �������    ���\n");
		printf("........�������\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");

		printf(".........<����ü���Դϴ�>\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 25.0) {
		printf(ANSI_COLOR_BLUE ".........�����\n");
		printf(".......���������\n");
		printf(".......���������\n");
		printf(".........�����\n");
		printf("........��������\n");
		printf("......�����������\n");
		printf("....���������������\n");
		printf("...���   �������   ���\n");
		printf("..���    �������    ���\n");
		printf("........�������\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");

		printf(".........<��ü���Դϴ�. �ǰ��� �������ּ���.>\n");

		printf("\nü�� ������ ���� [ü���� ����] ��� �����մϴ�.\n" ANSI_COLOR_RESET);
	}
	else if (fatness < 30.0) {
		printf(ANSI_COLOR_MAGENTA ".........�����\n");
		printf(".......���������\n");
		printf(".......���������\n");
		printf(".........�����\n");
		printf("........��������\n");
		printf("......�����������\n");
		printf("....���������������\n");
		printf("...���   �������   ���\n");
		printf("..���    �������    ���\n");
		printf("........�������\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");

		printf(".........<���Դϴ�. �ǰ��� �������ּ���.>\n");

		printf("\nü�� ������ ���� [ü���� ����] ��� �����մϴ�.\n" ANSI_COLOR_RESET);
	}
	else {
		printf(ANSI_COLOR_RED ".........�����\n");
		printf(".......���������\n");
		printf(".......���������\n");
		printf(".........�����\n");
		printf("........��������\n");
		printf("......�����������\n");
		printf("....���������������\n");
		printf("...���   �������   ���\n");
		printf("..���    �������    ���\n");
		printf("........�������\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");
		printf("........���  ���\n");

		printf(".........<�����Դϴ�. �ǰ��� �������ּ���.>\n");

		printf("\nü�� ������ ���� [ü���� ����] ��� �����մϴ�.\n" ANSI_COLOR_RESET);
	}


	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//��ü ���� ����ϱ�

	//���� ��¥ ����ϱ�
	date = date_to_file_name();

	//���� ��¥, Ű, ������, bmi �����ϱ�.
	bmi_save(date, height, weight, fatness);
}

// bmi ��ü ���� ����� ���ؼ�
// �ؽ�Ʈ ���� ������ ��¥�� �����ϰ��� ��.
void bmi_save(int date, int height, int weight, float bmi) {
	char filename[20];
	FILE* fbmi;

	//�ؽ�Ʈ ���� �̸� ����
	sprintf(filename, "%d", date);
	strcat(filename, ".txt");

	fbmi = fopen(filename, "w");

	//�ؽ�Ʈ ���Ͽ� bmi ���� ����
	fprintf(fbmi, "��¥: %d\n", date);
	fprintf(fbmi, "����: %d cm\n", height);
	fprintf(fbmi, "ü��: %d kg\n", weight);
	fprintf(fbmi, "BMI: %.2f\n", bmi);

	// ���� �ݱ�
	fclose(fbmi);

	printf("BMI ������ ���������� ����Ǿ����ϴ�.\n");
}


// ���� �̸����� �� �� �ֵ���, ��¥ ���� ��ȯ�ϱ�
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

// �̹� ���� ��ϵ� ������ �ִ��� Ȯ���ϴ� �Լ�
int hasRecordedToday(char* name) {
	char filename[20];
	FILE* fbmi;

	int today;

	today = date_to_file_name();

	sprintf(filename, "%d.txt", today);

	// ���� ���� �õ�
	fbmi = fopen(filename, "r");

	if (fbmi == NULL) {
		// ������ �������� ������ ����� �Ǿ����� ���� ��
		bmi_calculation(name);

		return 0;
	}
	else {
		// ������ �����ϸ� �̹� ��ϵ� ��
		fclose(fbmi);

		printf("\n\n������ �̹� ��ü ����� �߽��ϴ�.\n");

		return 1;
	}
}