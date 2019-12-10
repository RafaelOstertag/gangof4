#ifndef __SCORER_HH
#define __SCORER_HH

#include <memory>

class Scorer {
  public:
    using score_t = unsigned int;
    using level_t = unsigned int;

    Scorer(unsigned int minosPerLine) : minosPerLine{minosPerLine}, score{0} {}
    void scoreLinesRemoved(unsigned int numberOfLines);

    constexpr score_t getScore() const { return score; }
    constexpr level_t getLevel() const { return score / pointsPerLevel; }

  private:
    static constexpr score_t pointsPerMino = 2;
    static constexpr score_t pointsPerLevel = 100;
    static constexpr score_t scorePerLine = 4;
    unsigned int minosPerLine;
    score_t score;
};

using scorer_ptr_t = std::shared_ptr<Scorer>;

#endif
