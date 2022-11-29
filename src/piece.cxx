#include "piece.hxx"

using namespace ge211;

Piece::Piece()
: player_(Player::neither)
{}

Piece::Piece(Player player, Position pos, Piece (&squares)[8][8])
        : player_(player)
{
    set_moves(pos, squares);
}

Piece
Piece::piece_at_(ge211::Posn<int> pos, Piece (&squares)[8][8])
{
    return squares[pos.x][pos.y];
}

bool
Piece::good_position(ge211::Posn<int> pos)
{
    return 0 <= pos.x && pos.x < 8 &&
           0 <= pos.y && pos.y < 8;
}

// This shouldn't ever be called, all children will override calculate_moves
Position_set
Piece::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    Position_set pset = {};
    return pset;
}

void
Piece::set_moves(Position pos, Piece (&squares)[8][8]){
    allowable_moves_ = calculate_moves(pos, squares);
}

Position_set
Piece::find_line(Position pos, std::vector<ge211::geometry::Dims<int>> dims,
                 Piece (&squares)[8][8], bool no_line) {
    Position_set pset = {};

    for (auto dim: dims) {
        Position advanced_pos = {pos.x + dim.width, pos.y + dim.height};

        while (good_position(advanced_pos)) {
            if (piece_at_(advanced_pos, squares).player() != player_) {
                pset[advanced_pos] = true;
            }

            if (piece_at_(advanced_pos, squares).player() == other_player
            (player_) ||
                no_line) {
                break;

            }
        }
    }

    return pset;

}


Pawn::Pawn(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares),
        // these sprites are just as a test, not necessarily final choice for image
        // use ternary operator to determine which sprite to use based on player
        //  piece_sprite_(player==Player::light ?
        //                ge211::Image_sprite("./Resources/white-pawn.png") :
        //                ge211::Image_sprite("./Resources/dark-pawn.png")),
         first_move_(true)
{}

Position_set
Pawn::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    Position_set pset = {};
    int move_direction = 1;
    if(player_ == Player::dark) {
        move_direction = -1;
    }

    //Add first double move if pawn hasn't moved yet and square is unoccupied
    if(first_move_ && piece_at_({pos.x, pos.y + (2 * move_direction)},
                               squares).player() == Player::neither) {
        pset[{pos.x, pos.y + (2 * move_direction)}] = true;
    }

    //Add advancing moves if pawn hasn't reached the end of the board
    Position advanced_pos = {pos.x, pos.y + move_direction};
    if((0 <= advanced_pos.y) && (7 >= advanced_pos.y) && piece_at_
    (advanced_pos, squares).player() == Player::neither) {
        pset[{advanced_pos}] = true;
    }

    //Calculate capture moves
    if(piece_at_({advanced_pos.x - 1, advanced_pos.y}, squares).player() ==
    other_player
            (player_)) {
        pset[{advanced_pos.x - 1, advanced_pos.y}] = true;
    }

    if(piece_at_({advanced_pos.x + 1, advanced_pos.y}, squares).player() ==
    other_player
            (player_)) {
        pset[{advanced_pos.x + 1, advanced_pos.y}] = true;
    }

    return pset;
}


Knight::Knight(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares)
        // these sprites are just as a test, not necessarily final choice for image
        // use ternary operator to determine which sprite to use based on player
        //  piece_sprite_(player==Player::light ?
        //                ge211::Image_sprite("./Resources/white-pawn.png") :
        //                ge211::Image_sprite("./Resources/dark-pawn.png"))
{}

Position_set
Knight::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2,
                        -1}
    };

    return find_line(pos, move_dims, squares, true);
}


Bishop::Bishop(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares)
        // these sprites are just as a test, not necessarily final choice for image
        // use ternary operator to determine which sprite to use based on player
        //  piece_sprite_(player==Player::light ?
        //                ge211::Image_sprite("./Resources/white-pawn.png") :
        //                ge211::Image_sprite("./Resources/dark-pawn.png"))
{}

Position_set
Bishop::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, squares, false);
}


Rook::Rook(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares)
// these sprites are just as a test, not necessarily final choice for image
// use ternary operator to determine which sprite to use based on player
//  piece_sprite_(player==Player::light ?
//                ge211::Image_sprite("./Resources/white-pawn.png") :
//                ge211::Image_sprite("./Resources/dark-pawn.png"))
{}

Position_set
Rook::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    return find_line(pos, move_dims, squares, false);
}


Queen::Queen(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares)
// these sprites are just as a test, not necessarily final choice for image
// use ternary operator to determine which sprite to use based on player
//  piece_sprite_(player==Player::light ?
//                ge211::Image_sprite("./Resources/white-pawn.png") :
//                ge211::Image_sprite("./Resources/dark-pawn.png"))
{}

Position_set
Queen::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, squares, false);
}


King::King(Player player, Position pos, Piece (&squares)[8][8])
        :Piece(player, pos, squares)
// these sprites are just as a test, not necessarily final choice for image
// use ternary operator to determine which sprite to use based on player
// piece_sprite_(player==Player::light ?
//   ge211::Image_sprite("./Resources/white-pawn.png") :
//   ge211::Image_sprite("./Resources/dark-pawn.png"))
{}

Position_set
King::calculate_moves(Position pos, Piece (&squares)[8][8]) {
    std::vector<ge211::geometry::Dims<int>> move_dims = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1},
            {1, 1}, {-1, 1}, {1, -1}, {-1, -1}
    };

    return find_line(pos, move_dims, squares, true);
}