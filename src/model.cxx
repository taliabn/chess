#include "model.hxx"
#include <algorithm>

using namespace ge211;
using namespace std;


Model::Model()
{
    for (auto i = 0; i < 64; ++i) {
        square_vec.push_back(std::make_unique<Piece>());
    }
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

void Model::setup_pieces(){
    for (int j = 0; j < 8; j++) {
        square_vec[pos_to_idx({j,1})]=std::make_unique<Pawn>(Pawn
                (Player::dark,Position(j,1)));
        square_vec[pos_to_idx({j,6})]=std::make_unique<Pawn>(Pawn
                (Player::light,Position(j,6)));
    }
    for (int j = 0; j < 8; j = j + 7) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Rook>(
                Rook(Player::dark, Position(j,0)));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Rook>(Rook
                (Player::light, Position(j,7)));
    }

    for (int j = 1; j < 8; j = j + 5) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Knight>(Knight
                (Player::dark, Position(j,0)));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Knight>(Knight
                (Player::light, Position(j,7)));
    }
    for (int j = 2; j < 8; j = j + 3) {
        square_vec[pos_to_idx({j,0})]=std::make_unique<Bishop>(Bishop
                (Player::dark, Position(j,0)));
        square_vec[pos_to_idx({j,7})]=std::make_unique<Bishop>(Bishop
                (Player::light, Position(j,7)));
    }

    // Set the king and queen pieces
    square_vec[pos_to_idx({3,0})]=std::make_unique<Queen>(Queen(Player::dark,
                                            Position(3,0)));
    square_vec[pos_to_idx({4,0})]=std::make_unique<King>(King(Player::dark,
                                            Position(4,0)));
    square_vec[pos_to_idx({3,7})]=std::make_unique<Queen>(Queen(Player::light,
                                            Position(3,7)));
    square_vec[pos_to_idx({4,7})]=std::make_unique<King>(King(Player::light,
                                            Position(4,7)));
}


void
Model::on_first_click_(Position pos){
    square_vec[pos_to_idx(pos)]->set_moves(pos, square_vec);
    piece_clicked_ = true;
    square_clicked_ = pos;
    viable_moves_ = piece_at_(square_clicked_).allowable_moves();
}


const char*
Model::piece_type_at(Position pos) const {
    return square_vec[pos_to_idx(pos)]->get_piece_type();
}


void
Model::play_move(Position dst)
{
    swap(square_vec[pos_to_idx(square_clicked_)], square_vec[pos_to_idx(dst)]);
    square_vec[pos_to_idx(square_clicked_)]=std::make_unique<Piece>();
    // Reset the highlighted piece and clicked square fields.
    piece_clicked_ = false;
    square_clicked_ = {-1, -1};

    if (!check_king_()) {
        // game is now over
        turn_ = Player::neither;
        return;
    } else {
        turn_ = other_player(turn_);
    }

    player_has_moves();
}

void
Model::player_has_moves() {
    bool has_moves = false;
    for (auto pos : board()) {
        square_vec[pos_to_idx(pos)]->set_moves(pos, square_vec);
        if (piece_at_(pos).player() == turn_ &&
                !piece_at_(pos).allowable_moves().empty()) {
            has_moves = true;
            break;
        }
    }

    if (!has_moves) {
        winner_ = other_player(turn_);
        turn_ = Player::neither;
    }
}

void
Model::check_pos(Position pos)
{
    if (good_position(pos) && !is_game_over()) {
        // If a piece is highlighted, check to see whether clicked position
        // is within its viable moves
        if (piece_clicked_ &&
            viable_moves_[pos]) {
            // If so, play the move and clear viable moves
            play_move(pos);
            viable_moves_ = Position_set();
        }
        // If the clicked position is a piece that the current player owns,
        // set it to the highlighted piece
        else if (piece_at_(pos).player() == turn_) {
            on_first_click_(pos);
        }
    }
}

bool
Model::check_king_()
{
    for (auto pos: board()) {
        // first condition checks if piece is of type King
        if ((strcmp(piece_type_at(pos), "King") == 0) &&
        piece_at_(pos).player() == other_player(turn_) ){
            return true;
        }
    }

    winner_ = turn_;
    return false;
}


void
Model::set_piece_(Position src, Position dst) {
    square_vec[pos_to_idx(dst)]=std::make_unique<Piece>();
    swap(square_vec[pos_to_idx(src)], square_vec[pos_to_idx(dst)]);
}

Piece
Model::piece_at_(ge211::Posn<int> pos)
{
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
    return Rectangle::from_top_left(the_origin, Dimensions(8, 8));
}