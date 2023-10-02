#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include <time.h>
#include "BinaryTree.h"
#include "AVL.h"
#include "HashTable.h"
#include "SortedArray.h"
#include "Array.h"

using namespace std;

//Function that eliminates punctuation marks.
void eliminate_punct(string& s)
{
    int i;
    int len = s.size();
    for (i = 0;i < len;i++)
    {
        if (ispunct(s[i]))
        {
            s.erase(i--, 1);
            len = s.size();
        }
    }
}
int main()
{
    ifstream file("input.txt");
    string linestr; //a line from file.
    string word;
    //Creating data structures.

    BinaryTree t;
    AVL a;
    HashTable h;
    SortedArray s;
    Array us;

    while (getline(file, linestr))
    {
        //Eliminating punctuation from line.
        eliminate_punct(linestr);
        stringstream iss(linestr);
        //Extracting words from a line.
        while (iss >> word)
        {
            //Adding each word.
            t.add(word);
            a.add(word);
            h.add(word);
            s.add(word);
            us.add(word);
        }
    }
    //Get 10000 words from the file.
    ifstream fileRandom("input.txt");
    string* W;
    W = new string[10000];
    int stored=0;

    int c = 0; //counter of words.
    int numofLines = 1; //counter of lines.
    bool flag = false;
    while (getline(fileRandom, linestr))
    {
        if (numofLines > 10 && flag == false)
        {
            eliminate_punct(linestr);
            stringstream iss(linestr);
            while (iss >> word) //extracting all words from a line.
            {
                W[c] = word;  //save words in array W.
                c++;
                if (c == 10000)
                {
                    flag = true; //10000 words found, exit loop.
                    break;
                }
            }
        }
        numofLines++;
        if (flag == true)
            break;
    }

    //Open the file output,txt
    ofstream myFile("output.txt");


    //Searching these 10000 words in data structures.
    // and store the results in the output.txt file

    //Timing of Binary Tree.
    myFile<< "BINARY TREE: " << endl;
    cout << "BINARY TREE: " << endl;
    clock_t timeBinary;
    timeBinary = clock();
    for (int i = 0;i < 10000;i++)
    {
        if(t.searching(W[i],stored)){
            myFile<< W[i]<<"(" << stored << ")"<<endl;
        }else{
            myFile<< "Word '" << W[i] << "' not found." << endl;
        }

    }
    timeBinary = clock() - timeBinary;
    myFile<<"\n"<<endl;
    cout << "\n" << endl;


    //Timing of AVL.
    myFile<< "AVL: "<<endl;
    cout << "AVL: " << endl;
    clock_t timeAVL;
    timeAVL = clock();
    for (int i = 0;i < 10000;i++){

        if(a.searching(W[i],stored)){
                myFile<< W[i]<<"(" << stored << ")"<<endl;
        }else{
            myFile<< "Word '" << W[i] << "' not found." << endl;
        }
    }

    timeAVL = clock() - timeAVL;
    myFile<<"\n"<<endl;
    cout << "\n" << endl;


    //Timing of Hash Table.
    myFile<<"HASH TABLE: "<<endl;
    cout << "HASH TABLE: " << endl;
    clock_t timeHT;
    timeHT = clock();
    for (int i = 0;i < 10000;i++){

        if(h.Search(W[i],stored)){
            myFile<< W[i]<<"(" << stored << ")"<<endl;

        }else{
            myFile<< "Word '" << W[i] << "' not found." << endl;
        }
    }
    timeHT = clock() - timeHT;
    myFile<<"\n"<<endl;
    cout << "\n" << endl;


    //Timing of Sorted Array.

    myFile<<"SORTED ARRAY: "<<endl;
    cout<<"SORTED ARRAY: "<<endl;
    clock_t timeSA;
    timeSA= clock();
    for(int i=0; i<10000; i++){

        if(s.Search(W[i],stored)){
                myFile<< W[i]<<"(" << stored << ")"<<endl;
        }
        else{
            myFile<< "Word '" << W[i] << "' not found." << endl;
        }

    }
    timeSA=clock()- timeSA;
    myFile<<"\n"<<endl;
    cout<<"\n"<<endl;


    //Timing of UnSorted Array.

    myFile<<"UNSORTED ARRAY: "<<endl;
    cout<<"UNSORTED ARRAY: "<<endl;
    clock_t timeUSA;
    timeUSA=clock();
    for(int i=0; i<10000; i++){
        if(us.Search(W[i],stored)){
            myFile<< W[i]<<"(" << stored << ")"<<endl;

        }
        else{
            myFile<< "Word '" << W[i] << "' not found." << endl;
        }
    }
    timeUSA=clock()-timeUSA;
    myFile<<"\n"<<endl;
    cout<<"\n"<<endl;

    //Printing the results
    cout<<"Binary Tree took " <<(float)timeBinary / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "AVL took " << (float)timeAVL / CLOCKS_PER_SEC << " seconds" << endl;
    cout<< "Hash Table took " << (float)timeHT / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Sorted Array took " <<(float)timeSA/CLOCKS_PER_SEC<<" seconds"<<endl;
    cout << "Unsorted Array took "<<(float)timeUSA/CLOCKS_PER_SEC<<" seconds"<<endl;



    //Printing the results in the output file
    myFile<<"Binary Tree took " <<(float)timeBinary / CLOCKS_PER_SEC << " seconds" << endl;
    myFile << "AVL took " << (float)timeAVL / CLOCKS_PER_SEC << " seconds" << endl;
    myFile<< "Hash Table took " << (float)timeHT / CLOCKS_PER_SEC << " seconds" << endl;
    myFile << "Sorted Array took " <<(float)timeSA/CLOCKS_PER_SEC<<" seconds"<<endl;
    myFile << "Unsorted Array took "<<(float)timeUSA/CLOCKS_PER_SEC<<" seconds"<<endl;

    //Close the file
    myFile.close();




    return 0;
}
