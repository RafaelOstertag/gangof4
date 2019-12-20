#include "hardgamefactory.hh"
#include "board.hh"
#include "fastadvancingscorer.hh"
#include "normaltetriminostock.hh"

HardGameFactory::HardGameFactory(const Window& window, FontFactory& fontFactory)
    : window{window}, fontFactory{fontFactory} {}

GamePtr HardGameFactory::create() {
    TetriminoStockPtr tetriminoStock{new NormalTetriminoStock{}};
    ScorerPtr scorer{new FastAdvancingScorer{Board::WIDTH_IN_MINOS}};

    return GamePtr{new Game{window, fontFactory, tetriminoStock, scorer}};
}
