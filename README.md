OpenGL_Library

====

OpenGL class library using GLFW and GLEW.

# Description
OpenGL（GLFW、GLEW）を用いた描画ライブラリ。

GLFWを用いることで、OpenGL専用のループに入らず、描画以外の処理をメインルーチンで行える。

# Requirement
* glfw3 3.3.0
* glew 7.0

# Usage
WindowBaseクラスを継承して使う
必要に応じて関数をオーバライドする(init、display、keyboard)
詳細はexamplesプログラムを参照
