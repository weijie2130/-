//三子棋游戏

#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
//菜单 ，是否要一直玩下去
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
	//设计一个三子棋，开一个数组存储数据
	char board[ROW][COL] = { 0 };//数组初始化为空格
	InitBoard(board, ROW, COL);//初始化棋盘 -空格
	DisplayBoard(board, ROW, COL);//打印棋盘
	//会出现四种情况
	//1.玩家赢 返回值*
	//2.电脑赢 #
	//3.平局 Q
	//4.继续 C
	
	while (1)
		{
			PlayerMove(board, ROW, COL);
			//判断输赢
			ret = CheckWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);

			ComputerMove(board, ROW, COL);
			//判断输赢
			ret = CheckWin(board, ROW, COL);
			
			if (ret != 'C')
			{
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
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
		printf("请输入你的选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//三子棋游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);//只要是1就一直执行；
		return 0;
}