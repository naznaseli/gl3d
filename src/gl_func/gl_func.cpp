#include "./gl_func.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

namespace gl
{
//色指定

//xy平面に描画、高さ対応
void arc(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness)
{
    //glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    ColorSetter cs(color);
    const int Split = (int)radius / 10;    //分割数
    //const int Split = 500;

    //glBegin(GL_TRIANGLES);
    glLineWidth((GLfloat)thickness);
    glBegin(GL_LINES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i / Split;
        double rate2 = (double)(i + 1) / Split;

        if ((2.0 * M_PI * rate1 >= startAngle) && (2.0 * M_PI * rate2 <= endAngle))
        {
            double pos1x = radius * cos(2.0 * M_PI * rate1);
            double pos1y = radius * sin(2.0 * M_PI * rate1);
            double pos2x = radius * cos(2.0 * M_PI * rate2);
            double pos2y = radius * sin(2.0 * M_PI * rate2);
            glVertex3d(center[0] + pos1x, center[1] + pos1y, center[2]);
            glVertex3d(center[0] + pos2x, center[1] + pos2y, center[2]);
        }
    }
    glEnd();
}

void arcReverse(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness)
{
    //glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    ColorSetter cs(color);
    const int Split = (int)radius / 10;    //分割数
    //const int Split = 500;

    //glBegin(GL_TRIANGLES);
    glLineWidth((GLfloat)thickness);
    glBegin(GL_LINES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i / Split;
        double rate2 = (double)(i + 1) / Split;

        if ((2.0 * M_PI * rate1 >= startAngle) && (2.0 * M_PI * rate2 <= endAngle))
        {
            double pos1x = radius * -cos(2.0 * M_PI * rate1);
            double pos1y = radius * sin(2.0 * M_PI * rate1);
            double pos2x = radius * -cos(2.0 * M_PI * rate2);
            double pos2y = radius * sin(2.0 * M_PI * rate2);
            glVertex3d(center[0] + pos1x, center[1] + pos1y, center[2]);
            glVertex3d(center[0] + pos2x, center[1] + pos2y, center[2]);
        }
    }
    glEnd();
}

//! 円を描く
//void circle2D(double* centerPos, double radius)
//{
//    circle2D(centerPos, radius, m_lineWidth);
//}

//! @param in
//!     centerPos:  中心点
//!     radius:     半径
//!     lineWidth:  線の幅[mm]
void circle2D(double* centerPos, double radius, int lineWidth)
{
    int n = (int)(radius / 10);    //分割数
    //int LineWidth = 50; //[mm]

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < n; i++)
    {
        double rate1 = (double)i / n;
        double rate2 = (double)(i + 1) / n;

        double x_inside1 = (double)(radius - lineWidth / 2) * cos(2.0 * M_PI * rate1);
        double y_inside1 = (double)(radius - lineWidth / 2) * sin(2.0 * M_PI * rate1);
        double x_outside1 = (double)(radius + lineWidth / 2) * cos(2.0 * M_PI * rate1);
        double y_outside1 = (double)(radius + lineWidth / 2) * sin(2.0 * M_PI * rate1);
        double x_inside2 = (double)(radius - lineWidth / 2) * cos(2.0 * M_PI * rate2);
        double y_inside2 = (double)(radius - lineWidth / 2) * sin(2.0 * M_PI * rate2);
        double x_outside2 = (double)(radius + lineWidth / 2) * cos(2.0 * M_PI * rate2);
        double y_outside2 = (double)(radius + lineWidth / 2) * sin(2.0 * M_PI * rate2);
        glVertex3d(centerPos[0] + x_inside1, centerPos[1] + y_inside1, 0.0);
        glVertex3d(centerPos[0] + x_outside1, centerPos[1] + y_outside1, 0.0);
        glVertex3d(centerPos[0] + x_outside2, centerPos[1] + y_outside2, 0.0);
        glVertex3d(centerPos[0] + x_inside1, centerPos[1] + y_inside1, 0.0);
        glVertex3d(centerPos[0] + x_outside2, centerPos[1] + y_outside2, 0.0);
        glVertex3d(centerPos[0] + x_inside2, centerPos[1] + y_inside2, 0.0);
    }
    glEnd();
}

