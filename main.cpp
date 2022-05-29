/*
  3494 - Alexandros Savvidis 
  3275 - Nikos Marinakis 
*/
#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include <time.h>
#include "BinaryTree.h"
#include "AVL.h"
#include "HashTable.h"

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
        }
    }
    //Get 1000 words from the file.
    ifstream fileRandom("input.txt");
    string* W;
    W = new string[1000];
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
                c = c + 1;
                if (c == 1000)
                {
                    flag = true; //1000 words found, exit loop.
                    break;
                }
            }
        }
        numofLines = numofLines + 1;
        if (flag == true)
            break;
    }


    //Searching these 1000 words in data structures.
    // 
    //Timing of Binary Tree.
    cout << "BINARY TREE: " << endl;
    clock_t timeBinary;
    timeBinary = clock();
    for (int i = 0;i < 1000;i++)
        t.searching(W[i]);
    timeBinary = clock() - timeBinary;
    cout << "\n" << endl;


    //Timing of AVL.
    cout << "AVL: " << endl;
    clock_t timeAVL;
    timeAVL = clock();
    for (int i = 0;i < 1000;i++)
        a.searching(W[i]);
    timeAVL = clock() - timeAVL;
    cout << "\n" << endl;


    //Timing of Hash Table.
    cout << "HASH TABLE: " << endl;
    clock_t timeHT;
    timeHT = clock();
    for (int i = 0;i < 1000;i++)
        h.Search(W[i]);
    timeHT = clock() - timeHT;
    cout << "\n" << endl;


    //Printing the results.
    cout << "Binary Tree took " << (float)timeBinary / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "AVL took " << (float)timeAVL / CLOCKS_PER_SEC << " seconds" << endl;
    cout << "Hash Table took " << (float)timeHT / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}
