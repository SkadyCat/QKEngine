set(Model_LIBRARY "Model")
set(Model_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Model.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/TextureData.cpp

)
set(Model_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/Model.h
	${CMAKE_CURRENT_SOURCE_DIR}/TextureData.h
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	../glad/include
	../glfw-master/include
	../Base
	../glm
)

add_library(${Model_LIBRARY} STATIC ${Model_SOURCE_FILES} ${Model_HEADER_FILES})
set_target_properties(${Model_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Model_LIBRARY} glfw Glad Base glm)
SET_TARGET_PROPERTIES(Model PROPERTIES FOLDER "QKEngineCore")