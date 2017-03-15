        #include "QuadraticProbing.h"
        #include "mystring.h"
        #include "string.h"

        /**
         * Internal method to test if a positive number is prime.
         * Not an efficient algorithm.
         */
        template <class HashedObj>
        bool QuadraticHashTable<HashedObj>::isPrime( int n ) const
        {
            if( n == 2 || n == 3 )
                return true;

            if( n == 1 || n % 2 == 0 )
                return false;

            for( int i = 3; i * i <= n; i += 2 )
                if( n % i == 0 )
                    return false;

            return true;
        }

        /**
         * Internal method to return a prime number at least as large as n.
         * Assumes n > 0.
         */
        template <class HashedObj>
        int QuadraticHashTable<HashedObj>::nextPrime( int n ) const
        {
            if( n % 2 == 0 )
                n++;

            for( ; !isPrime( n ); n += 2 )
                ;

            return n;
        }

        /**
         * Construct the hash table.
         */
        template <class HashedObj>
        QuadraticHashTable<HashedObj>::QuadraticHashTable( const HashedObj & notFound, int size )
          : /*array( nextPrime( size ) ),*/ ITEM_NOT_FOUND( notFound )
        {
           // makeEmpty( );
        }

        /**
         * Insert item x into the hash table. If the item is
         * already present, then do nothing.
         */
      
       	template <class HashedObj>
        void QuadraticHashTable<HashedObj>::insert( const HashedObj & x )
        {
	    //cout << "inserted" << endl;
                // Insert x as active
            int currentPos = findPos( x );
         // if( array[currentPos] != NULL )
	 // {
	//	cout << "in if statement" << endl;
           //     return;
	 // }
	    // Gutted
	    /*
            array[ currentPos ] = HashEntry( x, ACTIVE );
            */
	  array [currentPos] = x;
	 // cout << "currentPos is " << currentPos << endl;
	 // cout << "array[currentpos] " << array[currentPos] << endl;
                // Rehash; see Section 5.5
//            if( ++currentSize > array.size( ) / 2 )
  //              rehash( );



	  //  cout << "inserted" << endl;
        }

        /**
         * Expand the hash table.
         */
  
  //	template <class HashedObj>
      //  void QuadraticHashTable<HashedObj>::rehash( )
       // {
		// change to HashedObj
     //       vector<HashedObj> oldArray = array;

                // Create new double-sized, empty table
   //         array.resize( nextPrime( 2 * oldArray.size( ) ) );
            //for( int j = 0; j < array.size( ); j++ )

		// EMPTY --> NULL
          //      array[ j ]/*.info*/ = NULL;

                // Copy table over
        //    currentSize = 0;
      //      for( int i = 0; i < oldArray.size( ); i++ )

		// ACTIVE --> NULL
    //            if( oldArray[ i ]/*.info*/ == NULL )
  //                  insert( oldArray[ i ]/*.element*/ );
//        }

        /**
         * Method that performs quadratic probing resolution.
         * Return the position where the search for x terminates.
         */
        template <class HashedObj>
        int QuadraticHashTable<HashedObj>::findPos( const HashedObj & x ) const
        {

	
/* 1*/     // int collisionNum = 0;
/* 2*/      int currentPos = hash( x, 200000 );
            // EMPTY --> NULL
	    //cout << "currentPos" << currentPos << endl;
            //cout << "array " << array[currentPos] << endl;
//	    cout << "x " << x << endl;
	  //  cout << "array " << array[currentPos] << endl;
/* 3*/    
	    while( array[ currentPos ] != NULL &&
                   strcmp(array[ currentPos ]/*.element*/, x) )
            {
	//	cout << "array[currentpos]" << array[currentPos] << endl;
	//	cout << "current position: " << currentPos << endl;
	//	cout << "while is working " << endl;

/* 4*/          currentPos += 1;  // Compute ith probe
/* 5*/          if( currentPos >= 200000 )
/* 6*/              currentPos -= 200000;
            }

/* 7*/      return currentPos;
        }


        /**
         * Remove item x from the hash table.
         */
        //template <class HashedObj>
       // void QuadraticHashTable<HashedObj>::remove( const HashedObj & x )
        //{
          //  int currentPos = findPos( x );
           // if( isActive(currentPos) )
		    // DELETED --> NULL
             //   array[ currentPos ]/*.info*/ = NULL;
       // }

        /**
         * Find item x in the hash table.
         * Return the matching item, or ITEM_NOT_FOUND, if not found.
         */
        template <class HashedObj>
        const HashedObj & QuadraticHashTable<HashedObj>::find( const HashedObj & x ) const
        {
            int currentPos = findPos( x );
	   // cout << "currentPos is " << currentPos << endl;
            //return isActive( currentPos ) ? array[ currentPos ]/*.element*/ : ITEM_NOT_FOUND;

	    if (array[currentPos] != NULL)
		    return array[currentPos];
	    return ITEM_NOT_FOUND;
        }

        /**
         * Make the hash table logically empty.
         */
        template <class HashedObj>
        void QuadraticHashTable<HashedObj>::makeEmpty( )
        {
            currentSize = 0;
            for( int i = 0; i < 200000; i++ )
            {

		    // ACTIVE --> NULL
	   // if (array[ i ]/*.info*/ == NULL)
	    //{    
              //  delete [] array[ i ]/*.element*/;
	    //}
	       
		   array[i] = NULL;
	    }
        }

        /**
         * Deep copy.
         */
        template <class HashedObj>
        const QuadraticHashTable<HashedObj> & QuadraticHashTable<HashedObj>::
        operator=( const QuadraticHashTable<HashedObj> & rhs )
        {
            if( this != &rhs )
            {
                array = rhs.array;
                currentSize = rhs.currentSize;
            }
            return *this;
        }


        /**
         * Return true if currentPos exists and is active.
         */
        //template <class HashedObj>
        //bool QuadraticHashTable<HashedObj>::isActive( int currentPos) const
        //{
		// ACTIVE --> NULL
         //   return array[ currentPos ]/*.info*/ == NULL;
       // }

        /**
         * A hash routine for string objects.
         */
        template <class HashedObj>
        int QuadraticHashTable<HashedObj>::hash( const char* key, int tableSize) const
        {
            int hashVal = 0;

            for( int i = 0; key[i] != '\0'; i++ )
                hashVal = 37 * hashVal + key[ i ];

            hashVal %= tableSize;
            if( hashVal < 0 )
                hashVal += tableSize;

            return hashVal;
        }


        /**
         * A hash routine for ints.
         */
/*
         template <class HashedObj>
        int QuadraticHashTable<HashedObj>::hash( const char key, int tableSize ) const
        {
            if( key < 0 ) key = -key;
            return key % tableSize;
        }
*/
