#ifndef BLOQ_MACROS_H
#define BLOQ_MACROS_H

#define bloqDiscard(statement) (void)statement
#define bloqExitCondition(condition) if (condition) { return; }

#endif