//
// Created by kieran on 6/09/18.
//

#ifndef DITHER_DITHER_H
#define DITHER_DITHER_H

#include <png++/image.hpp>

namespace dthr
{
void dither(png::image<png::rgb_pixel> &image, const png::palette &palette);
}

#endif //DITHER_DITHER_H
