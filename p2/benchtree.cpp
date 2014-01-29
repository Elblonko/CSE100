/*
 *Name: Matthew Schwegler
 *ID: A09293823
 *File Benchtree
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
#include "BST.hpp"
#include "RST.hpp"
#include "countint.hpp"

#define TWO 2

using namespace std;

int main(int argc, char * argv[]){

    /* Variable Declarations */
    double stdev = 0;
    double avgTotal =0;
    int maxSize = 0;    //max size of tree
    int index = 1;
    int numRuns = 0;    //Number of benchmark runs to preform
    int N = 0;
    bool shuffle = false;
    bool bst = false;
    bool rst = false;
    bool set1 = false;

    //Switch statement to parse user input
    while (argv[index] != NULL ){
        //get argument
        //string word ( argv[index]);

        if( !strcmp(argv[index],"bst") )
        {
            //Code to generate BST
            bst = true;
        }
        else if ( !strcmp (argv[index], "rst") )
        {
            //Code to generate RST
            rst = true;
        }
        else if ( !strcmp(argv[index], "set" ) )
        {
            //Code to generate c++ set
            set1 = true;
        }
        else if ( !strcmp(argv[index], "shuffle" ) )
        {
            //Code to shuffle input
            shuffle = true;    
        }

        index++;
    }

    //Get the max size as 3rd user argument
    maxSize = atoi( argv[3] );
    //Convert given size to power of 2 minus one
    N = pow (maxSize, TWO);


    //Get the number of benchmark runs to preform
    numRuns = atoi( argv[4] ) - 1;

    //Create vector of the size specified

    vector<countint> v;
    v.clear();
    for(int i = 0; i < N; ++i) {
        v.push_back(i);
    }

    //if user wanted elements shuffeled
    if (shuffle){
        std::random_shuffle( v.begin(),v.end() );
    }

    //create an iterator
    vector<countint>::iterator vit = v.begin();
    vector<countint>::iterator ven = v.end();

    //create the appriate structure
    //Inserts for the chosen structure


    if (bst){
        BST<countint> s;
        for(; vit != ven; vit++ ){
            s.insert(*vit);
        }


        //cout messages to user
        cout << "# Benchmarking average number of comparisons for successful find" << endl;
        cout << "# Data Structure: " << argv[1] << endl;
        cout << "# Data: " << argv[2] << endl;
        cout << "# N is powers of 2, minus 1, from 1 to " << argv[3] << endl;
        cout << "# Averaging over 5 runs for each N" << endl;
        cout << "#" << endl;
        cout << "# N    avgcomps    stdev"<< endl;

        //For the number of runs passed in
        for ( int run = 0; run < numRuns; run++ ){

            //now start the count variable for find
            countint::clearcount();
            for(vit = v.begin(); vit != ven; ++vit){
                s.find(*vit);
            }

            //now get avg computations
            double avgcomps = countint::getcount() / (double) N;

            //now calculate the standard deviation
            avgTotal += avgcomps;

            stdev = sqrt( (avgTotal/run) - ( pow(avgTotal,TWO) /run) );

            //print statements
            cout << "     " << run << "     " << avgcomps << "     " << stdev << endl;



        }


    }


    else if (rst){
        RST<countint> s;
        //insert into s
        for(; vit != ven; vit++ ){
            s.insert(*vit);
        }



        //cout messages to user
        cout << "# Benchmarking average number of comparisons for successful find" << endl;
        cout << "# Data Structure: " << argv[1] << endl;
        cout << "# Data: " << argv[2] << endl;
        cout << "# N is powers of 2, minus 1, from 1 to " << argv[3] << endl;
        cout << "# Averaging over 5 runs for each N" << endl;
        cout << "#" << endl;
        cout << "# N    avgcomps    stdev"<< endl;

        //For the number of runs passed in
        for ( int run = 0; run  < numRuns; run++ ){

            //now start the count variable for find
            countint::clearcount();
            for(vit = v.begin(); vit != ven; ++vit){
                s.find(*vit);
            }


            //now get avg computations
            double avgcomps = countint::getcount() / (double) N;

            //now calculate the standard deviation
            avgTotal += avgcomps;

            stdev = sqrt( (avgTotal/run) - ( pow(avgTotal,TWO) /run) );

            //print statements
            cout << "     " << run << "     " << avgcomps << "     " << stdev << endl;


        }

    }

    else if(set1){
        set<countint> s;
        //insert values into nodes
        for(; vit != ven; vit++ ){
            s.insert(*vit);
        }

        //cout messages to user
        cout << "# Benchmarking average number of comparisons for successful find" << endl;
        cout << "# Data Structure: " << argv[1] << endl;
        cout << "# Data: " << argv[2] << endl;
        cout << "# N is powers of 2, minus 1, from 1 to " << argv[3] << endl;
        cout << "# Averaging over 5 runs for each N" << endl;
        cout << "#" << endl;
        cout << "# N    avgcomps    stdev"<< endl;

        for (int i = 0; i < 15; i++ ){

            //For the number of runs passed in
            for ( int run = 0; run < numRuns; run++ ){

                //now start the count variable for find
                countint::clearcount();
                for(vit = v.begin(); vit != ven; ++vit){
                    s.find(*vit);
                }


                //now get avg computations
                double avgcomps = countint::getcount() / (double) N;

                //now calculate the standard deviation
                avgTotal += avgcomps;


            }

            //average over the amount of runs
            avgTotal = avgTotal / numRuns;

            stdev = sqrt( (avgTotal/numRuns) - ( pow(avgTotal,TWO) /numRuns) );

            //print statements
            cout << "     " << numRuns << "     " << avgTotal << "     " << stdev << endl;


        }

    }


    //endfile
}
