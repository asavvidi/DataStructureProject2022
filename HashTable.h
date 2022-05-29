#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <iostream>

using namespace std;

class HashTable
{
private:
    struct bucket
    {
        string value;
        int key;
        int a;   //appearances of a word.
    };
    long long D; //size of arrays.
    long long N; //number of buckets.
    bucket* HT;
    bool* Empty;
    bucket* temp1;
    bool* temp2;
    int getKey(string word);
    void resize_array();
    int Searching(string w);
public:
    HashTable();
    void add(string word);
    void Search(string word);
    void print();
};

#endif // HASHTABLE_H