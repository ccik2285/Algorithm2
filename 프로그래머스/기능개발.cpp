#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> arr;
    for(int i=0; i < speeds.size(); i++){
           
            arr.push_back(ceil(double((100-progresses[i]))/double(speeds[i])));
    }
    int count = 0;
    int maxday = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxday){
            count++;
            answer.push_back(count);
            count = 0;
            maxday = arr[i];
        }
        else{
            answer.back()++;
        } 
    } 
    return answer;
}