#include "piece.hxx"

Piece::Piece(Player player, Position pos)
    : player_(player)
{
    set_moves(pos);
};

// This shouldn't ever be called, all children will override calculate_moves
Position_set
Piece::calculate_moves(Position pos) {
    Position_set pset;
    return pset;
}

void
Piece::set_moves(Position pos){
    allowable_moves_ = calculate_moves(pos);
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
Pawn::calculate_moves(Position pos) {
    // TODO
    Position_set pset;
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