#include "opengl.hpp"
#include <stdio.h>

WindowBase::WindowBase()
{
    //std::cout << "base create" << std::endl;
    printf("WindowBase created\n");

}

WindowBase::~WindowBase()
{
    //std::cout << "base delete" << std::endl;
    printf("WindowBase deleted\n");
    glfwTerminate();
}

void WindowBase::init(int width, int height, char* windowName)
{
    windowWidth = width;
    windowHeight = height;

    //GLFW初期化
    if (glfwInit() == GL_FALSE) {
        //初期化失敗
        //std::cerr << "error" << std::endl;
        printf("GLFW initialize error\n");
        getchar();
        //return 1;
        return;
    }

    //GLFWバージョン3.2
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
    if (glfwWindow == NULL) {
        //std::cerr << "window error" << std::endl;
        printf("GLFW create window error\n");
        //return 1;
        return;
    }

    //静的メンバ関数をコールバックに登録
    glfwSetWindowUserPointer(glfwWindow, this);
    glfwSetKeyCallback(glfwWindow, keyCallback);
    glfwSetWindowSizeCallback(glfwWindow, windowSizeCallback);

    //ウィンドウを処理対象にする
    glfwMakeContextCurrent(glfwWindow);
    glfwSwapInterval(1);

    //GLEWの初期化
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        //初期化失敗
        //std::cerr << "error init glew" << std::endl;
        printf("GLEW initialize error\n");
        //return 1;
        return;
    }

    glInit();
}

void WindowBase::glInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

bool WindowBase::isExist(void)
{
    return !(glfwWindowShouldClose(glfwWindow));
}

//継承するなら内部にglfw関数なくす
void WindowBase::run(void)
{
    //画面消去
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //描画処理
    display();

    //バッファ入れ替え
    glfwSwapBuffers(glfwWindow);

    //イベント
    //glfwWaitEvents(); //イベント待ち続ける
    glfwPollEvents();
}

//継承する仮想関数
void WindowBase::display(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
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

void WindowBase::keyboard(int key, int scancode, int action, int mods)
{
    printf("keyboard Child\n");
    if(key == 256) glfwSetWindowShouldClose(glfwWindow, GLFW_TRUE);
}

void WindowBase::mouseScroll(double x, double y)
{

}

void WindowBase::resize(int width, int height)
{
    printf("resize Child\n");
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 1.0, 10.0);
}

void WindowBase::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    printf("skeyboard\n");

    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->keyboard(key, scancode, action, mods);
}

void WindowBase::mouseScrollCallback(GLFWwindow* window, double x, double y)
{

}

void WindowBase::windowSizeCallback(GLFWwindow* window, int width, int height)
{
    printf("sresize\n");

    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->resize(width, height);

}

