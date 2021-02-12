#include <stdio.h>
#include "opengl.hpp"
#include "draw.hpp"

class Window : public WindowBase
{
public:
    Window();
    ~Window();

    //! OpenGL
    //int init(int width, int height, char* windowName);
    //void glInit(void);
    void display(void);

    //! 描画
    void drawBlocks(void);

    //! コールバック関数
    void keyboard(int key, int scancode, int action, int mods);
    void resize(int width, int height);

private:
    //unsigned int m_windowWidth;
    //unsigned int m_windowHeight;
};
