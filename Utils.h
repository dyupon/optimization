//
// Created by User on 10/30/2017.
//

#ifndef NELDERMID_STDVECTORUTILS_H
#define NELDERMID_STDVECTORUTILS_H

#include <vector>

template<class T>
class Utils {
public:
    std::vector<T> sum(const std::vector<T> &a, const std::vector<T> &b);

    std::vector<T> diff(const std::vector<T> &a, const std::vector<T> &b);
};

template<class T>
std::vector<T> Utils<T>::sum(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] + b[i]);
    }
    return result;
}

template<class T>
std::vector<T> Utils<T>::diff(const std::vector<T> &a, const std::vector<T> &b) {
    std::vector<T> result;
    for (int i = 0; i < a.size(); ++i) {
        result.push_back(a[i] - b[i]);
    }
    return result;
}

#endif //NELDERMID_STDVECTORUTILS_H
