#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "Array.h"

class SortedArray: public Array
{
    private:
        pairsOfWords* Search(const string &, int start, int end);
    public:
        SortedArray();
        SortedArray(unsigned int s);
        ~SortedArray();

        bool add(string &);
        bool Search(const string &, int &);
        bool removing(const string &);
};

#endif // SORTEDARRAY_H
