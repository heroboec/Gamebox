#ifndef GRAPHICS_H
#define GRAPHICS_H

// COLORS
// 
// are defined as 6-bit integer: RRGGBB

#define BLACK 0
/*#define BLUE 3
#define GREEN 12
#define RED 48*/
#define BLUE 0x44
#define GREEN 0x22
#define RED 0x11
#define CYAN (BLUE + GREEN)
#define PURPLE (RED + BLUE)
#define YELLOW (RED + GREEN)
#define WHITE (RED + GREEN + BLUE)
/* for 6-bit colored games */
/* brigthness of the msb is higher */
#define BLUE_DARK 4
#define RED_DARK 1
#define RED_MIDDLE 0x10
#define YELLOW_DARK 3
#define YELLOW_MIDDLE 0x30
#define WHITE_DARK 0x7
#define TRANSPARENT 0xff

// SPRITE

struct game_sprite
{
    uint8_t width;
    uint8_t height;
    uint8_t lineSize;
    const uint8_t *lines;
};

struct game_color_sprite
{
    uint8_t width;
    uint8_t height;
    const uint8_t *lines;
};

// Setup functions

void game_enable_frame_buffer();

// Sprite functions

uint8_t game_sprite_width(const struct game_sprite *s);
uint8_t game_sprite_height(const struct game_sprite *s);
uint8_t game_color_sprite_width(const struct game_color_sprite *s);
uint8_t game_color_sprite_height(const struct game_color_sprite *s);

// DRAWING FUNCTIONS

void game_draw_pixel(int x, int y, uint8_t color);
uint8_t game_get_pixel(int x, int y);
void game_draw_vline(int x, int y1, int y2, uint8_t color); // vertical line
void game_draw_rect(int x, int y, int w, int h, uint8_t color);
void game_draw_text(const uint8_t *s, int x, int y, uint8_t color, uint8_t bg = TRANSPARENT); // text is drawn with default 5x7 font
void game_draw_char(uint8_t c, int x, int y, uint8_t color, uint8_t bg = TRANSPARENT); // char is drawn with default 5x7 font
void game_draw_sprite(const struct game_sprite *s, int x, int y, uint8_t color);
void game_draw_digits(uint16_t num, int len, int x, int y, uint8_t color, uint8_t bg = TRANSPARENT);
void game_draw_color_sprite(const struct game_color_sprite *s, int x, int y);
/* Clear screen in frame buffer mode */
void game_clear_screen();

bool game_is_drawing_lines(int y, int height);

// Internal functions
// Called only by libgame

void graphics_setup();

#endif

