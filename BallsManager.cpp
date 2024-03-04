#include <iostream>

const int NUM_BALLS = 20;
int totalBallsCount = 0;
int balls[NUM_BALLS] = { 0 };

int main()
{
    bool shouldContinue = true;
    while (shouldContinue)
    {
        std::cout << "List of commands:" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "1 - Add ball" << std::endl;
        std::cout << "2 - Remove ball" << std::endl;
        std::cout << "3 - Get ball according to the article number" << std::endl;
        std::cout << "4 - Total balls count" << std::endl;
        std::cout << "5 - Balls that are missing" << std::endl;
        std::cout << ">: ";
        std::string command;
        std::cin >> command;

        if (command == "1")
        {
            int add = -1;
            std::cout << "Enter the article number you want to add" << std::endl;
            std::cin >> add;
            if (add < 0 || add >= NUM_BALLS)
            {
                std::cout << "Invalid article number!" << std::endl;
            }
            else if (balls[add] != 0)
            {
                std::cout << "Balls already exist for article " << add << std::endl;
            }
            else
            {
                balls[add] = 1;
                std::cout << "Ball added for article " << add << std::endl;
            }
        }
        else if (command == "2")
        {
            int remove = -1;
            std::cout << "Enter the article number you want to remove" << std::endl;
            std::cin >> remove;
            if (remove < 0 || remove >= NUM_BALLS)
            {
                std::cout << "Invalid article number!" << std::endl;
            }
            else if (balls[remove] == 0)
            {
                std::cout << "No balls found for article " << remove << std::endl;
            }
            else
            {
                balls[remove] = 0;
                std::cout << "Ball removed for article " << remove << std::endl;
            }
        }
        else if (command == "3")
        {
            int article = -1;
            std::cout << "Enter the article number you want to get" << std::endl;
            std::cin >> article;
            if (article < 0 || article >= NUM_BALLS)
            {
                std::cout << "Invalid article number!" << std::endl;
            }
            else
            {
                std::cout << "There " << (balls[article] == 0 ? "are no" : "is one") << " ball" << " of article " << article << std::endl;
            }
        }
        else if (command == "4")
        {
            totalBallsCount = 0;
            for (int i = 0; i < NUM_BALLS; i++)
            {
                if (balls[i] != 0)
                {
                    totalBallsCount++;
                }
            }
            std::cout << "Total balls count is: " << totalBallsCount << std::endl;
        }
        else if (command == "5")
        {
            std::cout << "Balls that are missing:" << std::endl;
            for (int i = 0; i < NUM_BALLS; ++i)
            {
                if (balls[i] == 0)
                {
                    std::cout << "Article " << i << std::endl;
                }
            }
        }
        else if (command == "0")
        {
            std::cout << "Bye!" << std::endl;
            break;
        }
        else
        {
            std::cout << "Unknown command " << command << std::endl;
        }
    }

    return 0;
}