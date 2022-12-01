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

    for (auto pos : model_.board()) {
        const char* piece_type = model_.piece_type_at(pos);

        if (piece_type == nullptr) {
            continue;
        }
        if (strcmp(piece_type, "Pawn") == 0) {
            //  ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
            //                set.add_sprite(light_knight_sprite, pos, 1):
            //                ge211::Image_sprite{"dark_pawn.png"});
            set.add_sprite(light_pawn_sprite, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.4));
        } else if (strcmp(piece_type, "Knight") == 0) {
            // ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
            //               ge211::Image_sprite{"light_knight.png"} :
            //               ge211::Image_sprite{"dark_knight.png"});
            set.add_sprite(dark_knight_sprite, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.4));
		}
        // } else if (strcmp(piece_type, "Bishop") == 0) {
        //     ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
        //                   ge211::Image_sprite{"light_bishop.png"} :
        //                   ge211::Image_sprite{"dark_bishop.png"});
        //     set.add_sprite(piece_sprite_, board_to_screen(pos), 1);
        // } else if (strcmp(piece_type, "Rook") == 0) {
        //     ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
        //                   ge211::Image_sprite{"light_rook.png"} :
        //                   ge211::Image_sprite{"dark_rook.png"});
        //     set.add_sprite(piece_sprite_, board_to_screen(pos), 1);
        // } else if (strcmp(piece_type, "Queen") == 0) {
        //     ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
        //                   ge211::Image_sprite{"light_queen.png"} :
        //                   ge211::Image_sprite{"dark_queen.png"});
        //     set.add_sprite(piece_sprite_, board_to_screen(pos), 1);
        // } else if (strcmp(piece_type, "King") == 0) {
        //     ge211::Image_sprite piece_sprite_(model_[pos] == Player::light ?
        //                   ge211::Image_sprite{"light_king.png"} :
        //                   ge211::Image_sprite{"dark_king.png"});
        //     set.add_sprite(piece_sprite_, board_to_screen(pos), 1);
        // }
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
