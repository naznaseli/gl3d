#include "example-robot.hpp"

Window::Window()
{
    init(1920, 1080, (char*)"example-robot");
}

Window::~Window()
{
    glfwTerminate();
}

void Window::display(void)
{
    resize(m_windowWidth, m_windowHeight);

    //glBegin(GL_POLYGON);
    //glColor3d(1.0, 0.0, 0.0);
    //glVertex2d(-0.9, -0.9);
    //glColor3d(0.0, 1.0, 0.0);
    //glVertex2d(0.9, -0.9);
    //glColor3d(0.0, 0.0, 1.0);
    //glColor3d(0.0, 0.0, 1.0);
    //glVertex2d(0.9, 0.9);
    //glColor3d(1.0, 1.0, 0.0);
    //glVertex2d(-0.9, 0.9);
    //glEnd();

    glBegin(GL_POLYGON);
    glVertex3d(100, 100, 100);
    glVertex3d(-100, 100, 100);
    glVertex3d(-100, 100, -100);
    glVertex3d(100, 100, -100);

    glEnd();

    glFlush();
}

void Window::keyboard(int key, int scancode, int action, int mods)
{

    //printf("keyboard callback\n");
    //printf("key:%d\n", key);
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
    //case 88:    //'x'
    //    printf("x pressed.\n");
    //    if(shiftPressed) m_cameraParam.posWidth += 50;
    //    else m_cameraParam.posWidth -= 50;
    //    break;
    //case 89:    //'y'
    //    printf("y pressed.\n");
    //    if(shiftPressed) m_cameraParam.posDepth += 50;
    //    else m_cameraParam.posDepth -= 50;
    //    break;
    //case 90:    //'z'
    //    printf("z pressed.\n");
    //    if(shiftPressed) m_cameraParam.posHeight += 50;
    //    else m_cameraParam.posHeight -= 50;
    //    break;
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
    gluPerspective(30.0, 1.0, 1.0, 30000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //カメラ座標、カメラ角度
    //double cameraPos[3] = {m_wheelPosFR[0] - m_cameraParam.posWidth, m_wheelPosFR[1] - m_cameraParam.posDepth, m_cameraParam.posHeight};
    double cameraPos[3] = {0, -10000, 0};
}
