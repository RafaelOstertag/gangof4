#include "hardgamefactory.hh"
#include "../board/board.hh"
#include "../scorer/fastadvancingscorer.hh"
#include "../tetrimino/hardtetriminostock.hh"

HardGameFactory::HardGameFactory(const Window& window, FontFactory& fontFactory)
    : window{window}, fontFactory{fontFactory} {}

GamePtr HardGameFactory::create() {
    TetriminoStockPtr tetriminoStock{new HardTetriminoStock{}};
    ScorerPtr scorer{new FastAdvancingScorer{Board::WIDTH_IN_MINOS}};

    return GamePtr{new Game{window, fontFactory, tetriminoStock, scorer}};
}
