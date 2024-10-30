#util
subdir('util')
#encodings
subdir('encodings')
#core
subdir('core')
#operators
subdir('operators')
#metaheuristics
subdir('metaheuristics')

# public lib
common_src=[core_src,encodings_src,util_src]
common_inc=[core_inc,encodings_inc,util_inc]
common_lib=static_library(
    'common_lib',
    common_src,
    include_directories:common_inc
)

# cmaes
# cmaes_inc=[common_inc,meta_so_cmaes_inc]
# cmaes_lib=static_library(
#     'cmaes_lib',
#     [meta_so_cmaes_src],
#     include_directories:[cmaes_inc],
#     link_with: common_lib
# )

# nsgaii
nsgaii_inc=[common_inc,operators_inc,meta_nsgaii_inc]
nsgaii_lib=static_library(
    'nsgaii_lib',
    [meta_nsgaii_src,operators_src],
    include_directories:[nsgaii_inc],
    link_with: common_lib
)