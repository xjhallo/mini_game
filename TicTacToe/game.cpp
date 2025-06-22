#include"game.h"
#include<ctime>
//��ʼ������
void InitBoard(char board[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//��ӡ����
void DisplayBoard(char board[ROW][COL])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
			printf("---+---+---\n");
	}
}
//�������
void PlayerMove(char board[ROW][COL])
{
	int x = 0, y = 0;
	printf("Player��turn, please enter your move (row and column): ");
	scanf_s("%d %d", &x, &y);
	while (x < 1 || x > ROW || y < 1 || y > COL || board[x - 1][y - 1] != ' ')
	{
		printf("Invalid move. Please enter again (row and column): ");
		scanf_s("%d %d", &x, &y);
	}
	board[x - 1][y - 1] = '*';
}
//��������
void ComputerMove(char board[ROW][COL])
{
	printf("Computer's turn...\n");
	int x = 0, y = 0;
    // �������Χ�ܴ��3ȡ�༴�õ�0��2�ķ�Χ
	x = rand() % ROW; 
	y = rand() % COL;
	while (board[x][y] != ' ')
	{
		x = rand() % ROW;
		y = rand() % COL;
	}
	board[x][y] = '#';
}
char IsGameOver(char board[ROW][COL])//�ж���Ӯ
{
	for (int i = 0; i < ROW - 2; i++)//����ÿһ�к�ÿһ��
	{
		for (int j = 0; j < COL - 2; j++)
		{
			//�ж����Ƿ����
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}

			//�ж����Ƿ����
			if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j][i] != ' ')
			{
				return board[j][i];
			}
		}
	}
	//�ж�б���Ƿ����
	for (int i = 0; i < ROW - 2; i++)
	{
		for (int j = 0; j < COL - 2; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 1][j + 1] != ' ')
			{
				return board[i + 1][j + 1];
			}

			if (board[i][ROW - j + 1] == board[i + 1][ROW - j] && board[i + 1][ROW - j] == board[i + 2][ROW - j - 1] && board[i + 1][ROW - j] != ' ')
			{
				return board[i + 1][ROW - j];
			}
		}
	}
	//��������Ƿ�������������ǣ��򷵻� u
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			if (board[i][j] == ' ')
			{
				return ' ';
			}
		}
	}

	return 'Q';
}