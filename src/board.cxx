#include "board.hxx"
#include <algorithm>

using namespace ge211;

Board::Board()
    : dims_(8,8)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares_[i][j] = Piece(); // default "dummy" piece
            // (player=neither)
        }
    }
}

void
Board::set_piece(Piece piece, Position pos) {
    squares_[pos.x][pos.y] = piece;
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

Piece
Board::piece_at(Position pos) const
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
