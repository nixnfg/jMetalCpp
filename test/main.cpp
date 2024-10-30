#include <math.h>
#include <Problem.h>
#include <Solution.h>
#include <SBXCrossover.h>
#include <PolynomialMutation.h>
#include <BinaryTournament2.h>
#include <iostream>
#include <NSGAII.h>
#include <string.h>
#include <time.h>
//#include "wrs_sub.h"

//#include <iostream>
//#include <vector>
//int main() {
//    std::vector<int> numbers = {1, 2, 3, 4, 5};
//    int sum = 0;
//    
//    for(const auto& num : numbers) {
//        sum += num;  // 设置断点测试
//    }
//    
//    std::cout << "Sum: " << sum << std::endl;
//    return 0;
//}

class MyProblem : public Problem {
public:
    MyProblem() {
        numberOfVariables_   = 10;
        numberOfObjectives_  = 2;
        numberOfConstraints_ = 2;
        problemName_         = "MyProblem";

        lowerLimit_ = new double[numberOfVariables_];
        upperLimit_ = new double[numberOfVariables_];

        for (int i = 0; i < numberOfVariables_; i++) {
            lowerLimit_[i] = 0.0;
            upperLimit_[i] = 1.0;
        }
        solutionType_ = new RealSolutionType(this);
    }
    ~MyProblem()
    {
        delete [] lowerLimit_;
        delete [] upperLimit_;
    }
    void evaluate(Solution *solution) {
        double *x = new double[numberOfVariables_];
        for (int i = 0; i < numberOfVariables_; i++)
            x[i] = solution->getDecisionVariables()[i]->getValue();

        double f1 = 0.0;
        for (int i = 0; i < numberOfVariables_; i++)
            f1 += x[i] * x[i];

        double f2 = 0.0;
        for (int i = 0; i < numberOfVariables_; i++)
            f2 += (x[i] - 2.0) * (x[i] - 2.0);

        solution->setObjective(0, f1);
        solution->setObjective(1, f2);

        delete[] x;
    }
    void evaluateConstraints(Solution *solution)
    {
        double *constraint = new double[getNumberOfConstraints()];
        double *x = new double[numberOfVariables_];
        for(int i=0;i<numberOfVariables_;i++)
        {
            x[i]=solution->getDecisionVariables()[i]->getValue();
        }
        // Constraints
        constraint[0] = 0.0;
        constraint[1] = 0.0;
        for (int i = 0; i < numberOfVariables_; i++) {
            constraint[0] += x[i];
            constraint[1] += x[i] * x[i];
        }
        constraint[0] = constraint[0] - 5.0;
        constraint[1] = constraint[1] - 9.0;
        int number = 0;
        double total = 0.0;
        for(int i=0; i<this->getNumberOfConstraints();i++)
        {
            // 这个可以判断
            if(constraint[i]>0.0)
            {
                number++;
                total+=constraint[i];
            }
        }
        solution->setOverallConstraintViolation(total);
        solution->setNumberOfViolatedConstraints(number);

        delete x;
    }
};

int main() {
    Problem   * problem   = new MyProblem();
    Algorithm * algorithm = new NSGAII(problem);

    // Algorithm parameters
    int populationSize = 100;
    int maxEvaluations = 25000;
    algorithm->setInputParameter("populationSize", &populationSize);
    algorithm->setInputParameter("maxEvaluations", &maxEvaluations);

    // Mutation and Crossover for Real codification
    map<string, void *> parameters;
    double crossoverProbability = 0.9;
    double crossoverDistributionIndex = 20.0;
    parameters["probability"] = &crossoverProbability;
    parameters["distributionIndex"] = &crossoverDistributionIndex;
    Crossover * crossover = new SBXCrossover(parameters);

    parameters.clear();
    double mutationProbability = 1.0 / problem->getNumberOfVariables();
    double mutationDistributionIndex = 20.0;
    parameters["probability"] = &mutationProbability;
    parameters["distributionIndex"] = &mutationDistributionIndex;
    Mutation * mutation = new PolynomialMutation(parameters);
    parameters.clear();
    Selection * selection = new BinaryTournament2(parameters);

    // Add the operators to the algorithm
    algorithm->addOperator("crossover", crossover);
    algorithm->addOperator("mutation", mutation);
    algorithm->addOperator("selection",selection);

    // Execute the Algorithm
    SolutionSet * population = algorithm->execute();

    // Result messages
    //cout << "Total execution time: " << algorithm->getExecutionTime() << "ms" << endl;
    cout << "Variables values have been written to file VAR" << endl;
    population->printVariablesToFile("out_VAR.txt");
    cout << "Objectives values have been written to file FUN" << endl;
    population->printObjectivesToFile("out_FUN.txt");
    
    delete selection;
    delete crossover;
    delete mutation;
    delete population;
    delete algorithm;


    return 0;
}
