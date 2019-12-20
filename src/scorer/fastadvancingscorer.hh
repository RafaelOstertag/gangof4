#ifndef __FASTADVANCINGSCORER_HH
#define __FASTADVANCINGSCORER_HH

#include "scorer.hh"

class FastAdvancingScorer : public Scorer {
  public:
    FastAdvancingScorer(unsigned int minosPerLine)
        : minosPerLine{minosPerLine}, score{0} {}
    virtual void scoreLinesRemoved(unsigned int numberOfLines);

    virtual score_t getScore() const { return score; }
    virtual level_t getLevel() const { return score / POINTS_PER_LEVEL; }

  private:
    static constexpr score_t POINTS_PER_MINO = 4;
    static constexpr score_t POINTS_PER_LEVEL = 100;
    static constexpr score_t SCORE_PER_LINE = 16;
    unsigned int minosPerLine;
    score_t score;
};

#endif
