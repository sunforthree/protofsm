#include <stdio.h>
#include <iostream>
#include <assert.h>

#include <re2/filtered_re2.h>
#include <re2/re2.h>
#include <re2/stringpiece.h>

int main() {

    re2::FilteredRE2 f;
    int id;
    f.Add("a.*b.*c*", RE2::DefaultOptions, &id);
    std::vector<std::string> v;
    f.Compile(&v);
    std::vector<int> ids;
    f.FirstMatch("abbccc", ids);

    int n;
    if (RE2::FullMatch("axbyc", "a.*b.*c") &&
        RE2::PartialMatch("foo123var", "(\\d+)", &n) && n == 123) {
        printf("PASS\n");
        // return 0;
    }

    /* test RE2 compile rules. */
    re2::RE2 re("(aaa)(aaab)");
    assert(re.ok());
    std::cout << "re size is: " << sizeof(re) << '\n';
    std::cout << "re program size is: " << re.ProgramSize() << '\n';

    re2::StringPiece match;
    re2::StringPiece match2;
    if (RE2::FullMatch("192.168.1.1", "\\d+.\\d*[L][-]\\d*\\s[A-Z]*[/]\\d*", &match)) {
        if (match.size() != 0)
            std::cout << "match is: " << match << '\n';
        if (match2.size() != 0)
            std::cout << "match2 is: " << match2 << '\n';
    }

    printf("FAIL\n");
    return 0;
}