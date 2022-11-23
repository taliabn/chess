#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "board.hxx"
#include <iostream>
#include <vector>

// Represents the state of the chess game
class Model
{
public:
    /***************************************************/
    /*** DON'T CHANGE ANYTHING IN THE PUBLIC SECTION ***/
    /***************************************************/

    /// Model dimensions will use `int` coordinates, as board dimensions do.
    using Dimensions = Board::Dimensions;

    /// Model positions will use `int` coordinates, as board positions do.
    using Position = Board::Position;

    /// Model rectangles will use `int` coordinates, as board rectangles do.
    using Rectangle = Board::Rectangle;

    /// Constructs a model with an 8x8 board
    explicit Model();

    /// Returns a rectangle containing all the positions of the board.
    /// This can be used to iterate over the positions.
    Rectangle board() const;

    /// Returns whether the game is finished. This is true when neither
    /// player can move.
    bool is_game_over() const
    { return turn() == Player::neither; }

    /// Returns the current turn, or `Player::neither` if the game is
    /// over.
    Player turn() const
    { return turn_; }

    /// Returns the winner, or `Player::neither` if there is no winner
    /// (either because the game isn't over, or because it's a draw).
    Player winner() const
    { return winner_; }

    /// Returns the player at the given position, or `Player::neither` if
    /// the position is unoccupied.
    ///
    /// ## Errors
    ///
    ///  - Throws `ge211::Client_logic_error` if the position is out of
    ///    bounds.
    Player operator[](Position) const;


    void play_move(Position);

private:
    Player turn_   = Player::dark;
    Player winner_ = Player::neither;
    Board board_;
};
