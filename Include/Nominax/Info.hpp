#pragma once

#include <cstdint>
#include <ostream>
#include <string_view>

namespace Nominax {
	struct Version final {
		std::uint8_t Major{};
		std::uint8_t Minor{};
		std::uint8_t Build{};
		std::uint8_t Revision{};
	};

	constexpr Version SYSTEM_VERSION{
		.Major = 0,
		.Minor = 4,
		.Build = 0,
		.Revision = 0,
	};

	inline auto operator <<(std::ostream& out, const Version version) -> std::ostream& {
		return out << static_cast<std::uint16_t>(version.Major) << '.' << static_cast<std::uint16_t>(version.Minor) << '.' << static_cast<std::uint16_t>(version.Build) << '.' << static_cast<std::uint16_t>(version.Revision);
	}
	
	constexpr std::string_view SYSTEM_COPYRIGHT_TEXT = 
		"(c) Copyright Mario Sieg <pinsrq> mt3000@gmx.de 2019-2021! All rights reserved!\n"
		"The Nominax runtime system is open source software: https://github.com/MarioSieg/NominaX\n"
		"See LICENSE file for licensing and copyright information!\n";
	
	constexpr std::string_view SYSTEM_LOGO_TEXT = R"(
                                                         #@@#   
                                                      %@@@@@@@@@
                                                     .@@@    (@@
                                                            &@@@
                                                          /@@@  
                                                         @@@*   
                                                       @@@@@@@@@
   @@@@@@@&             /@@@@@@@*           #@@@@@@@            
  ,@@@@@@@@@/            @@@@@@@@@         @@@@@@@@@            
  ,@@@@@@@@@@@            *@@@@@@@@@     @@@@@@@@@              
  ,@@@@@@@@@@@@@            @@@@@@@@@& @@@@@@@@@%               
  ,@@@@@@@@@@@@@@#            @@@@@@@@@@@@@@@@@                 
  ,@@@@@@@@@@@@@@@@            .@@@@@@@@@@@@@                   
  ,@@@@@@@@@@@@@@@@@@            %@@@@@@@@@*                    
  ,@@@@@@@(  #@@@@@@@@@         (@@@@@@@@@@@,                   
  ,@@@@@@@(    @@@@@@@@@*      @@@@@@@@@@@@@@@                  
  ,@@@@@@@(      @@@@@@@@@   @@@@@@@@@@@@@@@@@@@                
  ,@@@@@@@(       /@@@@@@@@@@@@@@@@@&   @@@@@@@@@(              
  ,@@@@@@@(         @@@@@@@@@@@@@@@       @@@@@@@@@             
  ,@@@@@@@(           @@@@@@@@@@@          .@@@@@@@@@           
                                          
     _   _  ___  __  __ ___ _   _    _   __  __
    | \ | |/ _ \|  \/  |_ _| \ | |  / \  \ \/ /
    |  \| | | | | |\/| || ||  \| | / _ \  \  / 
    | |\  | |_| | |  | || || |\  |/ ___ \ /  \
    |_| \_|\___/|_|  |_|___|_| \_/_/   \_/_/\_\

)";
}
