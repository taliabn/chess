#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "board.hxx"
#include "piece.hxx"
#include <string.h>
#include <iostream>
#include <vector>
#include <typeinfo>

// Represents the state of the chess game
class Model
{
public:

    /***************************************************/
    /*** DON'T CHANGE ANYTHING IN THE PUBLIC SECTION ***/
    /***************************************************/

    // Model dimensions will use `int` coordinates, as board dimensions do.
    using Dimensions = Board::Dimensions;

    // Model positions will use `int` coordinates, as board positions do.
    using Position = Board::Position;

    // Model rectangles will use `int` coordinates, as board rectangles do.
    using Rectangle = Board::Rectangle;

    // Constructs a model with an 8x8 board
    explicit Model();

    // Returns a rectangle containing all the positions of the board.
    // This can be used to iterate over the positions.
    Rectangle board() const;
    // adds pieces to the board in the appropriate starting locations
    void setup_pieces(Board const&);

    // Returns whether the game is finished. This is true when one player's
    // king has been taken
    bool is_game_over() const
    { return turn() == Player::neither; }

    // Returns the current turn, or `Player::neither` if the game is
    // over.
    Player turn() const
    { return turn_; }

    // Returns the winner, or `Player::neither` if there is no winner
    // (either because the game isn't over, or because it's a draw).
    Player winner() const
    { return winner_; }

    // Returns the piece at the given position
    Piece operator[](Position) const;
    Piece piece_at(Position) const;

    void on_first_click(Position);

    bool piece_clicked() const
    { return piece_clicked_; }

    Position square_clicked() const
    { return square_clicked_; }

    // move piece at position square_clicked to position dst
    void play_move(Position dst);

    // check if other player has a king
    bool check_king();


private:
    Player turn_   = Player::light;
    Player winner_ = Player::neither;
    Board board_;
    // has a playable piece been selected to be moved
    bool piece_clicked_ = false;
    // if so, what square is it in
    Position square_clicked_ = {-1,-1};

};
