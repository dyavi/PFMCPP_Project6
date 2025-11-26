/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References


 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.

 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 */


#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n);   
    int value;
    std::string name;
};

T::T(int v, const char* n) : value(v), name(n) {}

struct F                                
{
    T* compare(T& a, T& b) 
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float origin { 0 }, destination { 0 };

    float updateDestinationValue(float* updatedValue)     
    {
        if (updatedValue == nullptr) 
        {
            std::cout << "Warning! The parameter to this function is a null pointer, so the result is defaulting to 0.f now.\n";
            return 0.f;
        }

        std::cout << "\n";
        std::cout << "U's origin value: " << origin << std::endl;
        origin = *updatedValue;
        std::cout << "U's origin updated value: " << origin << std::endl;
        while( std::abs(destination - origin) > 0.001f )
        {
            /*
             write something that makes the distance between that->destination and that->origin get smaller
             */
            destination += (origin - destination) * 0.25f;
        }
        std::cout << "U's destination updated value: " << destination << std::endl;
        return destination * origin;        
    }
};

struct V
{
    static float staticUpdateDestinationValue(U* that, float* updatedValue )        
    {

        if (that == nullptr) 
        {
            std::cout << "Warning! The first parameter is a null pointer, so the result is defaulting to 0.f now.\n";
            return 0.f;
        }
        if (updatedValue == nullptr) 
        {
            std::cout << "Warning! The second parameter is a null pointer, so the result is defaulting to 0.f now.\n";
            return 0.f;
        }

        std::cout << "\n";
        std::cout << "U's origin value: " << that->origin << std::endl;
        that->origin = *updatedValue;
        std::cout << "U's origin updated value: " << that->origin << std::endl;
        while( std::abs(that->destination - that->origin) > 0.001f )
        {
            /*
             write something that makes the distance between that->destination and that->origin get smaller
             */
            that->destination += (that->origin - that->destination) * 0.25f;
        }
        std::cout << "U's destination updated value: " << that->destination << std::endl;
        return that->destination * that->origin;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t33(33, "t33");                                             
    T t13(13, "t13");                                             

    F f;                                            
    auto* smaller = f.compare(t33, t13);                              

    if (smaller == nullptr)
    {
        std::cout << "f.compare() returned nullptr because The `value` member variable of both arguments is exactly the same.\n\n";
    }
    else 
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; 
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << V::staticUpdateDestinationValue(&u1, &updatedValue) << std::endl;                  

    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.updateDestinationValue(&updatedValue) << std::endl;
}
