# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(cppTaskCommandBattle CXX)
# a.outという実行ファイルをmain.cppから作成
add_executable(a.out main.cpp character.cpp player.cpp enemy.cpp gameManager.cpp skill.cpp)