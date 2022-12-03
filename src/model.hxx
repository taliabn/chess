#pragma once

#include <ge211.hxx>
#include "player.hxx"
#include "piece.hxx"
#include <string.h>
#include <vector>

// Represents the state of the chess game
class Model
{
public:

    // Model dimensions will use `int` coordinates
    using Dimensions = ge211::Dims<int>;

    // Model positions will use `int` coordinates
    using Position = ge211::Posn<int>;

    // Model rectangles will use `int` coordinates
    using Rectangle = ge211::Rect<int>;;

    // Constructs a model with an 8x8 board
    explicit Model();

    // Returns a rectangle containing all the positions of the board.
    // This can be used to iterate over the positions.
    Rectangle board() const;

    // Returns whether the game is finished. This is true when one player's
    // king has been taken
    bool is_game_over() const
    { return turn_ == Player::neither; }

    // Returns the current turn, or `Player::neither` if the game is
    // over.
    Player turn() const
    { return turn_; }

    // Returns the winner, or `Player::neither` if there is no winner
    Player winner() const
    { return winner_; }

    // Returns the player at the given position
    // this gets used by the view
    Player operator[](Position) const;

    // returns whether a playable piece has been selected to be moved
    bool piece_clicked() const
    { return piece_clicked_; }
    // returns the position selected piece is in
    Position square_clicked() const
    { return square_clicked_; }

    // returns the position set of viable moves
    Position_set viable_moves() const
    { return viable_moves_; }

    // move piece at position square_clicked to position dst
    void play_move(Position dst);

    // Check the position to determine whether to set highlighted square vs.
    // move a piece
    void check_pos(Position pos);

    // Returns a string that contains the piece type at a given position
    const char* piece_type_at(Position pos) const;

    // Returns a rectangle containing all the positions of the board. This
    // can be used to iterate over the positions:
    Rectangle all_positions() const;

    // Converts a board position to an index that can be used for square_vec
    int pos_to_idx(Position pos) const;

#ifdef CS211_TESTING
    // When this class is compiled for testing, members of a struct named
    // Test_access will be allowed to access private members of this class.
    friend struct Test_access;
#endif


private:
    // Set the first turn to the light player. Holds the current player
    Player turn_   = Player::light;
    // Holds the winner of the game.
    Player winner_ = Player::neither;

    // Holds whether a piece is selected or not
    bool piece_clicked_ = false;
    // If piece is selected, what position is it located at
    Position square_clicked_ = {-1,-1};

    // This is a vector of unique pointers. It stores a pointer to the piece
    // at an index, which can be found with pos_to_inx(pos).
    std::vector<std::unique_ptr<Piece>> square_vec;

    // The position set of viable moves for the highlighted piece to make
    Position_set viable_moves_;

    // Returns the piece located in squares_ at the given position
    // this is used internally within Model
    Piece piece_at_(ge211::Posn<int>);
    // Check if other player has a king. Called after each move, and sets
    // game over states if player does not have a king.
    bool check_king_();

    // If a player doesn't have any possible moves, set the winner to the
    // other player and end the game
    void player_has_moves();

    // Sets given position on board to hold the given piece
    void set_piece_(Position src, Position dst);
    void setup_pieces();

    // selects a piece
    // unchecked precondition: piece can be moved
    void on_first_click_(Position);
};