#include <vector>
#include<iostream>
using namespace std;



class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double avg = 0;
        int startTime = 0;
        int clk = 0;
        for(auto customer:customers){
            int wait = 0;
            // int arrival = customer[0];
            // int work = customer[1];
            // if (clk < arrival){
            //     clk = arrival;
            // }
            // clk += work;
            if (startTime > customer[0]){
                wait = startTime - customer[0];
            }else if (startTime < customer[0]){
                wait = 0;
                startTime = customer[0];
            }
            startTime += customer[1];
            avg +=  wait + customer[1];




            
        }

        return avg/customers.size() ;

    }
};