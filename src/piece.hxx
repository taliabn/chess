#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "position_set.hxx"
#include <vector>

// Returns whether the given position is in bounds.
bool good_position(ge211::Posn<int>);

// Base class that children build from
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

    // Returns the piece type
    virtual const char* get_piece_type()
    {return piece_type; }

protected:
    // Holds a string with the name of the piece
    const char* piece_type = "None";
    // Holds the player the piece belongs to
    Player player_;
    Position_set allowable_moves_; // all positions piece can move to

    // Returns a position set with the positions a piece can move to. Takes
    // the position of the piece, a vector of directions the piece can move
    // in (stored in a dimension vector), the square_vec that holds the board
    // state, and a boolean that declares whether the piece can move multiple
    // times in the same direction (kings cannot move multiple times but
    // queens can).
    Position_set find_line(
            Position pos, std::vector<ge211::geometry::Dims<int>> dims,
            std::vector<std::unique_ptr<Piece>> &square_vec, bool no_line);
    // returns piece located at given square on board
    // this is used internally within Piece
    Piece piece_at_(ge211::Posn<int> pos, std::vector<std::unique_ptr<Piece>>
    &square_vec);
};

// Holds pawn child of piece
class Pawn : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    Pawn(Player player, Position pos);

    //Calculates the viable moves for a pawn at a given position
    Position_set calculate_moves(Position,
                 std::vector<std::unique_ptr<Piece>> &square_vec) override;

    //Overrides the virtual function in Piece of the same name to return "Pawn"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to pawn
    const char* piece_type = "Pawn";

};

// Holds knight child of piece
class Knight : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    Knight(Player player, Position pos);

    //Calculates the viable moves for a knight at a given position
    Position_set calculate_moves(Position,
                    std::vector<std::unique_ptr<Piece>> &square_vec) override;

    //Overrides the virtual function in Piece of the same name to return
    // "Knight"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to Knight
    const char* piece_type = "Knight";
};

// Holds bishop child of piece
class Bishop : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    Bishop(Player player, Position pos);

    //Calculates the viable moves for a bishop at a given position
    Position_set calculate_moves(Position,
                 std::vector<std::unique_ptr<Piece>> &square_vec) override;

    //Overrides the virtual function in Piece of the same name to return
    // "Bishop"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to Bishop
    const char* piece_type = "Bishop";
};

// Holds rook child of piece
class Rook : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    Rook(Player player, Position pos);

    //Calculates the viable moves for a rook at a given position
    Position_set calculate_moves(Position,
                 std::vector<std::unique_ptr<Piece>> &square_vec) override;
    //Overrides the virtual function in Piece of the same name to return
    // "Rook"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to Rook
    const char* piece_type = "Rook";
};

// Holds queen child of piece
class Queen : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    Queen(Player player, Position pos);

    //Calculates the viable moves for the queen at a given position
    Position_set calculate_moves(Position,
                 std::vector<std::unique_ptr<Piece>> &square_vec) override;

    //Overrides the virtual function in Piece of the same name to return
    // "Queen"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to Queen
    const char* piece_type = "Queen";
};

// Holds king child of piece
class King : public Piece
{
public:
    //Constructor, calls piece constructor to initialize player information
    King(Player player, Position pos);

    //Calculates the viable moves for the king at a given position
    Position_set calculate_moves(Position,
                 std::vector<std::unique_ptr<Piece>> &square_vec) override;

    //Overrides the virtual function in Piece of the same name to return
    // "King"
    const char* get_piece_type() override
    {return piece_type; }
private:
    //Set piece type to King
    const char* piece_type = "King";
};
