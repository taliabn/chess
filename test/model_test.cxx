#include "model.hxx"
#include <catch.hxx>

// struct to enable access to private members of Model
struct Test_access
{
    Model& model;

    // Constructs a `Test_access` with a reference to the Model under test.
    explicit Test_access(Model&);

    // gives access to on_first_click
    void on_first_click(Model::Position pos);

    // gives access to set_piece
    void set_piece(Model::Position src, Model::Position dst);
};

///
/// Member function definitions for Test_access
///

Test_access::Test_access(Model& model)
        : model(model)
{ }

void Test_access::on_first_click(Model::Position pos) {
    model.on_first_click_(pos);
}

void Test_access::set_piece(Model::Position src, Model::Position dst) {
    model.set_piece_(src, dst);
}


// TEST CASE 1: Game is over when player cannot move
TEST_CASE("Stalemate Check")
{
    Model m = Model();
    Test_access access(m);

    // This requirement will be tested by 'locking' the king in the corner by
    // surrounding it with pawns. Pawns do not promote in our implementation,
    // so there will be no moves available.

    // Move the king to the corner
    access.set_piece({4, 0}, {7, 7});

    // Surround the king with pawns
    access.set_piece({0, 1}, {6, 7});
    access.set_piece({2, 1}, {6, 6});
    access.set_piece({3, 1}, {7, 6});

    Position_set protected_squares {
        {7, 7}, {6, 7}, {6, 6}, {7, 6}, {4, 7}
    };

    // Clear the board except for the light king and the dark pieces moved
    for (auto pos : access.model.board()) {
        if (!protected_squares[pos]) {
            // If not one of the protected squares, set empty square
            access.set_piece({4, 4}, pos);
            CHECK(strcmp(access.model.piece_type_at(pos), "None") == 0);
        }
    }

    // Move the light king (since dark king cannot move, light player should
    // win after moving)

    access.on_first_click({4, 7});
    access.model.check_pos({4, 6});

    // Check game over
    CHECK(access.model.is_game_over());

    // Check light player is winner
    CHECK(access.model.winner() == Player::light);
    // Check turn is no longer set
    CHECK(access.model.turn() == Player::neither);

}

// TEST CASE 2: Game is over after king is captured
TEST_CASE("game over king captured")
{
    Model m = Model();
    Test_access access(m);

    // Setup checkmate scenario by moving pieces
    // Move light pawn
    access.on_first_click({4, 6});
    access.model.check_pos({4, 4});
    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Pawn") == 0);
    // Move dark pawn
    access.on_first_click({5, 1});
    access.model.check_pos({5, 3});
    CHECK(strcmp(access.model.piece_type_at({5, 3}), "Pawn") == 0);
    // Move light queen
    access.on_first_click({3, 7});
    access.model.check_pos({7, 3});
    CHECK(strcmp(access.model.piece_type_at({7, 3}), "Queen") == 0);
    // Dark can make any move
    access.on_first_click({1, 1});
    access.model.check_pos({1, 2});

    // Now the light queen can capture the dark king
    // Select light queen
    access.model.check_pos(Model::Position(7, 3));
    // Move light queen
    access.model.check_pos(Model::Position(4, 0));
    // The light queen captured the dark king
    CHECK(strcmp(access.model.piece_type_at({4, 0}), "Queen") == 0);
    // Light should now be the winner and the game should be over
    CHECK(access.model.turn() == Player::neither);
    CHECK(access.model.winner() == Player::light);
    CHECK(access.model.is_game_over());

}

// TEST CASE 3: Players can only play moves at allowable times
    // Light moves first
    // Players can only move on their turn
    // Players can only move pieces of their color
    // Clicking one piece and then another of the same color doesn't play a move
    // Players can only play a move when a piece has been selected
TEST_CASE("when can player move")
{
    Model m = Model();
    Test_access access(m);


    // Make sure nothing happens when no piece is selected and an empty square
    // is clicked
    // Nothing has been clicked to start
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    const char* piece_type = access.model.piece_type_at(Model::Position(5,5));
    // (5,5) is an empty square
    CHECK(strcmp("None", piece_type) == 0);
    // Simulate clicking on (5,5)
    access.model.check_pos(Model::Position(5,5));
    // There is still nothing selected
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    piece_type = access.model.piece_type_at(Model::Position(5,5));
    // (5,5) is still an empty square
    CHECK(strcmp("None", piece_type) == 0);


    // Make sure dark cannot move on the first turn
    // Game starts with light player
    CHECK(access.model.turn() == Player::light);
    // Simulate clicking one of dark's pawns
    access.model.check_pos(Model::Position(1,1));
    // The click should not have done anything
    CHECK(!access.model.piece_clicked());
    CHECK(Model::Position(-1, -1) == access.model.square_clicked());


    // Now simulate clicking on one of lights pawns, which is allowed
    access.model.check_pos(Model::Position(6, 6));
    // The click should have selected that pawn
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(6, 6));

    // Now attempt to click on a light rook, which is allowed
    // The rook should be selected, but neither the rook nor the pawn should
    // move because they are both light
    access.model.check_pos(Model::Position(7, 7));
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(7, 7));
    // The pawn should still be at (6,6)
    piece_type = access.model.piece_type_at(Model::Position(6, 6));
    CHECK(strcmp("Pawn", piece_type) == 0);
    // The rook should still be at (7,7)
    piece_type = access.model.piece_type_at(Model::Position(7, 7));
    CHECK(strcmp("Rook", piece_type) == 0);

    // Now attempt to reselect the light pawn and play a move, which is
    // allowed
    // Select a light pawn
    access.model.check_pos(Model::Position(6,6));
    // Before the move, the square in front of pawn should be empty
    piece_type = access.model.piece_type_at(Model::Position(6, 5));
    CHECK(strcmp("None", piece_type) == 0);
    // Play move
    access.model.check_pos(Model::Position(6,5));
    // Pawn should have moved, and the square where it previously was should
    // now be empty
    piece_type = access.model.piece_type_at(Model::Position(6, 5));
    CHECK(strcmp("Pawn", piece_type) == 0);
    piece_type = access.model.piece_type_at(Model::Position(6, 6));
    CHECK(strcmp("None", piece_type) == 0);
    // There should no longer be a piece selected
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));

    // Check that turn has switched to dark
    CHECK(access.model.turn() == Player::dark);
    // Now dark can move
    // Select a dark pawn
    access.model.check_pos(Model::Position(1, 1));
    // The piece should have been selected
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(1, 1));
    // Before the move, the square in front of pawn should be empty
    piece_type = access.model.piece_type_at(Model::Position(1, 2));
    CHECK(strcmp("None", piece_type) == 0);
    // Play move
    access.model.check_pos(Model::Position(1, 2));
    // Pawn should have moved, and the square where it was previously should
    // now be empty
    piece_type = access.model.piece_type_at(Model::Position(1, 2));
    CHECK(strcmp("Pawn", piece_type) == 0);
    piece_type = access.model.piece_type_at(Model::Position(1, 1));
    CHECK(strcmp("None", piece_type) == 0);

    // There should no longer be a piece selected
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    // The turn should have switched back to light
    CHECK(access.model.turn() == Player::light);

}

