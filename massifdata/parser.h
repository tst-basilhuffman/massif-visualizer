/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef MASSIF_PARSER_H
#define MASSIF_PARSER_H

class QIODevice;

namespace Massif {

class FileData;

/**
 * This class parses a Massif output file and stores it's information.
 */
class Parser
{
public:
    Parser();
    ~Parser();

    /**
     * Parse @p file and return a FileData structure representing the data.
     *
     * @note The caller has to delete the data afterwards.
     */
    FileData* parse(QIODevice* file);
};

}

#endif // MASSIF_PARSER_H
