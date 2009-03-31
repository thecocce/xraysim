/* 
 * File:   include.hpp
 * Author: uli
 *
 * Created on 27. März 2009, 22:05
 */

#ifndef _INCLUDE_HPP
#define	_INCLUDE_HPP

//Constant decs
#define FIELD_DELIM ',' //Character that separates 2 values in the data file

//Includes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/multi_array.hpp>

using namespace std;
using namespace boost;

struct extents_3d_t
{
    uint x;
    uint y;
    uint z;
};

#endif	/* _INCLUDE_HPP */

