/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
 #include <stdbool.h>

 enum Color {White, Black};

 enum PieceType
 {
   Pawn, Rook, Knight, Bishop, Queen, King
 };

 struct ChessPiece{
     enum Color color;
     enum PieceType type;
 };

 struct ChessSquare{
     bool is_set;
     struct ChessPiece piece;
 };

 typedef ChessSquare ChessBoard[8][8];
 bool is_piece(struct ChessPiece piece, enum PieceType type, enum Color color);
 void init_chess_board(Chessboard chess_board);
