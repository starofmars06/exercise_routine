#include "common.h"

//3. � ���� ����
void daily_routine(char* name) {
	int choice;   // ���ð�
	int choice1, choice2, choice3, choice4; // � ��ǥ�� ���� � ���� ���ð�
	int c;

	char exercise_name[MAX_STRING_LENGTH]; // � �̸�
	char descr[MAX_STRING_LENGTH];     // � ����
	char time[MAX_STRING_LENGTH];      // � �ð�
	char level[MAX_STRING_LENGTH];     // � ����
	int cal;                           // ���� �Ҹ� Į�θ�
	char url[MAX_STRING_LENGTH];       // � ���� �ּ�

	printf("\n*******************\n");
	printf("���� �ִ� � ��ǥ�� �����Ͻø� %s�Բ� �˸´� � ��ƾ�� ��õ�帮�ڽ��ϴ�.\n", name);

	// � ��ǥ ��� ���
	printf("\n� ��ǥ�� �����ϼ���.\n");
	printf("1. ���������� ���\n2. ������ ���\n3. ������ ����\n4. ü���� ����\n");
	printf("\n������ � ��ǥ: ");
	// ���ð� �Է�
	c = scanf("%d", &choice);

	// ���� ó�� - ���ڰ� �ƴ� �Է� Ȥ�� �������� ���� ���� �Է� ��

	if (c != 1 || choice < 1 || choice > 4) {

		// ��� ��� �� ó������ �ٽ� ����
		printf(":::�ùٸ� ���� �Է��ϼ���:::\n");
		while ((c = getchar()) != '\n' && c != EOF);  // �߸��� �Է°� ����ֱ�
		daily_routine(name);  // ��� ȣ�� (daily_routine �Լ� ó������ �ٽ� ����)
	}
	// �Է¹��� ���ð��� ���� �ش� ��ȣ�� � ���
	switch (choice)
	{
	case 1: // ���� ������ ���
		printf("\n*******************\n");
		printf("\n[���� ������ ���]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1: �ȱ� \n2: ��� \n3: �ٳѱ� \n4: ������ \n5: ��� ������ \n6: ���͹� Ʈ���̴� \n");
		printf("\n������ �: ");
		scanf("%d", &choice1);
		// ���ϴ� � ��ȣ�� ���� � ���� ���
		switch (choice1)
		{
		case 1:
			strcpy(exercise_name, "�ȱ�");
			strcpy(descr, "�ۿ��� �Ȱų�, �ǳ����� Ʈ������� �̿��ؼ� �ɾ�ô�.");
			strcpy(time, "30�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 110;
			strcpy(url, "� ȿ���� ���̱� ���� �ٸ��� �ȴ� ���\n	   https://youtu.be/rVoB0heVow0?si=QsUqPhefBghZ_jDy");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "���");
			strcpy(descr, "��ó ��, �긲, Ȥ�� ���θ� ã�� ���ȭ�� ���� ���� �԰� ���� ��������.");
			strcpy(time, "30�� ~ 2�ð� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 204;
			strcpy(url, "����� �� �ùٸ� �����\n	   https://youtu.be/NTEaUa8SSpM?si=maVK23YRfzmlr1b-");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "�ٳѱ�");
			strcpy(descr, "���� ������ ���� ������ �����̸� ���, ���� ���� ���÷� ���� �Ѿ� �پ� �ѱ⼼��.");
			strcpy(time, "30��~1�ð�");
			// �� ����
			strcpy(level, "��");
			cal = 371;
			strcpy(url, "�ٳѱ� �ʺ��ڸ� ���� ������ ����\n	   https://youtu.be/_yWerNDS2AQ?si=KbnH8guZX_JJ0Oa1");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "������");
			strcpy(descr, "���� �ӵ��� �̵��ϸ鼭 �������� ��Ʋ���� ġ����. ����� ������ �Ѵٸ�, ���� ��Ʋ���� �������� �ְ� ���� �� �ֽ��ϴ�.");
			strcpy(time, "1�ð� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 246;
			strcpy(url, "������ �Թ��ڿ� ���� ����\n	   https://youtu.be/giXK9YAeJEI?si=nKTfS_rM72A3MSHe");

			exercise_details(exercise_name, descr, time, level, cal, url);
		case 5:
			strcpy(exercise_name, "��� ������");
			strcpy(descr, "�ǹ� ���� �Ǵ� �߿��� ����� ���������⸦ �ݺ��ϼ���.");
			strcpy(time, "30�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 261;
			strcpy(url, "ȿ�������� ��ܿ����� � �ϴ� ���\n	   https://youtu.be/5K_-Bz9VfHw?si=QPudFsNtw9pQxmgs");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "���͹� Ʈ���̴�");
			strcpy(descr, "5���� ���־� �� 8~10�� �ӵ��� 3�а� �޸��ϴ�. �� �� 5~6�� �ӵ��� 2�а� �Ƚ��ϴ�. �ش� ��ƾ�� 30�е��� �ݺ��� �� �� �ٿ��� �� 5~10�а� õõ�� �Ƚ��ϴ�. \n�ڽ��� ü�� ���ؿ� ���� �ӵ��� �ð��� �����Ͽ� �����սô�.");
			strcpy(time, "30�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 157;
			strcpy(url, "���͹�Ʈ���̴��� ����� ȿ��\n	   https://youtu.be/RKcfpPNlMvE?si=z6nWkIUmKrZNBclu");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 2: //������ ���
		printf("\n*******************\n");
		printf("\n[������ ���]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.�ݴ� �ڼ� \n2: ������ �ڼ� \n3: ���� �ڼ� \n4:�ʶ��׽� \n5: �ٸ� ����");
		printf("\n������ �: ");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			strcpy(exercise_name, "�ݴ� �ڼ�");
			strcpy(descr, "���� �� ������ ��￩ �ϳ��� ���� �ٴڿ� ���� �ٸ� ���� õ�� ������ ��� �����ϴٰ� ������ �ٲ߽ô�.");
			strcpy(time, "30�� ~ 1��");
			// �� ����
			strcpy(level, "��");
			cal = 30;
			strcpy(url, "�ݴ��ڼ� �ϴ� ���\n	   https://youtu.be/E93q2CDmp14?si=O0PUMTEwNRqx9RbS");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "������ �ڼ�");
			strcpy(descr, "�������� ���� ������ �� �Ȳ�ġ�� �����ϰ� �� �չٴ��� �´굵�� �մϴ�. \n������ �ٸ��� ��Ʋ�� �������� ���� ���Ƹ��� ��ģ ���·� �����ϴٰ� ������ �ٲ߽ô�.");
			strcpy(time, "30�� ~ 1��");
			// �� ����
			strcpy(level, "��");
			cal = 30;
			strcpy(url, "�������ڼ� �ϴ� ���\n		https://youtu.be/0yVcCuc_uGE?si=iWOupRitjG_7uKSP");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;

		case 3:
			strcpy(exercise_name, "���� �ڼ�");
			strcpy(descr, "�� �� ���� �ݴ��� ����� ���ʿ� ���̰�, �� ���� �Ӹ� ���� �÷� ������ �� ä�� ���� �ڼ��� �����ϴٰ� ������ �ٲ߽ô�.");
			strcpy(time, "1�� ~ 1�� 30��");
			// �� ����
			strcpy(level, "��");
			cal = 30;
			strcpy(url, "�����ڼ� �ϴ� ���\n	   https://youtu.be/TptsloulelU?si=EyVohJpO7mhmq-H2");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "�ʶ��׽�");
			strcpy(descr, "�ʶ��׽� ��Ʈ�� ����Ͽ� �پ��� ������ �����ϰų�, �ʶ��׽� �ⱸ�� Ȱ���սô�.");
			strcpy(time, "30�� ~ 1�ð�");
			// �� ����
			strcpy(level, "��");
			cal = 30;
			strcpy(url, "������ �ϴ� �����ʶ��׽� 20���� ����\n	   https://youtu.be/L5QnCr_vdJE?si=miiZhZyb5_M2xbc3");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "�ٸ� ����");
			strcpy(descr, "�ٸ��� ������ ���� �ִٰ� õõ�� �¿�� �����ϴ�.");
			strcpy(time, "30�� ~ 1��");
			// �� ����
			strcpy(level, "��");
			cal = 30;
			strcpy(url, "�ٸ� ���� �ø��� ���\n	   https://youtu.be/MYdr0deU5N4?si=Ez9h_3KQExrR102M");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 3: //���� ����
		printf("\n*******************\n");
		printf("\n[���� ����]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.����Ʈ \n2.���帮��Ʈ \n3.��ġ������ \n4.�ȱ������ \n5.���� ����Ű�� \n6.Ǯ�� \n");
		printf("\n���ϴ� �: ");
		scanf("%d", &choice3);
		switch (choice3)
		{
		case 1:
			strcpy(exercise_name, "����Ʈ");
			strcpy(descr, "��� �ʺ�� �ٸ��� ���� ��, ��� �ڷ� ���� ������ ������, 90�� ������ �̸� ������ �������ϴ�. ���� �����̸� ���� �÷� �ʱ� ��ġ�� ���ư��ϴ�.");
			strcpy(time, "15 ~ 30��(10~15ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 147;
			strcpy(url, "����Ʈ �ùٸ� �ڼ� ����\n	   https://youtu.be/fy9URmTqNio?si=8MubMXaGBXLmGgB8");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "���帮��Ʈ");
			strcpy(descr, "�ٺ��� ���߾ӿ� ���� ���� ��� �ʺ�� ������, �ٺ��� ��� �ʺ񺸴� ��¦ �а� ����ϴ�. �ü��� �Ʒ� �缱�������� �ϰ� �㸮�� �������� �ʰ� �� ���·� �ٺ��� ���ø��ϴ�.\n��ü�� ������ �������� �ٺ��� �ø��� ���� �����ʹ� ���� ������ ���ø��ϴ�.");
			strcpy(time, "15 ~ 30��(6~10ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 100;
			strcpy(url, "���帮��Ʈ �ùٸ��� �ϴ� ��� ����\n	   https://youtu.be/EBjYQeeBI-0?si=fZ1gasghn-ZRCTge");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "��ġ ������");
			strcpy(descr, "�̽���Ʈ �ٺ� �Ǵ� ������ ����Ͽ� ������ ��� �ø��� ������ ������ �ݺ��մϴ�.");
			strcpy(time, "10 ~ 20��(8~12ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 50;
			strcpy(url, "��ġ������ �ùٸ��� �ϴ� ��� ����\n	   https://youtu.be/0DsXTSHo3lU?si=_qOT7u-ZiMAYnVP5");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "�ȱ������");
			strcpy(descr, "���� ��� �ʺ�� ���� ���� �ٴڰ� �����ϰ� ���ø��� �ٽ� ������ ������ �ݺ��մϴ�.");
			strcpy(time, "10�� (15~20ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 49;
			strcpy(url, "�ȱ������ �ڼ� �� ȿ�� ����\n	   https://youtu.be/-_DUjHxgmWk?si=o1ukxpoBJRzOdseA");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "���� ����Ű��");
			strcpy(descr, "���� ��Ʈ�� ���� ���� �� �ڿ� �ΰ� ��ü�� ���÷� �ٽ� �������� ������ �ݺ��մϴ�.");
			strcpy(time, "10�� (15~20ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 98;
			strcpy(url, "��������Ű�� ���� ���� �ùٸ��� �ϴ� ��� ����\n	   https://youtu.be/kWKqlIKnIG0?si=X6-hqBvlAK1uLCEY");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "Ǯ��");
			strcpy(descr, "�Ȳ�ġ�� �� ���¿��� ����ʺ񺸴� ���� �� �а� �ٸ� ���� �� ������ ���� ��¦ ����ְ� ����� �����ϴ�. �״�� ������ �ٿ� ��ġ�Ѵٴ� �������� ��ܿø��ϴ�.\n��ü �ٷ��� ���� ���̶�� ����� ������ �����ô�.");
			strcpy(time, "10�� (10~15ȸ �ݺ�)");
			// �� ����
			strcpy(level, "��");
			cal = 15;
			strcpy(url, "Ǯ�� �ڼ� ����\n	   https://youtu.be/nWhS28U6bCY?si=S3j7U4EYrv-XAOcY");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	case 4:
		printf("\n*******************\n");
		printf("\n[ü���� ����]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.���� \n2.�޸��� \n3.������Ÿ�� \n4.���� \n5.ũ�ν��� \n6.���� \n");
		printf("\n���ϴ� �: ");
		scanf("%d", &choice4);
		switch (choice4)
		{
		case 1:
			strcpy(exercise_name, "����");
			strcpy(descr, "�Ź��� �Ű� ����� �Ƿ��� ���� ��, �߿ܳ� Ʈ������ ������ �ӵ��� �ٰų� �ȴ� ���� �ݺ��մϴ�.");
			strcpy(time, "30�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 220;
			strcpy(url, "� ȿ�� ���̴� ���� ���\n	   https://youtu.be/4OZKcJ_Ze6E?si=Rdgk6ANeKmPd83Zy");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 2:
			strcpy(exercise_name, "�޸���");
			strcpy(descr, "������ �Ź��� �Ű�, ���� Ʈ���̳� �ڿ� ȯ�濡�� �ִ��� ���� �ӵ��� �޸�����.");
			strcpy(time, "20�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 230;
			strcpy(url, "ȿ�������� �޸� �� �ִ� �ڼ��� ȣ�� ���\n	   https://youtu.be/th7Wi9DsmFo?si=eX_XuLisgdLFsY82");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 3:
			strcpy(exercise_name, "������Ÿ��");
			strcpy(descr, "�����Ÿ� Ÿ�� ����, ������ ����, Ȥ�� ������ Ʈ������ ���� �̵��ϼ���.");
			strcpy(time, "45�� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 366;
			strcpy(url, "������ Ÿ�� ��� ����\n	   https://youtu.be/M9vqn0R9HmE?si=hJxua2LB7Fh-MP-L");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 4:
			strcpy(exercise_name, "����");
			strcpy(descr, "�������̳� �ڿ� �����忡�� ������, ����, � ������ ��Ʈ��ũ�� �����ϼ���.");
			strcpy(time, "30�� ~ 1�ð�");
			// �� ����
			strcpy(level, "��");
			cal = 159;
			strcpy(url, "���� ���� ������ ����\n	   https://youtu.be/7PqEAls1wjE?si=tx4FXGP6qx7CZusA");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 5:
			strcpy(exercise_name, "ũ�ν���");
			strcpy(descr, "ũ�ν��� ��Ʈ�Ͻ� ���Ϳ��� �پ��� ����Ʈ ������, �����, ü�� ��� �����ϼ���.");
			strcpy(time, "1�ð� �̻�");
			// �� ����
			strcpy(level, "��");
			cal = 270;
			strcpy(url, "ũ�ν��� �⺻ ���� ����\n	   https://youtu.be/7oGstYEb-_k?si=gYyBOccRRkt03wRP");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		case 6:
			strcpy(exercise_name, "����");
			strcpy(descr, "���� ��Ʈ�Ͻ� ���Ϳ��� �Ʒ��� �ްų� ���� ������ ����Ͽ� �⺻ ���� ����� �����ϼ���.");
			strcpy(time, "30�� ~ 1�ð�");
			// �� ����
			strcpy(level, "��");
			cal = 245;
			strcpy(url, "�⺻ ���� �ϴ� ��� ����\n	   https://youtu.be/4THFtd5K5TI?si=rD-dObdshI1DpgJJ");

			exercise_details(exercise_name, descr, time, level, cal, url);
			break;
		}
		break;
	}


	//----------------------------------------------------------
	//���� ��¥���� Ȯ���ϱ�
	date = date_to_file_name();

	chosen_routine_save(date, exercise_name);
	printf("\n\n ������ ��� : %s �Դϴ�.\n\n", exercise_name);




}

// ��� ���
void exercise_details(char exercise_name[], char descr[], char time[], char level[], int cal, char url[]) {

	printf("\n*******************\n");
	printf("\n[%s]��� �����ϼ̽��ϴ�.\n", exercise_name);
	printf("����: %s\n", descr);
	printf("�ð�: %s\n", time);
	printf("\n***�� ����***\n");
	printf("����: %s\n", level);
	printf("���� �Ҹ� Į�θ��� %dkcal �Դϴ�.\n", cal);
	printf("���� ����: %s\n", url);
}


// bmi ��ü ������ ����� ���Ͽ�
// � �ð��� �������� �߰��ؼ� ����ϰ��� ��.
void chosen_routine_save(int date, char* exercise_name) {
	char filename[20];
	FILE* fbmi;

	//�ؽ�Ʈ ���� �̸� ����
	sprintf(filename, "%d.txt", date);

	fbmi = fopen(filename, "a");


	//�ؽ�Ʈ ���Ͽ� � ���� ����
	fprintf(fbmi, "%s\n", exercise_name);

	// ���� �ݱ�
	fclose(fbmi);

	printf("\n\n� ����� ���������� ����Ǿ����ϴ�.\n");
}