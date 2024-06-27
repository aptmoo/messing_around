#ifndef CORE_DRAGGABLEWINDOW_H
#define CORE_DRAGGABLEWINDOW_H
#include <raylib.h>
#include <raymath.h>
#include <string>

class DraggableWindow
{
public:
    virtual void Update();
    virtual void Render();

    void SetName(const std::string& name) { m_Name = name; };
    std::string GetName() { return m_Name; }

    void SetSize(Vector2 size) { m_Extent = size; };
    Vector2 GetSize() { return m_Extent; };

    void SetPosition(Vector2 pos) { m_Position = pos; };
    Vector2 GetPosition() {return m_Position; }

    void SetResizable(bool resizable) { m_IsResizable = resizable; };
    bool GetResizable() { return m_IsResizable; };

    void SetDraggable(bool draggable) { m_IsDraggable = draggable; };
    bool GetDraggable() { return m_IsDraggable; };
private:
    std::string m_Name;

    Vector2 m_Position = Vector2Zero();
    Vector2 m_Extent = Vector2Zero();

    bool m_IsDraggable = true;
    bool m_Dragging = false;
    
    bool m_IsResizable = true;
    bool m_Resizing = false;
};

#endif