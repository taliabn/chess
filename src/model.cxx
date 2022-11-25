#include "model.hxx"

using namespace ge211;

Model::Model()
        : board_()
{}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

Piece
Model::operator[](Position pos) const
{
    return board_[pos];
}

void
Model::play_move(Position src, Position dst)
{
    // TODO
}

bool Model::check_king() {
    // TODO
    return true; // this is wrong
}
