# crossover
crossover_inc=include_directories('crossover')
crossover_src=files(
    'crossover' / 'Crossover.cpp',
    'crossover' / 'DifferentialEvolutionCrossover.cpp',
    'crossover' / 'HUXCrossover.cpp',
    'crossover' / 'OXCrossover.cpp',
    'crossover' / 'PositionBasedCrossover.cpp',
    'crossover' / 'SBXCrossover.cpp',
    'crossover' / 'SinglePointCrossover.cpp',
)
crossover_lib = library(
    'crossover_lib',
    crossover_src,
    include_directories: crossover_inc)

# mutation
mutation_inc=include_directories('mutation')
mutation_src=files(
    'mutation' / 'BitFlipMutation.cpp',
    'mutation' / 'InsertionMutation.cpp',
    'mutation' / 'InversionMutation.cpp',
    'mutation' / 'Mutation.cpp',
    'mutation' / 'NonUniformMutation.cpp',
    'mutation' / 'PolynomialMutation.cpp',
    'mutation' / 'UniformMutation.cpp',
)
crossover_lib = library(
    'crossover_lib',
    crossover_src,
    include_directories: crossover_inc)

# selection
selection_inc=include_directories('selection')
selection_src=files(
    'selection' / 'BestSolutionSelection.cpp',
    'selection' / 'BinaryTournament.cpp',
    'selection' / 'BinaryTournament2.cpp',
    'selection' / 'DifferentialEvolutionSelection.cpp',
    'selection' / 'RandomSelection.cpp',
    'selection' / 'Selection.cpp',
    'selection' / 'WorstSolutionSelection.cpp',
)
selection_lib = library(
    'selection_lib',
    selection_src,
    include_directories: selection_inc)