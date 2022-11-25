#include "piece.hxx"
#include "board.hxx"
#include "model.hxx"

Piece::Piece(Player player, Position pos)
    : player_(player)
{
    set_moves(pos);
};

// This shouldn't ever be called, all children will override calculate_moves
Position_set
Piece::calculate_moves(Position pos) {
    Position_set pset = {};
    return pset;
}

void
Piece::set_moves(Position pos){
    allowable_moves_ = calculate_moves(pos);
}

Position_set
Piece::find_line(Position pos, std::vector<ge211::geometry::Dims<int>> dims,
                 Model const& model, bool no_line) {
    Position_set pset = {};

    for (auto dim: dims) {
        Position advanced_pos = {pos.x + dim.x, pos.y + dim.y};

        while (good_position(advanced_pos)) {
            if (model[advanced_pos].player != player_) {
                pset[advanced_pos] = true;
            }

            if (model[advanced_pos].player == other_player(player_) ||
            no_line) {
                break;
            }
        }
    }

    return pset;

}

Pawn::Pawn(Player player, Position pos)
    :Piece(player, pos),
    // these sprites are just as a test, not necessarily final choice for image
    // use ternary operator to determine which sprite to use based on player
    piece_sprite_(player==Player::light ?
                    ge211::Image_sprite("./Resources/white-pawn.png") :
                    ge211::Image_sprite("./Resources/dark-pawn.png")),
    first_move_(true)
{
    // // this will initialize value in available_moves
    // calculate_moves(pos);
};


Position_set
Pawn::calculate_moves(Position pos, Model const& model) {
    Position_set pset = {};
    int move_direction = 1;
    if(player_ == Player::dark) {
        move_direction = -1;
    }

    //Add first double move if pawn hasn't moved yet and square is unoccupied
    if(first_move_ && model[{pos.x, pos.y + (2 * move_direction)}] ==
    Player::neither) {
        pset[{pos.x, pos.y + (2 * move_direction)}] = true;
    }

    //Add advancing moves if pawn hasn't reached the end of the board
    Position advanced_pos = {pos.x, pos.y + move_direction};
    if((0 <= advanced_pos.y) && (7 >= advanced_pos.y) && model[advanced_pos]
    .player == Player::neither) {
        pset[{advanced_pos}] = true;
    }

    //Calculate capture moves
    if(model[{advanced_pos.x - 1, advanced_pos.y}].player == other_player
    (player_)) {
        pset[{advanced_pos.x - 1, advanced_pos.y}] = true;
    }

    if(model[{advanced_pos.x + 1, advanced_pos.y}].player == other_player
            (player_)) {
        pset[{advanced_pos.x + 1, advanced_pos.y}] = true;
    }

    // allowable_moves_ = pset; // this is wrong
    return pset;
}

// Position_set
// Pawn::find_line() {
//     // TODO
//     Position_set pset;
//     allowable_moves_ = pset; // this is wrong
// }
// TODO constructors for each piece type
// TODO calculate_moves for each piece type

Knight::Knight(Player player, Position pos)
        :Piece(player, pos),
        // these sprites are just as a test, not necessarily final choice for image
        // use ternary operator to determine which sprite to use based on player
         piece_sprite_(player==Player::light ?
                       ge211::Image_sprite("./Resources/white-knight.png") :
                       ge211::Image_sprite("./Resources/dark-knight.png"))
{
    // // this will initialize value in available_moves
    // calculate_moves(pos);
};

Position_set
Knight::calculate_moves(Position pos, Model const& model) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 2}, {2, 1} {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2,
                                                                          -1}
    };

    return find_line(pos, move_dims, model, true);
}

Position_set
Bishop::calculate_moves(Position pos, Model const& model) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, model, false);
}

Position_set
Rook::calculate_moves(Position pos, Model const& model) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    return find_line(pos, move_dims, model, false);
}

Position_set
Queen::calculate_moves(Position pos, Model const& model) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, model, false);
}

Position_set
King::calculate_moves(Position pos, Model const& model) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, model, true);
}