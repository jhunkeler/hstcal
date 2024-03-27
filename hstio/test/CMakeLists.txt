file (GLOB TEST_DATA
	"*.py"
	"*.fits"
)
file(COPY ${TEST_DATA}
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

project(test_hstio_resize_hdu)
add_executable(${PROJECT_NAME}
	test_hstio_resize_hdu.c
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC cvos
	PUBLIC ${cfitsio_LDFLAGS}
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC hstio
	PUBLIC ${cfitsio_LDFLAGS}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC ${cfitsio_INCLUDE_DIRS}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC ${HSTCAL_include}
)
target_compile_options(${PROJECT_NAME} PUBLIC ${cfitsio_CFLAGS_OTHER})

project(test_hstio_resize_hdu2)
add_executable(${PROJECT_NAME}
	test_hstio_resize_hdu2.c
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC cvos
	PUBLIC ${cfitsio_LDFLAGS}
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC hstio
	PUBLIC ${cfitsio_LDFLAGS}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC ${cfitsio_INCLUDE_DIRS}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC ${HSTCAL_include}
)
target_compile_options(${PROJECT_NAME} PUBLIC ${cfitsio_CFLAGS_OTHER})

