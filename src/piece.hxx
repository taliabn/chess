#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "position_set.hxx"
#include "board.hxx"
#include "model.hxx"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


class Piece
{
public:
    // Piece positions will use `int` coordinates.
    using Position = ge211::Posn<int>;
    // compute all positions a piece can move to
    virtual Position_set calculate_moves(Position, Board const& board);

    // updates allowable_moves_
    void set_moves(Position, Board const& board);
    Piece(Player, Position, Board const& board);
    Piece(); // default "dummy" piece
    // Returns the player who owns the piece
    Player player() const
    { return player_; }

protected:
    Player player_;
    Position_set allowable_moves_;
    Position_set find_line(
            Position, std::vector<ge211::geometry::Dims<int>>,
            Board const&, bool);
};

class Pawn : public Piece
{
public:
    Pawn(Player player, Position posn, Board const& board);
private:
    ge211::Image_sprite piece_sprite_;
    bool first_move_;
    Position_set calculate_moves(Position, Board const&) override;
};


class Knight : public Piece
{
public:
    Knight(Player player, Position posn, Board const& board);
private:
    ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Board const&) override;
};


class Bishop : public Piece
{
public:
    Bishop(Player player, Position posn, Board const& board);
private:
    ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Board const&) override;
};


class Rook : public Piece
{
public:
    // Rook(Player player, Position posn, Board board);
    Rook(Player player, Position posn, Board board);
private:
    ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Board const&) override;
};


class Queen : public Piece
{
public:
    Queen(Player player, Position posn, Board const& board);
    Queen(Player player, Position posn);
private:
    ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Board const&) override;
};


class King : public Piece
{
public:
    King(Player player, Position posn, Board const& board);
private:
    ge211::Image_sprite piece_sprite_;
    Position_set calculate_moves(Position, Board const&) override;
};
