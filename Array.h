#ifndef ARRAY_H
#define ARRAY_H

#include "pairsOfWords.h"
#include <iostream>

class Array
{
    private:
        pairsOfWords* Search(const string &);
    protected:
        pairsOfWords* *a;
        unsigned int size;
        unsigned int words;
        unsigned int position_to_search;
    public:
        Array();
        Array(unsigned int);

        ~Array();
        virtual bool add(string &);
        virtual bool removing(const string &);
        virtual bool Search(const string &, int &);


        unsigned int get_Size(); // ���������� �� ������� ��� ������
        unsigned int get_Words(); // ���������� ��� ������������� ������
        unsigned int get_Stored(); // ���������� �� ����� ����� ������� � ����

        void print();
        string get(int);

};

#endif // ARRAY_H
