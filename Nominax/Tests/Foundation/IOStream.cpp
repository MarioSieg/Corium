#include "../TestBase.hpp"

TEST(IOStream, CAccessModeProxy_WB)
{
	ASSERT_STREQ(std::data(IOStream::GetCAccessModeProxy(FileAccessMode::Write, FileContentMode::Binary)), "wb");
}

TEST(IOStream, CAccessModeProxy_WT)
{
	ASSERT_STREQ(std::data(IOStream::GetCAccessModeProxy(FileAccessMode::Write, FileContentMode::Text)), "wt");
}

TEST(IOStream, CAccessModeProxy_RB)
{
	ASSERT_STREQ(std::data(IOStream::GetCAccessModeProxy(FileAccessMode::Read, FileContentMode::Binary)), "rb");
}

TEST(IOStream, CAccessModeProxy_RT)
{
	ASSERT_STREQ(std::data(IOStream::GetCAccessModeProxy(FileAccessMode::Read, FileContentMode::Text)), "rt");
}

TEST(IOStream, AccessModes)
{
	const auto executor
	{
		[]
		{
			IOStream stream { "test.bin", FileAccessMode::Write, FileContentMode::Binary };
			ASSERT_EQ(stream.GetAccessMode(), FileAccessMode::Write);
			ASSERT_EQ(stream.GetContentMode(), FileContentMode::Binary);
			ASSERT_TRUE(stream.IsWriteable());
			ASSERT_FALSE(stream.IsReadable());
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	ASSERT_TRUE(std::filesystem::exists("test.bin"));
	std::filesystem::remove("test.bin");
}

TEST(IOStream, Open_WriteBinary)
{
	const auto executor
	{
		[]
		{
			IOStream stream { "Test.bin", FileAccessMode::Write, FileContentMode::Binary };
			ASSERT_EQ(stream.GetAccessMode(), FileAccessMode::Write);
			ASSERT_EQ(stream.GetContentMode(), FileContentMode::Binary);
			ASSERT_TRUE(stream.IsWriteable());
			ASSERT_FALSE(stream.IsReadable());
			ASSERT_NE(*stream, nullptr);
			ASSERT_TRUE(stream.WriteUnchecked(3));
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	ASSERT_TRUE(std::filesystem::exists("Test.bin"));
	std::filesystem::remove("Test.bin");
}

TEST(IOStream, Open_WriteText)
{
	const auto executor
	{
		[]
		{
			IOStream stream { "Test.txt", FileAccessMode::Write, FileContentMode::Text };
			ASSERT_EQ(stream.GetAccessMode(), FileAccessMode::Write);
			ASSERT_EQ(stream.GetContentMode(), FileContentMode::Text);
			ASSERT_TRUE(stream.IsWriteable());
			ASSERT_FALSE(stream.IsReadable());
			ASSERT_NE(*stream, nullptr);
			ASSERT_TRUE(stream.WriteUnchecked(3));
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	ASSERT_TRUE(std::filesystem::exists("Test.txt"));
	std::filesystem::remove("Test.txt");
}

TEST(IOStream, Open_NativeHandle)
{
	const auto executor
	{
		[]
		{
			FILE* const f { fopen("Test.txt", "wt")};
			ASSERT_TRUE(f);
			IOStream s { *f };
			ASSERT_EQ(*s, f);
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	ASSERT_TRUE(std::filesystem::exists("Test.txt"));
	std::filesystem::remove("Test.txt");
}

TEST(IOStream, Open_WriteReadBinary)
{
	const auto executor
	{
		[]
		{
			{
				IOStream stream { "Test.bin", FileAccessMode::Write, FileContentMode::Binary };
				ASSERT_TRUE(stream.WriteUnchecked(3));
			}
			ASSERT_TRUE(std::filesystem::exists("Test.bin"));
			{
				IOStream stream { "Test.bin", FileAccessMode::Read, FileContentMode::Binary };
				int x { };
				ASSERT_TRUE(stream.ReadUnchecked(x));
				ASSERT_EQ(x, 3);
			}
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	std::filesystem::remove("Test.bin");
}

TEST(IOStream, Open_WriteReadText)
{
	const auto executor
	{
		[]
		{
			{
				IOStream stream { "Test.txt", FileAccessMode::Write, FileContentMode::Text };
				ASSERT_TRUE(stream.WriteUnchecked("Hello\n"));
			}
			ASSERT_TRUE(std::filesystem::exists("Test.txt"));
			{
				IOStream stream { "Test.txt", FileAccessMode::Read, FileContentMode::Text };

				std::array<char, 32> blob { };
				std::uint64_t size { };
				ASSERT_TRUE(stream.ReadLine(blob, size));
				ASSERT_EQ(size, 5);
				ASSERT_EQ(blob[0], 'H');
				ASSERT_EQ(blob[1], 'e');
				ASSERT_EQ(blob[2], 'l');
				ASSERT_EQ(blob[3], 'l');
				ASSERT_EQ(blob[4], 'o');
			}
		}
	};
	ASSERT_NO_FATAL_FAILURE(executor());
	std::filesystem::remove("Test.txt");
}
