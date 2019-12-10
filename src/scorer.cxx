#include "scorer.hh"

void Scorer::scoreLinesRemoved(unsigned int numberOfLines) {
    if (numberOfLines == 0) {
        return;
    }
    auto lineScore = 1 << numberOfLines;
    score += lineScore > scorePerLine ? lineScore : 0;

    auto minoScore = pointsPerMino * minosPerLine * numberOfLines;
    score += minoScore;
}
