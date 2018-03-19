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

#ifndef __JUCE_APPLICATIONCOMMANDID_JUCEHEADER__
#define __JUCE_APPLICATIONCOMMANDID_JUCEHEADER__


//==============================================================================
/** A type used to hold the unique ID for an application command.

    This is a numeric type, so it can be stored as an integer.

    @see ApplicationCommandInfo, ApplicationCommandManager,
         ApplicationCommandTarget, KeyPressMappingSet
*/
typedef int CommandID;


//==============================================================================
/** A set of general-purpose application command IDs.

    Because these commands are likely to be used in most apps, they're defined
    here to help different apps to use the same numeric values for them.

    Of course you don't have to use these, but some of them are used internally by
    Juce - e.g. the quit ID is recognised as a command by the JUCEApplication class.

    @see ApplicationCommandInfo, ApplicationCommandManager,
         ApplicationCommandTarget, KeyPressMappingSet
*/
namespace StandardApplicationCommandIDs
{
    /** This command ID should be used to send a "Quit the App" command.

        This command is recognised by the JUCEApplication class, so if it is invoked
        and no other ApplicationCommandTarget handles the event first, the JUCEApplication
        object will catch it and call JUCEApplication::systemRequestedQuit().
    */
    static const CommandID  quit           = 0x1001;

    /** The command ID that should be used to send a "Delete" command. */
    static const CommandID  del            = 0x1002;

    /** The command ID that should be used to send a "Cut" command. */
    static const CommandID  cut            = 0x1003;

    /** The command ID that should be used to send a "Copy to clipboard" command. */
    static const CommandID  copy           = 0x1004;

    /** The command ID that should be used to send a "Paste from clipboard" command. */
    static const CommandID  paste          = 0x1005;

    /** The command ID that should be used to send a "Select all" command. */
    static const CommandID  selectAll      = 0x1006;

    /** The command ID that should be used to send a "Deselect all" command. */
    static const CommandID  deselectAll    = 0x1007;
}


#endif   // __JUCE_APPLICATIONCOMMANDID_JUCEHEADER__
