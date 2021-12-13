#include "../include/StickerSheet.h"
#include "../include/Image.h"

StickerSheet::StickerSheet(const Image& picture, unsigned max) {
    max_images_ = max;
    base_ = new Image(picture);
}

StickerSheet::~StickerSheet() {
    clear();
}

StickerSheet::StickerSheet(const StickerSheet& other) {
    copy(other);
}

const StickerSheet& StickerSheet::operator=(const StickerSheet& other){
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

void StickerSheet::changeMaxStickers(unsigned max) {
    if (max < stickers_.size()) {
        stickers_.resize(max);
        x_coord_.resize(max);
        y_coord_.resize(max);
    }
    max_images_ = max;
}

int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y) {
    if (stickers_.size() > max_images_) {
        return -1;
    }
    if (stickers_.size() > 0) {
        for (unsigned i = 0; i < stickers_.size(); i++) {
            if (stickers_[i] == NULL) {
                stickers_[i] = &sticker;
                x_coord_[i] = x;
                y_coord_[i] = y;
                return i;
            }
        }
    }
    stickers_.push_back(&sticker);
    x_coord_.push_back(x);
    y_coord_.push_back(y);
    return stickers_.size() -1;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
    if (index >= stickers_.size() || stickers_[index] == NULL) {
        return false;
    }
    x_coord_[index] = x;
    y_coord_[index] = y;
    return true;
}

void StickerSheet::removeSticker(unsigned index){
    if (index < stickers_.size()) {
        stickers_[index] = NULL;
    }
}

Image* StickerSheet::getSticker(unsigned index) {
    if (stickers_[index] == NULL || index < 0 || index >= stickers_.size()) {
        return NULL;
    }
    return stickers_[index];
}

Image StickerSheet::render() const {
    Image final = Image();
    final.resize(base_->width(), base_->height());
    for (unsigned y = 0; y < final.height(); y++) {
        for (unsigned x = 0; x < final.width(); x++) {
            cs225::HSLAPixel& current_pixel = final.getPixel(x, y);
            current_pixel = base_->getPixel(x,y);
        }
    }

    for (unsigned i = 0; i < stickers_.size(); i++) {
        if (stickers_[i] != NULL) {
            if (y_coord_[i] + stickers_[i]->height() > final.height()) {
                final.resize(final.width(), y_coord_[i] + stickers_[i]->height());
            }
            if (x_coord_[i] + stickers_[i]->width() > final.width()) {
                final.resize(x_coord_[i] + stickers_[i]->width(), final.height());
            }
            for (unsigned y = 0; y < stickers_[i]->height(); y++) {
                for (unsigned x = 0; x < stickers_[i]->width(); x++) {
                    if (stickers_[i]->getPixel(x,y).a != 0) {
                    cs225::HSLAPixel& current_pixel = final.getPixel(x + x_coord_[i], y + y_coord_[i]);
                    current_pixel = stickers_[i]->getPixel(x,y);
                    }
                }
            }
        }
    }

    return final;
}

void StickerSheet::clear() {
    x_coord_.clear();
    y_coord_.clear();
    if (base_ != NULL) {

        delete base_;
    }
    stickers_.clear();
}

void StickerSheet::copy(const StickerSheet& other) {
    max_images_ = other.max_images_;
    x_coord_ = other.x_coord_;
    y_coord_ = other.y_coord_;
    stickers_ = other.stickers_;
    base_ = new Image(*other.base_);
}









