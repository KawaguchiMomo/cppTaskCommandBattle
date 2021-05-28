# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(cppTaskCommandBattle CXX)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall")
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
# a.outという実行ファイルをmain.cppから作成
add_executable(a.out main.cpp character.cpp player.cpp playerList.cpp enemy.cpp enemyList.cpp gameManager.cpp skillList.cpp skill.cpp skillSetting.cpp battleField.cpp csvLoader.cpp)