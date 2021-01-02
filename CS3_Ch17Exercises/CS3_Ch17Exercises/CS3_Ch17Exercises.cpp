#include <iostream>
using namespace std;

//9
template < class T1, class T2>
class HeterogeneousPair
{
public:
    HeterogeneousPair();
    HeterogeneousPair(T1 firstValue, T2 secondValue);
    void setFirst(T1 value);
    void setSecond(T2 value);
    T1 getFirst() const;
    T2 getSecond() const;
private:
    T1 first;
    T2 second;
};

template<class T1, class T2> HeterogeneousPair<T1, T2>::HeterogeneousPair() {}

template<class T1, class T2> HeterogeneousPair<T1, T2>::HeterogeneousPair(T1 firstValue, T2 secondValue) : first(firstValue), second(secondValue) {}

template<class T1, class T2> T1 HeterogeneousPair<T1, T2>::getFirst() const {
    return first;
}
template<class T1, class T2> T2 HeterogeneousPair<T1, T2>::getSecond() const {
    return second;
}

template<class T1, class T2> void HeterogeneousPair<T1, T2>::setFirst(T1 value) {
    first = value;
}

template<class T1, class T2> void HeterogeneousPair<T1, T2>::setSecond(T2 value) {
    second = value;
}

int main()
{
   
}

/*
    1. template<class T> T maximum(T first, T second) {
          if (first < second){
            return second;
          }
          else{
            return first;
          }
       }
    2. template<class T> T absolute(T value) {
          if (value < 0){
            return −value;
          }
          else{
            return value;
          }
       }
    3. Templates allow function definitions and classes to have parameterized types
    4. Any type
    5. template<class BaseType> int search(const BaseType a[], int numberUsed, BaseType target);
    6. Function overloading only works when an overload is provided. Some types may automatically convert to another type, but the desired effect may not be guaranteed
    7. template<class T> T Pair<T>::getElement(int position) const {
          if (position == 1)
            return first;
          else if (position == 2)
            return second;
          else {
            cout << "Error: Illegal pair position.\n";
            exit(1);
          }
        }
    8. This constructor does nothing
    9. *see above
    10. True


*/
