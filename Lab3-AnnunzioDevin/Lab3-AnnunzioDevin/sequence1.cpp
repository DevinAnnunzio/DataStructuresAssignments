#include "sequence1.h"
#include <cassert>
#include <iostream>

using namespace std;

namespace main_savitch_3
{
	// no argument constructor
	sequence::sequence()
	{
		used = 0;
		current_index = 0;
	}
	
	
	void sequence::start( )
	{
		current_index = 0;
	}
    
    //     Precondition: is_item returns true.
    //     Postcondition: If the current item was already the last item in the
    //     sequence, then there is no longer any current item. Otherwise, the new
    //     current item is the item immediately after the original current item.
    //Implementation goes here
	
	void sequence::advance( )
	{
        //if is item increment before @current_index
        if (is_item()) {
            ++current_index;
        }
		
	}
    
    //   void insert(const value_type& entry)
    //     Precondition: size( ) < CAPACITY.
    //     Postcondition: A new copy of entry has been inserted in the sequence
    //     before the current item. If there was no current item, then the new entry
    //     has been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
	
	void sequence::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
		if(!is_item())
		{
			current_index = 0;
		}
		if(size() > 0)
		{
			for(int i = size(); i > current_index; i--)
			{
				data[i] = data[i-1];
			}
		}
		data[current_index] = entry;
		used++;
	}
	
	
	void sequence::attach(const value_type& entry)
	{
        //     Precondition: size( ) < CAPACITY.
        //     Postcondition: A new copy of entry has been inserted in the sequence after
        //     the current item. If there was no current item, then the new entry has
        //     been attached to the end of the sequence. In either case, the newly
        //     inserted item is now the current item of the sequence.
		// implementation goes here
        assert( size() < CAPACITY);
        if(!is_item()) current_index= used-1;
        ++current_index;
        for(size_type i = used; i>current_index; --i)
            data[i] = data[i-1];
        data[current_index] = entry;
        ++used;
        }
		
	
    //   void remove_current( )
    //     Precondition: is_item returns true.
    //     Postcondition: The current item has been removed from the sequence, and the
    //     item after this (if there is one) is now the new current item.
    //implementation goes here
	void sequence::remove_current( )
	{
        if( is_item() ) {
            for(size_type i = current_index; i<used-1; ++i) {
                data[i] = data[i+1];
            }
            --used;
        }
	}
	
	
	// CONSTANT MEMBER FUNCTIONS
    //   typedef ____ size_type
    //     sequence::size_type is the data type of any variable that keeps track of
    //     how many items are in a sequence.
	sequence::size_type sequence::size( ) const
	{
		return used;
	}
	
	bool sequence::is_item( ) const
	{
		return used > current_index;
	}
	
	sequence::value_type sequence::current( ) const
	{
		return data[current_index];
	}
}
