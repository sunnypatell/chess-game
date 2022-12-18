#include <iostream>
#include <cmath>

// We will use a two-dimensional array to represent the chess board.
// Each element of the array will be a pointer to a Piece object.
// We will use nullptr to represent an empty square.
const int BOARD_SIZE = 8;
Piece* board[BOARD_SIZE][BOARD_SIZE];

// We will use enumerated types to represent the different types of pieces.
enum PieceType {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

// We will use a separate class for each type of piece.
class Piece {
  public:
    Piece(PieceType type, bool isWhite, int x, int y)
        : type_(type), isWhite_(isWhite), x_(x), y_(y) {}
    virtual ~Piece() {}

    // Return true if the piece can move to the given square.
    virtual bool canMoveTo(int x, int y) = 0;

    // Return the type of the piece.
    PieceType getType() const { return type_; }

    // Return true if the piece is white.
    bool isWhite() const { return isWhite_; }

    // Return the current x-coordinate of the piece.
    int getX() const { return x_; }

    // Return the current y-coordinate of the piece.
    int getY() const { return y_; }

  private:
    PieceType type_;
    bool isWhite_;
    int x_;
    int y_;
};

// Implement the Pawn class.
class Pawn : public Piece {
  public:
    Pawn(bool isWhite, int x, int y) : Piece(PAWN, isWhite, x, y), hasMoved_(false) {}

    bool canMoveTo(int x, int y) override {
        // Pawns can only move forward.
        if (isWhite()) {
            if (y <= getY()) {
                return false;
            }
        } else {
            if (y >= getY()) {
                return false;
            }
        }

        // Pawns can move one square at a time, or two squares if they have not moved yet.
        if (std::abs(x - getX()) == 0 && std::abs(y - getY()) <= 2) {
            return true;
        }

        // Pawns can capture pieces diagonally.
        if (std::abs(x - getX()) == 1 && std::abs(y - getY()) == 1) {
            return true;
        }

        return false;
    }

  private:
    // Keep track of whether the pawn has moved.
    bool hasMoved_;
};

// Implement the Knight class.
class Knight : public Piece {
  public:
    Knight(bool isWhite, int x, int y) : Piece(KNIGHT, isWhite, x, y) {}

    bool canMoveTo(int x, int y) override {
        // Knights can move in an L shape.
        if (std::abs(x - getX()) == 2 && std::abs(y - getY()) == 1) {
            return true;
        }
        if (std::abs(x - getX()) == 1 && std::abs(y - getY()) == 2) {
            return true;
        }
        return false;
    }
};

class Bishop : public Piece {
  public:
    Bishop(bool isWhite, int x, int y) : Piece(BISHOP, isWhite, x, y) {}

    bool canMoveTo(int x, int y) override {
        // Bishops can move diagonally.
        if (std::abs(x - getX()) == std::abs(y - getY())) {
            return true;
        }
        return false;
    }
};

// Implement the Rook class.
class Rook : public Piece {
  public:
    Rook(bool isWhite, int x, int y) : Piece(ROOK, isWhite, x, y) {}

    bool canMoveTo(int x, int y) override {
        // Rooks can move horizontally or vertically.
        if (x == getX() || y == getY()) {
            return true;
        }
        return false;
    }
};

// Implement the Queen class.
class Queen : public Piece {
  public:
    Queen(bool isWhite, int x, int y) : Piece(QUEEN, isWhite, x, y) {}

    bool canMoveTo(int x, int y) override {
        // Queens can move horizontally, vertically, or diagonally.
        if (x == getX() || y == getY() || std::abs(x - getX()) == std::abs(y - getY())) {
            return true;
        }
        return false;
    }
};

// Implement the King class.
class King : public Piece {
  public:
    King(bool isWhite, int x, int y) : Piece(KING, isWhite, x, y) {}

    bool canMoveTo(int x, int y) override {
        // Kings can move one square in any direction.
        if (std::abs(x - getX()) <= 1 && std::abs(y - getY()) <= 1) {
            return true;
        }
        return false;
    }
};

// Initialize the board with the starting positions of the pieces.
void initializeBoard() {
    // Initialize the pawns.
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = new Pawn(true, i, 1);
        board[6][i] = new Pawn(false, i, 6);
    }

    // Initialize the knights.
    board[0][1] = new Knight(true, 1, 0);
    board[0][6] = new Knight(true, 6, 0);
    board[7][1] = new Knight(false, 1, 7);
    board[7][6] = new Knight(false, 6, 7);

    // Initialize the bishops.
    board[0][2] = new Bishop(true, 2, 0);
    board[0][5] = new Bishop(true, 5, 0);
    board[7][2] = new Bishop(false, 2, 7);
    board[7][5] = new Bishop(false, 5, 7);

    // Initialize the rooks.
    board[0][0] = new Rook(true, 0, 0);
    board[0][7] = new Rook(true, 7, 0);
    board[7][0] = new Rook(false, 0, 7);
    board[7][7] = new Rook(false, 7, 7);

    // Initialize the queens.
    board[0][3] = new Queen(true, 3, 0);
    board[7][3] = new Queen(false, 3, 7);

    // Initialize the kings.
    board[0][4] = new King(true, 4, 0);
    board[7][4] = new King(false, 4, 7);
}

int main() {
    // Initialize the board.
    initializeBoard();

    // Print the board.
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (board[y][x] == nullptr) {
                std::cout << "- ";
            } else {
                switch (board[y][x]->getType()) {
                    case PAWN:
                        std::cout << "P ";
                        break;
                    case KNIGHT:
                        std::cout << "N ";
                        break;
                    case BISHOP:
                        std::cout << "B ";
                        break;
                    case ROOK:
                        std::cout << "R ";
                        break;
                    case QUEEN:
                        std::cout << "Q ";
                        break;
                    case KING:
                        std::cout << "K ";
                        break;
                }
            }
        }
        std::cout << std::endl;
    }

    return 0;
}