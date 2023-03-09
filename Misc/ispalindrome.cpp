bool is_palindrome(const string &str) {
    for (int a = 0, b = int(str.size()) - 1; a < b; a++, b--)
        if (str[a] != str[b])
            return false;

    return true;
}