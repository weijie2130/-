#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-------------------------\n");
	//列号的打印
	for (i = 0; i <= col; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	//1.随机布置雷
	//布置10个雷
	int count = EASY_COUNT;
	while (count)
	{
		//布置一个雷，count--
		//随机产生一个雷，生成一个随机坐标行1-9 列1-9
		int x = rand() % row+1;//模9得到0-8
		int y = rand() % row + 1;
		//2.布置
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

 int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	 return mine[x-1][y] +
		 mine[x-1][y-1] +
		 mine[x-1][y+1] +
		 mine[x][y-1] +
		 mine[x][y+1] +
		 mine[x+1][y-1] +
		 mine[x + 1][y] +
		 mine[x + 1][y+1] - 8 * '0';//ASCAL码的值
		 
}
 //扫雷如何结束？
 //1.炸死
 //2.扫雷成功



void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{

	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL - EASY_COUNT)
	{
		printf("请输入要排查的雷的坐标：>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			//判断x,y坐标处是否有雷
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//x,y坐标处不是雷，统计周围有几个雷
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
	if (win == ROW*COL - EASY_COUNT)
	{
		printf("恭喜您，游戏成功\n");
		DisplayBoard(mine, row, col);
	}



}