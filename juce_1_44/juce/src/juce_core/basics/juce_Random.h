/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-7 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

#ifndef __JUCE_RANDOM_JUCEHEADER__
#define __JUCE_RANDOM_JUCEHEADER__


//==============================================================================
/**
    A simple pseudo-random number generator.
*/
class JUCE_API  Random
{
public:
    //==============================================================================
    /** Creates a Random object based on a seed value.

        For a given seed value, the subsequent numbers generated by this object
        will be predictable, so a good idea is to set this value based
        on the time, e.g.

        new Random (Time::currentTimeMillis())
    */
    Random (const int64 seedValue) throw();

    /** Destructor. */
    ~Random() throw();

    /** Returns the next random 32 bit integer.

        @returns a random integer from the full range 0x80000000 to 0x7fffffff
    */
    int nextInt() throw();

    /** Returns the next random number, limited to a given range.

        @returns a random integer between 0 (inclusive) and maxValue (exclusive).
    */
    int nextInt (const int maxValue) throw();

    /** Returns the next 64-bit random number.

        @returns a random integer from the full range 0x8000000000000000 to 0x7fffffffffffffff
    */
    int64 nextInt64() throw();

    /** Returns the next random floating-point number.

        @returns a random value in the range 0 to 1.0
    */
    float nextFloat() throw();

    /** Returns the next random floating-point number.

        @returns a random value in the range 0 to 1.0
    */
    double nextDouble() throw();

    /** Returns the next random boolean value.
    */
    bool nextBool() throw();

    //==============================================================================
    /** To avoid the overhead of having to create a new Random object whenever
        you need a number, this is a shared application-wide object that
        can be used.

        It's not thread-safe though, so threads should use their own Random object.
    */
    static Random& getSystemRandom() throw();

    /** Resets this Random object to a given seed value. */
    void setSeed (const int64 newSeed) throw();

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    int64 seed;
};


#endif   // __JUCE_RANDOM_JUCEHEADER__