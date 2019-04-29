/*
 Devin Annunzio
 Data Structures CS 3305 Section 06
 Assignment 3
 Sharon Perry
 */
//AE = algorithm efficiency
#include "set.h"
#include <cassert>
#include<iostream>
using namespace std;


//Create an empty set
//AE:  O(n)
set::set(size_type initial_capacity)
{
    capacity = initial_capacity;
    used = 0;
    data = new value_type[capacity];
    
}
//A copy of source gets created here
//AE: O(n)
set::set (const set& source)
{
    capacity = source.capacity;
    used = source.used;
    data = new value_type[capacity];
    for(int i = 0; i < used; i++)
        data[i] = source.data[i];
}

//deallocated
//AE:O(n)
set::~set()
{
    capacity = 0;
    used = 0;
    delete data;
}
//inserting the entry in the set
//AE:O(n)^2
void set::insert (const value_type& entry)
{
    bool found = false;
    for(int i = 0; i < used; i++)
        if(data[i] == entry)
        {
            found = true;
            break;
        }
    if(!found && used < capacity)
    {
        data[used] = entry;
        used++;
    }
}

// the entry is removed from the set
//AE: O(n)^2
void set::remove (const value_type& entry)
{
    int pos = -1;
    for(int i = 0; i < used; i++)
        if(data[i] == entry)
        {
            pos = i;
            break;
        }
    for(int i = pos; i < used-1; i++)
        data[i] = data[i+1];
    used--;
}

// the number of elements in the set has been returned
//AE: O(n)
set::size_type set::size() const
{
    return used;
}

// Checks whether or not the entry in the set has been returned
//AE:O(n)
bool set::contains (const value_type& entry) const
{
    for(int i = 0; i < used; i++)
        if(data[i] == entry)
            return true;
    return false;
}
//Union of s1 and s2 gets returned
//AE:O(n)^2
set set_union (const set& s1, const set& s2)
{
    set temp;
    for(int i = 0; i < s1.size(); i++)
        temp.insert(s1.data[i]);
    for(int i = 0; i < s2.size(); i++)
        temp.insert(s2.data[i]);
    return temp;
}
 // S1 & s2 gets returned
//AE:O(n)^2
set set_intersection (const set& s1, const set& s2)
{
    set temp;
    for(int i = 0; i < s1.size(); i++)
        if(s2.contains(s1.data[i]))
            temp.insert(s1.data[i]);
    return temp;
}

// Returns the difference of s1-s2
//AE:O(n)^2
set set_difference (const set& s1, const set& s2)
{
    set temp;
    for(int i = 0; i < s1.size(); i++)
        if(!s2.contains(s1.data[i]))
            temp.insert(s1.data[i]);
    return temp;
}
// Returns whether s1 is a subset of s2
//AE:O(n)
bool is_subset (const set& s1, const set& s2)
{
    for(int i = 0; i < s1.size(); i++)
        if(!s2.contains(s1.data[i]))
            return false;
    return true;
}
 // Returns whether s1 & s2 are equal
//AE:O(n)
bool operator == (const set& s1, const set& s2)
{
    if(is_subset(s1, s2) && is_subset(s2, s1))
        return true;
    return false;
}

// Display s in output
//AE:O(n)^2
std::ostream& operator << (std::ostream& output, const set& s)
{
    output << "{ ";
    for(int i = 0; i < s.size()-1; i++)
        output <<s.data[i]<<", ";
    output<<s.data[s.size()-1]<<" }";
    return output;
    }
