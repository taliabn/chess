#include "model.hxx"

using namespace ge211;
using namespace std;

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
        board_.set_piece(Pawn(Player::light, Position(1,j)), {0,j});
        board_.set_piece(Pawn(Player::dark, Position (6,j)), {7, j});
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
Model::on_first_click(Position pos){
    piece_at(pos).set_moves(pos, board_);
    piece_clicked_ = true;
    square_clicked_ = pos;
}


void
Model::play_move(Position dst)
{
    board_.set_piece(piece_at(square_clicked_), dst);
    board_.set_piece(Piece(), square_clicked_);
    piece_clicked_ = false;
    square_clicked_ = {-1, -1};

    if (!check_king()) {
        // game is now over
        turn_ = Player::neither;
    } else {
        turn_ = other_player(turn_);
    }
}


bool Model::check_king()
{
    const char *king = "4King";
    for (auto pos: board()) {
        // first condition checks if piece is of type King
        if ((strcmp(typeid(piece_at(pos)).name(), king) == 0) && piece_at
        (pos).player() == other_player(turn_) ){
            return true;
        }
    }
    return false;
}