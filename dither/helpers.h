//
// Created by kieran on 6/09/18.
//

#ifndef DITHER_HELPERS_H
#define DITHER_HELPERS_H

#include <algorithm>
#include <png++/png.hpp>

using namespace png;


int sqr_dif(png_byte a, png_byte b)
{
    return (a < b) ? (b - a) * (b - a) : (a - b) * (a - b);
}

int color_difference(const color &a, const color &b)
{
    return sqr_dif(a.red, b.red) + sqr_dif(a.green, b.green) + sqr_dif(a.blue, b.blue);
}

color quantize(const color &pixel, const std::vector<color> &palette)
{
    auto less = [&](const color &a, const color &b)
    {
        return color_difference(a, pixel) < color_difference(b, pixel);
    };
    return *std::min_element(std::begin(palette), std::end(palette), less);
}

color pixel_to_color(const rgb_pixel &pixel)
{
    return color{pixel.red, pixel.green, pixel.blue};
}

auto pixel_offset(const rgb_pixel &a, const rgb_pixel &b)
{
    return basic_rgb_pixel<short>(
            (short) a.red - (short) b.red,
            (short) a.green - (short) b.green,
            (short) a.blue - (short) b.blue);
}

png_byte clamp_short(short value)
{
    return (png_byte) std::max<short>(0, std::min<short>(value, 255));
}

void add_error(rgb_pixel &pixel, const basic_rgb_pixel<short> &error)
{
    pixel = rgb_pixel(
            clamp_short(error.red + pixel.red),
            clamp_short(error.green + pixel.green),
            clamp_short(error.blue + pixel.blue));
}

rgb_pixel color_to_pixel(const color &color)
{
    return {color.red, color.green, color.blue};
}

auto mult_div_error(const basic_rgb_pixel<short> &error, short multiply, short divide)
{
    return basic_rgb_pixel<short>(
            error.red * multiply / divide,
            error.green * multiply / divide,
            error.blue * multiply / divide);
}

#endif //DITHER_HELPERS_H
