#include "example-robot.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

Window::Window()
{

}

Window::~Window()
{
    glfwTerminate();
}

void Window::display(void)
{
    resize(m_windowWidth, m_windowHeight);

    gl::draw3Axis(0, 0, 0);

    //床
    if(1)
    {
        glColor3d(0.6, 0.6, 0.6);
        glPushMatrix();
        glTranslated(0, 0, -500);
        gl::drawSolidCube(1000);
        glPopMatrix();
    }

    //胴体
    glColor3d(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslated(0, 0, 750);
    gl::drawSolidRectangular(200, 100, 500);

    //頭
    glColor3d(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(0, 0, 250);
    glRotated(30, 1.0, 0.0, 0.0);   //+:うなずく
    gl::drawSolidRectangular2(80, 80, 120);
    glPopMatrix();

    //左腕
    glColor3d(0.0, 1.0, 1.0);   //水色
    glPushMatrix();
    glTranslated(150, 0, 250);
    glRotated(180 - 30, 1, 0, 0);   //-:腕前から挙げる
    gl::drawSolidRectangular2(80, 80, 200);
    //左手
    glColor3d(1.0, 0.0, 0.0);   //赤
    glTranslated(0, 0, 200);
    glRotated(-30, 1, 0, 0);
    gl::drawSolidRectangular2(80, 80, 200);
    glPopMatrix();  //左腕

    //右腕
    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslated(-150, 0, 250);
    glRotated(180 - 30, 1, 0, 0);   //-:腕前から挙げる
    gl::drawSolidRectangular2(80, 80, 200);
    //右手
    glTranslated(0, 0, 200);
    glRotated(-30, 1, 0, 0);
    gl::drawSolidRectangular2(80, 80, 200);
    glPopMatrix();

    //左大腿
    glColor3d(1.0, 0.0, 1.0);
    glPushMatrix();
    glTranslated(70, 0, -250);
    glRotated(180 - 30, 1, 0, 0);
    gl::drawSolidRectangular2(100, 100, 250);
    //左足
    glColor3d(1.0, 1.0, 0.0);
    glTranslated(0, 0, 250);
    glRotated(30, 1, 0, 0);
    gl::drawSolidRectangular2(100, 100, 250);
    glPopMatrix();

    //右大腿
    glColor3d(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(-70, 0, -250);
    glRotated(180 - 0, 1, 0, 0);
    gl::drawSolidRectangular2(100, 100, 250);
    //右足
    glTranslated(0, 0, 250);
    glRotated(0, 1, 0, 0);
    gl::drawSolidRectangular2(100, 100, 250);
    glPopMatrix();

    glPopMatrix();  //胴体

    glFlush();
}

void Window::drawBlocks(void)
{
    double Size = 500; //1辺の長さ[mm]
    int BoxNum = 10;

    for (int i = 0; i < BoxNum; i++)
    {
        if(i % 2 == 0) glColor3d(0.6, 0.6, 0.6);
        else glColor3d(0.3, 0.3, 0.3);

        glPushMatrix();
        glTranslated(1250, (double(i) + 0.5) * Size, 250);   //平行移動値の設定
        gl::drawSolidCube((float)Size);
        glPopMatrix();
        glPushMatrix();
        glTranslated(1250, (double(i) + 0.5) * Size, 750);   //平行移動値の設定
        gl::drawSolidCube((float)Size);
        glPopMatrix();
        glPushMatrix();
        glTranslated(1250, (double(i) + 0.5) * Size, 1250);   //平行移動値の設定
        gl::drawSolidCube((float)Size);
        glPopMatrix();
        glPushMatrix();
        glTranslated(1250, (double(i) + 0.5) * Size, 1750);   //平行移動値の設定
        gl::drawSolidCube((float)Size);
        glPopMatrix();
    }
}

void Window::keyboard(int key, int scancode, int action, int mods)
{
    static bool shiftPressed = false;
    switch (key)
    {
    case 256:   //'ESC'
        glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
        break;
    case 340:   //ShiftL
        //fall through
    case 344:   //ShiftR
        if (action == GLFW_PRESS) shiftPressed = true;
        else if (action == GLFW_RELEASE) shiftPressed = false;
        break;
    case 88:    //'x'
        if(shiftPressed) m_cameraPos[0] += 500;
        else m_cameraPos[0] -= 500;
        break;
    case 89:    //'y'
        if(shiftPressed) m_cameraPos[1] += 500;
        else m_cameraPos[1] -= 500;
        break;
    case 90:    //'z'
        if(shiftPressed) m_cameraPos[2] += 500;
        else m_cameraPos[2] -= 500;
        break;
    case 87:    //'w'
        //if (action == GLFW_PRESS)
        //{
        //    //アスペクト比変更
        //    if (displayParam.aspectRatio == STANDARD) displayParam.aspectRatio = WIDE;
        //    else displayParam.aspectRatio = STANDARD;
        //}
        break;
    case 86:    //'v'
        //ウィンドウ表示切り替え
        //非表示にするとキーコールバックが行われなくなるので実質非表示のみ
        if (action == GLFW_PRESS)
        {
            int visible = glfwGetWindowAttrib(glfwWindow, GLFW_VISIBLE);
            if (visible)
                glfwHideWindow(glfwWindow);
            else
                glfwShowWindow(glfwWindow);
        }
    default: break;
    }
}

void Window::resize(int width, int height)
{
    m_windowWidth = width;
    m_windowHeight = height;

    //バッファ読み取り位置がずれないように
    //画像の表示位置：左上、大きさ固定
    glViewport(0, 0, width, height);

    //投影変換
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //カメラ画角
    gluPerspective(45.0, 1.0, 1.0, 30000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //カメラ座標、カメラ角度

    gluLookAt(
        m_cameraPos[0], m_cameraPos[1], m_cameraPos[2],
        m_cameraDir[0], m_cameraDir[1], m_cameraDir[2],
        m_cameraUpward[0], m_cameraUpward[1], m_cameraUpward[2]
    );
}
