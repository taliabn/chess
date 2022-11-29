#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "position_set.hxx"

class Piece
{
public:
    // Piece positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // default "dummy" piece (e.g. no player's piece is there)
    Piece();
    // primary constructor that children will call
    Piece(Player player, Position pos, Piece (&squares)[8][8]);

    // compute all positions piece can move to
    virtual Position_set calculate_moves(Position, Piece (&squares)[8][8]);
    // updates allowable_moves_
    void set_moves(Position, Piece (&squares)[8][8]);
    // Returns the player who owns the piece
    Player player() const
    { return player_; }
    // Returns all positions piece can move to
    Position_set allowable_moves() const
    { return allowable_moves_; }
    // Returns whether the given position is in bounds.
    bool good_position(ge211::Posn<int>);

protected:
    Player player_;
    Position_set allowable_moves_; // all positions piece can move to
    Position_set find_line(
            Position pos, std::vector<ge211::geometry::Dims<int>> dims,
            Piece (&squares)[8][8], bool no_line);
    // returns piece located at given square on board
        // this is used internally within Piece
    Piece piece_at_(ge211::Posn<int> pos, Piece (&squares)[8][8]);
};

class Pawn : public Piece
{
public:
    Pawn(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    bool first_move_; // has this pawn made its first move yet
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};


class Knight : public Piece
{
public:
    Knight(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};


class Bishop : public Piece
{
public:
    Bishop(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};


class Rook : public Piece
{
public:
    Rook(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};


class Queen : public Piece
{
public:
    Queen(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};


class King : public Piece
{
public:
    King(Player player, Position pos, Piece (&squares)[8][8]);
private:
    // ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Piece (&squares)[8][8]) override;
};