//! @param in
//!     centerPos:  中心点
//!     radius:     半径
//!     lineWidth:  線の幅[mm]
//!     start:      描画開始地点[rad]
//!     end:        描画終了地点[rad]
void arc2D(double* centerPos, double radius, int lineWidth, double start, double end)
{
    int n = (int)(radius / 10);    //分割数

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < n; i++)
    {
        double rate1 = (double)i / n;
        double rate2 = (double)(i + 1) / n;

        if (2.0 * M_PI * rate1 >= start && 2.0 * M_PI * rate2 <= end)
        {
            double x_inside1 = (double)(radius - lineWidth / 2) * cos(2.0 * M_PI * rate1);
            double y_inside1 = (double)(radius - lineWidth / 2) * sin(2.0 * M_PI * rate1);
            double x_outside1 = (double)(radius + lineWidth / 2) * cos(2.0 * M_PI * rate1);
            double y_outside1 = (double)(radius + lineWidth / 2) * sin(2.0 * M_PI * rate1);
            double x_inside2 = (double)(radius - lineWidth / 2) * cos(2.0 * M_PI * rate2);
            double y_inside2 = (double)(radius - lineWidth / 2) * sin(2.0 * M_PI * rate2);
            double x_outside2 = (double)(radius + lineWidth / 2) * cos(2.0 * M_PI * rate2);
            double y_outside2 = (double)(radius + lineWidth / 2) * sin(2.0 * M_PI * rate2);
            glVertex3d(centerPos[0] + x_inside1, centerPos[1] + y_inside1, 0.0);
            glVertex3d(centerPos[0] + x_outside1, centerPos[1] + y_outside1, 0.0);
            glVertex3d(centerPos[0] + x_outside2, centerPos[1] + y_outside2, 0.0);
            glVertex3d(centerPos[0] + x_inside1, centerPos[1] + y_inside1, 0.0);
            glVertex3d(centerPos[0] + x_outside2, centerPos[1] + y_outside2, 0.0);
            glVertex3d(centerPos[0] + x_inside2, centerPos[1] + y_inside2, 0.0);
        }
    }
    glEnd();
}

//! 線分を描く
//! X軸Y軸に直行する直線のみ
//void segment(double startPosX, double startPosY, double endPosX, double endPosY)
//{
//    segment(startPosX, startPosY, endPosX, endPosY, m_lineWidth);
//}

//! 線分を描く(太さ指定)
//! @param in
//!     startPosX,startPosY:    始点
//!     endPosX,endPosY:        終点
//!     lineWidth:              線の太さ[mm]
void segment(double startPosX, double startPosY, double endPosX, double endPosY, int lineWidth)
{
}

//! 左右の線分
//void segmentWidth(double posY, double startPosX, double endPosX, int lineWidth)
//{
//    int length = abs((int)(endPosX - startPosX));   //[mm]
//    int Split = 10;
//    int n = (int)((double)length / Split);  //[mm]
//
//    glBegin(GL_TRIANGLES);
//    for (int i = 0; i < Split; i++)
//    {
//        double rate1 = (double)i * n;
//        double rate2 = (double)(i + 1) * n;
//
//        glVertex3d(startPosX + rate1, (double)(posY - lineWidth / 2), 0.0);
//        glVertex3d(startPosX + rate1, (double)(posY + lineWidth / 2), 0.0);
//        glVertex3d(startPosX + rate2, (double)(posY + lineWidth / 2), 0.0);
//        glVertex3d(startPosX + rate1, (double)(posY - lineWidth / 2), 0.0);
//        glVertex3d(startPosX + rate2, (double)(posY + lineWidth / 2), 0.0);
//        glVertex3d(startPosX + rate2, (double)(posY - lineWidth / 2), 0.0);
//    }
//    glEnd();
//}

//void segmentDepth(double posX, double startPosY, double endPosY)
//{
//    segment(posX, startPosY, endPosY, m_lineWidth);
//}

