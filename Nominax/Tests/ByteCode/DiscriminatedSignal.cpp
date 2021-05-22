#include "../TestBase.hpp"

TEST(DiscriminatedSignal, MapStreamType)
{
	ASSERT_EQ(MapStreamType<Instruction>().value(), Signal::Discriminator::Instruction);
	ASSERT_EQ(MapStreamType<SystemIntrinsicCallID>().value(), Signal::Discriminator::SystemIntrinsicCallID);
	ASSERT_EQ(MapStreamType<UserIntrinsicCallID>().value(), Signal::Discriminator::UserIntrinsicCallID);
	ASSERT_EQ(MapStreamType<JumpAddress>().value(), Signal::Discriminator::JumpAddress);
	ASSERT_EQ(MapStreamType<U64>().value(), Signal::Discriminator::U64);
	ASSERT_EQ(MapStreamType<I64>().value(), Signal::Discriminator::I64);
	ASSERT_EQ(MapStreamType<F64>().value(), Signal::Discriminator::F64);
	ASSERT_EQ(MapStreamType<CharClusterUtf8>().value(), Signal::Discriminator::CharClusterUtf8);
	ASSERT_EQ(MapStreamType<CharClusterUtf16>().value(), Signal::Discriminator::CharClusterUtf16);
	ASSERT_EQ(MapStreamType<CharClusterUtf32>().value(), Signal::Discriminator::CharClusterUtf32);
	ASSERT_FALSE(MapStreamType<short>().has_value());
}

TEST(DiscriminatedSignal, Contains)
{
	const DiscriminatedSignal sig{ Signal::Discriminator::F64, Signal{2.5} };
	ASSERT_TRUE(sig.Contains<F64>());
	ASSERT_TRUE(sig.Contains(2.5));
	ASSERT_FALSE(sig.Contains<I64>());
	ASSERT_FALSE(sig.Contains<I64>(2));
}

TEST(DiscriminatedSignal, Unwrap)
{
	const DiscriminatedSignal sig{ Signal::Discriminator::F64, Signal{2.5} };
	ASSERT_TRUE(sig.Unwrap<F64>().has_value());
	ASSERT_FALSE(sig.Unwrap<U64>().has_value());
	ASSERT_DOUBLE_EQ(sig.Unwrap<F64>().value(), 2.5);

	ASSERT_DOUBLE_EQ(sig.UnwrapUnchecked<F64>(), 2.5);
}

TEST(DiscriminatedSignal, Equality)
{
	const DiscriminatedSignal sig{ Signal::Discriminator::F64, Signal{2.5} };
	const DiscriminatedSignal sig2{ Signal::Discriminator::F64, Signal{2.0} };
	const DiscriminatedSignal sig3{ Signal::Discriminator::I64, Signal{-2_int} };
	ASSERT_EQ(sig, sig);
	ASSERT_EQ(sig.Discriminator, sig2.Discriminator);
	ASSERT_NE(sig, sig2);
	ASSERT_NE(sig.Discriminator, sig3.Discriminator);
	ASSERT_NE(sig, sig3);
}
