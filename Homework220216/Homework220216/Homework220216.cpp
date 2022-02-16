// Homework220216.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <algorithm>

class GameServerString
{
public:
	static void Replace(std::string& source, const std::string& find_string, const std::string& replace_string, int replace_count = 0);
	static void Insert(std::string& source, int index, const std::string& insert_text);
	static void TrimRemove(std::string& source);
	static void ToUpper(std::string& source);
	static void Remove(std::string& source, const std::string& delete_text);
};

/*
 * replace_count가 0인 경우 처음부터 끝까지 전부 찾아서 변경하고
 * 1 이상의 값인 경우 source에서 find_string을 replace_count 만큼 찾아서 변경.
 * 0 보다 작은 값의 경우에도 0일 경우와 동일하게 동작.
 */
void GameServerString::Replace(std::string& source, const std::string& find_string, const std::string& replace_string, int replace_count)
{
	std::string::size_type string_pos = 0;
	int count = 0;

	while ((string_pos = source.find(find_string)) != std::string::npos)
	{
		source.replace(string_pos, find_string.length(), replace_string);

		if (++count == replace_count)
		{
			break;
		}
	}
}

void GameServerString::Insert(std::string& source, int index, const std::string& insert_text)
{
	source.insert(index, insert_text);
}

// ' ' 공백제거
void GameServerString::TrimRemove(std::string& source)
{
	Replace(source, " ", "");
}

// 한글이 섞여있어도 알파벳 전부 upper
void GameServerString::ToUpper(std::string& source)
{
	std::transform(source.begin(), source.end(), source.begin(), 
		[](char word)
		{
			/*
			 * __NTH (toupper (int __c))
			 * {
			 *	return __c >= -128 && __c < 256 ? (*__ctype_toupper_loc ())[__c] : __c;
			 * }
			 */
			return static_cast<char>(std::toupper(word));
		});
}

void GameServerString::Remove(std::string& source, const std::string& delete_text)
{
	Replace(source, delete_text, "");
}

int main()
{
	std::string test_string = "오늘은 오늘은 정말 힘들었다";
	GameServerString::Replace(test_string, "오늘은", "내일은");
	std::cout << test_string << std::endl;
	GameServerString::Replace(test_string, "내일은", "어제는", 1000);
	std::cout << test_string << std::endl;

	std::string test_string_1 = "오늘은 오늘은 정말 힘들었다";
	GameServerString::Replace(test_string_1, "오늘은", "내일은", 1);
	std::cout << test_string_1 << std::endl;
	GameServerString::Replace(test_string_1, "오늘은", "내일은", -1);
	std::cout << test_string_1 << std::endl;

	GameServerString::Insert(test_string_1, 14, "정말 ");
	std::cout << test_string_1 << std::endl;

	GameServerString::TrimRemove(test_string_1);
	std::cout << test_string_1 << std::endl;

	GameServerString::Remove(test_string_1, "내일은");
	std::cout << test_string_1 << std::endl;


	std::string KoreanTest = "하하ㄴ haha ㅇ하하";
	GameServerString::ToUpper(KoreanTest);
	std::cout << KoreanTest << std::endl;
}