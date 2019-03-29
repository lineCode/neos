/*
  language.cpp

  Copyright (c) 2019 Leigh Johnston.  All Rights Reserved.

  This program is free software: you can redistribute it and / or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <neos/language/concept.hpp>
#include "language.hpp"

namespace neos
{
    namespace concept
    {
        namespace core
        {   
            language::language(neos::language::i_concept_library& aParent) :
                neos::language::concept_library
                { 
                    aParent,
                    library_id(), 
                    aParent.uri().to_std_string(),
                    library_name(), 
                    "Core language concepts", 
                    neolib::version{ 1, 0, 0 }, 
                    "Copyright (c) 2019 Leigh Johnston.  All Rights Reserved."
                }
            {
                /* todo */
                concepts()[neolib::string{ "language.whitespace" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.whitespace");
                concepts()[neolib::string{ "language.character" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character");
                /* todo: make next concepts child of above concept */
                concepts()[neolib::string{ "language.character.utf8" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8");
                /* todo: make next concepts children of above concept */
                concepts()[neolib::string{ "language.character.utf8.LF" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.LF");
                concepts()[neolib::string{ "language.character.utf8.CR" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.CR");
                concepts()[neolib::string{ "language.character.utf8.TAB" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.TAB");
                concepts()[neolib::string{ "language.character.utf8.EOF" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.EOF");
                concepts()[neolib::string{ "language.character.utf8.digit" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.digit");
                concepts()[neolib::string{ "language.character.utf8.hexdigit" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.character.utf8.hexdigit");
                concepts()[neolib::string{ "language.statement" }] = neolib::make_ref<neos::language::unimplemented_concept>("language.statement");
                // aliases
                concepts()[neolib::string{ "language.character" }] = concepts()[neolib::string{ "language.character.utf8" }];
                concepts()[neolib::string{ "language.character.LF" }] = concepts()[neolib::string{ "language.character.utf8.LF" }];
                concepts()[neolib::string{ "language.character.CR" }] = concepts()[neolib::string{ "language.character.utf8.CR" }];
                concepts()[neolib::string{ "language.character.TAB" }] = concepts()[neolib::string{ "language.character.utf8.TAB" }];
                concepts()[neolib::string{ "language.character.EOF" }] = concepts()[neolib::string{ "language.character.utf8.EOF" }];
                concepts()[neolib::string{ "language.character.digit" }] = concepts()[neolib::string{ "language.character.utf8.digit" }];
                concepts()[neolib::string{ "language.character.hexdigit" }] = concepts()[neolib::string{ "language.character.utf8.hexdigit" }];
            }

            const std::string& language::library_name()
            {
                static const std::string sName = "neos.language";
                return sName;
            }

            const neolib::uuid& language::library_id()
            {
                static const neolib::uuid sId = neolib::make_uuid("C33C5C53-937B-434B-A3F9-C2A1BB71D391");
                return sId;
            }
        }
    }
}

