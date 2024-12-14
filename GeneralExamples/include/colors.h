//  COLORS.h
#ifndef COLORS_h
#define COLORS_h

/* FOREGROUND */
// These codes set the actual text to the specified color
#define RESETTEXT "\x1B[0m" // Set all colors back to normal.
#define FOREBLK "\x1B[30m"  // Black
#define FORERED "\x1B[31m"  // Red
#define FOREGRN "\x1B[32m"  // Green
#define FOREYEL "\x1B[33m"  // Yellow
#define FOREBLU "\x1B[34m"  // Blue
#define FOREMAG "\x1B[35m"  // Magenta
#define FORECYN "\x1B[36m"  // Cyan
#define FOREWHT "\x1B[37m"  // White

/* BACKGROUND */
// These codes set the background color behind the text.
#define BACKBLK "\x1B[40m" // Black
#define BACKRED "\x1B[41m" // Red
#define BACKGRN "\x1B[42m" // Green
#define BACKYEL "\x1B[43m" // Yellow
#define BACKBLU "\x1B[44m" // Blue
#define BACKMAG "\x1B[45m" // Magenta
#define BACKCYN "\x1B[46m" // Cyan
#define BACKWHT "\x1B[47m" // White

#define BackBLK(x) BACKBLK x RESETTEXT
#define ForeRED(x) FORERED x RESETTEXT

#endif