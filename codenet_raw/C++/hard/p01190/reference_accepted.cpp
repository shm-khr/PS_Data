#include <cstdio>
#include <cctype>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>

void preprocess(const std::string &s, std::vector<std::string> &t) {
  t.clear();
  for (size_t i=0; i<s.length(); ++i) {
    if (s[i] == 'a') {
      if (s[i+1] == ' ') {
        // "a list of "
        t.push_back("(");
        i += 9;
      } else if (s[i+1] == 'n') {
        // "and "
        t.push_back("&");
        i += 3;
      } else {
        assert(false);
      }
      continue;
    }

    std::string word(1, s[i]);
    while (++i < s.length() && isupper(s[i]))
      word += s[i];

    t.push_back(word);
    if (i < s.length() && s[i] == ',') {
      ++i;
    }
  }
}

void debug(const std::vector<std::string> &s) {
  fprintf(stderr, "> ");
  for (size_t i=0; i<s.size(); ++i)
    fprintf(stderr, "%s%c", s[i].c_str(), i+1<s.size()? ' ':'\n');
}

std::string cyk(const std::vector<std::string> &s) {
  /*
     S-Expr   -> "(" Element
               | "(" Elements
     Element  -> Upper
               | S-Expr
     Elements -> Element "and" Element
               | Element Elements
     ---

     S-Expr     -> "(" Elements
                 | "(" Upper
                 | "(" S-Expr
     Elements   -> Upper Elements
                 | Upper AndElement
                 | S-Expr Elements
                 | S-Expr AndElement
     AndElement -> "and" Upper
                 | "and" S-Expr
   */ 
  enum Symbol {
    INVALID,
    // non-terminals
    S_EXPR, ELEMS, AND_ELEM,
    // terminals
    PAREN=9, AND, UPPER,
  };
  std::vector<std::string> types={
    "0", "S-expr", "Elems", "AndElem",
    "0", "0", "0", "0", "0", "\"(\"", "\"and\"", "[A-Z]+"
  };
  
  auto category=[](const std::string &token) {
    if (token == "(") return PAREN;
    if (token == "&") return AND;
    if (isupper(token[0])) return UPPER;
    return INVALID;
  };

  std::vector<Symbol> term={PAREN, AND, UPPER};
  std::vector<std::vector<Symbol>> prod={
    {S_EXPR, PAREN, ELEMS},
    {S_EXPR, PAREN, UPPER},
    {S_EXPR, PAREN, S_EXPR},
    {ELEMS, UPPER, ELEMS},
    {ELEMS, UPPER, AND_ELEM},
    {ELEMS, S_EXPR, ELEMS},
    {ELEMS, S_EXPR, AND_ELEM},
    {AND_ELEM, AND, UPPER},
    {AND_ELEM, AND, S_EXPR},
  };

  std::vector<std::vector<std::vector<int>>> dp(
      s.size(), std::vector<std::vector<int>>(
        s.size(), std::vector<int>(prod.size()+term.size())));

  for (size_t i=0; i<s.size(); ++i) {
    Symbol cat=category(s[i]);
    if (cat != INVALID) {
      dp[0][i][cat] = 1;
    }
  }

  struct Left {
    size_t length, pos;
    Symbol symb;
    Left(size_t i, size_t j, Symbol a): length(i), pos(j), symb(a) {}
    bool operator <(const Left &oth) const {
      if (length != oth.length) return length < oth.length;
      if (pos != oth.pos) return pos < oth.pos;
      return symb < oth.symb;
    }
  };

  struct Right {
    size_t part;
    Symbol symb1, symb2;
    Right(size_t k, Symbol b, Symbol c): part(k), symb1(b), symb2(c) {}
  };

  std::map<Left, Right> via;
  size_t n=s.size();
  for (size_t i=1; i<n; ++i) {
    for (size_t j=0; j<n-i; ++j) {
      for (size_t k=1; k<=i; ++k) {
        for (const auto &pp: prod) {
          Symbol a=pp[0], b=pp[1], c=pp[2];
          if (dp[k-1][j][b] && dp[i-k][j+k][c]) {
            dp[i][j][a] += std::max(dp[k-1][j][b], dp[i-k][j+k][c]);
            if (dp[i][j][a] > 2) dp[i][j][a] = 2;
            via.emplace(Left(i, j, a), Right(k, b, c));
          }
        }
      }
    }
  }
  if (dp[n-1][0][1] > 1) return "AMBIGUOUS";

  assert(dp[n-1][0][1]);
  std::function<std::string (Left)> dfs=[&](const Left &left) {
    if (left.length == 0) return s[left.pos];
    Right right=via.at(left);
    size_t i=left.length, j=left.pos, k=right.part;
    Symbol a=left.symb, b=right.symb1, c=right.symb2;

    std::string sb=dfs(Left(k-1, j, b)), sc=dfs(Left(i-k, j+k, c));

    if (a == S_EXPR) {
      return sb + sc + ")";
    } else if (a == ELEMS) {
      return sb + " " + sc;
    } else if (a == AND_ELEM) {
      assert(sb == "&");
      return sc;
    } else {
      assert(false);
    }
  };
  return dfs(Left(n-1, 0, S_EXPR));
}

void solve_testcase() {
  char buf[1024];
  scanf("\n%[^\n]", buf);
  std::string s=buf;
  std::vector<std::string> t;
  preprocess(s, t);
  printf("%s\n", cyk(t).c_str());
}

int main() {
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; ++i)
    solve_testcase();
}

