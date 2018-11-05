/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2DHIF
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			Khnifes Kyrillus
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdlib.h>
 #include "general.h"
 #include "chess.h"

void init_chess_board(Chessboard chess_board)
{
  for (size_t y = 0; y < 8; y++)
  {
    for (size_t x = 0; x < 8; x++)
    {
      chess_board[y][x].is_occupied=false;
    }
  }
}
void setup_chess_board(Chessboard chess_board)
{
  //White_Pawn
  for (size_t x = 0; x < 8; x++)
  {
    chess_board[1][x].piece.type=Pawn;
    chess_board[1][x].piece.color=White;
    chess_board[1][x].is_occupied=true;
  }
  //Black_Pawn
  for (size_t x = 0; x < 8; x++)
  {
    chess_board[6][x].piece.type=Pawn;
    chess_board[6][x].piece.color=Black;
    chess_board[6][x].is_occupied=true;
  }
  //White_Rook
  chess_board[0][0].piece.type=Rook;
  chess_board[0][0].piece.color=White;
  chess_board[0][0].is_occupied=true;
  chess_board[0][7].piece.type=Rook;
  chess_board[0][7].piece.color=White;
  chess_board[0][7].is_occupied=true;
  //Black_Rook
  chess_board[7][0].piece.type=Rook;
  chess_board[7][0].piece.color=Black;
  chess_board[7][0].is_occupied=true;
  chess_board[7][7].piece.type=Rook;
  chess_board[7][7].piece.color=Black;
  chess_board[7][7].is_occupied=true;
  //White_Knight
  chess_board[0][1].piece.type=Knight;
  chess_board[0][1].piece.color=White;
  chess_board[0][1].is_occupied=true;
  chess_board[0][6].piece.type=Knight;
  chess_board[0][6].piece.color=White;
  chess_board[0][6].is_occupied=true;
  //Black_Knight
  chess_board[7][1].piece.type=Knight;
  chess_board[7][1].piece.color=White;
  chess_board[7][1].is_occupied=true;
  chess_board[7][6].piece.type=Knight;
  chess_board[7][6].piece.color=White;
  chess_board[7][6].is_occupied=true;
  //White_Bishop
  chess_board[0][2].piece.type=Bishop;
  chess_board[0][2].piece.color=White;
  chess_board[0][2].is_occupied=true;
  chess_board[0][5].piece.type=Bishop;
  chess_board[0][5].piece.color=White;
  chess_board[0][5].is_occupied=true;
  //Black_Bishop
  chess_board[7][2].piece.type=Bishop;
  chess_board[7][2].piece.color=Black;
  chess_board[7][2].is_occupied=true;
  chess_board[7][5].piece.type=Bishop;
  chess_board[7][5].piece.color=Black;
  chess_board[7][5].is_occupied=true;
  //White King
  chess_board[0][3].piece.type=King;
  chess_board[0][3].piece.color=White;
  chess_board[0][3].is_occupied=true;
  //Black_King
  chess_board[7][3].piece.type=King;
  chess_board[7][3].piece.color=Black;
  chess_board[7][3].is_occupied=true;
  //White_Queen
  chess_board[0][4].piece.type=Queen;
  chess_board[0][4].piece.color=White;
  chess_board[0][4].is_occupied=true;
  //Black_Queen
  chess_board[7][4].piece.type=Queen;
  chess_board[7][4].piece.color=Black;
  chess_board[7][4].is_occupied=true;
}
/*
struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank);
bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece);
struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank);
bool remove_piece(ChessBoard chess_board, File file ,Rank rank);*/
bool is_square_occupied(ChessBoard chess_board,File file, Rank rank)
{
  return chess_board[rank][file-'0'].is_occupied;
}
bool is_piece(struct ChessPiece piece, enum Color color ,enum PieceType type)
{
  return piece.color == color && piece.type == type;
}

bool squares_share_rank(File file1, Rank rank1, File file2, Rank rank2)
{
  return rank1==rank2;
}
bool squares_share_file(File file1, Rank rank1, File file2, Rank rank2)
{
  {
    return file1==file2;
  }
}
bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2)
{
  return file1-file2-'0'==rank1-rank2;
}

/*bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_pawns_move(enum Color color, enum PawnMoves move, File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2);
*/
