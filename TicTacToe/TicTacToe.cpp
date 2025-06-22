// TicTacToe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include"game.h"
using namespace std;
void menu()
{
	printf("欢迎来到井字棋游戏\n");
	printf("**** 1.play  0.exit ****\n");
	printf("   请输入你的选择：");
}
void game()
{
	 char ret = 0;
	 char board[ROW][COL] = {0};
	 //初始化棋盘
	 InitBoard(board);
	 DisplayBoard(board);
	 //开始下棋
	 while (1)
	 {
         PlayerMove(board);
	     DisplayBoard(board);
		 ret = IsGameOver(board);
		 if (ret != ' ') break;
	     ComputerMove(board);
	     DisplayBoard(board);
		 ret = IsGameOver(board);
		 if (ret != ' ') break;
	 }
	if(ret == '*') printf("The game is over, you win!\n");
	else if(ret == '#') printf("The game is over, you lose!\n");
	else if(ret == 'Q') printf("The game is over, it is a draw!\n");
	DisplayBoard(board);
}
int main()
{
	int input = 0;
	do
	{
		menu(); //显示菜单
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入吧\n");
			break;
		}
	} while(input);
	return 0;
}
