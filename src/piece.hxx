#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "position_set.hxx"
#include <vector>


class Piece
{
public:
    // Piece positions will use `int` coordinates.
    using Position = ge211::Posn<int>;
    // default "dummy" piece (e.g. no player's piece is there)
    Piece();
    // primary constructor that children will call
    Piece(Player player, Position pos);

    // compute all positions piece can move to
    virtual Position_set calculate_moves(Position,
                                         std::vector<std::unique_ptr<Piece>> &square_vec);
    // updates allowable_moves_
    void set_moves(Position, std::vector<std::unique_ptr<Piece>>
    &square_vec);
    // Returns the player who owns the piece
    Player player() const
    { return player_; }
    // Returns all positions piece can move to
    Position_set allowable_moves() const
    { return allowable_moves_; }
    // Returns whether the given position is in bounds.
    bool good_position(ge211::Posn<int>);
    virtual const char* get_piece_type()
    {return piece_type; }

protected:
    const char* piece_type = "asdfaweof";
    Player player_;
    Position_set allowable_moves_; // all positions piece can move to
    Position_set find_line(
            Position pos, std::vector<ge211::geometry::Dims<int>> dims,
            std::vector<std::unique_ptr<Piece>> &square_vec, bool no_line);
    // returns piece located at given square on board
        // this is used internally within Piece
    Piece piece_at_(ge211::Posn<int> pos, std::vector<std::unique_ptr<Piece>>
    &square_vec);
};

class Pawn : public Piece
{
public:
    int test = 4;
    Pawn(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "Pawn";

};


class Knight : public Piece
{
public:
    Knight(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "Knight";
};


class Bishop : public Piece
{
public:
    Bishop(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "Bishop";
};


class Rook : public Piece
{
public:
    Rook(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "Rook";
};


class Queen : public Piece
{
public:
    Queen(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "Queen";
};


class King : public Piece
{
public:
    King(Player player, Position pos);
    Position_set calculate_moves(Position,
                                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    const char* get_piece_type() override
    {return piece_type; }
private:
    const char* piece_type = "King";
};
