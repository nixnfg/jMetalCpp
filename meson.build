project('Fortran calling c and cpp', 'fortran', 'c', 'cpp',
  meson_version: '>= 0.51.0',
  default_options : ['default_library=static'])

subdir('src')
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
# ccid = meson.get_compiler('c').get_id()
# if ccid == 'msvc' or ccid == 'clang-cl'
#   error('MESON_SKIP_TEST: MSVC and GCC do not interoperate like this.')
# endif

# c_lib = library('clib', 'clib.c', vs_module_defs : 'clib.def')

# f_call_c = executable('f_call_c', 'f_call_c.f90',
#   link_with: c_lib,
#   link_language: 'fortran')
# test('Fortran calling C', f_call_c)
#!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# src_lib = files(
#     'src'/'csqlite3.c',
#     'src'/'sqlite3.c',
#     'src'/'Vegetables_m.f90',
#     'src'/'ISO_VARYING_STRING.f90',
#     'src'/'strff.f90',
#     'src'/'sqliteff_test.f90',
#     'src'/'sqliteff.f90',
# )
# include_dirs = include_directories('include')

# c_lib = static_library(
#   'clib',
#   src_lib,
#   include_directories: include_dirs)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
# fsql = executable('fsql', 'src/main.f90',
#   link_with: c_lib,
#   link_language: 'fortran')
# test('Fortran calling C', fsql)
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

# exe =  executable('eftest', 'eftest.cpp', link_with : c_lib)
# test('eftest', exe)

# exe =  executable('eftest', 'eftest.cpp', link_with : c_lib)
# test('eftest', exe)
