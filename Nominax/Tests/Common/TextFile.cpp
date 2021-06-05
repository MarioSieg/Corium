#include "../TestBase.hpp"

#include <fstream>

TEST(TextFile, Construct)
{
	const TextFile file{ "hey!" };
	ASSERT_EQ(file.GetContentText(), "hey!");
	ASSERT_FALSE(file.IsEmpty());
}

TEST(TextFile, Construct2)
{
	const TextFile file{ "info.txt", "hey!" };
	ASSERT_EQ(file.GetContentText(), "hey!");
	ASSERT_EQ(file.GetFilePath(), "info.txt");
}

TEST(TextFile, Construct3)
{
	const TextFile file{ };
	ASSERT_TRUE(file.IsEmpty());
}

TEST(TextFile, SizeCapacityBytes)
{
	const TextFile file{ "hey!" };
	ASSERT_EQ(file.GetCapacity(), std::string("hey!").capacity());
	ASSERT_EQ(file.GetSize(), std::string("hey!").size());
	ASSERT_EQ(file.GetSizeInBytes(), std::string("hey!").capacity() * sizeof(char));
}

TEST(TextFile, MoveConstruct)
{
	TextFile file{ "hey!" };
	const TextFile file2{ std::move(file) };
	ASSERT_EQ(file2.GetContentText(), "hey!");
}

TEST(TextFile, MoveAssign)
{
	TextFile file{ "hey!" };
	const TextFile file2 = std::move(file);
	ASSERT_EQ(file2.GetContentText(), "hey!");
}

TEST(TextFile, Write)
{
	TextFile file{ "test&*%$!" };
	ASSERT_TRUE(file.WriteToFile("TestTextFile.txt"));
	ASSERT_EQ(file.GetFilePath(), "TestTextFile.txt");
	ASSERT_TRUE(std::filesystem::is_regular_file("TestTextFile.txt"));
	std::ifstream in{ "TestTextFile.txt" };
	ASSERT_TRUE(in);
	const std::string str((std::istreambuf_iterator<char>(in)),
		std::istreambuf_iterator<char>());
	ASSERT_EQ(str, "test&*%$!");
}

TEST(TextFile, Read)
{
	{
		TextFile file{ "test&*%$!" };
		ASSERT_TRUE(file.WriteToFile("TestTextFile.txt"));
		ASSERT_TRUE(std::filesystem::is_regular_file("TestTextFile.txt"));
	}

	TextFile file{};
	ASSERT_TRUE(file.ReadFromFile("TestTextFile.txt"));
	ASSERT_EQ(file.GetFilePath(), "TestTextFile.txt");
	ASSERT_EQ(file.GetContentText(), "test&*%$!");
}

TEST(TextFile, Iterator)
{
	TextFile file{ "hey!" };
	for(auto i{ 0 }; const char x : file)
	{
		ASSERT_EQ(x, "hey!"[i++]);
	}
}

TEST(TextFile, EraseSpaces)
{
	TextFile file{ "Gestatten,\tmein Name ist\rMario Sieg!\n" };
	file.EraseSpaces();
	ASSERT_EQ(file.GetContentText(), "Gestatten,\tmeinNameist\rMarioSieg!\n");
}

TEST(TextFile, EraseCtrl)
{
	TextFile file{ "Gestatten,\tmein Name ist\rMario Sieg!\n" };
	file.EraseSpacesAndControlChars();
	ASSERT_EQ(file.GetContentText(), "Gestatten,meinNameistMarioSieg!");
}

TEST(TextFile, EraseChar)
{
	TextFile file{ "Gestatten,\tmein Name ist\rMario Sieg!\n" };
	file.Erase('e');
	ASSERT_EQ(file.GetContentText(), "Gstattn,\tmin Nam ist\rMario Sig!\n");
}

TEST(TextFile, SubStringIndex)
{
	const TextFile file{ "** Hey cutie! **" };
	ASSERT_EQ(file.SubString(0, 15), "** Hey cutie! **");
	ASSERT_EQ(file.SubString(0, 0), "*");
	ASSERT_EQ(file.SubString(1, 3), "* H");
}

TEST(TextFile, SubStringChar)
{
	const TextFile file{ "** Hey cutie! **" };
	ASSERT_EQ(file.SubStringChar('*', '*'), "**");
	ASSERT_EQ(file.SubStringChar('*', '!'), "** Hey cutie!");
}

TEST(TextFile, EraseSubString)
{
	TextFile file{ "** Hey cutie! **" };
	file.EraseRange('*', '!');
	ASSERT_EQ(file.GetContentText(), " **");
}
