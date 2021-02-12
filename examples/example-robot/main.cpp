#include <stdio.h>
#include "example-robot.hpp"

int main(int argc, char** argv)
{
    printf("example-robot\n");

    Window window;

    while(1)
    {
        window.run();
    }

    return 0;
}