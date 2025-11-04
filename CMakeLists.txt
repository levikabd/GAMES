cmake_minimum_required(VERSION 3.10.0)
project(GAMES VERSION 0.1.0 LANGUAGES C CXX)


add_executable(GAMES main.cpp welcome.cpp gwindow.cpp buildg.cpp)

set(CURSES_HAVE_NCURSES_H TRUE)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)
set(CMAKE_CXX_FLAGS "-lncurses")

