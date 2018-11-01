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
#include <stdbool.h>
#include "chess.h"

void init_chess_board(Chessboard chess_board);
void setup_chess_board(Chessboard chess_board);
bool is_square_occupied(ChessBoard chess_board,File file, Rank rank);

struct ChessSquare* get_square(ChessBoard chess_board,File file, Rank rank);
bool add_piece(ChessBoard chess_board, File file ,Rank rank,struct ChessPiece piece);
struct ChessPiece get_piece(ChessBoard chess_board, File file ,File rank);
bool remove_piece(ChessBoard chess_board, File file ,Rank rank);
bool is_piece(struct ChessPiece piece, enum Color color ,enum PieceType type);

bool squares_share_rank(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_file(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_diagonal(File file1, Rank rank1, File file2, Rank rank2);

bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_kings_move(File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_pawns_move(enum Color color, enum PawnMoves move, File file1, Rank rank1, File file2, Rank rank2);
bool squares_share_queens_move(File file1, Rank rank1, File file2, Rank rank2);
