// HomeworkBase.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
    while(true)
    {
        std::string ip;
        std::string port;

        std::cout << "IP 주소를 입력해주세요  ";
        std::cout << "(q를 입력하시면 127.0.0.1:30001로 접속합니다)" << std::endl;
        std::cin >> ip;
        system("cls");

        if ("q" == ip ||
            "Q" == ip)
        {
            ip = "127.0.0.1";
            port = "30001";
        }

        size_t ipStartPos = 0;
        bool isBreaked = false;
        for (int i = 0; i <= 3; ++i)
        {
            size_t dotPos = ip.find('.', ipStartPos);
            if (i != 3 && std::string::npos == dotPos)
            {
                std::cout << "잘못된 IP를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 IP : " << ip << std::endl;
                system("pause");
                isBreaked = true;
                break;
            }

            if (3 <= i && std::string::npos != dotPos)
            {
                std::cout << "잘못된 IP를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 IP : " << ip << std::endl;
                system("pause");
                isBreaked = true;
                break;
            }

            std::string ipTest = ip.substr(ipStartPos, dotPos - ipStartPos);
            ipStartPos = dotPos + 1;

            int ipTemp = 0;
            try
            {
                ipTemp = static_cast<int>(std::stoi(ipTest));
            }
            catch (...)
            {
                std::cout << "잘못된 IP를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 IP : " << ip << std::endl;
                system("pause");
                isBreaked = true;
                break;
            }
            
            if (0 > ipTemp || 255 < ipTemp)
            {
                std::cout << "잘못된 IP를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 IP : " << ip << std::endl;
                system("pause");
                isBreaked = true;
                break;
            }   
        }
        if (isBreaked)
        {
            system("cls");
            continue;
        }


        while (true)
        {
            size_t portPos = ip.find(':');
            if (port.empty() && std::string::npos == portPos)
            {
                std::cout << "포트 번호를 입력해주세요" << std::endl;
                std::cin >> port;
                system("cls");
            }
            else if (port.empty() && std::string::npos != portPos)
            {
                port = ip.substr(portPos + 1, ip.length() - portPos);
                ip = ip.substr(0, portPos);
            }

            int portTemp = 0;
            try
            {
                portTemp = std::stoi(port);
            }
            catch (...)
            {
                std::cout << "잘못된 포트 번호를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 포트 번호 : " << port << std::endl;
                system("pause");
                system("cls");

                port = "";
                continue;
            }

            if (65536 < portTemp || 0 > portTemp)
            {
                std::cout << "잘못된 포트 번호를 입력하였습니다" << std::endl;

                std::cout << std::endl << std::endl;
                std::cout << "입력한 포트 번호 : " << port << std::endl;
                system("pause");
                system("cls");

                port = "";
                continue;
            }

            break;
        }

        std::cout << "입력한 IP\t" << ip << std::endl;
        std::cout << "입력한 포트\t" << port << std::endl;
        system("pause");
        system("cls");
    }

    int a = 0;
}