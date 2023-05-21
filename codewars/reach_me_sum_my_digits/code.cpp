#include <iostream>
#include <assert.h>

#include <vector>

int sumDigNthTerm(int initval, const std::vector<int> patternl, int nthterm) 
{
    for(int i(0); i < nthterm - 1; i++)
    {
        initval += patternl[i % patternl.size()];
    }
    int sum(0);
    for(char c: std::to_string(initval))
    {
        sum += c - '0';
    }
    return sum;
}

int main()
{
    int initval = 10, nthterm = 6;
    std::vector<int> patternl = {2, 1, 3};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 10);
    initval = 10, nthterm = 15;
    patternl = {2, 1, 3};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 10);
    initval = 10, nthterm = 50;
    patternl = {2, 1, 3};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 9);
    initval = 10, nthterm = 78;
    patternl = {2, 1, 3};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 10);
    initval = 10, nthterm = 157;
    patternl = {2, 1, 3};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 7);
    initval = 10, nthterm = 6;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 10, nthterm = 15;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 10, nthterm = 50;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 9);
    initval = 10, nthterm = 78;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 10, nthterm = 157;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 16);
    initval = 100, nthterm = 6;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 100, nthterm = 15;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 100, nthterm = 50;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 9);
    initval = 100, nthterm = 78;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 11);
    initval = 100, nthterm = 157;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 16);
    initval = 1000, nthterm = 2550;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 14);
    initval = 1000, nthterm = 25500;
    patternl = {2, 2, 5, 8};
    assert(sumDigNthTerm(initval, patternl, nthterm) == 26);
    return 0;
}