#include "../include/Image.h"
#include "../include/HSLAPixel.h"
#include <cmath>
#include <cstdlib>

void Image::darken() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.l >= 0.1) {
                pixel.l -= 0.1;
            } else {
                pixel.l = 0;
            }
        }
    }
}

void Image::darken(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.l - amount > 0) {
                pixel.l -= amount;
            } else {
                pixel.l = 0;
            }
        }
    }
}

void Image::desaturate() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.s >= 0.1) {
                pixel.s -= 0.1;
            } else {
                pixel.s = 0;
            }
        }
    }
}

void Image::desaturate(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.s - amount > 0) {
                pixel.s -= amount;
            } else {
                pixel.s = 0;
            }
        }
    }
}

void Image::grayscale() {
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel& pixel = getPixel(x,y);
      pixel.s = 0;
    }
  }
}

void Image::illinify() {
    double orange = 11;
    double blue = 216;
    double orange_distance;
    double blue_distance;
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
        cs225::HSLAPixel & pixel = getPixel(x, y);
        orange_distance = std::min(std::abs(pixel.h - orange), 360 + orange - pixel.h);
        blue_distance = std::min(std::abs(pixel.h - blue), 360 + blue - pixel.h);
        if (blue_distance < orange_distance) {
            pixel.h = blue;
        } else {
            pixel.h = orange;
        }
        }
    }
}

void Image::lighten() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.l <= 0.9) {
                pixel.l += 0.1;
            } else {
                pixel.l = 1;
            }
        }
    }
}

void Image::lighten(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.l + amount < 1) {
                pixel.l += amount;
            } else {
                pixel.l = 1;
            }
        }
    }
}

void Image::rotateColor(double degrees) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.h + degrees <= 360 && pixel.h + degrees >=0) {
                pixel.h += degrees;
            } else {
                if (degrees > 0) {
                    pixel.h = pixel.h + degrees - ((int)(pixel.h + degrees) / 360) * 360;
                } else {
                    pixel.h = pixel.h + degrees + floor((pixel.h + degrees) / 360) * -360;
                }
            }
        }
    }
}

void Image::saturate() {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.s <= 0.9) {
                pixel.s += 0.1;
            } else {
                pixel.s = 1;
            }
        }
    }
}

void Image::saturate(double amount) {
    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            cs225::HSLAPixel& pixel = getPixel(x, y);
            if (pixel.s + amount < 1) {
                pixel.s += amount;
            } else {
                pixel.s = 1;
            }
        }
    }
}

void Image::scale(double factor) {
    if (factor != 1) {
        Image before_scale = *this;
        resize(width() * factor, height() * factor);
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                cs225::HSLAPixel& new_pixel = getPixel(x, y);
                cs225::HSLAPixel& old_pixel = before_scale.getPixel(x / factor, y / factor);
                new_pixel = old_pixel;
            }
        }
    }
} 

void Image::scale(unsigned w, unsigned h) {
    if ((double)w != width() || (double)h != height()) {
        double smaller_factor = std::min((double)w / width(), (double)h / height());
        scale(smaller_factor);
    }
}

