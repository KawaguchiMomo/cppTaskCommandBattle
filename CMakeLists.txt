# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(cppTaskCommandBattle CXX)
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
# a.outという実行ファイルをmain.cppから作成
add_executable(a.out main.cpp character.cpp player.cpp player_list.cpp enemy.cpp enemy_list.cpp game_manager.cpp skill_list.cpp skill.cpp skill_setting.cpp battle_field.cpp csv_loader.cpp)