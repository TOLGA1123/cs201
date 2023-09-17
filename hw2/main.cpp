#include <stdio.h>
#include <iostream>
#include <chrono>
#include <time.h>
#include<cstdlib>
#include <iomanip>
using namespace std;
    //Cubic maximum contiguous subsequence sum algorithm
    int maxSubSum1(const int* arr, const int arrLength){
        int maxSum = 0;
        for(int i = 0; i < arrLength; i++){
            for(int j = i; j < arrLength; j++){
                int thisSum = 0;

                for(int k = i; k <= j; k++){
                    thisSum += arr[k];
                }
                if(thisSum > maxSum){
                    maxSum = thisSum;
                }
            }
        }
        return maxSum;
    }
    //Quadratic maximum contiguous subsequence sum algorithm
    int maxSubSum2(const int* arr, const int arrLength){
        int maxSum = 0;
        for(int i = 0; i < arrLength; i++){
            int thisSum = 0;
            for(int j = i; j < arrLength; j++){
                thisSum += arr[j];
                if(thisSum > maxSum){
                    maxSum = thisSum;
                }
            }
        }
        return maxSum;
    }
    //function that returns maximum one  of 3 integers
    int max3(int a, int b, int c){
        int max = a;
        if(max < b){
            max = b;
        }
        if(max < c){
            max = c;
        }
        return max;
    }
    /* Recursive maximum contiguous subsequence sum algorithm
    *  Finds maximum sum in subarray spanning arr[left...right].
    *  Does not attempt to maintain actual best sequence. */
    int maxSumRec(const int* arr, const int arrLength, int left, int right){
        //base case
        if(left == right){
            if(arr[left] > 0){
                return arr[left];
            }
            else{
                return 0;
            }
        }
        int center = (left + right) / 2;
        int maxLeftSum = maxSumRec(arr, arrLength, left, center);       //should arrLength be changed here ???
        int maxRightSum = maxSumRec(arr, arrLength, center + 1, right);
        int maxLeftBorderSum = 0, leftBorderSum = 0;
        for(int i = center; i >= left; i--){
            leftBorderSum += arr[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        int maxRightBorderSum = 0, rightBorderSum = 0;
        for(int j = center + 1; j <= right; j++){
            rightBorderSum += arr[j];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }
    //Driver for divide-and-conquer maximum contiguous subsequence sum algorithm
    int maxSubSum3(const int* arr, const int arrLength){
        return maxSumRec(arr, arrLength , 0, arrLength -1);
    }
    //Linear-time maximum contiguous subsequence sum algorithm
    int maxSubSum4(const int* arr, const int arrLength){
        int maxSum = 0, thisSum = 0;
        for(int j = 0; j < arrLength; j++){
            thisSum += arr[j];
            if(thisSum > maxSum){
                maxSum = thisSum;
            }
            else if(thisSum < 0){
                thisSum = 0;
            }
        }
        return maxSum;
    }

    int main(){
        int size;               //change size later but dont print array
        cout<< "Enter array size: ";
        cin>> size;
        int* arr = new int[size];
        srand(time(0));     //included to generate different array on each run
        int up = 100;        //rand generates random integers between up and low     change bounds later
        int low = -100;
        for(int i = 0; i < size; i++){
            arr[i] = rand() % (up - low + 1) + low;
        }
        /*for(int i = 0; i < size; i++){
            cout<< arr[i] << " ";
        }*/
        //cout<< endl;
        //cout<< "\n" << maxSubSum1(arr, size) << endl;
        //cout<< "\n" << maxSubSum2(arr, size) << endl;
        //cout<< "\n" << maxSubSum3(arr, size) << endl;
        //cout<< "\n" << maxSubSum4(arr, size) << endl;

        // Declare necessary variables                  //small input with less than 1 miliseconds are rounded to 0 like size = 5, 10 etc.
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::duration<double, milli> elapsedTime;

        //ALGORITHM 1
        // Store the starting time
        startTime = std::chrono::system_clock::now();
        // Code block
        //for(int i = 0; i < 100000; i++){            //less than  1 milliseconds call 100000-ish times and divide time
        maxSubSum1(arr, size);
        //}
        // Compute the number of milliseconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "For algorithm 1 (N^3) execution took " << std::fixed << std::setprecision(5)<< elapsedTime.count() << " milliseconds." << endl;

        //ALGORITHM 2
        // Store the starting time
        startTime = std::chrono::system_clock::now();
         // Code block
         //for(int i = 0; i < 100000; i++){            //less than  1 milliseconds call 100000-ish times and divide time
        maxSubSum2(arr, size); //}
        // Compute the number of milliseconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "For algorithm 2 (N^2) execution took " << std::fixed << std::setprecision(5)<< elapsedTime.count() << " milliseconds." << endl;

        //ALGORITHM 3
        // Store the starting time
        startTime = std::chrono::system_clock::now();
         // Code block
         for(int i = 0; i < 100000; i++){                   //less than  1 milliseconds call 100000-ish times and divide time
        maxSubSum3(arr, size);
         }
        // Compute the number of milliseconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "For algorithm 3 (N logN) execution took " << std::fixed << std::setprecision(5)<< elapsedTime.count() << " milliseconds." << endl;

        //ALGORITHM 4
        // Store the starting time
        startTime = std::chrono::system_clock::now();
         // Code block
         for(int i = 0; i < 10000; i++){                    //less than  1 milliseconds call 100000-ish times and divide time
        maxSubSum4(arr, size);
         }
        // Compute the number of milliseconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "For algorithm 4 (N) execution took " << std::fixed << std::setprecision(5)<< elapsedTime.count() << " milliseconds." << endl;
        delete[] arr;
        return 0;
    }