//! 左右の線分
void segmentWidth(double posY, double posZ, double startPosX, double endPosX, int lineWidth, const cv::Scalar& color)
{
    ColorSetter cs(color);
    int length = abs((int)(endPosX - startPosX));   //[mm]
    int Split = 10;
    int n = (int)((double)length / Split);   //[mm]

    //if(color.val[3] != 255) //透明
    //{
    //    glEnable(GL_BLEND);
    //    //glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
    //    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //    glColor4ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0], (GLubyte)color.val[3]);
    //}
    //else
    //{
    //    glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    //}
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i * n;
        double rate2 = (double)(i + 1) * n;

        glVertex3d(startPosX + rate1, (double)(posY - lineWidth / 2), posZ);
        glVertex3d(startPosX + rate1, (double)(posY + lineWidth / 2), posZ);
        glVertex3d(startPosX + rate2, (double)(posY + lineWidth / 2), posZ);
        glVertex3d(startPosX + rate1, (double)(posY - lineWidth / 2), posZ);
        glVertex3d(startPosX + rate2, (double)(posY + lineWidth / 2), posZ);
        glVertex3d(startPosX + rate2, (double)(posY - lineWidth / 2), posZ);
    }
    glEnd();
    //if(color.val[3] != 255) glDisable(GL_BLEND);
}

//! 前後の線分
void segmentDepth(double posX, double posZ, double startPosY, double endPosY, int lineWidth, const cv::Scalar& color)
{
    ColorSetter cs(color);
    int length = abs((int)(endPosY - startPosY));   //[mm]
    int Split = 10;
    int n = (int)((double)length / Split);   //[mm]

    //glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i * n;
        double rate2 = (double)(i + 1) * n;

        glVertex3d((double)(posX - lineWidth / 2), startPosY + rate1, posZ);
        glVertex3d((double)(posX + lineWidth / 2), startPosY + rate1, posZ);
        glVertex3d((double)(posX + lineWidth / 2), startPosY + rate2, posZ);
        glVertex3d((double)(posX - lineWidth / 2), startPosY + rate1, posZ);
        glVertex3d((double)(posX + lineWidth / 2), startPosY + rate2, posZ);
        glVertex3d((double)(posX - lineWidth / 2), startPosY + rate2, posZ);
    }
    glEnd();
}

void rectangle(double x1, double y1, double z1, double x2, double y2, double z2, const cv::Scalar& color)
{
    glColor3d(color.val[0]/255, color.val[1]/255, color.val[2]/255);

    if (x1 == x2)
    {
        //yz平面に描く
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x1, y2, z1);
        glVertex3d(x1, y2, z2);
        glVertex3d(x1, y1, z2);
        glEnd();
    }
    if (y1 == y2)
    {
        //xz平面に描く
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x1, y1, z2);
        glVertex3d(x2, y1, z2);
        glVertex3d(x2, y1, z1);
        glEnd();
    }
    if (z1 == z2)
    {
        //xy平面に描く
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x2, y1, z1);
        glVertex3d(x2, y2, z1);
        glVertex3d(x1, y2, z1);
        glEnd();
    }
}

void circleX(double y1, double z1, int radius, cv::Scalar& color, int thickness = 1)
{
    glColor3d(color.val[0]/255, color.val[1]/255, color.val[2]/255);
}

void circleY(double z1, double x1, int radius, cv::Scalar& color, int thickness = 1)
{
    glColor3d(color.val[0]/255, color.val[1]/255, color.val[2]/255);

}

void circleZ(double* center, int radius, const cv::Scalar& color, int thickness = 1)
{
    glColor3d(color.val[0]/255, color.val[1]/255, color.val[2]/255);

    int n = radius / 10;    //分割数

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < n; i++)
    {
        double rate1 = (double)i / n;
        double rate2 = (double)(i + 1) / n;

        double x_inside1 = (double)(radius - thickness / 2) * cos(2.0 * M_PI * rate1);
        double y_inside1 = (double)(radius - thickness / 2) * sin(2.0 * M_PI * rate1);
        double x_outside1 = (double)(radius + thickness / 2) * cos(2.0 * M_PI * rate1);
        double y_outside1 = (double)(radius + thickness / 2) * sin(2.0 * M_PI * rate1);
        double x_inside2 = (double)(radius - thickness / 2) * cos(2.0 * M_PI * rate2);
        double y_inside2 = (double)(radius - thickness / 2) * sin(2.0 * M_PI * rate2);
        double x_outside2 = (double)(radius + thickness / 2) * cos(2.0 * M_PI * rate2);
        double y_outside2 = (double)(radius + thickness / 2) * sin(2.0 * M_PI * rate2);
        glVertex3d(center[0] + x_inside1, center[1] + y_inside1, 0.0);
        glVertex3d(center[0] + x_outside1, center[1] + y_outside1, 0.0);
        glVertex3d(center[0] + x_outside2, center[1] + y_outside2, 0.0);
        glVertex3d(center[0] + x_inside1, center[1] + y_inside1, 0.0);
        glVertex3d(center[0] + x_outside2, center[1] + y_outside2, 0.0);
        glVertex3d(center[0] + x_inside2, center[1] + y_inside2, 0.0);
    }
    glEnd();
}

