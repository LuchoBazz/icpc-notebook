template<class T>
T lcm(T a, T b) {  
    return (a*b)/gcd<T>(a, b);  
}