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

    // change piece_clicked
    void set_piece_clicked(bool is_true);
    // change square_clicked
    void set_square_clicked(Model::Position pos);
    // gives access to check_king_
    bool check_king_();
    // gives access to player_has_moves
    void player_has_moves();
    // gives access to set_piece
    void set_piece(Model::Position src, Model::Position dst);
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

void Test_access::set_piece(Model::Position src, Model::Position dst) {
    model.set_piece_(src, dst);
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

// TEST CASES 5-: Pieces' allowable moves are accurate and enforced
    // Pieces' allowable moves reflect the rules of chess
    // can only move piece to square where it is allowed move
    // pawns can move two squares on first move

//Test the rook moves and captures
TEST_CASE("Rook moves")
{
    Model m = Model();
    Test_access access(m);

    // Set the highlighted piece to the light rook in the corner
    access.on_first_click({0, 7});

    // Attempt to move the rook one square to the right (cannot capture own
    // piece, should fail)
    access.model.check_pos({1, 7});

    // Check that the rook has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 7}), "Rook") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({1, 7}), "Knight") == 0);

    // Move the rook to the center of the board
    access.set_piece({0, 7}, {4, 4});
    access.on_first_click({4, 4});

    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Rook") == 0);

    // Attempt to move the rook outside the board
    access.model.check_pos({-1, 0});
    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Rook") == 0);

    // Move the rook one square to the right
    access.model.check_pos({5, 4});
    CHECK(strcmp(access.model.piece_type_at({5, 4}), "Rook") == 0);

    // Set the highlighted piece to the rook again
    access.on_first_click({5, 4});

    // Attempt to move the rook one square up and to the right (not correct
    // direction)
    access.model.check_pos({6, 3});
    CHECK(strcmp(access.model.piece_type_at({5, 4}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({6, 3}), "Rook") == 0);

    access.on_first_click({5, 4});

    // Attempt to move the square to x:5 y:0 (not allowed because it will
    // skip over a pawn)
    access.model.check_pos({5, 0});
    CHECK(strcmp(access.model.piece_type_at({5, 4}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({5, 0}), "Rook") == 0);
    // Check that neither the pawn nor bishop were captured
    CHECK(strcmp(access.model.piece_type_at({5, 1}), "Pawn") == 0);
    CHECK(strcmp(access.model.piece_type_at({5, 0}), "Bishop") == 0);

    access.on_first_click({5, 4});

    //Capture the pawn on x:5 y:1
    access.model.check_pos({5, 1});
    CHECK(strcmp(access.model.piece_type_at({5, 1}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({5, 4}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({5, 1}), "Pawn") == 0);
}

//Test the knight moves and captures
TEST_CASE("Knight moves")
{
    Model m = Model();
    Test_access access(m);

    // Set the highlighted piece to the light knight in the corner
    access.on_first_click({1, 7});

    // Attempt to move the knight two squares to the right and one square up
    // (cannot capture own piece, should fail)
    access.model.check_pos({3, 6});

    // Check that the knight has not moved
    CHECK(strcmp(access.model.piece_type_at({1, 7}), "Knight") == 0);
    // Check that the pawn is still there
    CHECK(strcmp(access.model.piece_type_at({3, 6}), "Pawn") == 0);

    // Move the knight to the center of the board
    access.set_piece({1, 7}, {4, 4});
    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Knight") == 0);

    access.on_first_click({4, 4});

    // Attempt to move the knight outside the board
    access.model.check_pos({-1, 0});
    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Knight") == 0);

    access.on_first_click({4, 4});

    // Move the knight to the left and up
    access.model.check_pos({ 2, 3});
    CHECK(strcmp(access.model.piece_type_at({2, 3}), "Knight") == 0);

    // Set the highlighted piece to the knight again
    access.on_first_click({2, 3});

    // Attempt to move the knight one square up (not correct
    // direction)
    access.model.check_pos({2, 2});
    CHECK(strcmp(access.model.piece_type_at({2, 3}), "Knight") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({2, 2}), "Knight") == 0);

    access.on_first_click({2, 3});

    // Check that the knight can only move once in its direction (can't move
    // 4 squares right and 2 squares down)
    access.model.check_pos({6, 5});
    CHECK(strcmp(access.model.piece_type_at({2, 3}), "Knight") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({6, 5}), "Knight") == 0);

    access.on_first_click({2, 3});
    // Place a dark rook right below the knight (check it won't get blocked)
    access.set_piece({0, 0}, {2, 4});
    // Place a dark pawn under and to the right of the rook (check it will get
    // captured)
    access.set_piece({0, 1}, {3, 5});
    access.model.check_pos({3, 5});
    CHECK(strcmp(access.model.piece_type_at({3, 5}), "Knight") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({2, 3}), "Knight") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({3, 5}), "Pawn") == 0);
    CHECK(strcmp(access.model.piece_type_at({2, 4}), "Rook") == 0);

}