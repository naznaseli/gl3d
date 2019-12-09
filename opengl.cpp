#include "opengl.hpp"

WindowBase::WindowBase() {
    std::cout << "base create" << std::endl;

}

WindowBase::~WindowBase() {
    std::cout << "base delete" << std::endl;
    glfwTerminate();
}

void WindowBase::init(int width, int height, char* windowName) {
    windowWidth = width;
    windowHeight = height;

    //glfw初期化
    //glfwInit();
    if (glfwInit() == GL_FALSE) {
        std::cerr << "error" << std::endl;
        getchar();
        //return 1;
        return;
    }

    //atexit(glfwTerminate);

    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    //glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    //glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
    if (glfwWindow == NULL) {
        std::cerr << "window error" << std::endl;
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
        std::cerr << "error init glew" << std::endl;
        //return 1;
        return;
    }

    glInit();
}

void WindowBase::glInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

bool WindowBase::isExist(void) {
    return !(glfwWindowShouldClose(glfwWindow));
}

//継承するなら内部にglfw関数なくす
void WindowBase::run(void) {
    //画面消去
    glClear(GL_COLOR_BUFFER_BIT);

    //描画処理
    display();

    //バッファ入れ替え
    glfwSwapBuffers(glfwWindow);

    //イベント
    //glfwWaitEvents(); //イベント待ち続ける
    glfwPollEvents();
}

//継承する仮想関数
void WindowBase::display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
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

void WindowBase::keyboard(int key, int scancode, int action, int mods) {
    std::cout << "keyboard Child" << std::endl;
    if(key == 256) glfwDestroyWindow(glfwWindow);   //exit(0);
}

void WindowBase::mouseScroll(double x, double y) {

}

void WindowBase::resize(int widht, int height) {
    std::cout << "resize Child" << std::endl;
}

void WindowBase::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << "skeyboard" << std::endl;

    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->keyboard(key, scancode, action, mods);
}

void WindowBase::mouseScrollCallback(GLFWwindow* window, double x, double y) {

}

void WindowBase::windowSizeCallback(GLFWwindow* window, int width, int height) {
    std::cout << "sresize" << std::endl;

    //ポインタからクラスのインスタンスを取得
    WindowBase* windowBase = static_cast<WindowBase*>(glfwGetWindowUserPointer(window));

    //本物のコールバック関数を呼び出し
    windowBase->resize(width, height);

}

