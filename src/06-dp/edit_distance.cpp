int edit_dist(string &s1, string &s2, int m, int n) {
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0) return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;
 
    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (s1[m - 1] == s2[n - 1])
        return edit_dist(s1, s2, m - 1, n - 1);
 
    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1 + min({
        edit_dist(s1, s2, m, n - 1),    // Insert
        edit_dist(s1, s2, m - 1, n),    // Remove
        edit_dist(s1, s2, m - 1, n - 1) // Replace
    });
}