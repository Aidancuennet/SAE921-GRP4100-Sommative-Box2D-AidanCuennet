# CMakeList.txt : fichier projet CMake de niveau supérieur, effectuez une configuration globale
# et incluez les sous-projets ici.
#
cmake_minimum_required (VERSION 3.8)

# Solution
project ("SAE921-GRP4100-Sommative-Box2D-AidanCuennet")
message("SOLUTION/PROJECT CMAKING " ${CMAKE_PROJECT_NAME})

# Each sub-project
set(EXECUTABLE_CUSTOM_NAME "sommative-Box2D")
add_subdirectory ("sommative-Box2D")

