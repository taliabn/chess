#include "model.hxx"
#include "piece.hxx"

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
Model::play_move(Position dst)
{
    //If no square is highlighted, highlight clicked square if occupied and
    // return if not
    if (highlighted_square_ == nullptr) {
        if (board[dst].player() == Player::neither) {
            return;
        } else {
            highlighted_square_ = dst;
            highlight_move(dst);
        }
    }

    //If clicked square is within the viable moves for the previously
    // highlighted piece, make the move
    if (highlighted_moves_[dst]) {
        board[dst] = board[highlighted_square_]; //This needs to be a copy of
        // piece
        board[highlighted_square_] = Piece();
        turn_ = other_player(turn_);

        check_king();
        }
    }
}

Position_set
Model::highlight_move(Position pos)
{
    highlighted_moves_ = board_[pos].calculate_moves(pos, this);
}

bool Model::check_king() {
    bool light_king = false;
    bool dark_king = false;
    for (auto pos: board()) {
        if (King& dynamic_cast<King&> (board[pos])) {
            if (board[pos].player() == Player::light) {
                light_king = true;
            } else {
                dark_king = true;
            }
        }
    }

    if (!light_king) {
        winner_ = Player::dark;
    } else if (!dark_king) {
        winner_ = Player::light;
    }

    return true; // this is wrong
}