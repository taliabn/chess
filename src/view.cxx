#include "view.hxx"
// Convenient type aliases:
using Color = ge211::Color;

// Constant values
static Color const dark_square {179, 132, 100};
static Color const light_square {235, 219, 179};
static Color const green_color {130,151,104};
static int const grid_size = 48; // side length of each square on the board


View::View(Model const& model)
        : model_(model),
          dark_square_sprite_({grid_size, grid_size}, dark_square),
          light_square_sprite_({grid_size, grid_size}, light_square),
          green_square_sprite_({grid_size, grid_size}, green_color),
          green_circle_sprite_(grid_size/6, green_color)
{ }


void
View::draw(ge211::Sprite_set& set)
{
    for (auto pos : model_.board()) {

        // draw background board squares
        if (pos == model_.square_clicked()) {
            set.add_sprite(green_square_sprite_, board_to_screen(pos));
        } else if ((pos.x + pos.y)%2) {
            set.add_sprite(dark_square_sprite_, board_to_screen(pos));
        } else {
            set.add_sprite(light_square_sprite_, board_to_screen(pos));
        }

        if (model_.viable_moves()[pos]) {
            // indicate squares that selected piece can move to
            set.add_sprite(green_circle_sprite_, board_to_screen(pos)
            .down_right_by({grid_size*1/3, grid_size*1/3}), 2);
        }

        // draw sprite for piece at square
        draw_piece_sprite_(pos, set);
    }
}


void
View::draw_piece_sprite_(Position pos, ge211::Sprite_set& set){
    const char* piece_type = model_.piece_type_at(pos);

    if (piece_type == nullptr || strcmp(piece_type, "None") == 0) {
        return;
    }

    if (strcmp(piece_type, "Pawn") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_pawn_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        } else {
            set.add_sprite(dark_pawn_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        }
    } else if (strcmp(piece_type, "Knight") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_knight_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        } else {
            set.add_sprite(dark_knight_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        }
    } else if (strcmp(piece_type, "Bishop") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_bishop_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.4));
        } else {
            set.add_sprite(dark_bishop_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        }
    } else if (strcmp(piece_type, "Rook") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_rook_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        } else {
            set.add_sprite(dark_rook_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        }
    } else if (strcmp(piece_type, "Queen") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_queen_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.1));
        } else {
            set.add_sprite(dark_queen_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.1));
        }
    } else if (strcmp(piece_type, "King") == 0) {
        if (model_[pos] == Player::light) {
            set.add_sprite(light_king_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        } else {
            set.add_sprite(dark_king_sprite_, board_to_screen(pos), 1,
                           ge211::Transform::scale(0.11));
        }
        if (model_.is_game_over()) {
            if (model_[pos] == Player::light && model_.winner() ==
                                                Player::light) {
                set.add_sprite(light_win_sprite_, board_to_screen(pos), 2,
                               ge211::Transform::scale(0.3)); //0.32
            } else if (model_[pos] == Player::dark && model_.winner() ==
                                                      Player::dark){
                set.add_sprite(dark_win_sprite_, board_to_screen(pos), 2,
                               ge211::Transform::scale(0.3));
            }
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