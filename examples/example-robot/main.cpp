#include "example-robot.hpp"

int main(int argc, char** argv)
{
    Window window;

    //ウィンドウサイズ、名前指定
    window.init(1920, 1080, (char*)"example-robot");

    while(window.isExist())
    {
        //描画
        window.run();
    }

    return 0;
}