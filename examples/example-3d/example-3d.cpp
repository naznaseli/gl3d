//#include "opengl.hpp"
#include "gl3d.hpp"

class Window : public WindowBase
{
public:
    void glInit(void);
    void resize(int width, int height);

    //! 描画
    void display(void);

private:

};

void Window::glInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //αの有効化
    //glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA , GL_ONE);

    //カメラパラメタ設定
    m_cameraPos[0] = 500;
    m_cameraPos[1] = 500;
    m_cameraPos[2] = 500;
    m_cameraDir[0] = 0;
    m_cameraDir[1] = 0;
    m_cameraDir[2] = 0;
    m_cameraUpward[0] = 0;
    m_cameraUpward[1] = 0;
    m_cameraUpward[2] = 1;
}

void Window::resize(int width, int height)
{
    m_windowWidth = width;
    m_windowHeight = height;

    //ウィンドウ全体をビューポートに
    glViewport(0, 0, width, height);

    //投影変換
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //カメラ画角
    gluPerspective(30.0, (float)m_windowWidth / (float)m_windowHeight, 1.0, 10000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(
        m_cameraPos[0],
        m_cameraPos[1],
        m_cameraPos[2],
        m_cameraDir[0],
        m_cameraDir[1],
        m_cameraDir[2],
        m_cameraUpward[0],
        m_cameraUpward[1],
        m_cameraUpward[2]
    );
}

void Window::display(void)
{
    resize(m_windowWidth, m_windowHeight);
    draw3Axis(0, 0, 0);
    glFlush();
}

int main(int argc, char** argv)
{
    Window window;
    window.glInit();

    while(window.isExist())
    {
        //描画
        window.run();
    }

    return 0;
}
