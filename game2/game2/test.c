//��������Ϸ

#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
//�˵� ���Ƿ�Ҫһֱ����ȥ
void menu()
{
	printf("****************\n");
	printf("**   1.p1ay   **\n");
	printf("**   0.exit   **\n");
	printf("****************\n");

}
void game()
{
	char ret = 0;
	//���һ�������壬��һ������洢����
	char board[ROW][COL] = { 0 };//�����ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);//��ʼ������ -�ո�
	DisplayBoard(board, ROW, COL);//��ӡ����
	//������������
	//1.���Ӯ ����ֵ*
	//2.����Ӯ #
	//3.ƽ�� Q
	//4.���� C
	
	while (1)
		{
			PlayerMove(board, ROW, COL);
			//�ж���Ӯ
			ret = CheckWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);

			ComputerMove(board, ROW, COL);
			//�ж���Ӯ
			ret = CheckWin(board, ROW, COL);
			
			if (ret != 'C')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
	}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("���������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);//ֻҪ��1��һֱִ�У�
		return 0;
}