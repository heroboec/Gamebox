#ifndef FONT_H
#define FONT_H

#include "libgame.h"

// Adafruit 5x7 font
static const unsigned char font_data[] DATA = {
0, 0, 0, 0, 0, 0, 0, 14, 31, 21, 31, 27, 17, 14, 14, 31, 21, 31, 17, 27, 14, 0, 10, 31, 31, 31, 14, 4, 0, 4, 14, 31, 31, 14, 4, 14, 10, 31, 21, 31, 4, 14, 4, 14, 31, 31, 31, 4, 14, 0, 0, 4, 14, 14, 4, 0, 31, 31, 27, 17, 17, 27, 31, 0, 0, 4, 10, 10, 4, 0, 31, 31, 27, 21, 21, 27, 31, 0, 28, 24, 22, 5, 5, 2, 14, 17, 17, 14, 4, 31, 4, 30, 18, 30, 2, 2, 2, 3, 30, 18, 30, 18, 18, 26, 3, 4, 21, 14, 27, 27, 14, 21, 1, 3, 15, 31, 15, 3, 1, 16, 24, 30, 31, 30, 24, 16, 4, 14, 21, 4, 21, 14, 4, 27, 27, 27, 27, 27, 0, 27, 30, 21, 21, 22, 20, 20, 20, 12, 18, 10, 20, 8, 18, 18, 0, 0, 0, 0, 0, 31, 31, 4, 14, 21, 4, 21, 14, 4, 0, 4, 14, 21, 4, 4, 4, 0, 4, 4, 4, 21, 14, 4, 0, 4, 8, 31, 8, 4, 0, 0, 4, 2, 31, 2, 4, 0, 0, 1, 1, 1, 31, 0, 0, 0, 10, 31, 31, 10, 0, 0, 0, 4, 4, 14, 31, 31, 0, 0, 31, 31, 14, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 4, 10, 10, 10, 0, 0, 0, 0, 10, 10, 31, 10, 31, 10, 10, 4, 30, 5, 14, 20, 15, 4, 3, 19, 8, 4, 2, 25, 24, 2, 5, 5, 2, 21, 9, 22, 12, 12, 4, 2, 0, 0, 0, 8, 4, 2, 2, 2, 4, 8, 2, 4, 8, 8, 8, 4, 2, 4, 21, 14, 31, 14, 21, 4, 0, 4, 4, 31, 4, 4, 0, 0, 0, 0, 0, 12, 12, 4, 0, 0, 0, 31, 0, 0, 0, 0, 0, 0, 0, 0, 12, 12, 0, 16, 8, 4, 2, 1, 0, 14, 17, 25, 21, 19, 17, 14, 4, 6, 4, 4, 4, 4, 14, 14, 17, 16, 14, 1, 1, 31, 31, 16, 8, 12, 16, 17, 14, 8, 12, 10, 9, 31, 8, 8, 31, 1, 15, 16, 16, 17, 14, 28, 2, 1, 15, 17, 17, 14, 31, 16, 16, 8, 4, 2, 1, 14, 17, 17, 14, 17, 17, 14, 14, 17, 17, 30, 16, 8, 7, 0, 0, 4, 0, 4, 0, 0, 0, 0, 4, 0, 4, 4, 2, 16, 8, 4, 2, 4, 8, 16, 0, 0, 31, 0, 31, 0, 0, 2, 4, 8, 16, 8, 4, 2, 14, 17, 16, 12, 4, 0, 4, 14, 17, 21, 29, 13, 1, 30, 4, 10, 17, 17, 31, 17, 17, 15, 17, 17, 15, 17, 17, 15, 14, 17, 1, 1, 1, 17, 14, 15, 17, 17, 17, 17, 17, 15, 31, 1, 1, 15, 1, 1, 31, 31, 1, 1, 15, 1, 1, 1, 30, 17, 1, 1, 25, 17, 30, 17, 17, 17, 31, 17, 17, 17, 14, 4, 4, 4, 4, 4, 14, 28, 8, 8, 8, 8, 9, 6, 17, 9, 5, 3, 5, 9, 17, 1, 1, 1, 1, 1, 1, 31, 17, 27, 21, 21, 21, 17, 17, 17, 17, 19, 21, 25, 17, 17, 14, 17, 17, 17, 17, 17, 14, 15, 17, 17, 15, 1, 1, 1, 14, 17, 17, 17, 21, 9, 22, 15, 17, 17, 15, 5, 9, 17, 14, 17, 1, 14, 16, 17, 14, 31, 21, 4, 4, 4, 4, 4, 17, 17, 17, 17, 17, 17, 14, 17, 17, 17, 17, 17, 10, 4, 17, 17, 17, 21, 21, 21, 10, 17, 17, 10, 4, 10, 17, 17, 17, 17, 10, 4, 4, 4, 4, 31, 16, 8, 14, 2, 1, 31, 30, 2, 2, 2, 2, 2, 30, 0, 1, 2, 4, 8, 16, 0, 30, 16, 16, 16, 16, 16, 30, 4, 10, 17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 6, 6, 4, 8, 0, 0, 0, 0, 0, 6, 8, 14, 9, 30, 1, 1, 13, 19, 17, 19, 13, 0, 0, 14, 17, 1, 17, 14, 16, 16, 22, 25, 17, 25, 22, 0, 0, 14, 17, 31, 1, 14, 8, 20, 4, 14, 4, 4, 4, 0, 0, 14, 25, 25, 22, 16, 1, 1, 13, 19, 17, 17, 17, 4, 0, 6, 4, 4, 4, 14, 8, 0, 8, 8, 8, 9, 6, 1, 1, 9, 5, 3, 5, 9, 6, 4, 4, 4, 4, 4, 14, 0, 0, 11, 21, 21, 21, 21, 0, 0, 13, 19, 17, 17, 17, 0, 0, 14, 17, 17, 17, 14, 0, 0, 13, 19, 19, 13, 1, 0, 0, 22, 25, 25, 22, 16, 0, 0, 13, 19, 1, 1, 1, 0, 0, 30, 1, 14, 16, 15, 4, 4, 31, 4, 4, 20, 8, 0, 0, 17, 17, 17, 25, 22, 0, 0, 17, 17, 17, 10, 4, 0, 0, 17, 17, 21, 21, 10, 0, 0, 17, 10, 4, 10, 17, 0, 0, 17, 17, 30, 16, 17, 0, 0, 31, 8, 4, 2, 31, 8, 4, 4, 2, 4, 4, 8, 4, 4, 4, 0, 4, 4, 4, 2, 4, 4, 8, 4, 4, 2, 2, 21, 8, 0, 0, 0, 0, 4, 14, 27, 17, 17, 31, 0, 14, 17, 1, 1, 17, 14, 8, 0, 17, 0, 17, 17, 25, 22, 24, 0, 14, 17, 31, 1, 30, 31, 0, 6, 8, 14, 9, 30, 0, 17, 6, 8, 14, 9, 30, 3, 0, 6, 8, 14, 9, 30, 12, 0, 6, 8, 14, 9, 30, 0, 30, 3, 3, 30, 8, 12, 31, 0, 14, 17, 31, 1, 30, 17, 0, 14, 17, 31, 1, 30, 3, 0, 14, 17, 31, 1, 30, 20, 0, 12, 8, 8, 8, 28, 12, 18, 12, 8, 8, 8, 28, 6, 0, 12, 8, 8, 8, 28, 21, 10, 17, 17, 31, 17, 17, 4, 0, 4, 10, 17, 31, 17, 12, 0, 15, 1, 7, 1, 15, 0, 0, 30, 8, 30, 9, 30, 28, 10, 9, 31, 9, 9, 25, 14, 17, 0, 14, 17, 17, 14, 0, 17, 14, 17, 17, 17, 14, 0, 3, 0, 14, 17, 17, 14, 14, 17, 0, 17, 17, 25, 22, 0, 3, 0, 17, 17, 25, 22, 18, 0, 18, 18, 18, 28, 16, 17, 14, 17, 17, 17, 17, 14, 17, 0, 17, 17, 17, 17, 14, 4, 4, 31, 5, 5, 31, 4, 12, 26, 18, 7, 2, 18, 31, 27, 27, 14, 31, 4, 31, 4, 7, 9, 9, 7, 9, 29, 9, 24, 20, 4, 14, 4, 4, 5, 24, 0, 6, 8, 14, 9, 30, 24, 0, 12, 8, 8, 8, 28, 0, 24, 0, 14, 17, 17, 14, 0, 24, 0, 17, 17, 25, 22, 0, 30, 0, 14, 18, 18, 18, 31, 0, 19, 23, 29, 25, 17, 14, 9, 9, 30, 0, 31, 0, 14, 17, 17, 14, 0, 31, 0, 4, 0, 4, 6, 1, 17, 14, 0, 0, 0, 31, 1, 1, 0, 0, 0, 0, 31, 16, 16, 0, 1, 17, 9, 29, 18, 25, 4, 1, 17, 9, 21, 26, 29, 16, 4, 4, 0, 4, 4, 4, 4, 0, 20, 10, 5, 10, 20, 0, 0, 5, 10, 20, 10, 5, 0, 21, 0, 21, 0, 21, 0, 21, 10, 21, 10, 21, 10, 21, 10, 31, 21, 31, 21, 31, 21, 31, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 15, 8, 8, 8, 8, 15, 8, 15, 8, 8, 20, 20, 20, 20, 23, 20, 20, 0, 0, 0, 0, 31, 20, 20, 0, 0, 15, 8, 15, 8, 8, 20, 20, 23, 16, 23, 20, 20, 20, 20, 20, 20, 20, 20, 20, 0, 0, 31, 16, 23, 20, 20, 20, 20, 23, 16, 31, 0, 0, 20, 20, 20, 20, 31, 0, 0, 8, 8, 15, 8, 15, 0, 0, 0, 0, 0, 0, 15, 8, 8, 8, 8, 8, 8, 24, 0, 0, 8, 8, 8, 8, 31, 0, 0, 0, 0, 0, 0, 31, 8, 8, 8, 8, 8, 8, 24, 8, 8, 0, 0, 0, 0, 31, 0, 0, 8, 8, 8, 8, 31, 8, 8, 8, 8, 24, 8, 24, 8, 8, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 4, 28, 0, 0, 0, 0, 28, 4, 20, 20, 20, 20, 20, 23, 0, 31, 0, 0, 0, 0, 31, 0, 23, 20, 20, 20, 20, 20, 4, 20, 20, 20, 0, 0, 31, 0, 31, 0, 0, 20, 20, 23, 0, 23, 20, 20, 8, 8, 31, 0, 31, 0, 0, 20, 20, 20, 20, 31, 0, 0, 0, 0, 31, 0, 31, 8, 8, 0, 0, 0, 0, 31, 20, 20, 20, 20, 20, 20, 28, 0, 0, 8, 8, 24, 8, 24, 0, 0, 0, 0, 24, 8, 24, 8, 8, 0, 0, 0, 0, 28, 20, 20, 20, 20, 20, 20, 31, 20, 20, 8, 8, 31, 8, 31, 8, 8, 8, 8, 8, 8, 15, 0, 0, 0, 0, 0, 0, 24, 8, 8, 31, 31, 31, 31, 31, 31, 31, 0, 0, 0, 0, 31, 31, 31, 7, 7, 7, 7, 7, 7, 7, 24, 24, 24, 24, 24, 24, 24, 31, 31, 31, 31, 0, 0, 0, 0, 0, 22, 9, 9, 9, 22, 0, 14, 17, 15, 17, 17, 15, 0, 31, 25, 1, 1, 1, 1, 0, 31, 10, 10, 10, 10, 10, 31, 17, 2, 4, 2, 17, 31, 0, 0, 30, 9, 9, 9, 6, 0, 10, 10, 10, 10, 22, 3, 0, 31, 5, 4, 4, 4, 4, 31, 4, 14, 17, 17, 14, 4, 4, 10, 17, 31, 17, 10, 4, 4, 10, 17, 17, 10, 10, 27, 12, 2, 12, 14, 17, 17, 14, 0, 0, 0, 14, 21, 21, 14, 16, 14, 25, 21, 21, 19, 14, 14, 1, 1, 15, 1, 1, 14, 14, 17, 17, 17, 17, 17, 17, 0, 31, 0, 31, 0, 31, 0, 4, 4, 31, 4, 4, 0, 31, 2, 4, 8, 4, 2, 0, 31, 8, 4, 2, 4, 8, 0, 31, 28, 20, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 12, 12, 0, 31, 0, 12, 12, 0, 23, 29, 0, 23, 29, 0, 14, 27, 27, 14, 0, 0, 0, 0, 0, 0, 12, 12, 0, 0, 0, 0, 0, 0, 12, 0, 0, 28, 4, 4, 4, 5, 5, 6, 14, 18, 18, 18, 18, 0, 0, 14, 24, 12, 6, 30, 0, 0, 0, 0, 30, 30, 30, 30, 0, 0, 0, 0, 0, 0, 0, 0
};
#endif
