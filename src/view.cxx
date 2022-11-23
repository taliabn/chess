#include "view.hxx"
// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// Constant values
static Color const black {0, 0, 0};
static Color const white {255, 255, 255};
// side length of each square on the board
static int const grid_size = 36; // arbitratily chosen

View::View(Model const& model)
        : model_(model)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
}
