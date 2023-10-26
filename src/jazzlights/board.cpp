#include "jazzlights/board.h"

#ifdef ARDUINO

#if ORANGE_VEST || IS_STAFF || IS_CAPTAIN_HAT
#include "jazzlights/layouts/pixelmap.h"
#endif

#if IS_ROPELIGHT || IS_GAUNTLET || HAMMER || FAIRY_WAND
#include "jazzlights/layouts/matrix.h"
#endif

namespace jazzlights {

namespace {

#if ORANGE_VEST

constexpr Point pixelMap[] = {
    { 0.0,  0.0},
    { 0.0,  1.0},
    { 0.0,  2.0},
    { 0.0,  3.0},
    { 0.0,  4.0},
    { 0.0,  5.0},
    { 0.0,  6.0},
    { 0.0,  7.0},
    { 0.0,  8.0},
    { 0.0,  9.0},
    { 0.0, 10.0},
    { 0.0, 11.0},
    { 0.0, 12.0},
    { 0.0, 13.0},
    { 0.0, 14.0},
    { 0.0, 15.0},
    { 0.0, 16.0},
    { 0.0, 17.0},
    { 0.5, 18.0},
    { 1.0, 17.0},
    { 1.0, 16.0},
    { 1.0, 15.0},
    { 1.0, 14.0},
    { 1.0, 13.0},
    { 1.0, 12.0},
    { 1.0, 11.0},
    { 1.0, 10.0},
    { 1.0,  9.0},
    { 1.0,  8.0},
    { 1.0,  7.0},
    { 1.0,  6.0},
    { 1.0,  5.0},
    { 1.0,  4.0},
    { 1.0,  3.0},
    { 1.0,  2.0},
    { 1.0,  1.0},
    { 1.5,  0.0},
    { 2.0,  1.0},
    { 2.0,  2.0},
    { 2.0,  3.0},
    { 2.0,  4.0},
    { 2.0,  5.0},
    { 2.0,  6.0},
    { 2.0,  7.0},
    { 2.0,  8.0},
    { 2.0,  9.0},
    { 2.0, 10.0},
    { 2.0, 11.0},
    { 2.0, 12.0},
    { 2.0, 13.0},
    { 2.0, 14.0},
    { 2.0, 15.0},
    { 2.0, 16.0},
    { 2.0, 17.0},
    { 2.5, 18.0},
    { 3.0, 17.0},
    { 3.0, 16.0},
    { 3.0, 15.0},
    { 3.0, 14.0},
    { 3.0, 13.0},
    { 3.0, 12.0},
    { 3.0, 11.0},
    { 3.0, 10.0},
    { 3.0,  9.0},
    { 3.0,  8.0},
    { 3.0,  7.0},
    { 3.0,  6.0},
    { 3.0,  5.0},
    { 3.0,  4.0},
    { 3.0,  3.0},
    { 3.0,  2.0},
    { 3.0,  1.0},
    { 3.5,  0.0},
    { 4.0,  1.0},
    { 4.0,  2.0},
    { 4.0,  3.0},
    { 4.0,  4.0},
    { 4.0,  5.0},
    { 4.0,  6.0},
    { 4.0,  7.0},
    { 4.0,  8.0},
    { 4.0,  9.0},
    { 4.0, 10.0},
    { 4.0, 11.0},
    { 4.0, 12.0},
    { 4.0, 13.0},
    { 4.0, 14.0},
    { 4.0, 15.0},
    { 4.0, 16.0},
    { 4.0, 17.0},
    { 4.5, 18.0},
    { 5.0, 17.0},
    { 5.0, 16.0},
    { 5.0, 15.0},
    { 5.0, 14.0},
    { 5.0, 13.0},
    { 5.0, 12.0},
    { 5.0, 11.0},
    { 5.0, 10.0},
    { 5.0,  9.0},
    { 5.0,  8.0},
    { 5.0,  7.0},
    { 5.0,  6.0},
    { 5.0,  5.0},
    { 5.0,  4.0},
    { 5.0,  3.0},
    { 5.0,  2.0},
    { 5.0,  1.0},
    { 6.0,  0.0},
    { 6.0,  1.0},
    { 6.0,  2.0},
    { 6.0,  3.0},
    { 6.0,  4.0},
    { 6.0,  5.0},
    { 6.0,  6.0},
    { 6.0,  7.0},
    { 6.0,  8.0},
    { 6.0,  9.0},
    { 6.0, 10.0},
    { 6.0, 11.0},
    { 6.0, 12.0},
    { 6.0, 13.0},
    { 6.0, 14.0},
    { 6.0, 15.0},
    { 6.0, 16.0},
    { 6.0, 17.0},
    { 6.5, 18.0},
    { 7.0, 17.0},
    { 7.0, 16.0},
    { 7.0, 15.0},
    { 7.0, 14.0},
    { 7.0, 13.0},
    { 7.0, 12.0},
    { 7.0, 11.0},
    { 7.0, 10.0},
    { 7.0,  9.0},
    { 7.0,  8.0},
    { 7.0,  7.0},
    { 7.0,  6.0},
    { 7.0,  5.0},
    { 7.0,  4.0},
    { 7.0,  3.0},
    { 7.0,  2.0},
    { 7.0,  1.0},
    { 7.5,  0.0},
    { 8.0,  1.0},
    { 8.0,  2.0},
    { 8.0,  3.0},
    { 8.0,  4.0},
    { 8.0,  5.0},
    { 8.0,  6.0},
    { 8.0,  7.0},
    { 8.0,  8.0},
    { 8.0,  9.0},
    { 8.0, 10.0},
    { 8.0, 11.0},
    { 8.0, 12.0},
    { 8.0, 13.0},
    { 8.0, 14.0},
    { 8.0, 15.0},
    { 8.0, 16.0},
    { 8.0, 17.0},
    { 8.5, 18.0},
    { 9.0, 17.0},
    { 9.0, 16.0},
    { 9.0, 15.0},
    { 9.0, 14.0},
    { 9.0, 13.0},
    { 9.0, 12.0},
    { 9.0, 11.0},
    { 9.0, 10.0},
    { 9.0,  9.0},
    { 9.0,  8.0},
    { 9.0,  7.0},
    { 9.0,  6.0},
    { 9.0,  5.0},
    { 9.0,  4.0},
    { 9.0,  3.0},
    { 9.0,  2.0},
    { 9.0,  1.0},
    { 9.5,  0.0},
    {10.0,  1.0},
    {10.0,  2.0},
    {10.0,  3.0},
    {10.0,  4.0},
    {10.0,  5.0},
    {10.0,  6.0},
    {10.0,  7.0},
    {10.0,  8.0},
    {10.0,  9.0},
    {10.0, 10.0},
    {10.0, 11.0},
    {10.0, 12.0},
    {10.0, 13.0},
    {10.0, 14.0},
    {10.0, 15.0},
    {10.0, 16.0},
    {10.0, 17.0},
    {10.5, 18.0},
    {11.0, 17.0},
    {11.0, 16.0},
    {11.0, 15.0},
    {11.0, 14.0},
    {11.0, 13.0},
    {11.0, 12.0},
    {11.0, 11.0},
    {11.0, 10.0},
    {11.0,  9.0},
    {11.0,  8.0},
    {11.0,  7.0},
    {11.0,  6.0},
    {11.0,  5.0},
    {11.0,  4.0},
    {11.0,  3.0},
    {11.0,  2.0},
    {11.0,  1.0},
    {11.5,  0.0},
    {12.0,  1.0},
    {12.0,  2.0},
    {12.0,  3.0},
    {12.0,  4.0},
    {12.0,  5.0},
    {12.0,  6.0},
    {12.0,  7.0},
    {12.0,  8.0},
    {12.0,  9.0},
    {12.0, 10.0},
    {12.0, 11.0},
    {12.0, 12.0},
    {12.0, 13.0},
    {12.0, 14.0},
    {12.0, 15.0},
    {12.0, 16.0},
    {12.0, 17.0},
    {12.5, 18.0},
    {13.0, 17.0},
    {13.0, 16.0},
    {13.0, 15.0},
    {13.0, 14.0},
    {13.0, 13.0},
    {13.0, 12.0},
    {13.0, 11.0},
    {13.0, 10.0},
    {13.0,  9.0},
    {13.0,  8.0},
    {13.0,  7.0},
    {13.0,  6.0},
    {13.0,  5.0},
    {13.0,  4.0},
    {13.0,  3.0},
    {13.0,  2.0},
    {13.0,  1.0},
    {14.0,  0.0},
    {14.0,  1.0},
    {14.0,  2.0},
    {14.0,  3.0},
    {14.0,  4.0},
    {14.0,  5.0},
    {14.0,  6.0},
    {14.0,  7.0},
    {14.0,  8.0},
    {14.0,  9.0},
    {14.0, 10.0},
    {14.0, 11.0},
    {14.0, 12.0},
    {14.0, 13.0},
    {14.0, 14.0},
    {14.0, 15.0},
    {14.0, 16.0},
    {14.0, 17.0},
    {14.5, 18.0},
    {15.0, 17.0},
    {15.0, 16.0},
    {15.0, 15.0},
    {15.0, 14.0},
    {15.0, 13.0},
    {15.0, 12.0},
    {15.0, 11.0},
    {15.0, 10.0},
    {15.0,  9.0},
    {15.0,  8.0},
    {15.0,  7.0},
    {15.0,  6.0},
    {15.0,  5.0},
    {15.0,  4.0},
    {15.0,  3.0},
    {15.0,  2.0},
    {15.0,  1.0},
    {15.5,  0.0},
    {16.0,  1.0},
    {16.0,  2.0},
    {16.0,  3.0},
    {16.0,  4.0},
    {16.0,  5.0},
    {16.0,  6.0},
    {16.0,  7.0},
    {16.0,  8.0},
    {16.0,  9.0},
    {16.0, 10.0},
    {16.0, 11.0},
    {16.0, 12.0},
    {16.0, 13.0},
    {16.0, 14.0},
    {16.0, 15.0},
    {16.0, 16.0},
    {16.0, 17.0},
    {16.5, 18.0},
    {17.0, 17.0},
    {17.0, 16.0},
    {17.0, 15.0},
    {17.0, 14.0},
    {17.0, 13.0},
    {17.0, 12.0},
    {17.0, 11.0},
    {17.0, 10.0},
    {17.0,  9.0},
    {17.0,  8.0},
    {17.0,  7.0},
    {17.0,  6.0},
    {17.0,  5.0},
    {17.0,  4.0},
    {17.0,  3.0},
    {17.0,  2.0},
    {17.0,  1.0},
    {17.5,  0.0},
    {18.0,  1.0},
    {18.0,  2.0},
    {18.0,  3.0},
    {18.0,  4.0},
    {18.0,  5.0},
    {18.0,  6.0},
    {18.0,  7.0},
    {18.0,  8.0},
    {18.0,  9.0},
    {18.0, 10.0},
    {18.0, 11.0},
    {18.0, 12.0},
    {18.0, 13.0},
    {18.0, 14.0},
    {18.0, 15.0},
    {18.0, 16.0},
    {18.0, 17.0},
    {18.5, 18.0},
    {19.0, 17.0},
    {19.0, 16.0},
    {19.0, 15.0},
    {19.0, 14.0},
    {19.0, 13.0},
    {19.0, 12.0},
    {19.0, 11.0},
    {19.0, 10.0},
    {19.0,  9.0},
    {19.0,  8.0},
    {19.0,  7.0},
    {19.0,  6.0},
    {19.0,  5.0},
    {19.0,  4.0},
    {19.0,  3.0},
    {19.0,  2.0},
    {19.0,  1.0},
};

static_assert(LEDNUM == sizeof(pixelMap) / sizeof(pixelMap[0]), "bad LEDNUM");

PixelMap pixels(LEDNUM, pixelMap);

#endif  // ORANGE_VEST

#if IS_GAUNTLET
Matrix pixels(/*w=*/20, /*h=*/15);
#endif  // IS_GAUNTLET

#if HAMMER
Matrix pixels(/*w=*/LEDNUM, /*h=*/1);
#endif  // HAMMER

#if FAIRY_WAND
static constexpr int kMatrixWidth = 3;
static constexpr int kMatrixHeight = 3;
static_assert(LEDNUM == kMatrixWidth * kMatrixHeight, "bad LEDNUM");
Matrix pixels(/*w=*/kMatrixWidth, /*h=*/kMatrixHeight, /*resolution=*/1.0);
#endif  // FAIRY_WAND

#if IS_STAFF

constexpr Point pixelMap[] = {
    {2.00,  1.00},
    {2.00,  2.00},
    {2.00,  3.00},
    {2.00,  4.00},
    {2.00,  5.00},
    {2.00,  6.00},
    {2.00,  7.00},
    {2.00,  8.00},
    {2.00,  9.00},
    {2.00, 10.00},
    {2.00, 11.00},
    {2.00, 12.00},
    {2.00, 13.00},
    {2.00, 14.00},
    {2.00, 15.00},
    {2.00, 16.00},
    {2.00, 17.00},
    {2.00, 18.00},
    {2.00, 19.00},
    {2.00, 20.00},
    {2.00, 21.00},
    {2.00, 22.00},
    {2.00, 23.00},
    {2.00, 24.00},
    {2.00, 25.00},
    {2.00, 26.00},
    {2.00, 27.00},
    {2.00, 28.00},
    {2.00, 29.00},
    {2.00, 30.00},
    {2.00, 31.00},
    {2.00, 32.00},
    {2.00, 33.00},
    {2.00, 34.00},
    {2.00, 35.00},
    {2.00, 36.00},
};

static_assert(LEDNUM == sizeof(pixelMap) / sizeof(pixelMap[0]), "bad LEDNUM");

PixelMap pixels(LEDNUM, pixelMap);

constexpr Point pixelMap2[] = {
    {0.00,  0.00},
    {1.00,  0.00},
    {2.00,  0.00},
    {3.00,  0.00},
    {4.00,  0.00},
    {3.00,  0.00},
    {2.00,  0.00},
    {1.00,  0.00},
    {0.00, -1.00},
    {1.00, -1.00},
    {2.00, -1.00},
    {3.00, -1.00},
    {4.00, -1.00},
    {3.00, -1.00},
    {2.00, -1.00},
    {1.00, -1.00},
    {0.00, -2.00},
    {1.00, -2.00},
    {2.00, -2.00},
    {3.00, -2.00},
    {4.00, -2.00},
    {3.00, -2.00},
    {2.00, -2.00},
    {1.00, -2.00},
    {0.00, -3.00},
    {1.00, -3.00},
    {2.00, -3.00},
    {3.00, -3.00},
    {4.00, -3.00},
    {3.00, -3.00},
    {2.00, -3.00},
    {1.00, -3.00},
    {0.00, -4.00},
};

static_assert(LEDNUM2 == sizeof(pixelMap2) / sizeof(pixelMap2[0]), "bad LEDNUM2");

PixelMap pixels2(LEDNUM2, pixelMap2);

#endif  // IS_STAFF

#if IS_CAPTAIN_HAT
constexpr Point pixelMap[] = {
    { 0.00, 0.00},
    { 1.00, 0.00},
    { 2.00, 0.00},
    { 3.00, 0.00},
    { 4.00, 0.00},
    { 5.00, 0.00},
    { 6.00, 0.00},
    { 7.00, 0.00},
    { 8.00, 0.00},
    { 9.00, 0.00},
    {10.00, 0.00},
    {11.00, 0.00},
    {12.00, 0.00},
    {13.00, 0.00},
    {14.00, 0.00},
    {15.00, 0.00},
    {16.00, 0.00},
    {17.00, 0.00},
    {18.00, 0.00},
    {19.00, 0.00},
    {20.00, 0.00},
    {21.00, 0.00},
    {22.00, 0.00},
    {23.00, 0.00},
    {22.00, 0.00},
    {21.00, 0.00},
    {20.00, 0.00},
    {19.00, 0.00},
    {18.00, 0.00},
    {17.00, 0.00},
    {16.00, 0.00},
    {15.00, 0.00},
    {14.00, 0.00},
    {13.00, 0.00},
    {12.00, 0.00},
    {11.00, 0.00},
    {10.00, 0.00},
    { 9.00, 0.00},
    { 8.00, 0.00},
    { 7.00, 0.00},
    { 6.00, 0.00},
    { 5.00, 0.00},
    { 4.00, 0.00},
    { 3.00, 0.00},
    { 2.00, 0.00},
    { 1.00, 0.00},
    { 0.00, 0.00},
    { 1.00, 0.00},
    EmptyPoint(),
    EmptyPoint(),  EmptyPoint(),  EmptyPoint(),  EmptyPoint(),  EmptyPoint(),  EmptyPoint(),  EmptyPoint(),
    EmptyPoint(),  EmptyPoint(),  EmptyPoint(),  EmptyPoint(),
};

static_assert(LEDNUM == sizeof(pixelMap) / sizeof(pixelMap[0]), "bad LEDNUM");

PixelMap pixels(LEDNUM, pixelMap);

#endif  // IS_CAPTAIN_HAT

#if IS_ROPELIGHT
Matrix pixels(/*w=*/LEDNUM, /*h=*/1);
#endif  // IS_ROPELIGHT

}  // namespace

const Layout* GetLayout() { return &pixels; }

#if LEDNUM2
const Layout* GetLayout2() { return &pixels2; }
#endif  // LEDNUM2

}  // namespace jazzlights

#endif  // ARDUINO
