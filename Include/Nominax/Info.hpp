#pragma once

#include <cstdint>
#include <ostream>
#include <string_view>

namespace Nominax {
	struct version final {
		std::uint8_t major{};
		std::uint8_t minor{};
		std::uint8_t build{};
		std::uint8_t revision{};
	};

	constexpr version system_version{
		.major = 0,
		.minor = 4,
		.build = 0,
		.revision = 0,
	};

	inline auto operator <<(std::ostream& out, const version ver_) -> std::ostream& {
		return out << static_cast<std::uint16_t>(ver_.major) << '.' << static_cast<std::uint16_t>(ver_.minor) << '.' << static_cast<std::uint16_t>(ver_.build) << '.' << static_cast<std::uint16_t>(ver_.revision);
	}
	
	constexpr std::string_view info_notice = 
		"(c) Copyright Mario Sieg <pinsrq> mt3000@gmx.de 2019-2021! All rights reserved!\n"
		"The Nominax runtime system is open source software: https://github.com/MarioSieg/NominaX\n"
		"See LICENSE file for licensing and copyright information!\n";
	
	constexpr std::string_view logo = R"(
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
