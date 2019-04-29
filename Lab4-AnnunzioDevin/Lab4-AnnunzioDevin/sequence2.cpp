#include "sequence2.h"
#include <iostream>
#include <cassert>

using namespace std;

namespace main_savitch_4
{
    sequence::sequence(size_type initial_capacity)
    {
        capacity = initial_capacity;
        data = new value_type[capacity];
        used = 0;
        current_index = 0;
    }
    
    sequence::sequence(const sequence& source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data+used, data);
    }
    
    sequence::~sequence()
    {
        delete [] data;
    }
    
    void sequence::start()
    {
        current_index = 0;
    }
    
    void sequence::advance()
    {
        //assert(is_item());
        if((is_item()) && (current_index < used))
            current_index++;
    }
    
    void sequence::insert(const value_type& entry)
    {
        if(capacity <= used)
            resize(used+1);
        if(!(is_item()))
        {
            if(used == 0)
            {
                data[0] = entry;
                used++;
            }
            else
            {
                start();
                for(size_type i = used; i > current_index; i--)
                    data[i] = data[i-1];
                ++current_index;
                data[0] = entry;
                used++;
            }
        }
        else
        {
            for(size_type i = used; i > current_index; i--)
                data[i] = data[i-1];
            data[current_index] = entry;
            used++;
        }
    }
    
    void sequence::attach(const value_type& entry)
    {
        if(capacity <= used)
            resize(used+1);
        if(!(is_item()))
        {
            data[current_index] = entry;
            used++;
        }
        else
        {
            for(size_type i = used; i > current_index; i--)
                data[i] = data[i-1];
            ++current_index;
            data[current_index] = entry;
            used++;
        }
    }
    
    void sequence::remove_current()
    {
        assert(is_item());
        if(is_item())
        {
            for(size_type k = current_index; k < used; k++)
                data[k] = data[k+1];
        }
        used--;
    }
    
    void sequence::resize(size_type new_capacity)
    {
        value_type *new_array;
        if(capacity == new_capacity)
            return;
        if(capacity > new_capacity)
        {
            used = new_capacity;
        }
        if(capacity < new_capacity)
        {
            new_array = new value_type[new_capacity];
            copy(data, data+used, new_array);
            delete [] data;
            data = new_array;
            capacity = new_capacity;
        }
    }
    
    void sequence::operator=(const sequence& source)
    {
        value_type *new_data;
        if(this == &source)
            return;
        if(capacity != source.capacity)
        {
            new_data = new value_type[source.capacity];
            delete [] data;
            data = new_data;
            capacity = source.capacity;
        }
        used = source.used;
        current_index = source.current_index;
        copy(source.data, source.data+used, data);
    }
    
    sequence::size_type sequence::size() const
    {
        return used;
    }
    
    bool sequence::is_item() const
    {
        return (current_index < used);
    }
    
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index];
    }
}
