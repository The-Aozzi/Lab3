#include <iostream>
#include <vector>
#include <string>


/**
 * @brief Checks if the given string is an acronym of the given words.
 * 
 * @param str The string to check if it's an acronym.
 * @param words A vector of strings containing the words that form the acronym.
 *  
 * @return `true` if the given string is an acronym of the given words, `false` otherwise.
 */
bool isAcronym(std::string str, std::vector<std::string> words)
{
    if (str.size() != words.size())
        return false;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != words[i][0])
            return false;
    }
    return true;
}

/**
 * @brief Checks if the given string is a palindrome, excluding space character.
 * 
 * @param str The string to check if it's a palindrome.
 * 
 * @return `true` if the given string is a palindrome, `false` otherwise.
 */
bool isPalindrom(std::string str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            ++left;
            --right;
        }
        else if (str[left] == ' ' || str[right] == ' ')
        {
            left += str[left] == ' ';
            right -= str[right] == ' ';
        }
        else
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Calculates the maximum score among the given words that are constructable from the given letters.
 * 
 * @param words A vector of words that can be constructed.
 * @param letters A vector of letters that can be used to construct words.
 * @param score The score each letter contributes to the constructed word.
 * 
 * @return The maximum possible score for a word. If neither of the words is constructible from the given letters returns `-1`.
*/
int maxScore(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score)
{
    int max_score = -1;
    int current_score = 0;
    std::vector<int> letter_count(26, 0);
    for (char ch : letters)
    {
        letter_count[ch - 'a']++;
    }

    for (const std::string &word : words)
    {
        int current_score = 0;
        std::vector<int> letter_count_for_word(26, 0);
        int i;
        for (i = 0; i < word.size(); ++i)
        {
            if (letter_count_for_word[word[i] - 'a'] == letter_count[word[i] - 'a'])
                break;
            letter_count_for_word[word[i] - 'a']++;
            current_score += score[word[i] - 'a'];
        }
        if (i == word.size())
        {
            max_score = std::max(max_score, current_score);
        }
    }
    return max_score;
}

int main(int, char **)
{
    std::cout << std::boolalpha;

    std::cout << isAcronym("tpu", {"tomsk", "polytechnic", "university"}) << std::endl;
    std::cout << isAcronym("tpu", {"tomsk", "state", "university"}) << std::endl;

    std::cout << isPalindrom("never    odd       or  even") << std::endl;
    std::cout << isPalindrom("never   even      or      odd") << std::endl;

    std::cout << maxScore({"ab", "ac", "bc"}, {'a', 'b', 'c'}, {1, 3, 2}) << std::endl;
    std::cout << maxScore({"ab", "ac", "bc"}, {'x', 'y', 'z'}, {2, 3, 1}) << std::endl;
}
