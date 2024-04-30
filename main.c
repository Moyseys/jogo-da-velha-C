#include <stdio.h>

void showBoard(char board[3][3][3]) {
  printf("\n");
  for (int l = 0; l < 3; l++) {
    for (int c = 0; c < 3; c++) {
      for (int s = 0; s < 3; s++) {
        printf("%c", board[l][c][s]);
      }
    }
    printf("\n");
  }
  printf("\n");
};

char jogar(char board[3][3][3], int x, int y, char XorO) {
  for (int l = 0; l < 3; l++) {
    for (int c = 0; c < 3; c++) {
      if(l == x && c == y){
        if(board[l][c][1] == '#'){
          board[l][c][1] = XorO;
          return 1;
        }else{
          printf("\n☢️Já foi realizado um movimento nessa posição☢️\n");
          return 0;
        }
      }
    }
  }
}

int validCord(int cord) {
  if ((cord >= 0) && (cord <= 2)) {
    return 1;
  } else {
    return 0;
  }
}

void infInvalidCord(void) {
  printf("\n");
  printf("Cordenadas invalidas");
  printf("\n");
  return;
}

int verifyWin(char board[3][3][3]) {
  int winCases[8][3] = {
      {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
      {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6},
  };
  int contCell = 0;

  int cellsWithx[5] = {-1, -1, -1, -1, -1};
  int currentSizeY = 0;

  int cellsWithy[5] = {-1, -1, -1, -1, -1};
  int currentSizeX = 0;

  for (int i = 0; i < 3; i++) {
    for (int l = 0; l < 3; l++) {
      char cell = board[i][l][1];
      if (cell == 'X') {
        cellsWithx[currentSizeX] = contCell;
        currentSizeX++;
      }
      if (cell == 'O') {
        cellsWithy[currentSizeY] = contCell;
        currentSizeY++;
      }
      contCell++;
    }
  }
  // Pass across each case win
  int xWin = 0;
  int oWin = 0;
  for (int i = 0; i < 8; i++) {
      //printf("Case: %i\n", i);
    // pass across each cell of the case win
    for (int j = 0; j < 3; j++) {
      // Test case win X and O
      for (int u = 0; u < 5; u++) {
        // printf("%i", cellsWithy[u]);
        if (cellsWithx[u] == winCases[i][j]) {
          ++xWin;
        } else if (cellsWithy[u] == winCases[i][j]) {
          ++oWin;
        }
      }
    }
    if (xWin == 3) {
      return 1;
    } else if (oWin == 3) {
      return 2;
    } else {
      xWin = 0;
      oWin = 0;
    }
  }

  return 0;
}

int main() {
  char board[3][3][3] = {
      {"|#|", "|#|", "|#|"}, {"|#|", "|#|", "|#|"}, {"|#|", "|#|", "|#|"}};

  int fim = 0;
  char XorO = 'X';
  while (fim == 0) {
    int x = 0;
    int y = 0;

    printf("\nVez do %c\n", XorO);
    showBoard(board);

    printf("Digite a linha que deseja jogar: ");
    scanf("%i", &x);
    x--;
    if (validCord(x) != 1) {
      infInvalidCord();
      continue;
    }

    printf("Digite a coluna que deseja jogar: ");
    scanf("%i", &y);
    y--;
    if (validCord(y) != 1) {
      infInvalidCord();
      continue;
    }

    int isPlay = jogar(board, x, y, XorO);
    if (isPlay == 0) {
      continue;
    }
    
    int win = verifyWin(board);
    if (win == 1) {
      printf("🎉✨Jogador X ganhou, meus parabens😁.🎉✨");
      showBoard(board);
      return 0;
    }
    else if (win == 2) {
      printf("🎉✨Jogador O ganhou, meus parabens😁.🎉✨");
      showBoard(board);
      return 0;
    } else {
      if (XorO == 'X') {
        XorO = 'O';
      } else {
        XorO = 'X';
      }
    }
  }

  return 0;
}
