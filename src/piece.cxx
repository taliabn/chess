#include "piece.hxx"

using namespace ge211;
using namespace std;

Piece::Piece()
: player_(Player::neither)
{}

Piece::Piece(Player player, Position pos)
        : player_(player)
{
}

Piece
Piece::piece_at_(ge211::Posn<int> pos, std::vector<std::unique_ptr<Piece>>
&square_vec)
{
    return *square_vec[8*pos.x + pos.y];
}

bool
good_position(ge211::Posn<int> pos)
{
    return 0 <= pos.x && pos.x < 8 &&
           0 <= pos.y && pos.y < 8;
}

// This shouldn't ever be called, all children will override calculate_moves
Position_set
Piece::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>>
&square_vec) {
    Position_set pset = {};
    return pset;
}

void
Piece::set_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec){
    allowable_moves_ = calculate_moves(pos, square_vec);
}

Position_set
Piece::find_line(Position pos, std::vector<ge211::geometry::Dims<int>> dims,
                 std::vector<std::unique_ptr<Piece>> &square_vec, bool
                 no_line) {
    Position_set pset = {};

    for (auto dim: dims) {
        Position advanced_pos = {pos.x + dim.width, pos.y + dim.height};

        while (good_position(advanced_pos)) {
            //If the position contains a piece that turn_ owns, break from
            // loop before adding the move.
            if (piece_at_(advanced_pos, square_vec).player() != player_) {
                pset[advanced_pos] = true;
            } else {
                break;
            }

            //If the position contains an opposing piece, break from loop
            // after including the move in the first if statement. If
            // the noloop flag is set, break after first move
            if (piece_at_(advanced_pos, square_vec).player() == other_player
            (player_) ||
                no_line) {
                break;

            }

            advanced_pos.x += dim.width;
            advanced_pos.y += dim.height;

        }
    }

    return pset;

}


Pawn::Pawn(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
Pawn::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    Position_set pset = {};
    int move_direction = -1;
    if(player_ == Player::dark) {
        move_direction = 1;
    }

    bool unblocked_way = true;

    //Add advancing moves if pawn hasn't reached the end of the board
    Position advanced_pos = {pos.x, pos.y + move_direction};
    if(good_position(advanced_pos) && piece_at_
    (advanced_pos, square_vec).player() == Player::neither) {
        pset[{advanced_pos}] = true;
    } else {
        unblocked_way = false;
    }

    bool first_move = (player_ == Player::light && pos.y == 6) || (player_ ==
                                                                   Player::dark && pos.y == 1);

    //Add first double move if pawn hasn't moved yet and square is unoccupied
    if(first_move && unblocked_way && piece_at_({pos.x, pos.y + (2 *
    move_direction)},square_vec).player() == Player::neither) {
        pset[{pos.x, pos.y + (2 * move_direction)}] = true;
    }

    //Calculate capture moves
    if (good_position({advanced_pos.x - 1, advanced_pos.y})) {
        if (piece_at_({advanced_pos.x - 1, advanced_pos.y},
                      square_vec).player() ==
            other_player(player_)) {
            pset[{advanced_pos.x - 1, advanced_pos.y}] = true;
        }
    }

    if (good_position({advanced_pos.x + 1, advanced_pos.y})) {
        if (piece_at_({advanced_pos.x + 1, advanced_pos.y},
                      square_vec).player() ==
            other_player(player_)) {
            pset[{advanced_pos.x + 1, advanced_pos.y}] = true;
        }
    }

    return pset;
}

Knight::Knight(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
Knight::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2,
                        -1}
    };

    return find_line(pos, move_dims, square_vec, true);
}


Bishop::Bishop(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
Bishop::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, square_vec, false);
}


Rook::Rook(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
Rook::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    return find_line(pos, move_dims, square_vec, false);
}


Queen::Queen(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
Queen::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, square_vec, false);
}


King::King(Player player, Position pos)
        :Piece(player, pos)
{}

Position_set
King::calculate_moves(Position pos, std::vector<std::unique_ptr<Piece>> &square_vec) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, square_vec, true);
}