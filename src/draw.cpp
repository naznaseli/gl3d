#include "draw.hpp"
#include <GL/glew.h>
//#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

namespace gl
{

//! 座標軸を描く
void draw3Axis(float xPos, float yPos, float zPos)
{
    //先の長さ
    float distance = 100.0;
    //線の太さ
    glLineWidth(3);

    //X軸描画
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(xPos, yPos, zPos);
    glVertex3d(xPos + distance, yPos, zPos);
    glEnd();

    //Y軸描画
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(xPos, yPos, zPos);
    glVertex3d(xPos, yPos + distance, zPos);
    glEnd();

    //Z軸描画
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(xPos, yPos, zPos);
    glVertex3d(xPos, yPos, zPos + distance);
    glEnd();
}

//! 直方体描画
//! @param in
//!     float size:    一辺の長さ
void drawSolidCube(float size)
{
    glBegin(GL_QUADS);
    glVertex3d(size / 2, size / 2, size / 2);
    glVertex3d(-size / 2, size / 2, size / 2);
    glVertex3d(-size / 2, -size / 2, size / 2);
    glVertex3d(size / 2, -size / 2, size / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(size / 2, -size / 2, -size / 2);
    glVertex3d(-size / 2, -size / 2, -size / 2);
    glVertex3d(-size / 2, size / 2, -size / 2);
    glVertex3d(size / 2, size / 2, -size / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(size / 2, size / 2, size / 2);
    glVertex3d(size / 2, -size / 2, size / 2);
    glVertex3d(size / 2, -size / 2, -size / 2);
    glVertex3d(size / 2, size / 2, -size / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-size / 2, size / 2, -size / 2);
    glVertex3d(-size / 2, -size / 2, -size / 2);
    glVertex3d(-size / 2, -size / 2, size / 2);
    glVertex3d(-size / 2, size / 2, size / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(size / 2, size / 2, size / 2);
    glVertex3d(size / 2, size / 2, -size / 2);
    glVertex3d(-size / 2, size / 2, -size / 2);
    glVertex3d(-size / 2, size / 2, size / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-size / 2, -size / 2, size / 2);
    glVertex3d(-size / 2, -size / 2, -size / 2);
    glVertex3d(size / 2, -size / 2, -size / 2);
    glVertex3d(size / 2, -size / 2, size / 2);
    glEnd();
}

//! xyz原点を中心に直方体を描く
void drawSolidRectangular(float x, float y, float z)
{
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glEnd();
}

//! xy原点を中心にz方向に直方体を描く
void drawSolidRectangular2(float x, float y, float z)
{
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(-x / 2, y / 2, 0);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(x / 2, -y / 2, 0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(x / 2, y / 2, z);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(x / 2, -y / 2, 0);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(x / 2, y / 2, z);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(-x / 2, y / 2, 0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(x / 2, y / 2, z);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(-x / 2, y / 2, 0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(x / 2, -y / 2, 0);
    glEnd();

}

void drawWireRectangular(float x, float y, float z)
{
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, z / 2);
    glVertex3d(x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, -z / 2);
    glVertex3d(-x / 2, y / 2, z / 2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(-x / 2, -y / 2, z / 2);
    glVertex3d(-x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, -y / 2, -z / 2);
    glVertex3d(x / 2, -y / 2, z / 2);
    glEnd();

}

void drawWireRectangular2(float x, float y, float z)
{
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(-x / 2, y / 2, 0);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(x / 2, -y / 2, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(x / 2, y / 2, z);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(x / 2, -y / 2, 0);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(x / 2, y / 2, z);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(-x / 2, y / 2, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(x / 2, y / 2, 0);
    glVertex3d(x / 2, y / 2, z);
    glVertex3d(-x / 2, y / 2, z);
    glVertex3d(-x / 2, y / 2, 0);
    glEnd();
    glBegin(GL_LINES);
    glVertex3d(-x / 2, -y / 2, 0);
    glVertex3d(-x / 2, -y / 2, z);
    glVertex3d(x / 2, -y / 2, z);
    glVertex3d(x / 2, -y / 2, 0);
    glEnd();

}

}//namespace
