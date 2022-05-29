#include <iostream>
#include <new>
#include <string>
#include "string.h"
#include <cstring>
#include "HashTable.h"
#include  <cstdlib>

using namespace std;
//constructor
HashTable::HashTable()
{
    D = 80000;
    N = 0; //number of buckets
//creating an array of 80000 buckets
    HT = new (nothrow) bucket[D];
    if (HT == nullptr)
        cout << "Problem HT" << endl;
    //when Empty[k]=true, HT[k] is empty
    //when Empty[k]=false, HT[k] not empty
    Empty = new (nothrow) bool[D];
    if (Empty == nullptr)
        cout << "Problem Empty" << endl;
    for (int i = 0;i < D;i++)
        Empty[i] = true; //initializing
}


//extracting key of a word
int HashTable::getKey(string word)
{
    unsigned int k;
    unsigned int sum = 0;
    for (k = 0; k < word.length(); k++)
        sum = sum + abs(word[k]);
    return sum;
}


void HashTable::add(string word)
{
    int k = getKey(word); //key of word
    int i = k % D;         //(key%sizeofarray) position at first try
    int j = i;
    bool flag = false;  //as long as flag=false word not yet placed
    do {
        if (Empty[j] == true) //no word in this position
        {
            Empty[j] = false;
            bucket b;        //create new bucket b
            b.value = word;
            b.key = k;
            b.a = 1;        //initialize key,value and appearance of b
            HT[j] = b;
            N = N + 1;      //One more NEW word added.
            flag = true;
        }
        else if (Empty[j] == false && HT[j].value == word)
        {
            HT[j].a = HT[j].a + 1;  //Word already there, increasing its appearance a.
            flag = true;
        }
        j = (j + 1) % D; //next possible position of word
    } while (j != i && flag == false); //loop stops when j==i or flag==true

    if (double(N) / double(D) >= 0.5) //When half of the array is full ->
        resize_array();             //duplicate the size.
}



void HashTable::resize_array()
{
    int i;
    int dt = D;
    temp1 = new (nothrow) bucket[D];      //Temporary arrays.
    if (temp1 == nullptr)
        cout << "Problem temp1" << endl;
    temp2 = new (nothrow) bool[D];
    if (temp2 == nullptr)
        cout << "Problem temp2" << endl;
    //Copying two arrays to the temporary ones.
    for (i = 0;i < D;i++)
    {
        temp1[i] = HT[i];
        temp2[i] = Empty[i];
    }
    delete[] HT;
    delete[] Empty;

    HT = new (nothrow) bucket[D * 2];   //Dublicate memory.
    if (HT == nullptr)
        cout << "Problem HT" << endl;
    Empty = new (nothrow) bool[D * 2];
    if (Empty == nullptr)
        cout << "Problem Empty" << endl;
    //Initialising Empty Array.
    for (i = 0;i < D * 2;i++)
        Empty[i] = true;
    D = D * 2; //duplicate the size of the Array.
    N = 0;
    for (i = 0;i < dt;i++)
    {
        if (temp2[i] == false)
        {
            while (temp1[i].a != 0)
            {
                add(temp1[i].value);    //Add all the words from the beginning.
                temp1[i].a = temp1[i].a - 1;
            }
        }
    }
    delete[] temp1;
    delete[] temp2;
}


int HashTable::Searching(string w)
{
    int not_found = -1; //return -1 if word not found
    int k = getKey(w);
    int i = k % D;
    int j = i;
    do {
        if (Empty[j] == false && HT[j].value == w)
            return j;        //word found.
        j = (j + 1) % D;
    } while (j != i);
    return not_found;             //end of array, word not found.
}



//public function Search
void HashTable::Search(string word)
{
    int j = Searching(word);
    if (j > 0)
        cout << word << "(" << HT[j].a << ")" << endl;
    else
        cout << "Word '" << word << "' not found." << endl;
}
