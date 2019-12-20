#ifndef __EASYSCORER_HH
#define __EASYSCORER_HH

#include "scorer.hh"

class SlowAdvancingScorer : public Scorer {
  public:
    SlowAdvancingScorer(unsigned int minosPerLine)
        : minosPerLine{minosPerLine}, score{0} {}
    virtual void scoreLinesRemoved(unsigned int numberOfLines);

    virtual score_t getScore() const { return score; }
    virtual level_t getLevel() const { return score / POINTS_PER_LEVEL; }

  private:
    static constexpr score_t POINTS_PER_MINO = 2;
    static constexpr score_t POINTS_PER_LEVEL = 100;
    static constexpr score_t SCORE_PER_LINE = 4;
    unsigned int minosPerLine;
    score_t score;
};

#endif
