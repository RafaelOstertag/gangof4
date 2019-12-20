#include "slowadvancingscorer.hh"

void SlowAdvancingScorer::scoreLinesRemoved(unsigned int numberOfLines) {
    if (numberOfLines == 0) {
        return;
    }
    unsigned int lineScore = 1 << numberOfLines;
    score += lineScore > SCORE_PER_LINE ? lineScore : 0;

    auto minoScore = POINTS_PER_MINO * minosPerLine * numberOfLines;
    score += minoScore;
}
