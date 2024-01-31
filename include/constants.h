#ifndef CONSTANTS_H
#define CONSTANTS_H

// Screen size in pixels
#define SCR_PX_WIDTH 256
#define SCR_PX_HEIGHT 192

// Screen size in characters cells
#define SCR_CC_WIDTH 32
#define SCR_CC_HEIGHT 24

#define CC_WIDTH 8
#define CC_HEIGHT 8

#define SCR_AREA ((char*) 0x4000)
#define SCR_ATTR_AREA ((char*) 0x5800)

#define FIELD_WIDTH 30
#define FIELD_HEIGHT 20

// Coordinates of the location of the scene on the screen...
#define SCENE_POS_X ((SCR_CC_WIDTH - FIELD_WIDTH) / 2)
#define SCENE_POS_Y ((SCR_CC_HEIGHT - FIELD_HEIGHT) / 2 + 1)

// Minimum number of processor ticks in the snake step
#define MIN_STEP_TICKS 200

#endif  /* CONSTANTS_H */
