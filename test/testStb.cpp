#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

int main(void)
{
    int w, h, channels;
    unsigned char *bytes = stbi_load("img/slark.png",
        &w, &h, &channels, 0);
    if (!bytes)
    {
        std::cout << "Error in loadin the image\n" << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "Image is readed.\n";
        std::cout << bytes;
    }
    return (0);
}