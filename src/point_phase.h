#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
public:
    explicit PointPhase(int p);
    RollOutcome get_outcome(Roll* roll) override;

private:
    int point;
};

#endif
