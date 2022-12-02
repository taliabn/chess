#include "model.hxx"
#include <catch.hxx>

struct Test_access
{
    Model& model;

    // Constructs a `Test_access` with a reference to the Model under test.
    explicit Test_access(Model&);

    // REVERSI COPY PASTA:
    // // Sets the player at `posn` to `player`.
    // void set_player(Model::Position posn, Player player);
    // // Gives direct access to `model.next_moves_` so our tests can modify it:
    // Move_map& next_moves();
    // // gives direct access to 'model.board'
    // Board& board();
    // // gives access to find_flips
    // Position_set find_flips(Model::Position p, Model::Dimensions d);
    // void
    // compute_next_moves();
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

// REVERSI COPY PASTA:
// void
// Test_access::set_player(Model::Position posn, Player player)
// {
//     model.board_[posn] = player;
// }
//
// Move_map&
// Test_access::next_moves()
// {
//     return model.next_moves_;
// }
//
// void
// Test_access::compute_next_moves()
// {
//     model.compute_next_moves_();
// }
// Board&
// Test_access::board()
// {
//     return model.board_ ;
// }
//
// Position_set
// Test_access::find_flips ( Model :: Position p ,
//                           Model :: Dimensions d )
// {
//     return model . find_flips_ (p , d );
// }
bool Test_access::check_king_() {
    return model.check_king_();
}

void Test_access::player_has_moves() {
    model.player_has_moves();
}

void Test_access::set_piece(Piece piece, Model::Position pos){
    model.set_piece_(piece, pos);
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
    CHECK(1 + 1 == 2);
}


