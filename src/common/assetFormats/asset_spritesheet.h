#ifndef ASSETFORMAT_SPRITESHEET_H
#define ASSETFORMAT_SPRITESHEET_H
#include "common/spritesheet.h"

enum class SpriteSheetFormat
{
    LATEST,
    V0_0_1,
};

SpriteSheet LoadSpriteSheet(SpriteSheetFormat format = SpriteSheetFormat::LATEST);

#endif