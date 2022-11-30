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
    Position board_pos = view_.screen_to_board(position);
    model_.check_pos(board_pos);
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