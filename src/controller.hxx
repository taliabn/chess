#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    // These three delegate to the view:
    void draw(ge211::Sprite_set& set) override;
    View::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;

    // try to select piece or try to play move
    // behavior is dependent on value of "piece_clicked_" in model
    void on_mouse_down(ge211::Mouse_button m, ge211::Posn<int> position)
    override;

private:
    Model model_;
    View view_;


};
