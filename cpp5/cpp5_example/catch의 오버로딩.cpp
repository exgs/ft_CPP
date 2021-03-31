#include <iostream>
#include <string>

int func(int c) {
  if (c == 1) {
    throw 10;
  } else if (c == 2) {
    throw std::string("hi!");
  } else if (c == 3) {
    throw 'a';
  } else if (c == 4) {
    throw "hello!";
  } else if (c == 5) {
    throw (long)10000000;
  }

  return 0;
}

int main() {
  int c;
  std::cin >> c;

  try {
    func(c);
  } catch (char x) {
    std::cout << "Char : " << x << std::endl;
  } catch (int x) {
    std::cout << "Int : " << x << std::endl;
  } catch (std::string& s) {
    std::cout << "String : " << s << std::endl;
  } catch (const char* s) {
    std::cout << "String Literal : " << s << std::endl;
  }catch (...) { // else 같은 기능
    std::cout << "Default Catch!" << std::endl;
  }
}
