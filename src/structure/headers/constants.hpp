#ifndef Consts_H
#define Consts_H

// extern const int screenWidth = 1024;
// extern const int screenHeight = 768;

// #define standard_window
// #define medium_window
#define small_window

// NOTE : i should use these values
#ifdef standard_window
const int screenWidth = 1024;
// const int screenHeight = 768;
const int screenHeight = 650;
#endif

#ifdef medium_window
const int screenWidth = 850;
const int screenHeight = 500;
#endif

#ifdef small_window
const int screenWidth = 700;
// const int screenHeight = 768;
const int screenHeight = 400;
#endif

// const int screenWidth = 1024 / 2;
// const int screenHeight = 768 / 1.5;

#endif