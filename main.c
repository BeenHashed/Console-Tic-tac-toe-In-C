#include <stdio.h>
#include <ctype.h>

void printBoard();   
void resetGame(); 
void freeSpace(); 
void initalizeBoard(); 
void playerMove();
void player2Move();
char gameOver();
char printGameOver(char);

char board[3][3];
const char player = 'X';
const char player2 = 'O';
int plays = 9;
int move = 69; 
int playerPos;
int player2Pos;


int main() {
	initalizeBoard();

	while(plays != 0) {
		printBoard();
		freeSpace();
		playerMove();
		printBoard();

		char winner = gameOver();
		if(winner != ' ') {
			char result = printGameOver(winner);
			if(result == 'y') {
				resetGame();
				continue;
			} else if(result == 'n') {
				break;
			} else {
				printf("This was a tie");
			}
		}

		freeSpace();

		player2Move();
		winner = gameOver();
		if(winner != ' ') {
			char result = printGameOver(winner);
			if(result == 'y') {
				resetGame();
			} else if(result == 'n') {
				printf("See ya!\n");
				break;
			}
		}
	}

	return 0;
}

void initalizeBoard() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void printBoard() {
		printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
		printf("\n---|---|---\n");
		printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
		printf("\n---|---|---\n");
		printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
		printf("\n");
}

void resetGame() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
	plays = 9;
}

void freeSpace() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(board[i][j] != ' ') {
				plays--;
				return;
			} 
		}
	}
}

void playerMove() {
	printf("Player 1, Pick your position from 1-9: ");
	scanf("%d", &playerPos);

	while(playerPos == move) {
		printf("Invalid Position\n");
		printf("Player 1, Pick your position from 1-9: ");
		scanf("%d", &playerPos);
	}
	
	move = playerPos;
	switch(playerPos) {
		case 1:
			board[0][0] = player;
			break;
		case 2:
			board[0][1] = player;
			break;
		case 3:
			board[0][2] = player;
			break;
		case 4:
			board[1][0] = player;
			break;
		case 5:
			board[1][1] = player;
			break;
		case 6:
			board[1][2] = player;
			break;
		case 7:
			board[2][0] = player;
			break;
		case 8:
			board[2][1] = player;
			break;
		case 9:
			board[2][2] = player;
			break;
		default:
			printf("Invalid Position\n");
			break;
	}
}


void player2Move() {
	printf("Player 2, Pick your position from 1-9: ");
	scanf("%d", &player2Pos);

	while(player2Pos == move) {
		printf("Invalid Position\n");
		printf("Player 2, Pick your position from 1-9: ");
		scanf("%d", &player2Pos);
	}
	
	move = player2Pos;

	switch(player2Pos) {
		case 1:
			board[0][0] = player2;
			break;
		case 2:
			board[0][1] = player2;
			break;
		case 3:
			board[0][2] = player2;
			break;
		case 4:
			board[1][0] = player2;
			break;
		case 5:
			board[1][1] = player2;
			break;
		case 6:
			board[1][2] = player2;
			break;
		case 7:
			board[2][0] = player2;
			break;
		case 8:
			board[2][1] = player2;
			break;
		case 9:
			board[2][2] = player2;
			break;
		default:
			printf("Invalid Position\n");
			break;
	}
}


char gameOver() {
	 // Rows
   for(int i = 0; i < 3; i++) {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
         return board[i][0];
      }
   }

   // Columns
   for(int i = 0; i < 3; i++) {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
         return board[0][i];
      }
   }

   //Diagonal 1
   if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
      return board[0][0];
   }

   // Diagonal 2
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
      return board[0][2];
   }

   return ' ';
}

char printGameOver(char winner) {
	char tied;
	if(winner == 'X') {
		printf("Player 1 won!\n");
	} else if(winner == 'O') {
		printf("Player 2 won!\n");
	} else {
		printf("It was a tie!\n");
	}

	char playAgain;
	tolower(playAgain);
	while(playAgain != 'y' && playAgain != 'n') {
		printf("Would you like to play again(y/n): ");
		scanf(" %c", &playAgain);
	}
	return playAgain;
}
