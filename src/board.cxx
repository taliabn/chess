#include "board.hxx"
#include <algorithm>

using namespace ge211;

Board::Board()
    : dims_(8,8)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares_[i][j] = Piece(); // default "dummy" piece (player=neither)
        }
    }
    setup_pieces_();
}

void Board::setup_pieces_(){

    for (int j = 0; j < 8; j++) {
        squares_[1][j] = Pawn(Player::light, {1,j});
        squares_[6][j] = Pawn(Player::dark, {6,j});
    }

    for (int j = 0; j < 8; j = j + 7) {
        squares_[0][j] = Rook(Player::light, {0,j});
        squares_[7][j] = Rook(Player::dark, {7,j});
    }

    for (int j = 1; j < 8; j = j + 5) {
        squares_[0][j] = Knight(Player::light, {0,j});
        squares_[7][j] = Knight(Player::dark, {7,j});
    }
    for (int j = 2; j < 8; j = j + 3) {
        squares_[0][j] = Bishop(Player::light, {0,j});
        squares_[7][j] = Bishop(Player::dark, {7,j});
    }

    squares_[0][3] = Queen(Player::dark, {0,3});
    squares_[0][4] = King(Player::dark, {0,4});
    squares_[7][3] = Queen(Player::light, {7,3});
    squares_[7][4] = King(Player::light, {7,4});
}


Board::Dimensions
Board::dimensions() const
{
    return dims_;
}

// bool
// Board::has_piece_(Position pos) {
//     return squares_.find(pos)==squares_.end();
// }


Piece
Board::operator[](Position pos) const
{
    return squares_[pos.x][pos.y];
}

static std::vector<Board::Dimensions>
build_directions()
{
    std::vector<Board::Dimensions> result;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx || dy) {
                result.push_back({dx, dy});
            }
        }
    }

    return result;
}

std::vector<Board::Dimensions> const&
Board::all_directions()
{
    static std::vector<Dimensions> result = build_directions();
    return result;
}


Board::Rectangle
Board::all_positions() const
{
    return Rectangle::from_top_left(the_origin, dims_);
}


void
Board::bounds_check_(Position pos) const
{
    if (!good_position(pos)) {
        throw Client_logic_error("Board: position out of bounds");
    }
}


bool
Board::good_position(Position pos) const
{
    return 0 <= pos.x && pos.x < dims_.width &&
           0 <= pos.y && pos.y < dims_.height;
}
