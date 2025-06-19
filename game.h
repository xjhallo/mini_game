#pragma once
#include<iostream>
using namespace std;
const int ROW = 3, COL = 3;
void InitBoard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
bool IsGameOver(char board[ROW][COL], char& winner);
