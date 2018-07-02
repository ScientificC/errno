INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(include)

SET(CML_MAIN_HEADERS
		include/scic/errno.h
)

add_subdirectory(src)

INSTALL(FILES ${CML_MAIN_HEADERS} DESTINATION include/scic)
INSTALL(DIRECTORY include/scic/errno DESTINATION include/scic)
