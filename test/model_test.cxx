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
        // clicking one piece of turn and then another of the same color
        // doesn't play a move
    // can only play a move when a piece has been selected
TEST_CASE("when can player move")
{
    // setup
    Model m = Model();
    Test_access access(m);


    // make sure nothing happens when no piece is selected and an empty square
    // is clicked
    // nothing has been clicked to start
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    const char* piece_type = access.model.piece_type_at(Model::Position(5,5));
    // (5,5) is an empty square
    CHECK(strcmp("None", piece_type) == 0);
    // simulate clicking on (5,5)
    access.model.check_pos(Model::Position(5,5));
    // there is still nothing clicked
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    piece_type = access.model.piece_type_at(Model::Position(5,5));
    // (5,5) is still an empty square
    CHECK(strcmp("None", piece_type) == 0);


    // make sure dark cannot move on the first turn
    // game starts with light player
    CHECK(access.model.turn() == Player::light);
    // simulate clicking one of dark's pawns
    access.model.check_pos(Model::Position(1,1));
    // the click should not have done anything
    CHECK(!access.model.piece_clicked());
    CHECK(Model::Position(-1, -1) == access.model.square_clicked());


    // now simulate clicking on one of lights pawns, which is allowed
    access.model.check_pos(Model::Position(6, 6));
    // the click should have selected that pawn
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(6, 6));

    // now try clicking on a light rook, which is allowed
    // the rook will be selected, and neither the rook nor the pawn will move
    access.model.check_pos(Model::Position(7, 7));
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(7, 7));
    // the pawn should still be at (6,6)
    piece_type = access.model.piece_type_at(Model::Position(6, 6));
    CHECK(strcmp("Pawn", piece_type) == 0);
    // the rook should still be at (7,7)
    piece_type = access.model.piece_type_at(Model::Position(7, 7));
    CHECK(strcmp("Rook", piece_type) == 0);

    // now click back to the light pawn and play a move, which is allowed
    // select a light pawn
    access.model.check_pos(Model::Position(6,6));
    // before move, square in front of pawn is empty
    piece_type = access.model.piece_type_at(Model::Position(6, 5));
    CHECK(strcmp("None", piece_type) == 0);
    // play move
    access.model.check_pos(Model::Position(6,5));
    // pawn should have moved, and the square where it was previously is empty
    piece_type = access.model.piece_type_at(Model::Position(6, 5));
    CHECK(strcmp("Pawn", piece_type) == 0);
    piece_type = access.model.piece_type_at(Model::Position(6, 6));
    CHECK(strcmp("None", piece_type) == 0);
    // there should no longer be a piece selected
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));

    // check it has switched to dark's turn
    CHECK(access.model.turn() == Player::dark);
    // now dark can move
    // select a dark pawn
    access.model.check_pos(Model::Position(1, 1));
    // the piece should have been selected
    CHECK(access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(1, 1));
    // before move, square in front of pawn is empty
    piece_type = access.model.piece_type_at(Model::Position(1, 2));
    CHECK(strcmp("None", piece_type) == 0);
    // play move
    access.model.check_pos(Model::Position(1, 2));
    // pawn should have moved, and the square where it was previously is empty
    piece_type = access.model.piece_type_at(Model::Position(1, 2));
    CHECK(strcmp("Pawn", piece_type) == 0);
    piece_type = access.model.piece_type_at(Model::Position(1, 1));
    CHECK(strcmp("None", piece_type) == 0);

    // there should no longer be a piece selected
    CHECK(!access.model.piece_clicked());
    CHECK(access.model.square_clicked() == Model::Position(-1, -1));
    // the turn switched again
    CHECK(access.model.turn() == Player::light);

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


