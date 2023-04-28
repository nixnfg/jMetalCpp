# jMetalCpp project Web site

jMetalCpp is a C++ based framework for multi-objective optimization. It is a
fork of the [jMetal project](https://github.com/jmetal/jmetal).

## TABLE OF CONTENTS

0. Updates
1. Requirements
2. Installing jMetalCpp
3. Executing jMetalCpp
4. Choosing a problem
5. Configuring a problem
6. Calculating quality indicators
7. Advanced: Building a Experiment
   7.1. Executing a experiment
   7.2. Generating reports from a experiment
8. Installation

### 0. Updates

Version 1.11:

- Added support for CMake and successfully build on Windows with
  MSCV 2019. Contributor: Dimitar Stanev (https://github.com/mitkof6)

Version 1.10:

- Added new algorithm: Moth-Flame Optimization Algorithm (MFO). Contributor:
  Ahmad Dajani (https://github.com/adajani)

Version 1.9:

- Added new algorithm: Whale Optimizer Algorithm (WOA). Contributor: Ahmad
  Dajani (https://github.com/adajani)

Version 1.8:

- Added new algorithm: GWO. Contributor: Ahmad Dajani
  (https://github.com/adajani)
- Enhance input parameter with default value.

Version 1.7:

- Added a new algorithm: MOCH
  Expect new algorithms soon

Version 1.6:

- Added new algorithms: OMOPSO, PAES, SMPSOhv, StandardPSO2007 and
  StandardPSO2011
- Added CEC 2005 problems

Version 1.5:

- Added new algorithms: SMS-EMOA, ssNSGA-II, MOEA/D and CMA-ES.
- Added new problems: Srinivas, Tanaka, Rastrigin and Rosenbrock.
- Changed POSIX threads to C++11 built-in threads.

Version 1.0.1:

- Fixed a bug that prevented the last Wilcoxon table being generated
  correctly.
- Changed FIT quality indicator to be minimized instead of being maximized.

Version 1.0:

- Added quality indicators.
- Added experiments.

Version 0.1:

- First version.

### 1. Requirements

jMetalCpp has been developed in Unix machines (Ubuntu and MacOS X) as well as in
Windows making use of Cygwin. The make utility has been used to compile the
software package.

From version 1.5, it is mandatory to use a C++ compilator with C++11
support. This is needed to use the C++11 threads library.

### 2. Installing jMetalCpp

Copy the compressed file to the location where you want to install jMetal and
unzip it.

Then, compile the code with the following command:

```
% make
```

One can also use the CMake building system to compile the project independently
of the OS. Example for building on Linux can be found below:

```
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install
make
```

### 3. Executing jMetal

All the main binaries are in the subfolder `main` included in the `bin`
folder. Enter this folder to execute jMetal.

```
% cd bin
% cd main
```

The following multi-objective metaheuristics are provided in this version of
jMetal:

```text
  Algorithm                                   Command
  ---------------------------------------------------------
  NSGA-II                                     NSGAII_main
  ssNSGA-II                                   ssNSGAII_main
  GDE3                                        GDE3_main
  SMPSO                                       SMPSO_main
  SMPSOhv (NEW)                               SMPSOhv_main
  OMOPSO (NEW)                                OMOPSO_main
  PAES (NEW)                                  PAES_main
  SMS-EMOA                                    SMSEMOA_main
  MOEA/D                                      MOEAD_main
```

Additionally, we include single-objective variants of these techniques:

```text
  Algorithm                                   Command
  ---------------------------------------------------------
  DE (Differential Evolution)                 DE_main
  gGA (Generational Genetic Algorithm)        gGA_main
  PSO (Particle Swarm Optimization)           PSO_main
  PSO (Standard 2007) (NEW)                   StandardPSO2007_main
  PSO (Standard 2011) (NEW)                   StandardPSO2011_main
  ssGA (Steady-state Genetic Algorithm)       ssGA_main
  CMA-ES                                      CMAES_main
  GWO (Grey Wolf Optimizer)                   GWO_main
  WOA (Whale Optimizer Algorithm)             WOA_main
  MFO (Moth-Flame Optimization Algorithm)     MFO_main
```

To execute one metaheuristic just use its associated command. For example, to
execute GDE3 simply type the following command:

```
% ./GDE3_main
```

### 4. Choosing a problem

If you execute an algorithm like before, a default problem will be used for each
algorithm. You can specify what problem to solve by passing it as a
parameter. For example, if you desire to execute the Generational Genetic
Algorithm to solve the Sphere problem, you need to execute the following
command:

```
% ./gGA_main Sphere
```

The following multi-objective problems are currently included:

- Fonseca
- Kursawe
- OneMax
- Schaffer
- Sphere
- Srinivas
- Tanaka
- DTLZ1
- DTLZ2
- DTLZ3
- DTLZ4
- DTLZ5
- DTLZ6
- DTLZ7
- ZDT1
- ZDT2
- ZDT3
- ZDT4
- ZDT5
- ZDT6
- LZ09_F1
- LZ09_F2
- LZ09_F3
- LZ09_F4
- LZ09_F5
- LZ09_F6
- LZ09_F7
- LZ09_F8
- LZ09_F9

The list of single-objective problems currently is composed of:

- Griewank
- OneMax
- Rastrigin
- Rosenbrock
- Sphere
- CEC2005

### 5. Configuring a problem

When you select a problem to solve, you can configure some problem parameters
passing them as parameters. If a problem has three parameters, you can choose to
specify one, two or the three of them.

The following parameters can be configured when going to solve a problem:

```text
 Problem        Parameter 1         Parameter 2             Parameter 3
--------------------------------------------------------------------------------------
 Fonseca        Solution type
 Griewank       Solution type       Number of variables
 Kursawe        Solution type       Number of variables
 OneMax         Number of bits      Number of strings
 Rastrigin      Solution type       Number of variables
 Rosenbrock     Solution type       Number of variables
 Shaffer        Solution type
 Sphere         Solution type       Number of variables
 Srinivas       Solution type
 Tanaka         Solution type
 DTLZ1          Solution type       Number of variables     Number of objectives
 DTLZ2          Solution type       Number of variables     Number of objectives
 DTLZ3          Solution type       Number of variables     Number of objectives
 DTLZ4          Solution type       Number of variables     Number of objectives
 DTLZ5          Solution type       Number of variables     Number of objectives
 DTLZ6          Solution type       Number of variables     Number of objectives
 DTLZ7          Solution type       Number of variables     Number of objectives
 LZ09_F1        Solution type
 LZ09_F2        Solution type
 LZ09_F3        Solution type
 LZ09_F4        Solution type
 LZ09_F5        Solution type
 LZ09_F6        Solution type
 LZ09_F7        Solution type
 LZ09_F8        Solution type
 LZ09_F9        Solution type
 ZDT1           Solution type       Number of variables
 ZDT2           Solution type       Number of variables
 ZDT3           Solution type       Number of variables
 ZDT4           Solution type       Number of variables
 ZDT5           Solution type       Number of variables
 ZDT6           Solution type       Number of variables
```

The following values are allowed for the 'Solution type' parameter:
	- Real
	- Binary

For example, if you want to solve the DTLZ5 problem using SMPSO using 'Real" as
solution type, you would need to execute the following command:

```
% ./SMPSO_main DTLZ5 Real
```

In the future, a binary-real encoding will be available.

If you intend to modify the default parameters of the DTLZ5 problem with ten variables
and two objectives, the following command must be executed:

```
%./SMPSO_main DTLZ5 Real 10 2
```

The CEC 2005 problems are an exception, as the order of the parameters change if you
are setting one, two or the three of them.

```text
 Problem        Parameter 1         Parameter 2             Parameter 3
--------------------------------------------------------------------------------------
 CEC2005        Problem number
 CEC2005        Solution type       Problem number
 CEC2005        Solution type       Problem number          Number of variables
```

 The `<problem number>` variable accepts values from 1 to 25. The default values for
 `Solution type` and `Number of variables` are `Real` and 10.
 Examples:

```
% ./gGA_main CEC2005 1
% ./gGA_main CEC2005 Real 1
% ./gGA_main CEC2005 Real 1 20
```

### 6. Calculating quality indicators

To assess the performance of multi-objective metaheuristics, quality indicators
are needed to evaluate the quality of the obtained Pareto front approximations.

The following quality indicators are provided in this version of jMetal:

```text
  Quality Indicator                     Command
  ---------------------------------------------------------------------
  Hypervolume                           Hypervolume
  Spread                                Spread
  Epsilon                               Epsilon
  Generational Distance                 GenerationalDistance
  Inverted Generational Distance        InvertedGenerationalDistance
```

This quality indicators require to know the true Pareto front of the
problems. In the case of the included benchmark problems, their Pareto fronts
can be downloaded from http://jmetal.sourceforge.net/problems.html

The quality indicator binaries are included in `bin/qualityIndicator/main`.
Enter this folder to execute any indicator.

```
% cd bin
% cd qualityIndicator
% cd main
```

To calculate a quality indicator you have to execute the following command:

```
% ./<QualityIndicatorCommand> <SolutionFrontFile> <TrueFrontFile> <numberOfObjectives>
```

For example, if you need to calculate the hypervolume indicator on the `FUN file
obtained by a metaheuristic when trying to solve the ZDT1 problem, you have to
execute the following command:

```
% ./Hypervolume /home/username/jmetalcpp-test/FUN/home/username/jmetalcpp-test/ZDT1.pf 2
```

Remember to change the file paths to whatever the actual location of the files
containing the Pareto fronts is.

### 7. Advanced: Building a Experiment

Since this version of jMetalCpp, it is possible to create experimental
studies. An experiment consists of a list of algorithms which are used to solve
a list of problems, performing a number of independent runs. The results are
then evaluated by applying quality indicators and, as an output, a set of Latex
files and R scripts are produced.  These files include Latex tables with
means/medians and standard deviations/IQRs, Latex tables including the results
of applying the Wilcoxon rank-sum tests, and eps figures containing boxplots.

Experiments are divided in two independent parts: an execution part and a report
part.  This approach is different from the one used in the Java version of
jMetal. The current one included in jMetalCpp is more flexible and includes a
more efficient parallel scheme to run the experiments in parallel.

The execution part is the one which executes all the problems using the selected
algorithms. Each problem will be executed a specified number of times. As the
number of configuration can be high and they are independent among then, the
algorithms can be executed concurrently by a specified number of threads in
order to take advantage of current multi-core processors.

The report part allows to apply quality indicators to measure the quality of the
result data, and calculates statistical information yielding the Latex tables
and figures commented previously.

#### 7.1. Executing a experiment

To execute the 'execution part' of a experiment, you only need to execute the
corresponding command. This version of jMetalCpp provides two already
implemented experiments to be used as templates. Feel free to edit these
experiments or create new ones. Remember that after editing the code, you will
have to compile the code again.

The two provided experiments are:

- `StandardStudyExecution`
- `StandardStudyExecutionSO`

The first one is a multi-objective experiment. The second one is a
single-objective one. In order to execute a experiment, you only have to enter
its corresponding command. For example:

```
% ./StandardStudyExecution
```

Before executing the experiments, it is important to change some parameters in
the code accordingly to your needs and to your system configuration. Thus, you
need to indicate the current paths where to store the output files and from
where to read the input files. You will have to edit the corresponding .cpp
files located in the 'jmetalcpp/src/experiments/' folder.

In each .cpp file, you can specify the following parameters:

- `experimentName`:
  Self-explanatory. It will be used to create a folder when to store the
  results.
- `algorithmNameList`:
  List of algorithms to be executed for each problem in the experiment.
- `problemList`:
  List of problems that will be resolved in the experiment.
- `independentRuns`:
  Number of times that each problem will be executed for each algorithm.
- `numberOfThreads`:
  Number of threads that will be used to execute the algorithms concurrently.
- `experimentBaseDirectory`:
  Directory path where all the experiments result will be	stored. Inside this
  folder, the following structure will be created:

```text

    - <experimentalBaseDirectory/experimentName>
        |-data
          |- <algorithm_1>
          |	|- <problem_1>
          |	|	Result files from problem 1 using algorithm 1.
          |	|	(FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
          |	|- <problem_2>
          |	|	Result files from problem 2 using algorithm 1.
          |	|	(FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
          |	|- ...
          |	|- <problem_n>
          |   Result files from problem n using algorithm 1.
					|   (FUN.1, FUN.2, ..., FUN.X, VAR.1, VAR.2, ..., VAR.X)
          |
          |- <algorithm_2>
          |	|- <problem_1>
          |	|	Result files from problem 1 using algorithm 2.
          |	|- <problem_2>
          |	|	Result files from problem 2 using algorithm 2.
          |	|- ...
          |	|- <problem_n>
          |		Result files from problem n using algorithm 2.
          |
          |- ...
          |
          |- <algorithm_m>
            |- <problem_1>
            |	Result files from problem 1 using algorithm m.
            |- <problem_2>
            |	Result files from problem 2 using algorithm m.
            |- ...
            |- <problem_n>
              Result files from problem n using algorithm m.
					
```

Each algorithm used in the execution must be properly configured. This is done
in the algorithmSettings method in each .cpp file. For each algorithm (NSGAII,
GDE3, gGA...), this version of jMetalCpp provides a Settings class with a
default configuration. You can edit these Setting classes to change the
algorithm parameters. Don't forget to edit the algorithmSettings to configure
each algorithm used in the experiment. It's possible to execute the same
algorithm more than once in a experiment with different configurations, but you
will have to implement a different Settings class for each variant of the
algorithm.

#### 7.2. Generating reports from a experiment

To execute the `report part` of a experiment, you only need to execute the
corresponding command. For this part, this version of jMetalCpp provides three
already implemented experiments. The first two ones generate reports for the
multi-objective experiment and the third one generate reports for the
single-objective variant. As before, they are templates, so feel free to edit
them according to your needs or to create new ones from them. Remember that
after editing the code, you will have to compile the code again.

The three provided experiments are:

- `StandardStudyReportPF`
- `StandardStudyReportRF`
- `StandardStudyReportSO

The experiments in the Java version of jMetal assume that you known in advance
the true Pareto front of the solved problems, and this assumption is considered
in the `StandardStudyReportPF` (PF stands for "Pareto Front"). However, if the
Pareto fronts are unknown, as usually happens when solving real problem, the
approach then is to obtain a reference Pareto front from all the front of
solutions produced by all the algorithms in every independent run. The
`StandardStudyReportRF` (RF stands for "Reference Front") is designed to get
this reference fronts, which are then used to apply the desired quality
indicators.

`StandardStudyReportSO` generates the reports for a single-objective experiment.

In order to execute an experiment report, you only need to enter its
corresponding command. For example:

```
% ./StandardStudyReportPF
```

As before, the experiment report programs must be properly configured before
running them. It is very important that the list of parameters enumerated in the
following do match with the ones included in the execution part which was
previously run:

- experimentName:
  Self-explanatory. It will be used to know the folder from where to read the
  execution results.
- algorithmNameList:
  List of algorithms which were executed for each problem in the experiment
  execution part.
- problemList:
  List of problems which were resolved in the experiment execution part.
- independentRuns:
  Number of times that each problem were executed for each algorithm in the
  execution part.
- experimentBaseDirectory:
  Directory path where all the experiments result were stored.
- indicatorList:
  List of quality indicators that will be calculated in the reports. When doing
  a experiment about single-objective algorithms, the only possible value is
  `FIT`.
- paretoFrontFile:
  List of optimal pareto front files that will be used to calculate the
  quality indicators. Only necessary if the optimal pareto fronts are known and
  if the experiment is about multi-objective algorithms.
- paretoFrontDirectory:
  Directory path when the optimal pareto fronts are stored. Only necessary when
  going to use known optimal pareto fronts. If it is a single-objective
  experiment, this parameter is not used. If it is a multi-objective experiment
  and this parameter is not especified, reference pareto fronts will be
  generated to calculate the quality indicators.

In case of executing the StandardStudyReportRF program, a directory
<experimentalBaseDirectory/experimentName/referenceFronts> will contain the
obtained reference fronts of the solved problems.

### 8. Installation

- For installation: make install
- For uninstallation : make uninstall
- To install in not usr/local/, set a path to PREFIX. For example export
  PREFIX=a/b/c
