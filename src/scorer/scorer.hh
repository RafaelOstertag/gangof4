#ifndef __SCORER_HH
#define __SCORER_HH

#include <memory>

class Scorer {
  public:
    using score_t = unsigned int;
    using level_t = unsigned int;
    virtual ~Scorer() = default;

    virtual void scoreLinesRemoved(unsigned int numberOfLines) = 0;
    virtual score_t getScore() const = 0;
    virtual level_t getLevel() const = 0;
};

using ScorerPtr = std::shared_ptr<Scorer>;

#endif
