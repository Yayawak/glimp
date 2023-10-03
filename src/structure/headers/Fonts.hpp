#pragma once
#include <cstdio>
#ifndef ffont_H
#define ffont_H

// #define __STDC_WANT_LIB_EXT1__ 1 // for fopen_secure()
#include <stdio.h>
#include <stdlib.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include <stb/stb_truetype.h>

class Font
{

    unsigned int Atlas;
    int width;
    int height;
    void *data;

    Font(const char *pathToFontFile)
    {
        width = 256;
        height = 256;

        unsigned char *bitmap = new unsigned char[width * height];
        
        FILE *file = nullptr;
        file = fopen(pathToFontFile, "rb");

        // get file size
        fseek(file, 0, SEEK_END);

        
        
    }
    ~Font()
    {

    }
};

#endif