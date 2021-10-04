set(Window_LIBRARY "Window")
set(Window_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/BaseWindow.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SimpleData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp
)
set(Window_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/BaseWindow.h
	${CMAKE_CURRENT_SOURCE_DIR}/Shader.h
	${CMAKE_CURRENT_SOURCE_DIR}/SimpleData.h
	${CMAKE_CURRENT_SOURCE_DIR}/Utils.h
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	../glad/include
	../glfw-master/include
	../Res
)

add_library(${Window_LIBRARY} STATIC ${Window_SOURCE_FILES} ${Window_HEADER_FILES})
set_target_properties(${Window_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Window_LIBRARY} glfw Glad Res)
SET_TARGET_PROPERTIES(Window PROPERTIES FOLDER "QKEngineCore")