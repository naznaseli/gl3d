#include "opengl.hpp"
#include <stdio.h>

WindowBase::WindowBase()
{
    //printf("WindowBase created\n");
}

WindowBase::~WindowBase()
{
    //printf("WindowBase deleted\n");
    glfwTerminate();
}

//GLFW, GLEW初期化、ウィンドウ作成
int WindowBase::init(int width, int height, char* windowName)
{
    m_windowWidth = width;
    m_windowHeight = height;

    //GLFW初期化
    if (glfwInit() == GL_FALSE)
    {
        //初期化失敗
        return -1;
    }

    //GLFWバージョン3.2
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //ウィンドウ非表示
    //glfwWindowHint(GLFW_VISIBLE, 0);

    m_glfwWindow = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if (m_glfwWindow == NULL)
    {
        return -2;
    }

    //静的メンバ関数をコールバックに登録
    glfwSetWindowUserPointer(m_glfwWindow, this);
    glfwSetKeyCallback(m_glfwWindow, keyCallback);
    glfwSetWindowSizeCallback(m_glfwWindow, windowSizeCallback);
    glfwSetMouseButtonCallback(m_glfwWindow, mouseButtonCallback);
    glfwSetScrollCallback(m_glfwWindow, scrollCallback);
    glfwSetCursorPosCallback(m_glfwWindow, cursorPosCallback);

    //ウィンドウを処理対象にする
    glfwMakeContextCurrent(m_glfwWindow); //GLEW初期化より前
    glfwSwapInterval(1);

    //GLEWの初期化
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        //初期化失敗
        return -3;
    }

    glInit();

    return 0;
}

//! 描画の初期化
void WindowBase::glInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //αの有効化
    //glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA , GL_ONE);

    //カメラパラメタ設定
    m_cameraPos[0] = 0;
    m_cameraPos[1] = -3000;
    m_cameraPos[2] = 1000;
    m_cameraDir[0] = 0;
    m_cameraDir[1] = 3000;
    m_cameraDir[2] = -500;
    m_cameraUpward[0] = 0;
    m_cameraUpward[1] = 0;
    m_cameraUpward[2] = 1;
}

//! ウィンドウ存在確認
//! @param out
//!     true:存在、false:消えてる
bool WindowBase::isExist(void)
{
    return !(glfwWindowShouldClose(m_glfwWindow));
}

void WindowBase::run(void)
{
    glfwMakeContextCurrent(m_glfwWindow);
    glfwSwapInterval(1);

    //画面消去
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //描画処理
    display();

    //バッファ入れ替え
    glfwSwapBuffers(m_glfwWindow);

    //イベント
    //glfwWaitEvents(); //イベント待ち続ける
    glfwPollEvents();
}

//! 描画
void WindowBase::display(void)
{
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1.0, 0.0);
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9, 0.9);
    glEnd();
    glFlush();
}



//! keyboard callback
void WindowBase::keyboard(int key, int scancode, int action, int mods)
{
    static bool shiftPressed = false;
    switch (key)
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
    case 88:    //'x'
        if(shiftPressed) m_cameraPos[0] += 50;
        else m_cameraPos[0] -= 50;
        break;
    case 89:    //'y'
        if(shiftPressed) m_cameraPos[1] += 50;
        else m_cameraPos[1] -= 50;
        break;
    //case 86:    //'v'
    //    //ウィンドウ表示切り替え
    //    //非表示にするとキーコールバックが行われなくなるので実質非表示のみ
    //    if (action == GLFW_PRESS)
    //    {
    //        int visible = glfwGetWindowAttrib(glfwWindow, GLFW_VISIBLE);
    //        if (visible)
    //            glfwHideWindow(glfwWindow);
    //        else
    //            glfwShowWindow(glfwWindow);
    //    }
    default: break;
    }
}

//! maouse callback
void WindowBase::mouseCursorPos(double x, double y)
{
    //printf("x:%lf\n", x);
    //printf("y:%lf\n", y);
}

void WindowBase::mouseButton(int button, int action, int mods)
{
    //printf("button:%d\n", button);
    //printf("action:%d\n", action);
    //printf("mods:%d\n", mods);
}

void WindowBase::mouseScroll(double x, double y)
{
    //printf("x:%lf\n", x);
    //printf("y:%lf\n", y);

}

//! resize callback
void WindowBase::resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 1.0, 10.0);
}

//! static keyboard callback
void WindowBase::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->keyboard(key, scancode, action, mods);
}

//! static mouse callback
//座標がずれるたびにコールバック
void WindowBase::cursorPosCallback(GLFWwindow* window, double x, double y)
{
    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->mouseCursorPos(x, y);
}

//マウスのボタンが押される、離れるたびにコールバック
void WindowBase::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->mouseButton(button, action, mods);
}

//ホイールをスクロールするたびにコールバック
void WindowBase::scrollCallback(GLFWwindow* window, double x, double y)
{
    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->mouseScroll(x, y);
}

//! static resize callback
void WindowBase::windowSizeCallback(GLFWwindow* window, int width, int height)
{
    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->resize(width, height);
}
