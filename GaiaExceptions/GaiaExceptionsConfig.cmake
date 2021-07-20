cmake_minimum_required(3.10)

find_path(GaiaExceptions_INCLUDE_DIRS "GaiaExceptions")
find_library(GaiaExceptions_LIBS "GaiaExceptions")

if (GaiaExceptions_INCLUDE_DIRS AND GaiaExceptions_LIBS)
    set(GaiaExceptions_FOUND TRUE)
endif()