﻿set(Window_LIBRARY "Window")
set(Window_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/BaseWindow.cpp
)
set(Window_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/BaseWindow.h
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	../glad/include
	../glfw-master/include
	../Model
	../Base
)

add_library(${Window_LIBRARY} STATIC ${Window_SOURCE_FILES} ${Window_HEADER_FILES})
set_target_properties(${Window_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Window_LIBRARY} glfw Glad Model Base)
SET_TARGET_PROPERTIES(Window PROPERTIES FOLDER "QKEngineCore")