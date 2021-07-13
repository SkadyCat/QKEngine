# CMakeList.txt: QKEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)


include_directories( 
	../glad/include
	../glfw-master/include
	../Window
	../Res
)



# 将源代码添加到此项目的可执行文件。
add_executable (QKEngine "QKEngine.cpp" "QKEngine.h")
target_link_libraries (QKEngine glfw Glad Window Res)
# TODO: 如有需要，请添加测试并安装目标。
