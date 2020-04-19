#pragma once
//#include <iostream>
#include <GL/glew.h>
//#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

class WindowBase {
public:
    WindowBase();
    virtual ~WindowBase();
    void init(int width, int height, char* windowName);

    bool isExist(void);
    void run(void);

    virtual void glInit(void);
    virtual void display(void);

    virtual void keyboard(int key, int scancode, int action, int mods);
    //virtual void mouseButton();
    //virtual void mouseCursor();
    virtual void mouseScroll(double x, double y);
    virtual void resize(int width, int height);

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void charCallback(GLFWwindow* window, unsigned int charInfo);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    static void mousePosCallback(GLFWwindow* window, double x, double y);
    //:**********************************************************************
    //!
    //! @brief  マウスのホイールのコールバック関数
    //!
    //! @param in
    //!     GLFWwindow* window: ウィンドウのハンドラ
    //!     double x:   前回からの移動量x
    //!     double y:   前回からの移動量y
    //!
    //:**********************************************************************
    static void mouseScrollCallback(GLFWwindow* window, double x, double y);
    static void windowSizeCallback(GLFWwindow* window, int width, int height);

protected:
    GLFWwindow* glfwWindow;
    int windowWidth, windowHeight;
private:

};

