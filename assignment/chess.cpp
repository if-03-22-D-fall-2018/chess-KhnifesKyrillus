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
  for (size_t x = 'a'; x < 8+'a'; x++)
  {
    add_piece(chess_board, x, 0, {White, Pawn});
    add_piece(chess_board, x, 7, {Black, Pawn});
  }
  add_piece(chess_board, 'a', 0, {White, Rook});
  add_piece(chess_board, 'h', 0, {White, Rook});
  add_piece(chess_board, 'b', 0, {White, Knight});
  add_piece(chess_board, 'g', 0, {White, Knight});
  add_piece(chess_board, 'c', 0, {White, Bishop});
 	add_piece(chess_board, 'f', 0, {White, Bishop});
 	add_piece(chess_board, 'd', 0, {White, Queen});
 	add_piece(chess_board, 'e', 0, {White, King});
 	add_piece(chess_board, 'a', 7, {Black, Rook});
 	add_piece(chess_board, 'h', 7, {Black, Rook});
 	add_piece(chess_board, 'b', 7, {Black, Knight});
  add_piece(chess_board, 'g', 7, {Black, Knight});
  add_piece(chess_board, 'c', 7, {Black, Bishop});
 	add_piece(chess_board, 'f', 7, {Black, Bishop});
 	add_piece(chess_board, 'd', 7, {Black, Queen});
 	add_piece(chess_board, 'e', 7, {Black, King});
}

struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank)
{
  if((file > 'h' || file < 'a') && (rank > 8 || rank < 1) || chess_board[rank][file-'a'].is_occupied)
  {
    return 0;
  }
  return &chess_board[rank][file];
}

struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank)
{
  struct ChessPiece piece;
  if(file>'h'||rank>7||rank<0||file<'a')
  {
    piece.type=NoPiece;
    return piece;
  }
  piece.type=chess_board[rank][file-'a'].piece.type;
  piece.color=chess_board[rank][file-'a'].piece.color;
  return piece;
}

bool remove_piece(ChessBoard chess_board, File file ,Rank rank)
{
  if(file>'h'||rank>7||rank<0||file<'a')
  {
    return false;
  }
  chess_board[rank][file-'a'].is_occupied=false;
  return true;
}

bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece)
{
  if (!is_square_occupied(chess_board, file, rank) && file<='h' && rank<=7 && rank>=0 && file>='a')
  {
    chess_board[rank][file-'a'].piece=piece;
    chess_board[rank][file-'a'].is_occupied=true;
    return true;
  }
  return false;
}

bool is_square_occupied(ChessBoard chess_board,File file, Rank rank)
{
  return chess_board[rank][file-'a'].is_occupied;
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
  return file1==file2;
}

bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2)
{
  return (unsigned int) file1-file2-'a'*2==rank1-rank2;
}

bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2)
{
  return (rank1+1==rank2 && file1+2==file2) ||(rank1-1==rank2 && file1-2==file2)||(rank1+2==rank2 && file1+1==file2)||(rank1-2==rank2 && file1-1==file2);
}

bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2)
{
  return false;
}

bool squares_share_pawns_move(enum Color color, enum PawnMoves moves, File file1, Rank rank1, File file2, Rank rank2)
{
  if (moves==NormalMove)
  {
    return rank1+1==rank2||rank1-1==rank2;
  }
  else  if (moves==CaptureMove)
  {
    return (rank1+1==rank2 && file1+1==file2) ||(rank1-1==rank2 && file1-1==file2);
  }
  return false;
}

bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2)
{
  return squares_share_diagonal(file1,rank1,file2,rank2)||file1==file2||rank1==rank2;
}
