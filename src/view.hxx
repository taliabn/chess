#pragma once

#include "model.hxx"

class View
{
public:
    // View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    // View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // Constructs a view that knows about the given model.
    explicit View(Model const& model);

    // draw state of game to screen
    void draw(ge211::Sprite_set& set);

    // returns dimensions of game window
    Dimensions initial_window_dimensions() const;

    // returns title of game
    std::string initial_window_title() const;

    // Converts an abstract board position to a concrete screen
    // position.
    Position
    board_to_screen(Model::Position board_pos) const;

    // Converts a concrete screen (pixel) position to an abstract board
    // position.
    Model::Position
    screen_to_board(Position screen_pos) const;


private:
    Model const& model_;
    // sprites
    ge211::Rectangle_sprite const dark_square_sprite_;
    ge211::Rectangle_sprite const light_square_sprite_;
    ge211::Rectangle_sprite const green_square_sprite_;
    ge211::Circle_sprite const green_circle_sprite_;
    ge211::Image_sprite light_pawn_sprite_ {"light_pawn.png"};
    ge211::Image_sprite dark_pawn_sprite_ {"dark_pawn.png"};
    ge211::Image_sprite light_knight_sprite_ {"light_knight.png"};
    ge211::Image_sprite dark_knight_sprite_ {"dark_knight.png"};
    ge211::Image_sprite light_bishop_sprite_ {"light_bishop.png"};
    ge211::Image_sprite dark_bishop_sprite_ {"dark_bishop.png"};
    ge211::Image_sprite light_rook_sprite_ {"light_rook.png"};
    ge211::Image_sprite dark_rook_sprite_ {"dark_rook.png"};
    ge211::Image_sprite light_queen_sprite_ {"light_queen.png"};
    ge211::Image_sprite dark_queen_sprite_ {"dark_queen.png"};
    ge211::Image_sprite light_king_sprite_ {"light_king.png"};
    ge211::Image_sprite dark_king_sprite_ {"dark_king.png"};
    ge211::Image_sprite light_win_sprite_ {"light_win.png"};
    ge211::Image_sprite dark_win_sprite_ {"dark_win.png"};

    // draws sprite of piece at given position to board
    void draw_piece_sprite_(Position pos, ge211::Sprite_set& set);
};
