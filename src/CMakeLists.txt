set(LIB_NAME ${PROJECT_NAME}_lib)

set(HEADERS
        inc/Database.h
        inc/logger.h
        )

set(SOURCES
        Database.cpp
        Model.cpp
        )

add_library(${LIB_NAME} STATIC
        ${SOURCES}
        ${HEADERS}
        )

target_include_directories(${LIB_NAME} PUBLIC inc)
conan_target_link_libraries(${LIB_NAME}
        CONAN_PKG::boost
        )
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(
        ${PROJECT_NAME} ${LIB_NAME}
)
