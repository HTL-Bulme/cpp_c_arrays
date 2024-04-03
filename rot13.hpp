#ifndef ROT13_HPP
#define ROT13_HPP

#include <string>

namespace rot13 {

std::string encrypt(const std::string text);
std::string decrypt(const std::string text);

}  // namespace rot13

#endif  // ROT13_HPP
