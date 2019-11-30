#include <cbdd.h>
#include "libft.h"
#define EQUAL_STRING_FREE(expected, input) temp = input;\
                                                  expect_equal_string(expected, temp);\
                                                  free(temp);

int main() {
  __block char *str;
  __block char *temp; 
  describe("strtrim", ^{
    before_each(^{
      str = "hi";
    });

    it("Simple tests", ^{
            EQUAL_STRING_FREE("hello", ft_strtrim("      hello"));
            EQUAL_STRING_FREE("hello", ft_strtrim("hello"));
            EQUAL_STRING_FREE("hello", ft_strtrim("hello      "));
            EQUAL_STRING_FREE("hello", ft_strtrim("      hello       "));
    });

    it("Whitespace in string", ^{
        EQUAL_STRING_FREE("h e l l o", ft_strtrim("  h e l l o  "));
        EQUAL_STRING_FREE("h    o", ft_strtrim("h    o"));
    });
    it("Empty string", ^{
        EQUAL_STRING_FREE("", ft_strtrim(""));
        EQUAL_STRING_FREE("", ft_strtrim("    "));
    });
  });
  return 0;
}
