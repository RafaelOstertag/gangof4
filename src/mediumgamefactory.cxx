#include "mediumgamefactory.hh"
#include "board.hh"
#include "fastadvancingscorer.hh"
#include "randomtetriminostock.hh"

MediumGameFactory::MediumGameFactory(const Window& window,
                                     FontFactory& fontFactory)
    : window{window}, fontFactory{fontFactory} {}

GamePtr MediumGameFactory::create() {
    TetriminoStockPtr tetriminoStock{new RandomTetriminoStock{}};
    ScorerPtr scorer{new FastAdvancingScorer{Board::WIDTH_IN_MINOS}};

    return GamePtr{new Game{window, fontFactory, tetriminoStock, scorer}};
}
