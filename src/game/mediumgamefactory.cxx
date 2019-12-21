#include "mediumgamefactory.hh"
#include "../board/board.hh"
#include "../scorer/fastadvancingscorer.hh"
#include "../tetrimino/randomtetriminostock.hh"

MediumGameFactory::MediumGameFactory(const Window& window,
                                     FontFactory& fontFactory)
    : window{window}, fontFactory{fontFactory} {}

GamePtr MediumGameFactory::create() {
    TetriminoStockPtr tetriminoStock{new RandomTetriminoStock{}};
    ScorerPtr scorer{new FastAdvancingScorer{Board::WIDTH_IN_MINOS}};

    return GamePtr{new Game{window, fontFactory, tetriminoStock, scorer}};
}
