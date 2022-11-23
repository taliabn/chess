#include "model.hxx"

using namespace ge211;

// Model::Model(int size)
//         : Model(size, size)
// { }

Model::Model()
        : board_({8, 8})
{
}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

Player
Model::operator[](Position pos) const
{
    return board_[pos];
}