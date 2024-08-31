#ifndef COMMON_SPRITESHEET_H
#define COMMON_SPRITESHEET_H
#include "common/types.h"
#include <string>
#include <raylib.h>

struct SpriteSheetDesc
{
    std::string name;
    Size2D spriteSize;
    Size2D sheetSize;
    int offset;
};

class SpriteSheet
{
public:
    /**
     * @brief Sprite sheet constructor.
     *
     * @param image Texture data.
     * @param w Width of sprite, not total!
     * @param h Height of sprite, not total!
     */
    SpriteSheet(const Image& image, const SpriteSheetDesc& desc);
    ~SpriteSheet();

    /**
     * @brief Simple draw function.
     * Draws from pos downward and rightward.
     * 
     * @param spriteX 
     * @param spriteY 
     * @param pos 
     */
    void Draw(int spriteX, int spriteY, Vector2 pos);
    inline void Draw(Size2D frame, Vector2 pos) { Draw(frame.x, frame.y, pos); };

    /**
     * @brief Proper draw function.
     * Draws with pos as center.
     * 
     * @param spriteX 
     * @param spriteY 
     * @param pos 
     * @param scale 
     * @param rotation 
     */
    void Draw(int spriteX, int spriteY, Vector2 pos, Vector2 scale, float rotation);
    inline void Draw(Size2D frame, Vector2 pos, Vector2 scale, float rotation) { Draw(frame.x, frame.y, pos, scale, rotation); };

    inline Size2D GetSpriteSize() { return m_SpriteSize; };
private:
    Texture2D m_Sheet;
    Size2D m_SheetSize;

    Size2D m_SpriteSize;
    int m_SpriteOffset;
};

#endif