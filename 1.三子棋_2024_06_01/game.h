#ifndef __GAME_H__
#define __GAME_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define COL 3
#define ROW 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>
void game();//三子棋游戏
void Init_board(char(*p)[COL], int row, int col);//初始化棋盘
void Display_board(char(*p)[COL], int row, int col);//打印棋盘
void Player_move(char(*p)[COL], int row, int col);//玩家走
void Computer_move(char(*p)[COL], int row, int col);//电脑走
char Is_win(char(*p)[COL], int row, int col);//判断输赢
int Is_full(char(*p)[COL]);//判断棋盘是否已满
#endif