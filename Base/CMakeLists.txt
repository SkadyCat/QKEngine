set(Base_LIBRARY "Base")
set(Base_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Shader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SimpleData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Utils.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Texture.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Element.cpp
)
set(Base_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Shader.h
	${CMAKE_CURRENT_SOURCE_DIR}/SimpleData.h
	${CMAKE_CURRENT_SOURCE_DIR}/Utils.h
	${CMAKE_CURRENT_SOURCE_DIR}/Texture.h
	${CMAKE_CURRENT_SOURCE_DIR}/stb_image.h
	${CMAKE_CURRENT_SOURCE_DIR}/Element.h
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	../glad/include
	../glfw-master/include
)

add_library(${Base_LIBRARY} STATIC ${Base_SOURCE_FILES} ${Base_HEADER_FILES})
set_target_properties(${Base_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Base_LIBRARY} glfw Glad Model)
SET_TARGET_PROPERTIES(Base PROPERTIES FOLDER "QKEngineCore")