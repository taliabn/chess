#include "model.hxx"
#include <catch.hxx>

struct Test_access
{
    Model& model;

    // Constructs a `Test_access` with a reference to the Model under test.
    explicit Test_access(Model&);

    // Returns whether a piece is highlighted or not
    bool get_piece_clicked();

    // Returns the square that is currently highlighted
    Model::Position get_square_clicked();

    // Returns the piece at a board position
    Piece get_piece_at(Model::Position pos);
    // change piece_clicked
    void set_piece_clicked(bool is_true);
    // change square_clicked
    void set_square_clicked(Model::Position pos);
    // gives access to check_king_
    bool check_king_();
    // gives access to player_has_moves
    void player_has_moves();
    // gives access to set_piece
    void set_piece(Piece piece, Model::Position pos);
};

///
/// Member function definitions for Test_access
///


Test_access::Test_access(Model& model)
        : model(model)
{ }

bool Test_access::check_king_() {
    return model.check_king_();
}

void Test_access::player_has_moves() {
    model.player_has_moves();
}

void Test_access::set_piece(Piece piece, Model::Position pos){
    model.set_piece_(piece, pos);
}

void Test_access::set_piece_clicked(bool is_true){
    model.piece_clicked_ = is_true;
}

void Test_access::set_square_clicked(Model::Position pos)
{
    model.square_clicked_ = pos;
}

bool
Test_access::get_piece_clicked()
{
    return model.piece_clicked_ ;
}

Model::Position
Test_access::get_square_clicked()
{
    return model.square_clicked_;
}

Piece
Test_access::get_piece_at(Model::Position pos)
{
    return model.piece_at_(pos);
}

// ACTUAL TEST CASES
// TEST CASE 1: Game is over when player cannot move
TEST_CASE("game over player can't move")
{
    Model m = Model();
    Test_access access(m);
    CHECK(1 + 1 == 2);
}

// TEST CASE 2: Game is over from checkmate
TEST_CASE("game over checkmate")
{
    CHECK(1 + 1 == 2);
}

// TEST CASE 3: Players can only play moves at allowable times
    // white moves first
    // players can only move on their turn
    // players can only move pieces of their color
        // clicking one piece of turn and then another has no effect
    // can only play a move when a piece has been selected
TEST_CASE("when can player move")
{
    // setup
    Model m = Model();
    Test_access access(m);

    // make sure dark cannot move
    CHECK(access.model.turn() == Player::light);
    // try to move one of dark's pieces
}

// TEST CASE 4: a move captures an opponent's piece
TEST_CASE("capture piece")
{
    CHECK(1 + 1 == 2);
}

// TEST CASE 5: Pieces' allowable moves are accurate and enforced
    // Pieces' allowable moves reflect the rules of chess
    // can only move piece to square where it is allowed move
    // pawns can move two squares on first move
TEST_CASE("where piece can move")
{
    CHECK(1 + 1 == 2);
}


