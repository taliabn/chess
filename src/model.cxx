#include "model.hxx"

using namespace ge211;

Model::Model()
{
    board_ = Board();
    setup_pieces(board_);
}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}


void Model::setup_pieces(Board const& board){

    for (int j = 0; j < 8; j++) {
        // squares_[1][j] = Pawn(Player::light, {1,j});
        // squares_[6][j] = Pawn(Player::dark, {6,j});
    }

    for (int j = 0; j < 8; j = j + 7) {
        board_.set_piece(Rook(Player::light, Position(0,j), board_), {0,j});
        board_.set_piece(Rook(Player::dark, Position(7,j), board_), {7,j});
    }

    for (int j = 1; j < 8; j = j + 5) {
       board_.set_piece(Knight(Player::light, Position(0,j), board_), {0,j});
       board_.set_piece(Knight(Player::dark, Position(7,j), board_), {7,j});
    }
    for (int j = 2; j < 8; j = j + 3) {
        board_.set_piece(Bishop(Player::light, Position(0,j), board_), {0,j});
        board_.set_piece(Bishop(Player::dark, Position(7,j), board_), {7,j});
    }

    board_.set_piece(Queen(Player::dark, Position(0,3), board_), {0,3});
    board_.set_piece(King(Player::dark, Position(0,4), board_), {0,4});
    board_.set_piece(Queen(Player::light, Position(7,3), board_), {7,3});
    board_.set_piece(King(Player::light, Position(7,4), board_), {7,4});
}



Piece
Model::piece_at(Position pos) const
{
    return board_[pos];
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
