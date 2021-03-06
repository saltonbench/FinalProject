
#include "chess.c"




int evalboard(struct board * board){
  int value = 0;
  int king[8][8];
  int queen[8][8];
  int rook[8][8];
  int knight[8][8];
  int bishop[8][8];
  int pawn[8][8];

  int whiteking = 0;
  int blackking = 0;

  for(int I = 0; I < 8; I++){
    for(int J = 0; J < 8; J++){
      if((*board).a[I][J] == 'K'){
	whiteking = 1;
      }
      if((*board).a[I][J] == 'k'){
	blackking = 1;
      }
    }
  }

  if(whiteking == 0){
    return -100000;
  }
  if(blackking == 0){
    return 100000;
  }

  king[0][0] = -30;
  king[0][1] = -40;
  king[0][2] = -40;
  king[0][3] = -50;
  king[0][4] = -50;
  king[0][5] = -40;
  king[0][6] = -40;
  king[0][7] = -30;

  king[1][0] = -30;
  king[1][1] = -40;
  king[1][2] = -40;
  king[1][3] = -50;
  king[1][4] = -50;
  king[1][5] = -40;
  king[1][6] = -40;
  king[1][7] = -30;

  king[2][0] = -30;
  king[2][1] = -40;
  king[2][2] = -40;
  king[2][3] = -50;
  king[2][4] = -50;
  king[2][5] = -40;
  king[2][6] = -40;
  king[2][7] = -30;
  
  king[3][0] = -30;
  king[3][1] = -40;
  king[3][2] = -40;
  king[3][3] = -50;
  king[3][4] = -50;
  king[3][5] = -40;
  king[3][6] = -40;
  king[3][7] = -30;
  
  king[4][0] = -20;
  king[4][1] = -30;
  king[4][2] = -30;
  king[4][3] = -40;
  king[4][4] = -40;
  king[4][5] = -30;
  king[4][6] = -30;
  king[4][7] = -20;
  
  king[5][0] = -10;
  king[5][1] = -20;
  king[5][2] = -20;
  king[5][3] = -20;
  king[5][4] = -20;
  king[5][5] = -20;
  king[5][6] = -20;
  king[5][7] = -10;
  
  king[6][0] = 20;
  king[6][1] = 20;
  king[6][2] = 0;
  king[6][3] = 0;
  king[6][4] = 0;
  king[6][5] = 0;
  king[6][6] = 20;
  king[6][7] = 20;
  
  king[7][0] = 20;
  king[7][1] = 30;
  king[7][2] = 10;
  king[7][3] = 0;
  king[7][4] = 0;
  king[7][5] = 10;
  king[7][6] = 30;
  king[7][7] = 20;

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  queen[0][0] = -20;
  queen[0][1] = -10;
  queen[0][2] = -10;
  queen[0][3] = -5;
  queen[0][4] = -5;
  queen[0][5] = -10;
  queen[0][6] = -10;
  queen[0][7] = -20;

  queen[1][0] = -10;
  queen[1][1] = 0;
  queen[1][2] = 0;
  queen[1][3] = 0;
  queen[1][4] = 0;
  queen[1][5] = 0;
  queen[1][6] = 0;
  queen[1][7] = -10;

  queen[2][0] = -10;
  queen[2][1] = 0;
  queen[2][2] = 5;
  queen[2][3] = 5;
  queen[2][4] = 5;
  queen[2][5] = 5;
  queen[2][6] = 0;
  queen[2][7] = -10;
  
  queen[3][0] = -5;
  queen[3][1] = 0;
  queen[3][2] = 5;
  queen[3][3] = 5;
  queen[3][4] = 5;
  queen[3][5] = 5;
  queen[3][6] = 0;
  queen[3][7] = -5;
  
  queen[4][0] = 0;
  queen[4][1] = 0;
  queen[4][2] = 5;
  queen[4][3] = 5;
  queen[4][4] = 5;
  queen[4][5] = 5;
  queen[4][6] = 0;
  queen[4][7] = -5;
  
  queen[5][0] = -10;
  queen[5][1] = 5;
  queen[5][2] = 5;
  queen[5][3] = 5;
  queen[5][4] = 5;
  queen[5][5] = 5;
  queen[5][6] = 0;
  queen[5][7] = -10;
  
  queen[6][0] = -10;
  queen[6][1] = 0;
  queen[6][2] = 5;
  queen[6][3] = 0;
  queen[6][4] = 0;
  queen[6][5] = 0;
  queen[6][6] = 0;
  queen[6][7] = -10;
  
  queen[7][0] = -20;
  queen[7][1] = -10;
  queen[7][2] = -10;
  queen[7][3] = -5;
  queen[7][4] = -5;
  queen[7][5] = -10;
  queen[7][6] = -10;
  queen[7][7] = -20;

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  bishop[0][0] = -20;
  bishop[0][1] = -10;
  bishop[0][2] = -10;
  bishop[0][3] = -10;
  bishop[0][4] = -10;
  bishop[0][5] = -10;
  bishop[0][6] = -10;
  bishop[0][7] = -20;

  bishop[1][0] = -10;
  bishop[1][1] = 0;
  bishop[1][2] = 0;
  bishop[1][3] = 0;
  bishop[1][4] = 0;
  bishop[1][5] = 0;
  bishop[1][6] = 0;
  bishop[1][7] = -10;

  bishop[2][0] = -10;
  bishop[2][1] = 0;
  bishop[2][2] = 5;
  bishop[2][3] = 10;
  bishop[2][4] = 10;
  bishop[2][5] = 5;
  bishop[2][6] = 0;
  bishop[2][7] = -10;
  
  bishop[3][0] = -10;
  bishop[3][1] = 5;
  bishop[3][2] = 5;
  bishop[3][3] = 10;
  bishop[3][4] = 10;
  bishop[3][5] = 5;
  bishop[3][6] = 5;
  bishop[3][7] = -10;
  
  bishop[4][0] = -10;
  bishop[4][1] = 0;
  bishop[4][2] = 10;
  bishop[4][3] = 10;
  bishop[4][4] = 10;
  bishop[4][5] = 10;
  bishop[4][6] = 0;
  bishop[4][7] = -10;
  
  bishop[5][0] = -10;
  bishop[5][1] = 10;
  bishop[5][2] = 10;
  bishop[5][3] = 10;
  bishop[5][4] = 10;
  bishop[5][5] = 10;
  bishop[5][6] = 10;
  bishop[5][7] = -10;
  
  bishop[6][0] = -10;
  bishop[6][1] = 5;
  bishop[6][2] = 0;
  bishop[6][3] = 0;
  bishop[6][4] = 0;
  bishop[6][5] = 0;
  bishop[6][6] = 5;
  bishop[6][7] = -10;
  
  bishop[7][0] = -20;
  bishop[7][1] = -10;
  bishop[7][2] = -10;
  bishop[7][3] = -10;
  bishop[7][4] = -10;
  bishop[7][5] = -10;
  bishop[7][6] = -10;
  bishop[7][7] = -20;

  //////////////////////////////////////////////////////////////////////////////////////////////////////

  knight[0][0] = -50;
  knight[0][1] = -40;
  knight[0][2] = -30;
  knight[0][3] = -30;
  knight[0][4] = -30;
  knight[0][5] = -30;
  knight[0][6] = -40;
  knight[0][7] = -50;

  knight[1][0] = -40;
  knight[1][1] = -20;
  knight[1][2] = 0;
  knight[1][3] = 0;
  knight[1][4] = 0;
  knight[1][5] = 0;
  knight[1][6] = -20;
  knight[1][7] = -40;

  knight[2][0] = -30;
  knight[2][1] = 0;
  knight[2][2] = 10;
  knight[2][3] = 15;
  knight[2][4] = 15;
  knight[2][5] = 10;
  knight[2][6] = 0;
  knight[2][7] = -30;
  
  knight[3][0] = -30;
  knight[3][1] = 5;
  knight[3][2] = 15;
  knight[3][3] = 20;
  knight[3][4] = 20;
  knight[3][5] = 15;
  knight[3][6] = 5;
  knight[3][7] = -30;
  
  knight[4][0] = -30;
  knight[4][1] = 0;
  knight[4][2] = 15;
  knight[4][3] = 20;
  knight[4][4] = 20;
  knight[4][5] = 15;
  knight[4][6] = 0;
  knight[4][7] = -30;
  
  knight[5][0] = -30;
  knight[5][1] = 5;
  knight[5][2] = 10;
  knight[5][3] = 15;
  knight[5][4] = 15;
  knight[5][5] = 10;
  knight[5][6] = 5;
  knight[5][7] = -30;
  
  knight[6][0] = -40;
  knight[6][1] = -20;
  knight[6][2] = 0;
  knight[6][3] = 5;
  knight[6][4] = 5;
  knight[6][5] = 0;
  knight[6][6] = -20;
  knight[6][7] = -40;
  
  knight[7][0] = -50;
  knight[7][1] = -40;
  knight[7][2] = -30;
  knight[7][3] = -30;
  knight[7][4] = -30;
  knight[7][5] = -30;
  knight[7][6] = -40;
  knight[7][7] = -50;

  ////////////////////////////////////////////////////////////////////////////////////////////////////

  rook[0][0] = 0;
  rook[0][1] = 0;
  rook[0][2] = 0;
  rook[0][3] = 0;
  rook[0][4] = 0;
  rook[0][5] = 0;
  rook[0][6] = 0;
  rook[0][7] = 0;

  rook[1][0] = 5;
  rook[1][1] = 10;
  rook[1][2] = 10;
  rook[1][3] = 10;
  rook[1][4] = 10;
  rook[1][5] = 10;
  rook[1][6] = 10;
  rook[1][7] = 5;

  rook[2][0] = -5;
  rook[2][1] = 0;
  rook[2][2] = 0;
  rook[2][3] = 0;
  rook[2][4] = 0;
  rook[2][5] = 0;
  rook[2][6] = 0;
  rook[2][7] = -5;
  
  rook[3][0] = -5;
  rook[3][1] = 0;
  rook[3][2] = 0;
  rook[3][3] = 0;
  rook[3][4] = 0;
  rook[3][5] = 0;
  rook[3][6] = 0;
  rook[3][7] = -5;
  
  rook[4][0] = -5;
  rook[4][1] = 0;
  rook[4][2] = 0;
  rook[4][3] = 0;
  rook[4][4] = 0;
  rook[4][5] = 0;
  rook[4][6] = 0;
  rook[4][7] = -5;
  
  rook[5][0] = -5;
  rook[5][1] = 0;
  rook[5][2] = 0;
  rook[5][3] = 0;
  rook[5][4] = 0;
  rook[5][5] = 0;
  rook[5][6] = 0;
  rook[5][7] = -5;
  
  rook[6][0] = -5;
  rook[6][1] = 0;
  rook[6][2] = 0;
  rook[6][3] = 0;
  rook[6][4] = 0;
  rook[6][5] = 0;
  rook[6][6] = 0;
  rook[6][7] = -5;
  
  rook[7][0] = 0;
  rook[7][1] = 0;
  rook[7][2] = 0;
  rook[7][3] = 5;
  rook[7][4] = 5;
  rook[7][5] = 0;
  rook[7][6] = 0;
  rook[7][7] = 0;

  //////////////////////////////////////////////////////////////////////////////////////////////////

  pawn[0][0] = 0;
  pawn[0][1] = 0;
  pawn[0][2] = 0;
  pawn[0][3] = 0;
  pawn[0][4] = 0;
  pawn[0][5] = 0;
  pawn[0][6] = 0;
  pawn[0][7] = 0;

  pawn[1][0] = 50;
  pawn[1][1] = 50;
  pawn[1][2] = 50;
  pawn[1][3] = 50;
  pawn[1][4] = 50;
  pawn[1][5] = 50;
  pawn[1][6] = 50;
  pawn[1][7] = 50;

  pawn[2][0] = 10;
  pawn[2][1] = 10;
  pawn[2][2] = 20;
  pawn[2][3] = 30;
  pawn[2][4] = 30;
  pawn[2][5] = 20;
  pawn[2][6] = 10;
  pawn[2][7] = 10;
  
  pawn[3][0] = 5;
  pawn[3][1] = 5;
  pawn[3][2] = 10;
  pawn[3][3] = 25;
  pawn[3][4] = 25;
  pawn[3][5] = 10;
  pawn[3][6] = 5;
  pawn[3][7] = 5;
  
  pawn[4][0] = 0;
  pawn[4][1] = 0;
  pawn[4][2] = 0;
  pawn[4][3] = 20;
  pawn[4][4] = 20;
  pawn[4][5] = 0;
  pawn[4][6] = 0;
  pawn[4][7] = 0;
  
  pawn[5][0] = 5;
  pawn[5][1] = -5;
  pawn[5][2] = -10;
  pawn[5][3] = 0;
  pawn[5][4] = 0;
  pawn[5][5] = -10;
  pawn[5][6] = -5;
  pawn[5][7] = 5;
  
  pawn[6][0] = 5;
  pawn[6][1] = 10;
  pawn[6][2] = 10;
  pawn[6][3] = -20;
  pawn[6][4] = -20;
  pawn[6][5] = 10;
  pawn[6][6] = 10;
  pawn[6][7] = 5;
  
  pawn[7][0] = 0;
  pawn[7][1] = 0;
  pawn[7][2] = 0;
  pawn[7][3] = 0;
  pawn[7][4] = 0;
  pawn[7][5] = 0;
  pawn[7][6] = 0;
  pawn[7][7] = 0;

  //////////////////////////////////////////////////////////////////////////

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      char aa = (*board).a[i][j];
      if(aa == 'P'){
	value += pawn[i][j];
      }
      if(aa == 'p'){
	value -= pawn[7 - i][j];
      }
      if(aa == 'R'){
	value += rook[i][j];
      }
      if(aa == 'r'){
	value -= rook[7 - i][j];
      }
      if(aa == 'N'){
	value += knight[i][j];
      }
      if(aa == 'n'){
	value -= knight[7-i][j];
      }
      if(aa == 'B'){
	value += bishop[i][j];
      }
      if(aa == 'b'){
	value -= bishop[7 - i][j];
      }
      if(aa == 'K'){
	value += king[i][j];
      }
      if(aa == 'k'){
	value -= king[7 - i][j];
      }
      if(aa == 'Q'){
	value += queen[i][j];
      }
      if(aa == 'q'){
	value -= queen[7 - i][j];
      } 
    }
  }
  return value;
}

