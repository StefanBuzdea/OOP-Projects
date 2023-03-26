# OOP-Projects
Operators, Canvas projects

# Operators Project Description
The code presented is for a class called Number which can store a number represented as a string in a specified base between 2 and 16. The class has methods to convert the number to a different base, print the number, get the number of digits, and get the current base. In addition to these methods, the class also has overloaded operators for addition, subtraction, and comparison.

The class has a constructor that takes in two arguments - the value of the number as a string and the base in which it is represented. The constructor then initializes the data members of the class accordingly. There is also a destructor to deallocate any dynamically allocated memory.

To allow for copying and moving of Number objects, the class has a copy constructor, a move constructor, and a move assignment operator. These allow for efficient and safe copying and moving of objects, and help prevent memory leaks.

One unique feature of the class is the -- operator. This operator can be used in two ways - as a prefix or postfix operator. If used in a prefix form, it removes the first (most significant) digit from the number. If used in a postfix form, it removes the last (least significant) digit from the number. This allows for easy manipulation of the Number object.

The class also has overloaded operators for addition, subtraction, and comparison. Addition and subtraction are implemented as friend functions, which means they can access private members of the class. When performing operations with two Number objects that have different bases, the result will have the biggest base of the two Number instances.

Overall, the Number class is a useful tool for representing and manipulating numbers in different bases. Its features, such as the ability to convert between bases and the -- operator, make it a versatile and powerful tool for any program that deals with numbers.
