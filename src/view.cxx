#include "view.hxx"
// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// Constant values
static Color const dark_square {179, 132, 100};
static Color const light_square {235, 219, 179};
// side length of each square on the board
static int const grid_size = 48; // arbitrarily chosen

View::View(Model const& model)
        : model_(model),
          dark_square_sprite({grid_size, grid_size}, dark_square),
          light_square_sprite({grid_size, grid_size}, light_square)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // draw background board squares
    for (auto pos : model_.board()) {
        if ((pos.x + pos.y)%2) {
            set.add_sprite(dark_square_sprite, board_to_screen(pos));
        } else {
            set.add_sprite(light_square_sprite, board_to_screen(pos));
        }
    }
}

View::Position
View::board_to_screen(Model::Position pos) const
{
    return {grid_size * pos.x, grid_size * pos.y};
}


Model::Position
View::screen_to_board(View::Position pos) const
{
    return {pos.x / grid_size, pos.y / grid_size};
}

View::Dimensions
View::initial_window_dimensions() const
{
    return grid_size * model_.board().dimensions();
}

std::string
View::initial_window_title() const
{
    return "Chess";
}
