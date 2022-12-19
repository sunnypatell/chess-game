**Chess**
This is a chess program implemented in C++. It uses a two-dimensional array to represent the chess board, with each element of the array being a pointer to a Piece object. The program uses enumerated types to represent the different types of pieces, and has a separate class for each type of piece.
The program has classes for the following pieces:
Pawn
Knight
Bishop
Rook
Queen
King
Each piece class has a canMoveTo function that determines whether the piece can move to a given square on the board.

To use the program, create an instance of the desired piece and call its canMoveTo function with the desired x and y coordinates. The function will return true if the piece can move to the given coordinates, and false otherwise.

Note that this program does not handle game logic such as checkmate or castling. It is simply a tool for determining the possible moves for a given piece on the chess board.

To run the program, you will need to have a C++ compiler installed on your system. You can then compile the program using the following command:

g++ chess.cpp -o chess
This will create an executable file called chess. You can then run the program using the following command:

./chess
Alternatively, you can use an Integrated Development Environment (IDE) such as Xcode or Visual Studio to compile and run the program.

Note that the program includes the following libraries:

#include <iostream>
#include <cmath>
Make sure that these libraries are available on your system before attempting to compile the program.

To create an instance of a chess piece, you can use the following code:

Piece* pawn = new Pawn(true, 0, 0);
This creates a white pawn at coordinates (0, 0) on the board. The first argument is a boolean value that indicates whether the piece is white (true) or black (false). The second and third arguments are the x and y coordinates of the piece on the board.

You can then use the canMoveTo function to determine whether the pawn can move to a given square on the board:

bool canMove = pawn->canMoveTo(1, 1);
This will return true if the pawn can move to the square at coordinates (1, 1), and false otherwise.

You can use similar code to create and move other types of pieces. For example, the following code creates a black knight at coordinates (4, 4) and determines whether it can move to the square at coordinates (6, 5):

Piece* knight = new Knight(false, 4, 4);
bool canMove = knight->canMoveTo(6, 5);
Remember that this program does not handle game logic such as checkmate or castling. It is simply a tool for determining the possible moves for a given piece on the chess board.
