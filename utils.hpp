#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <iostream>

// TODO: throw error if trying to assign a second time?
// set once var type (like final in java)
template<typename T>
class Final {
private:
  T o_val;
  std::once_flag o_once_flag;

public:
  Final(T init) : o_val(init) {}
	Final(const Final& other) = delete;

  Final<T> &operator=(const T& other) {
    std::call_once(o_once_flag, [&]() {
      o_val = other;
    });
  }

  const T &get() { return o_val; }
};

#endif // _UTILS_HPP_
