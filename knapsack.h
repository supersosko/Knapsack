/** @file: knapsack.h
 * 	Definition of the knapsack solutions
 * 	Implementation of Brute-Force, Greedy,
 * 	and Dynamic Programming solutions to the Knapsack Problem
 */

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <random>
#include <stdio.h>
#include <cmath>

struct item
{
	int value;
	int weight;

	//constructor
	item(float v, float w) :
		value(v), weight)(w)
	{}
	
}; //KnapSack

class Knapsack
{
	const int size;
	const float mu;
	const float sigma;
	const int MaxWeight;
	item* shop;

public:

	//constructor generates shop
	Knapsack(int s, float m, float si);

	int Brute_Knapsack();

	int Greedy_KnapSack();

	int Dynamic_KnapSack();


};

#endif
