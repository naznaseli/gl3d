#include <stdio.h>
#include "opengl.hpp"

class Window : public WindowBase
{
public:
    Window();
    ~Window();

    //! OpenGL
    //int init(int width, int height, char* windowName);
    //void glInit(void);
    void display(void);

    //! コールバック関数
    void keyboard(int key, int scancode, int action, int mods);
    void resize(int width, int height);

private:
    //unsigned int m_windowWidth;
    //unsigned int m_windowHeight;
};
