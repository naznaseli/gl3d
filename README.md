# OpenGL_Library

OpenGL class library using GLFW and GLEW.

## Description
GLFW、GLEWを用いた描画ライブラリ。

GLFWを用いることで
* OpenGL専用のループに入らず、描画以外の処理をメインルーチンで行える。
* 
* 

## Requirement
* GLFW needs
    * X11 or WayLand
    * GLU

* X11 or WayLand (Linux) window creation
for GLFW build
if using X11
    sudo apt install xorg-dev
* OpenGL
    Windows glu32.lib
    Linux   glu.h
        in Ubuntu
            sudo apt-get install libglu1-mesa libglu1-mesa-dev

* glfw3 3.0.0
* glew 2.1.0

GLFW3、GLEWはパスにない場合自動でダウンロードとコンパイル

## Usage
WindowBaseクラスを継承して使う
必要に応じて関数をオーバライドする(init、display、keyboard)
詳細はexamplesプログラムを参照

