//#include "opengl.hpp"
#include "gl3d.hpp"

class Window : public WindowBase
{
public:

private:

};

int main(int argc, char** argv)
{
    Window window;
    window.glInit();

    while(window.isExist())
    {
        //描画
        window.run();
    }

    return 0;
}
