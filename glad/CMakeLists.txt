set(Glad_LIBRARY "Glad")
set(Glad_SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
)
set(Glad_HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
include_directories( 
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(${Glad_LIBRARY} STATIC ${Glad_SOURCE_FILES} ${Glad_HEADER_FILES})
set_target_properties(${Glad_LIBRARY} PROPERTIES PREFIX "")
target_link_libraries(${Glad_LIBRARY})
SET_TARGET_PROPERTIES(Glad PROPERTIES FOLDER "Glad")