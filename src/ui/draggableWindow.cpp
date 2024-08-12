#include "draggableWindow.h"
#include "raygui.h"

#if !defined(RAYGUI_WINDOWBOX_STATUSBAR_HEIGHT)
    #define RAYGUI_WINDOWBOX_STATUSBAR_HEIGHT 24
#endif

#if !defined(RAYGUI_WINDOW_CLOSEBUTTON_SIZE)
    #define RAYGUI_WINDOW_CLOSEBUTTON_SIZE 18
#endif

void DraggableWindow::Update()
{
    Rectangle title_collision_rect = { m_Position.x, m_Position.y, m_Extent.x - (RAYGUI_WINDOW_CLOSEBUTTON_SIZE + ((RAYGUI_WINDOWBOX_STATUSBAR_HEIGHT - RAYGUI_WINDOW_CLOSEBUTTON_SIZE) / 2)), RAYGUI_WINDOWBOX_STATUSBAR_HEIGHT };
    Rectangle resize_collision_rect = { m_Position.x + m_Extent.x - 20, m_Position.y + m_Extent.y - 20, 20, 20 };
    Vector2 mousePos = GetMousePosition();
    if(CheckCollisionPointRec(mousePos, title_collision_rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        m_Dragging = true;
    }

    if(CheckCollisionPointRec(mousePos, resize_collision_rect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        m_Resizing = true;
    }

    if(m_Dragging)
    {
        m_Position = Vector2Add(GetMouseDelta(), m_Position);
        m_Position = Vector2Clamp(m_Position, Vector2Zero(), {(float)GetScreenWidth() - m_Extent.x, (float)GetScreenHeight() -  m_Extent.y});
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            m_Dragging = false;
        }
    }

    if(m_Resizing)
    {
        if(mousePos.x > m_Position.x && mousePos.y > m_Position.y)
        {
            m_Extent = Vector2Subtract(mousePos, m_Position);
        }
        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            m_Resizing = false;
        }
    }
}

void DraggableWindow::Render()
{
    DrawText(TextFormat("%f, %f", m_Position.x, m_Position.y), 10, 10, 20, RED);
    GuiWindowBox({m_Position.x, m_Position.y, m_Extent.x, m_Extent.y}, m_Name.c_str());
}