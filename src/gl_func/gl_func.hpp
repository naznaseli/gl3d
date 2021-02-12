#pragma once
#include <GL/glew.h>
//#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <opencv2/opencv.hpp>

//:**********************************************************************
//! 3次元空間上での描画機能
//:**********************************************************************
namespace gl
{
//! 色指定(透過対応)
class ColorSetter
{
public:
    //! @param
    //!     color:  8ビット色指定
    ColorSetter(const cv::Scalar& color)
    {
        setColor(color);
    };
    ~ColorSetter()
    {
        if(m_color.val[3] != 255) glDisable(GL_BLEND);
    };
    void setColor(const cv::Scalar& color)
    {
        m_color = color;
        if(color.val[3] != 255) //透明
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glColor4ub((GLubyte)m_color.val[2], (GLubyte)m_color.val[1], (GLubyte)m_color.val[0], (GLubyte)m_color.val[3]);
        }
        else
        {
            glColor3ub((GLubyte)m_color.val[2], (GLubyte)m_color.val[1], (GLubyte)m_color.val[0]);
        }
    };
private:
    cv::Scalar m_color;
};

//! 線(1次元)**********************************************************************
void arc(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness = 1);
void arcReverse(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness = 1);

//! 平面(2次元)**********************************************************************
//! 円を描く(Z座標=0)
void circle2D(double* centerPos, double radius, int lineWidth);
//! 弧を描く
void arc2D(double* centerPos, double radius, int lineWidth, double start, double end);
//! 線分を描く(Z座標=0)
void segment(double startPosX, double startPosY, double endPosX, double endPosY, int lineWidth);
//! 左右の線分
//void segmentWidth(double posY, double startPosX, double endPosX, int lineWidth);
void segmentWidth(double posY, double posZ, double startPosX, double endPosX, int lineWidth, const cv::Scalar& color);
//! 前後の線分
void segmentDepth(double posX, double posZ, double startPosY, double endPosY, int lineWidth, const cv::Scalar& color);

//! 長方形を描く
void rectangle(double x1, double y1, double z1, double x2, double y2, double z2, const cv::Scalar& color);
//! 円を描く
void circleX(double y1, double z1, int radius, const cv::Scalar& color, int thickness);
void circleY(double z1, double x1, int radius, const cv::Scalar& color, int thickness);
void circleZ(double* center, int radius, const cv::Scalar& color, int thickness);
//! 弧を描く
void arcZ(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness = 1);
void arcZReverse(double* center, double radius, double startAngle, double endAngle, const cv::Scalar& color, int thickness = 1);

//! 立体(3次元)**********************************************************************
//! 立方体を描く
//void cube(double x1, double y1, double z1, double x2, double y2, double z2, const cv::Scalar& color);
void cube(double* center, int side, const cv::Scalar& color);
//! 球を描く
//void sphere(double centerX, double centerY, double centerZ, int radius, int color);
void sphere(double* center, int radius, const cv::Scalar& color);
    
}

//void drawPictureInPicture(cv::Mat& img, cv::Mat& img2, int x, int y, int w, int h);

