// HomeworkBase_Class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int CheckPoint(const std::string& ipText)
{
	int count = 0;
	for (const char i : ipText)
	{
		if (i == '.')
			++count;
	}

	return count;
}

bool IsPortNumber(const std::string& ipText)
{
	return std::string::npos != ipText.find(':');
}

std::vector<std::string> CutIp(const std::string& ipText, char cutChar)
{
	std::vector<std::string> ips;
	ips.emplace_back();

	for (const char text : ipText)
	{
		if (text == cutChar)
		{
			ips.emplace_back();
			continue;
		}

		ips.back() += text;
	}

	return ips;
}

bool IsNumberStr(const std::string& number)
{
	for (const char num : number)
	{
		if (0 == isdigit(num))
			return false;
	}

	return true;
}

bool CheckIp(const std::string& ipText)
{
	std::vector<std::string> vecIp = CutIp(ipText, '.');

	if (4 != vecIp.size())
		return false;

	// 숫자인지 아닌지 구분한다
	for (const auto & ip : vecIp)
	{
		if (ip.empty())
			return false;
	}

	for (const auto & ip : vecIp)
	{
		if (false == IsNumberStr(ip))
			return false;

		const int value = std::stoi(ip);
		if (0 > value || value > 256)
			return false;
	}

	return true;
}

int main()
{
	std::string resultIp;
	std::string resultPort;

	std::string ip;
	while (true)
	{
		std::cout << "IP 주소를 입력해주세요" << std::endl;
		std::cin >> ip;

		if (3 != CheckPoint(ip))
			continue;

		if (true == IsPortNumber(ip))
		{
			// 포트와 ip 분리
			std::vector<std::string> vecIpAndPort = CutIp(ip, ':');

			resultIp = vecIpAndPort[0];
			resultPort = vecIpAndPort[1];
		}
		else
		{
			if (true == CheckIp(ip))
			{
				resultIp = ip;
				break;
			}
		}
	}

	while (resultPort.empty())
	{
		/* ... */
	}
}