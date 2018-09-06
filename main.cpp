#include <iostream>
#include "dither/dither.h"

png::palette getpalette();

int main()
{
    const png::palette palette = getpalette();

    png::image<png::rgb_pixel> image("cat.png");

    dthr::dither(image, palette);

    image.write("rgb.png");

    return 0;
}

png::palette getpalette()
{
    return {png::color(0, 0, 0),        //Black
            png::color(34, 32, 52),     //Valhalla
            png::color(69, 40, 60),     //Loulou
            png::color(102, 57, 49),    //Ceder
            png::color(143, 86, 59),    //Rope
            png::color(223, 113, 38),   //Tahiti
            png::color(217, 160, 102),  //Twine
            png::color(238, 195, 154),  //Pancho
            png::color(251, 242, 54),   //Fizz
            png::color(153, 229, 80),   //Atlantis
            png::color(106, 190, 48),   //Christi
            png::color(55, 148, 110),   //Elf
            png::color(75, 105, 47),    //Dell
            png::color(82, 75, 36),     //Verdigris
            png::color(50, 60, 57),     //Opal
            png::color(63, 63, 116),    //Koamaru
            png::color(48, 96, 130),    //Venice
            png::color(91, 110, 225),   //Royal
            png::color(99, 155, 255),   //Cornflower
            png::color(95, 205, 228),   //Viking
            png::color(203, 219, 252),  //Steel
            png::color(255, 255, 255),  //White
            png::color(155, 173, 183),  //Heather
            png::color(132, 126, 135),  //Topaz
            png::color(105, 106, 106),  //Gray
            png::color(89, 86, 82),     //Ash
            png::color(118, 66, 138),   //Clairvoyant
            png::color(172, 50, 50),    //Brown
            png::color(217, 87, 99),    //Mandy
            png::color(215, 123, 186),  //Plum
            png::color(143, 151, 74),   //Forest
            png::color(138, 111, 48)};  //Stinger
}