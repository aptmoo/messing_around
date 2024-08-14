#include "spritesheet.h"

SpriteSheet::SpriteSheet(const Image &image, int spriteWidth, int spriteHeight, int sheetWidth, int sheetHeight, int offset)
{
    m_SpriteOffset = offset;
    m_Sheet = LoadTextureFromImage(image);
    m_SpriteSize = {spriteWidth, spriteHeight};
    m_SheetSize = {sheetWidth, sheetHeight};
}

SpriteSheet::~SpriteSheet()
{
    UnloadTexture(m_Sheet);
}

void SpriteSheet::Draw(int spriteX, int spriteY, Vector2 pos)
{
    Rectangle spriteRec =
        {
            (float)spriteX * (m_Sheet.width / m_SheetSize.x + m_SpriteOffset),
            (float)spriteY * (m_Sheet.height / m_SheetSize.y + m_SpriteOffset),
            (float)m_SpriteSize.x,
            (float)m_SpriteSize.y,
        };
    DrawTextureRec(m_Sheet, spriteRec, pos, WHITE);
}

void SpriteSheet::Draw(int spriteX, int spriteY, Vector2 pos, Vector2 scale, float rotation)
{
    Rectangle spriteRec =
        {
            (float)spriteX * (m_Sheet.width / m_SheetSize.x + m_SpriteOffset),
            (float)spriteY * (m_Sheet.height / m_SheetSize.y + m_SpriteOffset),
            (float)m_SpriteSize.x,
            (float)m_SpriteSize.y,
        };

    Rectangle destRec =
        {
            pos.x,
            pos.y,
            (m_SpriteSize.x) * scale.x,
            (m_SpriteSize.y) * scale.y,
        };

    Vector2 origin = {m_SpriteSize.x *(scale.x/2), m_SpriteSize.y * (scale.y/2)};
    DrawTexturePro(m_Sheet, spriteRec, destRec, origin, rotation, WHITE);
}