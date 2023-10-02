
#include "Array.h"

Array::Array()
{
    size=10;
    a = new pairsOfWords *[size];
    for(int i=0; i<size; i++)
    {
        a[i]= nullptr;
    }
    words= 0;
    position_to_search= 0;
}

Array::Array(unsigned int b)
{
    size= b;
    a = new pairsOfWords*[size];
    for(int i=0; i<size; i++)
    {
        a[i]= nullptr;
    }
    words=0;
    position_to_search= 0;
}

Array::~Array()
{
    for(int i=0; i<size; i++)
    {
        delete a[i];
    }
    delete [] a;
    a= nullptr;
    size= 0;
    words= 0;
    position_to_search= 0;

}

bool Array::add(string & word) //������� ������� �� ������� ��� � ���� ��� �� ������ �������� 1
{
    pairsOfWords * pair=Search(word);
    if(pair!=nullptr)
    {
        pair-> stored+=1;
        return false;
    }

    a[words]= new pairsOfWords(word,1);
    words++;

    if(words>=size/2)//if the size of array is >=size/2 then increase the size
    {
        pairsOfWords **temp;
        size*=2;
        temp= new pairsOfWords*[size];
        for(int i=0; i< size; i++)
        {
            temp[i]=nullptr;
        }
        for (int i=0; i< words; i++)
        {
            temp[i]=a[i];
        }
        delete[] a;
        a= temp;
    }
    return true;
}

pairsOfWords * Array::Search(const string &word)
{
    pairsOfWords * temp= nullptr;
    for(int i=0; i< words;i++)
    {
        if(a[i]->word==word)
        {
            temp= a[i];
            position_to_search= i;
            return temp;
        }
    }
    return temp;
}

bool Array::Search(const string &word, int & stored)
{
    if(words==0)
    {
        stored=0;
        return false;
    }

    pairsOfWords* temp= Search(word);

    if(temp== nullptr)
    {
        stored=0;
        return false;
    }

    stored= temp->stored;
    cout<< word<<"(" << stored << ")"<<endl;

    return true;
}

bool Array::removing(const string &word)
{
    if(words==0)
    {
        return false;
    }
    if(Search(word)== nullptr)
    {
        return false;
    }

    delete a[position_to_search];
    a[position_to_search]= nullptr;

    for(int i=0; i<= words; i++)
    {
        a[i-1]= a[i];
    }
    words--;
    if(words< size/4)
    {
        pairsOfWords **temp;
        size/=2;
        temp= new pairsOfWords*[size];
        for(int i=0;i <size;i++)
        {
            temp[i]=a[i];
        }
        delete[] a;
        a=temp;
    }
    return true;

}

unsigned int Array::get_Size()
{
    return size;
}
unsigned int Array::get_Words()
{
    return words;
}
unsigned int Array::get_Stored()
{
    int stored = 0;
    for(int i=0;i<words;i++)
    {
        stored+=a[i]->stored;

    }
    return stored;
}

void Array::print()
{
    for(int i=0; i<words; i++)
    {
        cout<<a[i]->word<<" "<<a[i]->stored<<endl;
    }
}

string Array::get(int x)
{
    if(words == 0)
    {
        throw runtime_error("Empty Array");
    }
    if(x< -1)
    {
        throw runtime_error("You cant get method with negative argument");
    }
    if(x>=words)
    {
        throw runtime_error("You gave bigger argument than existing cells");
    }
    return a[x]->word;
}






