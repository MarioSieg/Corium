#include <fstream>
#include <filesystem>

#include "../TestBase.hpp"

TEST(IniFile, Write)
{
	{
		IniFile file{};
		file.PushSection("Values");
		file.PushValue("Age", 10LL);
		file.PushValue("Symver", "Hello");
		file.PushValue("Pi", 3.1415);
		ASSERT_TRUE(file.SerializeToDisk("Test.ini"));
		ASSERT_TRUE(std::filesystem::exists("Test.ini"));
	}
	std::ifstream file{ "Test.ini" };
	ASSERT_TRUE(file);
	const std::string content{ (std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>() };
	ASSERT_EQ(content, Format("[Values]\n{}Age = 10\n{}Symver = Hello\n{}Pi = 3.1415\n\n", IniFile::SECTION_CONTENT_INDENTATION, IniFile::SECTION_CONTENT_INDENTATION, IniFile::SECTION_CONTENT_INDENTATION));
	file.close();
	std::filesystem::remove("Test.ini");
	ASSERT_FALSE(std::filesystem::exists("Test.ini"));
}
