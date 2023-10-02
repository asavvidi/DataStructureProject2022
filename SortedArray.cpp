#include "SortedArray.h"

SortedArray::SortedArray()= default;
SortedArray::SortedArray(unsigned int s):Array(s)
{
};
SortedArray::~SortedArray()= default;

bool SortedArray::add(string & word) //���� ����������� ����������� ������� ������� ��������� ��� �� ��� �� �����.
{
    if(words==0)
    {
        words++;
        a[0]= new pairsOfWords(word,1);
        return true;
    }

    pairsOfWords * pair=nullptr;

    if(word< a[0]->word) //��� �� ���� �����
    {
        position_to_search=0;
    }
    else if(word> a[words-1]->word) // ��� �� ���� ���������
    {
        position_to_search= words-1;
    }
    else  // ������� �� ������� ��� ��� �������� +1 �� �������
    {
        pair = Search(word, 0, words-1);
        if(pair!=nullptr)
        {
            pair ->stored+=1;
            return false;
        }
    }

    if(a[position_to_search]->word<word)
    {
        position_to_search +=1;
    }

    for(int i=words; i>position_to_search; i--)
    {
        a[i]=a[i-1];
    }

    a[position_to_search]= new pairsOfWords(word,1);
    words++;

    if(words>= size/2) //������ ��� �������� ��� ������ �� ���������
    {
        pairsOfWords ** tmp;
        size*=2;
        tmp = new pairsOfWords*[size];
        for(int i=0; i<size; i++)
        {
            tmp[i]=nullptr;
        }
        for(int i=0; i<words; i++)
        {
            tmp[i] = a[i];
        }
        delete[] a;
        a= tmp;
    }
    return true;
}


pairsOfWords* SortedArray::Search(const string & word, int start, int end) //���� ����� ��� ������� ���������
{
    if(start==end)
    {
        position_to_search=start;
        if(a[start]->word ==word)
        {
            return a[start];
        }
        else
        {
            return nullptr;
        }
    }

    int mid= (end+start)/2;

    if(a[mid]-> word == word)
    {
        position_to_search= mid;
        return a[mid];
    }
    else if(a[mid]-> word> word)
    {
        if(mid== start)
        {
            position_to_search=mid;
            return nullptr;
        }
        return Search(word, start, mid-1);
    }
    else
    {
        return Search(word,mid+1 , end);
    }

}

bool SortedArray::Search(const string & word, int & stored)
{

    if(words == 0)
    {
        return false;
    }
    if( word < a[0]-> word || word> a[words-1]->word)
    {
        return false;
    }
    pairsOfWords * tmp= Search(word,0,words-1);

    if(tmp== nullptr)
    {
        return false;
    }

    stored = tmp -> stored;
    cout<< word<<"(" << stored << ")"<<endl;
    return true;

}

bool SortedArray::removing(const string & word)
{
    if(words == 0)
    {
        return false;
    }
    if(word< a[0] -> word || word> a[words-1] -> word)
    {
        return false;
    }
    if(Search(word,0,words-1)== nullptr)
    {
        return false;
    }
    delete a[position_to_search];
    a[position_to_search] = nullptr;

    for(int i=position_to_search+1; i<=words; i++)
    {
        a[i-1]= a[i];
    }

    words--;

    if(words< size/4)
    {
        pairsOfWords ** tmp;
        size/=2;
        tmp= new pairsOfWords*[size];

        for(int i=0;i<size; i++)
        {
            tmp[i]=a[i];
        }
        delete[] a;
        a=tmp;

    }
    return true;
}


