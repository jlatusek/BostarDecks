set(LIB_NAME ${PROJECT_NAME}lib)

add_library(${LIB_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/db/database_builder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/db/models.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/db/models/deck.cpp
        )

target_include_directories(${LIB_NAME} PUBLIC
        )

conan_target_link_libraries(${LIB_NAME}
        CONAN_PKG::boost
        CONAN_PKG::poco
        )

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        )

target_link_libraries(
        ${PROJECT_NAME} ${LIB_NAME}
        )
