# OOP-Projects
Operators, Canvas projects

# Operators Project Description
The code presented is for a class called Number which can store a number represented as a string in a specified base between 2 and 16. The class has methods to convert the number to a different base, print the number, get the number of digits, and get the current base. In addition to these methods, the class also has overloaded operators for addition, subtraction, and comparison.

The class has a constructor that takes in two arguments - the value of the number as a string and the base in which it is represented. The constructor then initializes the data members of the class accordingly. There is also a destructor to deallocate any dynamically allocated memory.

To allow for copying and moving of Number objects, the class has a copy constructor, a move constructor, and a move assignment operator. These allow for efficient and safe copying and moving of objects, and help prevent memory leaks.

One unique feature of the class is the -- operator. This operator can be used in two ways - as a prefix or postfix operator. If used in a prefix form, it removes the first (most significant) digit from the number. If used in a postfix form, it removes the last (least significant) digit from the number. This allows for easy manipulation of the Number object.

The class also has overloaded operators for addition, subtraction, and comparison. Addition and subtraction are implemented as friend functions, which means they can access private members of the class. When performing operations with two Number objects that have different bases, the result will have the biggest base of the two Number instances.

Overall, the Number class is a useful tool for representing and manipulating numbers in different bases. Its features, such as the ability to convert between bases and the -- operator, make it a versatile and powerful tool for any program that deals with numbers.


# Canvas Project Description
The code presented is for a class called Canvas which allows for drawing various shapes on a canvas. The Canvas class is defined with several public methods for drawing shapes, as well as methods for printing and clearing the canvas.

The class has a constructor that takes in two arguments - the width and height of the canvas. It initializes a matrix of characters to represent the canvas, with each cell initially set to a space character to indicate that it is empty.

The Canvas class provides methods for drawing shapes such as circles, rectangles, and lines. The DrawCircle method takes in the x and y coordinates of the center of the circle, the radius of the circle, and a character to use for drawing the circle. The FillCircle method is similar to DrawCircle, but fills in the circle instead of just drawing the outline.

Similarly, the DrawRect and FillRect methods take in the coordinates of the top-left and bottom-right corners of a rectangle, and a character to use for drawing or filling the rectangle. The SetPoint method allows for setting the value of a single pixel at a specified location on the canvas.

Finally, the DrawLine method takes in the coordinates of two points and a character to use for drawing the line. It implements the Braseham algorithm for drawing a line, which is a widely used algorithm in computer graphics for drawing straight lines.

The Canvas class also provides a method for printing the current state of the canvas, as well as a method for clearing the canvas to its initial state.

The Canvas class is a useful tool for creating and manipulating graphical images in a C++ program. Its ability to draw various shapes and lines using a simple interface makes it easy to use for both novice and experienced programmers.
