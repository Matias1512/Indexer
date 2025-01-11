cmake_minimum_required(VERSION 3.16)

project(indexer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core LinguistTools)
find_package(Qt6 REQUIRED COMPONENTS Core Sql)

set(TS_FILES indexer_fr_FR.ts)

add_executable(indexer
  main.cpp
  ${TS_FILES}
  searchcommand.h searchcommand.cpp
  tokenizer.h tokenizer.cpp
  token.h token.cpp
  Command.h
  factory.h
  indexercommand.h indexercommand.cpp
  getcommand.h getcommand.cpp
  addcommand.h addcommand.cpp
  pushcommand.h pushcommand.cpp
  clearcommand.h clearcommand.cpp
  fsm.h fsm.cpp
  state.h state.cpp
  transition.h transition.cpp
  option.h
  lastmodified.h lastmodified.cpp
  factory.cpp
  created.h created.cpp
  optionUtil.h optionUtil.cpp
  maxsize.h maxsize.cpp
  minsize.h minsize.cpp

)
target_link_libraries(indexer Qt${QT_VERSION_MAJOR}::Core Qt6::Core Qt6::Sql)


if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

include(GNUInstallDirs)
install(TARGETS indexer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
