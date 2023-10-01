#include <algorithm>
#include <string>

std::string solver(std::string input)
{
    std::string alph = "eyuioaEYUIOA";
    std::string answer;
    for (int i = 0; i < input.size(); ++i)
    {
        char k = input[i];
        if (std::count(alph.begin(), alph.end(), k) == 0)
        {
            answer += k;
        }
    }
    return answer;
}