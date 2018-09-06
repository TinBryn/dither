//
// Created by kieran on 6/09/18.
//

#include <algorithm>
#include "dither.h"
#include "helpers.h"

using namespace png;

namespace dthr
{
void dither(image<rgb_pixel> &image, const palette &palette)
{
    const auto WIDTH = static_cast<const int>(image.get_width());
    const auto HEIGHT = static_cast<const int>(image.get_height());
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            const rgb_pixel old_pixel = image[y][x];
            const rgb_pixel new_pixel = color_to_pixel(quantize(pixel_to_color(old_pixel), palette));
            image[y][x] = new_pixel;

            const basic_rgb_pixel<short> error = pixel_offset(old_pixel, new_pixel);

            if (y < HEIGHT - 1)
            {
                add_error(image[y + 1][x], mult_div_error(error, 5, 16));
                if (x > 0)
                {
                    add_error(image[y + 1][x - 1], mult_div_error(error, 3, 16));
                }
                if (x < WIDTH - 1)
                {
                    add_error(image[y + 1][x + 1], mult_div_error(error, 1, 16));
                }
            }
            if (x < WIDTH - 1)
            {
                add_error(image[y][x + 1], mult_div_error(error, 7, 16));
            }

        }
    }
}
}



