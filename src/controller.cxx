#include "controller.hxx"

Controller::Controller()
        : view_(model_)
{ }


void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}


void
Controller::on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
{
    if (model_.is_game_over()) {return;}

    Position board_pos = view_.screen_to_board(position);
    // bool p = model_[model_.square_clicked()].allowable_moves()[board_pos];
    if (model_.piece_clicked() && model_[model_.square_clicked()]
    .allowable_moves()[board_pos]){
        model_.play_move(board_pos);
    } else {
        if(model_[position].player() == model_.turn()){
            model_.on_first_click(board_pos);
        }
    }
}


View::Dimensions
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}


std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}