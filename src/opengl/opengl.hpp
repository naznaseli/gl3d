#pragma once
#include <GL/glew.h>
//#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

class WindowBase
{
public:
    WindowBase();
    virtual ~WindowBase();
    virtual int init(int width, int height, char* windowName);

    bool isExist(void);
    void run(void);

    //! 描画関連
    virtual void glInit(void);
    virtual void display(void);
    //! 座標軸を描く
    void draw3Axis(float xPos, float yPos, float zPos);
    //! 直方体を描く
    void drawSolidCube(float size);

    //! コールバック
    virtual void keyboard(int key, int scancode, int action, int mods);
    virtual void mouseButton(int button, int action, int mods);
    virtual void mouseCursorPos(double x, double y);
    virtual void mouseScroll(double x, double y);
    virtual void resize(int width, int height);

    //! 静的コールバック
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void charCallback(GLFWwindow* window, unsigned int charInfo);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void cursorPosCallback(GLFWwindow* window, double x, double y);
    static void scrollCallback(GLFWwindow* window, double x, double y);
    static void windowSizeCallback(GLFWwindow* window, int width, int height);

protected:
    GLFWwindow* m_glfwWindow;
    unsigned int m_windowWidth, m_windowHeight;
    double m_cameraPos[3];
    double m_cameraDir[3];
    double m_cameraUpward[3];

private:

};
