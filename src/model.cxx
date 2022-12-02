#include "model.hxx"
#include <algorithm>

using namespace ge211;
using namespace std;


Model::Model()
    : dims_(8,8)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            squares_[i][j] = Piece(); // default "dummy" piece
            // (player=neither)
        }
    }
    for (auto i = 0; i < 64; ++i) {
        square_vec.push_back(std::make_unique<Piece>());
    }
    setup_pieces_new();
    setup_pieces();
}

Model::Rectangle
Model::board() const
{
    return all_positions();
}

int Model::pos_to_idx(Position pos) const {
    return 8*pos.x + pos.y;
}

ge211::Posn<int> Model::idx_to_pos(int idx) const {
    // return Position(2,2);
    auto x = int(idx / 8);
    auto y = int(idx % 8);
    return Position(x, y);
}



void Model::setup_pieces_new(){
    // square_vec[4] = (std::make_unique<Pawn>(Player::dark, Position(4,4),
    //                                         squares_));
    // square_vec[4]->set_moves(Position(0,0), squares_);
    for (int j = 0; j < 8; j++) {
        // Piece p = Piece(); // this works
        // this does not work
        // squares_[4][4] = p;

        square_vec[pos_to_idx({j,1})]=std::make_unique<Pawn>(Pawn
                (Player::dark,Position(j,1), squares_));
        square_vec[pos_to_idx({j,6})]=std::make_unique<Pawn>(Pawn
                (Player::light,Position(j,6), squares_));
    }
    for (int j = 0; j < 8; j = j + 7) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Rook>(
                Rook(Player::dark, Position(j,0), squares_));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Rook>(Rook
                (Player::light, Position(j,7), squares_));
    }

    for (int j = 1; j < 8; j = j + 5) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Knight>(Knight
                (Player::dark, Position(j,0), squares_));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Knight>(Knight
                (Player::light, Position(j,7), squares_));
    }
    for (int j = 2; j < 8; j = j + 3) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Bishop>(Bishop
                (Player::dark, Position(j,0), squares_));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Bishop>(Bishop
                (Player::light, Position(j,7), squares_));
    }

    square_vec[pos_to_idx({3,0})]=std::make_unique<Queen>(Queen(Player::dark,
                                            Position(3,0),squares_));
    square_vec[pos_to_idx({4,0})]=std::make_unique<King>(King(Player::dark,
                                            Position(4,0),squares_));
    square_vec[pos_to_idx({3,7})]=std::make_unique<Queen>(Queen(Player::light,
                                            Position(3,7),squares_));
    square_vec[pos_to_idx({4,7})]=std::make_unique<King>(King(Player::light,
                                            Position(4,7),squares_));
}

void Model::setup_pieces(){
    for (int j = 0; j < 8; j++) {
        // Piece p = Piece(); // this works
        // this does not work
        // squares_[4][4] = p;
        set_piece_(Pawn(Player::dark, Position(1,j), squares_), {1,j});
        set_piece_(Pawn(Player::light, Position (6,j), squares_), {6, j});
    }

    for (int j = 0; j < 8; j = j + 7) {
        set_piece_(Rook(Player::dark, Position(0,j), squares_), {0,j});
        set_piece_(Rook(Player::light, Position(7,j), squares_), {7,j});
    }

    for (int j = 1; j < 8; j = j + 5) {
       set_piece_(Knight(Player::dark, Position(0,j), squares_), {0,j});
       set_piece_(Knight(Player::light, Position(7,j), squares_), {7,j});
    }
    for (int j = 2; j < 8; j = j + 3) {
        set_piece_(Bishop(Player::dark, Position(0,j), squares_), {0,j});
        set_piece_(Bishop(Player::light, Position(7,j), squares_), {7,j});
    }

    set_piece_(Queen(Player::dark, Position(0,3), squares_), {0,3});
    set_piece_(King(Player::dark, Position(0,4), squares_), {0,4});
    set_piece_(Queen(Player::light, Position(7,3), squares_), {7,3});
    set_piece_(King(Player::light, Position(7,4), squares_), {7,4});
}


void
Model::on_first_click(Position pos){
    square_vec[pos_to_idx(pos)]->set_moves(pos, squares_);
    // p.set_moves(pos, squares_);
    piece_clicked_ = true;
    square_clicked_ = pos;
}


const char*
Model::piece_type_at(Position pos) const {
    return square_vec[pos_to_idx(pos)]->get_piece_type();
}


void
Model::play_move(Position dst)
{
    // Piece tmp = &square_vec[pos_to_idx(square_clicked_)];
    // square_vec[pos_to_idx(dst)]=;
    // square_vec[pos_to_idx({1,j})]=std::make_unique<Pawn>(Pawn(Player::dark,Position(1,j), squares_));
    //
    swap(square_vec[pos_to_idx(square_clicked_)], square_vec[pos_to_idx(dst)]);
    square_vec[pos_to_idx(square_clicked_)]=std::make_unique<Piece>();
    set_piece_(piece_at_(square_clicked_), dst);
    set_piece_(Piece(), square_clicked_);
    piece_clicked_ = false;
    square_clicked_ = {-1, -1};

    // const char *pawn = "4Pawn";
    // if ((strcmp(typeid(piece_at_(dst)).name(), pawn) == 0)) {
    //     piece_at_(dst).update_first_move();
    // }

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
            piece_at_(square_clicked_).allowable_moves()[pos]){
        play_move(pos);
    } else if(piece_at_(pos).player() == turn_){
        on_first_click(pos);
    }
}

bool Model::check_king_()
{
    for (auto pos: board()) {
        // first condition checks if piece is of type King
        if ((strcmp(piece_type_at(pos), "King") == 0) &&
        piece_at_(pos).player() == other_player(turn_) ){
            return true;
        }
    }
    return false;
}


void
Model::set_piece_(Piece piece, Position pos) {

    squares_[pos.y][pos.x] = piece;
}

Piece
Model::piece_at_(ge211::Posn<int> pos)
{
    // return square_vec[pos.x + pos.y];
    return *square_vec[pos_to_idx(pos)];
}


Player
Model::operator[](Position pos) const
{
    return square_vec[pos_to_idx(pos)]->player();
}


Model::Rectangle
Model::all_positions() const
{
    return Rectangle::from_top_left(the_origin, dims_);
}