char* stringify(int i, int j, int m, int n){
  char * stuff = malloc(sizeof(char[4]));
  
  stuff[0] = i + '0';
  stuff[1] = j + '0';
  stuff[2] = m + '0';
  stuff[3] = n + '0';
  

  return stuff;
}

/*
  (*movelist)[*index][0] = i + '0';
  (*movelist)[*index][1] = j + '0';
  (*movelist)[*index][2] = i + '0';
  (*movelist)[*index][3] = j + '0';
*/

void addkings(struct board * board, int i, int j, int* index, char ***movelist){
  if( i+1 < 8 && j+1 < 8){
    if((*board).a[i+1][j+1] > 90 || (*board).a[i+1][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';
      (*index)++;
    }
  }

  if( j+1 < 8){
    if((*board).a[i][j+1] > 90 || (*board).a[i][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }

  if( i-1 > -1 && j+1 < 8){
    if((*board).a[i-1][j+1] > 90 || (*board).a[i-1][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }

  if( i+1 < 8){
    if((*board).a[i+1][j] > 90 || (*board).a[i+1][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }

  if( i-1 > -1){
    if((*board).a[i-1][j] > 90 || (*board).a[i-1][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }

  if( i+1 < 8 && j-1 > -1){
    if((*board).a[i+1][j-1] > 90 || (*board).a[i+1][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }

  if(j-1 > -1){
    if((*board).a[i][j-1] > 90 || (*board).a[i][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }

  if( i-1 > 0 && j-1 >0){
    if((*board).a[i-1][j-1] > 90 || (*board).a[i-1][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j - 1+ '0';

      (*index)++;
    }
  }
}

void addkings1(struct board * board, int i, int j, int* index, char ***movelist){
  if( i+1 < 8 && j+1 < 8){
    if((*board).a[i+1][j+1] < 90 || (*board).a[i+1][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }

  if( j+1 < 8){
    if((*board).a[i][j+1] < 90 || (*board).a[i][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }

  if( i-1 > -1 && j+1 < 8){
    if((*board).a[i-1][j+1] < 90 || (*board).a[i-1][j+1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }

  if( i+1 < 8){
    if((*board).a[i+1][j] < 90 || (*board).a[i+1][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }

  if( i-1 > -1){
    if((*board).a[i-1][j] < 90 || (*board).a[i-1][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }

  if( i+1 < 8 && j-1 > -1){
    if((*board).a[i+1][j-1] < 90 || (*board).a[i+1][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j - 1 + '0';
      (*index)++;
    }
  }

  if(j-1 > -1){
    if((*board).a[i][j-1] < 90 || (*board).a[i][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }

  if( i-1 > 0 && j-1 >0){
    if((*board).a[i-1][j-1] < 90 || (*board).a[i-1][j-1] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }
}

void addpawns(struct board * board, int i, int j, int * index, char ***movelist){
  if((*board).a[i-1][j] == 'O'){
    (*movelist)[*index][0] = i + '0';
    (*movelist)[*index][1] = j + '0';
    (*movelist)[*index][2] = i - 1 + '0';
    (*movelist)[*index][3] = j + '0';

    (*index)++;
  }

  if(j+1<8){
    if((*board).a[i-1][j+1] > 90 && (*board).a[i-1][j+1] != 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }
 
  if(j-1>-1){
    if((*board).a[i-1][j-1] > 90 && (*board).a[i-1][j-1] != 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 1 + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }

  
  if(i == 6){
    if((*board).a[i-1][j] == 'O' && (*board).a[i-2][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i - 2 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }
}

void addpawns1(struct board * board, int i, int j, int * index, char ***movelist){
  if((*board).a[i+1][j] == 'O'){
    (*movelist)[*index][0] = i + '0';
    (*movelist)[*index][1] = j + '0';
    (*movelist)[*index][2] = i + 1 + '0';
    (*movelist)[*index][3] = j + '0';

    (*index)++;
  }

  if(j+1<8){
    if((*board).a[i+1][j+1] < 90 && (*board).a[i+1][j+1] != 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j + 1 + '0';

      (*index)++;
    }
  }
 
  if(j-1>-1){
    if((*board).a[i+1][j-1] < 90 && (*board).a[i+1][j-1] != 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + 1 + '0';
      (*movelist)[*index][3] = j - 1 + '0';

      (*index)++;
    }
  }

  
  if(i == 1){
    if((*board).a[i+1][j] == 'O' && (*board).a[i+2][j] == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i  + 2 + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
    }
  }
}

void addknights(struct board * board, int i, int j, int * index, char ***movelist){
  if(i+2<8){
    if(j+1 < 8){
      if((*board).a[i+2][j+1] > 90 || (*board).a[i+2][j+1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i + 2 + '0';
	(*movelist)[*index][3] = j + 1 + '0';

	(*index)++;
      }
    }    
    if(j-1 > -1){
      if((*board).a[i+2][j-1] > 90 || (*board).a[i+2][j-1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i  + 2 + '0';
	(*movelist)[*index][3] = j  - 1 + '0';

	(*index)++;
      }
    }
  }

  if(i-2<8){
    if(j+1 < 8){
      if((*board).a[i-2][j+1] > 90 || (*board).a[i-2][j+1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 2 + '0';
	(*movelist)[*index][3] = j  + 1 + '0';

	(*index)++;
      }
    }    
    if(j-1 > -1){
      if((*board).a[i-2][j-1] > 90 || (*board).a[i-2][j-1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 2 + '0';
	(*movelist)[*index][3] = j  - 1 + '0';

	(*index)++;
      }
    }
  }

  if(j+2<8){
    if(i+1 < 8){
      if((*board).a[i+1][j+2] > 90 || (*board).a[i+1][j+2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i  + 1 + '0';
	(*movelist)[*index][3] = j + 2 + '0';

	(*index)++;
      }
    }    
    if(i-1 > -1){
      if((*board).a[i-1][j+2] > 90 || (*board).a[i-1][j+2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 1 + '0';
	(*movelist)[*index][3] = j + 2 + '0';

	(*index)++;
      }
    }
  }

  if(j-2<8){
    if(i+1 < 8){
      if((*board).a[i+1][j-2] > 90 || (*board).a[i+1][j-2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i + 1 + '0';
	(*movelist)[*index][3] = j  - 2 + '0';

	(*index)++;
      }
    }    
    if(i-1 > -1){
      if((*board).a[i-1][j-2] > 90 || (*board).a[i-1][j-2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i  - 1 + '0';
	(*movelist)[*index][3] = j  - 2 + '0';

	(*index)++;
      }
    }
  }
}

void addknights1(struct board * board, int i, int j, int * index, char ***movelist){
  if(i+2<8){
    if(j+1 < 8){
      if((*board).a[i+2][j+1] < 90 || (*board).a[i+2][j+1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i  + 2 + '0';
	(*movelist)[*index][3] = j  + 1 + '0';

	(*index)++;
      }
    }    
    if(j-1 > -1){
      if((*board).a[i+2][j-1] < 90 || (*board).a[i+2][j-1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i + 2 + '0';
	(*movelist)[*index][3] = j - 1 + '0';

	(*index)++;
      }
    }
  }

  if(i-2<8){
    if(j+1 < 8){
      if((*board).a[i-2][j+1] < 90 || (*board).a[i-2][j+1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 2 + '0';
	(*movelist)[*index][3] = j + 1 + '0';

	(*index)++;
      }
    }    
    if(j-1 > -1){
      if((*board).a[i-2][j-1] < 90 || (*board).a[i-2][j-1] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 2 + '0';
	(*movelist)[*index][3] = j - 1 + '0';

	(*index)++;
      }
    }
  }

  if(j+2<8){
    if(i+1 < 8){
      if((*board).a[i+1][j+2] < 90 || (*board).a[i+1][j+2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i + 1 + '0';
	(*movelist)[*index][3] = j + 2 + '0';

	(*index)++;
      }
    }    
    if(i-1 > -1){
      if((*board).a[i-1][j+2] < 90 || (*board).a[i-1][j+2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 1 + '0';
	(*movelist)[*index][3] = j + 2 + '0';

	(*index)++;
      }
    }
  }

  if(j-2<8){
    if(i+1 < 8){
      if((*board).a[i+1][j-2] < 90 || (*board).a[i+1][j-2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i + 1 + '0';
	(*movelist)[*index][3] = j - 2 + '0';

	(*index)++;
      }
    }    
    if(i-1 > -1){
      if((*board).a[i-1][j-2] < 90 || (*board).a[i-1][j-2] == 'O'){
	(*movelist)[*index][0] = i + '0';
	(*movelist)[*index][1] = j + '0';
	(*movelist)[*index][2] = i - 1 + '0';
	(*movelist)[*index][3] = j - 2 + '0';

	(*index)++;
      }
    }
  }
}


void addrooks(struct board * board, int i, int j, int * index, char ***movelist){
  int ic = i + 1;
  while(ic < 8){
    char aa = (*board).a[ic][j];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
      ic++;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
      ic = 8;
    }
    else if(aa < 90){
      ic = 8;
    }
  }

  ic = i - 1;
  while(ic > -1){
    char aa = (*board).a[ic][j];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
      ic--;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
      ic = -1;
    }
    else if(aa < 90){
      ic = -1;
    }
  }

  int jc = j + 1;
  while(jc < 8){
    char aa = (*board).a[i][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';

      (*index)++;
      jc++;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';

      (*index)++;
      jc = 8;
    }
    else if(aa < 90){
      jc = 8;
    }
  }

  jc = j - 1;
  while(jc > -1){
    char aa = (*board).a[i][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';

      (*index)++;
      jc--;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';

      (*index)++;
      jc = -1;
    }
    else if(aa < 90){
      jc = -1;
    }
  }
}


void addrooks1(struct board * board, int i, int j, int * index, char ***movelist){
  int ic = i + 1;
  while(ic < 8){
    char aa = (*board).a[ic][j];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';

      (*index)++;
      ic++;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';
      (*index)++;
      ic = 8;
    }
    else if(aa > 90){
      ic = 8;
    }
  }

  ic = i - 1;
  while(ic > -1){
    char aa = (*board).a[ic][j];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';
      (*index)++;
      ic--;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = j + '0';
      (*index)++;
      ic = -1;
    }
    else if(aa > 90){
      ic = -1;
    }
  }

  int jc = j + 1;
  while(jc < 8){
    char aa = (*board).a[i][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc++;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = 8;
    }
    else if(aa > 90){
      jc = 8;
    }
  }

  jc = j - 1;
  while(jc > -1){
    char aa = (*board).a[i][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc--;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = i + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = -1;
    }
    else if(aa > 90){
      jc = -1;
    }
  }
}

void addbishops(struct board * board, int i, int j, int * index, char ***movelist){
  int hor = 1;
  int ver = 1;

  int ic = i + ver;
  int jc = j + hor;
  
  while(ic < 8 && jc < 8){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = 8;
    }
    else if(aa < 90){
      jc = 8;
    }
  }
  ver = -1;
  hor = 1;

  ic = i + ver;
  jc = j + hor;
  while(ic > -1 && jc < 8){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = 8;
    }
    else if(aa < 90){
      jc = 8;
    }
  }

  ver = 1;
  hor = -1;

  ic = i + ver;
  jc = j + hor;
  while(ic < 8 && jc > -1){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = -1;
    }
    else if(aa < 90){
      jc = -1;
    }
  }

  ver = -1;
  hor = -1;

  ic = i + ver;
  jc = j + hor;
  while(ic > -1 && jc > -1){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa > 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = -1;
    }
    else if(aa < 90){
      jc = -1;
    }
  }
}

void addbishops1(struct board * board, int i, int j, int * index, char ***movelist){
  int hor = 1;
  int ver = 1;

  int ic = i + ver;
  int jc = j + hor;
  
  while(ic < 8 && jc < 8){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = 8;
    }
    else if(aa > 90){
      jc = 8;
    }
  }
  ver = -1;
  hor = 1;

  ic = i + ver;
  jc = j + hor;
  while(ic > -1 && jc < 8){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = 8;
    }
    else if(aa > 90){
      jc = 8;
    }
  }

  ver = 1;
  hor = -1;

  ic = i + ver;
  jc = j + hor;
  while(ic < 8 && jc > -1){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = -1;
    }
    else if(aa > 90){
      jc = -1;
    }
  }

  ver = -1;
  hor = -1;

  ic = i + ver;
  jc = j + hor;
  while(ic > -1 && jc > -1){
    char aa = (*board).a[ic][jc];
    if(aa == 'O'){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      ic += ver;
      jc += hor;
    }
    else if(aa < 90){
      (*movelist)[*index][0] = i + '0';
      (*movelist)[*index][1] = j + '0';
      (*movelist)[*index][2] = ic + '0';
      (*movelist)[*index][3] = jc + '0';
      (*index)++;
      jc = -1;
    }
    else if(aa > 90){
      jc = -1;
    }
  }
}


void addqueens(struct board * board, int i, int j, int * index, char ***movelist){
  addbishops(board, i, j, index, movelist);
  addrooks(board, i, j, index, movelist);
}

void addqueens1(struct board * board, int i, int j, int * index, char ***movelist){
  addbishops1(board, i, j, index, movelist);
  addrooks1(board, i, j, index, movelist);
}
  
char *** findallmoves(struct board * board){
  char *** movelist = malloc(sizeof(char[150][4]));
  int * index = malloc(sizeof(int*));
  *index = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      char p = (*board).a[i][j];
      if (p = 'K' && (*board).b == 1){
	addkings(board, i, j,index, movelist);
      }
      if (p = 'Q' && (*board).b== 1){
	addqueens(board, i, j,index, movelist);
      }
      if (p = 'B' && (*board).b== 1){
	addbishops(board, i, j, index,movelist);
      }
      if (p = 'N' && (*board).b== 1){
	addknights(board, i, j, index,movelist);
      }
      if (p = 'R' && (*board).b== 1){
	addrooks(board, i, j, index,movelist);
      }
      if (p = 'P' && (*board).b== 1){
	addpawns(board, i, j, index, movelist);
      }
      if (p = 'k'&& (*board).b == -1){
	addkings1(board, i, j,index, movelist);
      }
      if (p = 'q' && (*board).b== -1){
	addqueens1(board, i, j,index, movelist);
      }
      if (p = 'b' && (*board).b== -1){
	addbishops1(board, i, j,index,movelist);
      }
      if (p = 'n' && (*board).b== -1){
	addknights1(board, i, j, index,movelist);
      }
      if (p = 'r' && (*board).b== -1){
	addrooks1(board, i, j, index,movelist);
      }
      if (p = 'p' && (*board).b== -1){
	addpawns1(board, i, j, index, movelist);
      }
    }
  }
  return movelist;
}





int findvalue(struct board * board, char * move){
  int i = move[0] - '0';
  int j = move[1] - '0';
  int m = move[2] - '0';
  int n = move[3] - '0';

  struct board c;
  c.b = (*board).b;
  for(int I = 0; I < 8; I++){
    for(int J = 0; J < 8; J++){
      c.a[I][J] = (*board).a[I][J];
    }
  }

  movepieceWrap(&c, i, j, m, n);
  return evalboard(&c);
}


  

char* findbestmove(struct board * board, int depth){
  depth--;
  
  char ** movelist = *findallmoves(board);
  int bestcases[140];

  
  if(depth == 0){
    int counter = 0;
    while(movelist[counter] != NULL){
      bestcases[counter] = findvalue(board, movelist[counter]);
    }
    int mod = (*board).b;
    int best = bestcases[0];
    int dexbest = 0;
    counter = 1;
    while(movelist[counter] != NULL){
      if(bestcases[counter] * mod > best * mod){
	best = bestcases[counter];
	dexbest = counter;
      }
    }
    return movelist[dexbest];
    
  }
  
  else{
    char bestmoves[140][4];
    int counter = 0;
    while(movelist[counter] != NULL){
      struct board c;
      c.b = (*board).b;
      for(int I = 0; I < 8; I++){
	for(int J = 0; J < 8; J++){
	  c.a[I][J] = (*board).a[I][J];
	}
      }
      int i = movelist[counter][0] - '0';
      int j = movelist[counter][1] - '0';
      int m = movelist[counter][2] - '0';
      int n = movelist[counter][3] - '0';
      movepieceWrap(&c,i,j,m,n);
      //
      *bestmoves[counter] = *findbestmove(&c, depth);
      //
      counter = 0;
      while(bestmoves[counter] != NULL){
	bestcases[counter] = findvalue(board, bestmoves[counter]);
      }
    }
    int mod = (*board).b;
    int best = bestcases[0];
    int dexbest = 0;
    counter = 1;
    while(movelist[counter] != NULL){
      if(bestcases[counter] * mod > best * mod){
	best = bestcases[counter];
	dexbest = counter;
      }
    }
    char* bm = malloc(sizeof(char[4]));
    bm = bestmoves[dexbest];
    return bm;    
  }
}



int main(){
  struct board* board = startgame();
  printboard(board);
  while(1){
    char input[10];
    //fgets(input, sizeof(input), stdin);
    

    //char i = input[0] - '0';
    //char j = input[1] - '0';
    //char m = input[2] - '0';
    //char n = input[3] - '0';

    

    movepieceWrap(board,6,0,4,0);
    printboard(board);
    printf("%d\n", evalboard(board));
    printf("%p\n", findallmoves(board));
     
  }  
  return 0;
}
