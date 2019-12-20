#include "easygamefactory.hh"
#include "../board/board.hh"
#include "../scorer/slowadvancingscorer.hh"
#include "../tetrimino/randomtetriminostock.hh"

EasyGameFactory::EasyGameFactory(const Window& window, FontFactory& fontFactory)
    : window{window}, fontFactory{fontFactory} {}

GamePtr EasyGameFactory::create() {
    TetriminoStockPtr tetriminoStock{new RandomTetriminoStock{}};
    ScorerPtr scorer{new SlowAdvancingScorer{Board::WIDTH_IN_MINOS}};

    return GamePtr{new Game{window, fontFactory, tetriminoStock, scorer}};
}
