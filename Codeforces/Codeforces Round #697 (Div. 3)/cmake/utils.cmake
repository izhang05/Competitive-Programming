macro(add_subprojects _base_dir)
    # Find all CMakeLists.txt paths
    file(GLOB_RECURSE _cmake_files RELATIVE "${_base_dir}" CMakeLists.txt)
    # Collect all subdirectories containing CMakeLists.txt
    set(_dirs)
    foreach (file_path ${_cmake_files})
        get_filename_component(_dir_path ${file_path} PATH)
        list(APPEND _dirs ${_dir_path})
    endforeach ()

    unset(_cmake_files)
    unset(_dir_path)

    # Add all found directories
    foreach (dir ${_dirs})
        add_subdirectory(${dir})
    endforeach ()
endmacro()