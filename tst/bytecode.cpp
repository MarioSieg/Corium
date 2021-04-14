#include "tstbase.hpp"
#include "../inc/nominax/reactor.hpp"

using namespace nominax;

TEST(instruction_db, imm_max_arg_count) {
	const auto max_imm_args = idb::max_imm_args;
	for (const auto val : idb::imm_arg_counts) {
		ASSERT_LE(val, max_imm_args);
	}
}

TEST(instruction_db, imm_arg_count) {
	ASSERT_EQ(idb::imm_arg_counts.size(), idb::imm_arg_types.size());
	for (std::size_t i = 0; i < idb::imm_arg_counts.size(); ++i) {
		std::uint8_t count = 0;
		for (const auto x : idb::imm_arg_types[i]) {
			count += x != idb::instruction_imm_arg_type::none;
		}
		ASSERT_EQ(count, idb::imm_arg_counts[i]);
	}
}