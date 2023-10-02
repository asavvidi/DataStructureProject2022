#ifndef PAIRSOFWORDS_H
#define PAIRSOFWORDS_H

#include <string>

using namespace std;

class pairsOfWords
{
    private:

    protected:

    public:
        pairsOfWords(string w, int n)
        {
            word=w;
            stored=n;
        }
        string word;
        int stored;
};

#endif //PAIRSOFWORDS_H
