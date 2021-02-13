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

    glPushMatrix(); //世界のプッシュ
    glTranslated(worldX, worldY, worldZ);

    gl::draw3Axis(0, 0, 0);

    //床
    if(m_displayFloor)
    {
        double BoxSize = 500;
        int BoxNum = 10;
        for(int i = 0; i < BoxNum; i++)
        {
            for(int j = 0; j < BoxNum; j++)
            {
                if((i + j) % 2 == 0) glColor3d(0.6, 0.6, 0.6);
                else glColor3d(0.3, 0.3, 0.3);
                glPushMatrix();
                glTranslated((j - BoxNum/2) * BoxSize, (i - BoxNum/2) * BoxSize, 0);
                glTranslated(BoxSize/2, BoxSize/2, -BoxSize/2);
                gl::drawSolidCube(BoxSize);
                glPopMatrix();
            }
        }
    }

    //胴体
    glColor3d(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslated(0, 0, 750);
    if(m_displayMode == Solid) gl::drawSolidRectangular(400, 150, 500);
    else if(m_displayMode == Wire) gl::drawWireRectangular(400, 150, 500);

    //頭
    glColor3d(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(0, 0, 250);
    glRotated(neckAngleX, 1.0, 0.0, 0.0);
    glRotated(neckAngleY, 0.0, 1.0, 0.0);
    glRotated(neckAngleZ, 0.0, 0.0, 1.0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(150, 150, 150);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(150, 150, 150);
    glPopMatrix();

    //左腕
    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslated(200 + 60, 0, 200);
    glRotated(180 - shoulderAngleL, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(120, 120, 300);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(120, 120, 300);
    //左手
    glColor3d(1.0, 0.0, 0.0);
    glTranslated(0, 0, 300);
    glRotated(-elbowAngleL, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(120, 120, 300);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(120, 120, 300);
    glPopMatrix();  //左腕

    //右腕
    glColor3d(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslated(-200 - 60, 0, 200);
    glRotated(180 - shoulderAngleR, 1, 0, 0);   //-:腕前から挙げる
    if(m_displayMode == Solid) gl::drawSolidRectangular2(120, 120, 300);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(120, 120, 300);
    //右手
    glTranslated(0, 0, 300);
    glRotated(-elbowAngleR, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(120, 120, 300);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(120, 120, 300);
    glPopMatrix();

    //左大腿
    glColor3d(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(100, 0, -250);
    glRotated(180 - hipAngleL, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(180, 180, 250);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(180, 180, 250);
    //左足
    glTranslated(0, 0, 250);
    glRotated(kneeAngleL, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(180, 180, 250);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(180, 180, 250);
    glPopMatrix();

    //右大腿
    glColor3d(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslated(-100, 0, -250);
    glRotated(180 - hipAngleR, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(180, 180, 250);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(180, 180, 250);
    //右足
    glTranslated(0, 0, 250);
    glRotated(kneeAngleR, 1, 0, 0);
    if(m_displayMode == Solid) gl::drawSolidRectangular2(180, 180, 250);
    else if(m_displayMode == Wire) gl::drawWireRectangular2(180, 180, 250);
    glPopMatrix();

    glPopMatrix();  //胴体

    glPopMatrix();  //世界のプッシュ

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
    //printf("%d\n", key);
    switch(key)
    {
    case 256:   //'ESC'
        glfwSetWindowShouldClose(m_glfwWindow, GLFW_TRUE);
        break;
    case 340:   //ShiftL
        //fall through
    case 344:   //ShiftR
        if (action == GLFW_PRESS) shiftPressed = true;
        else if (action == GLFW_RELEASE) shiftPressed = false;
        break;
    default: break;
    }

    if(action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch(key)
        {
        case 88:    //'x'
            if(!shiftPressed) worldX += 500;
            else worldX -= 500;
            break;
        case 89:    //'y'
            if(!shiftPressed) worldY += 500;
            else worldY -= 500;
            break;
        case 90:    //'z'
            if(!shiftPressed) worldZ += 500;
            else worldZ -= 500;
            break;
        case 48:    //'0'
            if(!shiftPressed) neckAngleX += 5;
            else neckAngleX -= 5;
            break;
        case 49:    //'1'
            if(!shiftPressed) shoulderAngleL += 5;
            else shoulderAngleL -= 5;
            break;
        case 50:    //'2'
            if(!shiftPressed) elbowAngleL += 5;
            else elbowAngleL -= 5;
            break;
        case 51:    //'3'
            if(!shiftPressed) shoulderAngleR += 5;
            else shoulderAngleR -= 5;
            break;
        case 52:    //'4'
            if(!shiftPressed) elbowAngleR += 5;
            else elbowAngleR -= 5;
            break;
        case 53:    //'5'
            if(!shiftPressed) hipAngleL += 5;
            else hipAngleL -= 5;
            break;
        case 54:    //'6'
            if(!shiftPressed) kneeAngleL += 5;
            else kneeAngleL -= 5;
            break;
        case 55:    //'7'
            if(!shiftPressed) hipAngleR += 5;
            else hipAngleR -= 5;
            break;
        case 56:    //'8'
            if(!shiftPressed) kneeAngleR += 5;
            else kneeAngleR -= 5;
            break;
        case 84:    //'t': 表示モード切り替え
            m_displayMode = (DisplayMode)(((int)m_displayMode + 1) % DisplayMode::Size);
            break;
        case 86:    //'v': 床表示非表示切り替え
            m_displayFloor = !m_displayFloor;
            break;
        case 87:    //'w'
            //カメラシフト
            m_cameraPos[0] += 50;
            break;
        default: break;
        }
    }

    //値制限
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
    //gluPerspective(30.0, 1.0, 1.0, 30000.0);
    gluPerspective(30.0, 1920.0/1080.0, 1.0, 30000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //カメラ座標、カメラ角度

    gluLookAt(
        m_cameraPos[0], m_cameraPos[1], m_cameraPos[2],
        m_cameraPos[0] + m_cameraDir[0], m_cameraPos[1] + m_cameraDir[1], m_cameraPos[2] + m_cameraDir[2],
        m_cameraUpward[0], m_cameraUpward[1], m_cameraUpward[2]
    );
}
