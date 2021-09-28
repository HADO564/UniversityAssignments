#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
};

class dlinkl
{
    public:
    node *start;
    node *last;
};