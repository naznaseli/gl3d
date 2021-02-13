#include <stdio.h>
#include "opengl.hpp"
#include "draw.hpp"

typedef enum
{
    Solid, Wire, Size
}DisplayMode;

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

    DisplayMode m_displayMode = Solid;

    int worldX = 0, worldY = 0, worldZ = 0;

    bool m_displayFloor = true;

    int neckAngleX = 0; //+:頷く
    int neckAngleY = 0; //+:左に首を傾げる
    int neckAngleZ = 0; //+:左を見る
    int shoulderAngleL = 0, shoulderAngleR = 0;   //+:前に挙げる
    int elbowAngleL = 0, elbowAngleR = 0; //+:曲げる
    int hipAngleL = 0, hipAngleR = 0;   //+:膝を持ち上げる
    int kneeAngleL = 0, kneeAngleR = 0; //+:曲げる
};
