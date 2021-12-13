/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include "PNG.h"

class Image: public cs225::PNG {
    public:
        /**
         * Darken an Image by decreasing the luminance of every pixel by 0.1
         */
        void darken();

        /**
         * Darkens an Image by decreasing the luminance of every pixel by amount
         * @param amount Number that the luminance is decreased by
         */
        void darken(double amount);

        /**
         * Desaturates an Image by decreasing the saturation of every pixel by 0.1
         */
        void desaturate();

        /**
         * Desaturates an Image by decreasing the saturation of every pixel by amount
         * @param amount Number that the luminance is decreased by
         */
        void desaturate(double amount);

        /**
         * Turns the image grayscale
         */	
        void grayscale();

        /**
         * Illinify the image
         */	
        void illinify();

        /**
         * Lighten an Image by increasing the luminance of every pixel by 0.1
         */
        void lighten();

        /**
         * Darkens an Image by decreasing the luminance of every pixel by amount
         * @param amount Number that the luminance is increased by
         */
        void lighten(double amount);	

        /**
         * Rotates the color wheel by degrees
         * @param degrees Amount of degrees rotated
         */
        void rotateColor(double degrees);	

        /**
         * Saturates an Image by increasing the saturation of every pixel by 0.1
         */
        void saturate();

        /**
         * Saturates an Image by increasing the saturation of every pixel by amount
         * @param amount Number that the luminance is decreased by
         */
        void saturate(double amount);

        /**
         * Scales an image by the given factor
         * @param Factor Factor image is scaled by
         */
        void scale(double factor);

        /**
         * Scales an image to fit the width and height
         * @param w Desired width of image
         * @param h Desired height of image
         */
        void scale(unsigned w, unsigned h);


	
	




};


