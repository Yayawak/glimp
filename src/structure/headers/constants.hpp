#ifndef Consts_H
#define Consts_H

// extern const int screenWidth = 1024;
// extern const int screenHeight = 768;

#define standard_window

// NOTE : i should use these values
#ifdef standard_window
const int screenWidth = 1024;
// const int screenHeight = 768;
const int screenHeight = 650;
#endif


#ifdef small_window
const int screenWidth = 500;
// const int screenHeight = 768;
const int screenHeight = 300;
#endif

// const int screenWidth = 1024 / 2;
// const int screenHeight = 768 / 1.5;

#endif