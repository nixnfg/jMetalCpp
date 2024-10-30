#project('my_project', 'cpp',
#    version : '0.1',
#    default_options : ['warning_level=3',
#                      'cpp_std=c++17'])
#exe = executable('jmetal_cpp',
#    'main.cpp')

main_src = files('main.cpp')
main = executable('jmetal_cpp', main_src,
          include_directories: nsgaii_inc,
          link_with: nsgaii_lib,
          install:true)

#subdir('metaheuristics/singleObjective/cmaes')
#cmaes_lib=static_library(
#    'cmaes_lib',
#    meta_so_cmaes_src,
#    include_directories:[common_inc,meta_so_cmaes_inc],
#    link_with: common_lib
#)
#
#CMAES_main_src = files('main/CMAES_main.cpp')
#CMAES_main = executable('CMAES_main', CMAES_main_src,
#           include_directories: [common_inc,meta_so_cmaes_inc],
#           link_with: cmaes_lib)

# CMAES_main_src = files('main' / 'CMAES_main.cpp')
# CMAES_main = executable('CMAES_main', CMAES_main_src,
#            include_directories: inc_dirs,
#            dependencies: [phys_dep, math_dep],
#            install:true)

# operators
# operator_lib = library(
#     'operator_lib',
#     core_src,
#     include_directories: core_inc)

# exe = executable('main', 'main.c', link_with : lib)
# t = executable(
#   'main',
#   ['main.c', 'rone.c'],
#   include_directories : inc,
#   implicit_include_directories : false,
# )

# experiments
#subdir('experiments')

# main
# CMAES_main_src = files('main' / 'CMAES_main.cpp')
# CMAES_main = executable('CMAES_main', CMAES_main_src,
#            include_directories: inc_dirs,
#            dependencies: [phys_dep, math_dep],
#            install:true)