void arcZ(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness)
{
    ColorSetter cs(color);
    //glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    const int Split = (int)radius / 10;    //分割数

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i / Split;
        double rate2 = (double)(i + 1) / Split;

        if ((2.0 * M_PI * rate1 >= startAngle) && (2.0 * M_PI * rate2 <= endAngle))
        {
            double x_inn1 = ((double)radius - (double)thickness / 2) * cos(2.0 * M_PI * rate1);
            double y_inn1 = ((double)radius - (double)thickness / 2) * sin(2.0 * M_PI * rate1);
            double x_out1 = ((double)radius + (double)thickness / 2) * cos(2.0 * M_PI * rate1);
            double y_out1 = ((double)radius + (double)thickness / 2) * sin(2.0 * M_PI * rate1);
            double x_inn2 = ((double)radius - (double)thickness / 2) * cos(2.0 * M_PI * rate2);
            double y_inn2 = ((double)radius - (double)thickness / 2) * sin(2.0 * M_PI * rate2);
            double x_out2 = ((double)radius + (double)thickness / 2) * cos(2.0 * M_PI * rate2);
            double y_out2 = ((double)radius + (double)thickness / 2) * sin(2.0 * M_PI * rate2);
            glVertex3d(center[0] + x_inn1, center[1] + y_inn1, center[2]);
            glVertex3d(center[0] + x_out1, center[1] + y_out1, center[2]);
            glVertex3d(center[0] + x_out2, center[1] + y_out2, center[2]);
            glVertex3d(center[0] + x_inn1, center[1] + y_inn1, center[2]);
            glVertex3d(center[0] + x_out2, center[1] + y_out2, center[2]);
            glVertex3d(center[0] + x_inn2, center[1] + y_inn2, center[2]);
        }
    }
    glEnd();
}

//! X軸を始点として、右回り(第2象限->第1象限->第4象限->第3象限の順)に弧を描く
void arcZReverse(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness)
{
    ColorSetter cs(color);
    //glColor3ub((GLubyte)color.val[2], (GLubyte)color.val[1], (GLubyte)color.val[0]);
    const int Split = (int)radius / 10;    //分割数

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Split; i++)
    {
        double rate1 = (double)i / Split;
        double rate2 = (double)(i + 1) / Split;

        if ((2.0 * M_PI * rate1 >= startAngle) && (2.0 * M_PI * rate2 <= endAngle))
        {
            double x_inn1 = ((double)radius - (double)thickness / 2) * -cos(2.0 * M_PI * rate1);
            double y_inn1 = ((double)radius - (double)thickness / 2) * sin(2.0 * M_PI * rate1);
            double x_out1 = ((double)radius + (double)thickness / 2) * -cos(2.0 * M_PI * rate1);
            double y_out1 = ((double)radius + (double)thickness / 2) * sin(2.0 * M_PI * rate1);
            double x_inn2 = ((double)radius - (double)thickness / 2) * -cos(2.0 * M_PI * rate2);
            double y_inn2 = ((double)radius - (double)thickness / 2) * sin(2.0 * M_PI * rate2);
            double x_out2 = ((double)radius + (double)thickness / 2) * -cos(2.0 * M_PI * rate2);
            double y_out2 = ((double)radius + (double)thickness / 2) * sin(2.0 * M_PI * rate2);
            glVertex3d(center[0] + x_inn1, center[1] + y_inn1, center[2]);
            glVertex3d(center[0] + x_out1, center[1] + y_out1, center[2]);
            glVertex3d(center[0] + x_out2, center[1] + y_out2, center[2]);
            glVertex3d(center[0] + x_inn1, center[1] + y_inn1, center[2]);
            glVertex3d(center[0] + x_out2, center[1] + y_out2, center[2]);
            glVertex3d(center[0] + x_inn2, center[1] + y_inn2, center[2]);
        }
    }
    glEnd();
}

}//namespace gl
