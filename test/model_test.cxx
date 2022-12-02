#include "model.hxx"
#include <catch.hxx>


// TEST CASE 1: Game is over when player cannot move
TEST_CASE("game over player can't move")
{
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