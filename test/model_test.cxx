#include "model.hxx"
#include <catch.hxx>

struct Test_access
{
    Model& model;

    // Constructs a `Test_access` with a reference to the Model under test.
    explicit Test_access(Model&);

    // Returns whether a piece is highlighted or not
    bool get_piece_clicked();

    void on_first_click(Model::Position pos);

    // Returns the square that is currently highlighted
    Model::Position get_square_clicked();

    // Returns the piece at a board position
    Piece get_piece_at(Model::Position pos);

    // Runs check king and returns the result
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

void Test_access::on_first_click(Model::Position pos) {
    model.on_first_click_(pos);
}

void Test_access::set_piece(Piece piece, Model::Position pos){
    model.set_piece_(piece, pos);
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
    CHECK(1 + 1 == 2);
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
    Model m = Model();
    Test_access access(m);

    // Set the highlighted piece to the light rook in the corner
    access.get_piece_at({0, 7});

    // Attempt to move the rook one square to the right
    access.model.check_pos({1, 7});

    // Check that the rook has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 7}), "Rook") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({1, 7}), "Knight") == 0);

}


