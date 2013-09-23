/***************************************************************************
                        frames_io.h -  description
                       -------------------------
    begin                : June 2006
    copyright            : (C) 2006 Erwin Aertbelien
    email                : firstname.lastname@mech.kuleuven.ac.be

 History (only major changes)( AUTHOR-Description ) :

 Ruben Smits - Added output for jacobian and jntarray 06/2007

 ***************************************************************************
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place,                                    *
 *   Suite 330, Boston, MA  02111-1307  USA                                *
 *                                                                         *
 ***************************************************************************/
/**
//
// \file
//      Defines routines for I/O of Frame and related objects.
// \verbatim
//      Spaces, tabs and newlines do not have any importance.
//      Comments are allowed C-style,C++-style, make/perl/csh -style
//      Description of the I/O :
//        Vector  : OUTPUT : e.g. [10,20,30]
//                  INPUT  :
//                         1) [10,20,30]
//                         2) Zero
//        Twist   : e.g. [1,2,3,4,5,6]
//           where [1,2,3] is velocity vector
//           where [4,5,6] is rotational velocity vector
//        Wrench  : e.g. [1,2,3,4,5,6]
//           where [1,2,3] represents a force vector
//           where [4,5,6] represents a torque vector
//        Rotation : output :
//                 [1,2,3;
//                  4,5,6;
//                  7,8,9] cfr definition of Rotation object.
//                  input :
//                    1) like the output
//                    2) EulerZYX,EulerZYZ,RPY word followed by a vector, e.g. :
//                        Eulerzyx[10,20,30]
//                   (ANGLES are always expressed in DEGREES for I/O)
//                   (ANGELS are always expressed in RADIANS for internal representation)
//                    3) Rot [1,2,3] [20]  Rotates around axis [1,2,3] with an angle
//                   of 20 degrees.
//                    4) Identity          returns identity rotation matrix.
//       Frames   : output : [ Rotationmatrix positionvector ]
//                   e.g. [ [1,0,0;0,1,0;0,0,1] [1,2,3] ]
//                  Input  :
//                     1) [ Rotationmatrix positionvector ]
//                     2) DH [ 10,10,50,30]  Denavit-Hartenberg representation
//                     ( is in fact not the representation of a Frame, but more
//                       limited, cfr. documentation of Frame object.)
//  \endverbatim
//
// \warning
//   You can use iostream.h or iostream header files for file I/O,
//   if one declares the define WANT_STD_IOSTREAM then the standard C++
//   iostreams headers are included instead of the compiler-dependent version
//
 *
 ****************************************************************************/
#ifndef FRAMES_IO_H
#define FRAMES_IO_H

#include "kdl-config.h"

#include "utilities/utility_io.h"
#include "frames.hpp"
#include "jntarray.hpp"
#include "jacobian.hpp"

namespace KDL {

    //! width to be used when printing variables out with frames_io.h
    //! global variable, can be changed.


    // I/O to C++ stream.
    KDL_API std::ostream& operator << (std::ostream& os,const Vector& v);
    KDL_API std::ostream& operator << (std::ostream& os,const Rotation& R);
    KDL_API std::ostream& operator << (std::ostream& os,const Frame& T);
    KDL_API std::ostream& operator << (std::ostream& os,const Twist& T);
    KDL_API std::ostream& operator << (std::ostream& os,const Wrench& T);
    KDL_API std::ostream& operator << (std::ostream& os,const Vector2& v);
    KDL_API std::ostream& operator << (std::ostream& os,const Rotation2& R);
    KDL_API std::ostream& operator << (std::ostream& os,const Frame2& T);



    KDL_API std::istream& operator >> (std::istream& is,Vector& v);
    KDL_API std::istream& operator >> (std::istream& is,Rotation& R);
    KDL_API std::istream& operator >> (std::istream& is,Frame& T);
    KDL_API std::istream& operator >> (std::istream& os,Twist& T);
    KDL_API std::istream& operator >> (std::istream& os,Wrench& T);
    KDL_API std::istream& operator >> (std::istream& is,Vector2& v);
    KDL_API std::istream& operator >> (std::istream& is,Rotation2& R);
    KDL_API std::istream& operator >> (std::istream& is,Frame2& T);


} // namespace Frame

#endif
