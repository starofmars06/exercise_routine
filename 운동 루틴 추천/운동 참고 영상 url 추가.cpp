#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void daily_routine(char name[]) {
	int choice;   // ���ð�
	int choice1, choice2, choice3, choice4; // � ��ǥ�� ���� � ���� ���ð�
	int c;

	printf("\n*******************\n");
	printf("���� �ִ� � ��ǥ�� �����Ͻø� %s�Բ� �˸´� � ��ƾ�� ��õ�帮�ڽ��ϴ�.\n", );

	// � ��ǥ ��� ���
	printf("\n� ��ǥ�� �����ϼ���.\n");
	printf("1. ���������� ���\n2. ������ ���\n3. ������ ����\n4. ü���� ����\n");
	printf("\n������ � ��ǥ: ");
	// ���ð� �Է�
	c = scanf("%d", &choice);

	// ���� ó�� - ���ڰ� �ƴ� �Է� Ȥ�� �������� ���� ���� �Է� ��

	if (c != 1 || choice < 1 || choice > 4) {

		// ��� ��� �� ó������ �ٽ� ����
		printf("���! �ùٸ� ���� �Է��ϼ���.\n");
		while ((c = getchar()) != '\n' && c != EOF);  // �߸��� �Է°� ����ֱ�
		daily_routine(name);  // ��� ȣ�� (daily_routine �Լ� ó������ �ٽ� ����)
	}
	// �Է¹��� ���ð��� ���� �ش� ��ȣ�� � ���
	switch (choice)
	{
	case 1: // ���� ������ ���
		printf("\n[���� ������ ���]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1: �ȱ� \n2: ��� \n3: �ٳѱ� \n4: ������ \n5: ��� ������ \n6: ���͹� Ʈ���̴� \n");
		printf("\n������ �: ");
		scanf("%d", &choice1);
		// ���ϴ� � ��ȣ�� ���� � ���� ���
		switch (choice1)
		{
		case 1:
			printf("\n[�ȱ�]��� �����ϼ̽��ϴ�.\n");
			printf("����: �ۿ��� �Ȱų�, �ǳ����� Ʈ������� �̿��ؼ� �ɾ�ô�.\n");
			printf("�ð�: 30�� �̻�\n");
			printf("���� ����: �ٸ��� �ȴ� ��� https://youtu.be/rVoB0heVow0?si=QsUqPhefBghZ_jDy");
			break;
		case 2:
			printf("\n[���]��� �����ϼ̽��ϴ�. \n");
			printf("����: ��ó ��, �긲, Ȥ�� ���θ� ã�� ���ȭ�� ���� ���� �԰� ���� ��������.\n");
			printf("�ð�: 30�� ~ 2�ð� �̻�\n");
			printf("���� ����:����� �� �ùٸ� ����� https://youtu.be/NTEaUa8SSpM?si=maVK23YRfzmlr1b-" 
 );
			break;
		case 3:
			printf("\n[�ٳѱ�]��� �����ϼ̽��ϴ�. \n");
			printf("����: ���� ������ ���� ������ �����̸� ���, ���� ���� ���÷� ���� �Ѿ� �پ� �ѱ⼼��.\n");
			printf("�ð�: 30��~1�ð�\n");
			printf("���� ����: https://youtu.be/_yWerNDS2AQ?si=KbnH8guZX_JJ0Oa1");
			break;
		case 4:
			printf("\n[������]��� �����ϼ̽��ϴ�. \n");
			printf("����: ���� �ӵ��� �̵��ϸ鼭 �������� ��Ʋ���� ġ����. ����� ������ �Ѵٸ�, ���� ��Ʋ���� �������� �ְ� ���� �� �ֽ��ϴ�.\n");
			printf("�ð�: 1�ð� �̻�\n");
			printf("���� ����:https://youtu.be/giXK9YAeJEI?si=nKTfS_rM72A3MSHe");
			break;
		case 5:
			printf("\n[��� ������]��� �����ϼ̽��ϴ�. \n");
			printf("����: �ǹ� ���� �Ǵ� �߿��� ����� ���������⸦ �ݺ��ϼ���.\n");
			printf("�ð�: 30�� �̻�\n");
			printf("���� ����: ȿ������ ������� ����� ������ ��� https://youtu.be/5K_-Bz9VfHw?si=NUUht0hmxaZG7lx0");
			break;
		case 6:
			printf("\n[���͹� Ʈ���̴�]��� �����ϼ̽��ϴ�. \n");
			printf("����: 5���� ���־� �� 8~10�� �ӵ��� 3�а� �޸��ϴ�. �� �� 5~6�� �ӵ��� 2�а� �Ƚ��ϴ�. �ش� ��ƾ�� 30�е��� �ݺ��� �� �� �ٿ��� �� 5~10�а� õõ�� �Ƚ��ϴ�. \n�ڽ��� ü�� ���ؿ� ���� �ӵ��� �ð��� �����Ͽ� �����սô�.\n");
			printf("�ð�: 30�� �̻�\n");
			printf("���� ����:https://youtu.be/RKcfpPNlMvE?si=z6nWkIUmKrZNBclu");
			break;
		}
		break;
	case 2: //������ ���
		printf("\n[������ ���]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.�ݴ� �ڼ� \n2: ������ �ڼ� \n3: ���� �ڼ� \n4:�ʶ��׽� \n5: �ٸ� ����");
		printf("\n������ �: ");
		scanf("%d", &choice2);
		switch (choice2)
		{
		case 1:
			printf("\n[�ݴ� �ڼ�]��� �����ϼ̽��ϴ�. \n");
			printf("����: ���� �� ������ ��￩ �ϳ��� ���� �ٴڿ� ���� �ٸ� ���� õ�� ������ ��� �����ϴٰ� ������ �ٲ߽ô�.");
			printf("�ð�: 30�� ~ 1��\n");
			printf("���� ����:https://youtu.be/E93q2CDmp14?si=O0PUMTEwNRqx9RbS");
			break;
		case 2:
			printf("\n[������ �ڼ�]��� �����ϼ̽��ϴ�. \n");
			printf("����:�������� ���� ������ �� �Ȳ�ġ�� �����ϰ� �� �չٴ��� �´굵�� �մϴ�. \n������ �ٸ��� ��Ʋ�� �������� ���� ���Ƹ��� ��ģ ���·� �����ϴٰ� ������ �ٲ߽ô�. \n");
			printf("�ð�: 30�� ~ 1��\n");
			printf("���� ����:https://youtu.be/0yVcCuc_uGE?si=iWOupRitjG_7uKSP ");
			break;

		case 3:
			printf("\n[���� �ڼ�]��� �����ϼ̽��ϴ�. \n");
			printf("����: �� �� ���� �ݴ��� ����� ���ʿ� ���̰�, �� ���� �Ӹ� ���� �÷� ������ �� ä�� ���� �ڼ��� �����ϴٰ� ������ �ٲ߽ô�.\n");
			printf("�ð�: 1�� ~ 1�� 30��\n");
			printf("���� ����:https://youtu.be/TptsloulelU?si=EyVohJpO7mhmq-H2");
			break;
		case 4:
			printf("\n[�ʶ��׽�]��� �����ϼ̽��ϴ�. \n");
			printf("����: �ʶ��׽� ��Ʈ�� ����Ͽ� �پ��� ������ �����ϰų�, �ʶ��׽� �ⱸ�� Ȱ���սô�. \n");
			printf("�ð�: 30�� ~ 1�ð� \n");
			printf("���� ����:https://youtu.be/L5QnCr_vdJE?si=miiZhZyb5_M2xbc3");
			break;
		case 5:
			printf("\n[�ٸ� ����]��� �����ϼ̽��ϴ�. \n");
			printf("����: �ٸ��� ������ ���� �ִٰ� õõ�� �¿�� �����ϴ�. \n");
			printf("���� ����:https://youtu.be/MYdr0deU5N4?si=Ez9h_3KQExrR102M");
			break;
		}
		break;
	case 3: //���� ����
		printf("\n[���� ����]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.����Ʈ \n2.���帮��Ʈ \n3.��ġ������ \n4.�ȱ������ \n5.���� ����Ű�� \n6.Ǯ�� \n");
		printf("\n���ϴ� �: ");
		scanf("%d", &choice3);
		switch (choice3)
		{
		case 1:
			printf("\n[����Ʈ]��� �����ϼ̽��ϴ�.\n");
			printf("����: ��� �ʺ�� �ٸ��� ���� ��, ��� �ڷ� ���� ������ ������, 90�� ������ �̸� ������ �������ϴ�. ���� �����̸� ���� �÷� �ʱ� ��ġ�� ���ư��ϴ�.\n");
			printf("�ð�: 15 ~ 30��(10~15ȸ �ݺ�)\n");
			printf("���� ����:https://youtu.be/fy9URmTqNio?si=8MubMXaGBXLmGgB8");
			break;
		case 2:
			printf("\n[���帮��Ʈ]��� �����ϼ̽��ϴ�.\n");
			printf("����: �ٺ��� ���߾ӿ� ���� ���� ��� �ʺ�� ������, �ٺ��� ��� �ʺ񺸴� ��¦ �а� ����ϴ�. �ü��� �Ʒ� �缱�������� �ϰ� �㸮�� �������� �ʰ� �� ���·� �ٺ��� ���ø��ϴ�.\n��ü�� ������ �������� �ٺ��� �ø��� ���� �����ʹ� ���� ������ ���ø��ϴ�\n");
			printf("�ݺ�: 6 ~ 10ȸ\n");
			printf("���� ����:https://youtu.be/EBjYQeeBI-0?si=fZ1gasghn-ZRCTge");
			break;
		case 3:
			printf("\n[��ġ ������]��� �����ϼ̽��ϴ�.\n");
			printf("����: �̽���Ʈ �ٺ� �Ǵ� ������ ����Ͽ� ������ ��� �ø��� ������ ������ �ݺ��մϴ�.\n");
			printf("�ݺ�: 3��Ʈ(8 ~ 12ȸ)\n");
			printf("���� ����:https://youtu.be/0DsXTSHo3lU?si=_qOT7u-ZiMAYnVP5");
			break;
		case 4:
			printf("\n[�ȱ������]��� �����ϼ̽��ϴ�.\n");
			printf("����: ���� ��� �ʺ�� ���� ���� �ٴڰ� �����ϰ� ���ø��� �ٽ� ������ ������ �ݺ��մϴ�\n");
			printf("���� ����:https://youtu.be/-_DUjHxgmWk?si=o1ukxpoBJRzOdseA");
			break;
		case 5:
			printf("\n[���� ����Ű��]��� �����ϼ̽��ϴ�.\n");
			printf("����: ���� ��Ʈ�� ���� ���� �� �ڿ� �ΰ� ��ü�� ���÷� �ٽ� �������� ������ �ݺ��մϴ�\n");
			printf("�ݺ�: 3��Ʈ(15 ~ 20ȸ)\n");
			printf("���� ����:https://youtu.be/kWKqlIKnIG0?si=X6-hqBvlAK1uLCEY");
			break;
		case 6:
			printf("\n[Ǯ��]��� �����ϼ̽��ϴ�.\n");
			printf("����: �Ȳ�ġ�� �� ���¿��� ����ʺ񺸴� ���� �� �а� �ٸ� ���� �� ������ ���� ��¦ ����ְ� ����� �����ϴ�. �״�� ������ �ٿ� ��ġ�Ѵٴ� �������� ��ܿø��ϴ�.\n��ü �ٷ��� ���� ���̶�� ����� ������ �����ô�.\n");
			printf("���� ����:https://youtu.be/nWhS28U6bCY?si=S3j7U4EYrv-XAOcY");
			break;
		}
		break;
	case 4:
		printf("\n[ü���� ����]�� ��ǥ�� �����ϼ̽��ϴ�.\n");
		printf("�Ʒ� ��� �� ���ϴ� ��� ��ȣ�� �����ϼ���.\n");
		printf("1.���� \n2.�޸��� \n3.������Ÿ�� \n4.���� \n5.ũ�ν��� \n6.���� \n");
		printf("\n���ϴ� �: ");
		scanf("%d", &choice4);
		switch (choice4)
		{
		case 1:
			printf("\n[����]��� �����ϼ̽��ϴ�.\n");
			printf("����: �Ź��� �Ű� ����� �Ƿ��� ���� ��, �߿ܳ� Ʈ������ ������ �ӵ��� �ٰų� �ȴ� ���� �ݺ��մϴ�.\n");
			printf("�ð�: 30�� �̻�\n");
			printf("���� ����:https://youtu.be/4OZKcJ_Ze6E?si=Rdgk6ANeKmPd83Zy");
			break;
		case 2:
			printf("\n[�޸���]��� �����ϼ̽��ϴ�.\n");
			printf("����: ������ �Ź��� �Ű�, ���� Ʈ���̳� �ڿ� ȯ�濡�� �ִ��� ���� �ӵ��� �޸�����.\n");
			printf("�ð�: 20�� �̻�\n");
			printf("���� ����:https://youtu.be/th7Wi9DsmFo?si=eX_XuLisgdLFsY82");
			break;
		case 3:
			printf("\n[������Ÿ��]��� �����ϼ̽��ϴ�.\n");
			printf("����: �����Ÿ� Ÿ�� ����, ������ ����, Ȥ�� ������ Ʈ������ ���� �̵��ϼ���. \n");
			printf("�ð�: 45�� �̻�\n");
			printf("���� ����:https://youtu.be/M9vqn0R9HmE?si=hJxua2LB7Fh-MP-L ");
			break;
		case 4:
			printf("\n[����]��� �����ϼ̽��ϴ�.\n");
			printf("����: �������̳� �ڿ� �����忡�� ������, ����, � ������ ��Ʈ��ũ�� �����ϼ���.\n");
			printf("�ð�: 30�� ~ 1�ð�\n");
			printf("���� ����:https://youtu.be/7PqEAls1wjE?si=tx4FXGP6qx7CZusA ");
			break;
		case 5:
			printf("\n[ũ�ν���]��� �����ϼ̽��ϴ�.\n");
			printf("����: ũ�ν��� ��Ʈ�Ͻ� ���Ϳ��� �پ��� ����Ʈ ������, �����, ü�� ��� �����ϼ���\n");
			printf("�ð�: 1�ð� �̻�\n");
			printf("���� ����:https://youtu.be/7oGstYEb-_k?si=gYyBOccRRkt03wRP");
			break;
		case 6:
			printf("\n[����]��� �����ϼ̽��ϴ�.\n");
			printf("����: ���� ��Ʈ�Ͻ� ���Ϳ��� �Ʒ��� �ްų� ���� ������ ����Ͽ� �⺻ ���� ����� �����ϼ���.\n");
			printf("�ð�: 30�� ~ 1�ð�\n");
			printf("���� ����:");
			printf("���� https://youtu.be/8YR-B7FL43E?si=i1Ua0TZx6FFrEuAb");
			printf("���� https://youtu.be/4THFtd5K5TI?si=rD-dObdshI1DpgJJ");
			break;
		}
		break;
	}
}