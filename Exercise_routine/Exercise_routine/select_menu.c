#include "common.h"


// �޴� ������ ���� ��� ����
void select_menu() {
	int select_menu, choice1;

	SelectMenu:
	printf("\n*******************\n\n");

	printf("� ����� �����Ͻðڽ��ϱ�?\n");
	printf("1. � ��ǥ�� ��ƾ ����\n");
	printf("2. ��ü ���� ��� Ȯ���ϱ�(��¥ ����)     3. �̹��� ��ü ��� Ȯ���ϱ�   \n");
	printf("4. � ��� Ȯ���ϱ�                     5. ���� � ��� Ȯ���ϱ�   \n\n");

	printf("\n\n(*:�׸��ν÷��� 0�� �����ּ���)\n");
	scanf("%d", &select_menu);

	printf("\n*******************\n\n");

	if (select_menu == 1) {
		printf("�� �޴��� � ��ǥ���� ��ƾ�� �����ؼ� ������ Ȯ���ϰ�, � �� ������ �� �� ����� �� �ֽ��ϴ�.\n");
		printf("�����Ͻ÷��� 1��, �ڷ� ������ 2���� �����ּ���.\n\n");

		printf("1�� : ��ϱ�        2�� : �ڷΰ���\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//3. � ���� �����ϱ�
			daily_routine(name);

			//4. � �� ������ ��
			user_feedback();
		}

		goto SelectMenu;
	}
	else if (select_menu == 2) {

		printf("�� �޴��� ��¥���� ����� ��ü������ Ȯ���� �� �ֽ��ϴ�.\n");
		printf("�����Ͻ÷��� 1��, �ڷ� ������ 2���� �����ּ���.\n\n");

		printf("1�� : ��� Ȯ���ϱ�        2�� : �ڷΰ���\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//��¥�� ��ü ��� Ȯ��
			bmi_load();
		}

		goto SelectMenu;
	}
	else if (select_menu == 3) {
		printf("�� �޴��� �̹��޿� ����� ��ü������ ���� �׷����� Ȯ���� �� �ֽ��ϴ�.\n");
		printf("�����Ͻ÷��� 1��, �ڷ� ������ 2���� �����ּ���.\n\n");

		printf("1�� : ��� Ȯ���ϱ�        2�� : �ڷΰ���\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//�̹��� ���� ��ü ��� Ȯ��
			bmi_monthly_record();
		}
		goto SelectMenu;
	}
	else if (select_menu == 4) {
		printf("�� �޴��� ��¥���� ����� ��ü������ Ȯ���� �� �ֽ��ϴ�.\n");
		printf("�����Ͻ÷��� 1��, �ڷ� ������ 2���� �����ּ���.\n\n");

		printf("1�� : ��� Ȯ���ϱ�        2�� : �ڷΰ���\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//��¥�� � ��� Ȯ��
			exercise_load();
		}

		goto SelectMenu;
	}
	else if (select_menu == 5) {
		printf("�� �޴��� �̹��޿� ����� � �ð��� ���� �׷����� Ȯ���� �� �ֽ��ϴ�.\n");
		printf("�����Ͻ÷��� 1��, �ڷ� ������ 2���� �����ּ���.\n\n");

		printf("1�� : ��� Ȯ���ϱ�        2�� : �ڷΰ���\n");
		scanf("%d", &choice1);

		if (choice1 == 1) {
			//�̹��� ���� � �ð� ��� Ȯ��
			exercise_monthly_record();
		}
		goto SelectMenu;
	}
	else if (select_menu == 0) {
		printf("���α׷��� �����մϴ�.\n");
		printf("����� �޽��� �����ּ���, ���õ� �����ϼ̽��ϴ�!\n");
	}

}