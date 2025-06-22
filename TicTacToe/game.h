#pragma once
#define ROW 3
#define COL 3
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void InitBoard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
char IsGameOver(char board[ROW][COL]);
