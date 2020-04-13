

#pragma once

#include "MazeParams.h"

#define EMPTY           (0)
#define WALL (1 << 30)
#define MARK (1 << 29)
#define MASK (((-1) ^ WALL) ^ MARK)
#define BREADCRUMB      (2)

void makeMaze();
void recodeMaze(void);
