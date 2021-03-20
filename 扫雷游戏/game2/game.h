
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2	

#define EASYCOUNT 10


void InitBoard(char board[ROWS][COLS], int rows, int cols,char c);
void DisplayBoarf(char board[ROWS][COLS], int row, int col);  //传过来的数组都是11*11，不可设置为ROW和COL
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);