#pragma once

#include "model.hxx"

class View
{
public:
    // View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    // View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    // View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    // Constructs a view that knows about the given model.
    explicit View(Model const& model);

    // draw state of game to screen
    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

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
    ge211::Rectangle_sprite const dark_square_sprite;
    ge211::Rectangle_sprite const light_square_sprite;
	ge211::Image_sprite light_pawn_sprite{"light_pawn.png"};
    ge211::Image_sprite dark_pawn_sprite{"dark_pawn.png"};
	ge211::Image_sprite light_knight_sprite{"light_knight.png"};
	ge211::Image_sprite dark_knight_sprite{"dark_knight.png"};
    ge211::Image_sprite light_bishop_sprite{"light_bishop.png"};
    ge211::Image_sprite dark_bishop_sprite{"dark_bishop.png"};
    ge211::Image_sprite light_rook_sprite{"light_rook.png"};
    ge211::Image_sprite dark_rook_sprite{"dark_rook.png"};
    ge211::Image_sprite light_queen_sprite{"light_queen.png"};
    ge211::Image_sprite dark_queen_sprite{"dark_queen.png"};
    ge211::Image_sprite light_king_sprite{"light_king.png"};
    ge211::Image_sprite dark_king_sprite{"dark_king.png"};
	
};
