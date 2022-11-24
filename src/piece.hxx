#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "position_set.hxx"

class Piece {
protected:
    Player player_;
    Position_set allowable_moves_;

public:
    // Piece positions will use `int` coordinates.
    using Position = ge211::Posn<int>;
    virtual Position_set calculate_moves(Position);

    // updates allowable_moves_
    void set_moves(Position);
    Piece(Player, Position);
};

class Pawn : public Piece
{
public:
    Pawn(Player, Position);
private:
    ge211::Image_sprite piece_sprite_;
    bool first_move_;
    // compute all positions a piece can move to
    Position_set calculate_moves(Position) override;

};
// TODO: children piece classes