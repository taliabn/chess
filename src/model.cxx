#include "model.hxx"

using namespace ge211;

// Model::Model(int size)
//         : Model(size, size)
// { }

Model::Model()
        : board_({8, 8})
{}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

// currently board will return a Player, but we want a Piece
// Piece
// Model::operator[](Position pos) const
// {
//     return board_[pos];
// }

void
Model::play_move(Position src, Position dst)
{
    // TODO
}

bool Model::check_king() {
    // TODO
    return true; // this is wrong
}
