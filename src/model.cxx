#include "model.hxx"
#include <algorithm>

using namespace ge211;
using namespace std;


Model::Model()
    : dims_(8,8)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares_[i][j] = Piece(); // default "dummy" piece (player=neither)
        }
    }
    setup_pieces();
}

Model::Rectangle
Model::board() const
{
    return all_positions();
}


void Model::setup_pieces(){
    for (int j = 0; j < 8; j++) {
        // Piece p = Piece(); // this works
        // this does not work
        set_piece_(Pawn(Player::light, Position(1,j), squares_), {0,j});
        set_piece_(Pawn(Player::dark, Position (6,j), squares_), {7, j});
    }

    for (int j = 0; j < 8; j = j + 7) {
        set_piece_(Rook(Player::light, Position(0,j), squares_), {0,j});
        set_piece_(Rook(Player::dark, Position(7,j), squares_), {7,j});
    }

    for (int j = 1; j < 8; j = j + 5) {
       set_piece_(Knight(Player::light, Position(0,j), squares_), {0,j});
       set_piece_(Knight(Player::dark, Position(7,j), squares_), {7,j});
    }
    for (int j = 2; j < 8; j = j + 3) {
        set_piece_(Bishop(Player::light, Position(0,j), squares_), {0,j});
        set_piece_(Bishop(Player::dark, Position(7,j), squares_), {7,j});
    }

    set_piece_(Queen(Player::dark, Position(0,3), squares_), {0,3});
    set_piece_(King(Player::dark, Position(0,4), squares_), {0,4});
    set_piece_(Queen(Player::light, Position(7,3), squares_), {7,3});
    set_piece_(King(Player::light, Position(7,4), squares_), {7,4});
}


void
Model::on_first_click(Position pos){
    piece_at_(pos).set_moves(pos, squares_);
    piece_clicked_ = true;
    square_clicked_ = pos;
}


void
Model::play_move(Position dst)
{
    set_piece_(piece_at_(square_clicked_), dst);
    set_piece_(Piece(), square_clicked_);
    piece_clicked_ = false;
    square_clicked_ = {-1, -1};

    const char *pawn = "4Pawn";
    if ((strcmp(typeid(piece_at_(dst)).name(), pawn) == 0)) {
        piece_at_(dst).update_first_move();
    }

    if (!check_king_()) {
        // game is now over
        turn_ = Player::neither;
    } else {
        turn_ = other_player(turn_);
    }
}

void
Model::check_pos(Position pos)
{
    if (is_game_over()) {return;}
    // bool p = model_[model_.square_clicked()].allowable_moves()[board_pos];
    if (piece_clicked_ &&
            squares_[square_clicked_].allowable_moves()[pos]){
        play_move(pos);
    } else if(squares_[pos].player() == turn_){
        on_first_click(pos);
    }
}

bool Model::check_king_()
{
    const char *king = "4King";
    for (auto pos: board()) {
        // first condition checks if piece is of type King
        if ((strcmp(typeid(piece_at_(pos)).name(), king) == 0) &&
        piece_at_(pos).player() == other_player(turn_) ){
            return true;
        }
    }
    return false;
}


void
Model::set_piece_(Piece piece, Position pos) {
    squares_[pos.x][pos.y] = piece;
}


Piece
Model::piece_at_(ge211::Posn<int> pos)
{
    return squares_[pos.x][pos.y];
}


Piece
Model::operator[](Position pos) const
{
    return squares_[pos.x][pos.y];
}


Model::Rectangle
Model::all_positions() const
{
    return Rectangle::from_top_left(the_origin, dims_);
}