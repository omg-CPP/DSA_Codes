#include <iostream>
#include <vector>
using namespace std;

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

// T.C. = O(n^2)
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(); // No of gas stations
    int gasAvailable = 0;
    int totalCost = 0;
    for(int i = 0 ; i < n ; i++) {
        gasAvailable += gas[i];
        totalCost += cost[i];
    }
    if(gasAvailable < totalCost) {
        return -1;
    }
    // gasAvailable >= totalCost
    for(int start = 0 ; start < n ; start++) {
        int fuel = 0;
        int count = 0;
        int i = start;
        while(count < n) {
            fuel = fuel + gas[i];
            fuel = fuel - cost[i];

            if(fuel < 0) {
                break;
            }

            i = (i + 1) % n;
            count++;
        }
        if(count == n) {
            return start;
        }
    }
    return -1;
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int result = canCompleteCircuit(gas,cost);
    cout<<"Starting station index : "<<result<<endl;
    // Starting station index : 3
    return 0;
}