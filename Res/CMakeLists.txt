set(Res_LIBRARY "Res")
set(Res_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Res.cpp
	
)
set(Res_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Res.h
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	../glad/include
	../glfw-master/include
)

add_library(${Res_LIBRARY} STATIC ${Res_SOURCE_FILES} ${Res_HEADER_FILES})
set_target_properties(${Res_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Res_LIBRARY} glfw Glad)
SET_TARGET_PROPERTIES(Res PROPERTIES FOLDER "QKEngineCore")