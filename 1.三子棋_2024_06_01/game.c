#include "game.h"
//初始化棋盘
void Init_board(char (*p)[COL],int row,int col)
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
		{
			p[i][j] = ' ';
		}
	}
}
void Display_board(char(*p)[COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		for (int j = 0; j < col; j++)
		{
			if ((col - 1) == j)
			{
				printf(" %c ", p[i][j]);
				break;
			}
			printf(" %c |", p[i][j]);
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				if ((col - 1) == j)
				{
					printf("---");
					break;
				}
				printf("---|");
			}
		}
		printf("\n");
	}
}
//   |   |
//---|---|---
//   |   |   
//---|---|---
//   |   |
//打印棋盘
//玩家走
void Player_move(char(*p)[COL], int row, int col)
{
	int x, y;
	if (Is_full(p))
	{
		printf("board is full!\n");
		return;
	}
	else
	while (1)
	{
		printf("Please input x&y: ");
		scanf("%d%d",&x,&y);
		if (p[x - 1][y - 1] == ' ')
		{
			p[x - 1][y - 1] = '#';
			return;
		}
		else
		{
			printf("Error,Please input again!\n");
			continue;
		}
	}
	
}
//电脑走
void Computer_move(char(*p)[COL], int row, int col)
{
	while (!Is_full(p))
	{
		int x = rand() % row;
		int y = rand() % col;
		if (p[x][y] == ' ')
		{
			p[x][y] = '*';
			return;
		}
		else
			continue;
	}
	/*printf("board is full!\n");*/
}
//判断输赢
char Is_win(char(*p)[COL], int row, int col)
{
	int count = 0;
	char ret = 'C';
	//判断横行
	for (int i = 0; i < row; i++)
	{
		int count = 0;
		int j = 0;
		for (int j = 0; j < col; j++)
		{
			if (p[i][j] == '#')
				count++;
			else if (p[i][j] == '*')
				count--;
		}
		if (count == col || count == -col)
		{
			ret = p[i][j];
			break;
		}
		else
			continue;
	}
	//判断竖行
	for (int i = 0; i < row; i++)
	{
		int count = 0;
		int j = 0;
		for (int j = 0; j < col; j++)
		{
			if (p[j][i] == '#')
				count++;
			else if (p[j][i] == '*')
				count--;
		}
		if (count == row || count == -row)
		{
			ret = p[j][i];
			break;
		}
		else
			continue;
	}
	//判断对角
	
	for (int i = 0; i < row-1; i++)
	{
		count = 0;
		for (int j = col-1; 0 < j; j--)
		{
			if (p[i][i] = p[i + 1][i + 1])
			{
				count++;
			}
			else if (p[i][j] = p[i + 1][j - 1])
				count--;
		}
		if (count == row - 1 || count == -(row - 1))
		{
			ret = p[row - 1][col - 1];
			break;
		}
		else
			continue;
	}
	if (ret == 'C')
	{
		return 'C';
	}
	else if (Is_full(p))
	{
		return 'Q';
	}
	else
		return ret;
}
//棋盘是否已满
int Is_full(char(*p)[COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (p[i][j] == ' ')
			{
				return 0;
				break;
			}	
		}
	}
	return 1;
}
void game()
{
	char arr[ROW][COL] = {0};
	Init_board(arr,ROW,COL);//初始化棋盘
	printf("纷争开始！\n");
	Display_board(arr, ROW, COL);//打印棋盘
	while (1)
	{
		char ret = 0;
		//玩家走
		Player_move(arr, ROW, COL);
		Display_board(arr, ROW, COL);
		printf("************\n");
		/*ret = Is_win(arr, ROW, COL);*/
		//电脑走
		Computer_move(arr, ROW, COL);
		//打印棋盘Display_board(arr, ROW, COL);
		Display_board(arr, ROW, COL);
		//判断输赢
		ret = Is_win(arr, ROW, COL);
		if (ret == '#')
		{
			printf("Player is winner!\n");
			return;
		}
		else if (ret == '*')
		{
			printf("Computer is winner!\n");
			return;
		}
		else if (ret == 'Q')
		{
			printf("难分伯仲！\n");
			return;
		}
		else
			continue;
	}
}