// TEST CASES 5-: Pieces' allowable moves are accurate and enforced
    // Pieces' allowable moves reflect the rules of chess
    // Players can only move piece to square where it is allowed move
    // Pawns can move two squares on first move

// Test the rook moves and captures
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

    // Capture the pawn on x:5 y:1
    access.model.check_pos({5, 1});
    CHECK(strcmp(access.model.piece_type_at({5, 1}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({5, 4}), "Rook") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({5, 1}), "Pawn") == 0);

}

// Test the knight moves and captures
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

// Test the pawn moves and captures
TEST_CASE("Pawn moves")
{
    Model m = Model();
    Test_access access(m);

    // Set the highlighted piece to the light pawn in the corner
    access.on_first_click({0, 6});

    // Attempt to move the pawn three squares up (should fail)
    access.model.check_pos({0, 3});

    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 3}), "Pawn") == 0);

    // Move the pawn two squares up
    access.on_first_click({0, 6});
    access.model.check_pos({0, 4});

    // Check that the pawn has moved
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK(strcmp(access.model.piece_type_at({0, 4}), "Pawn") == 0);

    // Reset pawn position
    access.set_piece({0, 4}, {0, 6});
    // Put a piece in front of the pawn
    access.set_piece({1, 7}, {0, 5});

    // Attempt to move the pawn two squares up (can't because piece is in the
    // way)
    access.on_first_click({0, 6});
    access.model.check_pos({0, 4});

    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 4}), "Pawn") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({0, 5}), "Knight") == 0);

    // Attempt to move the pawn one square up (can't because knight is there)
    access.on_first_click({0, 6});
    access.model.check_pos({0, 5});

    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 5}), "Pawn") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({0, 5}), "Knight") == 0);

    // Attempt to move the pawn diagonally to the right (can't because there
    // is nothing to capture)
    access.on_first_click({0, 6});
    access.model.check_pos({1, 5});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({1, 5}), "Pawn") == 0);

    // Move the knight to the capture square
    access.set_piece({0, 5}, {1, 5});
    // Check that the pawn still cannot move to that square
    access.on_first_click({0, 6});
    access.model.check_pos({1, 5});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({1, 5}), "Pawn") == 0);

    //Put a dark knight in front of the pawn
    access.set_piece({6, 0}, {0, 5});

    // Attempt to move the pawn two squares up (can't because piece is in the
    // way)
    access.on_first_click({0, 6});
    access.model.check_pos({0, 4});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 4}), "Pawn") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({0, 5}), "Knight") == 0);

    // Attempt to move the pawn one square up (can't because knight is there)
    access.on_first_click({0, 6});
    access.model.check_pos({0, 5});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 5}), "Pawn") == 0);
    // Check that the knight is still there
    CHECK(strcmp(access.model.piece_type_at({0, 5}), "Knight") == 0);

    // Attempt to move the pawn diagonally to the right (can't because there
    // is nothing to capture)
    access.on_first_click({0, 6});
    access.model.check_pos({1, 5});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({1, 5}), "Pawn") == 0);

    // Move dark knight to the capture square
    access.set_piece({1, 0}, {1, 5});
    // Move the pawn to that square
    access.on_first_click({0, 6});
    access.model.check_pos({1, 5});
    // Check that the pawn has moved
    CHECK_FALSE(strcmp(access.model.piece_type_at({0, 6}), "Pawn") == 0);
    CHECK(strcmp(access.model.piece_type_at({1, 5}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({1, 5}), "Knight") == 0);

    // Move the pawn to the center of the board
    access.set_piece({1, 5}, {4, 4});
    // Check that the pawn cannot move two squares (because it has left the
    // second rank)
    access.on_first_click({4, 4});
    access.model.check_pos({4, 2});
    // Check that the pawn has not moved
    CHECK(strcmp(access.model.piece_type_at({4, 4}), "Pawn") == 0);
    CHECK_FALSE(strcmp(access.model.piece_type_at({4, 2}), "Pawn") == 0);

}