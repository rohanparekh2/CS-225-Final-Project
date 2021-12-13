/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include <vector>
#include "Image.h"
class StickerSheet{
    public:
        StickerSheet(const Image& picture, unsigned max);
        ~StickerSheet();
        StickerSheet(const StickerSheet& other);
        const StickerSheet& operator=(const StickerSheet& other);
        void changeMaxStickers(unsigned max);
        int addSticker(Image& sticker, unsigned x, unsigned y);
        bool translate(unsigned index, unsigned x, unsigned y);
        void removeSticker(unsigned index);
        Image* getSticker(unsigned index);
        Image render() const;
    private:
        unsigned max_images_;
        Image* base_;
        std::vector<Image*> stickers_;
        std::vector<unsigned> x_coord_;
        std::vector<unsigned> y_coord_;
        void clear();
        void copy(const StickerSheet& other);


};

 
